/*Problem Statement: We are given two arrays that represent the arrival and departure times of
 trains that stop at the platform. We need to find the minimum number of platforms needed at 
 the railway station so that no train has to wait.*/

 #include<bits/stdc++.h>
 using namespace std;

 class Solution{
    public:
    int no_of_platforms(vector<int>&Arrive,vector<int>&dep){
        int n=Arrive.size();
        sort(Arrive.begin(),Arrive.end());
        sort(dep.begin(),dep.end());
        int max_platform=1;
        int curr_platform=1;
        int i=1;
        int j=0;
        while(i<n && j<n){
            if(Arrive[i]<=dep[j]){
                curr_platform++;
                max_platform=max(max_platform,curr_platform);
                i++;
            }else{
                curr_platform--;
                j++;
            }
        }
        return max_platform;
    }
 };

 int main(){
     int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

     vector<int> arrival(arr, arr + n);
    vector<int> departure(dep, dep + n);

    // Create Solution object and call function
    Solution obj;
    cout << "Minimum number of Platforms required "
         << obj.no_of_platforms(arrival, departure) << endl;

    return 0;
 }