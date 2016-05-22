/*#include <iostream>
using namespace std;

class Robot
{
public:
	float getX();
	float getY();
	float getFacing();
	void setFacing(float f);
	inline void setLocation(float x, float y);
private:
	float locX;
	float locY;
	float facing;
};
float Robot::getX()
{
	return locX;
}
float Robot::getY()
{
	return locY;
}
float Robot::getFacing()
{
	return facing;
}
void Robot::setFacing(float f)
{
	facing = f;
}
inline void Robot::setLocation(float x, float y)
{
	if (x < 0.0f || y < 0.0f)
	{
		return;
	}
	else
	{
		locX = x;
		locY = y;
	}
}
struct Robot1
{
	float locX;
	float locY;
};

inline char upcase(char ch) {
	if ((ch >= 'a') && (ch <= 'z'))
	{
		return (ch + ('A' - 'a'));
	}
	else
	{
		return ch;
	}
}

int main()
{
	Robot r1;
	r1.setLocation(3, 5);
	r1.setLocation(-4, 7);
	cout << r1.getX() << endl;

	cout << upcase('c') << endl;

}*/

