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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *temp, *currNode, *prevNode, *tempHead, *tempNode, *tempPrevNodeEnd;
        tempHead = NULL;
        tempPrevNodeEnd = NULL;
        stack<ListNode *> ds;

        temp = head;
        int flag = -1;
        while(temp != NULL)
        {
            currNode = temp;
            // ds.push(currNode);
            if(ds.size() == k)
            {
                while(!ds.empty())
                {
                    if(tempHead == NULL)
                        tempHead = ds.top();
                    else
                        tempNode->next = ds.top();
                    tempNode = ds.top();
                    // tempPrevNode = ds.top();
                    ds.pop();
                }
                if(flag == -1)
                {
                    head = tempHead;
                    flag = 1;
                }
                tempNode->next = currNode;
                if(tempPrevNodeEnd == NULL)
                    tempPrevNodeEnd = tempNode;
                else
                {
                    tempPrevNodeEnd->next = tempHead;
                    tempPrevNodeEnd = tempNode;
                }
                tempHead =  NULL;
                ds.push(currNode);
            }
            else
                ds.push(currNode);
            prevNode = currNode;
            temp = temp->next;
        }
        cout<<ds.size()<<endl;
//         Check if ds.size() == k, here again vacate ds and modify linkedlist
        if(ds.size() == k && k != 1)
        {
            while(!ds.empty())
            {
                if(tempHead == NULL)
                    tempHead = ds.top();
                else
                    tempNode->next = ds.top();
                tempNode = ds.top();
                // tempPrevNode = ds.top();
                ds.pop();
            }
            if(flag == -1)
            {
                head = tempHead;
                flag = 1;
            }
            if(tempPrevNodeEnd == NULL)
                tempPrevNodeEnd = tempNode;
            else
            {
                tempPrevNodeEnd->next = tempHead;
                tempPrevNodeEnd = tempNode;
            }
            tempNode->next = NULL;
        }
        return head;
    }
};