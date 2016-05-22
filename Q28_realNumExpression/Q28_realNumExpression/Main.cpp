/*************************************************************************
*																		 *
* Problem:																 *
* 실수표현																 *
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
#include <string>
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
	string temp;
	for (int i = 0; i < numTestCases; i++)
	{
		in >> temp;
		char *str = new char[temp.size() + 1];
		for (int j = 0; j < temp.length(); j++)
		{
			if ('0' <= str[j])
			{

			}
		}

		cout << result << endl; /* print out*/
		delete[] str;
	}
	in.close(); /* close input file */
	return 0;
}