#include <bits/stdc++.h>
using namespace std; 
// Following is the Binary Tree node structure
template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inOrder(BinaryTreeNode<int> *root,vector<int>&v1) {
    if(root==NULL)return;
    inOrder(root->left,v1);
    v1.push_back(root->data);
    inOrder(root->right,v1);

}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int>v1;
    inOrder(root, v1);
    int i=0,j=v1.size()-1;
    while(i<j){
        if(v1[i]+v1[j]==target)return true;
        else if(v1[i]+v1[j]>target)j--;
        else i++;
    }
    return false;

}