/*************************************************************************
*																		 *
* Problem:																 *
* 소수																	 *
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