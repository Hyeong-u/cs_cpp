/*************************************************************************
*																		 *
* Problem:																 *
* �ֺ�																 *
*																		 *
*************************************************************************/
/*************************************************************************
*																		 *
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 2 �г�						 *
* 20153168 ������														 *
*																		 *
*************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
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
		int loop = 0;
		int num = 0;
		int idxMax = 0; 
		int lastIdx = 0;
		int temp = NULL; 
		int Count = 0;
		int countX = 0;
		int start = 0;
		in >> loop;
		int Value[200] = { 0, };
		int idx[200] = { 0, };
		int Result[200] = { 0, };

		for (int j = 0; j < loop; j++) // �迭 ����
		{
			in >> num;
			Value[j] = num;
		}

		for (int j = 0; j < loop; j++)//�������� ����
		{
			for (int k = 0; k < loop - 1; k++)
			{
				if (Value[k]>Value[k + 1])
				{
					temp = Value[k];
					Value[k] = Value[k + 1];
					Value[k + 1] = temp;
				}
			}
		}
		for (int j = 0; j < loop; j++)//�������� ����
		{
			for (int k = start; k < loop + 1; k++)
			{
				if (Result[]>Value[k + 1])
				{
					temp = Value[k];
					Value[k] = Value[k + 1];
					Value[k + 1] = temp;
				}
			}
		}

		Count = 0;
		for (int j = 0; j <= lastIdx; j++)
		{
			if (idxMax == idx[j])
			{
				Count++;
			}
		}
		cout << Count << " " << idxMax << " ";

		countX = 1;
		for (int j = 0; j <= lastIdx; j++)
		{
			if (idxMax == idx[j] && Count == countX)
			{
				cout << Value[j];
			}
			else if (idxMax == idx[j])
			{
				cout << Value[j] << " ";
				countX++;
			}
		}

		cout << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}