// ProjetFRW.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"

#define NUMERIC double
#include "ProjetFRW.h"


void testValue()
{
	std::cout <<  "Test Value" << std::endl;
	ValueModel v1(2);
	ValueModel v2(5);

	std::cout << "v1:" << v1 << std::endl;
	std::cout << "v2:" << v2 << std::endl;
	
	v1.setValue(3);
	std::cout << "v1:" << v1 << std::endl;
}

void testAnd()
{
	std::cout <<  "Test And" << std::endl;
	ValueModel v1(2);
	ValueModel v2(5);
	AndMin andmin;

	BinaryExpression bem(&andmin, &v1, &v2);
	std::cout << "AndMin: " << bem.evaluate() << std::endl;

	AndMin andmult;

	BinaryExpression bem2(&andmult, &v1, &v2);
	std::cout << "AndMult : " << bem2.evaluate() << std::endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	testValue();
	std::cout << std::endl;
	testAnd();
	std::cout << std::endl;

	return 0;
}

