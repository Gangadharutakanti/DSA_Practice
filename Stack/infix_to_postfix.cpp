#include<bits/stdc++.h>
using namespace std;


int pre(char c){
    if(c=='+' || c=='-'){
        return 1;
    }else if(c=='*' || c=='/'){
        return 2;
    }else if(c=='^'){
        return 3;
    }else{
        return -1;
    }
}
void infixToPostfix(string s){
    string out="";
    stack<char>s1;
    int n=s.size();
    for(int i=0;i<n;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='0'&&s[i]<='9' )){
            out+=s[i];
        }else{
            if(s[i]=='('){
                s1.push(s[i]);
            }else if(s[i]==')'){
                while(s1.top()!='('){
                    out+=s1.top();
                    s1.pop();
                }
                s1.pop();
            }else{
                char c=s[i];
                while(!s1.empty() &&((pre(c)<pre(s1.top()))|| (pre(c) == pre(s1.top()) && s[i] != '^'))){
                    out+=s1.top();
                    s1.pop();
                }
                s1.push(c);
            }
        }
    }

    while(!s1.empty()){
        out+=s1.top();
        s1.pop();
    }

    cout << "Postfix expression: " << out << endl;

}

int main() {
    string exp = "(p+q)*(m-n)";  // Infix expression
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp);  // Convert the infix expression to postfix
    return 0;
}