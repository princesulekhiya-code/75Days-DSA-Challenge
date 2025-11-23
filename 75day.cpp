class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> freq;
        for(int x : barcodes) freq[x]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto &p : freq) pq.push({p.second, p.first});
        
        vector<int> res;
        pair<int,int> prev = {0,0};
        
        while(!pq.empty()) {
            auto curr = pq.top(); 
            pq.pop();
            
            res.push_back(curr.second);
            curr.first--;
            
            if(prev.first > 0) pq.push(prev);
            prev = curr;
        }
        
        return res;
    }
};
