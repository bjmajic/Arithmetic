#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
题目二： 国王和金矿

有一个国家发现了5座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。
参与挖矿工人的总数是10人。每座金矿要么全挖，要么不挖，不能派出一半人挖取一半金矿。
要求用程序求解出，要想得到尽可能多的黄金，应该选择挖取哪几座金矿？
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
				results[j-1] = preResults[j-1]; // 这里j=1 表示有几个工人，但是preResults的索引是从0开始，所以要-1
			}
			else
			{
				int a = preResults[j-1];
				int b = g[i];
				if (j - p[i] - 1 >= 0) //这里做一下判断，是为了防止 j 和 p[i] 相等的情况出现
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