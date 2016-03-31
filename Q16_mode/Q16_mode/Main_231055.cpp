/*************************************************************************
*																		 *
* Problem:																 *
* 최빈값																 *
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
	
	int loop, num, idxMax, lastIdx, tmp, Count;
	in >> numTestCases; /* read the number of test cases */
	for (int i = 0; i < numTestCases; i++)
	{
		in >> loop;
		int arr1[200] = { 0, }; // 초기 배열, 오름차순 정렬된 배열
		int arr2[200] = { 0, }; // 최종배열
		int arr3[200] = { 0, }; // 결과배열
		int idx[200] = { 0, };

		for (int j = 0; j < loop; j++)
		{
			in >> num;
			arr1[j] = num;
			
		}
		
		for (int j = 0; j < loop - 1; j++) // 버블소트, 오름차순 정렬
		{
			for (int k = 0; k < loop - 1 - j; k++)
			{
				if (arr1[k] > arr1[k+1])
				{
					tmp = arr1[k];
					arr1[k] = arr1[k + 1];
					arr1[k + 1] = tmp;
				}
			}
		}
		for (int j = 0; j < loop; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				if (arr2[k] == arr1[k])
				{
					idx[k] ++;
					break;
				}
				if (arr2[k] == 0 && idx[k] == 0)
				{
					arr2[k] = arr1[k];
					idx[k] = 1;
					lastIdx = k;
					break;
				}
			}
		}
		idxMax = idx[0];
		Count = 0;
		for (int j = 0; j <= lastIdx; j++)
		{
			if (idxMax == idx[j])
			{
				arr3[Count] = arr2[j];
				Count++;
			}
		}
		cout << Count << " " << idxMax << " ";
		
		
		for (int j = 0; j <= Count; j++)
		{
			cout << arr3[j] << " ";
		}

		cout <<  endl; /* print out*/
	}
	in.close(); /* close input file */
	return 0;
}