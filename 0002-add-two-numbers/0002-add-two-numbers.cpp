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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1)return l2;
        else if(!l2)return l1;
        
        //make temp pointers
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* l3 = nullptr;
        ListNode* temp3 = l3;
        struct ListNode* temp = nullptr;
        int sum = 0;
        int carry = 0;
        int val1 = 0;
        int val2 = 0;

        while(temp1 || temp2 || carry)
        {
            val1 = temp1 ? temp1->val : 0;
            val2 = temp2 ? temp2->val : 0;

            sum = val1 + val2 + carry;
            printf("Sum is [%d]\n",sum);
            carry = sum / 10;
            sum = sum % 10;

            temp = new ListNode (sum);
            if(!temp3)
            {
                l3 = temp;
                temp3 = l3;
            }
            else
            {
                temp3->next = temp;
                temp3 = temp;
            }  

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        return l3;
    }
};