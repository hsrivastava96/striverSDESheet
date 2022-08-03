vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> v;
        int curMax = a[n-1];
        v.push_back(curMax);
        for(int i = n-2; i >= 0; i--)
        {
            if(a[i] >= curMax)
            {
                curMax = a[i];
                v.push_back(curMax);
            }
        }
        vector<int> res;
        int sz = v.size();
        for(int i = sz-1; i>=0; i--)
            res.push_back(v[i]);
        return res;
    }