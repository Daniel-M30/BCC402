#include <stdio.h>
#include <stdlib.h>

#define T_Y 8
#define T_X 8

// Verifica as retas
int handleStraight(char** board, int x, int y, char target1, char target2) {
    if(x - 1 >= 0 && y - 1 >= 0 && x + 1 < T_X && y + 1 < T_Y) {
        if ((board[y][x - 1] == target1 || board[y][x - 1] == target2) || (board[y][x + 1] == target1 || board[y][x + 1] == target2) || 
            (board[y - 1][x] == target1 || board[y - 1][x] == target2) || (board[y + 1][x] == target1 || board[y + 1][x] == target2))
            return 1;

        int xc, yc;
        for (xc = -1; xc + x - 1 >= 0 && board[y][xc + x] == '.'; xc--)
            if (board[y][xc + x - 1] == target1 || board[y][xc + x - 1] == target2)
                return 1;
        
        for (xc = 1; xc + x + 1 < T_X && board[y][xc + x] == '.'; xc++)
            if (board[y][xc + x + 1] == target1 || board[y][xc + x + 1] == target2)
                return 1;
        
        for (yc = -1; yc + y - 1 >= 0 && board[y + yc][x] == '.'; yc--)
            if (board[y + yc - 1][x] == target1 || board[y + yc - 1][x] == target2)
                return 1;
        
        for (yc = 1; yc + y + 1 < T_Y && board[y + yc][x] == '.'; yc++)
            if (board[y + yc + 1][x] == target1 || board[y + yc + 1][x] == target2)
                return 1;
    }
        
    return 0;
}

// Verifica a diagonal
int handleDiagonal(char** board, int x, int y, char target1, char target2) {
    int upLeft = 1, upRight = 1, downLeft = 1, downRight = 1;
    
    for (int c = 1; upLeft || upRight || downLeft || downRight; c++) {
        if (upLeft) {
            if (x - c >= 0 && y - c >= 0) {                
                if (board[y - c][x - c] == target1 || board[y - c][x - c] == target2)
                    return 1;
                
                else if (board[y - c][x - c] != '.')
                    upLeft = 0;
            }

            else
                upLeft = 0;
        }
        
        if (upRight) {
            if (x + c < T_X && y - c >= 0) {
                if (board[y - c][x + c] == target1 || board[y - c][x + c] == target2)
                    return 1;
                
                else if (board[y - c][x + c] != '.')
                    upRight = 0;
            }

            else
                upRight = 0;
        }
        
        if (downLeft) {
            if (x - c >= 0 && y + c < T_Y) {
                if (board[y + c][x - c] == target1 || board[y + c][x - c] == target2)
                    return 1;
                
                else if (board[y + c][x - c] != '.')
                    downLeft = 0;
            }

            else
                downLeft = 0;
        }
        
        if (downRight) {
            if (x + c < T_X && y + c < T_Y) {
                if (board[y + c][x + c] == target1 || board[y + c][x + c] == target2)
                    return 1;
                
                else if (board[y + c][x + c] != '.')
                    downRight = 0;
            }

            else
                downRight = 0;
        }
    }
    
    return 0;
}

int handleKnight(char** board, int x, int y, char target) {
    if (x - 2 >= 0) {
        if (y - 1 >= 0 && board[y - 1][x - 2] == target)
            return 1;
        
        if (y + 1 < T_Y && board[y + 1][x - 2] == target)
            return 1;
    }
    
    if (x + 2 < T_X) {
        if (y - 1 >= 0 && board[y - 1][x + 2] == target)
            return 1;
            
        if (y + 1 < T_Y && board[y + 1][x + 2] == target)
            return 1;
    }
    
    if (y - 2 >= 0) {
        if (x - 1 >= 0 && board[y - 2][x - 1] == target)
            return 1;
        
        if (x + 1 < T_X && board[y - 2][x + 1] == target)
            return 1;
    }
    
    if (y + 2 < T_Y) {
        if (x - 1 >= 0 && board[y + 2][x - 1] == target)
            return 1;
            
        if (x + 1 < T_X && board[y + 2][x + 1] == target)
            return 1;
    }
    
    return 0;
}

int handlePawn(char** board, int x, int y, char target, int yChange) {
    if (y + yChange < T_Y && y + yChange >= 0) {
        if (x - 1 >= 0 && board[y + yChange][x - 1] == target)
            return 1;
        
        if (x + 1 < T_X && board[y + yChange][x + 1] == target)
            return 1;
    }

    return 0;
}

int main() {
    int i, j, whitePosX, whitePosY, blackPosX, blackPosY, game = 1;
    char** board = malloc(T_Y * sizeof(char*));
    for(i = 0; i < T_Y; i++) {
        for(j = 0; j < T_X; j++) 
            board[i] = malloc(T_X * sizeof(char));
    }

    while(1) {
        whitePosX = -1, whitePosY = -1, blackPosX = -1, blackPosY = -1;
        for(i = 0; i < T_Y; i++) {
            for(j = 0; j < T_X; j++) {
                scanf("%c", &board[i][j]);

                // Ignorando '\n'
                if(board[i][j] == '\n') {
                    j--;
                    continue;
                }

                if(board[i][j] == 'k') {
                    blackPosY = i;
                    blackPosX = j;
                }

                if(board[i][j] == 'K') {
                    whitePosY = i;
                    whitePosX = j;
                }
            }
        }

        if(whitePosX == -1 || whitePosY == -1 || blackPosX == -1 || blackPosY == -1)
            break;

        printf("Game #%d: ", game);

        // A verificação atual pega a posição do rei e verifica se ele esta na area de ataque de uma das peças 
        if (handlePawn(board, whitePosX, whitePosY, 'p', -1))
            printf("white king is in check.\n");
        
        else if (handlePawn(board, blackPosX, blackPosY, 'P', 1))
            printf("black king is in check.\n");
        
        else if (handleKnight(board, whitePosX, whitePosY, 'n'))
            printf("white king is in check.\n");
            
        else if (handleKnight(board, blackPosX, blackPosY, 'N'))
            printf("black king is in check.\n");
            
        else if (handleStraight(board, whitePosX, whitePosY, 'r', 'q'))
            printf("white king is in check.\n");
        
        else if (handleStraight(board, blackPosX, blackPosY, 'R', 'Q'))
            printf("black king is in check.\n");
        
        else if (handleDiagonal(board, whitePosX, whitePosY, 'b', 'q'))
            printf("white king is in check.\n");
        
        else if (handleDiagonal(board, blackPosX, blackPosY, 'B', 'Q'))
            printf("black king is in check.\n");
        
        else
            printf("no king is in check.\n");

        game++;
    }

    for(i = 0; i < T_Y; i++)
        free(board[i]);

    return 0;
}