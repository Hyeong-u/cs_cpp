/*************************************************************************
*																		 *
* Problem:																 *
* 짝수 마방진															 *
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

class magicSquare4k
{
private:
	int order;
	vector<vector<int> > msArray;
public:
	magicSquare4k(int order);
	void doMagic();
	void toString();
};

magicSquare4k::magicSquare4k(int order)
{
	this->order = order;
	msArray = vector<vector<int> >(order, vector<int>(order, 0));
	int num = 1;
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			msArray[i][j] = num++;
		}
	}
}

void magicSquare4k::doMagic()
{
	int square = order*order;
	for (int i = 0; i < order; i++)
	{
		if (i % 4 == 0 || i % 4 == 3)
		{
			for (int j = 0; j < order; j++)
			{
				if (j % 4 == 0 || j % 4 == 3)
				{
					msArray[i][j] = square + 1 - msArray[i][j];
				}
			}
			continue;
		}
		for (int j = 0; j < order; j++)
		{
			if (j % 4 == 1 || j % 4 == 2)
			{
				msArray[i][j] = square + 1 - msArray[i][j];
			}
		}
	}
}

void magicSquare4k::toString()
{
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			cout << msArray[i][j] << " ";
		}
		cout << endl;
	}
}

class magicSquare
{
private:
	int order;
	int odd;
	int k;
	vector<vector<int> > msArray;
	vector<vector<int> > oddArray;
	vector<vector<char> > luxArray;
	void doMagicOdd();
public:
	magicSquare(int order);
	void doMagic();
	void toString();
};

magicSquare::magicSquare(int order)
{
	this->order = order;
	msArray = vector<vector<int> >(order, vector<int>(order, 0));
	odd = order / 2;
	k = odd / 2;
	oddArray = vector<vector<int> >(odd, vector<int>(odd, 0));
	doMagicOdd();
	luxArray = vector<vector<char> >(odd, vector<char>(odd, 'i'));
	for (int i = 0; i < odd; i++)
	{
		if (i < k)
		{
			for (int j = 0; j < odd; j++)
			{
				luxArray[i][j] = 'L';
			}
			continue;
		}
		if (i == k)
		{
			for (int j = 0; j < odd; j++)
			{
				if (j == k)
				{
					luxArray[i][j] = 'U';
					continue;
				}
				luxArray[i][j] = 'L';
			}
			continue;
		}
		if (i == k + 1)
		{
			for (int j = 0; j < odd; j++)
			{
				if (j == k)
				{
					luxArray[i][j] = 'L';
					continue;
				}
				luxArray[i][j] = 'U';
			}
			continue;
		}
		for (int j = 0; j < odd; j++)
		{
			luxArray[i][j] = 'X';
		}
	}
}

void magicSquare::doMagic()
{
	int num = 0;
	for (int i = 0; i < odd; i++)
	{
		for (int j = 0; j < odd; j++)
		{
			num = oddArray[i][j] * 4 - 3;
			if (luxArray[i][j] == 'L')
			{
				
				msArray[i * 2][j * 2 + 1] = num;
				msArray[i * 2 + 1][j * 2] = num + 1;
				msArray[i * 2 + 1][j * 2 + 1] = num + 2;
				msArray[i * 2][j * 2] = num + 3;
				continue;
			}
			if (luxArray[i][j] == 'U')
			{
				msArray[i * 2][j * 2] = num;
				msArray[i * 2 + 1][j * 2] = num + 1;
				msArray[i * 2 + 1][j * 2 + 1] = num + 2;
				msArray[i * 2][j * 2 + 1] = num + 3;
				continue;
			}
			msArray[i * 2][j * 2] = num;
			msArray[i * 2 + 1][j * 2 + 1] = num + 1;
			msArray[i * 2 + 1][j * 2] = num + 2;
			msArray[i * 2][j * 2 + 1] = num + 3;
		}
	}
}

void magicSquare::doMagicOdd()
{
	int i = 0;
	int j = odd / 2;
	int a;
	int b;
	oddArray[i][j] = 1;
	for (int k = 2; k <= odd * odd; k++) {
		i--; // upward
		j++; // rightward
		a = i;
		b = j;
		if (i == -1) {
			i = odd - 1;
		}
		if (j == odd) {
			j = 0;
		}
		if (oddArray[i][j] == 0) {
			oddArray[i][j] = k;
		}
		else {
			i = a + 2;
			j = b - 1;
			oddArray[i][j] = k;
		}
	}
}

void magicSquare::toString()
{
	for (int i = 0; i<order; i++) {
		for (int j = 0; j<order; j++) {
			cout << msArray[i][j] << " ";
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
		int order;
		in >> order;
		if (order % 4 == 0)
		{
			magicSquare4k m(order);
			m.doMagic();
			m.toString();
			continue;
		}
		magicSquare m(order);
		m.doMagic();
		m.toString();
	}
	in.close(); /* close input file */
	return 0;
}