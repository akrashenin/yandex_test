#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>

#define MAXLIMIT  20
#define MINLIMIT  4
#define INFILE    "input_10.txt"

using namespace std;

class CStr
{
  string m_str;
public:
  CStr(string str): m_str(str){}
  string getStr(){ return m_str; }

  string getMinShortStr(size_t uPos)
  {
    string strOut;
    char chBuff[16]; memset(&chBuff, '\0', sizeof(chBuff));
    size_t uLen = m_str.length();
    if(uLen < MINLIMIT || uLen > MAXLIMIT || uPos > (uLen/2 + 1) )
      return m_str;
    size_t uLenNew = uLen - uPos*2;
    if(uLenNew < 2)
      return m_str;
    sprintf(chBuff, "%u", uLenNew);
    strOut = m_str.substr(0,uPos);
    strOut += chBuff;
    strOut += m_str.substr(uLen-uPos,uPos);
    return strOut;
  }

  int compare(string str){ return m_str.compare(str); }
};

int main()
{
    cout << "It's work!" << endl;
    fstream flIn(INFILE, ios_base::in);
    fstream flOut("output.txt", ios_base::out);
    size_t uCount = 0;
    vector<CStr>  vec;
    vector<CStr>::iterator iter, iterIn;
    char buff[32];
    vector<string> vecOut;

    flIn >> uCount;
    cout << uCount << endl;
    CStr* pCStr;

    for(size_t i = 0; i < uCount; i++)
    {
      memset(buff, '\0', sizeof(buff));
      flIn >> buff;
      pCStr = new CStr(buff);
      vec.push_back(move(*pCStr));
    }

    for(iter = vec.begin(); iter < vec.end(); iter++) // check for correct input
       cout << iter->getStr() << endl;

    cout << "-------" << endl;
    string strOut, strTmp, strBeg, strTmpShort, strBegShort;
    bool fFind = false;

    for(iter = vec.begin(); iter < vec.end(); iter++)
    {
      strBeg = iter->getStr();
      for(int ind = 1; ind <= (strBeg.length()/2 - 1); ind++)
      {
        strBegShort = iter->getMinShortStr(ind);
        if(!strBegShort.compare(strBeg))
        {
          vecOut.push_back(strBegShort);
          break;
        }
        fFind = false;
        for(iterIn = vec.begin(); iterIn < vec.end(); iterIn++)
        {
          strTmp = iterIn->getStr();
          if(!strBeg.compare(strTmp))
            continue;
          strOut = iterIn->getMinShortStr(ind);
          if(!strOut.compare(strBegShort))
          {
            fFind = true;
            break;
          }
          else
            continue;
        }
        if(!fFind)
        {
          vecOut.push_back(strBegShort);
          break;
        }
        else
        {
          if(ind == (strBeg.length()/2 - 1))
            vecOut.push_back(strBeg);
        }
      }
    }

    for(auto& val: vecOut)
    {
      cout << val << endl;
      flOut << val << "\n";
    }

    return 0;
}
