class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto& p : freq) pq.push({p.second, p.first});
        string res;
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            res.append(count, ch);
        }
        return res;
    }
};
