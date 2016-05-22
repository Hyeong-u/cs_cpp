/*************************************************************************
 *																		 *
 * Problem:																 *
 * 해밍 거리															 *
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
#include <bitset>

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
		bitset<32> bit1;
		bitset<32> bit2;
		unsigned int num1 = 0;
		unsigned int num2 = 0;
		int hWeight1 = 0;
		int hWeight2 = 0;
		int hDistance = 0;
		in >> num1 >> num2;
		bit1 = num1;
		bit2 = num2;
		for (int j = 0; j < 32; j++)
		{
			if (bit1[j] == 1)
			{
				hWeight1++;
			}
			if (bit2[j] == 1)
			{
				hWeight2++;
			}
			if (bit1[j] != bit2[j])
			{
				hDistance++;
			}
		}
		cout << hWeight1 << " " << hWeight2 << " " << hDistance << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}