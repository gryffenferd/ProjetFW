#ifndef UNARYEXPRESSION_H
#define	UNARYEXPRESSION_H

#include "Expression.h"

namespace core
{

	template <class T>
	class UnaryExpression
	{
	public:
		virtual T evaluate(Expression<T>*) const = 0;
	};
}
#endif