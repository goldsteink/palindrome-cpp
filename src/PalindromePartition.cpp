/*
 * Author: Kevin A. Goldstein (kevin@sendence.com)
 * 
 * PRJ:     palindrome-cpp
 * FILE:		StatefullPalindrome.cpp
 * DSCRPT:	comment
 */


#include "PalindromePartition.hpp"
#include "stdinc.hpp"



//**************************************************************************************************
// the partition key
//**************************************************************************************************
uint64_t PKey::hash ()
{
	return 0;
}




bool PKey::eq ( Key* other_ )
{
	return true;
}





//**************************************************************************************************
// Partition Function 
//**************************************************************************************************
PalindromePartitionFunction::PalindromePartitionFunction ( PKey* key_ ) :
			_theKey(key_)
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
PalindromePartitionFunction::~PalindromePartitionFunction ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
Key* PalindromePartitionFunction::partition ( Data* data_ )
{
	INFO(__PRETTY_FUNCTION__);
	return _theKey;
}




//**************************************************************************************************
// the actual partition - will only have one key
//**************************************************************************************************
PalindromePartition::PalindromePartition () :
			_partitionKey(nullptr),
			_pFunction(nullptr)
{
	_partitionKey = new PKey();
	_pFunction = new PalindromePartitionFunction(_partitionKey);
	LOG(__PRETTY_FUNCTION__);
}



PalindromePartition::~PalindromePartition ()
{
	LOG(__PRETTY_FUNCTION__);
}





//-------------------------------------------------
PartitionFunction* PalindromePartition::get_partition_function ()
{
	LOG(__PRETTY_FUNCTION__);
	return _pFunction;
}





//-------------------------------------------------
size_t PalindromePartition::get_number_of_keys ()
{
	LOG(__PRETTY_FUNCTION__);
	return 1;
}





//-------------------------------------------------
Key* PalindromePartition::get_key ( size_t idx_ )
{
	LOG(__PRETTY_FUNCTION__);
	return _partitionKey;
}
