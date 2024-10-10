#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
int ways(int stair, vector<int>& v1) {
  if (stair == 0) return 1;
  if(stair<0)return 0;
  if(v1[stair]!=-1)return v1[stair];
  return v1[stair]=(ways(stair-1,v1)+ways(stair-2,v1))%MOD;
}
int countDistinctWays(int nStairs) {
    vector<int>v1(nStairs+1,-1);
    return ways(nStairs,v1);

}