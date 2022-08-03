#include<bits/stdc++.h>
using namespace std;

void subSum(int ind, vector<int> arr, int n, vector<int> ds, vector<vector<int>> &mainDs)
{
	if(ind == n)
		return;
	else
	{

		// Choose one of the unique values for the index
		ds.push_back(arr[ind]);
		mainDs.push_back(ds);
		subSum(ind+1, arr, n, ds, mainDs);

		for(int i = ind+1; i < n; i++)
		{
			if(arr[i] != arr[i-1])
			{
				ds.pop_back();
				ds.push_back(arr[i]);
				mainDs.push_back(ds);
				subSum(i+1, arr, n, ds, mainDs);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;

	vector<int> arr, ds;
	vector<vector<int>> mainDs;
	for(int i = 0; i < n; i++)
	{
		int val;
		cin>>val;
		arr.push_back(val);
	}

	sort(arr.begin(), arr.end());
	subSum(0, arr, n, ds, mainDs);

	for(auto row:mainDs)
		for(auto cell:row)
			cout<<cell<<" ";
		cout<<endl;

	return 0;
}