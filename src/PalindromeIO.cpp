#include "PalindromeIO.hpp"
#include "stdinc.hpp"
#include <cstring>
#include <sstream>
using namespace std;



//**************************************************************************************************
// the single word
//**************************************************************************************************
//-------------------------------------------------
SingleWord::SingleWord ( char* data_ ) :
			_data(nullptr),
			_dSz(0)
{
	LOG(__PRETTY_FUNCTION__);
	if (data_ == nullptr)
	{
		WARN("received empty data in constructor!");
		return;
	}

	//
	// copy in the data
	//
	_dSz = strlen(data_);
	deserialize(data_);
	INFO("SZ:" << _dSz <<",data:[" << _data <<"]");
}





//-------------------------------------------------
SingleWord::SingleWord ( char* data_, int len_ ) :
			_data(nullptr),
			_dSz(len_)
{
	LOG(__PRETTY_FUNCTION__);
	if (data_ == nullptr)
	{
		WARN("received empty data in constructor!");
		return;
	}

	//
	// copy in the data
	//
	deserialize(data_);
	INFO("SZ:" << _dSz <<",data:[" << _data <<"]");
}





//-------------------------------------------------
SingleWord::~SingleWord ()
{
	LOG(__PRETTY_FUNCTION__);
	if (_data != nullptr)
	{
		delete[] _data;
		_data = nullptr;
	}
}





//-------------------------------------------------
size_t SingleWord::serialize_get_size ()
{
	LOG(__PRETTY_FUNCTION__);
	if (_data == nullptr)
	{
		return 0;
	}

	return _dSz;
}





//-------------------------------------------------
void SingleWord::serialize ( char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);
	int ln = strlen(_data);
	strncpy(bytes_, _data, ln);
}





//-------------------------------------------------
void SingleWord::deserialize ( char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);
	_data = new char[_dSz + 1];
	strncpy(_data, bytes_, _dSz);
	_data[_dSz] = '\0';
}




//-------------------------------------------------
SingleWord* SingleWord::reverse ()
{
	//
	// make sure im valid
	//
	if (_data == nullptr)
	{
		string err = "Reverse called with no data initialized";
		ERR(err);
		throw new runtime_error(err);
	}


	//
	// reverse my data
	//
	int len = _dSz - 1;
	char* rhsData = new char[_dSz + 1];
	for (int i = len; i >= 0; i--)
	{
		rhsData[len - i] = _data[i];
	}



	//
	// pass out new object
	//
	return new SingleWord(rhsData, _dSz);
}





//-------------------------------------------------
const char* SingleWord::getData ()
{
	return const_cast<const char*>(_data);
}





//**************************************************************************************************
// the decoder
//**************************************************************************************************
//-------------------------------------------------
PalindromeInput::PalindromeInput () :
			_currSz(0)
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
PalindromeInput::~PalindromeInput ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
const char* PalindromeInput::name ()
{
	LOG(__PRETTY_FUNCTION__);
	return "PalindromeDecoder";
}





//-------------------------------------------------
size_t PalindromeInput::header_length ()
{
	LOG(__PRETTY_FUNCTION__);
	return sizeof(char);
}





//-------------------------------------------------
size_t PalindromeInput::payload_length ( char* bytes_ )
{
	int ln = strlen(bytes_);
	short sz = 0;
	memcpy((char*) &sz, bytes_, sizeof(char));
	_currSz = sz;
	return sz;
}





//-------------------------------------------------
Data* PalindromeInput::decode ( char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);
	SingleWord* sword = new SingleWord(bytes_, _currSz);
	return sword;
}





//**************************************************************************************************
// the decoder
//**************************************************************************************************
//-------------------------------------------------
PalindromeOutput::PalindromeOutput ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
PalindromeOutput::~PalindromeOutput ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
size_t PalindromeOutput::get_size ( Data* data_ )
{
	LOG(__PRETTY_FUNCTION__);





	//
	// make sure I can work with it
	//
	SingleWord* sword = dynamic_cast<SingleWord*>(data_);
	if (sword != nullptr)
	{
		INFO("OutputSz:" << sword->serialize_get_size());
		return sword->serialize_get_size();
	}





	//
	// done
	//
	WARN("Was unable to convert data to SingleWord, returning 0");
	return 0;
}





//-------------------------------------------------
void PalindromeOutput::encode ( Data* data_, char* bytes_ )
{
	LOG(__PRETTY_FUNCTION__);


	//
	// make sure I can work with it
	//
	SingleWord* sword = dynamic_cast<SingleWord*>(data_);
	if (sword == nullptr)
	{
		ERR("Unable to cast Data into SingleWord!");
		return;
	}




	//
	// work on it!
	//
	sword->serialize(bytes_);
	INFO("Serialized: " << bytes_);
	delete data_;




	//
	// done
	//
	return;
}

