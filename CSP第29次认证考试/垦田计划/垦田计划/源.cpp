#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 100010;

int n, k;
LL m;
int t[N], c[N];

bool checked(int mid)
{
	LL res = 0;
	for (int i = 1; i <= n; i++)
		if (t[i] > mid)
			res += (t[i] - mid) * c[i];
	return res <= m;
}

int main()
{
	fastio;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> t[i] >> c[i];

	//从k开始直至最大二分，每次判断是否是最小的且符合条件的天数，直至取到此天数
	int l = k, r = 1e5;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (checked(mid)) r = mid;
		else l = mid + 1;
	}

	cout << r << endl;

	return 0;
}