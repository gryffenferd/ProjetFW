#ifndef	UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class UnaryShadowEpression : public core::UnaryExpression<T>
	{
	public:
		UnaryShadowEpression(UnaryExpression<T>*);
		T evaluate(core::Expression<T>) const;
		void setTarget(UnaryExpression<T>*);

	private:
		UnaryExpression<T> *target;
	};

	template <class T>
	UnaryShadowEpression<T>::UnaryShadowEpression(UnaryExpression<T>* _target):
		target(_target)
	{}

	template <class T>
	T UnaryShadowEpression<T>::evaluate(core::Expression<T> e) const
	{
		if(target!= NULL)
			return target.evaluate(e);
	}

	template <class T>
	void UnaryShadowEpression<T>::setTarget(UnaryExpression<T>* t)
	{
		this.target = t;
	}

}

#endif