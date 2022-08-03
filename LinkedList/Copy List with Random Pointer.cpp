/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        map<Node*, Node*> ds;
        
        Node *temp, *newHead, *prev, *temp1;
        temp = head;
        prev = NULL;
        newHead = NULL;
        
        while(temp)
        {
            Node *newNode;
            newNode = new Node(temp->val);
            
            if(newHead == NULL)
                newHead = newNode;
            ds.insert(pair<Node *, Node *>(temp, newNode));
            if(prev == NULL)
                prev = newNode;
            else
            {
                prev->next = newNode;
                prev = newNode;
            }
            temp = temp->next;
        }
        
        temp = head;
        temp1 = newHead;
        
        while(temp)
        {
            if(temp->random)
                temp1->random = ds.find(temp->random)->second;
            else
                temp1->random = NULL;
            temp = temp->next;
            temp1 = temp1->next;
        }
        
        return newHead;
    }
};