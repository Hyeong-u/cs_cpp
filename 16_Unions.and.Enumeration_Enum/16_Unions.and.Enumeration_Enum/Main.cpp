#include <iostream>

using namespace std;

enum DAYS {
	Sunday, Monday, Tuesday,
	Wednesday, Thursday, Friday, Saturday
};

enum WEEK {
	one, two, three, four, five
};

int main(int argc, char *argv[])
{

	int March[5][7] = {
		{0, 0, 1, 2, 3, 4, 5,},
		{6, 7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18, 19},
		{20, 21, 22, 23, 24, 25, 26},
		{27, 28, 29, 30, 31, 0, 0} };

	cout << "Monday the third week of March is March "
		<< March[three][Monday] << "." << endl;
}