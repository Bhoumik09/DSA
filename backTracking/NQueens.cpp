#include <bits/stdc++.h>
using namespace std;
void add(vector<vector<int>> &board, vector<vector<int>> &ans) {
// convert 2d vector into 1 d vector 
  vector<int> temp;
  for (vector<int> i : board) {
    for (int j : i) {
      temp.push_back(j);
    }
  }
  ans.push_back(temp);
}
void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int r, int n,unordered_map<int,bool>&col,unordered_map<int,bool>&lud,unordered_map<int,bool>&rud) {
  if (r == n) {
    add(board, ans);
    return;
  }
  for(int c=0;c<n;c++){
    if (!col[c] && !lud[r-c] && !rud[r+c]) {
		board[r][c]=1;
		col[c]=lud[r-c]=rud[r+c]=true;
		solve(board,ans, r+1,n,col,lud,rud);
		col[c]=lud[r-c]=rud[r+c]=false;
		board[r][c]=0;
    }
  }
}
vector<vector<int>> nQueens(int n) {
  vector<vector<int>> ans;
  vector<vector<int>> board(n, vector<int>(n, 0));
  unordered_map<int,bool>col;
  unordered_map<int,bool>lud;
  unordered_map<int,bool>rud;
  solve(board, ans, 0, n,col,lud,rud);
  return ans;
}