#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.2.a.cpp"  // Assuming the student's code is in StudentFunctions.h

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// Test for the CalculateAverage function
		TEST_METHOD(TestCalculateAverage)
		{
			Student student = { "Ivanov", 1, COMPUTER_SCIENCE, 90, 85, 95 };
			double expectedAverage = (90 + 85 + 95) / 3.0;
			Assert::AreEqual(expectedAverage, CalculateAverage(student), 0.01, L"Average calculation is incorrect");
		}
	};
}
