#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 110;

int n;
unordered_map<string, int> mp;//可将string存储起来，并统计次数的哈希表

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string x = "";
		for (int j = 0; j < 8; j++)
		{
			string str;
			cin >> str;
			x += str;
		}
		mp[x]++;
		cout << mp[x] << endl;
	}

	return 0;
}