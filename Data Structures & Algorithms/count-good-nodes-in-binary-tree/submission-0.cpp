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

    void godNodes(TreeNode* root, int mx , int &count )
    {   
        if(root==nullptr)  return ;

        if(root->val >= mx) count++;

        mx=max(root->val,mx);

        godNodes(root->left ,mx ,count);
        godNodes(root->right ,mx ,count);
    }

    int goodNodes(TreeNode* root) {

        int mx=(-1e5);
        int count=0;

        godNodes(root,mx,count);
        return count;


        
    }
};