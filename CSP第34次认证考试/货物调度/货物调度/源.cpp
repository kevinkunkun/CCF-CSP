#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m, v;
int b[N], c[N];
int a[N], t[N];

int main()
{
	fastio;
	cin >> n >> m >> v;

	for (int i = 0; i < n; i++)
		cin >> b[i] >> c[i];

	for (int i = 0; i < m; i++)
		cin >> a[i] >> t[i];


}