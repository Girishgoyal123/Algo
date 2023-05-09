#include<bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int finish;
};
bool compareActivity(activity i1, activity i2) {
    return (i1.finish < i2.finish);
}
class Schedule{
    activity* request;
    activity* originalrequest;
    set<int> s;
    int n;
    public:
    
    void input(){
        cout<<"enter the number of requests: ";
        cin>>n;
        request=new activity[n];
        originalrequest=new activity[n];
        for(int i=0;i<n;i++){
            cout<<"For "<<i+1<<" request\n";
            cout<<"Enter start and finish time: ";
            cin>>request[i].start>>request[i].finish;
        }
        for(int i=0;i<n;i++){
            originalrequest[i]=request[i];
        }
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        
    }

    void schedule(){
        sort(request,request+n,compareActivity);
        set<int> a;
        set<int> temp;
        while(!s.empty()){
            set<int>::iterator it=s.begin();
            int ans=*it;
            temp=s;
            a.insert(ans);
            for(auto i:s){
                if(request[i].start < request[ans].finish){
                    temp.erase(i);
                }
            }
            s.clear();
            s=temp;
            temp.clear();
        }
        set<int> answer;
        for(auto m:a){
            for(int i=0;i<n;i++){
                if(request[m].finish == originalrequest[i].finish && request[m].start==originalrequest[i].start){

                    answer.insert(i);
                }
            }
        }
        cout<<"Requests will be in processed in following order:\n";
        for(auto i: answer){
            cout<<i+1<<" ";
        }cout<<endl;
    }
    void display(){
       
        for(int i=0;i<n;i++){
            cout<<i<<endl;
            cout<<originalrequest[i].start<<" "<<originalrequest[i].finish<<endl;
        }
    }
};
int main(){
    int n=9;
    Schedule s1;
    s1.input();
   
    s1.schedule();
    
}