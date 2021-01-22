#include "AnyType.h"

enum class AnyType::TYPES
{
	BOOL, CHAR, INT, LONG_INT,
	UNSIGNED_INT, FLOAT, DOUBLE, LONG_DOUBLE
} type;

AnyType::AnyType(bool p_bool) : m_bool(p_bool)
{
	type = TYPES::BOOL;
}

AnyType::AnyType(char p_char) : m_char(p_char)
{
	type = TYPES::CHAR;
}

AnyType::AnyType(int p_int) : m_int(p_int)
{
	type = TYPES::INT;
}

AnyType::AnyType(long int p_long_int) : m_long_int(p_long_int)
{
	type = TYPES::LONG_INT;
}

AnyType::AnyType(unsigned int p_u_int) : m_u_int(p_u_int)
{
	type = TYPES::UNSIGNED_INT;
}

AnyType::AnyType(float p_float) : m_float(p_float)
{
	type = TYPES::FLOAT;
}

AnyType::AnyType(double p_double) : m_double(p_double)
{
	type = TYPES::DOUBLE;
}

AnyType::AnyType(long double p_long_double) : m_long_double(p_long_double)
{
	type = TYPES::LONG_DOUBLE;
}

/*
<-------assignent operators------->
								 */
AnyType& AnyType::operator=(bool b)
{
	m_bool = b;
	type = TYPES::BOOL;
	return *this;
}
AnyType& AnyType::operator=(char c)
{
	m_char = c;
	type = TYPES::CHAR;
	return *this;
}
AnyType& AnyType::operator=(int i)
{
	m_int = i;
	type = TYPES::INT;
	return *this;
}
AnyType& AnyType::operator=(long int l_i)
{
	m_long_int = l_i;
	type = TYPES::LONG_INT;
	return *this;
}
AnyType& AnyType::operator=(unsigned int u_i)
{
	m_u_int = u_i;
	type = TYPES::UNSIGNED_INT;
	return *this;
}
AnyType& AnyType::operator=(float f)
{
	m_float = f;
	type = TYPES::FLOAT;
	return *this;
}
AnyType& AnyType::operator=(double d)
{
	m_double = d;
	type = TYPES::DOUBLE;
	return *this;
}
AnyType& AnyType::operator=(long double l_d)
{
	m_long_double = l_d;
	type = TYPES::LONG_DOUBLE;
	return *this;
}

/*
<-------getting current type-------->
<--------of AnyType object---------->
							       */
const type_info& AnyType::getType()
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

/*
<-----Casting functions. If cast is not-------->
<----type-safe, throwing custom exception------>
<-Otherway, returning current value of AnyType->
										      */
bool AnyType::toBool()
{
	if (getType() != typeid(bool))
	{
		throw NonTypeSafe("bool");
	}
	return m_bool;
}

char AnyType::toChar()
{
	if (getType() != typeid(char))
	{
		throw NonTypeSafe("char");
	}
	return m_char;
}

int AnyType::toInt()
{
	if (getType() != typeid(int))
	{
		throw NonTypeSafe("int");
	}
	return m_int;
}

long int AnyType::toLongInt()
{
	if (getType() != typeid(long int))
	{
		throw NonTypeSafe("int");
	}
	return m_long_int;
}

unsigned int AnyType::toUnsignedInt()
{
	if (getType() != typeid(unsigned int))
	{
		throw NonTypeSafe("unsigned int");
	}
	return m_u_int;
}

float AnyType::toFloat()
{
	if (getType() != typeid(float))
	{
		throw NonTypeSafe("float");
	}
	return m_float;
}

double AnyType::toDouble()
{
	if (getType() != typeid(double))
	{
		throw NonTypeSafe("double");
	}
	return m_double;
}

long double AnyType::toLongDouble()
{
	if (getType() != typeid(long double))
	{
		throw NonTypeSafe("long double");
	}
	return m_long_double;
}

/*
<--function, that swaps values of-->
<-------two AnyType objects-------->
								  */
void AnyType::swap(AnyType& obj)
{
	std::swap(*this, obj);
}