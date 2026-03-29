#include<iostream>
#include<vector>
#include<map>
using namespace std;
int positivesubArray(vector<int>&vec,int n,int k){
    int left=0;
    int right=0;
    int maxLen=0;
    int sum=0;
    while(right<n){
        sum+=vec[right];
        while(left<=right&&sum>k){
            sum-=vec[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        
        
        right++;
    }
    return maxLen;
}
int main(){
    int n;
    cout<<"enter Array size:";
    cin>>n;
    int k;
    cout<<"enter K value:";
    cin>>k;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int max=positivesubArray(vec,n,k);
    cout<<"Maximium subArray:"<<max<<endl;
    return 0;
}