// Use this when you compile
//gcc -std=c99 -lpthread name.c -o nameofFileToCompileTo

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

//for macros
#define BoARDLEN 9 //I will consider len of the board as the numner of all the elements "as if they were put in a single line"
#define NUMTHRDS 2


void printBoard(char**, int);
bool gameover(char**, int);
void printResults(char**, int);
void* player1(void*);
void* player2(void*);

int main(int argc, char** argv)
{

        struct threadInfo {
                char** board;
                int curPlayer;
                bool gameover;
        };


   struct threadInfo info;

   info.board = (char**) malloc(BoARDLEN); // because char is 1 byte so the len of the board would be how much space I need to be allocated
   info.curPlayer = 1;
   info.gameover = false;

         for(int i = 0; i < 3; i++){
                info.board[i] = (char*) malloc(3 * sizeof(char));
            }
   for(int i=0; i<3; i++)
   {
       for(int j = 0; j<3; j++)
       info.board[i][j] = '-';
   }

    printBoard(info.board, 3);

    pthread_t id1;
    pthread_t id2;

    int err = pthread_create(&id1, NULL, player1, &info);

    if(err !=0)
    {
        printf("Error creating pthread\n");
        return 1;
    }

    if(pthread_detach(id1) !=0)
    {
        printf("Error detaching player1\n");
        return 1;
    }

     err = pthread_create(&id2, NULL, player2, &info);

    if(err !=0)
    {
        printf("Error creating pthread\n");
        return 1;
    }

    if(pthread_detach(id2) !=0)
    {
        printf("Error detaching player2\n");
        return 1;
       }


    while(1)
    {
        if(gameover(info.board, 3))
        {
            printResults(info.board, 3);
            return 0;
        }
    }

        return 0;
}
    void* player1(void* arg)
    {
        struct threadInfo {
                char** board;
                int curPlayer;
                bool gameover;
        };

        printf("Player 1  \n");

        struct threadInfo* info = (struct threadInfo*) arg;
        int row = rand() % 3;
        int column = rand() %3;


       while(info -> curPlayer != 2)
       {
             sleep(4);

             while(info -> board[row][column] != '-')
             {
             row = rand() % 3;
             column = rand() % 3;
             }
            if(info -> board[row][column] = '-')
             {
             info -> board[row][column] = 'o';
             }

             info -> curPlayer = 1;
             printf("Player 2 \n");
             printBoard(info -> board, 3);
                }
        }

       void* player2(void* arg)
       {
        printf("Player2 \n");

        struct threadInfo {
                char** board;
                int curPlayer;
                bool gameover;
        };

        struct threadInfo* info = (struct threadInfo*) arg;
        int row = rand() % 3;
        int column = rand() %3;




       while(!info -> gameover)
        {
             while(info -> curPlayer != 1)
             {
                     sleep(4);
             }

             while(info -> board[row][column] != '-')
             {
                     row = rand() % 3;
                          column = rand() % 3;
             }
             if(info -> board[row][column] = '-')
             {
                     info -> board[row][column] = 'X';
             }

             info -> curPlayer = 2;
             printf("Player 1 \n");

             printBoard(info->board, 3);

             }

        }


          void printBoard(char** board, int len)
          {

                for(int x = 0 ; x < 3 ; x++)
                {
                        printf(" (");

                for(int y = 0 ; y < 3 ; y++)
                {
                        printf("%c     ", board[x][y]);
                }

                        printf(")\n");
                }

                }


        bool gameover(char** board, int len)
        {
            //printBoard(board, len);
        for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(board[i][j] == '-')
                    {
                        return false;
                    }
                }
            }

            return true;
        }


        void printResults(char** board, int len)
        {

            int result = 0;

        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
        {
                result = 1;
        }
        else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
        {
        result = 1;
        }
        else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
        {
                result = 1;
        }
        else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        {
                result = 1;
        }
        else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        {
                   result = 1;
        }
        else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
        {
                result = 1;
        }
        else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
        {
                result = 1;
        }

        else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
        {
                result = 1;
        }
        else if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o')
        {
                result = 2;
        }
        else if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o')
        {
                result = 2;
        }
        else if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o')
        {
                result = 2;
        }
        else if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o')
        {
                result = 2;
        }
        else if(board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o')
        {
                result = 2;
        }
        else if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o')
        {
                result = 2;
           }
        else if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o')
        {
                result = 2;
        }
        else if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o')
        {
                result = 2;
        }
            printf("\n result: %d", result);

            if(result ==0)
            {
                printf("\n tie\n");
            }
            else if (result == 1)
            {
                printf("\n Player 1 'X' won\n");
            }
            else
            {
                printf("\n Player 2 'o' won\n");
            }

        }






