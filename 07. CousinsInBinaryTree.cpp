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
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL || root->val == x || root->val == y){
            return false;
        }
        
        bool res = helperSolve(root,x,y);
        return res;
    }
    
    bool helperSolve(TreeNode* root, int x, int y){
        
        int levelX = findLevel(root,x,0);
        int levelY = findLevel(root,y,0);
        
		//Find the levels of x and y
		//And if they are same then check if they are siblings or not
        if(levelX == levelY){
            if(!isSibling(root,x,y)){
                return true;
            }
        }
        return false;
    }
    
    bool isSibling(TreeNode* root, int x, int y){
        if(root == NULL){
            return false;
        }
        
        if(root->left != NULL && root->right != NULL){
            if(root->left->val == x && root->right->val == y || root->left->val == y && root->right->val == x){
                return true;   
            }
        }
        return isSibling(root->left,x,y) || isSibling(root->right,x,y);
    }
    
    int findLevel(TreeNode* root, int x ,int k){
        if(root == NULL){
            return 0;
        }else if(root->val == x){
            return k;
        }
        
        int levelL = findLevel(root->left,x,k+1);
        if(levelL != 0){
            return levelL;
        }
        
        int levelR = findLevel(root->right,x,k+1);
        return levelR;
        
    }
};