#include <bits/stdc++.h>
using namespace std;
template<typename T>
    class BinaryTreeNode 
    {
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



int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    while(root){
        if(!root->left){
            i++;
            if(i==k)return root->data;
            root=root->right;
        }else{
            BinaryTreeNode<int>* temp=root->left;
            while(temp->right && temp->right!=root)temp=temp->right;
            if(temp->right==root){
                i++;
                if(i==k)return root->data;
                temp->right=NULL;
                root=root->right;

            }
            else{
                temp->right=root;
                root=root->left;
                
            }
        }
    }
    return -1;
}