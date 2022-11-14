#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/shm.h>
#include <sys/types.h>



void* create_shared_memory(size_t size) {

        const char *name = "lab5";
        int fd = shm_open(name, O_CREAT|O_RDWR, 0666);
        ftruncate(fd, size);
        int rwr = PROT_READ | PROT_WRITE;
        int visibility = MAP_SHARED;

        return mmap(NULL, size, rwr, visibility, fd, 0);

        }

       int main()
       {

        while(1)
        {

        char a[100];
        char b[100];


        read(0, a, 100);
//      read(0, b, 100);


        void* shmem = create_shared_memory(128);
                
                
        //void* shmem = mmap(NULL, 128, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
                        //
 //     int length = snprintf( NULL, 0, "%d", fd);
//      char* str = malloc( length + 1 );
//      snprintf( str, length + 1, "%d", fd);
//      memcpy(str, a, sizeof(a));
        memcpy(shmem, a, sizeof(a));

        int pid = fork();

        if (pid == 0) {
   // printf("Friend1 read: %s\n", shmem);
                printf("Friend1 wrote: %s\n", shmem);
        }
        else
        {
                read(0, b, 100);
                memcpy(shmem, b, sizeof(b));
                printf("Friend2 wrote: %s\n", shmem);
        }

        int ret = munmap(shmem, sizeof(shmem));
        if(ret != 0)
        {
                fprintf(stderr, "Failed to unmap shared memory\n");
        }
        }

}



//      read(0, b, 100);
//      memcpy(shmem, b, sizeof(b));


        // } else {
          // printf("Friend2 wrote: %s\n", shmem);
         // sleep(5);
          // printf("After 1s, Friend2 read: %s\n", shmem);




