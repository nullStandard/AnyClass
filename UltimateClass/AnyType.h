#pragma once
#include <iostream>
#include <algorithm>
#include <string>

/*
<--------Exception overrides what() method and informs us------>
<------------which exactly non-type-safe cast we have---------->
								                               */
class NonTypeSafe : public std::bad_cast
{
	 std::string str = "Error, non-type-safe casting to ";
public:
	NonTypeSafe(std::string message)
	{
		str += message;
	}

	const char* what() const noexcept { return str.c_str(); }
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
	
/*
<-----enum is for storing current state (type)------->
<-----------------of AnyType object------------------>						 
													*/
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

	explicit AnyType() = delete;


/*
<-------assignent operators------->
								 */
	AnyType& operator=(bool b);

	AnyType& operator=(char c);

	AnyType& operator=(int i);

	AnyType& operator=(long int l_i);

	AnyType& operator=(unsigned int u_i);

	AnyType& operator=(float f);

	AnyType& operator=(double d);

	AnyType& operator=(long double l_d);

	AnyType& operator=(const AnyType& anyType) = default;

/*
<------getting current type------>
<-------of AnyType object-------->
							    */
	const type_info& getType();

/*
<---Casting functions. If cast is not---->
<--type-safe, throwing custom exception.->
<-----------(getters actually)----------->
										*/
	bool toBool();

	char toChar();

	int toInt();

	long int toLongInt();

	unsigned int toUnsignedInt();

	float toFloat();

	double toDouble();

	long double toLongDouble();

/*
<--function, that swaps values of-->
<-------two AnyType objects-------->
								  */
	void swap(AnyType& obj);
};