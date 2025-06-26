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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //Method1: Traverse the both list's , keep adding nodes to a vector container,
        //later sort() the container overall and then create new list based on that and return the head node.
        //TC: O(N1)+O(N2)+O(Nlog(N)) ; where N= N1+N2
        //SC: O(N1+N2)

        //Method2: Using concept of dummy node to avoid extra NULL checks
        //Using optimized inplace merge sorted linkedlist creation without adding new nodes, 
        //Via just using the exisiting nodes

        struct ListNode* dummy = new ListNode(-1);
        struct ListNode* temp = dummy;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1) temp->next = list1;
        else temp->next = list2;

        return dummy->next;
        
    }
};