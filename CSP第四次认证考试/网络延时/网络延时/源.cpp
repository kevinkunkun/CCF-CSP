#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010, M = N;

int n, m;
int h[N], e[M], ne[M], idx;
int ans;

//邻接表
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//深搜得到一个点的两条最长边，相加得到树的直径
int dfs(int u)
{
	int d1 = 0, d2 = 0;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		int d = dfs(j);
		if (d >= d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
	}
	ans = max(ans, d1 + d2);
	return d1 + 1;
}

int main()
{
	fastio;

	cin >> n >> m;

	memset(h, -1, sizeof h);

	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;
		add(p, i);
	}

	for (int i = n + 1; i <= n + m; i++)
	{
		int p;
		cin >> p;
		add(p, i);
	}

	dfs(1);

	cout << ans << endl;

	return 0;
}