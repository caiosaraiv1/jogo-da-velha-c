#include <stdio.h>
#include <stdbool.h>

void show_start_screen() 
{
    printf("\n");
    printf("*********************************\n");
    printf("*       JOGO DA VELHA           *\n");
    printf("*********************************\n");
    printf("* Bem-vindo ao Jogo da Velha!   *\n");
    printf("*                               *\n");
    printf("* Regras:                       *\n");
    printf("* 1. Escolha entre X ou O.      *\n");
    printf("* 2. Informe a posicao (1-9).   *\n");
    printf("*                               *\n");
    printf("* Boa sorte e divirta-se!       *\n");
    printf("*********************************\n");
    printf("\nPressione ENTER para continuar...");
    getchar();  
}

void change_player(char *player) 
{
    *player = (*player == 'X') ? 'O' : 'X';   
}

void initialize_board(char board[3][3])
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[3][3])
{
    printf("\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf(" %c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

bool check_win(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

bool check_tie(char board[3][3])
{
    bool flag;

    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
            {
                flag = false;
                return flag;
                break;
            }
            else 
            {
                flag = true;
            }
        }
    }
    return flag;
}

bool check_valid_position(char board[3][3], int row, int column)
{
    if(board[row][column] != ' ')
    {
        return false;
    }
    return true;
}

void check_winner(char board[3][3], int *x_counter, int *o_counter)
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            if (board[i][0] == 'X') 
            {
                (*x_counter)++;
                printf("X ganhou!\n");
                return;
            } 
            else 
            {
                (*o_counter)++;
                printf("O ganhou!\n");
                return;
            }
        }
    }

    for (int j = 0; j < 3; j++) 
    {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) 
        {
            if (board[0][j] == 'X') 
            {
                (*x_counter)++;
                printf("X ganhou!\n");
                return;
            } 
            else
            {
                (*o_counter)++;
                printf("O ganhou!\n");
                return;
            }
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        if (board[0][0] == 'X') 
        {
            (*x_counter)++;
            printf("X ganhou!\n");
            return;
        } 
        else 
        {
            (*o_counter)++;
            printf("O ganhou!\n");
            return;
        }
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 'X') 
        {
            (*x_counter)++;
            printf("X ganhou!\n");
            return;
        } 
        else 
        {
            (*o_counter)++;
            printf("O ganhou!\n");
            return;
        }
    }
}

void convert_position(int n, int *row, int *column)
{
    n--;
    *row = n / 3;
    *column = n % 3;
}

void game(char board[3][3], char player, int *x_counter, int *o_counter)
{
    bool is_game_finished = false;
    int position, row, column;

    printf("----Placar----\n");
    printf("X: %d O: %d", *x_counter, *o_counter);

    while(!is_game_finished)
    {
        print_board(board);

        printf("\nVez do %c\n", player);
        printf("Digite a posicao da jogada (1-9): ");
        scanf("%d", &position);
        convert_position(position, &row, &column);

        if(!check_valid_position(board, row, column))
        {
            printf("\nPosicao ja ocupada! Escolha outra posicao\n");
            continue;
        }

        board[row][column] = player;
        change_player(&player);

        is_game_finished = check_win(board) || check_tie(board);
    }

    print_board(board);


    if(check_win(board))
    {
        check_winner(board, x_counter, o_counter);
    }
}

int main() 
{
    bool continue_play = true;
    int x_counter = 0, o_counter = 0;

    show_start_screen();

    while(continue_play)
    {
        char current_player;
        printf("Escolha entre X ou O (use CAPS LOCK): ");
        scanf(" %c", &current_player);

        char board[3][3];
        initialize_board(board);

        game(board, current_player, &x_counter, &o_counter);

        char play_again;
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &play_again);

        if (play_again == 'n' || play_again == 'N') {
            continue_play = false;
        }
    }
    
    return 0;
}