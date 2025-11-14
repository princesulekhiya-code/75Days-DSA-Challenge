class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (auto node : lists) {
            if (node) pq.push({node->val, node});
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            tail->next = p.second;
            tail = tail->next;
            if (p.second->next) pq.push({p.second->next->val, p.second->next});
        }
        return dummy->next;
    }
};
