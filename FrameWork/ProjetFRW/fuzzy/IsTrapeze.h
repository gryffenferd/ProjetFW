#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "Operator.h"

namespace fuzzy{

	template <class T>
	class IsTrapeze : public fuzzy::Is<T>
	{
	private:
		T min, max, mind1, mind2;

	public:
		IsTrapeze(T ,T,T,T);

		T evaluate(core::Expression<T>*) const;

	};

	template <class T>
	IsTrapeze<T>::IsTrapeze(T mi, T md1, T md2, T ma):
		min(mi),mind1(md1),mind2(md2),max(ma)
	{
	}

	template <class T>
	T IsTrapeze<T>::evaluate(core::Expression<T>* o) const
	{
		T val = o -> evaluate();

		if(val <= min || val >= max)
			return T(0);

		if(min <= val && val >= mind1)
			return (val-max)/(mind1 - max);

		if(mind1 <= val && val >= mind2)
			return T(1);

		if(mind2 <= val && val >= max)
			return (max - val)/(max - mind2);
	}
}

#endif