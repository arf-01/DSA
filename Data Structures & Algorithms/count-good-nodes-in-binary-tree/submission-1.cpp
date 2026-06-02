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

    int  godNodes(TreeNode* root, int mx  )
    {   
        if(root==nullptr)  return 0 ;

        //if(root->val >= mx) count++;

        mx=max(root->val,mx);

       // godNodes(root->left ,mx );
        //godNodes(root->right ,mx);


        if(root->val >= mx) 
        {
            return godNodes(root->left ,mx )+godNodes(root->right ,mx)+1;
        }

        else
        {
            return godNodes(root->left ,mx )+godNodes(root->right ,mx);
        }
        


    }

    int goodNodes(TreeNode* root) {

       // int mx=(-1e5);
        //int count=0;

         return godNodes(root,root->val);
        //return count;


        
    }
};