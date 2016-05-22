/*************************************************************************
*																		 *
* Problem:																 *
* 입체사목게임															 *
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

int rows = 6;
int cols = 7;

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
		
		int chips;
		int result = 0;
		int row[7] = { 5, 5, 5, 5, 5, 5, 5 };
		int choice = 0;
		in >> chips;

		vector<vector<int> > arr(rows, vector<int>(cols, 0));
		for (int j = 0; j < chips; j++)
		{
			in >> choice;
			if (j % 2 == 0)
			{
				arr[row[choice - 1]][choice - 1] = 1;
				
				int Count = 0;
				int prev = -1;
				int col = choice - 1;
				int leftBot[2] = { row[choice - 1], choice - 1 };
				for (int i = 0; i < 5; i++)
				{
					if (leftBot[0] == 0 || leftBot[1] == 0)
					{
						break;
					}
					leftBot[0]--;
					leftBot[1]--;
				}
				int rightBot[2] = { row[choice - 1], choice - 1 };
				for (int i = 0; i < 5; i++)
				{
					if (rightBot[0] == 0 || rightBot[1] == 6)
					{
						break;
					}
					rightBot[0]--;
					rightBot[1]++;
				}
				Count = 1;
				prev = -1;
				for (int i = 0; i < rows; i++)
				{
					if (arr[i][choice - 1] == prev)
					{
						Count++;
						if (Count == 4 && arr[i][choice - 1] != 0)
						{
							result = arr[i][choice - 1];
						}
						prev = arr[i][choice - 1];
						continue;
					}
					Count = 1;
					prev = arr[i][choice - 1];
				}

				Count = 1;
				prev = -1;
				for (int j = 0; j < cols; j++)
				{
					if (arr[row[choice - 1]][j] == prev)
					{
						Count++;
						if (Count == 4 && arr[row[choice - 1]][j] != 0)
						{
							result = arr[row[choice - 1]][j];
						}
						prev = arr[row[choice - 1]][j];
						continue;
					}
					Count = 1;
					prev = arr[row[choice - 1]][j];
				}

				Count = 1;
				prev = -1;
				for (int i = 0; i < 6; i++)
				{
					if (leftBot[0] + i >= rows || leftBot[1] + i >= cols)
					{
						break;
					}
					if (arr[leftBot[0] + i][leftBot[1] + i] == prev)
					{
						Count++;
						if (Count == 4 && arr[leftBot[0] + i][leftBot[1] + i] != 0)
						{
							result = arr[leftBot[0] + i][leftBot[1] + i];
						}
						prev = arr[leftBot[0] + i][leftBot[1] + i];
						continue;
					}
					Count = 1;
					prev = arr[leftBot[0] + i][leftBot[1] + i];
				}

				for (int i = 0; i < 6; i++)
				{
					if (rightBot[0] + i >= rows || rightBot[1] - i < 0)
					{
						break;
					}
					if (arr[rightBot[0] + i][rightBot[1] - i] == prev)
					{
						Count++;
						if (Count == 4 && arr[rightBot[0] + i][rightBot[1] - i] != 0)
						{
							result = arr[rightBot[0] + i][rightBot[1] - i];
						}
						prev = arr[rightBot[0] + i][rightBot[1] - i];
						continue;
					}
					Count = 1;
					prev = arr[rightBot[0] + i][rightBot[1] - i];
				}

				if (result != 0)
				{
					break;
				}
				row[choice - 1]--;
				continue;
			}
			arr[row[choice - 1]][choice - 1] = 2;
			
			int Count = 0;
			int prev = -1;
			int col = choice - 1;
			int leftBot[2] = { row[choice - 1], choice - 1 };
			for (int i = 0; i < 5; i++)
			{
				if (leftBot[0] == 0 || leftBot[1] == 0)
				{
					break;
				}
				leftBot[0]--;
				leftBot[1]--;
			}
			int rightBot[2] = { row[choice - 1], choice - 1 };
			for (int i = 0; i < 5; i++)
			{
				if (rightBot[0] == 0 || rightBot[1] == 6)
				{
					break;
				}
				rightBot[0]--;
				rightBot[1]++;
			}
			Count = 1;
			prev = -1;
			for (int i = 0; i < rows; i++)
			{
				if (arr[i][choice - 1] == prev)
				{
					Count++;
					if (Count == 4 && arr[i][choice - 1] != 0)
					{
						result = arr[i][choice - 1];
					}
					prev = arr[i][choice - 1];
					continue;
				}
				Count = 1;
				prev = arr[i][choice - 1];
			}

			Count = 1;
			prev = -1;
			for (int j = 0; j < cols; j++)
			{
				if (arr[row[choice - 1]][j] == prev)
				{
					Count++;
					if (Count == 4 && arr[row[choice - 1]][j] != 0)
					{
						result = arr[row[choice - 1]][j];
					}
					prev = arr[row[choice - 1]][j];
					continue;
				}
				Count = 1;
				prev = arr[row[choice - 1]][j];
			}

			Count = 1;
			prev = -1;
			for (int i = 0; i < 6; i++)
			{
				if (leftBot[0] + i >= rows || leftBot[1] + i >= cols)
				{
					break;
				}
				if (arr[leftBot[0] + i][leftBot[1] + i] == prev)
				{
					Count++;
					if (Count == 4 && arr[leftBot[0] + i][leftBot[1] + i] != 0)
					{
						result = arr[leftBot[0] + i][leftBot[1] + i];
					}
					prev = arr[leftBot[0] + i][leftBot[1] + i];
					continue;
				}
				Count = 1;
				prev = arr[leftBot[0] + i][leftBot[1] + i];
			}

			for (int i = 0; i < 6; i++)
			{
				if (rightBot[0] + i >= rows || rightBot[1] - i < 0)
				{
					break;
				}
				if (arr[rightBot[0] + i][rightBot[1] - i] == prev)
				{
					Count++;
					if (Count == 4 && arr[rightBot[0] + i][rightBot[1] - i] != 0)
					{
						result = arr[rightBot[0] + i][rightBot[1] - i];
					}
					prev = arr[rightBot[0] + i][rightBot[1] - i];
					continue;
				}
				Count = 1;
				prev = arr[rightBot[0] + i][rightBot[1] - i];
			}

			if (result != 0)
			{
				break;
			}
			row[choice - 1]--;
		}

		cout << result << endl;
	}
	in.close(); /* close input file */
	return 0;
}

