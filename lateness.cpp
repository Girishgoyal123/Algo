#include<bits/stdc++.h>
using namespace std;
struct activity{
    int start;
    int finish;
    int deadline;
    int length;
};

bool compareJob(activity j1, activity j2) 
{
    return (j1.deadline < j2.deadline);
}

class Schedule{
    activity* request;
    int* lateness;
    int starttime;
    int n;
    public:
    void input(){
        cout<<"Enter the start time: ";
        cin>>starttime;
        cout<<"Enter the number of requests: ";
        cin>>n;
        lateness=new int[n];
        request=new activity[n];
         
        for(int i=0;i<n;i++){
            cout<<"For "<<i+1<<" request\n";
            cout<<"Enter time taken by job and the deadline: ";
            cin>>request[i].length>>request[i].deadline;
        }
    }

    void schedule(){
        
        sort(request,request+n,compareJob);
        int f=starttime;
        for(int i=0;i<n;i++){
            request[i].start=f;
            request[i].finish=f+request[i].length;
            f=f+request[i].length;
        }
        int ans,late=0;
        for(int i=0;i<n;i++){
            ans=starttime+request[i].length -request[i].finish;
            if(ans>0){
                lateness[i]=0;
            }
            else{
            lateness[i]=abs(ans);
            late+=abs(ans);}
        }
        cout<<"Id"<<"\t"<<"start"<<"\t"<<"finish"<<"\t"<<"length"<<"\t"<<"deadline"<<"\t"<<"Lateness\n";
        for(int i=0;i<n;i++){
            cout<<i+1<<"\t";
            cout<<request[i].start<<"\t"<<request[i].finish<<"  \t"<<request[i].length<<"  \t"<<request[i].deadline<<"\t\t"<<lateness[i]<<endl;
        }
        cout<<"Toatl minimum lateness: "<<late<<endl;
    }
    
    void display(){
        for(int i=0;i<n;i++){
            cout<<i<<endl;
            cout<<request[i].length<<" "<<request[i].deadline<<endl;
        }
        cout<<endl;
    }
};
int main(){
    Schedule s1;
    s1.input();
    s1.display();
    s1.schedule();
    // s1.display();
    
  
}