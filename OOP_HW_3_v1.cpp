
#include <iostream>
#include <cmath>
#include <string>

//1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1.1

class Figure
{
protected:
	const double M_PI = 3.1415926535;

public:
    virtual double area() = 0;

    virtual ~Figure()
    {
		
    }
};

class Parallelogram : public Figure
{
private:
    double length_1;
    double length_2;
    double angle;

public:
    Parallelogram(double l_1, double l_2, double ang) : length_1(l_1), length_2(l_2), angle(ang)
    {
    }

    double area() override
    {
		return length_1 * length_2 * sin(angle * M_PI / 180);
    }
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double l_1, double l_2) : Parallelogram(l_1, l_2, 90)
	{
	}
};

class Square : public Parallelogram
{
public:
	Square(double l_1) : Parallelogram(l_1, l_1, 90)
	{
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double l_1, double ang) : Parallelogram(l_1, l_1, ang)
	{
	}
};

class Circle : public Figure
{
private:
	const double M_PI = 3.1415926535;
	double radius;

public:
	Circle(double rad) : radius(rad)
	{
	}

	double area() override
	{
		return M_PI * radius * radius;
	}
};

void part1()
{
	std::cout << "|| ... 1 ... ||" << std::endl;
	Parallelogram par(22, 18, 41);
	std::cout << "Parallelogram Area: " << par.area() << std::endl;

	Rectangle rec(21, 34);
	std::cout << "Rectangle Area: " << rec.area() << std::endl;

	Square sq(15);
	std::cout << "Square Area: " << sq.area() << std::endl;

	Rhombus rhom(9, 27);
	std::cout << "Rhombus Area: " << rhom.area() << std::endl;

	Circle cir(15);
	std::cout << "Circle Area: " << cir.area() << std::endl;

};

//2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2.2

