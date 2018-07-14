#include<iostream>
#include<unistd.h>
#include<sys/dir.h>
using namespace std;
int main(){
    cout<<execlp("/bin/date","date",0);
}
