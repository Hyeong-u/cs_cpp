/*************************************************************************
*																		 *
* Problem:																 *
* 라이프 게임															 *
*																		 *
*************************************************************************/
/*************************************************************************
*																		 *
* 국민대학교 전자정보통신대학 컴퓨터공학부 2 학년	2					 *
* 20153168 김형우														 *
*																		 *
*************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int vert[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int horz[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
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
		int rows;
		int cols;
		int generation;
		int live = 0;
		in >> rows >> cols >> generation;

		vector<vector<char> > arr(rows, vector<char>(cols, 'O'));
		
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				in >> arr[j][k];
			}
		}
		vector<vector<char> > result(arr);

		for (int n = 0; n < generation; n++)
		{
			
			vector<vector<char> > temp(result);
			int cell = 0;
			for (int m = 0; m < rows; m++)
			{
				for (int o = 0; o < cols; o++)
				{
					cell = 0;
					for (int k = 0; k < 8; k++)
					{
						if (m + vert[k] < 0 || o + horz[k] < 0 || m + vert[k] >= rows || o + horz[k] >= cols)
						{
							continue;
						}
						if (result.at(m + vert[k]).at(o + horz[k]) == 'O')
						{
							cell++;
						}
						/*
						try
						{
							if (result.at(m + vert[k]).at(o + horz[k]) == 'O')
							{
								cell++;
							}

						}
						catch (const out_of_range& oor)
						{
							continue;
						}
						*/
					}
					if (cell == 3)
					{
						temp[m][o] = 'O';
						continue;
					}
					if (cell <= 1 || cell >= 4)
					{
						temp[m][o] = 'X';
						continue;
					}
				}
			}
			result = temp;
		}


		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				if (result[j][k] == 'O')
				{
					live++;
				}
			}
		}
		cout << live << endl;
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				cout << result[j][k];
			}
			cout << endl;
		}
		/*
		for (vector<char> vec : result)
		{
			for (char ch : vec)
			{
				if (ch == 'O')
				{
					live++;
				}
			}
		}
		cout << live << endl;

		for (vector<char> vec : result)
		{
			for (char ch : vec)
			{
				printf("%c", ch);
			}
			cout << endl;
		}
		*/
		

	}
	in.close(); /* close input file */
	return 0;
}