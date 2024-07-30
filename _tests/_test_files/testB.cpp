#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/vector/vector_class.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_v1 (bool debug = false){
  //**BASIC CONSTRUCTOR TEST
  Vector <int> one(5);
  if (debug){
  cout<<one.size ()<<" "<< one.capacity()<<"\n";
  cout<<one;
  }
  int test [10]= {1,2,3,4,5,6,7,8,9,10};
  Vector <int> b (test,10);
  if (debug)
  cout<<b;
  one=b;
  one.set_capacity (20);
  if (debug)
  cout<<"USED = SUCCESFULLY";
  cout<<"\n";
  if (one.size ()!=10){
    cout<<"Expected 10, but found "<< one.size();
    return false;
  }
  if (debug){
  cout<<"NEW VECTOR";
  cout<<one;
  cout<<"ORIGINAL VECTOR";
  cout<<b<<endl;
  }
  return true;
}

bool test_v2 (bool debug = false){
char op [5] = {'a','b','c','d','e'};
Vector <char> testing (op, 5);
if (debug)
cout<<testing;
testing = testing;
if (debug)
cout<<testing;
if (debug)
cout<<"If statement for = operator working properly\n";
for (int i=0;i<10;i++){
  testing+=102+i;
  if (debug)
  cout<<testing;
  }
if (testing.at (14)!='o')
{
  cout<<"Expected o at 15, but found "<< testing.at (15)<<"\n";
  return false;
}
if (debug)
cout<<"appended elements at the end of the vector, succesfully using +=\n";
return true;
}

bool test_vfunc(bool debug= false){
  int ar [5]={1,3,4,5,6};
  Vector <int> a (ar,5);
  if (debug)
  cout<<a;
  if (a [2]!=4){
    cout<<"Expected 4, but found "<<a[2]<<"\n";
    return false;
  }
  a[0]=5;
    if (a [0]!=5){
    cout<<"Expected 5, but found "<<a[0]<<"\n";
    return false;
  }
  if (a.at (1)!=3){
    cout<<"Expected 3, but found "<< a.at (1)<<"\n";
    return false;
}
  a.at(5)=2;
  if (a.at (5)!=2)
  {
     cout<<"Expected 2, but found "<< a.at (5)<<"\n";
    return false;
  }
  if (debug)
cout<<"at functions and [] operator working properly\n";
return true;
}
bool test_vfunc_2 (bool debug = false){
  char charay[6]= {'a','c','b','c','b','z'};
  Vector <char> newvec (charay,6);
  if (debug)
  if (debug)
  cout<< newvec;
  char pof = newvec.front ();
  if (pof != 'a'){
    cout<<"Expected a to be the first element but found "<< newvec.front ()<<"\n";
    return false;
  }
  newvec.front() = 'l';
  if (newvec [0]!='l'){
        cout<<"Expected l to be the first element but found "<< newvec.front ()<<"\n";
    return false;
  }
  pof = newvec.back();
  if (pof != 'z'){
    cout<<"Expected z to be the last element but found "<< newvec.back ()<<"\n";
    return false;
  }
  newvec.back ()='g';
    if (newvec [5]!='g'){
        cout<<"Expected g to be the last element but found "<< newvec.back ()<<"\n";
    return false;
  }
  if (debug)
  cout<<"Tested front and back succesfully\n";
  return true;
}
bool test_vfunc_3 (bool debug = false){
  long ar [2]= {12345,56343};
  Vector <long> vecto (ar,2);
  cout<<vecto;
  vecto.push_back (84098);
  cout<<vecto;
  if (vecto.back() != 84098){
    cout<<"Expected 84098,but found "<<vecto.back()<<"\n";
    return false;
  }
  for (int i =0 ; i<10;i++){
    vecto.push_back (3495*i);
    cout<<vecto;
  }
  long value21;
  cout<<"Popping elements\n";
  for (int i =0 ; i<13;i++){
    if (debug){
    cout<<"===========================================\n";
    cout<<"Vector before popping\n"<<vecto;
    }
    value21= vecto.pop_back ();
    if (debug)
    cout<<"Vecotor after popping\n"<<"Element popped: "<<value21<<"\n "<< vecto;
  }
  if (value21 != 84098){
      cout<<vecto.size()<<"\n";
      cout<<"Expected 84098,but found "<<value21<<"\n";
      return false;
  }
  if (debug)
  cout<<"pushback and pop back tested sucessfully\n";
  return true;
}

bool finals (bool debug =false){
int arr [1]={0};
Vector <int> test (arr,1);
if (debug)
cout<<test;
for (int i = 0; i < 3; i++)
  {
    test.insert (1+i,1+i);
    if (debug)
    cout<<test;
  }
string result = test.string_vector ();
if (result !="0123"){
    cout<<"FAILED, expeceted 0123 but found "<< result<<"\n";
    return false;
  }
 for (int i = 0; i < 3; i++)
 {
  test.erase (3-i);
  if (debug)
  cout<<test;
}
result = test.string_vector ();
if (result !="0"){
    cout<<"FAILED, expeceted 0 but found "<< result<<"\n";
    return false;
  }
  if (debug)
  cout<<"Basic insert and erase passed\n";
  return true;
}

