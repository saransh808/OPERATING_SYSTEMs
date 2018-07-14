#include<iostream>
#include<unistd.h>
#include<sys/dir.h>
using namespace std;
int main(){
    int pid=fork();
    if(pid<0){
        cout<<"Failed";
        exit(0);
    }else if(pid==0){
        cout<<"Child:"<<endl;
        for(int i=0;i<5;i++) cout<<"Process : "<<getpid()<<endl;
    }else{
        wait(0);
        cout<<"Parent Ends"<<getppid();
        exit(0);
    }
}
