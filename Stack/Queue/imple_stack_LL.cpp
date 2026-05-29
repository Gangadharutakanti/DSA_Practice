#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class LL {
    Node* head;

public:
    LL() {
        head = NULL;
    }

    Node* createNode(int x) {
        Node* p = new Node();
        p->val = x;
        p->next = NULL;
        return p;
    }

    void push(int x) {
        Node* node = createNode(x);

        if (!head) {
            head = node;
        } else {
            Node* p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = node;
        }
    }

    Node* pop() {
        if (!head) return NULL;

        if (head->next == NULL) {
            Node* temp = head;
            head = NULL;
            return temp;
        }

        Node* prev = NULL;
        Node* curr = head;

        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        return curr;
    }

    void display() {
        Node* p = head;
        while (p != NULL) {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }
};