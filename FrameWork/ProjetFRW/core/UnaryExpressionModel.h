#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>
	{
	public:
		UnaryExpressionModel(UnaryExpression<T>* = NULL,Expression<T>* = NULL);
		~ UnaryExpressionModel() {}

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*) const;

		virtual UnaryExpression<T>* getOperat() const;
		virtual Expression<T>* getOperand() const;
		

	private:
		UnaryExpression<T> *operat;
		Expression<T> *operand;
	};

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* ue, Expression<T>* e):
		operat(ue),operand(e)
	{}

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
	{
		if(operat != NULL)
			return operat->evaluate(o);
	}

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if(operat != NULL)
			return evaluate(operand);
	}

	template <class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::getOperat() const
	{
		return operat;
	}

	template <class T>
	Expression<T>* UnaryExpressionModel<T>::getOperand() const
	{
		return operand;
	}


}

#endif
