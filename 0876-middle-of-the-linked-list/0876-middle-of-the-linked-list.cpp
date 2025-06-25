/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //M1:Brute Force via 2 traversal method , WIll work here as Node's count is less than 100
        //M2:Optimized via slow & fast pointer method's

        //Edge-Case
        if(head->next == nullptr)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
        
    }
};