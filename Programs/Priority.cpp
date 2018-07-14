#include<iostream>
#include<unistd.h>
#include<sys/dir.h>
#include<algorithm>
using namespace std;
struct Process{
    int bt, wt,tat,prior;
};
bool cmp(struct Process a, struct Process b){
    return a.prior<b.prior;
}
int main(){
    int n;
    cin>>n;
    float sumtat=0, sumbt=0;
    struct Process p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].bt;
        cin>>p[i].prior;
    }
    for(int i=0;i<n;i++){
        p[i].wt=0;
    }
    sort(p, p+n, cmp);
    for(int i=0;i<n;i++){
        p[i].wt=0;
    }
    for(int i=1;i<n;i++){

        p[i].wt=p[i-1].bt+p[i-1].wt;
        sumbt+=p[i].wt;
    }
    for(int i=0;i<n;i++){
        p[i].tat=p[i].wt+p[i].bt;
        sumtat+=p[i].tat;
    }
    cout<<"BT PR WT TAT"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].bt<<"  "<<p[i].prior<<"  "<<p[i].wt<<"  "<<p[i].tat<<endl;;
    }
    cout<<"Avg. WT : "<<sumbt/n<<endl;
    cout<<"Avg. TAT : "<<sumtat/n<<endl;


}
