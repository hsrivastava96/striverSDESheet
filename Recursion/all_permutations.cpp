#include<bits/stdc++.h>
using namespace std;

void perm(int count, int n, vector<int> arr, vector<int> ds, vector<int> map, int &ans)
{
    if(count == n)
    {
        for(auto it:ds)
            cout<<it<<" ";
        cout<<endl;
        ans++;
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
                perm(count+1, n, arr, ds, map, ans);
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

    vector<int> v, ds, map;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
        map.push_back(0);
    }

    sort(v.begin(), v.end());
    int ans = 0;
    perm(0, n, v, ds, map, ans);
    cout<<ans<<endl;
    return 0;
}