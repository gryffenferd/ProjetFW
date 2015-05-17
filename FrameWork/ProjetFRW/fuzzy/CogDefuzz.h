#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MandaniDefuzz.h"

namespace fuzzy
{
	template <class T>
	class CogDefuzz : public MandaniDefuzz<T>
	{
	public:
		CogDefuzz(const T&,const T&,const T&);

		T defuzz(const typename core::Evaluator<T>::Shape&) const;
		T CogDefuzz<T>::getMax() const;
		T CogDefuzz<T>::getMin() const;
		T CogDefuzz<T>::getStep() const;
	private:
		T min,max,step;

	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min,const T& _max,const T& _step):
		min(_min),max(_max),step(_step)
	{}
	
	template <class T>
	T CogDefuzz<T>::getMax() const
	{
		return max;
	}

	template <class T>
	T CogDefuzz<T>::getMin() const
	{
		return min;
	}

	template <class T>
	T CogDefuzz<T>::getStep() const
	{
		return step;
	}

	template <class T>
	T CogDefuzz<T>::defuzz(const typename core::Evaluator<T>::Shape &s) const
	{
		T x,y,num=0,den=0;
		for(unsigned int i=0; i<(s.first.size()-1); i++)
		{
			x=s.first.at(i);
			y=s.second.at(i);
			num+=x*y;
			den+=y;
		}
		return num/den;
	}
}

#endif