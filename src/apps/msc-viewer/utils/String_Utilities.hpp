/**
 * @file   String_Utilities.hpp
 * @author Marvin Smith
 * @date   3/11/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_UTILS_STRING_UTILITIES_HPP__
#define __MSC_APPS_MSC_VIEWER_UTILS_STRING_UTILITIES_HPP__

// C++ Libraries
#include <string>
#include <vector>

/**
 * @brief Trim a String
 *
 * @param[in] str
 *
 * @return Trimmed string.
*/
std::string String_Trim( const std::string& str );


/**
 * @brief Split a String based on a pattern.
 *
 * @param[in] str Input string
 * @param[in] pattern Pattern to match.
 *
 * @return Resulting matches.
*/
std::vector<std::string> String_Split( const std::string& str, 
                                       const std::string& pattern );

#endif
