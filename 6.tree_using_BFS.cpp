#include<iostream>
#include<queue>
using namespace std;

// contruct tree form level order traversal(using queue)
/*
first make new node with the intial value of the array and push back it in the queue
remove the fornt of queue
make node left wiht arr[i] and node right with arr[j]

*/


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

levelOrderQueue(Node* root){
    queue<Node*>q;
    q.push(root);
    while(q.size()> 0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!= NULL) q.push(temp->left);
        if(temp->right!= NULL) q.push(temp->right);
    }
    cout<<endl;

}

Node *construct(int arr[], int n){
    queue<Node*> q;
    Node* root= new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()> 0 && i < n ){
        Node*temp = q.fornt();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i] != INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j != n && arr[j] != INT_MIN) l = new Node(arr[j]);
        else l = NULL;

        temp->left = l;
        temp->right = r;

        if (l != NULL) q.push(l);
        if(r != NULL) q.push(r);

        i+= 2;
        j+= 2;
    }
    return root;
}

int main(){
    // construct
    int arr[] = {1,2,3,4,5,6,INT_MIN,6, INT_MIN, INT_MIN, 7, 8, INT_MIN};
    int  n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    levelOrderQueue(root);
}