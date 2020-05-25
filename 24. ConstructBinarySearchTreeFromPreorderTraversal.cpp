/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        unordered_map<int,int> umap;
        int n;
        vector<int> inorder;
        int preInd = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        for(int i = 0; i < n; i++){
            inorder.push_back(preorder[i]);
        }
        
        sort(inorder.begin(),inorder.end());
        
        for(int i = 0; i < n; i++){
            umap[inorder[i]] = i;
        }
        
        TreeNode* root = constructBST(preorder,0,n-1);
        
        return root;
    }
    
    TreeNode* constructBST(vector<int> &preorder,int low, int high){
        if(low > high){
            return NULL;
        }
        
        int item = preorder[preInd++];
        TreeNode* node = new TreeNode(item);
        
        if(low == high){
            return node;
        }
        
        int ind = umap[item];
        
        node->left = constructBST(preorder, low, ind -1);
        node->right = constructBST(preorder, ind + 1, high);
        
        return node;
        
    }
};