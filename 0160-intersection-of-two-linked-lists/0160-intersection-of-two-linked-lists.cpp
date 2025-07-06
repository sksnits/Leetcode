/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //Method: 2 pointer method
        struct ListNode* tempA = headA;
        struct ListNode* tempB = headB;

        while(tempA != tempB)
        {
            if(tempA == nullptr)
            {
                tempA = headB;
            }
            else
            {
                tempA = tempA->next;
            }

            if(tempB == nullptr)
            {
                tempB = headA;
            }
            else
            {
                tempB = tempB->next;
            }


            if(tempA == tempB)
            {
                return tempA;
            }
        }

        return tempA;
        
    }
};

/*
Brute Force: Two loop without space O(m*n), o(1) Space
Brute Force: Hasmap Based, o(m+n) time and space

Optimized: Length difference approach
Optimized: Two pointer based approach

Both optimization takes O(m+n) TC and O(1) solution 

*/