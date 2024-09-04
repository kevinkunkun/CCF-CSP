#define _CRT_SECURE_NO_WARNINGS
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//ÿ���������飬����2�°��շ������¼�����굥���жϼ�1����Ϊû�е�0���£�������0����
int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

//�ж��Ƿ�ĳһ���Ƿ�������ĺ���
int is_leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	return 0;
}

//����ĳһ�����ж�����
int get_days(int year, int month)
{
	if (month == 2) return months[month] + is_leap(year);
	return months[month];
}

int main()
{
	fastio;//��������Ż�

	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;

	int days = 0;
	for (int year = 1850; year <= y2; year++)//��1850�꿪ʼ���㣬��ΪҪ��1850���1��1�����ڶ���ʼ����
		for (int month = 1; month <= 12; month++)//ѭ��ÿһ���12����
		{
			if (year >= y1 && month == a)//��ѭ����Ŀ���������ʱ�����ж������	
			{
				int w = (1 + days) % 7, cnt = 0;//��ʼ��wΪ���������������Ϊ�˽�ʡ�ռ��0��ʼ���������Ǵ�1��ʼ�ģ���������ֵ��1����7���ࣻcntΪ����������¼����
				for (int day = 1; day <= get_days(year, month); day++)//��Ŀ������ѭ��������������
				{
					if (w == c - 1)//�����������ͬ��˵���Ѿ�ѭ����һ��
					{
						cnt++;//��������1
						if (cnt == b)//����������Ŀ������ʱ��˵��Ӧ�������
						{
							printf("%04d/%02d/%02d\n", year, month, day);//������
							break;//������ǰѭ������Ϊ��һ��������Ѿ����
						}
					}
					w = (w + 1) % 7;//���û��break��˵��û�е�Ŀ��������day����ʱ��wҲӦ��֮�ı䣬����ı�w��ֵ
				}
				if (cnt < b) puts("none");//���һ���¶�ѭ�����ˣ�����cnt����С��b˵����������һ�죬���������Ϣ��none��
			}
			days += get_days(year, month);//��1850�꿪ʼ�������������ڼ���������
		}

	return 0;
}