/*
int determine(vector<vector<int> > &arr, int row, int col)
{
	int Count = 0;
	int prev = -1;
	int leftBot[2] = { row, col };
	for (int i = 0; i < 5; i++)
	{
		if (leftBot[0] == 0 || leftBot[1] == 0)
		{
			break;
		}
		leftBot[0]--;
		leftBot[1]--;
	}
	int rightBot[2] = { row, col };
	for (int i = 0; i < 5; i++)
	{
		if (rightBot[0] == 0 || rightBot[1] == 6)
		{
			break;
		}
		rightBot[0]--;
		rightBot[1]++;
	}
	Count = 1;
	prev = -1;
	for (int i = 0; i < rows; i++)
	{
		if (arr[i][col] == prev)
		{
			Count++;
			if (Count == 4 && arr[i][col] != 0)
			{
				return arr[i][col];
			}
			prev = arr[i][col];
			continue;
		}
		Count = 1;
		prev = arr[i][col];
	}

	Count = 1;
	prev = -1;
	for (int j = 0; j < cols; j++)
	{
		if (arr[row][j] == prev)
		{
			Count++;
			if (Count == 4 && arr[row][j] != 0)
			{
				return arr[row][j];
			}
			prev = arr[row][j];
			continue;
		}
		Count = 1;
		prev = arr[row][j];
	}

	Count = 1;
	prev = -1;
	for (int i = 0; i < 6; i++)
	{
		if (leftBot[0] + i >= rows || leftBot[1] + i >= cols)
		{
			break;
		}
		if (arr[leftBot[0]+i][leftBot[1] + i] == prev)
		{
			Count++;
			if (Count == 4 && arr[leftBot[0] + i][leftBot[1] + i] != 0)
			{
				return arr[leftBot[0] + i][leftBot[1] + i];
			}
			prev = arr[leftBot[0] + i][leftBot[1] + i];
			continue;
		}
		Count = 1;
		prev = arr[leftBot[0] + i][leftBot[1] + i];
	}

	for (int i = 0; i < 6; i++)
	{
		if (rightBot[0] + i >= rows || rightBot[1] - i < 0)
		{
			break;
		}
		if (arr[rightBot[0] + i][rightBot[1] - i] == prev)
		{
			Count++;
			if (Count == 4 && arr[rightBot[0] + i][rightBot[1] - i] != 0)
			{
				return arr[rightBot[0] + i][rightBot[1] - i];
			}
			prev = arr[rightBot[0] + i][rightBot[1] - i];
			continue;
		}
		Count = 1;
		prev = arr[rightBot[0] + i][rightBot[1] - i];
	}

	return 0;
}
*/