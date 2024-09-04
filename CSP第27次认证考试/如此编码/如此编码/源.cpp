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
const int N = 30;

int n, m;
int a[N], b[N];
LL c[N];

int main()
{
	fastio;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	c[0] = 1;
	for (int i = 1; i <= n; i++)
		c[i] = a[i] * c[i - 1];

	for (int i = 0; i < n; i++)
		b[i + 1] = ((m % c[i + 1]) - (m % c[i])) / c[i];

	for (int i = 1; i <= n; i++)
		cout << b[i] << ' ';

	return 0;
}
