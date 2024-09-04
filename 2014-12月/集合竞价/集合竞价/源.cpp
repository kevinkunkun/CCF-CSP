#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 5010;

int n;
struct stock {
	int type;
	double p;
	int s;
	bool is_del;
}d[N];

int main()
{
	string type;
	while (cin >> type)
	{
		if (type == "buy")
		{
			double p;
			int s;
			cin >> p >> s;
			d[++n] = { 1,p,s };
		}
		else if (type == "sell")
		{
			double p;
			int s;
			cin >> p >> s;
			d[++n] = { 2,p,s };
		}
		else
		{
			int id;
			cin >> id;
			d[id].is_del = true;
			d[++n].is_del = true;
		}
	}

	double resp = 0;
	LL ress = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i].is_del == false)
		{
			double p = d[i].p;
			LL s1 = 0, s2 = 0;
			for (int j = 1; j <= n; j++)
			{
				if (d[j].is_del == false)
					if (d[j].type == 1 && d[j].p >= p)
						s1 += d[j].s;
					else if (d[j].type == 2 && d[j].p <= p)
						s2 += d[j].s;
			}
			LL t = min(s1, s2);
			if (t > ress || t == ress && p > resp)
				ress = t, resp = p;
		}
	}
	printf("%.2lf %lld\n", resp, ress);
	return 0;
}