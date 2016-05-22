/*************************************************************************
*																		 *
* Problem:																 *
* üũ��																 *
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
#include <bitset> // bit�� �ٷ�� ���� ��Ŭ���
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
	bitset<32> bit; // 2���� bit ���� ���� ��)) bitset<4> bit ���� �� bit = 4�� �ϸ� bit�� 0100, ������ bit[0], bit[1] �̷������� �����Ѵ�.
	bitset<8> temp;
	bitset<8> BitArr[4];
	unsigned int num; // num�� �Է¹޴� ����
	for (int i = 0; i < numTestCases; i++)
	{
		int checksum = 0;
		int data = 0;
		int result = 0;
		int NumArr[4] = { 0, };
		in >> num;
		bit = num; // ���� �����Ͽ� 2������ ��ȯ
		

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