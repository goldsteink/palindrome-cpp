#ifndef __PALINDROME_HPP__
#define __PALINDROME_HPP__

#include <WallarooCppApi/ComputationBuilder.hpp>
using namespace wallaroo;



//**************************************************************************************************
class StatelessWordInverter : public Computation
{
	public:
		StatelessWordInverter ();
		virtual ~StatelessWordInverter ();

	public:
		virtual const char *name ();
		virtual Data *compute ( Data *input_ );
};





//**************************************************************************************************
class PalindromeStatelessFactory : public ComputationBuilder
{
	public:
		PalindromeStatelessFactory () = default;
		virtual ~PalindromeStatelessFactory () = default;

	public:
		virtual StatelessWordInverter* build ();
};





#endif // __PALINDROME_HPP__
