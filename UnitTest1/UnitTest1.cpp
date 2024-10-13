#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6_3_it/lab_6_3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMinOdd)
        {
            int a[10] = { 2, 4, 1, 3, 5, 8, 10, 12, 13, 14 };
            Assert::AreEqual(1, Min(a, 10)); 

            int b[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
            
            Assert::AreEqual(0, Min(b, 10));
        }

        TEST_METHOD(TestMinNegativeOdd)
        {
            int c[10] = { -2, -4, -1, -3, -5, -8, -10, -12, -13, -14 };
            Assert::AreEqual(-13, Min(c, 10)); 
        }
    };
}