/*************************************************************************
*																		 *
* Problem:																 *
* 모르스 부호															 *
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
#include <bitset>
#include <string.h>
using namespace std;
string search(string str);
string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
"---", ".--.", "--.-", ".-.", "...","-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
string alpha[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
"T", "U", "V", "W", "X", "Y", "Z"};
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
		string str;
		string temp;
		int idx = 0;
		int j = 0;
		in >> str;
		while (str[idx] != NULL)
		{
			if (str[idx] == '|')
			{
				temp.append(str, j, idx - j);
				cout << search(temp);
				temp = "";
				idx++;
				j = idx;
				continue;
			}
			if (str[idx] == '#')
			{
				temp.append(str, j, idx - j);
				cout << search(temp) << "_";
				temp = "";
				idx++;
				j = idx;
				continue;
			}
			idx++;
		}
		temp.append(str, j, idx);
		cout << search(temp) << endl;
	}
	in.close(); /* close input file */
	return 0;
}

string search(string str)
{
	int idx = 0;
	for (int i = 0; i < 26; i++)
	{
		if (str == morse[i])
		{
			idx = i;
			break;
		}
	}
	return alpha[idx];
}