/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    vector<int> in;
public:
    int kthSmallest(TreeNode* root, int k) {
        
        inOrder(root);
        return in[k-1];
    }
    
    void inOrder(TreeNode * root){
        if(root == NULL){
            return;
        }else{
            inOrder(root->left);
            in.push_back(root->val);
            inOrder(root->right);
        }
    }
};