//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    // Function to return a tree created from postorder and inoreder traversals.
    Node* build(int in[], int post[], int &index, int start, int end,unordered_map <int,int>&m1){
        if(index<0 ||start>end)return NULL;
        int element = post[index--];
        int position = m1[element];
        Node* root=new Node(element);
        root->right=build(in,post,index,position+1,end,m1);
        root->left=build(in,post,index,start,position-1,m1);
        return root;
    }
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderIndex=n-1;
        unordered_map<int,int>m1;
        for(int i=0;i<n;i++){
            m1[in[i]]=i;
        }
        return build(in,post,postOrderIndex, 0 ,n-1,m1);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends