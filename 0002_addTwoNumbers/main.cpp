struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;

        int carry = 0;
        ListNode **cur = &result;
        while(l1 || l2 || carry) {
            if(l1) {
                carry = carry + l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry = carry + l2->val;
                l2 = l2->next;
            }
            *cur = new ListNode(carry % 10);
            carry = carry / 10;
            cur = &((*cur) -> next);
        }

        return result;
    }
};
