#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
 
void bucketSort(double* arr,int n,int nb){
    int max = *max_element(arr,arr+n);
    int d;
    if(max>1){
         d = floor(log10(max))+1;
    }
    vector<double> b[nb];
    for(int i = 0; i<n ;i ++){
        int ib = floor(arr[i]*nb/pow(10,d)); // index in bucket
        b[ib].push_back(arr[i]);
    }

    for(int i =0; i<nb; i++)
        sort(b[i].begin(),b[i].end());

    int index = 0;
    for(int i = 0;i<nb;i++){
        for(int j = 0; j<b[i].size();j++){
            arr[index++] = b[i][j];
        }
    }
}


int main(){
    int n,nb;
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"Enter the no. of buckets ";
    cin>>nb;
    cout<<"enter the elements of array ";
    double *arr = new double[n];
    for(int i =0; i<n; i++) cin>>arr[i];
    bucketSort(arr,n,5);
    for(int i =0; i<n; i++) cout<<arr[i]<<" ";
}