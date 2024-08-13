#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//每月天数数组，其中2月按照非闰年记录，闰年单独判断加1，因为没有第0个月，所以用0代替
int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

//判断是否某一年是否是闰年的函数
int is_leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	return 0;
}

//计算某一个月有多少天
int get_days(int year, int month)
{
	if (month == 2) return months[month] + is_leap(year);
	return months[month];
}

int main()
{
	fastio;//输入输出优化

	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;

	int days = 0;
	for (int year = 1850; year <= y2; year++)//从1850年开始计算，因为要从1850年的1月1日星期二开始推算
		for (int month = 1; month <= 12; month++)//循环每一年的12个月
		{
			if (year >= y1 && month == a)//当循环到目标年份区间时进行判断与输出	
			{
				int w = (1 + days) % 7, cnt = 0;//初始化w为计算出的星期数，为了节省空间从0开始，而星期是从1开始的，所以索引值减1并对7求余；cnt为计数器，记录周数
				for (int day = 1; day <= get_days(year, month); day++)//对目标区间循环天数计算日期
				{
					if (w == c - 1)//如果星期数相同，说明已经循环完一周
					{
						cnt++;//周数自增1
						if (cnt == b)//当周数等于目标周数时，说明应该输出了
						{
							printf("%04d/%02d/%02d\n", year, month, day);//输出结果
							break;//结束当前循环，因为这一年的日期已经输出
						}
					}
					w = (w + 1) % 7;//如果没有break，说明没有到目标天数，day自增时，w也应随之改变，这里改变w的值
				}
				if (cnt < b) puts("none");//如果一个月都循环完了，但是cnt还是小于b说明不存在这一天，输出错误信息“none”
			}
			days += get_days(year, month);//从1850年开始计算天数，便于计算星期数
		}

	return 0;
}