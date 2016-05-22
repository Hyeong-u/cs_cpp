/*************************************************************************
*																		 *
* Problem:																 *
* 시이저 암호기법														 *
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
	};
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int num;
		int alphanum; // 알바벳 갯수
		in >> num;
		char arr[200];
		char result[200];
		in >> arr;
		int idx = 0;
		while (arr[idx] != NULL) {
			if ('a' <= arr[idx]  && arr[idx] <= 'z')
			{
				if (arr[idx] + num > 'z')
				{
					result[idx] = arr[idx++] + num - 26;
					continue;
				}
				result[idx] = arr[idx++] + num;
				continue;
			}
			if ('A' <= arr[idx]   && arr[idx] <= 'Z')
			{
				if (arr[idx] + num > 'Z')
				{
					result[idx] = arr[idx++] + num - 26;
					continue;
				}
				result[idx] = arr[idx++] + num;
				continue;
			}
			result[idx] = arr[idx++];
		}
		result[idx] = NULL;

		idx = 0;
		while (result[idx] != NULL)
		{
			cout << result[idx++];
		}
		cout << endl;

		//cout << result << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}