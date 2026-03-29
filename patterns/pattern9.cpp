#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<4;i++){
        for(int j=1;j<i+2;j++){
            cout<<j;        
        }
        for(int j=0;j<4-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<4-i-1;j++){
            cout<<" ";
        }
        for(int j=i+1;j>0;j--){
            cout<<j;        
        }
        cout<<'\n';
    }
    return 0;
}