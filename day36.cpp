#include <bits/stdc++.h>
using namespace std;

// Problem 316: Remove Duplicate Letters
class Solution316 {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);
        vector<bool> seen(26,false);
        for(int i=0;i<s.size();i++) lastIndex[s[i]-'a']=i;
        string res="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(seen[c-'a']) continue;
            while(!res.empty() && c<res.back() && i<lastIndex[res.back()-'a']){
                seen[res.back()-'a']=false;
                res.pop_back();
            }
            res+=c;
            seen[c-'a']=true;
        }
        return res;
    }
};

// Problem 227: Basic Calculator II
class Solution227 {
public:
    int calculate(string s) {
        int n=s.size(), num=0;
        char op='+';
        stack<int> st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            if((!isdigit(s[i]) && s[i]!=' ') || i==n-1){
                if(op=='+') st.push(num);
                else if(op=='-') st.push(-num);
                else if(op=='*'){ int t=st.top(); st.pop(); st.push(t*num);}
                else if(op=='/'){ int t=st.top(); st.pop(); st.push(t/num);}
                op=s[i];
                num=0;
            }
        }
        int ans=0;
        while(!st.empty()){ ans+=st.top(); st.pop();}
        return ans;
    }
};

// Problem 399: Evaluate Division
class Solution399 {
    unordered_map<string,string> parent;
    unordered_map<string,double> ratio;
public:
    string find(string x){
        if(parent[x]!=x){
            string p=find(parent[x]);
            ratio[x]*=ratio[parent[x]];
            parent[x]=p;
        }
        return parent[x];
    }
    
    double divide(string a,string b){
        if(parent.find(a)==parent.end() || parent.find(b)==parent.end()) return -1.0;
        string pa=find(a), pb=find(b);
        if(pa!=pb) return -1.0;
        return ratio[a]/ratio[b];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        for(int i=0;i<equations.size();i++){
            string x=equations[i][0], y=equations[i][1];
            if(parent.find(x)==parent.end()){ parent[x]=x; ratio[x]=1.0;}
            if(parent.find(y)==parent.end()){ parent[y]=y; ratio[y]=1.0;}
            string px=find(x), py=find(y);
            if(px!=py){
                parent[px]=py;
                ratio[px]=values[i]*ratio[y]/ratio[x];
            }
        }
        vector<double> res;
        for(auto &q: queries){
            res.push_back(divide(q[0],q[1]));
        }
        return res;
    }
};

int main(){
    // You can add test cases here if needed
    return 0;
}
