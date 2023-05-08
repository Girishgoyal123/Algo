#include<iostream>
#include<cstdlib>
using namespace std;
int lomuto(int arr[],int f, int l){
    int pivot = arr[l];
    int i = f-1;
    for(int j = f; j<l; j++){
        if(arr[j]<=pivot)
            swap(arr[++i],arr[j]);
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}
int randomPart(int arr[],int f, int l){
    srand(time(0)) ;
    int rd = rand()%(l-f+1)+f;
    swap(arr[rd],arr[l]);
    int pivot = arr[l];
    int i = f-1;
    for(int j = f; j<l; j++){
        if(arr[j]<=pivot)
            swap(arr[++i],arr[j]);
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}

int hoare(int arr[], int f, int l){
    int pi = (f+l)/2;
    int i = f-1;
    int j = l+1;
    while(true){
        do {i++;
        }while(arr[i]<arr[pi]) ;
        do {j--;
        }while(arr[j]>arr[pi]);
        if(i<j) swap(arr[i],arr[j]);
        else{ 
            return j;
            cout<<"hi\n";
        }
    }
}
void qs1(int arr[],int f,int l){
    if(f>=l)
        return;
    int p = lomuto(arr,f,l);
    qs1(arr,f,p-1);
    qs1(arr,p+1,l);
}
int main(){
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the elements of array: ";
    for(int i =0;i<n;i++)
        cin>>arr[i];
    
    qs1(arr,0,n-1);
    for(int i =0;i<n;i++)
        cout<<arr[i]<<" ";
}