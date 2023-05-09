#include<bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int finish;
    int profit;
};
bool compareActivity(activity i1, activity i2) {
    return (i1.finish < i2.finish);
}
class Schedule{
    activity* request;
    int n;
    public:
    void input(){
        cout<<"enter the number of requests: ";
        cin>>n;
        request=new activity[n];
        for(int i=0;i<n;i++){
            cout<<"For "<<i+1<<" request\n";
            cout<<"Enter start and finish time and profit: ";
            cin>>request[i].start>>request[i].finish>>request[i].profit;
        }
    }  

    int non_conflicting(int i){
        for(int j=i-1;j>=0;j--){
            if(request[j].finish <= request[i].start)
            return j;
        }return -1;
    }  

    int findProfit(){
        sort(request,request+n,compareActivity);
        int* sol=new int[n];
        sol[0]=request[0].profit;
        for(int i=1;i<n;i++){
        int incljob=request[i].profit;
        int p=non_conflicting(i);
        if(p!=-1){
            incljob+=sol[p];
        }
        sol[i]=max(incljob,sol[i-1]);
        }
        int ans=sol[n-1];
        // for(int i=0;i<n;i++){
        //     cout<<sol[i]<<" ";
        // }cout<<endl;
        delete [] sol;
        return ans;
    }
    
};
int main(){
    Schedule s1;
    s1.input();
    cout<<"Maximum profit is: "<<s1.findProfit()<<endl;
}