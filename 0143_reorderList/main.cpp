#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode *ptr = head;
        while(ptr)
        {
            list.push_back(ptr);
            ptr = ptr->next;
        }
        ListNode **indirectPtr = &head;
        
        for(int i = 0; i < list.size(); i++)
        {
            if(i % 2 == 0)
                *indirectPtr = list[i/2];
            else
                *indirectPtr = list[list.size() - i/2 - 1];
            
            indirectPtr = &(*indirectPtr)->next;
        }
        *indirectPtr = nullptr;
    }
};

int main()
{
    const int N = 5;
    ListNode *head = nullptr;
    ListNode **indirect = &head;
    for(int i = 0; i < N; ++i)
    {
        *indirect = new ListNode(i);
        indirect = &(*indirect)->next;
    }
    Solution sol;
    sol.reorderList(head);
}