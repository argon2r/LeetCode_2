class Solution {
public:

    bool exist(TreeNode* root, TreeNode* target){
        if(root == NULL) return false;
        if(root == target) return true;
        return exist(root->left , target) || exist(root->right , target);
    }
    

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;

        bool p_in_left = exist(root->left, p);
        bool q_in_left = exist(root->left, q);

        // If both p and q are on the left side
        if (p_in_left && q_in_left) return lowestCommonAncestor(root->left, p, q);
        
        // If both p and q are on the right side
        if (!p_in_left && !q_in_left) return lowestCommonAncestor(root->right, p, q);

        // If p and q are on different sides
        return root;
    }


    // ------------------------Short version -----------------------------
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(exist(root->left , p) && exist(root->left , q)) return lowestCommonAncestor(root->left , p , q);
    //     else if(exist(root->right , p) && exist(root->right , q)) return lowestCommonAncestor(root->right , p , q);
    //     return root;

    // }
};