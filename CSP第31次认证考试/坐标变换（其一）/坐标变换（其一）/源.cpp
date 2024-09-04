#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m;
int dx[N], dy[N];

int main()
{
	fastio;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> dx[i] >> dy[i];

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = 1; j <= n; j++)
			x += dx[j], y += dy[j];
		cout << x << ' ' << y << endl;
	}

	return 0;
}