#include<bits/stdc++.h>
using namespace std;

void kPerm(int pos, int n, int &seq, int k, vector<int> arr, vector<int> ds, vector<int> map, string &s)
{
	if(pos == n)
	{
		seq++;
		if(seq == k)
		{
			int zeroASCII = '0';
			for(auto it:ds)
				s+=it+zeroASCII;
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(map[i] == 0)
			{
				map[i] = 1;
				ds.push_back(arr[i]);
				kPerm(pos+1, n, seq, k, arr, ds, map, s);
				map[i] = 0;
				ds.pop_back();
			}
		}
	}
}

string getPermutation(int n, int k)
{
	vector<int> arr, map;
	int f = 1, l = 0, u = 0, range = n;
	k-=1;

	for(int i = 1; i <=n; i++)
	{
		arr.push_back(i);
		map.push_back(0);
		f*=i;
	}
	f/=range;
	u = f-1;
	string s = "";

	while(s.length() != n)
	{
		for(int i = 0; i < n; i++)
		{
			if(map[i] == 0)
			{
				if(k >= l && k <= u)
				{
					s+=arr[i] + 48;
					map[i] = 1;
					k-=l;
					break;
				}
				l+=f;
				u+=f;
			}
		}
		range-=1;
		if(range > 0)
			f/=range;
		l = 0;
		u = f - 1;
	}
	return s;
}

int main()
{
	int n, k, seq = 0;
	cin>>n>>k;

	vector<int> arr, ds, map;
	for(int i = 1; i <= n; i++)
	{
		arr.push_back(i);
		map.push_back(0);
	}

	string s, s1;
	kPerm(0, n, seq, k, arr, ds, map, s);
	s1 = getPermutation(n, k);
	cout<<s<<endl;
	cout<<s1<<endl;
	return 0;
}