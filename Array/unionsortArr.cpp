#include<iostream>
#include<vector>
#include<set>
using namespace std;

void ReadArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void unionsort(int *arr,int *arr2,vector<int> &unionvec,int n){
    set<int>vec;
    for(int i=0;i<n;i++){
        vec.insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        vec.insert(arr2[i]);
    }
    for(int val:vec){
        unionvec.push_back(val);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    vector<int> unionvec;
    ReadArray(arr,n);
    ReadArray(arr2,n);
    unionsort(arr,arr2,unionvec,n);
    cout<<"UNION ARRAY:";
    for(int val:unionvec){
        cout<<val<<"\t";
    }
    return 0;
}



/** vector<int> unionSorted(int arr[], int arr2[], int n) {
    vector<int> res;
    int i=0, j=0;
    while(i<n && j<n) {
        if(arr[i] < arr2[j]) {
            if(res.empty() || res.back() != arr[i])
                res.push_back(arr[i]);
            i++;
        } else if(arr[i] > arr2[j]) {
            if(res.empty() || res.back() != arr2[j])
                res.push_back(arr2[j]);
            j++;
        } else { // equal
            if(res.empty() || res.back() != arr[i])
                res.push_back(arr[i]);
            i++; j++;
        }
    }
    while(i<n) { if(res.back() != arr[i]) res.push_back(arr[i]); i++; }
    while(j<n) { if(res.back() != arr2[j]) res.push_back(arr2[j]); j++; }
    return res;
}**/
