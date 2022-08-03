/*
    Algo:
    Use DLL as auxilliary data structure

    There are two scenarios: get and put
    
    Get:
    If element exist, put element as most recently accessed in DLL and unordered map
    If element doesn't exist then return -1

    Put:
    If element exist, update the value of the key with current one and put element as most recently accessed in DLL and unordered map
    Otherwise, check if max_size has een reached or not. If Yes, delete head from DLL and delete the element from unordered map
    If max_size hasn't reached yet then add element to last of DLL and in unordered map
*/

class LRUCache {
public:
    
	struct node
	{
		int key, value;
		struct node *prev, *next;
	};
	typedef struct node Node;
	Node *head, *rear;

    unordered_map<int, Node *> m;
    int siz;

    LRUCache(int capacity) 
    {
        siz = capacity;    
        head = NULL;
        rear = NULL;
    }

	Node * addBottom(int k, int v)
	{
		Node *newNode;
		newNode = new Node;
		newNode->key = k;
		newNode->value = v;
		newNode->next = NULL;
		newNode->prev = NULL;

		if(head == NULL)
			head = newNode;
		else
		{
			rear->next = newNode;
			newNode->prev = rear;
		}
		rear = newNode;
        return newNode;
	}


	void delNode(Node *n)
	{
        if(n == head && n == rear)
        {
            head = NULL;
            rear = NULL;
            return;
        }
        if(n == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if(n->next)
        {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
        else
        {
            rear = n->prev;
            n->prev->next = NULL;
        }
	}
    
    int get(int k) 
    {
        if(m.find(k) != m.end())
        {
            int ret = m[k]->value;
            Node * temp = m[k];
            m.erase(k);
            delNode(temp);
            Node *r = addBottom(k, ret);
            m[k] = r;    
            return ret;
        }
        return -1;
    }
    
    void put(int k, int v) 
    {        
        if(m.find(k) != m.end())
        {
            Node * temp = m[k];
            m.erase(k);
            delNode(temp);
        }
        else if(m.size() == siz)
        {
            Node *temp = head;
            m.erase(head->key);
            delNode(temp);
        }
        Node *r = addBottom(k, v);
        m[k] = r;    
    }
};

