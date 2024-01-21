# PureChat

Este é um script de configuração de chat para SA-MP.

O script oferece funcionalidades para controlar o chat de jogadores no servidor, permitindo a ativação ou desativação do chat para jogadores específicos ou para todos.

## Uso

1. **Inclusão no Script:**
<p>Certifique-se de incluir este script no seu servidor SA-MP.</p>
<p>O código incluído no seu script deve conter a referência adequada ao arquivo `purechat.inc`.</p>

```pawn
#include <purechat>
```

2. **Ativação/Desativação do Chat:**

Utilize as funções `ToggleChatForPlayer` e `ToggleChatForAll` para ativar ou desativar o chat para jogadores específicos ou para todos, respectivamente.

- Desativa o chat para o jogador específico:
  ```pawn
  ToggleChatForPlayer(playerid, false);
  ```

- Desativa o chat para todos os jogadores:
  ```pawn
  ToggleChatForAll(false);
  ```

3. **Verificação do Status do Chat:**

Use a função `IsPlayerChatEnabled` para verificar se o chat está ativado ou desativado para um jogador específico.

```pawn
if(IsPlayerChatEnabled(playerid)) {
    // O chat está ativado para este jogador
} else {
    // O chat está desativado para este jogador
}
```

4. **Limpeza do Chat:**

As funções `ClearChatForPlayer` e `ClearChatForAll` permitem limpar um número específico de linhas do chat para um jogador ou para todos.

- Limpa as últimas 5 linhas do chat para o jogador específico
  ```pawn
  ClearChatForPlayer(playerid, 5);
  ```

- Limpa as últimas 5 linhas do chat para todos os jogadores
  ```pawn
  ClearChatForAll(5);
  ```

5. **Envio de Mensagens:**

As mensagens só podem ser vistas por jogadores que estão com o chat ativo!<br />
Caso o jogador tenha seu chat desativado, SendClientMessage e SendClientMessageToAll não fará efeito nesse jogador.

## Notas

- Certifique-se de incluir e configurar corretamente a include no seu script SA-MP.
- Consulte o código fonte para obter informações detalhadas sobre as funções incluídas.
- Este script é originalente criado por mim, porém serviu de base e recebeu uma adaptação por parte do [BlueN](https://github.com/devbluen/ChatConfig-Samp).
  ![Pawn Express Screenshots](https://raw.githubusercontent.com/devicewhite/PureChat/DeviceWhite/Screenshot_2024-01-21-04-40-03-227_com.discord.jpg)


**Creditos:**
- DeviceWhite (Include Original)
- [BlueN](https://github.com/devbluen) (Versão Adaptada)