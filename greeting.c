#include <stdio.h>


        int main(int argc, char *argv[])
        {
        if (argc < 1)   return 0;

        char* argument = argv[1];

        printf("Hello, %s\n",argument);
        return 0;
        }
