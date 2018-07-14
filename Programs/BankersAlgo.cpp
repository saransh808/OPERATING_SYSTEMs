#include<iostream>
#include<unistd.h>
#include<sys/dir.h>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int all[n][m], max[n][m], need[n][m], ava[m];
    queue<int> q;

    cout<<"Enter Allocation matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>all[i][j];
        }
    }
    cout<<"Enter Max matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Need Matrix :  "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-all[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter Avail : ";
    for(int i=0;i<m;i++) cin>>ava[i];

    for(int i=0;i<n;i++) q.push(i);
    while(q.size()!=0){
        int index=q.front();
        int count=0;
        for(int i=0;i<m;i++){
            if(need[index][i]<=ava[i]){
                count++;
            }
        }
        if(count==m){
            cout<<"P["<<index+1<<"]"<<endl;
            for(int i=0;i<m;i++){
                ava[i]+=need[index][i];
            }
            q.pop();
        }else{
            q.pop();
            q.push(index);
        }
    }

}
/*
5
3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

*/
