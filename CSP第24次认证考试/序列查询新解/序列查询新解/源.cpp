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

typedef long long LL;
const int N = 1e5 + 10;

int n, m;
int R;
int a[N];

LL get(int l, int r)
{
	if (l / R == r / R) return (r - l + 1) * (l / R);
	int a = l / R + 1, b = r / R - 1;
	LL res = (LL)(a + b) * (b - a + 1) / 2 * R;
	res += (LL)(a - 1) * (a * R - l);
	res += (LL)(b + 1) * (r - (b + 1) * R + 1);
	return res;
}

int main()
{
	fastio;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[n + 1] = m;
	R = m / (n + 1);

	LL res = 0;
	for (int i = 0; i <= n; i++)
	{
		int l = a[i], r = a[i + 1] - 1;
		int x = l / R, y = r / R;
		if (y <= i || x >= i)
		{
			res += abs((LL)i * (r - l + 1) - get(l, r));
		}
		else
		{
			int mid = i * R;
			res += abs((LL)i * (mid - l + 1) - get(l, mid));
			res += abs((LL)i * (r - mid) - get(mid + 1, r));
		}
	}

	cout << res << endl;

	return 0;
}