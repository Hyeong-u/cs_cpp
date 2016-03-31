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

	
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int loop, num, idxMax, lastIdx, temp, Count, countX;
		in >> loop;
		int Value[200] = { 0, };
		int idx[200] = { 0, };
		for (int j = 0; j < loop; j++) // 배열 생성
		{
			in >> num;
			Value[j] = num;
		}

		for (int j = 0; j < loop; j++)//오름차순 정렬
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
		for (int j = 0; j < loop; j++)//빈도 배열
		{
			a = arr[c];
			b = 0;
			arr2[j] = a;
			for (int k = c; k < loop + 1; k++)
			{
				if (arr[k] == a)
				{
					b++;
					if (b == loop)
					{
						break;
					}
				}
				else
				{
					d++;
					c = k;
					break;
				}
			}
			arr3[j] = b;
			arr4[j] = b;
			if (b == loop)
			{
				break;
			}
		}

		

		cout << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}