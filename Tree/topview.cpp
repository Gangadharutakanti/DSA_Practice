#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
class Solution{
    public:
        vector<int> topView(Node* root){
            if(root==NULL) return {};
            map<int,int>m1;
            queue<pair<Node*,int>>q;
            vector<int>vec;
            q.push({root,0});
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                Node* node=p.first;
                if(m1.find(p.second)==m1.end()){
                    m1[p.second]=node->data;
                }
                if(node->left){
                    q.push({node->left,p.second-1});
                }
                if(node->right){
                    q.push({node->right,p.second+1});
                }
            }
            for(auto p:m1){
                vec.push_back(p.second);
            }
            return vec;
        }
};

int main() {
    // Create the sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create a Solution object
    Solution solution;

    // Get the top view
    vector<int>result = solution.topView(root);

    // Print the top view traversal
    cout << "Top View Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    return 0;
}
