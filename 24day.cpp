# 🚀 Day 24 of 75 Days DSA Challenge  

Today I solved **3 Linked List problems** from LeetCode in C++:  

---

## 🔹 876. Middle of the Linked List  
**Problem:** Return the middle node of a singly linked list. If two middle nodes exist, return the second one.  
**Approach:** Used **fast & slow pointer** technique.  
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
