#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "UnaryExpressionModel.h"
#include <set>

namespace core
{
	template <class T>
	class ExpressionFactory
	{
	public:
		ExpressionFactory();
		~ExpressionFactory();
		core::Expression<T>* hold(core::Expression<T>*);
		core::Expression<T>* newUnary(core::UnaryExpression<T>,core::Expression<T>);
		core::Expression<T>* newBinary(core::BinaryExpression<T>, core::Expression<T>);

	public :
		std::set<Expression<T>*> memory;
	};

	template <class T>
	ExpressionFactory<T>::ExpressionFactory():
		memory(new std::set<Expression<T>*>)
	{}

	template <class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		delete memory;
	}

	template <class T>
	core::Expression<T> ExpressionFactory<T>::hold(core::Expression<T>* e)
	{
		memory.insert(e);
		return e;
	}

	template <class T>
	core::Expression<T>* ExpressionFactory<T>::newUnary(core::UnaryExpression<T> ope ,core::Expression<T> o)
	{
		return new UnaryExpressionModel(ope,o);
	}

	template <class T>
	core::Expression<T>* ExpressionFactory<T>::newBinary(core::BinaryExpression<T> ope ,core::Expression<T> o)
	{
		return new BinaryExpressionModel(ope,o);
	}

}

#endif