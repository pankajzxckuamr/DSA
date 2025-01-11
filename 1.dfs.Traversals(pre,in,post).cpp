// traversals in tree  
// traversal means= using loop, visit to all the elements( in this case node) of a particular data structure. 

// two main traversal technique= 1. DFS(Depth ), 2. BFS, 3. MORIS traversal


#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void displayTree(Node* root){
    if(root == NULL) return; // base case
    cout<<root->val<<" "; // work
    displayTree(root->left); // call 1
    displayTree(root->right); // call 2
}

// learnings: 6 possible to get the nodes= preorder- work -> call 1 -> call2, inOrder- call 1->work -> call 2, postOrder- call 1-> call 2-> work.
                // other three are if we reverse the order of calling the left and right node of recursion.


// preOrder= root left right // leetcode 144
void preOrder(Node* root){
    if(root == NULL) return; // base case
    cout<<root->val<<" "; // work
    preOrder(root->left); // call 1 // left
    preOrder(root->right); // call 2 // right
}

// inOrder= left root right // leetcode 94 
void inOrder(Node* root){
    if(root == NULL) return; // base case
    inOrder(root->left); // call 1 // left
    cout<<root->val<<" "; // work
    inOrder(root->right); // call 2 // right
}

// postOrder= left right root
void postOrder(Node* root){
    if(root == NULL) return; // base case
    postOrder(root->left); // call 1 // left
    postOrder(root->right); // call 2 // right
    cout<<root->val<<" "; // work
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);    
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b-> left = d;
    b->right = e;
    c-> left = f;
    c-> right = g;

}
