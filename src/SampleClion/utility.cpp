/*-------------------------------------------------------------------------------------------------
	File Name	: utililty.cpp
	Author		: Oğuz Karan, Anadolu Isuzu
	Last Update	: 10th Oct 2022
	Platform	: All

	Implementation file for utility functions and types

	Copyleft (c) 1993 by C and System Programmers Association (CSD)
	All Rights Free
-------------------------------------------------------------------------------------------------*/

#include <cstddef>
#include <optional>
#include <string>
#include <random>
#include <cstdlib>
#include <bitset>
#include <cstdint>
#include <thread>
#include "csd/utility.hpp"

namespace org::csystem::util::random {
	inline namespace Version1 {
		double randomDouble(double min, double max)
		{
			static std::mt19937 eng{ std::random_device{}() };
			std::uniform_real_distribution<> dist{ min, max };

			return dist(eng);
		}

		int randomInt(int min, int max)
		{
			static std::mt19937 eng{ std::random_device{}() };
			std::uniform_int_distribution<> dist{ min , max };

			return dist(eng);
		}

		bool randomBool()
		{
			static std::mt19937 eng{ std::random_device{}() };
			std::uniform_int_distribution<> dist{ 0 , 1 };

			return dist(eng) == 1;
		}

		std::string randomString(std::size_t count)
		{
			static std::mt19937 eng{ std::random_device{}() };
			std::uniform_int_distribution<> distchar{ 0, 25 };
			std::uniform_int_distribution<> distcapital{ 0, 1 };

			std::string result{};

			while (count--)
				result += static_cast<char>(distchar(eng) + (distcapital(eng) ? 'A' : 'a'));

			return result;
		}


        unsigned char randomChar()
        {
            return static_cast<char>(randomInt(0, 25) + (randomBool() ? 'A' : 'a'));
        }

		double drand(double min, double max)
		{
			static std::mt19937 eng{ std::random_device{}() };
			std::uniform_real_distribution<> dist{ min, max };

			return dist(eng);
		}

		
		int irand(int min, int max)
		{
			static std::mt19937 eng{ std::random_device{}() };
			std::uniform_int_distribution<> dist{ min , max };

			return dist(eng);
		}
	}
}

namespace org::csystem::util::str {
	std::size_t countString(const std::string& s1, const std::string& s2)
	{
		std::size_t count{};

		for (std::size_t idx{}; (idx = s1.find(s2, idx)) != std::string::npos; ++count, ++idx)
			;

		return count;
	}
}

namespace org::csystem::util::convert {
	std::optional<int> toInt(const std::string &s, int base)
    {
        try {
            std::size_t pos;
            auto result = std::stoi(s, &pos, base);

            if (pos != s.length())
                return std::nullopt;

            return result;
        }
        catch (...) {
            return std::nullopt;
        }
    }

	std::optional<long> toLong(const std::string &s, int base)
	{
		try {
		    std::size_t pos;
		    auto result = std::stol(s, &pos, base);

		    if (pos != s.length())
		        return std::nullopt;

		    return result;
		}
		catch (...) {
			return std::nullopt;
		}
	}

	std::optional<float> toFloat(const std::string& s)
	{
	    try {
	        std::size_t pos;
	        auto result = std::stof(s, &pos);

	        if (pos != s.length())
	            return std::nullopt;

	        return result;
	    }
	    catch (...) {
	    	return std::nullopt;
	    }
	}

	std::optional<double> toDouble(const std::string& s)
	{
	    try {
	        std::size_t pos;
	        auto result = std::stod(s, &pos);

	        if (pos != s.length())
	            return std::nullopt;

	        return result;
	    }
	    catch (...) {
			return std::nullopt;
	    }
	}

	std::optional<long double> toLongDouble(const std::string& s)
	{
	    try {
	        std::size_t pos;
	        auto result = std::stold(s, &pos);

	        if (pos != s.length())
	            return std::nullopt;

	        return result;
	    }
	    catch (...) {
	    	return std::nullopt;
	    }
	}
}

namespace org::csystem::util::numeric {
	bool isPrime(int val)
	{
		if (val <= 1)
			return false;

		if (val % 2 == 0)
			return val == 2;

		if (val % 3 == 0)
			return val == 3;

		if (val % 5 == 0)
			return val == 5;

		if (val % 7 == 0)
			return val == 7;

		for (auto i{11}; i * i <= val; i += 2)
			if (val % i == 0)
				return false;

		return true;
	}

	bool isPrime(std::uint64_t val)
	{
		if (val <= 1)
			return false;

		if (val % 2 == 0)
			return val == 2;

		if (val % 3 == 0)
			return val == 3;

		if (val % 5 == 0)
			return val == 5;

		if (val % 7 == 0)
			return val == 7;

		for (std::uint64_t i{ 11 }; i * i <= val; i += 2)
			if (val % i == 0)
				return false;

		return true;
	}
}

namespace org::csystem::util::byte::bitwise {
	using btype = std::bitset<std::numeric_limits<unsigned char>::digits>;

	std::ostream& operator<<(std::ostream& os, std::byte b)
	{
		return os << btype{ std::to_integer<unsigned char>(b) };
	}

	std::istream& operator>>(std::istream& is, std::byte& b)
	{
		btype bt;
		is >> bt;

		if (!is.fail())
			b = std::byte{ static_cast<unsigned char>(bt.to_ulong()) };

		return is;
	}
}
namespace org::csystem::util::threading {
	void sleep(int seconds)
	{
		using std::this_thread::sleep_for;

		sleep_for(std::chrono::seconds(seconds));
	}
}


namespace org::csystem::util::numeric {
    int readInt(const char *msg, const char *errMessage, std::ostream &os, std::istream &is, std::ostream &osErr)
    {
        using namespace std;
        using org::csystem::util::convert::toInt;

        string s;

        for (;;) {
            os << msg;
            is >> s;
            auto opt{toInt(s)};
            if (opt)
                return *opt;

            osErr << errMessage;
        }
    }
}
