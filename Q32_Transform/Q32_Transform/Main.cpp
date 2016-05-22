/*************************************************************************
*																		 *
* Problem:																 *
* 숫자변환																 *
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
#include <stdlib.h>
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
	unsigned int pre, next;
	char Num[33];
	char Result[33];
	for (int i = 0; i < numTestCases; i++)
	{
		unsigned int result = 0;
		unsigned int temp = 0;
		int size = 0;
		int posNum = 0;
		in >> pre;
		in >> Num;
		in >> next;
		int idx = 0;

		while (Num[size] != NULL)
		{
			size++;
		}

		for (int j = size - 1; j >= 0; j--, idx++)
		{
			switch (Num[idx])
			{
			case 'a':
				posNum = 10;
				break;
			case 'b':
				posNum = 11;
				break;
			case 'c':
				posNum = 12;
				break;
			case 'd':
				posNum = 13;
				break;
			case 'e':
				posNum = 14;
				break;
			case 'f':
				posNum = 15;
				break;
			default:
				posNum = Num[idx] - '0';
				break;
			}

			temp += posNum*(int)pow(pre, j);
		}
		
		idx = 0;
		while (temp > 0)
		{
			switch (temp % next)
			{
			case 10:
				Result[idx++] = 'a';
				temp /= next;
				break;
			case 11:
				Result[idx++] = 'b';
				temp /= next;
				break;
			case 12:
				Result[idx++] = 'c';
				temp /= next;
				break;
			case 13:
				Result[idx++] = 'd';
				temp /= next;
				break;
			case 14:
				Result[idx++] = 'e';
				temp /= next;
				break;
			case 15:
				Result[idx++] = 'f';
				temp /= next;
				break;
			default:
				Result[idx++] = temp % next + '0';
				temp /= next;
				break;
			}
		}
		Result[idx++] = temp + '0';
		
		for (int j = idx -2; j >= 0; j--)
		{
			cout << Result[j];
		}

		cout << endl; /* print out */
	}
	in.close(); /* close input file */
	return 0;
}