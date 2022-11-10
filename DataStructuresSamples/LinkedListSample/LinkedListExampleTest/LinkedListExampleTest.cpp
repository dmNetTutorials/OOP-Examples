#include "pch.h"
#include "CppUnitTest.h"
#include"../Main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListExampleTest
{
	TEST_CLASS(LinkedList)
	{
		LinkedList<double> _myList;

	public:
		
		TEST_METHOD_INITIALIZE(AddTest)
		{
		}

		TEST_METHOD(AddTest)
		{

			//LinkedList myList;

			Assert::IsTrue(myList.AddTest());

			auto elem1 = new ListElement<double>();

			elem1->Value = 1.0;

			auto elem2 = new ListElement<double>();

			elem2->Value = 2.0;

			auto elem3 = new ListElement<double>();

			elem3->Value = 3.0;

			auto add = bool (*ptrToAdd) (ListElement<double>);

		}
	};
}
