#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<4;i++){
        for(int j=4-i-1;j>0;j--){
            cout<<' ';
        }
        for(int j=0;j<i+1;j++){
            cout<<char(65+j);
        }
        for(int j=i;j>0;j--){
            cout<<char(65+j-1);
        }
        cout<<'\n';
    }
    return 0;
}