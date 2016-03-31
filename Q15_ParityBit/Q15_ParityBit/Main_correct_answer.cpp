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
	bitset<32> bit; // 2진수 bit 변수 선언 예)) bitset<4> bit 선언 후 bit = 4로 하면 bit는 0100, 접근은 bit[0], bit[1] 이런식으로 접근한다.
	unsigned int Result, Count; // Result는 짝수패러티비트 결과값, Count는 1의 갯수, 음수가 나오면 안되기때문에 unsigned로 선언
	unsigned int num; // num은 입력받는 숫자
	for (int i = 0; i < numTestCases; i++)
	{
		// 1의 갯수가 홀수면 32번째 비트를 1로 바꾸고 1의 갯수가 짝수면 그대로 둔다.
		in >> num;
		bit = num; // 정수 대입하여 2진수로 변환
		Result = 0;
		Count = 0;
		for (int j = 0; j < 31; j++) // bit[j]가 1인지 0인지 확인하고 
		{
			if (bit[j] != 1)
			{
				continue;
			}
			Count++;
		}
		if (Count % 2 != 0)
		{
			bit[31] = 1;
		}
		Result = bit.to_ulong(); // 
		cout << Result << endl; /* print out */
	}
	in.close(); /* close input file */
	return 0;
}