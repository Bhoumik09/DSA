#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int checkValid(string s){
        stack<char>s1;
        for(char i :s){
            if(s1.size() && s1.top()=='('){
                if(i==')'){
                    s1.pop();
                    continue;
                }
            }
            if(i=='(' || i==')')s1.push(i);
        }
        return s1.size();

    }
    void solve(string s , set<string>&ans , int minR, unordered_map<string,bool>&m1){
        if(minR<0){
            return;
        }
        if(m1[s])return;
        m1[s]=true;
        if(minR==0){
            if(!checkValid(s)){
                
                ans.insert(s);
            }
            return;
        }
        for(int i=0;i<s.length();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,ans,minR-1,m1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string>ans;
        unordered_map<string,bool>m1;
        solve(s, ans, checkValid(s),m1);
        
        vector<string>ans2;
        for(string i:ans){
            ans2.push_back(i);
        }
        return ans2;
    }
};