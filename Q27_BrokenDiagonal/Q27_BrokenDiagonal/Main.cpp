/*************************************************************************
*																		 *
* Problem:																 *
* 절단대각선															 *
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
		//2차원 배열 할당
		int **mat;
		mat = new int*[Size];
		for (int j = 0; j < Size; j++) 
		{
			mat[j] = new int[Size];
		}
		//할당 끝

		//행렬 값 채우기
		for (int j = 0; j < Size; j++)
		{
			for (int k = 0; k < Size; k++)
			{
				in >> mat[j][k];
			}
		}

		// 오른 절단대각선
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

		// 왼 절단대각선
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

		sort(Sum.begin(), Sum.end(), Comp); // 내림차순 정렬

		cout << Sum[0] << endl; /* print out*/
		Sum.clear();
		//2차원 배열 해제
		for (int j = 0; j < Size; j++)
		{
			delete[] mat[j];
		}
		delete[] mat;
		//해제 끝
	}
	in.close(); /* close input file */
	return 0;
}

bool Comp(const int &a, const int &b)
{
	return a > b;
}