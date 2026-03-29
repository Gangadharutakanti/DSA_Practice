#include<iostream>
using namespace std;
int ispalimdrome(string);
int main(){
    string name;
    cin>>name;
    int str=ispalimdrome(name);
    if(str){
        cout<<"palimdone";
    }else{
        cout<<"Not palimdrone";
    }
}

int ispalimdrome(string name){
    int left=0;
    int right=name.size()-1;
    while(left<right){
        if(!isalnum(name[left])){
            left++;
        }else if(!isalnum(name[right])){
            right--;
        }else if(name[left]!=name[right]){
            return 0;
        }else{
            left++;
            right--;
        }
    }
    return 1;
}