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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //Method1
        int len = 0; //length of singly linked-list
        struct ListNode* temp = head;

        while(temp)
        {
            temp = temp->next;
            len++;
        }

        printf("len is as [%d]\n",len);

        int delPosition = len-n-1;
        struct ListNode* temp1 = head;

        //EdgeCase: As per constraints
        if(len == 1)
        {
           return head = nullptr;
        }
        else if(len == n)
        {
            //apply node delete logic
            temp1 = temp1->next;
            return head = temp1;
        }

        while(delPosition--)
        {
            printf("hello\n");
            temp1 = temp1->next;
        }

        //apply node delete logic
        temp1->next = temp1->next->next;

        return head;
        
    }
};