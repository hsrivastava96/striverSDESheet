/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        vector<ListNode *> address;
        ListNode *temp1, *temp2;
        temp1 = headA;
        temp2 = headB;
        
        while(temp1)
        {
            address.push_back(temp1);
            temp1 = temp1->next;
        }
        
        while(temp2)
        {
            for(auto it:address)
            {
                if(it == temp2)
                    return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};