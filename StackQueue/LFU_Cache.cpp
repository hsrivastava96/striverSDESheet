struct node
{
    int key, value, frequency;
    struct node *prev, *next;
};
typedef struct node Node;

class DLL
{
public:
	Node *head, *rear;
    DLL() 
    {
        head = NULL;
        rear = NULL;
    }

	Node * addBottom(int k, int v, int f)
	{
		Node *newNode;
		newNode = new Node;
		newNode->key = k;
		newNode->value = v;
		newNode->frequency = f;
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
            rear = rear->prev;
            rear->next = NULL;
        }
	}
};

class LFUCache {
public:
    
    unordered_map<int, DLL *> fr;
    unordered_map<int, Node *> m;
    int siz;

    LFUCache(int capacity) 
    {
        siz = capacity;    
    }
    
    int get(int k) 
    {
        if(m.find(k) != m.end())
        {
            Node *nAdd = m[k], *r;
            int currF = nAdd->frequency, newF = nAdd->frequency+=1, retVal = m[k]->value;
            nAdd->frequency+=1;
            
            fr[currF]->delNode(nAdd);     
            
            if(fr.find(newF) != fr.end())
                r = fr[newF]->addBottom(k, nAdd->value, newF);
            else
            {
                DLL *newOb;
                r = newOb->addBottom(k, nAdd->value, newF);
                fr[newF] = newOb;
            }
            
            m[k] = r;
            return retVal;
        }
        return -1;
    }
    
    void put(int k, int v) 
    {
        cout<<"Put --> ("<<k<<", "<<v<<") "<<m.size()<<" "<<siz<<endl;
        cout<<"DLL:"<<endl;
        
        Node *tmp = fr[k]->head;
        while(tmp)
        {
            cout<<"DLL: ("<<tmp->key<<", "<<tmp->value<<")"<<endl;
            tmp = tmp->next;
        }
        int tempF = 0;
        
        if(m.find(k) != m.end())
        {
            cout<<"Deleting --> ("<<m[k]->key<<", "<<m[k]->value<<")"<<endl;
            Node * temp = m[k];
            tempF = temp->frequency;
            m.erase(k);
            fr[temp->frequency]->delNode(temp);
        }
        else if(m.size() == siz)
        {
            cout<<"Deleting --> ("<<fr[k]->head->key<<", "<<fr[k]->head->value<<")"<<endl;
            m.erase(fr[k]->head->key);
            fr[k]->delNode(fr[k]->head);
        }
        
        Node *r;
        if(tempF != 0)
            r = fr[tempF]->addBottom(k, v, tempF);
        else
        {
            cout<<"COming in here!"<<endl;
            DLL *ob;
            ob = new DLL();
            r = ob->addBottom(k, v, 1);
            fr[1] = ob;
        }
        m[k] = r;    
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
