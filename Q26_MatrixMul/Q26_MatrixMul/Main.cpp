/*************************************************************************
*																		 *
* Problem:																 *
* 행렬곱셈																 *
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
#include <vector>
using namespace std;

struct Matrix
{
	int row;
	int col;
	vector<int> Mat;
};
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

	int temp;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		Matrix m1;  // A
		Matrix m2;  // B
		Matrix m3;  // AXB
		in >> m1.row;
		in >> m1.col;
		m2.row = m1.col;
		in >> m2.col;
		m3.row = m1.row;
		m3.col = m2.col;
		for (int j = 0; j < m1.row*m1.col; j++)
		{
			in >> temp;
			m1.Mat.push_back(temp);
		}
		for (int j = 0; j < m2.row*m2.col; j++)
		{
			in >> temp;
			m2.Mat.push_back(temp);
		}
		int l = 0; // index of m1.Mat
		for (int j = 0; j < m1.row; j++) // Matrix Multiplication
		{
			int *arr = new int[m2.col];
			for (int k = 0; k < m2.col; k++)
			{
				arr[k] = 0;
			}
			for (int k = 0; k < m1.col*m2.col; k++)
			{
				arr[k%m2.col] += m1.Mat[l] * m2.Mat[k];
				if (k%m2.col == m2.col - 1)
				{
					l++;
				}
			}
			for (int k = 0; k < m2.col; k++)
			{
				m3.Mat.push_back(arr[k]);
			}
			delete[] arr;
		}
		for (int j = 0; j < m1.row*m2.col; j++) // print out
		{
			cout << m3.Mat[j] << " ";
			if (j%m2.col == m2.col - 1)
			{
				cout << endl;
			}
		}
	}
	in.close(); /* close input file */
	return 0;
}
