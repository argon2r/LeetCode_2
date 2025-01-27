//-------------------Method-1 : RECURSIVE------------------------
// class Solution {
// public:
//     void inOrder(TreeNode* root , vector<int> &ans){
//         if(root == NULL) return;
//         inOrder(root->left , ans);
//         ans.push_back(root->val);
//         inOrder(root->right , ans);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inOrder(root , ans);
//         return ans;      
//     }
// };

//-----------Metod-2 : ITERATIVE------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(st.size()>0 || node){
            if(node){
                st.push(node);
                node = node->left;
            }
            else{
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                node = temp->right;
            }
        }
        return ans; 
    }
};