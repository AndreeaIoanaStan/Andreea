RM = rm

CPPTOOL = g++
CPPFLAGS = -Wall

CPP = $(CPPTOOL) $(CPPFLAGS) -c
LINK = $(CPPTOOL) -o

GTEST_DIR=C:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

TESTS=\
	test_Constructor.o\
	test_Operators.o

all: main.exe test.exe

main.exe: main.o Arguments.o
	$(LINK) main.exe main.o Arguments.o
	
test.exe: Arguments.o $(TESTS) $(GTEST_LIB)
	$(CPPTOOL) -o test.exe $(TESTS) Arguments.o $(GTEST_LIB)
	
test_Constructor.o: test_Constructor.cpp
	$(CPPTOOL) $(CPPFLAGS) $(GTEST_INC) -o test_Constructor.o -c test_Constructor.cpp
	
test_Operators.o: test_Operators.cpp
	$(CPPTOOL) $(CPPFLAGS) $(GTEST_INC) -o test_Operators.o -c test_Operators.cpp

main.o: main.cpp Arguments.h
	$(CPP) main.cpp

Arguments.o: Arguments.cpp Arguments.h
	$(CPP) Arguments.cpp
	
test: test.exe
	test.exe

clean:
	$(RM) Arguments.o
	$(RM) main.o
	$(RM) main.exe
	$(RM) test_Constructor.o
	$(RM) test_Operators.o
	$(RM) test.exe