/*************************************************************************
*																		 *
* Problem:																 *
* 홀수 마방진															 *
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
#include <cmath>
#include <vector>
using namespace std;

class magicSquare
{
private:
	int order;
	vector<vector<int> > msArray;
public:
	magicSquare(int n);
	void doMagic();
	void toString();
};

magicSquare::magicSquare(int n)
{
	order = n;
	msArray = vector<vector<int> >(n, vector<int>(n, 0));
}

void magicSquare::doMagic()
{
	int i = 0;
	int j = order / 2;
	int a;
	int b;
	msArray[i][j] = 1;
	for (int k = 2; k <= order * order; k++) {
		i--; // upward
		j++; // rightward
		a = i;
		b = j;
		if (i == -1) {
			i = order - 1;
		}
		if (j == order) {
			j = 0;
		}
		if (msArray[i][j] == 0) {
			msArray[i][j] = k;
		}
		else {
			i = a + 2;
			j = b - 1;
			msArray[i][j] = k;
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
		magicSquare m(order);
		m.doMagic();
		m.toString();
	}
	in.close(); /* close input file */
	return 0;
}