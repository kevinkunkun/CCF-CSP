#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 55, M = 1010, INF = 1e8;

int n, L, S;
int s[N][N];
PII b[M];

int main()
{
	fastio;

	cin >> n >> L >> S;

	for (int i = 0; i < n; i++)
		cin >> b[i].x >> b[i].y;

	int tc = 0;
	for (int i = S; i >= 0; i--)
		for (int j = 0; j <= S; j++)
		{
			cin >> s[i][j];
			tc += s[i][j];
		}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int sx = b[i].x, sy = b[i].y;
		if (sx + S > L || sy + S > L) continue;

		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			int x = b[j].x, y = b[j].y;
			if (x >= sx && x - sx <= S && y >= sy && y - sy <= S)
				if (s[x - sx][y - sy] == 0) cnt = -INF;
				else cnt++;
		}
		if (cnt == tc) res++;
	}

	cout << res << endl;

	return 0;
}