#include "AnyType.h"

int main()
{
	AnyType anyType(1);
	AnyType anyType2(1u);
	std::cout << anyType.getType().name();
	std::cout << anyType2.getType().name();

	anyType.swap(anyType2);
	std::cout << anyType.getType().name();
	std::cout << anyType2.getType().name();

	anyType = true;
	anyType = 1.7;

	try
	{
		int storedValue = anyType.toInt();
	}
	catch (std::bad_cast& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	double storedValue = anyType.toDouble();
	std::cout << storedValue;
}