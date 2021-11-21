#include <unistd.h>


void plot(char * fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","visualise hasse.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","visualise hasse.py",fname,(char*)NULL);
        };
    }
    exit(0);
}
// int main(){
//     plot("../src/testPartailOrder.csv");
//     return 0;
// }