bool test_pop (bool debug=false){
  int a[100];
  for (int i =0; i<100;i++){
    *a=rand()%300;
  }
  Vector <int> test (a,100);
  int last , current;
  for (int i =0;i<100;i++){
    last= test.back();
    current = test.pop_back();
    if (current!=last){
      cout<<"Expected "<<last<<" but found "<<current;
    }
  }
  return true;
}

bool test_insert (bool debug=false){
  int a [9]={1,2,3,4,5,6,7,8,0};
  Vector <int> b (a,9);
  if (debug)
  cout<<b;
  b.insert (4,6);
    if (b[4]!=6){
    cout<< "Expected 6 at pos 4, but found "<< a[4]<<"\n";
    return false;
  }
  if (debug)
  cout<<b;
  b.insert (0,999);
   if (b[0]!=999){
    cout<< "Expected 999 at pos 0, but found "<< a[0]<<"\n";
    return false;
  }
    if (debug)
  cout<<b;
  b.insert (10,888);
  if (b[10]!=888){
    cout<< "Expected 888 at pos 10, but found "<< a[10]<<"\n";
    return false;
  }
    if (debug)
  cout<<b;
  b.insert (1,555);
    if (b[1]!=555){
    cout<< "Expected 555 at pos 1, but found "<< a[1]<<"\n";
    return false;
  }
    if (debug)
  cout<<b;
  b.insert (2,189);
    if (b[2]!=189){
    cout<< "Expected 555 at pos 1, but found "<< a[2]<<"\n";
    return false;
  }
    if (debug)
  cout<<b;
  b.insert (8, 110);
    if (b[8]!=110){
    cout<< "Expected 110 at pos 8, but found "<< a[8]<<"\n";
     return false;
  }
    if (debug)
  cout<<b;
  b.insert (4,892);
    if (b[4]!=892){
    cout<< "Expected 892 at pos 1, but found "<< a[4]<<"\n";
    return false;
  }
    if (debug)
  cout<<b;
  b.insert (17,10000);
    if (b[17]!=10000){
    cout<< "Expected 10000 at pos 17, but found "<< a[17]<<"\n";
    return false;
  }
    if (debug)
  cout<<b;
  b.insert (21,10000);
    if (b[21]!=10000){
    cout<< "Expected 10000 at pos 17, but found "<< a[21]<<"\n";
    return false;
  }
  if (debug)
  cout<<b;
  if (debug)
  cout<<"Multiple inserts have been successful\n";
  return true;
}
bool test_erase (bool debug=false){
  int c[10]= {5,4,3,2,1,5,6,7,9,0};
  Vector <int> test (c,10);
  if (debug)
  cout<<test;
  test.erase (3);
  if (debug)
  cout<<test;
  if (test[3]!=1){
    cout<<"Expected 1 at pos 3, but found "<<test[3];
    return false;
  }
  test.erase (5);
  if (debug)
  cout<<test;
  if (test[5]!=7){
    cout<<"Expected 7 at pos 5, but found "<<test[5];
    return false;
  }  
  test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=4){
    cout<<"Expected 4 at pos 0, but found "<<test[0];
    return false;
  }
  test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=3){
    cout<<"Expected 3 at pos 0, but found "<<test[0];
    return false;
  }
    test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=1){
    cout<<"Expected 1 at pos 0, but found "<<test[0];
    return false;
  }
    test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=5){
    cout<<"Expected 5 at pos 0, but found "<<test[0];
    return false;
  }
    test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=7){
    cout<<"Expected 7 at pos 0, but found "<<test[0];
    return false;
  }
    test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=9){
    cout<<"Expected 9 at pos 0, but found "<<test[0];
    return false;
  }
  test.erase (0);
  if (debug)
  cout<<test;
  if (test[0]!=0){
    cout<<"Expected 0 at pos 0, but found "<<test[0];
    return false;
  }
  test.erase (0);
  if (debug)
  cout<<test;
  if (test.size()!=0){
    cout<<test.size ()<<"\n";
    return false;
  }

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(VECTORIAL_TEST, TestVec) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_v1(false));
}
TEST(VECTORIAL_TEST, TestVec2) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_v2(false));
}
TEST(TESTINGFUNC, TestVecFunc1) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_vfunc(false));
}
TEST(TESTINGFUNC, TestVecFunc2) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_vfunc_2(false));
}

TEST(FIXINGTEST, TestVecFunc3) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_pop(false));
}
TEST(FIXINGTEST, TestInse) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_insert(false));
}
TEST(FIXINGTEST, TestErase) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, test_erase(true));
}

TEST(TESTFIN, TestVecFunc3) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);
  EXPECT_EQ(1, finals(false));
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

