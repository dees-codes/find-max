// Analyze unordered find_max
// 1. fill a vector with n randomly chosen values
// 2. see how many operations are required to find the maximum value
// Jon Beck
// 26 August 2019

#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

/**
 * use linear search to find the largest value in the array
 * @param array the array of values to search
 * @param operations the count of basic operations
 * @return the largest value in the array
 */
unsigned find_max(const vector <unsigned>& array, unsigned& operations);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] <<
      " n where n is the number of values in the array" << endl;
    return 1;
  }

  srand(static_cast<unsigned>(time(nullptr)));

  unsigned number_of_values {static_cast<unsigned>(stoul(argv[1]))};

  // put n random values into the array
  vector <unsigned> values;
  for (unsigned count {0}; count < number_of_values; count++)
  {
    values.push_back(static_cast<unsigned>(rand()));
  }

  unsigned count_operations {0};
  unsigned max_value {find_max(values, count_operations)};

  cout << "Maximum value: " << max_value << endl;
  cerr << number_of_values << ' ' << count_operations << endl;
  return 0;
}

unsigned find_max(const vector <unsigned>& array, unsigned& operations)
{
  unsigned new_max {array.at(0)};
  operations++;

  for (size_t index {1}; index < array.size(); index++)
  {
    operations += 2;
    new_max = array.at(index) > new_max ? array.at(index) : new_max;
    operations++;
  }
  operations += 2;
  return new_max;
}
