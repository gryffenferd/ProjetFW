#ifndef ANDMULT_H
#define ANDMULT_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class AndMult : public And<T>
	{
	public:
		AndMult();
		virtual ~AndMult(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	AndMult<T>::AndMult()
	{}

	template <class T>
	T AndMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l -> evaluate();
		T _r = r -> evaluate();
		return _l*_r;
	}
}

#endif