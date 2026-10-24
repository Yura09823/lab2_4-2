#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../lab2_4_2/Model.h"
#include "../lab2_4_2/Model.cpp"
#include "../lab2_4_2/PriceList.h"
#include "../lab2_4_2/PriceList.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Model m1("Asus", "Intel_i7", 3.2, 16, 512, 4, 1000, 5);

			Assert::AreEqual(std::string("Asus"), m1.getBrand());
			Assert::AreEqual(16, m1.getRam());
			Assert::AreEqual(1000.0, m1.getPrice());

			m1.setPrice(1200.0);
			Assert::AreEqual(1200.0, m1.getPrice());
		}
	};
}
