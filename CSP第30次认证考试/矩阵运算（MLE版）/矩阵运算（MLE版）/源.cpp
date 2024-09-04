#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 10010, M = 25;

LL n, d;
LL w[N];
LL q[N][M], res1[N][M], res[N][N], v[N][M], k[N][M], v1[M][N];

int main()
{
	fastio;
	cin >> n >> d;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			cin >> q[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			cin >> k[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			cin >> v[i][j];

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			res[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int t = 1; t <= d; t++)
				res[i][j] += q[i][t] * k[j][t];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			res[i][j] *= w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			v1[j][i] = v[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			res1[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			for (int t = 1; t <= n; t++)
				res1[i][j] += res[i][t] * v1[j][t];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= d; j++)
			cout << res1[i][j] << ' ';
		cout << endl;
	}

	return 0;
}