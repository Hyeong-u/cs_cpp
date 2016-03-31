/*************************************************************************
*																		 *
* Problem:																 *
* 이동평균																 *
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
	int k;  // 이동평균 기준
	int n;  // 입력되는 자연수 개수
	int temp; // 임시저장
	int num; // 만들어지는 수의 갯수
	for (int i = 0; i < numTestCases; i++)
	{
		vector<int> Vec;
		int idx_s;
		int idx_e;
		
		in >> n;
		for (int j = 0; j < n; j++)
		{
			in >> temp;
			Vec.push_back(temp);
		}
		temp = 0;
		in >> k;
		num = n - k + 1;
		idx_s = 0;
		idx_e = k;
		
		cout << num << ' ';
		for (int j = 0; j < num; j++)
		{
			for (; idx_s != idx_e; idx_s++)
			{
				temp += Vec[idx_s];
			}
			idx_s += (1 - k);
			idx_e++;
			temp /= k;
			cout << temp << ' ';
			temp = 0;
		}
		cout << endl;
		Vec.clear();
	}
	in.close(); /* close input file */
	return 0;
}