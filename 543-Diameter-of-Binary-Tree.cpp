class Solution {
public:
    // int maxDia = 0;
    // int levels(TreeNode* root){
    //     if(root==NULL) return 0;
    //     return 1 + max(levels(root->left) , levels(root->right));
        
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int Dia = levels(root->left) + levels(root->right);
    //     maxDia = max(maxDia , Dia);
    //     diameterOfBinaryTree(root->left);
    //     diameterOfBinaryTree(root->right);
    //     return maxDia;
    // }

// Interviwer doesn't like using global variable in the code
// so this code was used 
// helper fn and maxDia as reference are used to remove the use of global varriable
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }

    void helper(TreeNode* root , int &maxDia){
        if(root == NULL) return;
        int Dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia , Dia);
        helper(root->left  , maxDia);
        helper(root->right , maxDia);    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root , maxDia);
        return maxDia;
    }
};