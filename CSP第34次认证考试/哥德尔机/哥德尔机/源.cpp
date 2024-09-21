#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 10010;

int n, m;
int v[N][N];

int main()
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x1, x2, y1, y2, v1;
		cin >> x1 >> x2 >> y1 >> y2 >> v1;
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
			{
				int Re = max(0, v[i][j] - v1);
				v[i][j] = v1 + Re;
			}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, x2, y1, y2, res = 0;
		cin >> x1 >> x2 >> y1 >> y2;
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				res = max(res, v[i][j]);
		cout << res << endl;
	}

	return 0;
}