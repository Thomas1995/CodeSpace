#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern void Parse(string&);
extern void PrintFigures();

int main(int argc, char *argv[])
{
    if(argc < 3)
        return 0;

    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);

    string line;

    while(getline(cin,line))
    {
        Parse(line);
    }

    PrintFigures();

    return 0;
}
