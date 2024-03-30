#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cstring>
#include <algorithm>

using namespace std;

int main() 
{
	string str;
	cin >> str;

	int sum = 0;
	for (int i = 0, j = 1; i+1 < str.size(); i++)
	{
		if (str[i] != '-')
		{
			sum += (str[i] - '0') * j;
			j++;
		}
	}

		sum %= 11;
			char c = sum + '0';
			if (sum == 10)
			{
				c = 'X';
			}
		if (str.back() == c)
		{
			puts("Right");
		}
		else
		{
			str.back() = c;
			cout << str << endl;
		}
		return 0;
}