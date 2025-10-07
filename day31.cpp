#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* -------------------------------
   Problem 1: Reverse Linked List (LeetCode 206)
--------------------------------- */
class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};

/* -------------------------------
   Problem 2: Swap Nodes in Pairs (LeetCode 24)
--------------------------------- */
class SwapPairs {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

/* -------------------------------
   Problem 3: Rotate List (LeetCode 61)
--------------------------------- */
class RotateList {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        temp->next = head;  // Make it circular
        k = k % len;
        int stepsToNewHead = len - k;
        while (stepsToNewHead--) temp = temp->next;

        ListNode* newHead = temp->next;
        temp->next = nullptr;  // Break the circle
        return newHead;
    }
};

/* -------------------------------
   Optional: Utility functions
--------------------------------- */
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
