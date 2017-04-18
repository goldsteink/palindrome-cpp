/**
 * Kevin A. Goldstein R. (kevgol0@gmail.com)
 *
 * FILE:   StatefullPalindrome.hpp
 * DSCRPT: comment
 */

#ifndef __STATEFULLPALINDROME_HPP__
#define __STATEFULLPALINDROME_HPP__


#include <WallarooCppApi/Computation.hpp>
using namespace wallaroo;



class StatefullWordInverter : public StateComputation
{
	private:

	public:
		StatefullWordInverter ();
		virtual ~StatefullWordInverter ();

	public:
		virtual const char *name ();
		virtual void *compute ( Data *input_, StateChangeRepository *state_change_repository_,
				void* state_change_Respository_helper_, State *state_, void *none );
		virtual size_t get_number_of_state_change_builders ();
		virtual StateChangeBuilder *get_state_change_builder ( size_t idx_ );
};





//**************************************************************************************************
class WordInverterStateChangeFactory : public StateChangeBuilder
{
	public:
		WordInverterStateChangeFactory () = default;
		virtual ~WordInverterStateChangeFactory () = default;

	public:
		virtual StateChange *build ( uint64_t idx_ )
		{
			return nullptr;
		}
};





//**************************************************************************************************
class PalindromeStatefullFactory : public StateBuilder
{
	public:
		PalindromeStatefullFactory () = default;
		virtual ~PalindromeStatefullFactory () = default;

	public:
		virtual const char *name ();
		virtual State *build ();
};




#endif /* __STATEFULLPALINDROME_HPP__ */
