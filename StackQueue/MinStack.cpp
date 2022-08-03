/*
    ALgo:

    We are creating two stacks here, 1 Normal stack to hold data, 
    other minStack to hold current data's corresponding minimum value
    For example:
    Array: [6, 3, 5, 2]

    Normal    Min
    Stack    Stack
    | 2 | -> | 2 |
    | 5 | -> | 3 |
    | 3 | -> | 3 |
    | 6 | -> | 6 |

    The idea here is to check if stack is empty then simply put current value in both stack
    Otherwise put current value in normal stack and put min(currentValue, minHead->top) in minHead 
    and update minHead position

*/


class MinStack {
public:
    struct node
    {
        int data;
        struct node *next;
    };
    typedef struct node Node;
    
    Node *head, *rear, *minHead;
    MinStack() 
    {
        head = NULL;
        minHead = NULL;
    }
    
    void push(int val) 
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;    
            minHead = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;

            Node *temp = new Node();
            if(newNode->data < minHead->data)
                temp->data = newNode->data;
            else
                temp->data = minHead->data;
            temp->next = minHead;
            minHead = temp;
        }
    }
    
    void pop() 
    {
        if(head)
        {
            head = head->next;
            minHead = minHead->next;
        }
    }
    
    int top() 
    {
        if(head)
            return head->data;
        return -1;
    }
    
    int getMin() 
    {
        if(minHead)
            return minHead->data;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */