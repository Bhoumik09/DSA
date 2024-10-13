
#include <bits/stdc++.h>
using namespace std;
int segPossible(int n , int x, int y, int z, vector<int>v1) {
	if(n<0)return -1;
	if(n==0)return 0;
	if(v1[n]!=-1)return v1[n];
	int op1=segPossible(n-x,x,y,z,v1);
	int op2=segPossible(n-y,x,y,z,v1);
	int op3=segPossible(n-z,x,y,z,v1);
	int maxOp= max({op1, op2, op3});
	return v1[n]= maxOp==-1?-1:maxOp+1;

}
int segTabu(int n, int x, int y, int z) {
	vector<int>dp(n+1, -1);
	dp[0]=0;
	int index=1;
    for(int i=1;i<=n;i++){
		if(i-x>=0 && dp[i-x]!=-1){
			dp[i]=max(dp[i], dp[i-x]+1);
		}
		if(i-y>=0 && dp[i-y]!=-1){
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0 && dp[i-z]!=-1){
			dp[i]=max(dp[i],dp[i-z]+1);
		}
	}
	return dp[n]==-1?0 :dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	vector<int>v1(n+1, -1);
	int ans=segTabu(n,x,y,z);
	return ans;

}