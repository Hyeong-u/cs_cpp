/*************************************************************************
*																		 *
* Problem:																 *
* ���ܴ밢��															 *
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
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(const int &a, const int &b);

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
		int Size;
		int temp;
		int row;
		int col;
		vector<int> Sum;
		in >> Size;
		//2���� �迭 �Ҵ�
		int **mat;
		mat = new int*[Size];
		for (int j = 0; j < Size; j++) 
		{
			mat[j] = new int[Size];
		}
		//�Ҵ� ��

		//��� �� ä���
		for (int j = 0; j < Size; j++)
		{
			for (int k = 0; k < Size; k++)
			{
				in >> mat[j][k];
			}
		}

		// ���� ���ܴ밢��
		for (int j = 0; j < Size; j++)
		{
			temp = 0;
			row = 0;
			col = j;
			for (int k = 0; k < Size; k++)
			{

				temp += mat[row++][col++ % Size];
			}
			Sum.push_back(temp);
		}

		// �� ���ܴ밢��
		for (int j = 0; j < Size; j++)
		{
			temp = 0;
			row = 0;
			col = j+ Size - 1;
			for (int k = 0; k < Size; k++)
			{

				temp += mat[row++][col-- % Size];
			}
			Sum.push_back(temp);
		}

		sort(Sum.begin(), Sum.end(), Comp); // �������� ����

		cout << Sum[0] << endl; /* print out*/
		Sum.clear();
		//2���� �迭 ����
		for (int j = 0; j < Size; j++)
		{
			delete[] mat[j];
		}
		delete[] mat;
		//���� ��
	}
	in.close(); /* close input file */
	return 0;
}

bool Comp(const int &a, const int &b)
{
	return a > b;
}