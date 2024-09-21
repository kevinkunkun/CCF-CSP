#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m, t;
int p, q;
int a[N];
bool flag1 = false, flag2 = false;
int b[N][N];

int main()
{
    fastio;

    cin >> n >> m >> t;

    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[k];
            k++;
        }

    while (t--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            cin >> p >> q;
            flag1 = true;
        }
        else if (op == 2)
        {
            k = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    b[i][j] = a[k];
                    k++;
                }

            k = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    a[k] = b[j][i];
                    k++;
                }
            flag2 = true;
        }
        else
        {
            int x, y;
            cin >> x >> y;

            if (flag1 == false && flag2 == false)
                cout << a[x * m + y] << endl;

            if (flag1)
            {
                cout << a[x * q + y] << endl;
                flag1 = false;
            }

            if (flag2)
            {
                cout << a[x * n + y] << endl;
                flag2 = false;
            }
        }
    }

    return 0;
}