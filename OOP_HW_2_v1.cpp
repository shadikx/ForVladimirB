

#include <iostream>
#include <string>

int students = 0;

class Person
{
private:
	std::string m_name;
	int m_age;
	bool m_gender;
	int m_weight;

public:

	Person(const std::string& name, int age, bool gender, int weight)
		// Здесь должен быть список инициализации, можете показать как это выглядит, в виде кода? Видимо, я что-то упускаю...
	{
		m_name = name;
		m_age = age;
		m_gender = gender;
		m_weight = weight;
	}

	void setName(const std::string& name)
	{
		m_name = name;
	}

	void setAge(int age)
	{
		m_age = age;
	}

	void setWeight(int weight)
	{
		m_weight = weight;
	}

	std::string getName()
	{
		return m_name;
	}

	int getAge()
	{
		return m_age;
	}

	bool getGender()
	{
		return m_gender;
	}

	int getWeight()
	{
		return m_weight;
	}

};

class Student : public Person
{
	int m_year;

public:
	Student(const std::string& name, int age, bool gender, int weight)
		:Person(name, age, gender, weight)
	{
		students++;
	}

	void setYears(int years)
	{
		m_year = years;
	}

	void addYears(int year)
	{
		m_year = year;
	}
};
void Print(Person& student)
{
	std::cout << "|| ... 1 ... ||" << std::endl;
	if (student.getGender() == true)
	{
		std::cout << student.getName() << " " << student.getAge() << " M " << student.getWeight() << std::endl;
	}
	else
	{
		std::cout << student.getName() << " " << student.getAge() << " F " << student.getWeight() << std::endl;
	}
	std::cout << std::endl << "|| ... 2 ... ||" << std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Fruit
{
private:
    std::string m_name;
	std::string m_color;
public:
    Fruit()
	{
	}
    
	Fruit(std::string name, std::string color) 
		: m_name(move(name)), m_color(move(color))
	{
	}
	
	void setColor(std::string color) 
	{
		m_color = color;
	}
	
	void setName(std::string name) 
	{
		m_name = name;
	}
	
	std::string getColor() 
	{
		return m_color;
	}
	std::string getName() 
	{
	    return m_name;
	}
};

class Apple : public Fruit      
{
public:
    Apple(std::string color = "Red", std::string name = "apple")
        :Fruit(move(name), move(color))
	{
	}
};
	
class Banana : public Fruit
{
public:
	Banana(std::string name = "banana", std::string color = "Yellow")
        :Fruit(move(name), move(color)) 
	{
	}	
};
	
class GrannySmith : public Apple
{
public:
    GrannySmith(std::string name = "Granny Smith apple", std::string color = "green") 
        :Apple(move(color), move(name))
	{
	}
};

//.......................................................................................................................


int main()
{
	Student ivanov("Roman", 22, false, 65);
	Student petrov("Evgeniy", 19, true, 81);
	Student sizikov("Innokentiy", 27, true, 94);
	Print(ivanov);
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	Apple a("red");
	Banana b;
	GrannySmith c;
	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
}
