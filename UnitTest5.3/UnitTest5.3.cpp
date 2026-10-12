#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3/5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
	TEST_CLASS(UnitTest53)
	{
	public:
		
        TEST_METHOD(Test_H_GreaterOrEqualOne)
        {
            double x = 2.0;

            // Ручний розрахунок: (cos(2) + 1) / (cos^2(2) + 1)
            double expected = (cos(2.0) + 1.0) / (pow(cos(2.0), 2) + 1.0);
            double actual = h(x);

      
            Assert::AreEqual(expected, actual, 0.00001);
        }
        TEST_METHOD(Test_H_LessThanOne)
        {
            double x = 0.5;

            // Ручний розрахунок суми рядка для x = 0.5:
            double sum = 1.0
                + pow(0.5, 2) / 2.0
                + pow(0.5, 4) / 24.0
                + pow(0.5, 6) / 720.0
                + pow(0.5, 8) / 40320.0
                + pow(0.5, 10) / 3628800.0
                + pow(0.5, 12) / 479001600.0;

            double expected = (1.0 / cos(0.5)) * sum;
            double actual = h(x);

            Assert::AreEqual(expected, actual, 0.00001);
        }
	};
}
