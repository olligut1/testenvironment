#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using::testing::AtLeast;
using::testing::Return;
using::testing::_;

// Assertions = take output true or false: Success, Non-Fatal Failure (EXPECT_EQ), Fatal Failure (ASSERT_EQ)

/*	
						Non-Fatal Failure		Fatal Failure
	Values:
	Equal:				EXPECT_EQ(..)			ASSERT_EQ(..)
	Not equal:			EXPECT_NE(..)			ASSERT_NE(..)
	LessThan:			EXPECT_LT(..)			ASSERT_LT(..)
	LessThanEqual:		EXPECT_LE(..)			ASSERT_LE(..)
	GreaterThan:		EXPECT_GT(..)			ASSERT_GT(..)
	GreaterThanEqual:	EXPECT_GE(..)			ASSERT_GE(..)
	
	Strings:
	Equal:				EXPECT_STREQ(..)		ASSERT_STREQ(..)
	Not equal:			EXPECT_STRNE(..)		ASSERT_STRNE(..)
	Case Equal:			EXPECT_STRCASEEQ(..)	ASSERT_STRCASEEQ(..)
	Case Not Equal:		EXPECT_STRCASENE(..)	ASSERT_STRCASENE(..)
*/

// supposed to be false
TEST(TestName, Subtest_1) {

	ASSERT_FALSE(1 == 2);
	cout << "After assertion" << endl;
}

// supposed to be true
TEST(TestName, Subtest_2) {

	ASSERT_TRUE(1 == 1);
}

// supposed to be equal
TEST(TestName2, Subtest_1) {

	ASSERT_EQ(1,1);	
}

// non-fatal test failure, test doesn't stop
TEST(TestName2, Subtest_2) {

	EXPECT_EQ(1, 1);
}

// TEST: Arrange, Act, Assert
TEST(TestName3, increment_by_5) {

	//Arrange (arrange everything required to run the test)
	int value = 100;
	int increment = 5;

	//Act (run the test)
	value = value + increment;

	//Assert (verify the output)
	ASSERT_EQ(value, 105);
}

// tests are always independent
TEST(TestName3, increment_by_10) {

	//Arrange
	int value = 100;
	int increment = 10;

	//Act
	value = value + increment;

	//Assert
	ASSERT_EQ(value, 110);
}

class MyClass {
	string id;
public:
	MyClass(string _id) : id(_id) {}
	string GetId() { return id; }
};

TEST(TestName4, compare_string) {

	//Arrange
	MyClass mc("root");

	//Act
	string value = mc.GetId();

	//Assert
//	ASSERT_EQ(value.c_str(), "root"); //test will fail because ASSERT_EQ compares value and not the string -> ASSERT_STREQ
	ASSERT_STREQ(value.c_str(), "root");
}

class MyClass2 {
	int baseValue;
public:
	MyClass2(int _bv) : baseValue(_bv) {}
	void Increment(int byValue) {
		baseValue += byValue;
	}
	int getValue() { return baseValue; }
};

struct MyClassTest : public testing::Test {
	MyClass2* mc;	//MyClass2 Instanz
	void SetUp() { cout << "Alive" << endl; mc = new MyClass2(100); }
	void TearDown() { cout << "Dead" << endl; delete mc; }
};

TEST(ClassTest, Increment_by_5) {
	//Arrange
	MyClass2 mc(100);
	//Act
	mc.Increment(5);
	//Assert
	ASSERT_EQ(mc.getValue(), 105);
}

TEST(ClassTest, Increment_by_10) {
	//Arrange part is similar to Increment_by_5 -> use Text Fixture
	MyClass2 mc(100);
	//Act
	mc.Increment(10);
	//Assert
	ASSERT_EQ(mc.getValue(), 110);
}

TEST_F(MyClassTest, Increment_by_5) { //TEST_F = fixture, instead of passing the name of the class we have to pass the name of the fixture
	//Act, got rid of the Arrange part	
	mc->Increment(5);	//now we are using the pointer
	//Assert
	ASSERT_EQ(mc->getValue(), 105);	//pointer
}

TEST_F(MyClassTest, Increment_by_10) { 
	//Act	
	mc->Increment(10);
	//Assert
	ASSERT_EQ(mc->getValue(), 110);
}

class Stack {
	vector<int> vstack = {};
//stack class has two functions, push and pop
public:
	void push(int value) { vstack.push_back(value); }
	int pop() {
		if (vstack.size() > 0) {
			int value = vstack.back();
			vstack.pop_back();
			return value;
		}
		else {
			return -1;
		}
	}
	int size() { return vstack.size(); }
};

//Text Fixture for Stack Class
struct stackTest : public testing::Test {
	Stack s1;
	void SetUp() {
		int value[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (auto& val : value) {
			s1.push(val);
		}
	}
	void TearDown() {};
};

TEST_F(stackTest, PopTest) {
	int lastPoppedValue = 9;
	while (lastPoppedValue != 1)
		ASSERT_EQ(s1.pop(), lastPoppedValue--);
}

TEST_F(stackTest, sizeValidityTest) {
	int val = s1.size();
	for (val; val > 0; val--)
		ASSERT_NE(s1.pop(), -1);
}

//interface
class DataBaseConnect {
public:
	virtual bool login(string username, string password)
	{ return true;}
	virtual bool logout(string username) { return true; }
	virtual int fetchRecord() { return -1; }
};

//write a Mock for DataBasseConnect Class
class MockDB : public DataBaseConnect {
public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(string username));
	MOCK_METHOD2(login, bool(string username, string password));
};

class MyDatabase {
	DataBaseConnect & dbC;
public:
	MyDatabase(DataBaseConnect & _dbC) : dbC(_dbC) {}

	int Init(string username, string password) {
		if (dbC.login(username, password) != true) {
			//
			if (dbC.login(username, password) != true) {
				cout << "DB FAILURE 2nd TIME" << endl; return -1;
			}
		} else {
			cout << "DB SUCCESS" << endl; return 1;
		}
	}
};

TEST(MyDBTest, LoginTest) {
	//Arrange
	MockDB mdb;
	MyDatabase db(mdb);
	/*EXPECT_CALL(mdb, login("Terminator", "I'm Back"))	//_ would mean that we accept any parameter
	.Times(AtLeast(1))
	.WillOnce(Return(true));
	*/
	ON_CALL(mdb, login(_, _)).WillByDefault(Return(true));
	//Act
	int retValue = db.Init("Terminator", "I'm Back");

	//Assert
	EXPECT_EQ(retValue, 1);
}

/*
TEST(MyDBTest, LoginFailure) {
	//Arrange
	MockDB mdb;
	MyDatabase db(mdb);
	EXPECT_CALL(mdb, login(_,_))	//_ would mean that we accept any parameter
		.Times(2)
		.WillRepeatedly(Return(false));

	//Act
	int retValue = db.Init("Terminator", "I'm Back");

	//Assert
	EXPECT_EQ(retValue, -1);
}
*/

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}