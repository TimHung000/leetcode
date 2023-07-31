#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int res = 0;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *tmp;
        ListNode *prev = nullptr;
        while(slow) {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        ListNode *first = head;
        ListNode *second = prev;
        while(second) {
            res = std::max(res, first->val + second->val);
            first = first->next;
            second = second->next; 
        }
        return res;
    }
};