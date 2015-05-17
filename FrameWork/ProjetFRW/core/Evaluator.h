#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "ValueModel.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class Evaluator
	{
	public:
		typedef std::pair<std::vector<T>,std::vector<T>> Shape;
		static Shape buildShape(T,T,T,core::ValueModel<T>*, core::Expression<T>*);
		static std::ostream& printShape(const Shape& , std::ostream&);
	};

	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::buildShape(T min, T max, T step, core::ValueModel<T>* v, core::Expression<T>* e)
	{
	
		std::vector<T> x,y;
		T mem = v -> evaluate();

		for (T i = min; i <= max ; i += step)
		{
			v -> setValue(i);
			y.push_back(e -> evaluate());
			x.push_back(i);
		}	
		v -> setValue(mem)
		return Shape(x,y);
	}

	template <class T>
	std::ostream& Evaluator<T>::printShape(const Shape& s, std::ostream& os)
	{
		os << '[';
		typename std::vector<T>::const_iterator it = s.first.begin();
		for(;it!=s.first.end();++it)
			os << *it << ' ';
		os << ']';
		os << std::endl;
		os << '[';
		it = s.second.begin();
		for(; it != s.second.end(); ++it)
			os << *it << ' ';
		os << ']';
		return os;
	}

}

#endif