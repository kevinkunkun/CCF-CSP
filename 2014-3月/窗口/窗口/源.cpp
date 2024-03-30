#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int n, m;
struct Window
{
	int x1, y1, x2, y2;
	int id;
}win[N];

int get(int x,int y)
{
	for (int i = n; i; i--)
		if (x >= win[i].x1 && x <= win[i].x2 && y >= win[i].y1 && y <= win[i].y2)
			return i;
	return 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1,x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		win[i] = { x1,y1,x2,y2,i };
	}
	
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		int t = get(x, y);
		if (!t) puts("IGNORED");
		else
		{
			cout << win[t].id << endl;
			auto r = win[t];
			for (int i = t; i < n; i++)
				win[i] = win[i + 1];
			win[n] = r;
		}
	}

	return 0;
}