#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    void convert(vector<int>&nums,int i){
        int size=nums.size();
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<size&&nums[largest]<nums[l] ){
            largest=l;
        }
        if(r<size&&nums[largest]<nums[r]){
            largest=r;
        }
        if(largest!=i){
            swap(&nums[largest],&nums[i]);
            convert(nums,largest);
        }
    }

    void swap(int* x,int* y){
        int t=*x;
        *x=*y;
        *y=t;
    }
};

int main(){
    vector<int> nums = {1,3,5,7,9,2};
    Heap h;
    for(int i=nums.size()/2-1;i>=0;i--){
        h.convert(nums,i);
    }
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
