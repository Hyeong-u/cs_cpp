/*************************************************************************
*																		 *
* Problem:																 *
* 집합 연산																 *
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
#include <bitset> // bit를 다루기 위해 인클루드
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
		bitset<132> bit1;
		bitset<132> bit2;
		bitset<132> Or;
		bitset<132> And;
		bitset<132> Sub;
		int loop;
		int temp;
		int Count;
		in >> loop;
		for (int j = 0; j < loop; j++)
		{
			in >> temp;
			if (bit1[temp] == 0)
			{
				bit1[temp] = 1;
			}
		}
		in >> loop;
		for (int j = 0; j < loop; j++)
		{
			in >> temp;
			if (bit2[temp] == 0)
			{
				bit2[temp] = 1;
			}
		}
		Or = bit1 | bit2;
		And = bit1 & bit2;
		Sub = bit1;
		for (int j = 0; j < 132; j++)
		{
			if (bit1[j] != bit2[j])
			{
				continue;
			}
			Sub[j] = 0;
		}

		Count = And.count();
		cout << Count;
		for (int j = 0; j < 132; j++)
		{
			if (And[j] == 0)
			{
				continue;
			}
			cout << " " << j;
		}
		cout << endl;

		Count = Or.count();
		cout << Count;
		for (int j = 0; j < 132; j++)
		{
			if (Or[j] == 0)
			{
				continue;
			}
			cout << " " << j;
		}
		cout << endl;

		Count = Sub.count();
		cout << Count;
		for (int j = 0; j < 132; j++)
		{
			if (Sub[j] == 0)
			{
				continue;
			}
			cout << " " << j;
		}
		cout << endl;
	}
	in.close(); /* close input file */
	return 0;
}