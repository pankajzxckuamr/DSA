// nth level (DFS) using stack or recursion 
// level order traversal (using queue) called BFS

// it print the 

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()> 0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
        // in reverse order we need to exchange the condition
    }
    cout<<endl;
}

