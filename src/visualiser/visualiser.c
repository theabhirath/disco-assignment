#include <unistd.h>
#include <stdlib.h>

void plot_digraph(char *fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","plotting/visualise.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","plotting/visualise.py",fname,(char*)NULL);
        };
    }
    // exit(0);
}
