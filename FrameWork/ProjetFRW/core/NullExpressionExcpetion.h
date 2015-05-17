#ifndef NULLEXPRESSIONEXCEPTION_H
#define NULLEXPRESSIONEXCEPTION_H

#include <exception>

namespace core
{
	class NullExpressionException : public std::invalid_argument
	{
	public:
		NullExpressionException(unsigned char);
		virtual std::ostream& PrintOn(std::ostream&) const

	private:
		const unsigned short msg;
	};
#endif