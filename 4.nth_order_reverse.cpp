void nthLevelReverse(Node* root, int curr, int level){
    if(root == NULL) return; // base case
    // if (curr == level) cout<<root->val<<" "; it is not good as TC and SC is more than whcih is written below in optimised way 
    if(curr == level){
        cout<<root->val<<" ";
        return; 
    }
    // it is preOrder using level order tranversal. it is insane that if we do pre, in or post using level order technique all give the same result
    nthLevelReverse(root->right, curr+1, level); // call 2 // right
    nthLevelReverse(root->left, curr+1, level); // call 1 // left

}

// we interchange left and right
