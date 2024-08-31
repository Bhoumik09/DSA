//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
bool KAns(Node*root,int&k, int node,int&ans){
    if(root==NULL)return false;
    //to return as root is null
    int op1=KAns(root->left,k,node,ans);
    int op2=KAns(root->right,k,node,ans);
    if(k==0)return false;
    // if k==0, means we have found  the ans, so we will retur false as no furthur things need to be done
    
    if(root->data==node)return true;
    // if the present data==node, it means we have found the node whose ancestor needs to be found
    if(op1 || op2){
        //if any one node is true, it means ki jitna upar jayenga , utna kth node ka paas ayenga, so kpp
        
        k--;
        if(k==0){
            // agar abhi k==0 aa gaya, we found the ans or bas retuurn kardo
            ans=root->data;
            return false;
        }
        // abhi k th ancestor tak nahi pahuncha, but usi path pai milega, threfore returning true 
        return true;
        
    }
    // agar kuch bhi true nahi hai toh bas false dedo nah 
    return false;
    
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    KAns(root,k,node,ans);
    return ans;
}
