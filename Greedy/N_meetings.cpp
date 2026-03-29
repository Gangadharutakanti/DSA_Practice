#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool static comparator(const tuple<int,int,int>&a,const tuple<int,int,int>&b){
        return get<1> (a) >get<1> (b);
    }
    vector<int> meetings(vector<int>&start,vector<int>&end){
        vector<tuple<int,int,int>>vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({start[i],end[i],i+1});
        }
        sort(vec.begin(),vec.end(),comparator);
        int lasttime=-1;
        vector<int>ans;
        for(auto c:vec){
            int first=get<0> (c);
            int last=get<1> (c);
            int position=get<2>(c);
            if(first>lasttime){
                ans.push_back(position);
                lasttime=last;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    Solution sol;
    vector<int> res = sol.meetings(start, end);

    for (int idx : res) cout << idx << " ";
}