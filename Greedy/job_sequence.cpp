#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};
class Solution{
    public:
    bool static comparator(Job a,Job b){
        return a.profit>b.profit;
    }
    pair<int,int> JobScheduling(Job arr[],int n){
        sort(arr,arr+n,comparator);
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }

        int slots[maxi+1];

        for(int i=0;i<maxi+1;i++){
            slots[i]=-1;
        }
        int count=0;
        int job_profit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slots[j]==-1){
                    slots[j]=i;
                    count++;
                    job_profit+=arr[i].profit;
                    break;
                }
            }
        }
        return {count,job_profit};
    }
};

int main() {
   // Driver code
   int n = 4;
   // Define jobs with id, deadline, and profit
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   // Function call to find the number of jobs done and total profit
   pair < int, int > ans = ob.JobScheduling(arr, n);

   // Output the number of jobs and the total profit
   cout << ans.first << " " << ans.second << endl;

   return 0;
}