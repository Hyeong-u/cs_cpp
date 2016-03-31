/*************************************************************************
*																		 *
* Problem:																 *
* 숫자맞추기게임														 *
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
#include <string>
#include <list>
#include <vector>
using namespace std;

vector<int> makeNum(int num);
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
	list<int> List;
	string temp;
	for (int i = 0; i < 10000; i++)
	{
		List.push_back(i);
	}
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		int loop;
		int strike;
		int ball;
		int num;
		int s_temp;
		int b_temp;
		
		in >> loop;
		list<int> S = List;
		for (int i = 0; i < loop; i++)
		{
			vector<int> Num;
			vector<int> origin;
			vector<int> temp;
			in >> num >> strike >> ball;
			Num = makeNum(num);
			origin = Num;
			for (int j = 0; j < 10000; j++)
			{
				temp = makeNum(i);
				s_temp = 0;
				b_temp = 0;
				for (vector<int>::size_type k = 0; k < origin.size;)
				{
					if (origin[k] == temp[k])
					{
						s_temp++;
						origin.erase(origin.begin() + k);
						temp.erase(temp.begin() + k);
					}
					else
					{
						k++;
					}
				}
				for (vector<int>::size_type k = 0; k < origin.size;)
				{
					for (vector<int>::size_type l = 0; l < temp.size;)
					{
						if (origin[k] == temp[l])
						{
							b_temp++;
						}
					}
					if (origin[i] == temp[i])
					{
						s_temp++;
						origin.erase(origin.begin() + k);
						temp.erase(temp.begin() + k);
					}
					else
					{
						k++;
					}
				}
				
			}
			
			
			

		}
		
		cout << result << endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}
vector<int> makeNum(int num)
{
	vector<int> temp;
	if (0 <= num && num < 10)
	{
		temp.push_back(0);
		temp.push_back(0);
		temp.push_back(0);
		temp.push_back(num);
	}
	else if (10 <= num && num < 100)
	{
		temp.push_back(0);
		temp.push_back(0);
		temp.push_back(num / 10);
		temp.push_back(num % 10);
	}
	else if (100 <= num && num < 1000)
	{
		temp.push_back(0);
		temp.push_back(num / 100);
		temp.push_back(num / 10);
		temp.push_back(num % 10);
	}
	else
	{
		temp.push_back(num / 1000);
		temp.push_back(num / 100);
		temp.push_back(num / 10);
		temp.push_back(num % 10);
	}
	return temp;
};