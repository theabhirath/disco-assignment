#include <unistd.h>

void plot_hasse(char *fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","visualise_hasse.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","visualise_hasse.py",fname,(char*)NULL);
        };
    }
    exit(0);
}

// int main(){
//     plot("../src/testPartailOrder.csv");
//     return 0;
// }
