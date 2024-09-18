
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int>m1;
    //  insertion
    // 1)
    pair<string,int> p=make_pair("babbar",3);
    m1.insert(p);
    // 2(
    pair<string, int>q("love",2);
    m1.insert(q);
    //3()
    m1["mera"]=1;

    // /searching
    cout<<m1["mera"];
    // 2
    cout<<m1.at("babbar");
    // error 
    cout<<m1.at("mera");
    //out of range error, abort , 
    cout<<m1["mera"];
    // yaha 0 aayega agar key exist nahi karti, but at use karenge toh error aayega;
    m1["unknownkey"];
    // yeh ek entry create kar degfa with default value 
    // to check that there is a entry for function or not 
    cout<<m1.count("love");
    // absent-> 0 present->gives 1

    m1.erase("c");
    // it erase the key
    
    unordered_map <string, int> ::iterator it=m1.begin();
    while(it!=m1.end()){
        cout<<it->first<<" "<<it->second;
    } 
}