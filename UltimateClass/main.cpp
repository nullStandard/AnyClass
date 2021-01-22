#include "AnyType.h"

int main()
{
	//initializing AnyType object with integer value
	AnyType anyType_first(1);

	//printing out the current state (int) of AnyType object
	std::cout << "Type of anyType_first is " << anyType_first.getType().name() << std::endl;

	//demonstrating work of default assigment constructor
	AnyType anyType_second(anyType_first);

/*
	Printing out the current state of second AnyType object.
	It should contain the same type (int) like an first AnyType object
*/
	std::cout << "Type of anyType_second is " << anyType_second.getType().name() << std::endl;

	//now, lets cast anyType_first object to bool
	anyType_first = 1.971f;
	std::cout << "Now, type of anyType_first is " << anyType_first.getType().name() << std::endl;

	//now, lets cast anyType_second object to double
	anyType_second = 1.7;
	std::cout << "Now, type of anyType_second is " << anyType_second.getType().name() << std::endl;

	//swapping two values of objects
	anyType_first.swap(anyType_second);

	std::cout << "After swaping, type of anyType_first is " << anyType_first.getType().name() << std::endl;
	std::cout << "After swaping, type of anyType_second is " << anyType_second.getType().name() << std::endl;

/*
	Lets try to cast double to int. 
	There is exception will be thrown due to non-type-safe casting.
*/
	try
	{
		int storedValue = anyType_first.toInt();
	}
	catch (std::bad_cast& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

/*
	Now, lets implement type-safe casting of our anyType_first object (double) to double.
	There is all should be good.
*/
	double storedValue = anyType_first.toDouble();
	std::cout << "Type-safe casting: storedValue (double) variable now stores "
			  << "anyType_first object's " << storedValue << " value\n";
}