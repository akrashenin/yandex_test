#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int giCount = 0;
fstream flOut;
string strBeg;

void printStr(string str){
  for (size_t i=0; i < str.length(); i++){
    cout << str[i];
  }
  cout << endl;
  giCount++;
}

string getCheckStr(int iPos, string str){
  string strOut;
  string strBr = "(";

  for (size_t i=iPos/2; i < str.length()/2; i++)
  {
    strOut += strBr;
  }
  return strOut;
}

void changeBrack(int iPos, string str){
  char chBrackR = ')';
  char chBrackL = '(';
  int k;
  bool bFlag = true;

  string strOut = getCheckStr(iPos, strBeg);

  while( str.compare(iPos,strOut.length(),strOut) ){
    for(size_t i = iPos; i < str.length(); i++){
      if(str[i] == chBrackR && bFlag){
        k = i;
        bFlag = false;
      }
      if(str[i] == chBrackL && !bFlag){
        str.erase(k,1);
        str.insert(i,")");
        printStr(str);
        flOut << str << "\n";
        break;
      }
    }
    bFlag = true;
  }
}

int main()
{
  cout << "It's work!" << endl;

  flOut.open("out.txt",ios_base::out);
  fstream flIn("in.txt", ios_base::in);
  char ch;
  string str;

  while (flIn.get(ch)){
    strBeg += ch;
    std::cout << ch;
  }
  cout << endl;
  giCount++;

  size_t iLen = strBeg.length();
  flOut << strBeg << "\n";
  cout << "length: " << iLen << endl;
  str = strBeg;

  for(size_t i=0; i < iLen; (i+=2)){
    changeBrack(i, str);
    str = strBeg;
  }
  cout << "Count: " << giCount << endl;
  flOut << giCount;
  return 0;
}

