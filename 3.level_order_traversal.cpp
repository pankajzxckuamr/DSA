// till now, we have done with the help of DFS

// now with BFS(breadth force search)

// print elements of nth level


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


// preOrder= root left right // leetcode 144
void preOrder(Node* root){
    if(root == NULL) return; // base case
    cout<<root->val<<" "; // work
    preOrder(root->left); // call 1 // left
    preOrder(root->right); // call 2 // right
}

// nth level print

void nthLevel(Node* root, int curr, int level){
    if(root == NULL) return; // base case
    // if (curr == level) cout<<root->val<<" "; it is not good as TC and SC is more than whcih is written below in optimised way 
    if(curr == level){
        cout<<root->val<<" ";
        return; 
    }
    // it is preOrder using level order tranversal. it is insane that if we do pre, in or post using level order technique all give the same result
    nthLevel(root->left, curr+1, level); // call 1 // left
    nthLevel(root->right, curr+1, level); // call 2 // right
}


// levels
int levels(node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

// level order traversal // dfs using loop
void levelOrder(Node* root){
    int n = levels(root);
    for(int i = 1; i<n; i++){
        nthLevel(root, 1, i);
        cout<<endl;
    }
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

    nthLevel(a, 1, 1);
}


// TC = O(n) // where n is the number of nodes
// SC = maximum elements is stack(it creates as recursion always do so) is always equal to number of levels of the tree. 
// SC = O(levels+1) or approx. O(height + 2) or approx. O(height) // it is same in all threr cases pre,in post
// it is O(h), usually we consider O(n) in avg. case or worst case(degenrate tree) . and in best case (balanced tree) it is O(log n). 
