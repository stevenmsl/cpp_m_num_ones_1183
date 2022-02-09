#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1183;

vector<int> testFixture1()
{
  return vector<int>{3, 3, 2, 1, 4};
}

vector<int> testFixture2()
{
  return vector<int>{3, 3, 2, 2, 6};
}

void test1()
{
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see " << to_string(fixture[4])
       << endl;
  Solution sol;
  auto result = sol.maxOnes(fixture[0], fixture[1], fixture[2], fixture[3]);
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto fixture = testFixture2();
  cout << "Test 2 - expect to see " << to_string(fixture[4])
       << endl;
  Solution sol;
  auto result = sol.maxOnes(fixture[0], fixture[1], fixture[2], fixture[3]);
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}