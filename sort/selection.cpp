#include<iostream>
using namespace std;
void selection(int *arr,int n){
    int mini;
    int j;
    for(int i=0;i<n;i++){
        mini=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp=arr[mini];
        arr[mini]=arr[j];
        arr[j]=temp;
    }
    return;
}
void printArray(int *arr,int n){
    cout<<"Array elemets:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int n;
    cout<<"enter Array(size):";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection(arr,n);
    printArray(arr,n);
    return 0;
}