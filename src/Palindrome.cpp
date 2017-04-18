#include "Palindrome.hpp"
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
	LOG(__FUNCTION__);
}





//**************************************************************************************************
// the single word
//**************************************************************************************************
WordInverter* WordInverterFactory::build ()
{
	LOG(__FUNCTION__);
	return new WordInverter();
}
