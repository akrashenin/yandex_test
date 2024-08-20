/*
There is an inaccuracy in the problem statement, since it is not defined what a road is.
If a road is a path from a gas station to a gas station, then this is one condition of the problem.
If a road is a path from a city to a city, then this is another condition of the problem. (The problem with this condition has been solved)/
The size of the executable code is is 18944 bytes.
*/
#include <iostream>
#include <fstream>
#include <vector>

#define INPUTFILE "input-1.txt"

using namespace std;

class CCity{
  int m_coordX;
  int m_coordY;
  int m_distToEnd;

public:
  void setCoord(int x, int y){
    m_coordX = x;
    m_coordY = y;
  }

  void calcDistToEnd(CCity B, CCity E){
    m_distToEnd = abs(B.m_coordX - E.m_coordX) + abs(B.m_coordY - E.m_coordY);
  }

  int calcDist(CCity B, CCity E){
    return abs(B.m_coordX - E.m_coordX) + abs(B.m_coordY - E.m_coordY);
  }

  int getCoordX(){return m_coordX;}
  int getCoordY(){return m_coordY;}
  int getDistToEnd(){return m_distToEnd;}
};

vector<CCity> vec;
static int iDistRefuel;
static int iDistStep;

int findCity(int iIndBeg, int iIndEnd){
  int iDistCurr, iDist, iDistTotal, iDistToEndCity, iIndex = 0;
  CCity city;
  // returned code:
  // address - successful
  // 0 - found yourself
  // -1 - found nothing

  if(iIndBeg == iIndEnd)
    return 0;

  city = vec[iIndBeg];
  iDist = -1;

  int i = 0;
  for(vector<CCity>::iterator iter = vec.begin(); iter < vec.end(); iter++, i++){
    if(i == iIndBeg) continue;
    iDistCurr = iter->calcDist(city, *iter);
    if(iDistCurr > iDistRefuel) continue;
    iDistToEndCity = iter->getDistToEnd();
    if(iDistToEndCity == 0){
        iDistStep++;
        return iDistCurr;
      }
    iDistTotal = iDistCurr + iDistToEndCity;
    if(iDist == -1)
      iDist = iDistTotal;
    else if(iDistTotal < iDist){
      iDist = iDistTotal;
      iIndex = i;
    }
  }

  if(iDist == -1){
    iDistStep = -1;
    return iDistStep;
  }
  else{
    iDistStep++;
    findCity(iIndex, iIndEnd);
  }
  return iDist;
}

int main()
{
  fstream flIn(INPUTFILE, fstream::in);
  fstream flOut("output.txt", fstream::out);
  size_t iCount;
  int iCoordX, iCoordY;
  CCity city;
  int iIndCityBeg, iIndCityEnd;

  if(!flIn.is_open()){
    cout << "File is not open!" << endl;
    return -1;
  }
  flIn >> iCount;

  cout << "count: " << iCount << endl;
  for(size_t i = 0; i < iCount; i++){
    flIn >> iCoordX;
    flIn >> iCoordY;
    city.setCoord(iCoordX, iCoordY);
    vec.push_back(city);
  }

  for(vector<CCity>::iterator iter = vec.begin(); iter < vec.end(); ++iter){
    cout << iter->getCoordX() << "\t" << iter->getCoordY();
    cout <<  endl;
  }

  flIn >> iDistRefuel ;
  cout << "distance without refueling: " << iDistRefuel << endl;

  flIn >> iIndCityBeg;
  cout << "starting city index: " << iIndCityBeg << endl;

  flIn >> iIndCityEnd;
  cout << "end city index: " << iIndCityEnd << endl;

  city = vec[iIndCityEnd -1];
  cout << "coordinates end city: " << " " << city.getCoordX() << " " << city.getCoordY() << endl;

  cout << "calculate distance to end city: ";
  for(vector<CCity>::iterator iter = vec.begin(); iter < vec.end(); ++iter){
    iter->calcDistToEnd(*iter, city);
    cout << iter->getDistToEnd() << '\t';
  }
  cout << endl;

  iDistStep = 0;
  findCity(iIndCityBeg -1, iIndCityEnd -1);

  cout << "quantaty roads: " << iDistStep;
  flOut << iDistStep;

  return 0;
}
