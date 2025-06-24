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
    ListNode* deleteMiddle(ListNode* head) {

        //Brute Force via 2 traversal method 
        //Optimized via slow & fast pointer method's

        //Edge-Case
        if(head->next == nullptr)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast && fast->next)
        {
            temp = slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next = slow->next;
        delete slow;

        return head;
 
    }
};