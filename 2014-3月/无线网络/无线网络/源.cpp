#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 210, M = N * N;

int n, m, k, r;
int h[N], e[M], ne[M], idx;
PII p[N];
int dist[N][N];

bool check(PII a, PII b)
{
	LL dx = a.x - b.x;
	LL dy = a.y - b.y;
	return dx * dx + dy * dy <= (LL)r * r;
}

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
	queue<PII> q;
	q.push({ 1,0 });
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;

	while (q.size())
	{
		auto t = q.front();
		q.pop();

		for (int i = h[t.x]; ~i; i = ne[i])
		{
			int x = e[i], y = t.y;
			if (x > n) y++;
			if (y <= k)
			{
				if (dist[x][y] > dist[t.x][t.y] + 1)
				{
					dist[x][y] = dist[t.x][t.y] + 1;
					q.push({ x,y });
				}
			}
		}
	}

	int res = 1e8;
	for (int i = 0; i <= k; i++)
	{
		res = min(res, dist[2][i]);
	}
	return res - 1;
}

int main()
{
	cin >> n >> m >> k >> r;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	for (int i = n + 1; i <= n + m; i++) cin >> p[i].x >> p[i].y;

	for (int i = 1; i <= n + m; i++)
		for (int j = i + 1; j <= n + m; j++)
			if (check(p[i], p[j]))
			{
				add(i, j);
				add(j, i);
			}
	cout << bfs() << endl;

	return 0;
}