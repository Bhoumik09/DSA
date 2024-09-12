#include<bits/stdc++.h>
using namespace  std;

    
 // namespace  std;

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

class Info{
    public:
    int size;
    bool isBst;
    int mini;
    int maxi;
    Info() {}
    Info(int s, bool b, int mn, int mx) : size(s), isBst(b), mini(mn), maxi(mx) {}
};
Info solve(TreeNode*root, int&ans){
    if(root==nullptr)return Info(0, true, INT_MAX, INT_MIN);
    Info left=solve(root->left, ans);
    Info right=solve(root->right, ans);
    Info currNode;
    currNode.size=left.size+right.size+1;
    
    currNode.mini=min(root->data,left.mini);
    currNode.maxi=max(root->data,right.maxi);
    if(left.isBst && right.isBst &&(root->data>left.maxi && root->data<right.mini)){
        currNode.isBst=true;
    }else{
        currNode.isBst=false;
    }
    if(currNode.isBst){
        ans=max(ans,currNode.size);
    }
    return currNode;


    
}
int largestBST(TreeNode * root){
    int maxSum=0;
    Info temp=solve(root, maxSum);
    return maxSum;
}