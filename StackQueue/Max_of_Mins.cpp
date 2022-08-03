

/*
    Algo:
    Here, For each element we find for what window size they are minimum
    To do so, we find prevSmaller and nextSmaller. So, within that window the current element will be the smallest
    Step 1: Find prevSmaller and nextSmaller using stack approach
    Step 2: Now, for each calculate the length of window for which the current element is minimum. 
    Step 3: Update ans[len] = max(ans[len], a[i]) => Let Max value for len window size be INT_MIN initially
    then while traversing find out whether current index element (which is minimum for len window size) is greater than ans[len]
    if yes then update ans[len] to a[i] (i.e. current index element)
    Step 4: Now, there would be some lengths of window for which we might have not got the answer, but we do know the answer for
    maximum window size (This will be the smallest element in our array). 
    We just update all the elements in such a way that none should be smaller than the smallest max, i.e. element at max length 

*/
#include<stack>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> ds;
    
    vector<int> prevSmall(n), nextSmall(n);
    vector<int> ans(n+1, INT_MIN), res(n);
    for(int i = 0; i < n; i++)
    {
        while(!ds.empty() && a[ds.top()] >= a[i])
            ds.pop();
        if(!ds.empty())
            prevSmall[i] = ds.top();
        else
            prevSmall[i] = -1;
        ds.push(i);
    }
    
    while(!ds.empty())
        ds.pop();
    
    for(int i = n-1; i >= 0; i--)
    {
        while(!ds.empty() && a[ds.top()] >= a[i])
            ds.pop();
        
        if(!ds.empty())
            nextSmall[i] = ds.top();
        else
            nextSmall[i] = n;
        ds.push(i);
    }
    
//     cout<<"i\tPrev\tNext\tLen"<<endl;
//     for(int i = 0; i < n; i++)
//         cout<<i<<"\t"<<prevSmall[i]<<"\t\t"<<nextSmall[i]<<"\t\t"<<(nextSmall[i] - prevSmall[i] - 1)<<endl;
    
    for(int i = 0; i < n; i++)
    {
        int len = nextSmall[i] - prevSmall[i] - 1;
        if(a[i] > ans[len])
            ans[len] = a[i];
    }
    
    for(int i = n-1; i >= 1; i--)
    {
        if(ans[i+1] > ans[i])
            ans[i] = ans[i+1];
    }
    
    for(int i = 1; i < n+1; i++)
        res[i-1] = ans[i];
    
    return res;
}