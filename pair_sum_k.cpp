/*
https://www.techiedelight.com/find-pair-with-given-sum-array/

Find a pair with a given sum in the array.

For an array {2, 5, 1, 3, 9}, find a pair with given sum 8
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility> //For std::pair

using namespace std;

bool find_pair(const vector<int> &a, int sum, pair<int,int> &result)
{
  unordered_map<int,int> m;
  int i = 0;
  for (auto iE:a)
  {
    if(m.find(sum - iE) != m.end())
    {
      result.first = sum-iE;
      result.second = iE;
      return true;
    }
    m[iE] = i++;
  }
  return false;
}

int main ()
{
  vector<int> a = {2, 5, 1, 4, 9, 6, 3};
  pair<int,int> p;
  if(find_pair(a, 8, p))
    cout << "The first matching pair with given sum - " << p.first << "," << p.second << endl;
  else
    cout << "No pair matches the given sum" << endl;

  return 0; 
}
