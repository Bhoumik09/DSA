//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    
  public:
    Node* findRoot(Node*root,unordered_map<Node*,Node*>&m1,int target ){
        queue<Node*>q;
        q.push(root);
        Node* ans;
        m1[root]=NULL;
        while(q.size()){
            Node*temp=q.front();
            q.pop();
            if(temp->data==target){
                ans=temp;
            }
            if(temp->left!=NULL){
                m1[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                m1[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return ans;
    }
    int getTime(Node*root,unordered_map<Node*,Node*>&m1){
        queue<Node*>q;
        q.push(root);
        int ans=0;
        //make a visited map
        unordered_map<Node*,bool>visited;
        visited[root]=true;
        while(q.size()){
            Node*temp=q.front();
            bool change=false;
            q.pop();
            // cout<<temp->data<<endl;
            if(temp->left!=NULL && !visited[temp->left]){
                visited[temp->left]=1;
                q.push(temp->left);
                change=1;
            }
            if(temp->right!=NULL && !visited[temp->right]){
                visited[temp->right]=1;
                q.push(temp->right);
                change=1;
            }
            if(m1[temp]!=NULL && !visited[m1[temp]]){
                visited[m1[temp]]=1;
                q.push(m1[temp]);
                change=1;
            }
            if(change)ans++;
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>m1;
        // first we need to get the taregt node from the tree 
        
        Node*newRoot=findRoot(root,m1,target);
        cout<<"The ans is"<<newRoot->data<<endl;
        return getTime(newRoot, m1);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
// Why Not Separate Checks?
// If you check and process each node separately (without the for loop), you'd end up incrementing the time for every node you process, regardless of whether it's at the same level or not. This would incorrectly count time units for each node instead of for each level, leading to an overestimation of the time required.