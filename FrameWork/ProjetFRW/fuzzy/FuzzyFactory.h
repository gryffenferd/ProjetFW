#ifndef FUZZYFACTORY_H
#define FUZZYFAACTORY_H	

#include "Operator.h"
#include "../core/ExpressionFactory.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/UnaryShadowExpression.h"
#include "../core/BinaryExpressionModel.h"

namespace fuzzy
{
	template <class T>
	class FuzzyFactory : public core::ExpressionFactory<T>
	{
	private:
		core::BinaryShadowExpression<T>*  and, or, then, agg;
		core::UnaryShadowEpression<T>* not, is;

	public:
		FuzzyFactory(And<T>*,Or<T>*,Then<T>*,Agg<T>*,Not<T>*,Is<T>*);

		core::BinaryExpressionModel<T>* newAnd(core::Expression<T>*,core::Expression<T>*);
		core::BinaryExpressionModel<T>* newOr(core::Expression<T>*,core::Expression<T>*);
		core::BinaryExpressionModel<T>* newThen(core::Expression<T>*,core::Expression<T>*);
		core::BinaryExpressionModel<T>* newAgg(core::Expression<T>*,core::Expression<T>*);
		core::UnaryExpressionModel<T>* newNot(core::Expression<T>*);
		core::BinaryExpressionModel<T>* newIs(core::Expression<T>*);

		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeNot(Not<T>*);
		void changeIs(Is<T>*);
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(And<T>* _and,Or<T>* _or,Then<T>* _then,Agg<T>* _agg,Not<T>* _not,Is<T>* _is):
		and(_and),or(_or),then(_then),agg(_agg),not(_not),is(_is)
	{}

	template<class T>
	core::BinaryExpressionModel<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* l,core::Expression<T>* r)
	{
		return newBinary(and,l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* l,core::Expression<T>* r)
	{
		return newBinary(or,l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* l,core::Expression<T>* r)
	{
		return newBinary(then,l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* l,core::Expression<T>* r)
	{
		return newBinary(agg,l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o)
	{
		return newUnary(and,l,r);
	}

	template <class T>
	core::Expression<T>* FuzzyFactory<T>::newIs(core::Expression<T>* o)
	{
		return newUnary(is,l,r);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o){
		and->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o)
	{
		or->setTarget(o);
	}
	
	template <class T>
	void FuzzyFactory<T>::changeThen(Then<T>* o)
	{
		then ->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* o)
	{
		agg->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeNot(Not<T>* o)
	{
		not->setTarget(o);
	}

	template <class T>
	void FuzzyFactory<T>::changeIs(Is<T>* o)
	{
		is->setTarget(o);
	}
}

#endif