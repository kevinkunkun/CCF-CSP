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

const int N = 100010;

int n, m;
double s[N], ss[N];

struct op
{
	int id;
	double x;
}op[N];

int main()
{
	fastio;
	cin >> n >> m;

	s[0] = 1;
	ss[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> op[i].id >> op[i].x;
		if (op[i].id == 1)
		{
			s[i] = s[i - 1] * op[i].x;//�����һ�ֱ任��ʽ��ǰ׺��
			ss[i] = ss[i - 1];
		}
		else if (op[i].id == 2)
		{
			ss[i] = ss[i - 1] + op[i].x;//����ڶ��ַ�ʽ��ǰ׺��
			s[i] = s[i - 1];
		}
		else continue;
	}

	while (m--)
	{
		int i, j;
		double x, y;
		cin >> i >> j >> x >> y;
		double para1 = s[j] / s[i - 1];
		double para2 = ss[j] - ss[i - 1];

		double xx = x * para1;//����x�ĵ�һ�ֱ仯
		double yy = y * para1;//����y�ĵ�һ�ֱ仯
		x = xx * cos(para2) - yy * sin(para2);//����x�ĵڶ��ֱ仯
		y = xx * sin(para2) + yy * cos(para2);//����y�ĵڶ��ֱ仯

		cout << fixed << setprecision(3) << x << ' ' << y << endl;
	}

	return 0;
}