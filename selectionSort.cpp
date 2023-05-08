#include<bits/stdc++.h>
using namespace std;

void select(int* arr,int n){
    for(int i = 0;i<n-1; i++){
        int min =i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min])
                min = j;
        }
        if(min!=i)
        swap(arr[min],arr[i]);
    }
}
int main(){
    int n;
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"enter the elements of array ";
    int *arr = new int[n];
    for(int i =0; i<n; i++) cin>>arr[i];
    select(arr,n);
    for(int i =0; i<n; i++) cout<<arr[i]<<" ";
}