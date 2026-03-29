#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool isMinHeap(vector<int>&nums){
        int size1=nums.size();
        
        for(int i=0;i<(size1/2);i++){
            if((2*i+1)<size1&&nums[i]>nums[2*i+1]){
                return false;
            }
            if((2*i+2)<size1&&nums[i]>nums[2*i+2]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {10, 20, 30, 21, 23};

    // Output result
    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    return 0;
}