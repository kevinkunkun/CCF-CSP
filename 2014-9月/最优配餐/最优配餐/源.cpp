#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1010;

int n, m, k,d;
bool g[N][N];
int dist[N][N];
queue<PII> q;
struct Target
{
	int x, y, c;
}tg[N * N];

void bfs()
{
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
	while (q.size())
	{
		auto t = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if (x < 1 || x > n || y < 1 || y > n || g[x][y]) continue;
			if (dist[x][y] > dist[t.x][t.y] + 1)
			{
				dist[x][y] = dist[t.x][t.y] + 1;
				q.push({ x,y });
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &d);
	memset(dist, 0x3f, sizeof dist);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		dist[x][y] = 0;
		q.push({ x,y });
	}

	for (int i = 0; i < k; i++)
		scanf("%d%d%d", &tg[i].x, &tg[i].y, &tg[i].c);

	while (d--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = true;
	}
	bfs();

	LL res = 0;
	for (int i = 0; i < k; i++)
		res += dist[tg[i].x][tg[i].y] * tg[i].c;
	printf("%lld\n", res);
	return 0;
}