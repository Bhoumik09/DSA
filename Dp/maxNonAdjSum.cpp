#include <bits/stdc++.h>
using namespace std;
int maxSum(vector<int> &dp, vector<int> &v1, int index) {
    //memoiztion is used here 
    if(index>=v1.size())return 0;
    if(dp[index]!=-1)return dp[index];
    dp[index]= max(maxSum(dp, v1 , index+1) , maxSum(dp, v1, index+2)+v1[index]);
    return dp[index];
}
int maxSumTabu(vector<int> &v1) {
    vector<int>dp(v1.size()+1, -1);
    dp[v1.size()]=0;
    dp[v1.size()-1]=v1[v1.size()-1];
    for (int i = v1.size()-2; i >= 0; i--) {
        dp[i]=max(dp[i+1],dp[i+2]+v1[i]);
    }
    return max(dp[0], dp[1]);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int>dp(nums.size()+1, -1);
    return maxSumTabu(nums);
}