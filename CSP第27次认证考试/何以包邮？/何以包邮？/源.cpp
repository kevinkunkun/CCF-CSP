#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35, M = 300010;

int n, x;
int a[N];
int f[M];

int main()
{
	fastio;

	cin >> n >> x;

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	int m = sum - x;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= a[i]; j--)
			f[j] = max(f[j], f[j - a[i]] + a[i]);

	cout << sum - f[m] << endl;

	return 0;
}