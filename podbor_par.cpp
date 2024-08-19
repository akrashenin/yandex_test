#include <iostream>
#include <fstream>
#include <vector>

#define FILE_IN "in_1.txt"

using namespace std;

int main()
{
    cout << "It's work!" << endl;

    fstream flIn(FILE_IN, fstream::in);
    fstream flOut("out.txt", fstream::out);

    int iNumStudents;
    flIn >> iNumStudents;
    cout << "number students: " << iNumStudents << endl;

    int iThreShold;
    flIn >> iThreShold;
    cout << "threshold of abilities: " << iThreShold << endl;

    int iSmartCoach;
    flIn >> iSmartCoach;
    cout << "smart coach: " << iSmartCoach << endl;

    vector<int> vecStudsLevel;

    for(int i = 0; i < iNumStudents; i++)
    {
        int iVal;
        flIn >> iVal;
        vecStudsLevel.push_back(iVal);
    }

    cout << "vector students level: ";
    for(auto& iVal: vecStudsLevel)
    {
        cout << iVal << " ";
    }
    cout << endl;

    int iNumPair = 0;

    for(int j = 0; j < (iNumStudents - 1); j++)
    {
        int iVal1 = vecStudsLevel[j];
        for(int i = j + 1; i < iNumStudents; i++)
        {
            int iVal2 = vecStudsLevel[i];
            int iValue = abs(iVal1 - iVal2);
            if( iValue <= iThreShold && (iVal1 + iVal2) <= iSmartCoach)
                iNumPair++;

        }
    }

    cout << "number pairs: " << iNumPair;
    flOut << iNumPair;

    return 0;
}
