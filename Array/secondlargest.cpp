#include<iostream>
#include<limits.h>
using namespace std;
int second_large(int*,int);
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int large=second_large(arr,n);
    if(large==INT_MIN){
        cout<<"There is no second largest"<<endl;
    }else
        cout<<"Second largest:"<<large<<endl;
    return 0;
}
int second_large(int *arr,int n){
    int large=arr[0];
    int second=INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>large){
            second=large;
            large=arr[i];
        }else if(arr[i]>second&&large!=arr[i]){
            second=arr[i];
        }
    }
    return second;
}