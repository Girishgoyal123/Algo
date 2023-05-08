#include<iostream>
#include<climits>
using namespace std;
void merge(int arr[],int f, int mid, int l){
    int n1 = mid-f+1;
    int n2 = l-mid;
    int* left = new int[n1+1];
    int* right = new int[n2+1];
    for(int i = 0 ;i<n1;i++) left[i]= arr[i+f];
    for(int i = 0; i<n2; i++) right[i] = arr[mid+1+i];
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    int i,j,k;
    for( i = 0,j=0,k=f; k<=l;k++ ){
        if(left[i]<=right[j])
            arr[k]= left[i++];
        else
            arr[k] = right[j++];
    }
}
void mergesort(int arr[],int f,int l){
    if(f>=l) return;
    int mid = (f+l)/2;
    mergesort(arr,f,mid);
    mergesort(arr,mid+1,l);
    merge(arr,f,mid,l);
}
int main()
{   
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the elements of array: ";
    for(int i =0;i<n;i++)
        cin>>arr[i];
    
    mergesort(arr,0,n-1);
    for(int i =0;i<n;i++)
        cout<<arr[i]<<" ";
}