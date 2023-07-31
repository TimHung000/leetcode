#include <algorithm>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur = head;
        ListNode *n1;
        ListNode *n2;
        for(int i = 0; i < k-1; ++i)
            cur = cur->next;
        
        n1 = cur;
        n2 = head;
        while(cur->next != nullptr) {
            cur = cur->next;
            n2 = n2->next;
        }
        std::swap(n1->val, n2->val);
        return head;        
    }
};