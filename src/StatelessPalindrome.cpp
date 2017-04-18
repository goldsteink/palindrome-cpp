#include <StatelessPalindrome.hpp>

#include "PalindromeIO.hpp"
#include "stdinc.hpp"
#include <cstring>
using namespace std;


//**************************************************************************************************
// the single word
//**************************************************************************************************
StatelessWordInverter::StatelessWordInverter ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------

StatelessWordInverter::~StatelessWordInverter ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------

const char* StatelessWordInverter::name ()
{
	LOG(__PRETTY_FUNCTION__);
	return "WordInverter";
}





//-------------------------------------------------
Data* StatelessWordInverter::compute ( Data* input_ )
{
	WARN(__PRETTY_FUNCTION__);
	
	
	//
	// make sure I can work with it
	//
	SingleWord* sword = dynamic_cast<SingleWord*>(input_);
	if (sword==nullptr)
	{
		ERR("Data type not convertible");
		return nullptr;
	}
	
	
	
	//
	// reverse & log
	//
	SingleWord* output = sword->reverse();
	INFO(output->getData());
	
	
	
	//
	// done
	//
	return sword;
}





//**************************************************************************************************
// the single word
//**************************************************************************************************
StatelessWordInverter* PalindromeStatelessFactory::build ()
{
	LOG(__PRETTY_FUNCTION__);
	return new StatelessWordInverter();
}
