// 🚀 75 Days DSA Challenge – Day 40
// 📚 Advanced Data Structures & Simulation Series
// Problems Solved: 
// 1️⃣ 355. Design Twitter
// 2️⃣ 682. Baseball Game
// 3️⃣ 1472. Design Browser History
// Author: Prince Sulekhiya

#include <bits/stdc++.h>
using namespace std;

// ------------------ 355. Design Twitter ------------------
class Twitter {
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets; // userId -> vector of {time, tweetId}
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for (auto f: followers[userId]) {
            for (auto t: tweets[f]) pq.push(t);
        }
        for (auto t: tweets[userId]) pq.push(t);
        
        int count = 0;
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

// ------------------ 682. Baseball Game ------------------
class SolutionBaseball {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto &op: ops){
            if(op == "+"){
                int a = st.top(); st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(op == "D"){
                st.push(2*st.top());
            }
            else if(op == "C"){
                st.pop();
            }
            else{
                st.push(stoi(op));
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

// ------------------ 1472. Design Browser History ------------------
class BrowserHistory {
    vector<string> history;
    int current;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) {
        history.resize(current+1);
        history.push_back(url);
        current++;
    }
    
    string back(int steps) {
        current = max(0, current-steps);
        return history[current];
    }
    
    string forward(int steps) {
        current = min((int)history.size()-1, current+steps);
        return history[current];
    }
};
