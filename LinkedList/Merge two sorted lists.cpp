


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *head, *temp, *temp1, *temp2;
        head = NULL;
        temp = NULL;
        temp1 = list1;
        temp2 = list2;

        if(temp1 == NULL)
            return list2;
        else if(temp2 == NULL)
            return list1;

        while(temp1 && temp2)
        {
            ListNode *newNode;
            newNode = new ListNode;
            newNode->next = NULL;

            if(temp1->val < temp2->val)
            {
                newNode->val = temp1->val;
                if(temp == NULL)
                    head = newNode;
                else
                    temp->next = newNode;
                temp = newNode;
                temp1 = temp1->next;
            }
            else if(temp1->val == temp2->val)
            {
                newNode->val = temp1->val;

                ListNode *newNode2;
                newNode2 = new ListNode;
                newNode2->val = temp1->val;
                newNode2->next = NULL;
                newNode->next = newNode2;

                if(temp == NULL)
                    head = newNode;
                else
                    temp->next = newNode;
                temp = newNode2;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                newNode->val = temp2->val;
                if(temp == NULL)
                    head = newNode;
                else
                    temp->next = newNode;
                temp = newNode;
                temp2 = temp2->next;
            }
        }       
        // cout<<temp->val<<" "<<temp->next<<endl;
        temp->next = NULL;
        while(temp1)
        {
            ListNode *newNode;
            newNode = new ListNode;
            newNode->val = temp1->val;
            newNode->next = NULL;
            temp->next = newNode;
            temp1 = temp1->next;
            temp = newNode;
        }
        while(temp2)
        {
            // cout<<temp2->val<<endl;
            ListNode *newNode;
            newNode = new ListNode;
            newNode->val = temp2->val;
            newNode->next = NULL;
            temp->next = newNode;
            temp2 = temp2->next;            
            temp = newNode;
        }
        return head; 
    }
};}