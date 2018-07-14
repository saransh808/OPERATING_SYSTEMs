#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    int pid;
    pid=fork();
    if(pid<0) {
        cout<<"Fork Failed";
        exit(1);
    }else if(pid==0){
        execlp("Whoami","ls",NULL);
        exit(0);
    }else{
        cout<<"Process Pid : "<<getpid()<<endl;;
        wait(NULL);
        exit(0);
    }
}
