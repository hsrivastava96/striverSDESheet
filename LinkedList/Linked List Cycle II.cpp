/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Map method
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        map<ListNode *, int> ds;
        
        ListNode *slow, *fast;
        
        slow = head;
        fast = head;
        
        int flag = 0;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                fast = fast->next;
                while(fast != slow)
                {
                    ds.insert(pair<ListNode *, int>(fast, fast->val));
                    fast = fast->next;
                }
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            slow = head;
            while(true)
            {
                if(ds.find(slow) != ds.end())
                    return slow;
            }
        }
        return NULL;
    }
};


// Map method without using Floyd method of slow and fast pointers
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
    ListNode *detectCycle(ListNode *head) 
    {
        map<ListNode *, int> ds;
        ListNode *temp;
        
        temp = head;
        
        while(temp && temp->next)
        {
            if(ds.find(temp) != ds.end())
                return temp;
            ds.insert(pair<ListNode *, int>(temp, temp->val));
            temp = temp->next;
        }
        return NULL;
    }
};