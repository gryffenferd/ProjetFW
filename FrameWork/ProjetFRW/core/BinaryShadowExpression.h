#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression(BinaryExpression<T>*);
		T evaluate(core::Expression<T>,core::Expression<T>) const;
		void setTarget(BinaryExpression<T>*);

	private:
		BinaryExpression<T> *target;
	};

	template <class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target):
		target(_target)
	{}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(core::Expression<T> r,core::Expression<T> l) const
	{
		if(target!=NULL)
			return target.evaluate(l,r);
		return NULL;
	}

	template <class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* t)
	{
		this.target = t;
	}
}

#endif