#include"pch.h"
#include"CharCount.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

int CharCount(char *filename)						
{
	char ch_tmp;
	int ch_cnt = 0;
	int flag = -1;
	string str;
	fstream f_tmp;
	f_tmp.open(filename);
	if (!f_tmp)
	{
		cout << "Can't open file :" << filename << "\nUsage:countch filename" << endl;
		exit(0);
	}
	while (!f_tmp.eof())
	{
		getline(f_tmp, str);
		int str_len = str.length();
		if ((str[0] >= '0' && str[0] <= '9') && (str[str_len - 1] >= '0' && str[str_len - 1] <= '9'))			//��������ų����ַ�ͳ����
		{
			continue;
		}
		if (str_len > 7)																						//�����ַ������ȴ���Title����
		{
			string no_Count_Ttl = str.substr(0, 7);
			string no_Count_Abs = str.substr(0, 10);
			if (no_Count_Ttl == "Title: ")
			{
				ch_cnt += str_len - 7;
			}
			else if (no_Count_Abs == "Abstract: ")
			{
				ch_cnt += str_len - 10;
			}
			else								//������û��Title: Ҳû��Abstract: ����Ч�У�
			{
				ch_cnt += str_len;
			}
			if (str_len != 1024)				//������1024ȫ���������û�л��з�������������һ�����з���
			{
				ch_cnt++;
			}
		}
		else									//�����ַ�������С��7�������ǿ��л���ֻ�м����̵����ܳ�С��7��
		{
			if (str_len == 0)
			{
				continue;
			}
			else
			{
				ch_cnt += str_len + 1;
			}
		}
	}
	f_tmp.close();
	return ch_cnt - 1;
}