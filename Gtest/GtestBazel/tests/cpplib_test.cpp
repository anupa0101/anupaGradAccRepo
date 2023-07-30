#include "src/lib/cpplib.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

TEST(CPPLibTest, ReturnHelloWorld) {
  CPPLib cpplib;
  std::string actual = cpplib.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}

TEST(CPPLibTest, CalculateFibonacci) {
  CPPLib cpplib;

  EXPECT_EQ(cpplib.fib(1), 1) << "Error: The factorial calculation was wrong!";
  EXPECT_EQ(cpplib.fib(5), 5) << "Error: The factorial calculation was wrong!";
  EXPECT_EQ(cpplib.fib(6), 8) << "Error: The factorial calculation was wrong!";
}

TEST(CPPLibTest, CalculateFibonacci2) {
  CPPLib cpplib;

  std::vector<int> inputs = {1, 2, 3, 4, 5, 6};
  std::vector<int> actual;

  for (auto &in : inputs) {
    actual.push_back(cpplib.fib(in));
  }

  std::vector<int> expected = {1, 1, 2, 3, 5, 8};
  EXPECT_EQ(expected, actual) << "Error: The factorial calculation was wrong!";
}

TEST(CPPLibTest, FindMaxHandlesSizeOne) {
  CPPLib cpplib;
  std::vector<int> inputs = {2};
  EXPECT_EQ(cpplib.FindMax(inputs), 2);
  // other stuff
}

TEST(CPPLibTest, FindMaxHandlesConsecutiveNumbers) {
  CPPLib cpplib;
  std::vector<int> inputs = {1, 2, 3, 4};
  EXPECT_EQ(cpplib.FindMax(inputs), 4);
}

TEST(CPPLibTest, FindMaxHandlesEmptyVector) {
  CPPLib cpplib;
  std::vector<int> inputs = {};
  EXPECT_EQ(cpplib.FindMax(inputs), -1);
}

/* 
Gtest is a framework for unit testing. Gmock is a framework imitating the rest of your system during unit tests.

CMake can generate a native build environment that will compile source code, create libraries, generate wrappers
 and build executables in arbitrary combinations. 
Cmake allows to provide cross platform build files that would generate platform specific project/make files for particular compilation/platform.



GTest

1. tests should be independant and repeatable - cant have tests that depend on other tests succeeding 
2. group tests whe they share subroutines and data

3. assertions- check if condition is true. result can be sucess, non fatal failure and fatal failure. at fatal faluire it aborts the current function

ASSERT_EQ/EXPECT_EQ(---EXPECTED VALUE, ---ACTUAL VALUE)-- REMEMBER THISSS
EXPECT_TRUE(CONDITION WITH BOOLEAN OUTPUT LILKE VALUE==3);
EXPECT_NE(VA1,VAL2); // not equal check
EXPECT_STREQ-  to compare strings use this
EXPECT_LT-<, EXPECT_LE-<=, EXPECT_GT->, EXPECT_GE->=

4. ASSERT_* generates fatal failure- aborts the current function- use when it doesnt make sense to continue after the failure
EXPECT_* generates non fatal failure- 
use ASSER_EQ(....,....)<<"optional comment"<<optional variable;
EXPECT_EQ(....,....)<<"optional comment"<<optional variable;

5. Use TEST_F  when using test fixtures. first define a test fixture class
synatax- IMPORTANT
TEST_F(NAAME OF TEST FIXTURE CLASS, test name)

6. TEST_P  for parametrzed tests- see syntax


Test suite is a group of logically related test cases.
A test fixture is a class factorinng out common code for mulitple cases. create test fixtures when a place holder for common test codes is needed. can be used in multiple tests
write the common code in multiple tests in test fixtures. May have setup and tear down functions.
: public testing::test  public derive from testing::test
we can add setup and teardown functions (cleanup)
but can also do it in constrcutor and destructors

A test's fullname is the suitename.testname

gmock- mocks are used for testing the behaviour of APIs/ interfaces which will be used in the component
under test. 
expensice fucnion outputs, database acccess, functions involving sleeping waiting for user input etc
tdd- test driven devlopment
Mock class/object is a lightweight and simplified class to untangle compex dependencies while  testing.

there are fakes- have working implementations but usualy use shortcutss
 and mocks- have pre programmed expecctations

*/
int Factorial(int){
    
    return 3;
}
TEST(FactorialTestSuite, FacTest){

    EXPECT_EQ(Factorial(1),0)<<"wrong val: "<<Factorial(1);
    EXPECT_EQ(Factorial(2),5);// non fatal failure. will check next
    EXPECT_EQ(Factorial(3),7);  // non fatal failure. will check next  
    EXPECT_EQ(Factorial(4),7);// non fatal failure. will check next
     ASSERT_EQ(Factorial(4),70);//ASSET_ fatal failure- will not check the rest belo
    ASSERT_EQ(Factorial(4),7);// WILL NO BE CHECKED BECAUSE OF THE PREVIOUS FATAL FAILURE
    EXPECT_EQ(Factorial(4),7);// WILL NO BE CHECKED BECAUSE OF THE PREVIOUS FATAL FAILURE
}



