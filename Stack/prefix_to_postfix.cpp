#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s){
    stack<string>s1;
    int n=s.size();
    for(int i=n-1;i>=0;i++){
        char c=s[i];
        if(isalnum(c)){
            string temp="";
            temp+=c;
            s1.push(temp);
        }else{
            string op1=s1.top();
            s1.pop();
            string op2=s1.top();
            s1.pop();
            string result=op1+op2+c;
            s1.push(result);
        }
    }
    return s1.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}