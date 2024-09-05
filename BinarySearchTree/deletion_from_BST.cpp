#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int element)
    {
        this->data = element;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node()
    {
        this->data = -1;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// insertion into the bst
Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
// taking the input
int minVal(Node*root){
    if(root->left==NULL){
        return root->data;
    }
    return minVal(root->left);
}
Node* deleteBST(Node*root, int val){
    if(root==NULL){return nullptr;}
    if(root->data<val){
        root->right=deleteBST(root->right,val);
    }
    else if(root->data>val){
        root->left=deleteBST(root->left,val);

    }
    else{
        //if both child are null
        if(!root->right && !root->left){
            delete root;
            return NULL;
        }
        if(root->right && !root->left){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left && !root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left && root->right){
            int mini=minVal(root->right);
            root->data=mini;
            root->right=deleteBST(root->right,mini);
            return root;
        }
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}
bool validateBST(Node*root) {
  if(!root->right && !root->left)return true;
  cout<<root->data;
  bool op1,op2;
  if (root->left) {
      op1=root->left->data<=root->data && validateBST(root->left);
  }
  if(root->right){
      op2=root->right->data>=root->data && validateBST(root->right);
  }
  return op1&&op2;
}
int main()
{
    Node *root = NULL;
    takeInput(root);
    cout<<validateBST(root);

    
    
}