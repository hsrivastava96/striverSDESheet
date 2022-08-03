/*
Algo:

Step 1: Traverse the given vector from right to left
Step 2: If stack is empty then push the current element's index on to the stack otherwise move to step 3
Step 3: Start a flag with 0
Step 4: if(top is greater than current element) then set currentElement in answer data structure in place odf top index value
otherwise set flag = 1
Step 5: if stack gets vacated set flag = 1 and move to step 6 otherwise move to step 4
Step 6: now for each value in stack set answer as -1
Step 7: Return answer data structure

Time Complexity: in worst case O(n^2), best case: O(n)
Time Complexity (For nested looping in trivial solution): O(n^2) in both worst and best case 
because there we are traversing each element n times for each element


*/

vector<int> Solution::prevSmaller(vector<int> &A) 
{
    int n = A.size();
    vector<int> ans(n, 0);
    stack<int> ds;
    
    for(int i = n-1; i >= 0; i--)
    {
        if(ds.empty())
            ds.push(i);
        else
        {
            int flag = 0;
            while(flag == 0)
            {
                int topValInd = ds.top();
                if(A[topValInd] > A[i])
                {
                    ans[topValInd] = A[i];
                    ds.pop();
                }
                else
                    flag = 1;
                if(ds.empty())
                    flag = 1;
            }
            ds.push(i);
        }
    }
    while(!ds.empty())
    {
        int topValInd = ds.top();
        ans[topValInd] = -1;
        ds.pop();
    }
    return ans;    
}
