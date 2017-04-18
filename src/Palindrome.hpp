#ifndef __PALINDROME_HPP__
#define __PALINDROME_HPP__

#include <WallarooCppApi/ComputationBuilder.hpp>
using namespace wallaroo;



//**************************************************************************************************
class WordInverter : public Computation
{
	public:
		WordInverter ();
		virtual ~WordInverter ();

	public:
		virtual const char *name ();
		virtual Data *compute ( Data *input_ );
};





//**************************************************************************************************
class WordInverterFactory : public ComputationBuilder
{
	public:
		WordInverterFactory () = default;
		virtual ~WordInverterFactory () = default;

	public:
		virtual WordInverter* build ();
};





#endif // __PALINDROME_HPP__
