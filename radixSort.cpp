#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

void countSort(int*arr , int n , int pl){
    int count[10]= {0};
    for(int i =0; i<n;i++) {
        int y = pow(10,pl);
        int x = arr[i] % y/pow(10,pl-1); 
        count[x]++;
    }
    for(int i = 1;i<10; i++){
        count[i]+=count[i-1];
    }
    int* res= new int[n];
    for(int i =n-1;i>=0; i--){
        int y = pow(10,pl);
        int x = arr[i] % y/pow(10,pl-1); 
        res[--count[x]] = arr[i];  
    }
    for(int i= 0; i<n;i++) arr[i]= res[i];
    delete []res;
}

void radixSort(int* arr, int n){
    int max = *max_element(arr,arr+n);
    int d = floor(log10(max)) +1;
    for(int i = 1;i<=d;i++){
        countSort(arr,n,i);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements of array: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of array: ";
    for(int i =0; i<n;i++)
        cin>>arr[i];
    radixSort(arr,n);
    for(int i =0; i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}