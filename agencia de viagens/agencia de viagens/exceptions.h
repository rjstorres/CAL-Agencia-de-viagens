/**
* @file exceptions.h
* @author 
* @title Generic exception class
* @brief Exception class used throughout the project.
*/
#pragma once

#include <string>
typedef unsigned int uint;
using namespace std;

class exception_or_error {
	string reason;
public:
	/**
	*@brief Creates an exception with a given reason.
	*@param reason Reason for exception throw.
	*/
	exception_or_error(string reason) : reason(reason) {};

	/**
	*@brief Gets exception throw's reason.
	*@return Reason for exception throw.
	*/
	string get_reason() { return reason; };
};
