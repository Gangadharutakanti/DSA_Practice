#include<bits/stdc++.h>
using namespace std;
class kthSum{
    public:
    vector<int> KthSumA(vector<int>arr1,vector<int>arr2,int k){
        priority_queue<tuple<int,int,int>>pq;
        sort(arr1.begin(),arr1.end(),greater<int>());
        sort(arr2.begin(),arr2.end(),greater<int>());
        pq.push({arr1[0]+arr2[0],0,0});
        set<pair<int,int>>visited;
        visited.insert({0,0});
        vector<int>result;
        while(k-- && !pq.empty()){
            auto [largest,i,j]=pq.top();
            pq.pop();
            result.push_back(largest);
            if(i+1<arr1.size() && !visited.count({i+1,j})){
                pq.push({arr1[i+1]+arr2[j],i+1,j});
                visited.insert({i+1,j});
            }
            if(j+1<arr2.size() && !visited.count({i,j+1})){
                pq.push({arr1[i]+arr2[j+1],i,j+1} );
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};


int main() {
    kthSum sol;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = sol.KthSumA(nums1, nums2, k);
    for(int val : result) cout << val << " ";
    return 0;
}