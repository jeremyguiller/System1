#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    char *p;
    long nbChildProcess = strtol(argv[1], &p, 10);
    srand(time(NULL));
    int variable = 0;
    int tmp = 1;
    
    while(variable<1){
        variable = rand()%12;
    }
    
    for (int i = 0; i < nbChildProcess; ++i) {
        sleep(variable);
        if (fork() == 0) {
            printf("%d Je suis un fils ---- PID : %ld\n",tmp,getpid());
            atexit(printf("bye\n"));
            exit(0);
        }
        
        //while (waitpid(-1,NULL, WNOHANG) != 0);    
        tmp++;
    }
     return (0);
}


