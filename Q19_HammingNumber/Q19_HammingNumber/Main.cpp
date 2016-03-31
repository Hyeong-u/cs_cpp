/*************************************************************************
*																		 *
* Problem:																 *
* 해밍수																 *
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
#include <vector>
#include <algorithm>
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
	long long unsigned int temp;
	long long unsigned int two, three, five;
	long long unsigned int Max = 400000000;
	vector<long long unsigned int> Vector;
	for (int i = 0; i < 15;  i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 32; k++)
			{
				two = pow(2, k);
				three = pow(3, j);
				five = pow(5, i);
				temp = two * three * five;
				if (temp > 0 && temp < Max)
				{
					Vector.push_back(temp);
				}
				
			}
		}
	}
	sort(Vector.begin(), Vector.end());
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int idx;
		in >> idx;
		cout << Vector[idx-1] << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}