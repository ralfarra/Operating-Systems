#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

// I had problems understanding this program, so I got help from my friend Noah and StackOverFlow (please see link next line) on it. I used his code to understand the problem and then I wrote this from scratch. I might have used some exact code because this was the way I understood this problem
// StackOverFlow link: https://stackoverflow.com/questions/3919009/how-to-read-from-stdin-with-fgets

#define BUFF_SIZE 16
char buffer [BUFF_SIZE];

int main() {
        // variable declaration
        int p_arr[100];
        int pid;
        int x;
        int y;
        // size varialbes. size1, 2, 3 and 4
        int s1;
        int s2;
        int s3;
        int s4;
        int i;
	int printid;
        int l;
        int count = 0;
        char *args[] = {NULL};

        // main while loop. I want it to always show these options
        while (1){
                // print available options
                char option1[500];
                printf("1:Spawn player\n");
                printf("2:Injure player\n");
                printf("3:Heal player\n");
                printf("4: List player\n");
                printf("5: Quit\n");
                printf("please enter a number: \n");

                // read input from user
                while(1){
                        scanf("%d", &i);
                        }      
		// user chose option "1"
                if (i == 1) {
                        if ((pid = fork()) == 0){
				execv("./player1", NULL);
			} else if (pid[count] < 0){
				printf("fork error: %s\n", strerror(errno));
			}
                       
                }
                
		// user picker option "2"
                else if (i == 2) {
                        int x = 0;
                        for (x = 0; x < sizeof(p_Arr); x++){
				printf("ID: %d\n", pid[i]);
			}
                        
                        printf("Please enter one of the listed pids:\n");
                        
                                scanf("%d", &printid);
               
                        kill(printid, SIGUSR1); // send SIGUSR1 signal to chosen pid
                        sleep(1); 

                }
		
		// user picked option "3"
                else if (i == 3) {
                        int x = 0;
                        for (x = 0; x < sizeof(p_Arr); x++){
				printf("ID: %d\n", pid[i]);
			}
                        printf("Please enter one of the listed pids:\n");
                       
                                scanf("%d", &printid);
                        
                        kill(printid, SIGUSR1); // send SIGUSR1 signal to chosen pid
                        sleep(1); 


                        kill(i, SIGUSR2); // send SIGUSR2 signal to chosen PID
                        sleep(1);
                }
                else if (i == 4) // user picker option "4"
                {
                       int x = 0;
                        for (x = 0; x < sizeof(p_Arr); x++){
				printf("ID: %d\n", pid[i]);
			}
                        
                        sleep(1); // wait for child to finish executing

                }
                else if (i == 5) // user pciked option "5" (chose to quit)
                {
                        int x = 0;
                        for (x = 0; x < sizeof(p_Arr); x++){
				kill(p_arr[y], SIGKILL); // send SIGKILL signal to all children (force kill)
			}
                        printf("GAME OVER\n"); 
                        exit(1);
                }
        }
}


