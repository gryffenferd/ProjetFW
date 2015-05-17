#ifndef OPERATOR_H
#define OPERATOR_H

#include "../core/BinaryExpression.h"
#include "../core/UnaryExpression.h"
#include "../core/Expression.h"
#include "../core/Evaluator.h"

namespace fuzzy
{
	template <class T>
	class And : public core::BinaryExpression<T>
	{
	public :
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
	};

	template <class T>
	class Or : public core::BinaryExpression<T>
	{
	public:
		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const=0;
	};

	template <class T>
	class Then : public core::BinaryExpression<T>
	{
	public:
		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const=0;
	};

	template <class T>
	class Agg : public core::BinaryExpression<T>
	{
	public:
		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const=0;
	};

	template <class T>
	class Not : public core::UnaryExpression<T>
	{
	public:
		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const=0;
	};

	template <class T>
	class Is : public core::UnaryExpression<T>
	{
		virtual T evaluate(core::Expression<T>* e) const=0;
	};

	template <class T>
	class Defuzz : public core::BinaryExpression<T>
	{
	public:
		virtual T evaluate(core::Expression<T>,core::Expression<T>) const;

	protected:
		virtual T defuzz(const typename core::Evaluator<T>::Shape) const = 0 ;
	};

}

#endif