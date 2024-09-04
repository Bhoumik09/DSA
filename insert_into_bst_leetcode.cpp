
 #include<bits/stdc++.h>
 using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*temp=root;
        if(root==NULL){
            return new TreeNode(val);
        }
        while(temp){
            if(temp->val>val){
                if(temp->left==NULL){
                    temp->left=new TreeNode(val);
                    break;
                }
                temp=temp->left;
            }else{
                if(temp->right==NULL){
                    temp->right=new TreeNode(val);
                    break;
                }
                temp=temp->right;
            }
        }
        return root;
    }
};