#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H

#include"NaryExpression.h"
#include"Expression.h"

namespace core
{
	template <class T>
	class NaryExpressionModel :public Expression<T>, public NaryExpression<T>
	{
	public:
		NaryExpressionModel(NaryExpression<T>, std::vector<Expression<T>>);
		~NaryExpressionModel(){};
		T evaluate() const;
		T evaluate(std::vector<Expression<T>>) const;

	private:
		NaryExpression<T> operat;
		std::vector<Expression<T>> operands;
	};

	template <class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T> ne, std::vector<Expression<T>> _operands) :
		operat(ne), operands(_operands)
	{}

	template <class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operands != NULL)
			return evaluate(operands);
		return NULL;
	}

	template <class T>
	T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>> o)  const
	{
		if (operat != NULL)
			operat.evaluate(o);
		return NULL;
	}

}

#endif