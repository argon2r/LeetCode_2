class Solution {
public:
    // this fn is for traversal from the node(root) that is called
    void helper(TreeNode* root , long long sum , int &count){
        if(root==NULL) return;
        if(root->val == sum){
            count++;
        }
        helper(root->left , sum-(long long) (root->val) , count);
        helper(root->right , sum-(long long) (root->val), count);
    }

    // main fn
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count = 0;
        helper(root , targetSum , count);  //this call is used to traverse till end from any node that is called below
        count += pathSum(root->left , targetSum) + pathSum(root->right , targetSum);
        return count;
    }
};