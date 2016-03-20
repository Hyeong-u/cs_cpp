/*************************************************************************
*																		 *
* Problem:																 *
* �Ҽ�																	 *
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
	int result, num;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> num;
		result = 1;
		for (int j = 2; j <= sqrt(num) + 1; j++)
		{
			if (num == 2)
			{
				break;
			}
			else if (num % j == 0)
			{
				result = 0;
				break;
			}
		}
		cout << result << endl; /* print out the sum of numbers */
	}
	in.close(); /* close input file */
	return 0;
}