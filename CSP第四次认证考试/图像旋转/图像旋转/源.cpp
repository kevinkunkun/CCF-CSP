#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int g[N][N];

int main()
{
	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];

	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
			cout << g[j][i] << ' ';
		cout << endl;
	}

	return 0;
}