#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#define BUFF_SIZE 128

using namespace std;

struct TagToken
{
    string strAuth;
    unsigned long long uTimeStamp;
};

vector<TagToken> vec;

int main()
{
    fstream flIn("in2.txt", fstream::in);
    fstream flOut("out.txt", fstream::out);
    char buff[BUFF_SIZE];
    stringstream stream;
    int iTokenInSec;
    int iCountToken;

    flIn.getline(buff, sizeof(buff));
    stream.str(buff);
    stream >> iTokenInSec;
    stream >> iCountToken;
     
    cout << iTokenInSec << " " << iCountToken << endl;

    while (!flIn.eof())
    {
        stringstream streamIn;
        TagToken tag;
        memset(buff, '\0', sizeof(buff));
        flIn.getline(buff, sizeof(buff));
        streamIn.str(buff);
        streamIn >> tag.uTimeStamp;
        streamIn >> tag.strAuth;
        vec.push_back(tag);
    }

    for (auto& tag : vec)
    {
        cout << tag.uTimeStamp << " " << tag.strAuth.c_str() << endl;
    }

    cout << "----------------" << endl;

    vector<TagToken> vecOut;    

    unsigned long long uTimeEnd = vec[0].uTimeStamp + 1000;
    unsigned long long uTimeBeg = vec[0].uTimeStamp;    

    int j;
    for (int i = 0; i < vec.size(); i = (i++ + j)) {        
        int iCount = 0;
        for (j = 0; j <= vec.size(); j++)
        {   
            if ((i + j) >= vec.size())
                break;
            if (vec[i + j].uTimeStamp >= uTimeBeg && vec[i + j].uTimeStamp < uTimeEnd && iCount < iTokenInSec)
            {
                vecOut.push_back(vec[i + j]);
                iCount++;
            }            
            if(iCount >= iTokenInSec && vec[i + j].uTimeStamp >= uTimeEnd)
            {
                uTimeBeg = vec[i + j].uTimeStamp;
                uTimeEnd = uTimeBeg + 1000;
                j--;
                break;
            }
        }
    }

    for (auto& tag : vecOut)
    {
        cout << tag.uTimeStamp << " " << tag.strAuth.c_str() << endl;
    }

}


