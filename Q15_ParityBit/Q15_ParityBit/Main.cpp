/*************************************************************************
*																		 *
* Problem:																 *
* �и�Ƽ ��Ʈ															 *
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
	
	in >> numTestCases; /* read the number of test cases */
	unsigned int Result, Count; // Result�� ¦���з�Ƽ��Ʈ �����, Count�� 1�� ����, ������ ������ �ȵǱ⶧���� unsigned�� ����
	unsigned int num; // num�� �Է¹޴� ����
	unsigned int Add = pow(2, 31); // 1�� ������ Ȧ���� add�� �����ְ� ¦���� �״�� �д�. 2�� 31����
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