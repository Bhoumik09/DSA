#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
    map<char , int> m1;
	
	for(char i:s){
		m1[i]++;
	}
	int maxi =INT_MIN;
	char maxChar;
	for(auto i:m1){
		if(i.second>maxi){
			maxi=i.second;
			maxChar=i.first;
		}
	}
	int n=s.length();
	if((n%2==0 && maxi>n/2) ||(n%2 && maxi>n/2+1))return "";
	int pos=0;
	while(maxi--){
        s[pos]=maxChar;
        m1[maxChar]--;
        pos+=2;
    }
    for(auto i:m1){
        while(i.second!=0){
            if(pos>=n)pos=1;
            s[pos]=i.first;
            pos+=2;
            i.second--;
        }
    }
    return s;
        
    }
};