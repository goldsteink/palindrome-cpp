/*
 * Author: Kevin A. Goldstein (kevin@sendence.com)
 * 
 * PRJ:     palindrome-cpp
 * FILE:		StatefullPalindrome.cpp
 * DSCRPT:	comment
 */


#include "StatefullPalindrome.hpp"
#include "stdinc.hpp"





//-------------------------------------------------
StatefullWordInverter::StatefullWordInverter ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
StatefullWordInverter::~StatefullWordInverter ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
const char* StatefullWordInverter::name ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
void* StatefullWordInverter::compute ( Data* input_, StateChangeRepository* state_change_repository_,
		void* state_change_Respository_helper_, State* state_, void* none )
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
size_t StatefullWordInverter::get_number_of_state_change_builders ()
{
	return 1;
}





//-------------------------------------------------
StateChangeBuilder* StatefullWordInverter::get_state_change_builder ( size_t idx_ )
{

}



//**************************************************************************************************
// the single word
//**************************************************************************************************
const char* PalindromeStatefullFactory::name ()
{
}

State* PalindromeStatefullFactory::build ()
{
}





