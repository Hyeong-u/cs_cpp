/*************************************************************************
*																		 *
* Problem:																 *
* 패리티 비트															 *
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
	
	in >> numTestCases; /* read the number of test cases */
	unsigned int Result, Count; // Result는 짝수패러티비트 결과값, Count는 1의 갯수, 음수가 나오면 안되기때문에 unsigned로 선언
	unsigned int num; // num은 입력받는 숫자
	unsigned int Add = pow(2, 31); // 1의 갯수가 홀수면 add를 더해주고 짝수면 그대로 둔다. 2의 31제곱
	for (int i = 0; i < numTestCases; i++)
	{
		in >> num;
		Result = num;
		Count = 0;
		while (true)
		{
			if (num >= 2)
			{
				if (num == 0 || num == 1)
				{
					break;
				}
				else if (num == 2)
				{
					Count;
					break;
				}
			}
			else if(num % 2 == 0)
			{
				Count++;
			}
			num /= 2;
		}
		if (Count % 2 == 1)
		{
			Result += Add;
		}
		cout << Result << endl; /* print out */
	}
	in.close(); /* close input file */
	return 0;
}