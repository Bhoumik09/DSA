//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* build(int in[], int pre[], int &index,int n, int inOrderStart, int inOrderEnd, unordered_map<int,int>&m1 ){
        if(index>=n || inOrderStart>inOrderEnd)return NULL;
        int element=pre[index++];
        //select the element from the preordr array
        int position=m1[element];
        //find the position in the post order array
        Node* root=new Node(element);
        root->left=build(in,pre,index,n,inOrderStart,position-1,m1);
        //here we craete the left oparty of the tree
        root->right=build(in,pre,index,n,position+1,inOrderEnd,m1);
        //here we create the right part pf the tree    
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        unordered_map<int,int>m1;
        
        for(int i=0;i<n;i++){
            m1[in[i]]=i;
        }
        Node*root=build(in,pre,preOrderIndex,n,0,n-1,m1);
        return root;
        //logic
        // We have two array
        // inorder->{1,6,8,7}->L N R
        // preorder->{1,6,7,8}->N L R
        // the first element of the preorder array is the root node 
        // select the rode
        // 1 selected
        // now check the left part for left tree and right part for right tre
        // here right will be ->NULL
        // threfore root->left=NULL
        // and in right the whole array from position+1 to last is goiven
        // root->right={6,8,7}
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends