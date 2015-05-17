#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "Expression.h"
//#include "NullExpressionExcpetion.h"

namespace core
{
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T>
	{
	private:
		Expression<T> *left;
		Expression<T> *right;
		BinaryExpression<T> *operat;

	public:
		BinaryExpressionModel(BinaryExpression<T>* = NULL, Expression<T>* = NULL, Expression<T>* = NULL );

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;

		void setLeft(Expression<T>*);
		void setRight(Expression<T>*);
		void setOperat(BinaryExpression<T>*);

		Expression<T>* getLeft() const;
		Expression<T>* getRight() const;
		BinaryExpression<T>* getOperat() const;
	};

	template <class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* op, Expression<T>* l, Expression<T>* r):
		operat(op),left(l),right(r)
	{}

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if(left!=NULL && right!=NULL)
			return evaluate(left,right);
		return NULL;
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		/*if (left == NULL)
			throw (NullExpressionException("left operand missing"));
		if (right == NULL)
			throw (NullExpressionException("right operand missing"));*/
			return evaluate(l,r);
	}

	template <class T>
	void BinaryExpressionModel<T>::setLeft(Expression<T>* l)
	{
		left=l;
	}

	template <class T>
	void BinaryExpressionModel<T>::setRight(Expression<T>* r)
	{
		right = r;
	}

	template <class T>
	void BinaryExpressionModel<T>::setOperat(BinaryExpression<T>* o)
	{
		operat = o;
	}

	template <class T>
	core::Expression<T>* BinaryExpressionModel<T>::getRight() const
	{
		return right;
	}

	template <class T>
	core::Expression<T>* BinaryExpressionModel<T>::getLeft() const
	{
		return left;
	}

	template <class T>
	core::BinaryExpression<T>* BinaryExpressionModel<T>::getOperat() const
	{
		return operat;
	}
}
#endif
