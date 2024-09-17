//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class node{
    public:
    int r;
    int c;
    int data;
    node(int data, int r, int c){
        this->r=r;
        this->c=c;
        this->data=data;
    }
};

class compare{
    public:
    bool operator()(node a , node b){
        return a.data>b.data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        
        vector<int>ans;
        priority_queue<node, vector<node>, compare>pq;
        for(int i=0;i<k;i++){
            node element = node(arr[i][0],i,0);
            pq.push(element);
        }
        while(pq.size()){
            node tmp=pq.top();
            pq.pop();
            int i=tmp.r;
            int j=tmp.c;
            int data=tmp.data;
            ans.push_back(data);
            if(j+1<k){
                pq.push(node(arr[i][j+1],i,j+1));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends