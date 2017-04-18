/*
 * Author: Kevin A. Goldstein (kevin@sendence.com)
 * 
 * PRJ:     libpy
 * FILE:		stdinc.hpp
 * DSCRPT:	comment
 */


#ifndef __STDINC_HPP__
#define __STDINC_HPP__

#include <iostream>
#include <string>
using namespace std;

const std::string red("\033[31;1m");
const std::string green("\033[32;1m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[36;1m");
const std::string magenta("\033[35;1m");
const std::string reset("\033[0m");



#define ERR(x) (cout << red << __FILE__ << ":" << __LINE__ << " -- " << x << reset << endl)
#define WARN(x) (cout << cyan << __FILE__ << ":" << __LINE__ << " -- " << x << reset << endl)

#ifndef NDEBUG
#define INFO(x) (cout << yellow << x << reset << endl)
#define SUCCESS(x) (cout << green << x << reset << endl)
#define LOG(x) (cout << x << endl)
#else
#define INFO(x) ()
#define SUCCESS(x) ()
#define LOG(x) ()
#endif


#endif // __STDINC_HPP__
