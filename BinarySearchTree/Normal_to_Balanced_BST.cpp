#include <iostream>
#include<vector>
using namespace std;
template <typename T>
class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };


void inOrder(TreeNode<int>*root,vector<int>&v1){
    if(root==nullptr)return;
    inOrder(root->left,v1);
    v1.push_back(root->data);
    inOrder(root->right,v1);
}
TreeNode<int>*getBalancedBst(vector<int>&v1,int s, int e){
    if(s>e)return NULL;
    int mid=(s+e)/2;
    int element = v1[mid];
    TreeNode<int>*root=new TreeNode<int>(element);
    root->left=getBalancedBst(v1, s, mid-1);
    root->right=getBalancedBst(v1, mid+1, e);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int>v1;
    inOrder(root, v1);
    int n=v1.size();
    return getBalancedBst(v1, 0, n-1);
    
}
