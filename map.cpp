#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char **argv)
{
  map<string, int> m;
  
  m.insert(m.begin(), make_pair("One", 1));
  m.insert( m.begin(),make_pair("Two", 2));
  m.insert( m.begin(),make_pair("Three", 3));
  m.insert( m.begin(),make_pair("Zero", 0));

  auto it = m.find("Three");
  if(it != m.end())
    cout << "Value of Key Three is << " << (*it).second << endl;

  return 0;
}
