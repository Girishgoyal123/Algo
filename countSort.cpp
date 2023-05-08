#include<iostream>
#include<algorithm>
using namespace std;

void countSort(int*arr,int n){
    int max = *max_element(arr,arr+n);
    int min = *min_element(arr,arr+n);
    int range = max - min +1;
    int* count = new int[range];

    for(int i = 0; i<n; i++)
    {
        count[arr[i]-min]++;
    }

    for(int i = 1 ; i<range; i++)
    {
        count[i] = count[i]+count[i-1];
    }

    int* res = new int[n];
    for(int i = n-1; i>=0; i--)
    {
        res[--count[arr[i]-min]] = arr[i];
    }

    for(int i = 0;i<n;i++) arr[i] = res[i];

    delete []res;
    delete []count;
}

int main(){
    int n;
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"enter the elements of array ";
    int *arr = new int[n];
    for(int i =0; i<n; i++) cin>>arr[i];
    countSort(arr,n);
    for(int i =0; i<n; i++) cout<<arr[i]<<" ";
}