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
	unsigned int Result, Count; // Result�� ¦���з�Ƽ��Ʈ �����, Count�� 1�� ����, ������ ������ �ȵǱ⶧���� unsigned�� ����
	unsigned int num; // num�� �Է¹޴� ����
	for (int i = 0; i < numTestCases; i++)
	{
		// 1�� ������ Ȧ���� 32��° ��Ʈ�� 1�� �ٲٰ� 1�� ������ ¦���� �״�� �д�.
		in >> num;
		bit = num; // ���� �����Ͽ� 2������ ��ȯ
		Result = 0;
		Count = 0;
		for () // 1�� ���� Ȯ��
		{

		}
		if (true) 
		{
			// 1�� ������ Ȧ���� �ֻ�����Ʈ�� 1�� �ٲ�
		}
		Result = bit.to_ulong(); // bit�� 10���� ������ ��ȯ
		cout << Result << endl; /* print out */
	}
	in.close(); /* close input file */
	return 0;
}