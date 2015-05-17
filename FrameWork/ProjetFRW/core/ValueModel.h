#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"

namespace core
{

template <class T>
class ValueModel : public Expression<T>
{
private:
	T value;

public:
	ValueModel();
	ValueModel(const T&);
	virtual ~ValueModel() {};

	virtual void setValue(const T&);
	virtual T evaluate() const;

	template <class T>
	friend std::ostream& operator<<(std::ostream&, const ValueModel<T>&);
};

template <class T>
ValueModel<T>::ValueModel():
	value(0)
{}

template <class T>
ValueModel<T>::ValueModel(const T& _value):
	value(_value)
{}

template <class T>
T ValueModel<T>::evaluate() const
{
	return value;
}

template <class T>
void ValueModel<T>::setValue(const T& _value)
{
	value = _value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const ValueModel<T>& v)
{
	os << v.value;
	return os;
}

}
#endif