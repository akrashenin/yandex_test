#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
  fstream fileIn("input.txt", fstream::in);
  //char buff;
  char chLine[100];

  cout << "It's work!!!"  << endl;

  memset(chLine,'\0', sizeof(chLine));
  fileIn.getline(chLine, sizeof(chLine));
  string strJ(chLine);

  for(auto &j: strJ){
    cout << j << " ";
  }
  cout << endl;

  memset(chLine,'\0', sizeof(chLine));
  fileIn.getline(chLine, sizeof(chLine));
  string strS(chLine);

  for(auto &s: strS){
    cout << s << " ";
  }
  cout << endl;

  size_t uCount = 0;

  for(auto &s: strS){
    auto res = strJ.find(s);
    if(res != string::npos)
      uCount++;
  }

  cout << uCount << endl;

  fstream fileOut("output.txt", fstream::out);
  fileOut << uCount;

  fileIn.close();
  fileOut.close();
  return 0;
}
