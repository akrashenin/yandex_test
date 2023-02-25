#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  fstream flIn("in.txt", ios_base::in);
  fstream flOut("out.txt",ios_base::out);

  int iNum;
  int iVal;
  vector<int> vec;
  if(!flIn.is_open())
    cout << "File is not opened!!!" << endl;

  cout << "It's work!!!" << endl;

  flIn >> iNum ;
  for (int i=0; i<iNum; i++){
    flIn >> iVal;
    vec.push_back(iVal);
  }

  for (auto& v: vec){
    cout << v << " ";
  }
  cout << endl;

  int iCurr = 0;
  int iValMax = 0;

  for(auto& v: vec){
    if(v == 1){
      iCurr++;
    }
    else{
      if(iCurr > iValMax )
        iValMax = iCurr;
      iCurr = 0;  // to count the next sequence sequence
    }
  }
  if(iCurr > iValMax )  // if one is in the last position
        iValMax = iCurr;

  cout << iValMax;

  flOut << iValMax;

  return 0;
}
