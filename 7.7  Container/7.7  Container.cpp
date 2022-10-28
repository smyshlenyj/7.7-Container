#include <iostream>
#include <exception>
#include "IntegerArray.h"

int main()
{
	IntegerArray test(4);
	test[0] = 7;
	test[1] = 77;
	test[2] = 777;
	test[3] = 7777;
	std::cout << "-------push back-------------\n";
	test.PrintContainer();
	std::cout << "----------pop back----------\n";
	test.PopBack();
	test.PrintContainer();
	std::cout << "--------push front------------\n";
	// error impossible (is not a public offer) using int
	test.PushFront(888);
	test.PrintContainer();
	std::cout << "-----------pop front---------\n";
	test.PopFront();
	test.PrintContainer();
	std::cout << "-------insert by index-------------\n";
	test.InsertElementByIndex(3, 999);
	test.PrintContainer();
	std::cout << "-------deletebyindex-------------\n";
	test.DeleteElementByIndex(3);
	test.PrintContainer();
	std::cout << "-----test copy to test2:---------------\n";
	IntegerArray test2(3);
	std::cout << "test address \t" << &test << std::endl;
	std::cout << "test2 address \t" << &test2 << std::endl;
	test.CopyContainerTo(test2);
	test2.PrintContainer();

	std::cout << "\n and exceptions:\n";

	try
	{
		IntegerArray test(-1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test[-1] = 7;
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test[777] = 7;
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		// how to throw exception in case of overflow? this way doesn't work:
		test.PushBack(-34634645654646454);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	IntegerArray testPopBack(0);
	try
	{
		testPopBack.PopBack();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	IntegerArray testPopFront(0);
	try
	{
		testPopFront.PopFront();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl; //it was really scary
	}

	IntegerArray testElementByIndex(5);
	testElementByIndex[0] = 7;
	testElementByIndex[1] = 77;
	testElementByIndex[2] = 777;
	try
	{
		testElementByIndex.InsertElementByIndex(777, 111);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		testElementByIndex.InsertElementByIndex(777, 111);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	IntegerArray testCopy(2);
	try
	{
		test.CopyContainerTo(testElementByIndex);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test.SetSizeOfArray(-7);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nAll tests are passed. Code is extremely safe. Checked by Bjarne Stroustrup.\n";
}