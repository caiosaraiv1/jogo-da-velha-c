# Jogo da Velha (Tic Tac Toe)

Um jogo da velha implementado em C, com interface de linha de comando colorida e sistema de placar.

## Características

- Interface colorida usando códigos ANSI
- Sistema de placar para acompanhar vitórias de X e O
- Validação de jogadas
- Tela inicial com instruções
- Suporte para múltiplas partidas
- Detecção automática de vitória e empate

## Como Jogar

1. Compile o código fonte:
```bash
gcc jogo_da_velha.c -o jogo_da_velha
```

2. Execute o jogo:
```bash
./jogo_da_velha
```

3. Siga as instruções na tela:
   - Escolha seu símbolo (X ou O)
   - Use números de 1 a 9 para fazer sua jogada conforme o layout abaixo:

```
 1 | 2 | 3 
---+---+---
 4 | 5 | 6 
---+---+---
 7 | 8 | 9 
```

## Funcionalidades

- **Placar**: Mantém registro das vitórias de cada jogador (X e O)
- **Validação**: Impede jogadas em posições já ocupadas
- **Interface Amigável**: Usa cores diferentes para melhor visualização
- **Alternância Automática**: Troca automaticamente entre jogadores X e O
- **Verificação de Vitória**: Detecta vitórias em linhas, colunas e diagonais
- **Verificação de Empate**: Identifica quando o jogo termina em empate

## Requisitos

- Compilador C (GCC recomendado)
- Terminal com suporte a cores ANSI

## Estrutura do Código

O jogo é composto por várias funções principais:

- `show_start_screen()`: Exibe a tela inicial com instruções
- `initialize_board()`: Prepara o tabuleiro para uma nova partida
- `print_board()`: Mostra o estado atual do tabuleiro
- `check_win()`: Verifica se houve um vencedor
- `check_tie()`: Verifica se houve empate
- `game()`: Controla o fluxo principal do jogo
- `check_valid_position()`: Valida as jogadas dos usuários

## Cores Utilizadas

- 🔴 Vermelho: Mensagens de erro
- 🟢 Verde: Placar
- 🟡 Amarelo: Mensagem de empate
- 🔵 Ciano: Tela inicial e mensagem final
