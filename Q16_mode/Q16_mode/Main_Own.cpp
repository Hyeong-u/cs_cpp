/*************************************************************************
*																		 *
* Problem:																 *
* 최빈값																 *
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
	
	int loop, num, idxMax, lastIdx, tmp, Count, countX;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> loop;
		int Value[200] = { 0, };
		int idx[200] = { 0, };
		int Result[200] = { 0, };

		for (int j = 0; j < loop; j++)
		{
			in >> num;
			for (int k = 0; k <= j; k++)
			{
				if (Value[k] == num)
				{
					idx[k] ++;
					break;
				}
				if (Value[k] == 0 && idx[k] == 0)
				{
					Value[k] = num;
					idx[k] = 1;
					lastIdx = k;
					break;
				}
			}
			
		}
		idxMax = idx[0];
		for (int j = 0; j < lastIdx; j++) // 버블소트
		{
			for (int k = 0; k < lastIdx - j; k++)
			{
				if (Value[k] > Value[k+1])
				{
					tmp = Value[k];
					Value[k] = Value[k + 1];
					Value[k + 1] = tmp;
					tmp = idx[k];
					idx[k] = idx[k + 1];
					idx[k + 1] = tmp;
				}
			}
			if (idxMax < idx[j+1])
			{
				idxMax = idx[j + 1];
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

		cout <<  endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}