#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_2/Lab_12_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab122
{
	TEST_CLASS(UnitTestLab122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 20;
			Elem *first = NULL, *last = NULL;
			for (int i = 20; i >= 0; i -= 2)
				LAdd(first, last, i);
			LRemove(first, 6);
			while (first != NULL)
			{
				Assert::AreEqual(first->info, k);
				first = first->link; k -= 2;
			}
		}
	};
}
