// ya_test_parser_url.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

//define STR_URL "https://tyndex.com/api/search?text=funny+cats&page=1"
#define STR_URL "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
//#define STR_URL "http://example.com"

using namespace std;

class CParsefURL
{
    string m_strURL = "";
    string m_strNextIter = "";
    string m_strProto = "";
    string m_strHostName = "";
    string m_strHandle = "";
    string m_strParam = "";
public:
    bool parseURL(string strURL)
    {       
        
        m_strURL = strURL;
        m_strProto = getNextTag(this->m_strURL, "://");       
        m_strHostName = getNextTag(this->m_strNextIter, "/");        
        m_strHandle = getNextTag(this->m_strNextIter, "?");        
        m_strParam = m_strNextIter;
        int i = 0;
        return true;
    }

    void printURL()
    {
        cout << "Proto: " << m_strProto.c_str() << endl;
        cout << "Host: " << m_strHostName.c_str() << endl;
        if(m_strHandle.length())
            cout << "Handle: " << m_strHandle.c_str() << endl;
        
        string strParam = m_strParam;
        size_t uLen = 1;
            strParam.length();
        while (uLen) {
            strParam = getNextTag(strParam, "&");
            size_t uPos = strParam.find("=");
            if (uPos != string::npos)
                strParam.replace(uPos, 1, " -> ");
            cout << strParam.c_str() << endl;
            strParam = m_strNextIter;
            uLen = strParam.length();            
        }
    }
private:
    string getNextTag(string strCurrIter, string strDelim)
    {
        string strTag = "";
        size_t uPos = strCurrIter.find(strDelim.c_str());
        if (uPos == string::npos && strCurrIter.length() == 0)
            return strTag;
        strTag = strCurrIter.substr(0, uPos);
        size_t uLen = strDelim.length();
        size_t uLenCurr = strCurrIter.length();
        size_t uArg1 = uPos + uLen;
        size_t uArg2 = uLenCurr - uArg1;
        if (uPos != string::npos)
            m_strNextIter = strCurrIter.substr(uArg1, uArg2);
        else
            m_strNextIter = "";
        return strTag;
    }    

};

int main()
{
    std::cout << "It's work!\n";
    
    CParsefURL url;
    url.parseURL(STR_URL);
    url.printURL();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
