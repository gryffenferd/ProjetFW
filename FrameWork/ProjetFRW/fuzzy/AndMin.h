#ifndef ANDMIN_H
#define ANDMIN_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class AndMin : public And<T>
	{
	public:
		AndMin();
		virtual ~AndMin(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	AndMin<T>::AndMin()
	{}

	template <class T>
	T AndMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l-> evaluate();
		T _r = r -> evaluate();
		return (_l<_r)?_l:_r;
	}
}

#endif