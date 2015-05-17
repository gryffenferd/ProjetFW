#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "Operator.h"

namespace fuzzy{

	template <class T>
	class IsTriangle : public fuzzy::Is<T>
	{
	private:
		T min;
		T max;
		T mind;

	public:
		IsTriangle( T,T,T);
		T evaluate(core::Expression<T>*) const;

	};

	template <class T>
	IsTriangle<T>::IsTriangle(T mi, T md, T ma):
		min(mi),mind(md),max(ma)
	{}

	template <class T>
	T IsTriangle<T>::evaluate(core::Expression<T>* o) const{

		T val = o -> evaluate();

		if(val <= min || val >= max)
			return T(0);

		return (min <= val && val <= mind) ?
			(val - min)/(mind - min):
			(max - val)/(max - mind);
	}


}

#endif
