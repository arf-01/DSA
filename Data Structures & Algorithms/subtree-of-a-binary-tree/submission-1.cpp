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

   bool check(TreeNode* root, TreeNode* subRoot)
   {
       if(root==nullptr && subRoot==nullptr) return true;

       else if(root!=nullptr && subRoot!=nullptr && root->val==subRoot->val) 
       {

           return  (check(root->left,subRoot->left) && check(root->right,subRoot->right));
            
       }

       else  return false;



   }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

       if(root==nullptr) return false;

       else if(root->val==subRoot->val)
       {   
           TreeNode* subroot= subRoot;
           if( check(root,subroot))
           {
               return true;
           }
       }

     return  ( isSubtree(root->left,subRoot) ||  isSubtree(root->right,subRoot));
      


        

       
        
    }
};