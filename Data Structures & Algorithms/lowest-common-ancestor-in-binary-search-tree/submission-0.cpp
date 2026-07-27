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

  void dfs(TreeNode*current , TreeNode* target, vector<int>&m,TreeNode* &x)
  {
      if(!current) return;
      
      m[current->val + 100]++;
      if(m[current->val +100 ]==2) x=current;
      if(current->val==target->val) return ;

     if(target->val < current->val ) dfs(current->left, target, m, x);
     else if(target->val > current->val) dfs(current->right, target, m, x);
  }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x=nullptr;
        vector<int>m(202,0);

        //0 means -100
        dfs(root,p,m,x);
        
        dfs(root,q,m,x);

        return x;
    
    }
};