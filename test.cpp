#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication\ConsoleApplication.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_Empty)
		{
			List list;
			Assert::IsTrue(list.isEmpty());
			List list1;
			list1.push_back(1);
			Assert::IsTrue(list1.at(0) == 1);
			Assert::IsFalse(list1.isEmpty());
			List list2;
			list2.push_back(1);
			list2.remove(0);
			Assert::IsTrue(list2.isEmpty());
		}
		TEST_METHOD(Test_Push_Back)
		{
			List list; // 0 1 2 3 4
			for (int counter=0; counter<5; counter++)
			{
				list.push_back(counter);
			}
			Assert::AreEqual(list.at(0), 0);
			Assert::AreEqual(list.at(1), 1);
			Assert::AreEqual(list.at(2), 2);
			Assert::AreEqual(list.at(3), 3);
			Assert::AreEqual(list.at(4), 4);
			List list2;
			list2.push_back(1);
			Assert::AreEqual(list2.at(0), 1);
		}
		TEST_METHOD(Test_Push_Front)
		{
			List list; // 4 3 2 1 0
			for (int counter = 0; counter < 5; counter++)
			{
				list.push_front(counter);
			}
			Assert::AreEqual(list.at(0), 4);
			Assert::AreEqual(list.at(1), 3);
			Assert::AreEqual(list.at(2), 2);
			Assert::AreEqual(list.at(3), 1);
			Assert::AreEqual(list.at(4), 0);
			List list2;
			list2.push_back(1);
			Assert::AreEqual(list2.at(0), 1);
		}
		TEST_METHOD(Test_Pop_Front)
		{
			List list;
			list.push_back(1);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
			List list2; // 0 1 2 3 4
			int size;
			for (int counter = 0; counter < 5; counter++)
			{ list2.push_back(counter); }
			list2.pop_front(); // 1 2 3 4 
			size = list2.get_size();
			Assert::AreEqual(size, 4);
			Assert::AreEqual(list2.at(0), 1);
			List list3;
			bool check = 0;
			list3.pop_front();
			if (list3.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_Pop_Back)
		{
			List list;
			list.push_back(1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty());
			List list2; // 4 3 2 1 0
			int size;
			for (int counter = 0; counter < 5; counter++)
			{
				list2.push_front(counter);
			}
			list2.pop_back();// 4 3 2 1
			size = list2.get_size();
			Assert::AreEqual(size, 4);
			Assert::AreEqual(list2.at(0), 4);
			List list3;
			bool check = 0;
			list3.pop_back();
			if (list3.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_Insert_Node)
		{
			List list;
			list.insert_Node(5, 0);
			Assert::AreEqual(list.at(0), 5);
			List list2;
			for (int counter = 0; counter < 5; counter++)
			{
				list2.insert_Node(counter+1, counter);
			}
			list2.insert_Node(7, 3);
			Assert::AreEqual(list2.at(0), 1);
			Assert::AreEqual(list2.at(1), 2);
			Assert::AreEqual(list2.at(2), 3);
			Assert::AreEqual(list2.at(3), 7);
			Assert::AreEqual(list2.at(4), 4);
			Assert::AreEqual(list2.at(5), 5);
			List list3;
			bool check = 0;
			list3.insert_Node(5, 1);
			if (list3.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_At)
		{
			List list;
			bool check = 0;
			list.at(1);
			if (list.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
			List list2;
			for (int counter = 0; counter < 5; counter++)
			{
				list2.insert_Node(counter + 1, counter);
			}
			Assert::AreEqual(list2.at(0), 1);
			Assert::AreEqual(list2.at(1), 2);
			Assert::AreEqual(list2.at(2), 3);
			Assert::AreEqual(list2.at(3), 4);
			Assert::AreEqual(list2.at(4), 5);
		}
		TEST_METHOD(Test_Remove)
		{
			List list;
			bool check = 0;
			list.remove(1);
			if (list.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
			List list2; // 0 1 2 3 4
			for (int counter = 0; counter < 5; counter++)
			{
				list2.push_back(counter);
			}
			list2.remove(2); // 0 1 3 4
			Assert::AreEqual(list2.at(0), 0);
			Assert::AreEqual(list2.at(1), 1);
			Assert::AreEqual(list2.at(2), 3);
			Assert::AreEqual(list2.at(3), 4);
			List list3;
			list3.push_back(5);
			list3.remove(0);
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(Test_Get_Size)
		{
			List list;
			int size =list.get_size();
			Assert::AreEqual(size, 0);
			List list1; // 0 1 2 3 4
			for (int counter = 0; counter < 5; counter++)
			{
				list1.push_back(counter);
			}
			int size1 = list1.get_size();
			Assert::AreEqual(size1, 5);
		}
		TEST_METHOD(Test_clear)
		{
			List list;
			list.clear();
			Assert::IsTrue(list.isEmpty());
			List list1; // 0 1 2 3 4
			for (int counter = 0; counter < 5; counter++)
			{
				list1.push_back(counter);
			}
			list1.clear();
			Assert::IsTrue(list1.isEmpty());
			List list2;
			list2.push_back(1);
			list2.clear();
			Assert::IsTrue(list2.isEmpty());
		}
		TEST_METHOD(Test_Set)
		{
			List list;
			for (int counter = 0; counter < 5; counter++) // 0 1 2 3 4
			{
				list.push_back(counter);
			}
			for (int counter = 0; counter < 5; counter++) // 1 2 3 4 5
			{
				list.set(counter, counter+1);
			}
			list.set(0, 999); //999 2 3 4 5
			Assert::AreEqual(list.at(0), 999);
			Assert::AreEqual(list.at(1), 2);
			Assert::AreEqual(list.at(2), 3);
			Assert::AreEqual(list.at(3), 4);
			Assert::AreEqual(list.at(4), 5);
			List list2;
			bool check = 0;
			list2.set(0, 5);
			if (list2.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
		}
		TEST_METHOD(Test_Insert_List)
		{
			List list_for_insert;
			for (int counter = 0; counter < 4; counter++) // 0 1 2 3
			{
				list_for_insert.push_back(counter);
			}
			List list;
			list.insert_List(&list_for_insert, 0); // 0 1 2 3
			Assert::AreEqual(list.at(0), 0);
			Assert::AreEqual(list.at(1), 1);
			Assert::AreEqual(list.at(2), 2);
			Assert::AreEqual(list.at(3), 3);
			List list1; // 6 7 8
			list1.push_back(6);
			list1.push_back(7);
			list1.push_back(8);
			list1.insert_List(&list_for_insert, 1); // 6 0 1 2 3 7 8
			Assert::AreEqual(list1.at(0), 6);
			Assert::AreEqual(list1.at(1), 0);
			Assert::AreEqual(list1.at(2), 1);
			Assert::AreEqual(list1.at(3), 2);
			Assert::AreEqual(list1.at(4), 3);
			Assert::AreEqual(list1.at(5), 7);
			Assert::AreEqual(list1.at(6), 8);
			List list2; // 7 8
			list2.push_back(7);
			list2.push_back(8);
			list2.insert_List(&list_for_insert, 2); // 7 8 0 1 2 3
			Assert::AreEqual(list2.at(0), 7);
			Assert::AreEqual(list2.at(1), 8);
			Assert::AreEqual(list2.at(2), 0);
			Assert::AreEqual(list2.at(3), 1);
			Assert::AreEqual(list2.at(4), 2);
			Assert::AreEqual(list2.at(5), 3);
			List list3;
			List list_for_insert_empty;
			for (int counter = 0; counter < 4; counter++) // 1 2 3 4
			{
				list3.push_back(counter+1);
			}
			list3.insert_List(&list_for_insert_empty, 2);
			Assert::AreEqual(list3.at(0), 1);
			Assert::AreEqual(list3.at(1), 2);
			Assert::AreEqual(list3.at(2), 3);
			Assert::AreEqual(list3.at(3), 4);
			int size3;
			size3 = list3.get_size();
			Assert::AreEqual(size3, 4);
			List list4;
			bool check = 0;
			list4.insert_List(&list_for_insert, 2);
			if (list4.get_error())
			{
				check = 1;
			}
			else
			{
				check = 0;
			}
			Assert::IsTrue(check);
		}
	};
}
