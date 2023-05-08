#include<iostream>
using namespace std;
void heapify(int* arr,int heapsize,int k){
    int largest = k;
    int l = 2*k +1;
    int r = 2*k+2;
    if(l<=heapsize && arr[l]>arr[largest])
        largest = l;
    if(r<=heapsize && arr[r]>=arr[largest])
        largest = r;
    if(largest != k){
        swap(arr[k],arr[largest]);
        heapify(arr,heapsize,largest);
    }
}
void BuildHeap(int arr[],int n){
    int heapsize = n-1;
    for(int i = n/2 -1; i>=0;i--){
        heapify(arr,heapsize,i);
    }
    cout<<"The build heap is:-";
    for(int i =0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}


void Heapsort(int* arr,int n){
    BuildHeap(arr,n);
    int heapsize = n-1;
    for(int i =heapsize; i>=0;i--){
        swap(arr[0],arr[i]);
        heapsize--;
        heapify(arr,heapsize,0);
    }
}

int main(){
    int *arr,n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    cout<<"Enter the elements of array:";
    arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    Heapsort(arr,n);
    cout<<"The sorted array is:-";
    for(int i =0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}













#include<iostream>
using namespace std;
void heapify(int* arr, int n,int k){
    int largest = k;
    int l = 2*k+1;
    int r = 2*k+2;
    if(l<n && arr[l] > arr[largest])
        largest = l;
    if(r<n && arr[r] >= arr[largest])
        largest = r;
    if(largest !=k){
        swap(arr[k], arr[largest]);
        heapify(arr,n,largest);
    }
}
void buildheap(int* arr,int n){
    for(int i = n/2 -1; i>=0; i--)
        heapify(arr,n,i);
}
void heapsort(int* arr,int n){
    buildheap(arr,n);
    for(int i = n-1; i>=0; i--)
    {
        swap(arr[i],arr[0]);
        n--;
        heapify(arr,n,0);
    }
}
int main(){
    int n,*arr;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    cout<<"Enter the elements of array:";
    arr = new int[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    heapsort(arr,n);
    for(int i = 0; i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}