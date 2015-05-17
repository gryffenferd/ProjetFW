#ifndef ORMAX_H
#define ORMAX_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class OrMax : public Or<T>
	{
	public:
		OrMax();
		virtual ~OrMax(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	OrMax<T>::OrMax()
	{}

	template <class T>
	T OrMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
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