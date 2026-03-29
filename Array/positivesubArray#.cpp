#include<iostream>
#include<vector>
#include<map>
using namespace std;
int positivesubArray(vector<int>&vec,int n,int k){
    map<long long,int>prev;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        sum+=vec[i];
        int rem=sum-k;
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        if(prev.find(rem)!=prev.end()){
            int max1=i-prev[rem];
            maxLen=max(maxLen,max1);
        }
        if(prev.find(sum)==prev.end()){
            prev[sum]=i;
        }
    }
    return maxLen;
}
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    int k;
    cout<<"enter K value";
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int maxLen=positivesubArray(vec,n,k);
    cout<<"maxLen:"<<maxLen<<endl;
    return 0;
}