/*-------------------------------------------------------------------------------------------------
	File Name	: utility.hpp
	Author		: Oğuz Karan
	Last Update	: 07th Nov.2022
	Platform	: All

	Header file for utility functions and types

	Copyleft (c) 1993 by C and System Programmers Association (CSD)
	All Rights Free
-------------------------------------------------------------------------------------------------*/

#ifndef CSDUTILITY_HPP_
#define CSDUTILITY_HPP_

#include <optional>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <deque>
#include <utility>
#include <vector>
#include <map>
#include <any>
#include <algorithm>
#include <iterator>


template <int index, int n, typename...Args>
struct WriteTuple {
    static void write(std::ostream& os, const std::tuple<Args...>& rt)
    {
        os << std::get<index>(rt) << (n == index + 1 ? "" : ", ");
        WriteTuple<index + 1, n, Args...>::write(os, rt);
    }
};

template <int n, typename...Args>
struct WriteTuple<n, n, Args...> {
    static void write(std::ostream& os, const std::tuple<Args...>& rt)
    {

    }
};

template <typename...Args>
std::ostream& operator <<(std::ostream& os, const std::tuple<Args...>& rt)
{
    os << "(";
    WriteTuple<0, sizeof ...(Args), Args...>::write(os, rt);

    return os << ")";
}


template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
    return os << "{" << p.first << ", " << p.second << "}";
}


template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N> &a)
{
    for (const auto& t : a)
        os << t << ' ';

    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T> &lst)
{
    for (const auto& t : lst)
        os << t << ' ';

    return os;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (const auto& t : vec)
        os << t << ' ';

    return os;
}

namespace org::csystem::util::property {
	struct Property {
		std::string name;
		std::any value;

		Property() = default;
		Property(std::string name, std::any value) : name{ std::move(name) }, value{std::move( value )}
		{}
	};

	using Properties = std::deque<Property>;

    template <typename Key = std::string>
    using PropertyMap = std::map<Key, Property>;
}

namespace org::csystem::util::random {
	inline namespace Version1 {
		[[nodiscard]] double randomDouble(double min = 0, double max = 1);
		[[nodiscard]] int randomInt(int min = 0, int max = RAND_MAX);
		[[nodiscard]] bool randomBool();
		[[nodiscard]] std::string randomString(std::size_t count);
        [[nodiscard]] unsigned char randomChar();

		[[nodiscard]]
		[[deprecated("use randomDouble function instead")]]
		double drand(double min = 0, double max = 1);
		
		[[nodiscard]]
		[[deprecated("use randomInt function instead")]]
		int irand(int min = 0, int max = RAND_MAX);
	}
}

namespace org::csystem::util::str {
	[[nodiscard]]std::size_t countString(const std::string& s1, const std::string& s2);
}

namespace org::csystem::util::convert {
    [[nodiscard]] std::optional<int> toInt(const std::string& s, int base = 10);
	[[nodiscard]] std::optional<long> toLong(const std::string& s, int base = 10);
	[[nodiscard]] std::optional<float> toFloat(const std::string& s);
	[[nodiscard]] std::optional<double> toDouble(const std::string& s);
	[[nodiscard]] std::optional<long double> toLongDouble(const std::string& s);
}

namespace org::csystem::util::numeric {
	[[nodiscard]] bool isPrime(int val);
	[[nodiscard]] bool isPrime(std::uint64_t val);
}

namespace org::csystem::util {
	template <typename T>
	constexpr std::ostream& write(std::ostream& os, const char* psep, const T& t)
	{
		return os << t;
	}

	template <typename T, typename...Ts>
	constexpr std::ostream& write(std::ostream& os, const char* psep, const T& t, const Ts& ...rest)
	{
		os << t << psep;

		return write(os, psep, rest...);
	}

	template <typename T>
	constexpr T sum(T t)
	{
		return t;
	}

	template <typename T, typename...Args>
	constexpr T sum(const T& t, const Args&...args)
	{
		return t + sum(args...);
	}
}


namespace org::csystem::util::algorithm {
    template<std::size_t N, typename RandIt>
    void csdShuffle(RandIt first, RandIt last, std::size_t count = N)
    {
        using org::csystem::util::random::randomInt;

        auto n{std::distance(first, last)};

        for (std::size_t i{}; i < count; ++i) {
            auto idx1{randomInt(0, static_cast<int>(n - 1))};
            auto idx2{randomInt(0, static_cast<int>(n - 1))};

            std::iter_swap(std::next(first, idx1), std::next(first, idx2));
        }
    }
}

namespace org::csystem::util::container {
	/*Template function definitions*/
	template <typename C, typename F>
	C& fillContainer(C& c, std::size_t n, F f)
	{
		for (std::size_t i{}; i < n; ++i)
			c.insert(c.end(), f());

		return c;
	}

	template <typename OutIt, typename F>
	void fillContainer(OutIt first, OutIt last, F f)
	{
		for (auto iter{ first }; iter != last; ++iter)
			*iter = f();
	}

	template <typename InIt>
	void write(InIt first, InIt last, std::ostream& os = std::cout, const char *psep = " ", const char *pend = "\n")
	{
		for (auto iter{first}; iter != last; ++iter)
			os << *iter << psep;

		os << pend;
	}
}

namespace org::csystem::util::arr {
	template <std::size_t size>
	[[nodiscard]]std::array<int, size> randomIntArray(int min = 0, int max = RAND_MAX)
	{
		using namespace std;
		using org::csystem::util::random::randomInt;

		array<int, size> a;

		for (auto &r : a)
			r = randomInt(min, max);

		return a;
	}

	template <std::size_t size>
    [[nodiscard]]std::array<double, size> randomDoubleArray(double min = 0, double max = 1)
	{
		using namespace std;		
		array<double, size> a;

		using org::csystem::util::random::randomDouble;

		for (auto& r : a)
			r = randomDouble(min, max);

		return a;
	}

	template <typename T, std::size_t size>
	void write(const std::array<T, size>& a)
	{
		for (const auto& r : a)
			std::cout << r << ' ';

		std::cout << '\n';
	}
}

namespace org::csystem::util::byte::bitwise {
    std::ostream &operator<<(std::ostream &os, std::byte b);

    std::istream &operator>>(std::istream &is, std::byte &b);
}


namespace org::csystem::util::threading {
	void sleep(int seconds);
}

namespace org::csystem::util::numeric {
    [[nodiscard]]
    int readInt(const char *msg = "", const char *errMessage = "", std::ostream &os = std::cout,
                std::istream &is = std::cin, std::ostream &osErr = std::cerr);
}

#endif // CSDUTILITY_HPP_

