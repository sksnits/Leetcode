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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next)return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow ->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                break;
            }
        }

        if(!fast || !fast->next)
        {
            //no loop
            return nullptr;
        }

        //loop exist
        //Hint: Reset slow pointer now and move both pointers at same pace untill they meet
        slow = head;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
        
    }
};


/*
Intuition :
Use a Floyd's Cycle-Finding algorithm to detect a cycle in a linked list and find the node where the cycle starts.
What is Floyd's Cycle-Finding algorithm ?
It is also called Hare-Tortoise algorithm
The algorithm works by using two pointers, a slow pointer and a fast pointer.
Initially, both pointers are set to the head of the linked list.
The fast pointer moves twice as fast as the slow pointer.
If there is a cycle in the linked list, eventually, the fast pointer will catch up with the slow pointer.
If there is no cycle, the fast pointer will reach the end of the linked list.
Approach :
When the two pointers meet, we know that there is a cycle in the linked list.
We then reset the slow pointer to the head of the linked list and move both pointers at the same pace, one step at a time, until they meet again.
The node where they meet is the starting point of the cycle.
If there is no cycle in the linked list, the algorithm will return null.
Let's understand this with an Example :
Let's say we have a linked list with a cycle, like the one below:
1 -> 2 -> 3 -> 4 -> 5 -> 2
To detect the cycle and find the starting point, we use two pointers, a slow pointer and a fast pointer, initially set to the head of the linked list.
slow = 1
fast = 1
Then we move the pointers through the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
slow = 2
fast = 3

slow = 3
fast = 5

slow = 4
fast = 2
Eventually, the fast pointer will catch up with the slow pointer, which means that there is a cycle in the linked list.
slow = 5
fast = 4
At this point, we reset the slow pointer to the head of the linked list, and move both pointers one step at a time until they meet again.
slow = 1
fast = 4

slow = 2
fast = 5

slow = 3
fast = 2
The node where they meet is the starting point of the cycle, which in this case is node 2.
So, the algorithm returns node 2 as the starting point of the cycle.
I hope this visual explanation helps you understand the Floyd's Cycle-Finding algorithm better.
Complexity :
Time complexity : O(n)
Space complexity : O(1)
*/