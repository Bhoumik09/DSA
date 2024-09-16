//  https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d, int r, int c){
        data=d;
        col=c;
        row=r;
    }
};
class compare{
    public:
    bool operator()(node a , node b){
        return a.data>b.data;
    }
};
int kSorted(vector<vector<int>> &arr, int k, int n) {
    int mini=INT_MAX,maxi=INT_MIN;
    priority_queue<node,vector<node>, compare>pq;
    for(int i=0;i<k;i++){
        int element = arr[i][0];
        maxi=max(maxi,element);
        pq.push(node(element,i,0));
    }
    int s=pq.top().data,e=maxi;
    while(pq.size()){
        node temp=pq.top();
        pq.pop();
        mini=temp.data;
        if(maxi-mini<e-s){
            s=mini;
            e=maxi;
        }
        int i=temp.row;
        int j=temp.col;
        if(j+1<n){
            maxi=max(maxi,arr[i][j+1]);
            pq.push(node(arr[i][j+1],i,j+1));
        }else break;
    }
    return e-s+1;
}