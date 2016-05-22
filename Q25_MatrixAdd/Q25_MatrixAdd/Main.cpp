/*************************************************************************
*																		 *
* Problem:																 *
* 행렬 덧셈																 *
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
		vector<int> matA;
		vector<int> matB;
		vector<int> result;
		int row;
		int col;
		int Size;
		int temp;
		in >> row;
		in >> col;
		Size = row*col;
		for (int j = 0; j < Size; j++)
		{
			in >> temp;
			matA.push_back(temp);
		}
		for (int j = 0; j < Size; j++)
		{
			in >> temp;
			matB.push_back(temp);
		}
		for (int j = 0; j < Size; j++)
		{
			temp = matA[j] + matB[j];
			result.push_back(temp);
		}
		int k = 0;
		for (int j = 0; j < row; j++)
		{
			for (; k < col*(j+1); k++)
			{
				cout << result[k] << " ";
			}
			cout << endl;
		}

		//cout << result << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}