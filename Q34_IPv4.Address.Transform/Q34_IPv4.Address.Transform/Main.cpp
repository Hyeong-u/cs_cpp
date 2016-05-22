/*************************************************************************
*																		 *
* Problem:																 *
* IPv4 주소변환 														 *
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
#include <bitset>
#include <string.h>
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
	for (int i = 0; i < numTestCases; i++)
	{
		int Case = 0;
		in >> Case;
		string str1;
		string temp;
		bitset <8> bit8;
		bitset<32> bit32;
		int dot = 3;
		if (Case == 1)
		{
			int idx = 0;
			int j = 0;
			int tempNum;
			unsigned int resNum;
			in >> str1;
			while (str1[idx] != NULL) {
				if (str1[idx] == '.')
				{
					temp.append(str1, j, idx);
					tempNum = atoi(temp.c_str());
					temp = "";
					bit8 = tempNum;
					for (int k = dot*8, l = 0; k < (dot+1)*8; k++, l++)
					{
						bit32[k] = bit8[l];
					}
					idx++;
					j = idx;
					dot--;
				}
				idx++;
			}
			temp.append(str1, j, idx);
			tempNum = atoi(temp.c_str());
			temp = "";
			bit8 = tempNum;
			for (int k = dot * 8, l = 0; k < (dot + 1) * 8; k++, l++)
			{
				bit32[k] = bit8[l];
			}
			resNum = bit32.to_ulong();
			cout << resNum << endl;
		}

		if (Case == 2)
		{
			unsigned int num;
			int arr[4];
			int idx = 0;
			in >> num;
			bit32 = num;
			for (int j = 0; j < 4; j++)
			{
				for (int k = dot * 8, l = 0; k < (dot + 1) * 8; k++, l++)
				{
					bit8[l] = bit32[k];	
				}
				dot--;
				arr[idx++] = bit8.to_ulong();
			}
			for (int j = 0; j < 3; j++)
			{
				cout << arr[j] << ".";
			}
			cout << arr[3] << endl;
		}
	}
	in.close(); /* close input file */
	return 0;
}