#include <iostream>
#include <algorithm>

class NonTypeSafe : public std::bad_cast
{
	const char* for_what;
public:
	NonTypeSafe(const char* message) : for_what(message) {}

	const char* what() const noexcept { return for_what; }
};

class AnyType
{
	union
	{
		bool		 m_bool;
		char		 m_char;
		int			 m_int;
		long int	 m_long_int;
		unsigned int m_u_int;
		float		 m_float;
		double		 m_double;
		long double  m_long_double;
	};

	enum class TYPES
	{
		BOOL, CHAR, INT, LONG_INT,
		UNSIGNED_INT, FLOAT, DOUBLE, LONG_DOUBLE
	} type;

public:
	explicit AnyType(bool p_bool) : m_bool(p_bool)
	{
		type = TYPES::BOOL;
	}

	explicit AnyType(char p_char) : m_char(p_char)
	{
		type = TYPES::CHAR;
	}

	explicit AnyType(int p_int) : m_int(p_int)
	{
		type = TYPES::INT;
	}

	explicit AnyType(long int p_long_int) : m_long_int(p_long_int)
	{
		type = TYPES::LONG_INT;
	}

	explicit AnyType(unsigned int p_u_int) : m_u_int(p_u_int)
	{
		type = TYPES::UNSIGNED_INT;
	}

	explicit AnyType(float p_float) : m_float(p_float)
	{
		type = TYPES::FLOAT;
	}

	explicit AnyType(double p_double) : m_double(p_double)
	{
		type = TYPES::DOUBLE;
	}

	explicit AnyType(long double p_long_double) : m_long_double(p_long_double)
	{
		type = TYPES::LONG_DOUBLE;
	}

	AnyType& operator=(bool b)
	{
		m_bool = b;
		type = TYPES::BOOL;
		return *this;
	}
	AnyType& operator=(char c)
	{
		m_char = c;
		type = TYPES::CHAR;
		return *this;
	}
	AnyType& operator=(int i)
	{
		m_int = i;
		type = TYPES::INT;
		return *this;
	}
	AnyType& operator=(long int l_i)
	{
		m_long_int = l_i;
		type = TYPES::LONG_INT;
		return *this;
	}
	AnyType& operator=(unsigned int u_i)
	{
		m_u_int = u_i;
		type = TYPES::UNSIGNED_INT;
		return *this;
	}
	AnyType& operator=(float f)
	{
		m_float = f;
		type = TYPES::FLOAT;
		return *this;
	}
	AnyType& operator=(double d)
	{
		m_double = d;
		type = TYPES::DOUBLE;
		return *this;
	}
	AnyType& operator=(long double l_d)
	{
		m_long_double = l_d;
		type = TYPES::LONG_DOUBLE;
		return *this;
	}

	const type_info& getType()
	{
		switch (type)
		{
		case TYPES::BOOL:
			return typeid(m_bool);
		case TYPES::CHAR:
			return typeid(m_char);
		case TYPES::INT:
			return typeid(m_int);
		case TYPES::LONG_INT:
			return typeid(m_long_int);
		case TYPES::UNSIGNED_INT:
			return typeid(m_u_int);
		case TYPES::FLOAT:
			return typeid(m_float);
		case TYPES::DOUBLE:
			return typeid(m_double);
		case TYPES::LONG_DOUBLE:
			return typeid(m_long_double);
		}
	}

	bool toBool()
	{
		if (getType() != typeid(bool))
			throw NonTypeSafe("Error, non-type-safe casting to bool");
		return m_bool;
	}

	char toChar()
	{
		if (getType() != typeid(char))
			throw NonTypeSafe("Error, non-type-safe casting to char");
		return m_char;
	}
	
	int toInt()
	{
		if (getType() != typeid(int))
			throw NonTypeSafe("Error, non-type-safe casting to int");
		return m_int;
	}

	long int toLongInt()
	{
		if (getType() != typeid(long int))
			throw NonTypeSafe("Error, non-type-safe casting to long int");
		return m_long_int;
	}

	unsigned int toUnsignedInt()
	{
		if (getType() != typeid(unsigned int))
			throw NonTypeSafe("Error, non-type-safe casting to unsigned int");
		return m_u_int;
	}

	float toFloat()
	{
		if (getType() != typeid(float))
			throw NonTypeSafe("Error, non-type-safe casting to float");
		return m_float;
	}

	double toDouble()
	{
		if (getType() != typeid(double))
			throw NonTypeSafe("Error, non-type-safe casting to double");
		return m_double;
	}

	long double toLongDouble()
	{
		if (getType() != typeid(long double))
			throw NonTypeSafe("Error, non-type-safe casting to long double");
		return m_long_double;
	}

	void swap(AnyType& obj)
	{
		std::swap(*this, obj);
	}
};

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