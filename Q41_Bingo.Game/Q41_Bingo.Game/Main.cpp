/*************************************************************************
*																		 *
* Problem:																 *
* 빙고 게임																 *
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

class bingoGame
{
private:
	vector<vector<int> > bingo;
	vector<vector<int> > mark;
	int Count;
public:
	bingoGame();
	void setValue(int row, int col, int value);
	int call(int num);
	void toString();
};

bingoGame::bingoGame()
{
	bingo = vector<vector<int> >(5, vector<int>(5, 0));
	mark = vector<vector<int> >(5, vector<int>(5, 0));
	mark[2][2] = 1;
	Count = 0;
}

void bingoGame::setValue(int row, int col, int value)
{
	bingo[row][col] = value;
}

int bingoGame::call(int num)
{
	int row;
	int col;
	int prev;
	int current;
	int flag = 0;
	Count++;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (num == bingo[i][j])
			{
				mark[i][j] = 1;
				row = i;
				col = j;
				flag = 1;
				i = 5;
				break;
			}
		}
	}
	if (flag == 0)
	{
		return 0;
	}

	if (mark[0][col] == 1) // col check
	{
		flag = 0;
		prev = 1;
		current = 1;
		for (int i = 0; i < 5; i++)
		{
			prev = current;
			current = mark[i][col];
			if (prev != current)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return Count;
		}
	}
	
	if (mark[row][0] == 1) // row check
	{
		flag = 0;
		prev = 1;
		current = 1;
		for (int j = 0; j < 5; j++)
		{
			prev = current;
			current = mark[row][j];
			if (prev != current)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return Count;
		}
	}
	
	if (mark[0][0] == 1)  // right diagonal, vertex check
	{
		if (mark[0][0] == 1 && mark[0][4] == 1 && mark[4][0] == 1 && mark[4][4] == 1) // vertex check
		{
			return Count;
		}
		flag = 0;
		prev = 1;
		current = 1;
		for (int i = 0; i < 5; i++)
		{
			prev = current;
			current = mark[i][i];
			if (prev != current)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return Count;
		}
	}
	
	if (mark[0][4] == 1) // left diagonal check
	{
		flag = 0;
		prev = 1;
		current = 1;
		for (int i = 0; i < 5; i++)
		{
			prev = current;
			current = mark[i][4 - i];
			if (prev != current)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return Count;
		}
	}

	return 0;
}

void bingoGame::toString()
{
	cout << "Count = " << Count << endl;;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << mark[i][j] << " ";
		}
		cout << endl;
	}
}


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
		int num;
		int result = 0;
		char numbers[256];
		bingoGame bingo;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				in >> num;
				bingo.setValue(j, k, num);
			}
		}

		for (int j = 0; j < 75; j++)
		{
			in >> num;
			result = bingo.call(num);
			//cout << "num = " << num << ", ";
			//bingo.toString();
			if (result != 0)
			{
				cout << result << endl; /* print out*/
				in.getline(numbers, 256);
				break;
			}
		}
	}
	in.close(); /* close input file */
	return 0;
}