#include <iostream>
#include <fstream>

using namespace std;
#include <vector>

int main()
{
  fstream flIn("input.txt", fstream::in);
  fstream flOut("output.txt", fstream::out);
  size_t uCount;
  int iVal, iValPrev = 0;
  vector<int> vec;
  bool flag = false;

  flIn >> uCount;
  cout << "count: " << uCount << endl;

  for(size_t i = 0; i < uCount; i++)
  {
    flIn >> iVal;
    if(iVal > iValPrev){
      vec.push_back(iVal);
      iValPrev = iVal;
      if(flag)
        flOut << "\n";
      flOut << iVal;
      if(!flag) flag = true;
    }
  }

  for(auto &v: vec){
    cout << v << "\n";
  }

  return 0;
}
