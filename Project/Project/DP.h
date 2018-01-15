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
				results[j-1] = preResults[j-1]; // ����j=1 ��ʾ�м������ˣ�����preResults�������Ǵ�0��ʼ������Ҫ-1
			}
			else
			{
				int a = preResults[j-1];
				int b = g[i];
				if (j - p[i] - 1 >= 0) //������һ���жϣ���Ϊ�˷�ֹ j �� p[i] ��ȵ��������
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


class PackageItem
{
public:
	string name;
	int weight;
	int value;

	PackageItem()
	{

	}

	PackageItem(string name_, int weight_, int value_)
	{
		name = name_;
		weight = weight_;
		value = value_;
	}

	friend bool operator < (const PackageItem& item1, const PackageItem& item2)
	{
		return item1.weight < item2.weight;
	}
};

/*0-1��������*/
int Get01PackageAnswer(vector<PackageItem> bagitems, int bagweight)
{
	vector<string> answer;

	vector<int> result(bagweight+1);
	vector<int> preresults(bagweight+1);

	for (int i = 0; i <= bagweight; i++)
	{
		preresults[i] = 0;
	}

	for (int i = 0; i < bagitems.size(); i++)
	{
		for (int j = 0; j <= bagweight; j++)
		{
			if (j < bagitems[i].weight)
			{
				result[j] = preresults[j];  // ״̬ת�Ʒ��� f(n, p) = f(n-1, p)
			}
			else
			{
				int a = preresults[j];
				int b = bagitems[i].value + preresults[j - bagitems[i].weight];
				result[j] = max(a, b);
			}
		}
		preresults = result;
#ifdef _DEBUG
		for (int ii = 1; ii <= bagweight; ii++)
		{
			cout << "item = " << i << endl;
			cout << "preResults[" << ii << "] = " << preresults[ii] << endl;
		}
		cout << "***************************" << endl;
#endif
	}
	return result[bagweight];
}

void TestGetMostGold()
{
	int g[5] = {400, 500, 200, 300, 350};
	int p[5] = { 5, 5, 3, 4, 3 };
	int res = GetMostGold(5, 10, g, p);
	cout << "gold = " << res << endl;
}

void Test_Get01PackageAnswer()
{
	/*string nameArr[5] = { "a", "b", "c", "d", "e" };
	int weightArr[5] = { 2, 2, 6, 5, 4 };
	int valueArr[5] = { 6, 3, 5, 4, 6 };*/
	string nameArr[5] = { "e", "d", "c", "b", "a" };
	int weightArr[5] = { 4, 5, 6, 2, 2 };
	int valueArr[5] = { 6, 4, 5, 3, 6 };
	vector<PackageItem> bagItems(5);
	for (int i = 0; i < 5; i++)
	{
		PackageItem a(nameArr[i], weightArr[i], valueArr[i]);
		bagItems[i] = a;
	}
	
	cout << "most value = " << Get01PackageAnswer(bagItems, 10) << endl;
}