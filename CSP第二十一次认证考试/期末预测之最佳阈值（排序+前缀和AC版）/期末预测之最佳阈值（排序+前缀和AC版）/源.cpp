#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int n;
PII q[N];
int s[2][N];

int main()
{
	fastio;

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> q[i].x >> q[i].y;

	sort(q + 1, q + n + 1);

	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			s[i][j] += s[i][j - 1] + (q[j].y == i);

	int cnt = -1, res;
	for (int i = 1; i <= n; i++)
	{
		int t = s[0][i - 1] + s[1][n] - s[1][i - 1];
		if (t >= cnt) cnt = t, res = q[i].x;
		while (i + 1 <= n && q[i + 1].x == q[i].x) i++;
	}

	cout << res << endl;

	return 0;
}