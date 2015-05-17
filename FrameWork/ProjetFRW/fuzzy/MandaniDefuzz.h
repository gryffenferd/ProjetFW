#ifndef MANDANIDEFUZZ_H
#define MANDANIDEFUZZ_H

#include "Operator.h"

namespace fuzzy
{

	template <class T>
		class MandaniDefuzz:public core::BinaryExpression<T>
		{
		public :
			MandaniDefuzz(const T&,const T&,const T&);

			T evaluate(core::Expression<T>* l,core::Expression<T>* _r) const;
			virtual T defuzz(const typename core::Evaluator<T>::Shape&) const=0;
		private:
			T min, max, step, current;
		};

		template<class T>
		MandaniDefuzz<T>::MandaniDefuzz(const T& _min,const T& _max,const T& _step):
		min(_min),max(_max),step(_step)
		{
		}

		template<class T>
		T MandaniDefuzz<T>::evaluate(core::Expression<T>* s,core::Expression<T>* var) const
		{
			return defuzz( core::Evaluator<T>::BuildShape(min, max, step,(ValueModel<T>*)s,var));
		}
}

#endif