#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
  fstream flIn("input.txt", fstream::in);
  fstream flOut("output.txt", fstream::out);
  int iRes = 1;

  char buff[100000];

  flIn >> buff;
  string strF(buff);
  cout << strF << endl;

  memset(buff,'\0', sizeof(buff));
  flIn >> buff;
  string strS(buff);
  cout << strS << endl;

  if(strF.length() == strS.length())
  {
    for(size_t i = 0; i < strF.length(); i++){
      int found = strS.find(strF[i]);
      if(found == string::npos){
        iRes = 0;
        break;
      }
    }
  }
  else
  {
    iRes = 0;
  }

  cout << iRes;
  flOut << iRes;

  return 0;
}
