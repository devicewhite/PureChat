/*
 * Copyright (C) 2024 DeviceBlack
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined purechat_include
	#endinput
#endif
#define purechat_include

#pragma library purechat

// Static array to store chat enable/disable status for each player
static bool:ReceberMensagens[MAX_PLAYERS];

/*
 * Function: ToggleChatForPlayer
 * Toggles chat for a specific player.
 *
 * Parameters:
 *   playerid - The ID of the player for whom chat is being toggled.
 *   toggle   - A boolean indicating whether to enable (true) or disable (false) chat for the player.
 */
forward ToggleChatForPlayer(playerid, bool:toggle);
stock ToggleChatForPlayer(playerid, bool:toggle)
{
	if(IsPlayerConnected(playerid))
		ReceberMensagens[playerid] = toggle;
}

/*
 * Function: ToggleChatForAll
 * Toggles chat for all players.
 *
 * Parameters:
 *   toggle - A boolean indicating whether to enable (true) or disable (false) chat for all players.
 */
forward ToggleChatForAll(bool:toggle);
stock ToggleChatForAll(bool:toggle)
{
    for (new i = GetPlayerPoolSize(); i >= 0; --i)
        ReceberMensagens[i] = toggle;
}

/*
 * Function: IsPlayerChatEnabled
 * Checks if a player's chat is enabled.
 *
 * Parameters:
 *   playerid - The ID of the player whose chat status is being checked.
 *
 * Return:
 *   Returns a boolean indicating whether the player's chat is enabled (true) or disabled (false).
 */
stock bool:IsPlayerChatEnabled(playerid)
{
	return IsPlayerConnected(playerid) ? ReceberMensagens[playerid] : false;
}

/*
 * Function: ClearChatForPlayer
 * Clears a specified number of chat lines for a specific player.
 *
 * Parameters:
 *   playerid - The ID of the player whose chat lines are being cleared.
 *   lines    - The number of chat lines to clear. Default is 10.
 */
stock ClearChatForPlayer(playerid, lines = 10)
{
	if(IsPlayerConnected(playerid))
	{
		while(lines-- > 0)
			SendClientMessage(playerid, 0, " ");
	}
}

/*
 * Function: ClearChatForAll
 * Clears a specified number of chat lines for all players.
 *
 * Parameters:
 *   lines - The number of chat lines to clear for all players. Default is 10.
 */
stock ClearChatForAll(lines = 10)
{
	while(lines-- > 0)
		SendClientMessageToAll(0, " ");
}

// Script hooks, don't mess
public OnPlayerConnect(playerid)
{
	ReceberMensagens[playerid] = true;

	/*
	 * Script hook: PureChat_OnPlayerConnect
	 * Calls a user-defined function if defined.
	 */
	#if defined PureChat_OnPlayerConnect
		return PureChat_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect PureChat_OnPlayerConnect
#if defined PureChat_OnPlayerConnect
	forward PureChat_OnPlayerConnect(playerid);
#endif

public OnPlayerText(playerid, text[])
{
	/*
	 * Script hook: PureChat_OnPlayerText
	 * Calls a user-defined function if defined.
	 */
	#if defined PureChat_OnPlayerText
		new retn = PureChat_OnPlayerText(playerid, text);
	#else
		new retn = 1;
	#endif
	return ReceberMensagens[playerid] ? retn : 0;
}

#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif
#define OnPlayerText PureChat_OnPlayerText
#if defined PureChat_OnPlayerText
	forward PureChat_OnPlayerText(playerid, text[]);
#endif

/*
 * Function: EnviarMensagem
 * Sends a message to a player if their chat is enabled.
 *
 * Parameters:
 *   playerid - The ID of the player to whom the message is being sent.
 *   color    - The color of the message.
 *   message  - The message to be sent.
 *
 * Return:
 *   Returns 1 if the message is sent, 0 otherwise.
 */

stock EnviarMensagem(playerid, color, const message[])
{
	return ReceberMensagens[playerid] ? SendClientMessage(playerid, color, message) : 0;
}

#if defined _ALS_SendClientMessage
	#undef SendClientMessage
#else
	#define _ALS_SendClientMessage
#endif
#define SendClientMessage EnviarMensagem

/*
 * Function: EnviarMensagemParaTodos
 * Sends a message to all players if their chat is enabled.
 *
 * Parameters:
 *   color   - The color of the message.
 *   message - The message to be sent.
 *
 * Return:
 *   Always returns 1.
 */

stock EnviarMensagemParaTodos(color, const message[])
{
	for(new i = GetPlayerPoolSize(); i >= 0; --i)
		EnviarMensagem(i, color, message);

	return 1;
}

#if defined _ALS_SendClientMessageToAll
	#undef SendClientMessageToAll
#else
	#define _ALS_SendClientMessageToAll
#endif
#define SendClientMessageToAll EnviarMensagemParaTodos
