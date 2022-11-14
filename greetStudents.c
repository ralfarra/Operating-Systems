#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

        char names[3][10] = {"name1", "name2", "name3"};
        int pid;
        int wpid;
        int status = 0;

        int i =0;
        while(i<(sizeof(names))/sizeof(names[0]))
        {
                if((pid = fork()) == 0)
                {
                        char *argv[]={"greeting", names[i], NULL};
                        execv("greeting", argv);
                        exit(127);
                }

                i+=1;
        }

        while ((wpid = wait(&status)) > 0);
        printf("Done\n");
        return 0;
}
