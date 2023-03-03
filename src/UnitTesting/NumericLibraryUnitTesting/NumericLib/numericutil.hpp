#ifndef NUMERIC_UTIL_HPP_
#define NUMERIC_UTIL_HPP_

#include "common.hpp"
#include "Point.hpp"

#include <cstddef>

namespace com::anadoluisuzu::util::numeric {
	DLLSPEC bool isPrime(unsigned long val);
	DLLSPEC int getPrime(std::size_t n);
}

#endif //NUMERIC_UTIL_HPP_