#include<bits/stdc++.h>
using namespace std;

void perm(int count, int n, vector<int> arr, vector<int> ds, vector<int> map, vector<int> given, int &ans, int &ind)
{
    if(count == n)
    {
        ans++;
        if(ind != -1)
        {
            cout<<ans<<endl;
            for(auto it:ds)
                cout<<it<<" ";
            cout<<endl;
            ind = -1;
        }    
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(ds[i] != given[i])
                    return;
            }
            cout<<ans<<endl;
            for(auto it:ds)
                cout<<it<<" ";
            cout<<endl;
            ind = ans+1;
        }
    }
    else
    {
        int temp = -1;
        for(int i = 0; i < n; i++)
        {
            if(map[i] == 0 && arr[i] != temp)
            {
                ds.push_back(arr[i]);
                map[i] = 1;
                perm(count+1, n, arr, ds, map, given, ans, ind);
                ds.pop_back();
                map[i] = 0;
                temp = arr[i];
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> v, ds, map, given;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
        given.push_back(val);
        map.push_back(0);
    }

    sort(v.begin(), v.end());
    int ans = 0, ind = -1;
    perm(0, n, v, ds, map, given, ans, ind);
    cout<<ans<<endl;
    return 0;
}