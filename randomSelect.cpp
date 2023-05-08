#include<iostream>
#include<cstdlib>
using namespace std;

int randomPart(int arr[],int f, int l){
    // srand(time(0)) ;
    // int rd = rand()%(l-f+1)+f;
    // swap(arr[rd],arr[l]);
    int pivot = arr[l];
    int i = f-1;
    for(int j = f; j<l; j++){
        if(arr[j]<=pivot)
            swap(arr[++i],arr[j]);
    }
    swap(arr[++i],arr[l]);
    return i;
}

int randomSelect(int *arr,int f,int l, int i){
    if(f==l) return arr[f];
    int p = randomPart(arr,f,l);
    int k = p-f+1;
    if(k==i) return arr[p];
    else if(i>k){
        return randomSelect(arr,p+1,l,i-k);
    }
    else{
        return randomSelect(arr,f,p-1,i);
    }

}

int main(){
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the elements of array: ";
    for(int i =0;i<n;i++)
        cin>>arr[i];
    
    cout<<randomSelect(arr,0,n-1,4);
}

