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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *nNode, *nPrevNode, *temp, *nDel;
        int seq = 1;
        temp = head;
        nNode = head;
        nPrevNode = head;
        
        if(head->next == NULL)
            return NULL;
        
        while(temp->next != NULL)
        {  
            if(seq >= n)
            {
               nPrevNode = nNode;
               nNode = nNode->next;
            }
            temp = temp->next;
            seq++;            
        }
        nDel = nNode;
        if(nNode == head)
            head = nNode->next;
        else
            nPrevNode->next = nNode->next;
        delete nDel;
        return head;
    }
};