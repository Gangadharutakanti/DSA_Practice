#include<iostream>
using namespace std;
int main (){
    for(int i=0;i<5;i++){
        for(int j=0;j<i+1;j++){
            cout<<char(69+j-i);
            cout<<"\t";
        }
        cout<<'\n';
    }
    return 0;
}