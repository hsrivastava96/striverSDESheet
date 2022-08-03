#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

ListNode * getHead(int num, ListNode *p)
{
	if(num != 0)
	{
		int rem = num%10;
		int q = num/10;
		ListNode *h, *currNode;
		currNode = new ListNode;
		currNode->val = rem;
		currNode->next = p;
		h = getHead(q, currNode);
		if(h == NULL)
			h = currNode;
		return h;
	}
	return NULL;
}

// Optimised solution
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
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *t1, *t2, *h, *newNode, *temp;
        int carry = 0, currVal = 0;
        t1 = l1;
        t2 = l2;
        h = NULL;
        temp = NULL;
        while(t1 && t2)
        {
            int sum = t1->val + t2->val + carry;
            newNode = new ListNode;
            newNode->next = NULL;
            if(sum > 9)
            {
                carry = sum/10;
                currVal = sum%10;
            }
            else
            {
                carry = 0;
                currVal = sum;
            }
            newNode->val = currVal;
            if(temp == NULL)
                h = newNode;
            else
                temp->next = newNode;
            temp = newNode;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1)
        {
            int sum = t1->val + carry;
            newNode = new ListNode;
            newNode->next = NULL;
            if(sum > 9)
            {
                carry = sum/10;
                currVal = sum%10;
            }
            else
            {
                carry = 0;
                currVal = sum;
            }
            newNode->val = currVal;
            temp->next = newNode;
            temp = newNode;
            t1 = t1->next;
        }
        while(t2)
        {
            int sum = t2->val + carry;
            newNode = new ListNode;
            newNode->next = NULL;
            if(sum > 9)
            {
                carry = sum/10;
                currVal = sum%10;
            }
            else
            {
                carry = 0;
                currVal = sum;
            }
            newNode->val = currVal;
            temp->next = newNode;
            temp = newNode;
            t2 = t2->next;
        }
        if(carry > 0)
        {
            newNode = new ListNode;
            newNode->next = NULL;
            newNode->val = carry;
            temp->next = newNode;
            temp = newNode;
        }
        return h;
    }
};
int main()
{
	ListNode *h, *temp;
	h = getHead(78567, NULL);
	temp = h;
	while(temp != NULL)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
	return 0;
}