struct BankAccount{

    int balance=0;

    BankAccount(){};

    explicit BankAccount(const int balance):balance(balance){

    }
    void deposit(const int& val){
            balance+=val;
        }
    bool withdraw(int amount){
        if(balance>=amount){
            balance-=amount;
            return true;
        }
        return false;
    }


};



//test fixture- derived class- use when theres two or more tests on similar data
struct BankAccountTest: public ::testing::Test  //creating a test fixture. instead of creating a Bankaccount instance- 
//we create this which will do the cleaup actions
{

      BankAccount* acc;
        BankAccountTest(){
          acc= new BankAccount;
        }
    virtual ~BankAccountTest(){// does the cleanup actions
          delete acc;
        }

        

};





//TEST(group test name- suite, test name) this is macro- no undersscores for test group/suite names or testnames
TEST(AccountTest,BankAccountStartsEmpty){

    BankAccount account; //arrange
    //act
    //assert
    EXPECT_EQ(0,account.balance)<<"Balance not zero, its:"<<account.balance;// expecct equal synatax: EXPECT_EQ(expected value, variable);
// will show it as failed - will show the expected value and the actual value
}


TEST_F(BankAccountTest,BankAccountStartsEmptyButWithTestfixture){// TEST_F  F IS REQUIRED WHEN USING FIXTURES.
// synatax- IMPORTANT
// TEST_F(NAAME OF TEST FIXTURE CLASS, test name)
    BankAccountTest account; //arrange
 //  EXPECT_EQ(0,0);
   // EXPECT_EQ(0,account.acc->balance)<<"Balance not zero, its:"<<account.acc->balance;// expecct equal synatax: EXPECT_EQ(expected value, variable);
// will show it as failed - will show the expected value and the actual value
}
/* TEST_F(BankAccountTest,CanDepositMoney){
//synatax- IMPORTANT
//TEST_F(NAAME OF TEST FIXTURE CLASS, test name)
    BankAccountTest account;//we actually dont need it. its auto created lu .arrange
    account.acc->deposit(100);//act

    EXPECT_EQ(100, account.acc->balance)<<"wrong val"<<account.acc->balance;// will success
    EXPECT_EQ(10, account.acc->balance);// non fatal failure. will check next
    EXPECT_EQ(1, account.acc->balance);// non fatal failure. will check next
    EXPECT_EQ(9, account.acc->balance);// non fatal failure. will check next 
    ASSERT_EQ(10,account.acc->balance);//ASSET_ fatal failure- will not check the rest belo
    ASSERT_EQ(1, account.acc->balance);// WILL NO BE CHECKED BECAUSE OF THE PREVIOUS FATAL FAILURE
    EXPECT_EQ(9, account.acc->balance);//  WILL NO BE CHECKED BECAUSE OF THE PREVIOUS FATAL FAILURE
}
 */
