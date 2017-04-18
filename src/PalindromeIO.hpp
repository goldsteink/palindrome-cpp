#ifndef __PALINDROME_IO_HPP__
#define __PALINDROME_IO_HPP__

#include <WallarooCppApi/SourceDecoder.hpp>
#include <WallarooCppApi/SinkEncoder.hpp>
using namespace wallaroo;



//**************************************************************************************************
class SingleWord : public Data
{
	private:
		char* _data;

	public:
		SingleWord ( char* data_ );
		virtual ~SingleWord ();

	public:
		size_t getSize ();
		void encode ( char* bytes_ );
};




//**************************************************************************************************
class PalindromeInput : public SourceDecoder
{
	public:
		PalindromeInput ();
		virtual ~PalindromeInput ();

	public:
		virtual const char* name ();
		virtual std::size_t header_length ();
		virtual std::size_t payload_length ( char *bytes_ );
		virtual Data* decode ( char *bytes_ );
};





//**************************************************************************************************
class PalindromeOutput : public SinkEncoder
{
	public:
		PalindromeOutput ();
		virtual ~PalindromeOutput ();

	public:
		virtual size_t get_size ( Data *data_ );
		virtual void encode ( Data *data_, char *bytes_ );
};
#endif // __PALINDROME_IO_HPP__
