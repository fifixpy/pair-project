#include"pch.h"
#include"WordCount.h"
using namespace std;

int WordCount(char *filename)	
{

	ifstream f;
	f.open(filename, ios::in);
	string s;
	int word_cnt = 0;
	vector<int> ans;								//��ָ���λ��
	while (!f.eof())								//һ�ζ�ȡһ��
	{
		getline(f, s);
		ans.clear();
		int i;
		int ssize = s.size();
		int start = 0;								//�ӷ�title��abstract��ʼ
		if (ssize > 7 && ssize < 10)
		{
			string if_Ttl = s.substr(0, 7);
			if (if_Ttl == "Title: ")
			{
				start = 7;
			}
		}
		else if (ssize >= 10)
		{
			string if_Abs = s.substr(0, 10);
			string if_Ttl = s.substr(0, 7);
			if (if_Abs == "Abstract: ")
			{
				start = 10;
			}
			if (if_Ttl == "Title: ")
			{
				start = 7;
			}
		}

		for (i = start; i < ssize; i++)					//�ӷ�title��start��ʼ��ָ���
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] += 32;
			}
			if (s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i]>122)
			{
				ans.push_back(i);
			}
		}
		int sss = ans.size();
		if (sss == 0)				//����ָ����Ŀ����0������ֻ��һ���ַ���
		{
			//����Ӹ÷������ĸ��ַ�������ĸ
			if ((s[0] >= 97 && s[0] <= 122) && (s[1] >= 97 && s[1] <= 122) && (s[2] >= 97 && s[2] <= 122) && (s[3] >= 97 && s[3] <= 122))
			{
				word_cnt++;
			}
			continue;
		}

		//�������һ�����ϵķָ���
		//���жϵ�һ������Ϊ��һ��û�зָ�������ͷ���
		if ((s[start] >= 97 && s[start] <= 122) && (s[start + 1] >= 97 && s[start + 1] <= 122) && (s[start + 2] >= 97
			&& s[start + 2] <= 122) && (s[start + 3] >= 97 && s[start + 3] <= 122))
		{
			word_cnt++;
		}

		for (i = 0; i < sss; i++)
		{
			//����ָ������ĸ��ַ�����ĸ
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				word_cnt++;
			}
		}

	}
	return word_cnt;
}