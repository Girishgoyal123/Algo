#include<iostream>
using namespace std;

void preorder(int*arr,int n,int k){
    if(k>=n) return;
    int l = 2*k+1;
    int r = 2*k+2;
    cout<<arr[k]<<" ";
    preorder(arr,n,l);
    preorder(arr,n,r);   
}
void inorder(int*arr,int n,int k){
    if(k>=n) return;
    int l = 2*k+1;
    int r = 2*k+2;
    preorder(arr,n,l);
    cout<<arr[k]<<" ";
    preorder(arr,n,r);   
}

void postorder(int*arr,int n,int k){
    if(k>=n) return;
    int l = 2*k+1;
    int r = 2*k+2;
    preorder(arr,n,l);
    preorder(arr,n,r);
    cout<<arr[k]<<" ";   
}

int main(){
    int n;
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"enter the elements of tree ";
    int *arr = new int[n];
    for(int i =0; i<n; i++) cin>>arr[i];
    preorder(arr,n,0);
    //for(int i =0; i<n; i++) cout<<arr[i]<<" ";
}