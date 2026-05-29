#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int val;
};

class Queue{
    Node* head=NULL;
    public:
    Queue(){
        head=NULL;
    }
    void push(int x){
        Node* curr=new (Node);
        curr->val=x;
        curr->next=NULL;
        if(head==NULL){
            head=curr;
        }else{
            Node* p=head;
            while(p->next!=NULL){
                p=p->next; 
            }
            p->next=curr;
        }
    }

    void pop(){
        if(head==NULL){
            cout<<"Queue is Empty";
        }else{
            Node* temp =head;
            head=head->next;
            delete temp;
        }
    }

    int front(){
        if(head == NULL){
            cout << "Queue is Empty\n";
            return -1;
        }
        return head->val;
    }

    bool empty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
};


int main(){
    Queue q;

    // push elements
    q.push(10);
    q.push(20);
    q.push(30);

    // check front
    cout << "Front: " << q.front() << endl;

    // pop one element
    q.pop();
    cout << "Front after one pop: " << q.front() << endl;

    // pop all
    q.pop();
    q.pop();

    // try popping from empty
    q.pop();

    // check empty
    if(q.empty()){
        cout << "Queue is empty\n";
    } else {
        cout << "Queue is not empty\n";
    }

    return 0;
}