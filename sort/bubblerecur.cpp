#include<iostream>
using namespace std;
void bubble_recur(int*,int);
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++){
        cin>>arr[j];
    }
    bubble_recur(arr,n);
    cout<<"sorted Array:";
    for(int j=0;j<n;j++){
        cout<<arr[j]<<"\t";
    }
    return 0;
}

void bubble_recur(int *arr,int n){
    if(n==1) return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    bubble_recur(arr,n-1);
}