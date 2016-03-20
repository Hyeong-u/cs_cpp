/*************************************************************************
*																		 *
* Problem:																 *
* 삼각형의 면적															 *
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
using namespace std;

void Calc(long long int result[3]);

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
	
	int num;
	long long int result[3] = { 0, }; // result[0] == num, result[1] == number of divisiors, result[2] == sum of divisiors
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> num;
		result[0] = num;
		Calc(result);
		
		cout << result[1] << " " << result[2] << endl; /* print out the sum of numbers */
	}
	in.close(); /* close input file */
	return 0;
}
void Calc(long long int result[3]) {
	result[1] = 1;
	result[2] = 1;
	int j = 2;
	long long int num = result[0];
	long long int limit = num;
	while (j != limit)
	{
		if (num % j == 0)
		{
			limit = num / j;
			result[2] += j;
			result[2]+= limit;
			result[1] += 2;
			j++;
		}
		else
		{
			j++;
		}
	}
};