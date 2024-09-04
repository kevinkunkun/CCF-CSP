#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long LL;
const int N = 100010;

LL n, m;
int op[N];
double para[N];

int main()
{
	fastio;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> op[i] >> para[i];

	for (int i = 0; i < m; i++)
	{
		LL i1, j;
		double x, y, para1 = 1, para2 = 0;
		cin >> i1 >> j >> x >> y;
		for (int t = i1; t <= j; t++)
		{
			if (op[t] == 1) para1 *= para[t];
			if (op[t] == 2)	para2 += para[t];
		}

		double xx, yy;
		xx = x * para1, yy = y * para1;
		x = (xx * cos(para2) - yy * sin(para2));
		y = (xx * sin(para2) + yy * cos(para2));

		cout << fixed << x << ' ' << y << endl;
	}

	return 0;
}