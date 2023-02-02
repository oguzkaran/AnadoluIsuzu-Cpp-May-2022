#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "numericutil.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumericLibTest
{	
	static std::vector<unsigned long> g_trueValues;	
	static std::vector<unsigned long> g_falseValues;

	TEST_CLASS(NumericLibTest)
	{		
	public:
		static void loadTrueValues()
		{
			std::ifstream ft{ "C:\\primes.txt", std::ios::in };

			Assert::IsTrue(static_cast<bool>(ft));
			int count;

			ft >> count;

			for (auto i{ 0 }; i < count; ++i) {
				unsigned long val;

				ft >> val;
				g_trueValues.push_back(val);
			}

			Assert::AreEqual(static_cast<size_t>(count), g_trueValues.size());

			ft.close();
		}

		static void loadFalseValues()
		{
			std::ifstream ff{ "C:\\notprimes.txt", std::ios::in };

			Assert::IsTrue(static_cast<bool>(ff));
			int count;

			ff >> count;

			for (auto i{ 0 }; i < count; ++i) {
				unsigned long val;

				ff >> val;
				g_falseValues.push_back(val);
			}

			Assert::AreEqual(static_cast<size_t>(count), g_falseValues.size());

			ff.close();
		}

		TEST_CLASS_INITIALIZE(SetUp)
		{
			loadTrueValues();
			loadFalseValues();			
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(IsPrimeTrueTest1)
			TEST_METHOD_ATTRIBUTE(L"GROUP", L"Anadolu Isuzu")
			TEST_OWNER(L"Çaðlar Yalçýn")			
		END_TEST_METHOD_ATTRIBUTE()			
		TEST_METHOD(IsPrimeTrueTest1)
		{
			using com::anadoluisuzu::util::numeric::isPrime;						
			using namespace std;
			
			for_each(begin(g_trueValues), end(g_trueValues), [](auto val) {Assert::IsTrue(isPrime(val)); });
		}


		BEGIN_TEST_METHOD_ATTRIBUTE(IsPrimeTrueTest2)
			TEST_METHOD_ATTRIBUTE(L"GROUP", L"Anadolu Isuzu")
			TEST_OWNER(L"Sefa Beker")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(IsPrimeTrueTest2)
		{
			using com::anadoluisuzu::util::numeric::isPrime;

			unsigned long val = 2;

			Assert::IsTrue(isPrime(val));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(IsPrimeFalseTest)
			TEST_METHOD_ATTRIBUTE(L"GROUP", L"CSD")
			TEST_OWNER(L"Oðuz Karan")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(IsPrimeFalseTest)
		{
			using com::anadoluisuzu::util::numeric::isPrime;
			using namespace std;

			for_each(begin(g_falseValues), end(g_falseValues), [](auto val) {Assert::IsFalse(isPrime(val)); });
		}
	};
}
