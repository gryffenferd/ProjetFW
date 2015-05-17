#ifndef NOTMINUS1_H
#define NOTMINUS1_H

#include "Operator.h"

namespace fuzzy
{
	template <class T>
	class NotMinus : public fuzzy::Not<T>
	{
	public:
		T evaluate(core::Expression<T>*) const;
	};

	template <class T>
	T NotMinus<T>::evaluate(core::Expression<T>* o) const
	{
		T val = o -> evaluate();
		return 1 - val;
	}
}

#endif
