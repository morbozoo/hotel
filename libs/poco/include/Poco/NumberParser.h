//
// NumberParser.h
//
// $Id: //poco/1.4/Foundation/include/Poco/NumberParser.h#1 $
//
// Library: Foundation
// Package: Core
// Module:  NumberParser
//
// Definition of the NumberParser class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_NumberParser_INCLUDED
#define Foundation_NumberParser_INCLUDED


#include "Poco/Foundation.h"


namespace Poco {


class Foundation_API NumberParser
	/// The NumberParser class provides static methods
	/// for parsing numbers out of strings.
{
public:
	static int parse(const std::string& s);
		/// Parses an integer value in decimal notation from the given string.
		/// Throws a SyntaxException if the string does not hold a number in decimal notation.
	
	static bool tryParse(const std::string& s, int& value);
		/// Parses an integer value in decimal notation from the given string.
		/// Returns true if a valid integer has been found, false otherwise. 
	
	static unsigned parseUnsigned(const std::string& s);
		/// Parses an unsigned integer value in decimal notation from the given string.
		/// Throws a SyntaxException if the string does not hold a number in decimal notation.

	static bool tryParseUnsigned(const std::string& s, unsigned& value);
		/// Parses an unsigned integer value in decimal notation from the given string.
		/// Returns true if a valid integer has been found, false otherwise. 

	static unsigned parseHex(const std::string& s);
		/// Parses an integer value in hexadecimal notation from the given string.
		/// Throws a SyntaxException if the string does not hold a number in
		/// hexadecimal notation.

	static bool tryParseHex(const std::string& s, unsigned& value);
		/// Parses an unsigned integer value in hexadecimal notation from the given string.
		/// Returns true if a valid integer has been found, false otherwise. 

#if defined(POCO_HAVE_INT64)

	static Int64 parse64(const std::string& s);
		/// Parses a 64-bit integer value in decimal notation from the given string.
		/// Throws a SyntaxException if the string does not hold a number in decimal notation.

	static bool tryParse64(const std::string& s, Int64& value);
		/// Parses a 64-bit integer value in decimal notation from the given string.
		/// Returns true if a valid integer has been found, false otherwise. 

	static UInt64 parseUnsigned64(const std::string& s);
		/// Parses an unsigned 64-bit integer value in decimal notation from the given string.
		/// Throws a SyntaxException if the string does not hold a number in decimal notation.

	static bool tryParseUnsigned64(const std::string& s, UInt64& value);
		/// Parses an unsigned 64-bit integer value in decimal notation from the given string.
		/// Returns true if a valid integer has been found, false otherwise. 

	static UInt64 parseHex64(const std::string& s);
		/// Parses a 64 bit-integer value in hexadecimal notation from the given string.
		/// Throws a SyntaxException if the string does not hold a number in hexadecimal notation.

	static bool tryParseHex64(const std::string& s, UInt64& value);
		/// Parses an unsigned 64-bit integer value in hexadecimal notation from the given string.
		/// Returns true if a valid integer has been found, false otherwise. 

#endif // defined(POCO_HAVE_INT64)

	static double parseFloat(const std::string& s);
		/// Parses a double value in decimal floating point notation
		/// from the given string. 
		/// Throws a SyntaxException if the string does not hold a floating-point 
		/// number in decimal notation.
		
	static bool tryParseFloat(const std::string& s, double& value);
		/// Parses a double value in decimal floating point notation
		/// from the given string. 
		/// Returns true if a valid floating point number has been found, 
		/// false otherwise. 
};


} // namespace Poco


#endif // Foundation_NumberParser_INCLUDED
