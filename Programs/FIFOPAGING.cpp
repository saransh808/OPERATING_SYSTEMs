#include<iostream>
#include<unistd.h>
#include<sys/dir.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int que[n];
    for(int i=0;i<n;i++) cin>>que[i];
    int x;
    cin>>x;
    int hash[x];
    for(int i=0;i<x;i++) hash[i]=-1;
    for(int i=0;i<x;i++){
        hash[i]=que[i];
        for(int j=0;j<x;j++)
            cout<<hash[j]<<" ";
        cout<<endl;
    }
    //for(int i=0;i<x;i++) hash[i]=que[i];

    int count=0;
    int index=0;
    for(int i=x;i<n;i++){
        int flag=0;
        for(int j=0;j<x;j++){
            if(hash[j]==que[i]) flag=1;
        }
        if(flag==1){
            count++;
            continue;
        }
        if(index==x-1) index=0;
        else{
            hash[index]=que[i];
            index++;
        }
        for(int i=0;i<x;i++) cout<<hash[i]<<" ";cout<<endl;
    }
    cout<<"Faults:"<<n-count<<endl;
}
