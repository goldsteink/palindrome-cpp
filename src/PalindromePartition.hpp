/**
 * Kevin A. Goldstein R. (kevgol0@gmail.com)
 *
 * FILE:   StatefullPalindrome.hpp
 * DSCRPT: comment
 */

#ifndef __PALINDROME_PARTITION_HPP__
#define __PALINDROME_PARTITION_HPP__


#include <WallarooCppApi/Partition.hpp>
#include <WallarooCppApi/Key.hpp>
#include <WallarooCppApi/Data.hpp>

using namespace wallaroo;





//**************************************************************************************************
class PKey : public Key
{
	public:
		PKey () = default;
		virtual ~PKey () = default;

	public:
		virtual uint64_t hash ();
		virtual bool eq ( Key *other_ );
};





//**************************************************************************************************
class PalindromePartitionFunction : public PartitionFunction
{
	private:
		PKey* _theKey; 

	public:
		PalindromePartitionFunction (PKey* key_);
		virtual ~PalindromePartitionFunction ();

	public:
		virtual Key* partition ( Data *data_ );

};





//**************************************************************************************************
class PalindromePartition : public Partition
{
	private:
		PKey* _partitionKey;
		PalindromePartitionFunction* _pFunction;

	public:
		PalindromePartition ();
		virtual ~PalindromePartition ();

	public:
		virtual PartitionFunction *get_partition_function ();
		virtual size_t get_number_of_keys ();
		virtual Key *get_key ( size_t idx_ );
};


#endif /* __PALINDROME_PARTITION_HPP__ */
