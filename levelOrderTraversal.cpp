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
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    q.push(NULL);
    while (!q.empty())
    {

        Node *front = q.front();
        // cout<<front->data;
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                // we still have things in queue, therefore we actually need a new level here, tehrefore adding null
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }
    }
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
int main()
{
    Node *root = NULL;
    takeInput(root);
    
    levelOrderTraversal(root);
}