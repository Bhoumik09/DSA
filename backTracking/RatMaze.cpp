#include <bits/stdc++.h>
using namespace std;
void ratMaze(vector<vector<int>> &arr, vector<string> &ans,vector<vector<bool>> &visited, int n , int m, string temp, int N) {
  if (n == N - 1 && m == N - 1) {
      ans.push_back(temp);
      return;
  }
  if (n + 1 < N && !visited[n + 1][m] && arr[n + 1][m]) {//case for D
        visited[n+1][m]=true;
        temp+='D';
        ratMaze(arr,ans,visited,n+1,m,temp,N);
        temp.pop_back();
        visited[n+1][m]=false;
  }
  if (m-1 >=0 && !visited[n][m-1] && arr[n][m-1]) {//case for L
        visited[n][m-1]=true;
        temp+='L';
        ratMaze(arr,ans,visited,n,m-1,temp,N);
        temp.pop_back();
        visited[n][m-1]=false;
  }
  if (m + 1 < N && !visited[n][m+1] && arr[n][m+1]) {//case for R
        visited[n][m+1]=true;
        temp+='R';
        ratMaze(arr,ans,visited,n,m+1,temp,N);
        temp.pop_back();
        visited[n][m+1]=false;
  }
  if (n - 1 >=0 && !visited[n - 1][m] && arr[n - 1][m]) {//case for U
        visited[n-1][m]=true;
        temp+='U';
        ratMaze(arr,ans,visited,n-1,m,temp,N);
        temp.pop_back();
        visited[n-1][m]=false;
  }
  
  
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    if (arr[0][0] == 0 || arr[n-1][n-1] == 0) // If start or end is blocked
        return ans;
    visited[0][0]=true;
    ratMaze(arr,ans,visited,0,0,"",n);
    return ans;
}