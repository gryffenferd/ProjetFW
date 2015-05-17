#ifndef THENMIN_H
#define THENMIN_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class ThenMin : public Then<T>
	{
	public:
		ThenMin();
		virtual ~ThenMin(){};
		T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template <class T>
	ThenMin<T>::ThenMin()
	{}

	template <class T>
	T ThenMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T _l = l -> evaluate();
		T _r = r -> evaluate();
		if (_l < _r)
			return _l;
		if (_l > _r)
			return _r;
	}
}
#endif