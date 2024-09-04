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

const int N = 1010;

int n;
double a[N], f[N];
double sum, d;

int main()
{
	fastio;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		double x;
		cin >> x;
		sum += x;
		a[i] = x;
	}
	
	double a1 = sum / (double)n;

	sum = 0;
	for (int i = 1; i <= n; i++)
		sum += pow(a[i] - a1, 2);
		
	d = pow(sum / (double)n, 0.5);

	for (int i = 1; i <= n; i++)
		f[i] = (a[i] - a1) / d;

	for (int i = 1; i <= n; i++)
		cout << fixed << setprecision(16) << f[i] << endl;

	return 0;
}