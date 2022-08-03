/*
    Algo:
    The idea here is to find the nearest larger value of the given price
    Step 1: Pop from stack until either stack is empty or stack v[stackTop] < current value. 
    Here, v is a vecotr which holds all values received up till now
    Step 2: If stack is empty, it means all previously inserted values along with present is the span 
    (Count of values <= current value)
    Step 3: If stack is not empty, it means the top of stack is the index of element which is nearest larger value
    for current value.
    In this case set count as (total values received uptill now - stack top)
    Step 4: push current value in stack and vector and increment size counter (i)
    Step 5: return count 
*/


class StockSpanner {
public:
    stack<int> ds;
    vector<int> v;
    int i;
    StockSpanner() 
    {
        // ds.empty() = true;
        // m.size() = 0;
        i = 0;
    }
    
    int next(int price) 
    {
        int count = 0;
        
        while(!ds.empty() && v[ds.top()] <= price)
            ds.pop();
        
        if(!ds.empty())
            count = i - ds.top();
        else
            count = i + 1;
        
        ds.push(i);
        v.push_back(price);
        i++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */