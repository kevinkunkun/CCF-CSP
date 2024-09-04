#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int p[N], t[N];
int res[N];

int dfs(int i, int res)
{
	res += t[p[i]];
	if (p[p[i]] != 0)
		return dfs(p[i], res);
	return res;
}

int main()
{
	fastio;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> p[i];

	for (int i = 1; i <= m; i++)
		cin >> t[i];

	int mx;
	for (int i = m; i >= 1; i--)
	{
		if (p[i] == 0) res[i] = 1;
		else res[i] = dfs(i, 0) + 1;
		mx = max(mx, res[i] + t[i] - 1);
	}

	for (int i = 1; i <= m; i++)
		cout << res[i] << ' ';
	cout << endl;

	if (mx > n) return 0;

	memset(res, 0x3f, sizeof res);
	for (int i = m; i >= 1; i--)
	{
		if (res[i] > n) res[i] = n - t[i] + 1;
		if (p[i] != 0) res[p[i]] = min(res[p[i]], res[i] - t[p[i]]);
	}

	for (int i = 1; i <= m; i++)
		cout << res[i] << ' ';

	return 0;
}