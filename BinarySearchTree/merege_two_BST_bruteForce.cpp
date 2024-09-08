
#include<bits/stdc++.h>
using namespace std;

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


void inOrder(TreeNode*root,vector<int>&v1){
    if(root==nullptr)return;
    inOrder(root->left,v1);
    v1.push_back(root->data);
    inOrder(root->right,v1);
}
vector<int> mergeTwoVectors(vector<int>v1,vector<int>v2){
    vector<int>v3;
    int i=0;
    int j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]>v2[j]){
            v3.push_back(v2[j++]);
        }else{
            v3.push_back(v1[i++]);
        }
    }
    while(i<v1.size()){
        v3.push_back(v1[i++]);
    }
    while(j<v2.size()){
        v3.push_back(v2[j++]);
    }
    return v3;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int>v1;
    vector<int>v2;
    
    inOrder(root1, v1);
    inOrder(root2, v2);
    return mergeTwoVectors(v1,v2);


}