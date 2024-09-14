#include <bits/stdc++.h> 
using namespace std;
class node{
    public:
        int data;
        int row;
        int col;
        node(int data, int row, int col){
            this->data=data;
            this->row=row;
            this->col=col;
        }
};
class compare{
    public:
        bool operator()(node*a , node*b){
            return a->data>b->data;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare>minHeap;
    int n=kArrays.size();
    for (int i = 0; i < n; i++) {
        node* newNode=new node(kArrays[i][0],i,0);
        minHeap.push(newNode);
    }
    vector<int>ans;
    while(minHeap.size()>0){
        node*tmp=minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();
        int i=tmp->row;
        int j=tmp->col;
        if(j+1<kArrays[i].size()){
            node* newNode=new node(kArrays[i][j+1],i,j+1);
            minHeap.push(newNode);
        }
    
    }
    return ans;
}
