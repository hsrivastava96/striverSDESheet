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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int n = 0;
        
        ListNode *temp;
        temp = head;
        vector<ListNode *> ht;
        while(temp)
        {
            n++;
            ht.push_back(temp);
            temp = temp->next;
        }
        // cout<<n<<endl;
        
        if(head == NULL || k == 0 || n == 1 || n == k)
            return head;

        int rem = k;
        if(k > n)
        {
            if(k%n == 0)
                return head;
            else
                rem = k%n;
        }
        ht[n-rem-1]->next = NULL;
        ht[n-1]->next = head;
        head = ht[n-rem];
        
        return head;
    }
};