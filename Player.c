#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int health_level = 5;

void decrease_health(int signal)
{
        int pid = getpid();


        if (health_level == 0){

                printf("Enemy %d killed\n", pid);
                exit(0);
        } else {
                health_level-=1;
                printf("Health: %d\n", health_level);
        }
        }

void increase_health(int signal)
{
        if (health_level > 5) {
                health_level+=1;
                printf("Health: %d\n", health_level);
        } else {
                printf("Health already at max\n");
        }
}

void print_PID(int signal){
  pid_t pid = getpid();
        printf("%d\n", pid);
}

void print_health(int signal){
        pid_t pid = getpid();
        printf("%d: ", pid);
        printf("%d\n", health_level);
}

int main(){
        if (signal(SIGUSR1, decrease_health) == SIG_ERR){
                printf("Signal Error");
                exit(1);
        }
        if (signal(SIGUSR2, increase_health) == SIG_ERR){
                printf("Signal Error");
                exit(1);
        }
        if (signal(SIGINT, print_health) == SIG_ERR){
                printf("Signal Error");
                exit(1);
        }
        
        if(signal(SIGSEGV, print_PID) == SIG_ERR)
        {
                printf("printid Error");
                exit(1);
        }
        while(1)
        {
                pause();
        }

        return(0);
}
