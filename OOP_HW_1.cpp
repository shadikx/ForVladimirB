
#include <iostream>
#include <math.h>

class Power
{
private:
	int p_first;
	int p_second;
public:
	void setPower(int first, int second)
	{
		p_first = first;
		p_second = second;
	}

	void calculatePower(int first, int second)
	{
		std::cout << pow(p_first, p_second) << std::endl;
	}


};

int main()
{
	Power value;
	value.setPower(3, 5);
	value.calculatePower(3, 5);

	return 0;
}
