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

const int N = 55;

int n;
double I;
double g[N];

int main()
{
	fastio;

	cin >> n >> I;

	for (int i = 0; i <= n; i++)
		cin >> g[i];

	double res = 0;
	for (int i = 0; i <= n; i++)
	{
		double val;
		val = g[i] * pow(1 + I, (-i));
		res += val;
	}

	cout << res << endl;

	return 0;
}