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
    ListNode* rotateRight(ListNode* head, int k) {
        //Brute force with stack space

        if(head == nullptr)return nullptr;

        stack<ListNode*>s1,s2,s3;
        int len = 0;
        ListNode* temp = head;

        while(temp)
        {
            s1.push(temp);
            temp = temp -> next;
            len++;
        }

        printf("len is [%d]\n",len);

        k = k % len;  //Effective rotation numberr
        int rot = k;
        
        printf("k is [%d]\n",k);
        

        //creating a new answer list now
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp1 = dummyNode;

        while(rot--)
        {
            s2.push(s1.top());
            s1.pop();
        }

        rot = k;
        while(rot--)
        {
            temp1->next = new ListNode(s2.top()->val);
            temp1 = temp1->next;
            s2.pop();
        }

        //Now remaining item of s1 , push into s2
        while(!s1.empty())
        {
            s3.push(s1.top());
            s1.pop();
        }

        //now add the remaining elements to created answer list

        while(!s3.empty())
        {
            temp1->next = new ListNode(s3.top()->val);
            temp1 = temp1->next;
            s3.pop();
        }

        return dummyNode->next;

    }
};