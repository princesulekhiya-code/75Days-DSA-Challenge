// 🚀 75 Days DSA Challenge – Day 34
// 👨‍💻 Topic: Stack & Queue (Design & Implementation)
// 📚 Problems: 355. Design Twitter | 496. Next Greater Element I | 622. Design Circular Queue
// 💻 Language: C++

#include <bits/stdc++.h>
using namespace std;

// ===========================================================
// 🔹 355. Design Twitter
// ===========================================================
class Twitter {
    unordered_map<int, unordered_set<int>> followers;
    vector<pair<int, int>> tweets;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for (int i = tweets.size() - 1; i >= 0 && feed.size() < 10; i--) {
            int uid = tweets[i].first, tid = tweets[i].second;
            if (uid == userId || followers[userId].count(uid))
                feed.push_back(tid);
        }
        return feed;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

// ===========================================================
// 🔹 496. Next Greater Element I
// ===========================================================
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int x : nums1) ans.push_back(mp[x]);
        return ans;
    }
};

// ===========================================================
// 🔹 622. Design Circular Queue
// ===========================================================
class MyCircularQueue {
    vector<int> q;
    int front, rear, size, count;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        front = 0;
        rear = -1;
        size = k;
        count = 0;
    }
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % size;
        count--;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == size;
    }
};

// ===========================================================
// ✅ End of Day 34 – Stack & Queue (Design Problems)
// ===========================================================

int main() {
    cout << "🚀 Day 34 DSA Challenge – Solutions Compiled Successfully!\n";
    return 0;
}
dat34.cpp
