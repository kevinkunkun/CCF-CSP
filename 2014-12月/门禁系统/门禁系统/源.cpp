#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int g[N];

int main()
{
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		g[m]++;
		cout << g[m] << ' ';
	}	
}