#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    int pid=fork();
    if(pid<0){
        perror("Fork Failed");
        exit(0);
    }else if(pid==0){
        cout<<"Child : ";
        cout<<getpid()<<endl;
        cout<<"Parent : ";
        cout<<getppid()<<endl;
    }else{
        cout<<getpid()<<endl;
        //cout<<pid()<<endl;
        cout<<getppid()<<endl;
    }
}
