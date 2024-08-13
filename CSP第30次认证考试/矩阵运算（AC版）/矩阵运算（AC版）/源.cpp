#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 10010, M = 25;

int n, d;
int Q[N][M], K[M][N], V[N][M], W[N];
LL res1[M][M], res2[N][M];

int main()
{
    fastio;
    cin >> n >> d;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= d; j++)
            cin >> Q[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= d; j++)
            cin >> K[j][i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= d; j++)
            cin >> V[i][j];

    for (int i = 1; i <= n; i++)
        cin >> W[i];

    memset(res1, 0, sizeof res1);
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            for (int z = 1; z <= n; z++)
                res1[i][j] += K[i][z] * V[z][j];

    memset(res2, 0, sizeof res2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= d; j++)
            for (int z = 1; z <= d; z++)
                res2[i][j] += Q[i][z] * res1[z][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            res2[i][j] *= W[i];
            cout << res2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}