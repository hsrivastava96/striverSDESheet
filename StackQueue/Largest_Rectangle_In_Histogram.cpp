/*
    Algo:

    Traverse from left and find the nearest small element's index, to do this:
    Step 1: Pop stack top until it is either empty or height corresponding ot stack top is smaller than current index height
    Step 2: If stack is not empty, set current index's left nearest small element 
    as value at stack top + 1 index (This index is inclusive of width for current index height)
    Step 3: If stack is empty then set 0 current index's left nearest small element 

    Similarly,
    For rightMin
    Step 1: Pop stack top until it is either empty or height corresponding ot stack top is smaller than current index height
    Step 2: If stack is not empty, set current index's right nearest small element 
    as value at stack top - 1 index (This index is inclusive of width for current index height)
    Step 3: If stack is empty then set n-1 current index's left nearest small element 
*/



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int max = 0, area = 0, n = heights.size();

        stack<int> leftStack, rightStack;
        
        vector<int> leftMin(n, 0), rightMin(n, n-1);
                
        for(int i = 0; i < n; i++)
        {
            while(!leftStack.empty() && heights[leftStack.top()] >= heights[i])
                leftStack.pop();
            if(!leftStack.empty())
                leftMin[i] = leftStack.top() + 1;
            else
                leftMin[i] = 0;
            leftStack.push(i);
        }

        for(int i = n-1; i >= 0; i--)
        {
            while(!rightStack.empty() && heights[rightStack.top()] >= heights[i])
                rightStack.pop();
            if(!rightStack.empty())
                rightMin[i] = rightStack.top() - 1;
            else
                rightMin[i] = n-1;
            rightStack.push(i);
        }
        
        // cout<<"I\tRight\tLeft\tArea\tMax"<<endl;
        for(int i = 0; i < n; i++)
        {
            area = heights[i]*(rightMin[i] - leftMin[i] + 1);
            if(area > max)
                max = area;
            // cout<<i<<"\t"<<rightMin[i]<<"\t"<<leftMin[i]<<"\t"<<area<<"\t"<<max<<endl;
        }
        return max;
    }
};