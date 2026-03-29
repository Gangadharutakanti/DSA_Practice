#include<bits/stdc++.h>
using namespace std;

class ShortestJobFirst{
    public:
    int calculateAverageWaitTime(vector<int>&vec){
        sort(vec.begin(),vec.end());
        int waiting=0;
        int totaltime=0;
        for(auto c:vec){
            waiting+=totaltime;
            totaltime+=c;
        }
        return waiting/vec.size();
    }
};

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for (int job : jobs) cout << job << " ";
    cout << endl;

    ShortestJobFirst sjf;
    float ans = sjf.calculateAverageWaitTime(jobs);

    cout << "Average waiting time: " << ans << endl;
    return 0;
}