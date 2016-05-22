#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
void PrintFile(ifstream &in);
int main()
{
	/*
	ifstream inFile;
	ofstream outFile;
	char FileName[81];
	cout << "Enter filename: ";
	cin.getline(FileName, 81);
	inFile.open("myfile.dat");
	inFile.close();
	inFile.open(FileName);
	inFile.close();
	outFile.open("myfile.dat");
	*/
	/*
	ofstream outFile;
	outFile.open("myfile.dat");
	for (size_t i = 0; i < 5; i++)
	{
		//outFile << (i + 1) * 100 << endl;
		outFile << (i + 1) * 100 << "\n";
	}
	outFile.close();
	*/
	/*
	ifstream inFile;
	inFile.open("myfile.dat");
	if (!inFile)
	{
		cout << "Can't open file";
		exit(1);
	}
	int num;
	/*
	for (size_t i = 0; i < 5; i++)
	{
		inFile >> num;
		cout << num << endl;
	}
	
	while (inFile >> num)
	{
		cout << num << endl;
	}
	inFile.close();
	*/

	/*
	fstream file;
	file.open("sample.txt", ios::out);

	if (!file)
		exit(1);
	
	for (size_t i = 0; i < 100; i++)
	{
		file << setw(3) << i << endl;
	}

	file.close();
	*/

	/*
	ostringstream outStr;
	double amount = 109.7932;
	outStr << showpoint << fixed << setprecision(2) << 'S' << amount; //fixed를 쓰면 showpoint는 디폴트
	cout << outStr.str() << endl;

	ifstream file;
	file.open("sample.txt");

	if (!file)
		exit(1);

	PrintFile(file);

	file.close();
	*/

	//ifstream in;
	//in.open("myfile.dat");
	/*
	char ch = in.get();
	cout << "Got" << ch << endl;
	in.get(ch);
	cout << "Got" << ch << endl;
	*/
	/*
	char ch;
	ch = in.peek();
	cout << "Got" << ch << endl;

	ch = in.peek();
	cout << "Got" << ch << endl;
	in.close();
	*/

	ifstream infile;
	ofstream outfile;
	infile.open("sample1.txt");
	outfile.open("sample2.txt");

	if (!infile)
		exit(1);

	char ch;
	infile.get(ch);

	while (!infile.fail())
	{
		outfile.put(ch);
		infile.get(ch);
	}


	return 0;

}

void PrintFile(ifstream &in)
{
	int value;
	while (in >> value)
	{
		cout << "Value = " << value << endl;
	}
}