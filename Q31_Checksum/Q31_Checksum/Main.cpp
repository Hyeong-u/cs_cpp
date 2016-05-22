/*************************************************************************
*																		 *
* Problem:																 *
* 체크썸																 *
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
	bitset<8> temp;
	bitset<8> BitArr[4];
	unsigned int num; // num은 입력받는 숫자
	for (int i = 0; i < numTestCases; i++)
	{
		int checksum = 0;
		int data = 0;
		int result = 0;
		int NumArr[4] = { 0, };
		in >> num;
		bit = num; // 정수 대입하여 2진수로 변환
		

		for (int j = 0; j < 4; j++)
		{
			for (int k = j*8, l = 0; k < (j+1)*8; k++, l++)
			{
				BitArr[j][l] = bit[k];
			}
		}

		for (int j = 0; j < 4; j++)
		{
			temp = BitArr[j];
			NumArr[j] = temp.to_ulong();
		}

		checksum = NumArr[0];
		for (int j = 1; j < 4; j++)
		{
			data += NumArr[j];
		}

		while (data >= 256)
		{
			data -= 256;
		}

		if (255 - data == checksum)
		{
			result = 1;
		}
		cout << result << endl; /* print out */
	}
	in.close(); /* close input file */
	return 0;
}