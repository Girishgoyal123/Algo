#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        for(j; j>=0 &&arr[j]>current;j--){
                arr[j+1] = arr[j];                
        }
        swap(arr[j+1],current);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i =0; i<n;i++)
        cin>>arr[i];
    insertionSort(arr,n);
    for(int i =0; i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}