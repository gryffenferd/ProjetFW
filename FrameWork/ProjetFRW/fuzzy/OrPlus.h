#ifndef ORPLUS_H
#define ORPLUS_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class OrPlus : public Or<T>
	{
	public:
		OrPlus();
		virtual ~OrPlus(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	OrPlus<T>::OrPlus()
	{}

	template <class T>
	T OrPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l -> evaluate();
		T _r = r -> evaluate();
		return _l+_r;		
	}
}

#endif
