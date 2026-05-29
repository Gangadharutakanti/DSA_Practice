#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s){
    int n=s.size();
    stack<string>s1;
    for(int i=n-1;i>=0;i--){
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
            string result='('+op1+c+op2+')';
            s1.push(result);
        }
    }
    return s1.top();
}


int main() {

    string prefix = "*+AB-CD";

    cout << "Prefix expression: " << prefix << endl;

    string infix = prefixToInfix(prefix);

    cout << "Infix expression: " << infix << endl;

    return 0;
}