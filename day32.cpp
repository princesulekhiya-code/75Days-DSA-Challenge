// 🚀 75 Days DSA Challenge – Day 32
// 🔗 Linked List Advanced Problems (LeetCode)
// Author: Prince Sulekhiya
// Language: C++
// Topics: Linked List | Two Pointer | Reverse | Split | Merge

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

///////////////////////////////////////////////////////////////////////////////
// 🧩 Problem 1: Reorder List (LeetCode #143)
///////////////////////////////////////////////////////////////////////////////

class Solution1 {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find middle of list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Merge both halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};

///////////////////////////////////////////////////////////////////////////////
// 🧩 Problem 2: Split Linked List in Parts (LeetCode #725)
///////////////////////////////////////////////////////////////////////////////

class Solution2 {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        int length = 0;
        ListNode* curr = head;

        // Step 1: Find total length
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Step 2: Determine base size and extra nodes
        int baseSize = length / k;
        int extra = length % k;

        curr = head;
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int partSize = baseSize + (i < extra ? 1 : 0);

            // Step 3: Traverse each part
            for (int j = 1; j < partSize; j++)
                if (curr) curr = curr->next;

            // Step 4: Disconnect part
            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }
        return result;
    }
};

///////////////////////////////////////////////////////////////////////////////
// 🧩 Problem 3: Reverse Nodes in k-Group (LeetCode #25)
///////////////////////////////////////////////////////////////////////////////

class Solution3 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: Count total nodes
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Step 2: Use dummy node for easy connection
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        curr = head;

        // Step 3: Reverse in groups of k
        while (length >= k) {
            ListNode* prev = nullptr;
            ListNode* tail = curr;
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            prevGroupEnd->next = prev;
            tail->next = curr;
            prevGroupEnd = tail;
            length -= k;
        }

        return dummy.next;
    }
};

///////////////////////////////////////////////////////////////////////////////
// 🔧 Helper Functions for Testing (Optional for GitHub Report)
///////////////////////////////////////////////////////////////////////////////

ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
// 🧪 Example Main Function (You can comment out on LeetCode)
///////////////////////////////////////////////////////////////////////////////

int main() {
    cout << "🚀 Day 32: Linked List Advanced Problems\n";

    // Problem 1 Test
    Solution1 s1;
    ListNode* head1 = createList({1,2,3,4,5});
    cout << "\nBefore Reorder: ";
    printList(head1);
    s1.reorderList(head1);
    cout << "After Reorder:  ";
    printList(head1);

    // Problem 2 Test
    Solution2 s2;
    ListNode* head2 = createList({1,2,3,4,5,6,7,8,9,10});
    vector<ListNode*> parts = s2.splitListToParts(head2, 3);
    cout << "\nSplit into 3 Parts:\n";
    for (int i = 0; i < parts.size(); i++) {
        cout << "Part " << i+1 << ": ";
        printList(parts[i]);
    }

    // Problem 3 Test
    Solution3 s3;
    ListNode* head3 = createList({1,2,3,4,5});
    cout << "\nBefore Reverse k=2: ";
    printList(head3);
    ListNode* newHead = s3.reverseKGroup(head3, 2);
    cout << "After Reverse:      ";
    printList(newHead);

    return 0;
}
