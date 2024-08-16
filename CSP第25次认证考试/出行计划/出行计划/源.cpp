#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n, m, k;
int q[N];

int main()
{
	fastio;

	cin >> n >> m >> k;

	memset(q, 0, sizeof q);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		int l = max(0, x - k - y + 1), r = x - k;
		for (int i = l; i <= r; i++)
			q[i]++;
	}

	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		cout << q[t] << endl;
	}
	
	return 0;
}