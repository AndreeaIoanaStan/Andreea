#include "Arguments.h"
#include "gtest/gtest.h"

//Test1
TEST(ConstructorTest, AppName)
{
	char *arg[3] = {(char*) "nume", (char*) "nume1", (char*) "nume2"};
	Arguments args(3,arg);
	
	EXPECT_EQ ("nume", args.appName());
}


//Test2
TEST(ConstructorTest, ArgumentsNumber)
{
	char *arg[3] = {(char*) "nume", (char*) "nume1", (char*) "nume2"};
	Arguments args(3, arg);	
	
	EXPECT_EQ (2, args.count());
}

//Test3
TEST(ConstructorTest, ArgumentsNumberIs0)
{
	char *arg[1] = {(char*) "nume"};
	Arguments args(1, arg);	
	
	EXPECT_EQ (0, args.count());
}

//Test4
TEST(ConstructorTest, ArgumentsValues)
{
	char *arg[3] = {(char*) "nume", (char*) "nume1", (char*) "nume2"};
	Arguments args(3, arg);	
	
	EXPECT_EQ ("nume1", args[0]);
	EXPECT_EQ ("nume2", args[1]);
}

//Test5
TEST(ConstructorTest, CopyConstructorIsValid)
{
	char *arg[3] = {(char*) "nume", (char*) "nume1", (char*) "nume2"};
	Arguments args(3,arg);
	Arguments copy(args);
	
	EXPECT_EQ(copy.appName(), args.appName());
	EXPECT_EQ(args[0], copy[0]);
	EXPECT_EQ(args[1], copy[1]);
}

//Test6
TEST(ConstructorTest, TestInvalidDataARGCNegative)
{
	char * arg2[0] = {};
	bool isThrow = false;
	try
	{
		Arguments args2(-1,arg2);
	}
	catch(int e)
	{
		isThrow = true;
	}
	
	EXPECT_EQ(true, isThrow);
} 

//Test7
TEST(ConstructorTest, TestInvalidDataARGV0)
{
	char ** arg2=0;
	bool isThrow = false;
	try
	{
		Arguments args2(2,arg2);
	}
	catch(int e)
	{
		isThrow = true;
	}
	EXPECT_EQ(true, isThrow);
} 

//Test8
TEST(ConstructorTest, TestInvalidDataARGC0)
{
	char * arg2[0] = {};
	bool isThrow = false;
	try
	{
		Arguments args2(0,arg2);
	}
	catch(int e)
	{
		isThrow = true;
	}
	
	EXPECT_EQ(true, isThrow);
} 
