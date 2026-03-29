#include<iostream>
using namespace std;
int main(){
    int k=1;
    for(int i=0;i<5;i++){
        if(i%2==0){
            k=1;
        }else{
            k=0;
        }
        for(int j=i+1;j>0;j--){
            if(k){
                cout<<k;
                k=0;
            }else{
                cout<<k;
                k=1;
            }
        }
        cout<<'\n';
    }
    return 0;
}