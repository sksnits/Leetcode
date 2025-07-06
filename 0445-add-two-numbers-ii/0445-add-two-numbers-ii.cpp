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
        stack<int>s1,s2,s3;
        ListNode* temp = l1;
        ListNode* dummyNode = nullptr;

        while(temp != nullptr)
        {
            s1.push(temp->val);
            temp = temp->next;
        }

        temp = l2;
        
        while(temp != nullptr)
        {
            s2.push(temp->val);
            temp = temp->next;
        }

        //Now logical Part

        dummyNode = new ListNode(-1);
        temp = dummyNode;
        int sum = 0;
        int carry = 0;

        while(!s1.empty() || !s2.empty() || carry != 0)
        {
            if(!s1.empty())sum+=s1.top(),s1.pop();
            if(!s2.empty())sum+=s2.top(),s2.pop();

            sum+=carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            s3.push(sum);
            sum = 0;

        }


        while(!s3.empty())
        { 
            temp->next = new ListNode(s3.top());
            s3.pop();
            temp = temp->next;
        }
        return dummyNode->next;


    }
};