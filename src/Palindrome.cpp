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
	LOG(__FUNCTION__);
}





//-------------------------------------------------

WordInverter::~WordInverter ()
{
	LOG(__FUNCTION__);
}





//-------------------------------------------------

const char* WordInverter::name ()
{
	LOG(__FUNCTION__);
	return "WordInverter";
}





//-------------------------------------------------

Data* WordInverter::compute ( Data* input_ )
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
WordInverter* WordInverterFactory::build ()
{
	LOG(__FUNCTION__);
	return new WordInverter();
}
