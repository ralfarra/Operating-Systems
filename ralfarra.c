/***************
 *
 * ralfarra.c
 *
 * rashed alfarra
 ****************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sem_helper.h"
#include "sem_helper.c"

int main(int argc, char* argv[])
{
        int semid;
        int gladiator_id;
        int arena_len;
        int index = 0;
        int pos = 0;
        int next = 0;

        if (argc != 4) {
                printf("usage: %s semid gladiator_id arena_len\n", argv[0]);
                return 0;
        }

        semid = atoi(argv[1]);
        gladiator_id = atoi(argv[2]);
        arena_len = atoi(argv[3]);


        if(gladiator_id == 2) {
        /* Battle */
        int i =0;
        for(i =0; i<arena_len * arena_len ; i++){
                if(getSemaphore(semid, i) == 2)
                {
                        index = i;
                }
        }

        pos = index;

        while(1)
        {
              // if(gladiator_id = getSemaphore(semid, index))
               // {
                     // pos = index;
                 //     printf("semaphore id is: %d\n", pos+1);
               // }
                if(gladiator_id ==2){
                        if(index>0)
                        {
                        setSemaphore(semid, index-1, gladiator_id);
                        index--;
  }

                        else
                        {
                        setSemaphore(semid, pos+1, gladiator_id);
                        pos++;
                        }
                }




        }

        }

        else
        {
        int i =0;
        for(i =0; i<arena_len * arena_len ; i++){
                if(getSemaphore(semid, i) == 1)
                {
                        index = i;
                }
        }

        pos = index;
       while(1)
        {

                if(gladiator_id ==1){
                        if(index>0)
                        {
                        setSemaphore(semid, index-1, gladiator_id);
                        index--;
                        }

                        else
                        {
                        setSemaphore(semid, pos+1, gladiator_id);
                        pos++;
                        }
                }




        }
 }


}

//  END OF FILE