class Car
{
protected:
	std::string company;
	std::string model;
public:
	Car(const std::string& com, const std::string& mod) : company(com), model(mod)
	{
		std::cout << "Car " << company << " " << model << std::endl;
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(const std::string& com, const std::string& mod) : Car(com, mod)
	{
		std::cout << "PassengerCar " << company << " " << model << std::endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus(const std::string& com, const std::string& mod) : Car(com, mod)
	{
		std::cout << "Bus " << company << " " << model << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(const std::string& com, const std::string& mod) : PassengerCar(com, mod), Bus(com, mod), Car(com, mod)
	{
		std::cout << "Minivan " << company << " " << model << std::endl;
	}
};

void part2()
{
	std::cout << "|| ... 2 ... ||" << std::endl;

	std::cout << ">> Car" << std::endl;
	Car car("Mitsubichi", "Eclipse");

	std::cout << ">> PassengerCar" << std::endl;
	PassengerCar pas("Nissan", "Skyline");

	std::cout << ">> Bus" << std::endl;
	Bus bus("KIA", "Granbird");

	std::cout << ">> Minivan" << std::endl;
	Minivan min("Honda", "Jade");
}

//3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3.3

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int num, int den) : numerator(num), denominator(den)
	{
		if (den == 0)
		{
			throw "Cannot divide by zero";
		}
	}

	friend Fraction operator+ (const Fraction& fra_1, const Fraction& fra2);

	friend Fraction operator- (const Fraction& fra_1, const Fraction& fra2);
	
	friend Fraction operator* (const Fraction& fra_1, const Fraction& fra2);
	
	friend Fraction operator/ (const Fraction& fra_1, const Fraction& fra_2);
	
	friend Fraction operator- (const Fraction& fra_1);

	
	friend bool operator== (const Fraction& fra_1, const Fraction& fra_2);
	
	friend bool operator!= (const Fraction& fra_1, const Fraction& fra_2);
	
	friend bool operator< (const Fraction& fra_1, const Fraction& fra_2);
	
	friend bool operator> (const Fraction& fra_1, const Fraction& fra_2);
	
	friend bool operator>= (const Fraction& fra_1, const Fraction& fra_2);
	
	friend bool operator<= (const Fraction& fra_1, const Fraction& fra_2);


	friend std::ostream& operator<<(std::ostream& out, const Fraction& fra);
};

Fraction operator+ (const Fraction& fra_1, const Fraction& fra_2)
{
	if (fra_1.denominator == fra_2.denominator)
	{
		return Fraction(fra_1.numerator + fra_2.numerator, fra_1.denominator);
	}

	int denominator = fra_1.denominator * fra_2.denominator;
	int numerator = fra_1.numerator * fra_2.denominator + fra_2.numerator * fra_1.denominator;
	return Fraction(numerator, denominator);
}

Fraction operator- (const Fraction& fra_1, const Fraction& fra_2)
{
	if (fra_1.denominator == fra_2.denominator)
	{
		return Fraction(fra_1.numerator - fra_2.numerator, fra_1.denominator);
	}

	int denominator = fra_1.denominator * fra_2.denominator;
	int numerator = fra_1.numerator * fra_2.denominator - fra_2.numerator * fra_1.denominator;
	return Fraction(numerator, denominator);
}

Fraction operator* (const Fraction& fra_1, const Fraction& fra_2)
{
	int denominator = fra_1.denominator * fra_2.denominator;
	int numerator = fra_1.numerator * fra_2.numerator;
	return Fraction(numerator, denominator);
}

Fraction operator/ (const Fraction& fra_1, const Fraction& fra_2)
{
	if (fra_2.numerator == 0)
	{
		throw "Cannot divide by zero";
	}

	int denominator = fra_1.denominator * fra_2.numerator;
	int numerator = fra_1.numerator * fra_2.denominator;
	return Fraction(numerator, denominator);
}

Fraction operator- (const Fraction& fra_1)
{
	return Fraction(-1 * fra_1.numerator, fra_1.denominator);
}

bool operator== (const Fraction& fra_1, const Fraction& fra_2)
{
	return fra_1.numerator * fra_2.denominator == fra_2.numerator * fra_1.denominator;
}

bool operator!= (const Fraction& fra_1, const Fraction& fra_2)
{
	return !(fra_1 == fra_2);
}

bool operator< (const Fraction& fra_1, const Fraction& fra_2)
{
	return fra_1.numerator * fra_2.denominator < fra_2.numerator* fra_1.denominator;
}

bool operator> (const Fraction& fra_1, const Fraction& fra_2)
{
	return fra_1.numerator * fra_2.denominator > fra_2.numerator * fra_1.denominator;
}

bool operator>= (const Fraction& fra_1, const Fraction& fra_2)
{
	return !(fra_1 < fra_2);
}

bool operator<= (const Fraction& fra_1, const Fraction& fra_2)
{
	return !(fra_1 > fra_2);
}

std::ostream& operator<<(std::ostream& out, const Fraction& fra)
{
	return out << fra.numerator << '/' << fra.denominator;
}

void part3()
{
	std::cout << "|| ... 3 ... ||" << std::endl;
	
	std::cout << "2/4 + 3/9 = " << Fraction(2, 4) + Fraction(3, 9) << std::endl;
	
	std::cout << "2/4 - 3/9 = " << Fraction(2, 4) - Fraction(3, 9) << std::endl;
	
	std::cout << "2/4 * 3/9 = " << Fraction(2, 4) * Fraction(3, 9) << std::endl;
	
	std::cout << "2/4 / 3/9 = " << Fraction(2, 4) / Fraction(3, 9) << std::endl;
	
	
	std::cout << "- 2/4 = " << -Fraction(2, 4) << std::endl;
	
	
	std::cout << "2/4 == 4/8 = " << ((Fraction(2, 4) == Fraction(4, 8)) ? "true" : "false") << std::endl;
	
	std::cout << "2/4 != 4/8 = " << ((Fraction(2, 4) != Fraction(4, 8)) ? "true" : "false") << std::endl;
	
	std::cout << "2/4 < 3/9 = " << ((Fraction(2, 4) < Fraction(3, 9)) ? "true" : "false") << std::endl;
	
	std::cout << "2/4 > 3/9 = " << ((Fraction(2, 4) > Fraction(3, 9)) ? "true" : "false") << std::endl;
	
	std::cout << "2/4 >= 3/9 = " << ((Fraction(2, 4) >= Fraction(3, 9)) ? "true" : "false") << std::endl;
	
	std::cout << "2/4 <= 3/9 = " << ((Fraction(2, 4) <= Fraction(3, 9)) ? "true" : "false") << std::endl;
}

//4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4.4

enum CardRank
{
	ACE = 1, // =11, if score <= 21
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10,
};

enum CardBack
{
	GRID = 0,
	DAWN = 1,
	WINTER = 2,
	MOUNTAIN = 3,
};

class Card
{
private:
	CardBack back;
	CardRank value;
	bool isFaceUp;

public:
	Card(CardBack b = GRID, CardRank val = SIX, bool face = false) : back(b), value(val), isFaceUp(face)
	{
	}

	bool Flip()
	{
		return isFaceUp = !isFaceUp;
	}

	bool GetIsFaceUp()
	{
		return isFaceUp;
	}

	int GetValue()
	{
		return value;
	}
};

void part4()
{
	std::cout << "|| ... 4 ... ||" << std::endl;
	Card c = Card();
	std::cout << "isFaceUp: " << c.GetIsFaceUp() << std::endl;
	std::cout << "isFaceUp: " << c.Flip() << std::endl;
	std::cout << "Value: " << c.GetValue() << std::endl;
}


int main()
{
	part1();
	part2();
	part3();
	part4();
	return 0;
}
