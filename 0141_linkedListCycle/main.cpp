
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode *fastPtr = head;
        struct ListNode *slowPtr = head;
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(fastPtr == slowPtr)
                return true;
        }
        return false;

    }
};
