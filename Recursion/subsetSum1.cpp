#include<bits/stdc++.h>
using namespace std;

void subSum(int ind, vector<int> arr, int n, vector<int> &ds, int sum)
{
	if(ind == n)
	{
		ds.push_back(sum);
		return;
	}
	else
	{
		// select index
		sum+=arr[ind];
		subSum(ind+1, arr, n, ds, sum);

		// not select index
		sum-=arr[ind];
		subSum(ind+1, arr, n, ds, sum);
	}
}

int main()
{
	int n;
	cin>>n;

	vector<int> arr, ds;
	for(int i = 0; i < n; i++)
	{
		int val;
		cin>>val;
		arr.push_back(val);
	}

	subSum(0, arr, n, ds, 0);
	sort(ds.begin(), ds.end());

	for(auto it:ds)
		cout<<it<<" ";
	cout<<endl;

	return 0;
}