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
		int _dSz;

	public:
		SingleWord ( char* data_ );
		SingleWord ( char* data_, int sz_ );
		virtual ~SingleWord ();

	public:
		SingleWord* reverse ();
		const char* getData ();

	public:
		virtual void serialize ( char* bytes_ );
		virtual void deserialize (char* bytes_);
		virtual size_t serialize_get_size ();
};




//**************************************************************************************************
class PalindromeInput : public SourceDecoder
{
	private:
		int _currSz;

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
