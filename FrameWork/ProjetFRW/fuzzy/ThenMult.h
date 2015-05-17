#ifndef THENMULT_H
#define THENMULT_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class ThenMult : public Then<T>
	{
	public:
		ThenMult();
		virtual ~ThenMult(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	ThenMult<T>::ThenMult()
	{}

	template <class T>
	T ThenMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l -> evaluate();
		T _r = r -> evaluate();
		return _l*_r;
	}
}

#endif