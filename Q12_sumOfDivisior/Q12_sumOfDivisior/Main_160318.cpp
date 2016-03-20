/*************************************************************************
*																		 *
* Problem:																 *
* �ﰢ���� ����															 *
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
	int sum = 0;
	int count = 0;
	int num = 0;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> num;
		for (int j = 1; j <= num; j++)
		{
			if (num % j == 0 && j != num)
			{
				sum += j;
				count ++;
			}
		}
		cout << count << " " << sum << endl; /* print out the sum of numbers */
		sum = 0;
		count = 0;
	}
	in.close(); /* close input file */
	return 0;
}