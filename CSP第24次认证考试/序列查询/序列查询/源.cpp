#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 210;

int n, m;
int a[N];

int main()
{
	fastio;

	cin >> n >> m;
	int x = 1, res = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			res += (a[i + 1] - a[i]) * x;
		else res += (m - a[i]) * x;
		x++;
	}

	cout << res << endl;

	return 0;
}