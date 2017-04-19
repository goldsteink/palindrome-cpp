#include "Palindrome.hpp"
#include "PalindromeIO.hpp"
#include "stdinc.hpp"
#include <cstring>
using namespace std;


//**************************************************************************************************
// the single word
//**************************************************************************************************
WordInverter::WordInverter ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------

WordInverter::~WordInverter ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------

const char* WordInverter::name ()
{
	LOG(__PRETTY_FUNCTION__);
	return "WordInverter";
}





//-------------------------------------------------

Data* WordInverter::compute ( Data* input_ )
{
	SUCCESS(__PRETTY_FUNCTION__);
	
	
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
	delete sword;
	
	
	//
	// done
	//
	return output;
}





//**************************************************************************************************
// the single word
//**************************************************************************************************
WordInverter* WordInverterFactory::build ()
{
	LOG(__PRETTY_FUNCTION__);
	return new WordInverter();
}
