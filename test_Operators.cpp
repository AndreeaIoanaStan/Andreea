#include "Arguments.h"
#include "gtest/gtest.h"
#include <vector>

//Test1
TEST(AssignmentOperator, ValidData)
{
	char *arg[3] = {(char*) "nume", (char*) "nume1", (char*) "nume2"};
	Arguments args(3,arg);
	
	EXPECT_EQ("nume1", args[0]);
	EXPECT_EQ("nume2", args[1]);
}

//Test2
TEST(AssignmentOperator, ValidData2)
{
	char * args[1] = {(char*)"ccc"};
	char *arg[3] = {(char*) "nume", (char*) "nume1", (char*) "nume2"};
	Arguments obj(3,arg);
	Arguments copy(1, args);
	copy = obj;
	
	EXPECT_EQ(copy.appName(), obj.appName());
	EXPECT_EQ(copy[0], obj[0]);
	EXPECT_EQ(copy[1], obj[1]);
}