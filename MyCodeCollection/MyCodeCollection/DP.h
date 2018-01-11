#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
��Ŀ���� �����ͽ��

��һ�����ҷ�����5�����ÿ�����Ļƽ�����ͬ����Ҫ�����ھ�Ĺ�����Ҳ��ͬ��
�����ڿ��˵�������10�ˡ�ÿ�����Ҫôȫ�ڣ�Ҫô���ڣ������ɳ�һ������ȡһ����
Ҫ���ó���������Ҫ��õ������ܶ�Ļƽ�Ӧ��ѡ����ȡ�ļ������
*/
int GetMostGold(int n, int w, int* g, int* p)
{
	//int* preResults = new int[w];
	//int* results = new int[w];
	vector<int> preResults(w);
	vector<int> results(w);

	for (int i = 1; i <= w; i++)
	{
		if (i < p[0])
		{
			preResults[i-1] = 0;
		}
		else
		{
			preResults[i-1] = g[0];
		}
	}

#ifdef _DEBUG
	for (int i = 0; i < w; i++)
	{
		cout << "preResults[" << i << "] = " << preResults[i] << endl;
		
	}
	cout << "***************************" << endl;
#endif
	results = preResults;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (j < p[i])
			{
				results[j-1] = preResults[j-1];
			}
			else
			{
				int a = preResults[j-1];
				int b = g[i];
				if (j - p[i] - 1 >= 0)
				{
					b = preResults[j - p[i] - 1] + g[i];
				}
				results[j-1] = max(a, b);
			}
		}
		preResults = results;
#ifdef _DEBUG
		for (int ii = 0; ii < w; ii++)
		{
			cout << "preResults[" << ii << "] = " << preResults[ii] << endl;
		}
		cout << "***************************" << endl;
#endif
	}
	return results[w - 1];
}

void TestGetMostGold()
{
	int g[5] = {400, 500, 200, 300, 350};
	int p[5] = { 5, 5, 3, 4, 3 };
	int res = GetMostGold(5, 10, g, p);
	cout << "gold = " << res << endl;
}