/**
 * So this should be a real basic example
 */
#include <exception>
#include <WallarooCppApi/StateChange.hpp>
#include <WallarooCppApi/Application.hpp>
#include <WallarooCppApi/ManagedObject.hpp>

#include "stdinc.hpp"
#include "Palindrome.hpp"
#include "PalindromeIO.hpp"

using namespace std;
using namespace wallaroo;




extern "C"
{


void usage ( const char* prog_ )
{
	cerr << prog_ << " PATH MOD" << endl;
	cerr << "\tPATH: Fully qualified path where your python module lives" << endl;
	cerr << "\tMOD: Python moodule name (without the .py extnsion)" << endl;
	return;
}


//----------------------------------------------------------
//
extern bool w_main ( int argc_, char **argv_, Application *application_builder_ )
{
	PalindromeInput* pInput = new PalindromeInput();
	PalindromeOutput* pOutput = new PalindromeOutput();
	WordInverterFactory* inverterFactory = new WordInverterFactory();

	Application* theApp = application_builder_->create_application("palindromecpp");
	theApp->new_pipeline("palindrome", pInput);
	theApp->to(inverterFactory);
	theApp->to_sink(pOutput);
	theApp->done();
	return true;
}





//----------------------------------------------------------
//
extern wallaroo::Serializable* w_serializable_deserialize ( char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);
	INFO(bytes_);
	ERR("w_serializable_deserialize - call failed! PyApplication wrapper not valid");
	return nullptr;
}





//----------------------------------------------------------
//
extern wallaroo::Serializable* w_user_serializable_deserialize ( char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);
	w_serializable_deserialize(bytes_);
}



}
