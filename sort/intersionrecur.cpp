#include<iostream>
using namespace std;
void insertion_recur(int*,int,int);
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertion_recur(arr,0,n);
    cout<<"after sorting Array:";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}

void insertion_recur(int *arr,int n1,int n){
    if(n1==n-1) return;
    int j=n1+1;
    int temp=arr[j];
    while(arr[j-1]>temp&&j>0){
        arr[j]=arr[j-1];
        j--;
    }
    arr[j]=temp;
    insertion_recur(arr,n1+1,n);
}