#pragma once

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
	// how to declare a prototype of anonymous union?
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

	enum class TYPES;

public:
	explicit AnyType(bool p_bool);

	explicit AnyType(char p_char);

	explicit AnyType(int p_int);

	explicit AnyType(long int p_long_int);

	explicit AnyType(unsigned int p_u_int);

	explicit AnyType(float p_float);

	explicit AnyType(double p_double);

	explicit AnyType(long double p_long_double);

	AnyType& operator=(bool b);

	AnyType& operator=(char c);

	AnyType& operator=(int i);

	AnyType& operator=(long int l_i);

	AnyType& operator=(unsigned int u_i);

	AnyType& operator=(float f);

	AnyType& operator=(double d);

	AnyType& operator=(long double l_d);

	const type_info& getType();

	bool toBool();

	char toChar();

	int toInt();

	long int toLongInt();

	unsigned int toUnsignedInt();

	float toFloat();

	double toDouble();

	long double toLongDouble();

	void swap(AnyType& obj);
};