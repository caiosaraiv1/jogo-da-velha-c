# Jogo da Velha (Tic Tac Toe)

Um jogo da velha implementado em C, com interface de linha de comando colorida e sistema de placar. Este projeto demonstra o uso de estruturas de dados básicas, manipulação de matrizes e programação modular em C.

## Características Detalhadas

### Interface do Usuário
- Interface colorida usando códigos ANSI para melhor experiência visual
- Tabuleiro desenhado com caracteres ASCII para compatibilidade universal
- Feedback visual imediato para jogadas inválidas
- Sistema de placar integrado que persiste entre partidas
- Mensagens coloridas para diferentes estados do jogo:
  - 🔴 Vermelho: Alertas e erros
  - 🟢 Verde: Informações do placar
  - 🟡 Amarelo: Notificações de empate
  - 🔵 Ciano: Mensagens do sistema

### Mecânicas do Jogo
- Sistema de turnos alternados entre X e O
- Validação completa de entrada do usuário
- Verificação de vitória em 8 direções possíveis:
  - 3 linhas horizontais
  - 3 linhas verticais
  - 2 diagonais
- Detecção automática de empate ("Deu velha")
- Opção de jogar múltiplas partidas com placar acumulativo

## Instalação

### Pré-requisitos
```bash
# Ubuntu/Debian
sudo apt-get install gcc

# Fedora
sudo dnf install gcc

# macOS (usando Homebrew)
brew install gcc
```

### Compilação
```bash
# Compilação básica
gcc jogo_da_velha.c -o jogo_da_velha
```

## Como Jogar - Guia Detalhado

1. **Iniciando o Jogo**
   ```bash
   ./jogo_da_velha
   ```

2. **Tela Inicial**
   - Apresenta as regras do jogo
   - Mostra o layout do tabuleiro
   - Pressione ENTER para continuar

3. **Escolha do Símbolo**
   - Digite 'X' ou 'O' (não sensível a maiúsculas/minúsculas)
   - Entrada inválida resultará em mensagem de erro

4. **Sistema de Posições**
   ```
    1 | 2 | 3    → Primeira linha
   ---+---+---
    4 | 5 | 6    → Segunda linha
   ---+---+---
    7 | 8 | 9    → Terceira linha
   ```

5. **Durante o Jogo**
   - O placar é mostrado no topo
   - O jogador atual é indicado
   - Digite um número de 1-9 para fazer sua jogada
   - Jogadas inválidas são rejeitadas com feedback

6. **Fim de Jogo**
   - Vitória: Quando um jogador forma uma linha
   - Empate: Quando todas as posições estão preenchidas
   - Opção de jogar novamente (s/n)

## Detalhes Técnicos

### Estruturas de Dados
- Tabuleiro: Matriz 3x3 de caracteres (`char board[3][3]`)
- Contadores: Inteiros para placar (`x_counter`, `o_counter`)
- Estado do jogo: Booleanos para controle de fluxo

### Funções Principais

#### `void show_start_screen()`
- Exibe banner inicial com ASCII art
- Apresenta regras do jogo
- Utiliza códigos ANSI para colorização

#### `void initialize_board(char board[3][3])`
- Preenche a matriz com espaços em branco
- Prepara o tabuleiro para nova partida
- Complexidade: O(1) - tamanho fixo

#### `void print_board(char board[3][3])`
- Renderiza estado atual do tabuleiro
- Adiciona linhas divisórias
- Mantém alinhamento consistente

#### `bool check_win(char board[3][3])`
- Verifica todas as possibilidades de vitória
- Implementa lógica para 8 combinações vencedoras
- Retorna true se encontrar vencedor

#### `bool check_tie(char board[3][3])`
- Verifica se todas as células estão preenchidas
- Executa após verificação de vitória
- Complexidade: O(1) - tamanho fixo

#### `void convert_position(int n, int *row, int *column)`
- Converte entrada do usuário (1-9) em coordenadas da matriz
- Utiliza aritmética para cálculo de posição
- Fórmulas:
  - row = (position - 1) / 3
  - column = (position - 1) % 3

### Códigos de Cores ANSI
```c
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
```

## Tratamento de Erros

1. **Entrada Inválida de Símbolo**
   - Verifica se entrada é 'X' ou 'O'
   - Converte automaticamente para maiúscula
   - Solicita nova entrada se inválida

2. **Posição Inválida**
   - Verifica se número está entre 1-9
   - Verifica se posição está ocupada
   - Fornece feedback em vermelho

3. **Validação de Continuidade**
   - Verifica entrada s/n para continuar jogo
   - Permite entrada em maiúscula/minúscula
   - Finaliza jogo graciosamente se 'n'
