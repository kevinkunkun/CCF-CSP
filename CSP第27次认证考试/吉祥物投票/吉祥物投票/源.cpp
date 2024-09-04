#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 1e6 + 10;

int n, m, q;
int p[M], W[N];

int main()
{
	fastio;

	cin >> n >> m >> q;

	memset(p, 0, sizeof p);
	memset(W, 0, sizeof W);
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, x, sum = 0;
			cin >> l >> r >> x;
			for (int i = l; i <= r; i++)
			{
				if (p[i] == x) continue;
				else if (p[i] != 0)
				{
					W[p[i]]--, W[x]++;
					p[i] = x;
				}
				else
				{
					W[x]++;
					p[i] = x;
				}

			}
		}
		else if (op == 2)
		{
			int x, w;
			cin >> x >> w;
			for (int i = 1; i <= n; i++)
				if (p[i] == x)
					p[i] = w;
			W[x] = 0, W[w] += W[x];
		}
		else if (op == 3)
		{
			int x, y, sum1 = 0, sum2 = 0;
			cin >> x >> y;
			for (int i = 1; i <= n; i++)
			{
				if (p[i] == x)
				{
					p[i] = m + 1;
					sum1++;
				}
				if (p[i] == y)
				{
					p[i] = x;
					sum2++;
				}
				if (p[i] == m + 1)
					p[i] = y;
				W[x] += sum2 - sum1;
				W[y] += sum1 - sum2;
			}
		}
		else if (op == 4)
		{
			int w;
			cin >> w;
			if (w == 0)
			{
				int res = 0;
				for (int i = 1; i <= n; i++)
					if (p[i] == 0)
						res++;
				cout << res << endl;
			}
			else
			{
				int res = 0;
				for (int i = 1; i <= n; i++)
					if (p[i] == w)
						res++;
				cout << res << endl;
			}
		}
		else if (op == 5)
		{
			int res = 0, id = 0;
			for (int i = 1; i <= m; i++)
			{
				if (res == W[i] || W[i] == 0) continue;
				res = max(res, W[i]);
				if (res == W[i])
					id = i;
				//cout << res << W[i] << ' '	;
			}
			//cout << endl;
			cout << id << endl;
		}
	}

	return 0;
}