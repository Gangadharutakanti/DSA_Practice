#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

class Queue{
public:
    Node* head;
    Node* tail;

    Queue(){
        head = tail = NULL;
    }

    void push(int x){
        Node* curr = new Node();
        curr->val = x;
        curr->next = NULL;

        if(head == NULL){
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
    }

    void pop(){
        if(head == NULL){
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if(head == NULL){
            tail = NULL;
        }
    }

    int front(){
        if(head == NULL){
            cout << "Queue is empty\n";
            return -1;
        }
        return head->val;
    }

    bool empty(){
        return head == NULL;
    }
};