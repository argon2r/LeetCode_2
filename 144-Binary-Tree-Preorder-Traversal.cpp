// Method-1 : PreOrder RECURSIVE
// class Solution {
// public:

//     void preOrder(TreeNode* root , vector<int> &ans){
//         if(root == NULL) return;
//         ans.push_back(root->val);
//         preOrder(root->left , ans);
//         preOrder(root->right , ans);

//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preOrder(root , ans);
//         return ans;         
//     }
// };

// Method -2  Iterative 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root!=NULL)st.push(root);
        while( st.size()>0 ){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
        
        return ans;         
    }
};