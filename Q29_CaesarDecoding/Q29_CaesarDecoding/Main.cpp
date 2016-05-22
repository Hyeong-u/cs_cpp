/*************************************************************************
*																		 *
* Problem:																 *
* 시이저 암호문 복호기법												 *
*																		 *
*************************************************************************/
/*************************************************************************
*																		 *
* 국민대학교 전자정보통신대학 컴퓨터공학부 2 학년						 *
* 20153168 김형우														 *
*																		 *
*************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

double KaiSqure(int key, char arr[200]);

double freq[26] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996,
0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074 };
int main()
{
	ifstream in;
	int numTestCases;
	in.open("input.txt"); /* open input file */
	if (in.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int num;
		double min = 0;
		double temp;
		int ans = 0;
		int key = 0;
		char arr[200];
		
		double kaiSqure[26] = { 0.0 , };
		char result[200];
		in >> arr;
		int idx = 0;
		

		for (int j = 0; j < 26; j++)
		{
			temp = KaiSqure(j, arr);
			kaiSqure[j] = temp;
		}
		min = kaiSqure[0];
		for (int j = 0; j < 26; j++)
		{
			if (min > kaiSqure[j])
			{
				min = kaiSqure[j];
				key = j;
			}
		}

		num = key;
		idx = 0;
		while (arr[idx] != NULL) {
			if ('a' <= arr[idx] && arr[idx] <= 'z')
			{
				if (arr[idx] - num < 'a')
				{
					result[idx] = arr[idx++] - num + 26;
					continue;
				}
				result[idx] = arr[idx++] + num;
				continue;
			}
			if ('A' <= arr[idx] && arr[idx] <= 'Z')
			{
				if (arr[idx] - num < 'A')
				{
					result[idx] = arr[idx++] - num + 26;
					continue;
				}
				result[idx] = arr[idx++] + num;
				continue;
			}
			result[idx] = arr[idx++];
		}
		result[idx] = NULL;

		idx = 0;
		while (result[idx] != NULL)
		{
			cout << result[idx++];
		}
		cout << endl;

		//cout << result << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}

double KaiSqure(int key, char arr[200])
{
	int idx = 0;
	int num = key;
	int alphanum = 0; // 알바벳 갯수
	double freqresult[26] = { 0.0, };
	double out = 0.0;
	char result[200];

	while (arr[idx] != NULL) {
		if ('a' <= arr[idx] && arr[idx] <= 'z')
		{
			if (arr[idx] + num > 'z')
			{
				result[idx] = arr[idx++] + num - 26;
				continue;
			}
			result[idx] = arr[idx++] + num;
			continue;
		}
		if ('A' <= arr[idx] && arr[idx] <= 'Z')
		{
			if (arr[idx] + num > 'Z')
			{
				result[idx] = arr[idx++] + num - 26;
				continue;
			}
			result[idx] = arr[idx++] + num;
			continue;
		}
		result[idx] = arr[idx++];
	}
	result[idx] = NULL;
	idx = 0;
	while (result[idx] != NULL)
	{
		if ('a' <= result[idx] && result[idx] <= 'z')
		{
			freqresult[arr[idx++] - 97] ++;
			alphanum++;
			continue;
		}
		if ('A' <= result[idx] && result[idx] <= 'Z')
		{
			freqresult[arr[idx++] - 65] ++;
			alphanum++;
			continue;
		}
		idx++;
	}
	for (int i = 0; i < 26; i++)
	{
		out += pow((freqresult[i]/alphanum), 2.0) / freq[i];
	}
	return out;
}