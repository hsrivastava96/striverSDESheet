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
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        int flag = 0;
        while(slow && fast && fast->next && flag == 0)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                flag = 1;
        }
        if(flag == 1)
            return true;
        return false;
    }
};