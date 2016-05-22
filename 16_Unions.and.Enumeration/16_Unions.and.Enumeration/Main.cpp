#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

union Hair {
	int wear_wig;
	char color[20];
};
struct HairInfo {
	int bald;
	Hair hair;
};

void PrintHairInfo(HairInfo info)
{
	if (info.bald) {
		cout << "Subject is bold";

		if (info.hair.wear_wig)
			cout << ", but wears a wig" << endl;
		else
			cout << ", and does not wear a wig" << endl;
	}
	else
	{
		cout << "Subject's hair color is " << info.hair.color << "." << endl;
	}

}

int main(int agrc, char* argv[]) {

	HairInfo info1 = { 0x00, };
	info1.bald = 0;
	strcpy(info1.hair.color, "Brown");
	PrintHairInfo(info1);

	HairInfo info2 = { 0x00, };
	info2.bald = 1;
	PrintHairInfo(info2);

	HairInfo info3 = { 0x00, };
	info3.bald = 1;
	strcpy(info3.hair.color, "Red");
	PrintHairInfo(info3);
	return 0;
}