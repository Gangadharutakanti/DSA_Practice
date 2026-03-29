#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
    Solution(int k,vector<int>vec){
        size=k;
        for(auto p:vec){
            pq.push(p);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }

    int add(int val){
        pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    Solution kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;  // Output: 4
    cout << kthLargest.add(5) << endl;  // Output: 5
    cout << kthLargest.add(10) << endl; // Output: 5
    cout << kthLargest.add(9) << endl;  // Output: 8
    cout << kthLargest.add(4) << endl;  // Output: 8
    return 0;
}