#include <unistd.h>
#include <stdlib.h>

void plot_hasse(char *fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python", "plotting/visualise_hasse.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3", "plotting/visualise_hasse.py",fname,(char*)NULL);
        };
    }
    // exit(0);
}

// int main(){
//     plot_hasse("");
//     return 0;
// }
