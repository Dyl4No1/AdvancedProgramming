#pragma once

#include <cstdio>
#include <string>
#include <cassert>

template< typename... Args >
std::string sfmt(const char* format, Args... args) {
	int length = std::snprintf(nullptr, 0, format, args...);
	assert(length >= 0);

	char* buf = new char[length + 5];
	std::snprintf(buf, length + 5, format, args...);

	std::string str(buf);
	delete[] buf;
	return str;
}