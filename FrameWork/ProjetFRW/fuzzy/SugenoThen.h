#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include"Operator.h"

namespace fuzzy
{
	template<class T>
	class SugenoThen:public Then<T>
	{
	public:
		SugenoThen();
		virtual ~SugenoThen(){};
	private:
		T premiseValue;
	};

	template<class T>
	SugenoThen<T>::SugenoThen()
	{}

	template<class T>
	T SugenoThen<T>::premiseValue()
	{
		return premiseValue;
	}


}



#endif