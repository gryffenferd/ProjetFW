#ifndef AGGMAX_H
#define AGGMAX_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class AggMax : public Agg<T>
	{
	public:
		AggMax();
		virtual ~AggMax(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	AggMax<T>::AggMax()
	{}

	template <class T>
	T AggMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l -> evaluate();
		T _r = r -> evaluate();
		if(_l < _r)
			return _r;
		if(_l > _r)
			return _l;
	}
}

#endif