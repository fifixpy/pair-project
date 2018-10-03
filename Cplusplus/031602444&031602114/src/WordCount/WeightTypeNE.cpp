#include"pch.h"
#include"WeightTypeNE.h"
using namespace std;

void WeightTypeNE(char* filem, map<string, int> &m0, int W)
{
	ifstream f;
	f.open(filem, ios::in);
	string s;
	vector<int> ans;				//��ָ���λ��
	while (!f.eof())				//һ�ζ�ȡһ��
	{
		getline(f, s);
		ans.clear();
		int i;
		int ssize = s.size();
		int start = 0;								//�ӷ�title��abstract��ʼ
		int sflag = 0;								//0Ϊabstract��1Ϊtitle��Ĭ��Ϊ0
		if (ssize > 7 && ssize < 10)
		{
			string if_Ttl = s.substr(0, 7);
			if (if_Ttl == "Title: ")
			{
				start = 7;
				sflag = 1;
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
				sflag = 1;
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
				if (start == 0)
				{
					if (sflag == 1 && W == 1)			//Ϊtitle��ȨֵΪ10
					{
						m0[s] += 10;
					}
					else m0[s]++;
	
				}
			}
			continue;
		}

		//�������һ�����ϵķָ���
		//���жϵ�һ������Ϊ��һ��û�зָ�������ͷ���
		if ((s[start] >= 97 && s[start] <= 122) && (s[start + 1] >= 97 && s[start + 1] <= 122) && (s[start + 2] >= 97
			&& s[start + 2] <= 122) && (s[start + 3] >= 97 && s[start + 3] <= 122))
		{
			string temp(s.substr(start, ans[0]));			//����ǰ�ĸ��ַ�����ĸ����ȡ
			if (sflag == 1 && W == 1)
			{
				m0[temp] += 10;
			}
			else m0[temp]++;
		}

		for (i = 0; i < sss; i++)
		{
			//����ָ������ĸ��ַ�����ĸ
			if ((s[ans[i] + 1] >= 97 && s[ans[i] + 1] <= 122) && (s[ans[i] + 2] >= 97 && s[ans[i] + 2] <= 122) &&
				(s[ans[i] + 3] >= 97 && s[ans[i] + 3] <= 122) && (s[ans[i] + 4] >= 97 && s[ans[i] + 4] <= 122))
			{
				string a;
				if (i == sss - 1)
				{
					string temp(s.substr(ans[i] + 1, s.size() - ans[i] - 1));
					a = temp;
				}
				else
				{
					string temp(s.substr(ans[i] + 1, ans[i + 1] - ans[i] - 1));
					a = temp;
				}
				if (sflag == 1 && W == 1)
				{
					m0[a] += 10;
				}
				else m0[a]++;
			}
		}

	}
}