#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class AggPlus : public Agg<T>
	{
	public:
		AggPlus();
		virtual ~AggPlus(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	AggPlus<T>::AggPlus()
	{}

	template <class T>
	T AggPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l -> evaluate();
		T _r = r -> evaluate();
		return _l+_r;
	}
}

#endif
