/**
 * So this should be a real basic example
 */
#include <StatelessPalindrome.hpp>
#include <exception>
#include <WallarooCppApi/StateChange.hpp>
#include <WallarooCppApi/Application.hpp>
#include <WallarooCppApi/ManagedObject.hpp>

#include "stdinc.hpp"
#include "PalindromeIO.hpp"

using namespace std;
using namespace wallaroo;




extern "C"
{

//----------------------------------------------------------
//
bool buildStatelessApp ( int argc_, char **argv_, Application *application_builder_ )
{
	PalindromeInput* pInput = new PalindromeInput();
	PalindromeOutput* pOutput = new PalindromeOutput();
	PalindromeStatelessFactory* inverterFactory = new PalindromeStatelessFactory();

	Application* theApp = application_builder_->create_application("palindromecpp");
	theApp->new_pipeline("palindrome", pInput);
	theApp->to(inverterFactory);
	theApp->to_sink(pOutput);
	theApp->done();
	return true;
}





bool buildStatefullApp ( int argc_, char **argv_, Application *application_builder_ )
{
	PalindromeInput* pInput = new PalindromeInput();
	PalindromeOutput* pOutput = new PalindromeOutput();
	PalindromeStatelessFactory* inverterFactory = new PalindromeStatelessFactory();

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
	INFO(__PRETTY_FUNCTION__);
	INFO(bytes_);
	ERR("w_serializable_deserialize - call failed! PyApplication wrapper not valid");
	return new SingleWord(bytes_);
}





//----------------------------------------------------------
//
extern wallaroo::Serializable* w_user_serializable_deserialize ( char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);
	WARN(__PRETTY_FUNCTION__);
	w_serializable_deserialize(bytes_);
}





extern bool w_main ( int argc_, char **argv_, Application *application_builder_ )
{
	//return buildStatelessApp(argc_, argv_, application_builder_);
	return buildStatefullApp(argc_, argv_, application_builder_);
}

}
