#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 5.1/Project 5.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            double x = 2.0;
            double y = 3.0;

            // Ручне (очікуване) обчислення за формулою:
            // (x*x + y*y) / (1 + x*x + (x*x)*(y*y))
            // Для (2, 3): (4 + 9) / (1 + 4 + 4 * 9) = 13 / (5 + 36) = 13 / 41 ≈ 0.317073
            double expected = (x * x + y * y) / (1.0 + x * x + (x * x) * (y * y));

            // Виклик вашої функції з коду
            double result = h(x, y);

            // Порівняння з точністю 0.0001
            Assert::AreEqual(expected, result, 0.0001);
        }

        // Додатковий тест з нульовими значеннями
        TEST_METHOD(TestFunctionH_ZeroInput)
        {
            double x = 0.0;
            double y = 0.0;

            // Для (0, 0): (0 + 0) / (1 + 0 + 0) = 0 / 1 = 0.0
            double expected = 0.0;
            double result = h(x, y);

            Assert::AreEqual(expected, result, 0.0001);
        
		}
	};
}
