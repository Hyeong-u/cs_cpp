/*************************************************************************
*																		 *
* Problem:																 *
* ����� �� ���ϱ�														 *
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
	
	int count;
	long long int sum, num;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> num;
		count = 0;
		sum = 0;
		for (int j = 1; j <= sqrt(num); j++)
		{
			if (j == 1)
			{
				sum += j;
				count ++;
				continue;
			}
			else if(num%j == 0)
			{
				sum += j;
				sum += num / j;
				count += 2;
			}
		}
		cout << count << " " << sum << endl; /* print out the sum of numbers */
	}
	in.close(); /* close input file */
	return 0;
}