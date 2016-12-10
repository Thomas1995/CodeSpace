#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
#include "figure.h"
using namespace std;

vector<Figure*> figs;

void PrintFigures() {
    for(auto it : figs)
        cout<<*it;

    while(!figs.empty()) {
        delete figs.back();
        figs.pop_back();
    }
}

inline bool read(int& a, const string& line, int& p) {
    char c=' ';
    for(;!isdigit(c);c=line[p++])
        if(p >= line.size())
            return false;

    int sgn = 1;
    if(line[p-2] == '-') sgn = -1;

    for(a=0;isdigit(c);c=line[p++]) {
        a=a*10+c-'0';
        if(p >= line.size())
            return false;
    }

    if(sgn == -1) a = -a;

    return true;
}

void Parse(string& line) {
    static stack<int> condition;
    static stack<bool> cond_else;

    int it, it2;
    int x,y,l1,l2;
    pii dir;

    if(line.size() == 0)
        return;

    transform(line.begin(), line.end(), line.begin(), ::tolower);

    if(line.find("gata") != line.npos) {
        if(!condition.empty()) {
            condition.pop();
            cond_else.pop();
        }
        return;
    }

    if(line.find("altfel") != line.npos)
        cond_else.top() = true;

    it = line.find("daca");
    if(it != line.npos) {
        if(!condition.empty() && condition.top() == 2 && cond_else.top() == false) {
            condition.push(0);
            cond_else.push(false);
        }
        else if(!condition.empty() && condition.top() == 1 && cond_else.top() == true) {
            condition.push(0);
            cond_else.push(false);
        }
        else {
            it2 = line.find("figura", it+1);

            read(x, line, it2);

            it2 = line.find("intersecteaza", it2);

            it2 = line.find("figura", it2+1);

            read(y, line, it2);

            if(figs[x]->IntersectsWith(*figs[y]))
                condition.push(1);
            else condition.push(2);

            cond_else.push(false);
        }
    }

    if(!condition.empty() && condition.top() == 2 && cond_else.top() == false)
        return;

    if(!condition.empty() && condition.top() == 1 && cond_else.top() == true)
        return;

    if(!condition.empty() && condition.top() == 0)
        return;

    it = line.find("vreau");
    if(it != line.npos) {
        it2 = it;
        it = line.find("patrat", it+1);
        if(it != line.npos) {
            read(x, line, it);
            read(y, line, it);
            read(l1, line, it);
            Figure *F = new Figure(make_pair(x,y), l1);
            figs.push_back(F);
        }

        it = it2;
        it = line.find("dreptunghi", it+1);
        if(it != line.npos) {
            read(x, line, it);
            read(y, line, it);
            read(l1, line, it);
            read(l2, line, it);
            Figure *F = new Figure(make_pair(x,y), l1, l2);
            figs.push_back(F);
        }

        it = it2;
        it = line.find("poligon", it+1);
        if(it != line.npos) {
            vector<pii> tmp;
            while( read(x, line, it) && read(y, line, it) )
                tmp.push_back(make_pair(x,y));

            Figure *F = new Figure(tmp);
            figs.push_back(F);
        }
    }

    it = line.find("muta");
    if(it != line.npos) {
        it2 = line.find("stanga", it+1);
        if(it2 != line.npos)  dir = make_pair(-1, 0), it = it2;

        it2 = line.find("dreapta", it+1);
        if(it2 != line.npos)  dir = make_pair(1, 0), it = it2;

        it2 = line.find("jos", it+1);
        if(it2 != line.npos)  dir = make_pair(0, -1), it = it2;

        it2 = line.find("sus", it+1);
        if(it2 != line.npos)  dir = make_pair(0, 1), it = it2;

        it2 = line.find("figura", it+1);
        read(x, line, it2);

        it2 = line.find("cu", it+1);
        read(y, line, it2);

        figs[x]->Translate(dir, y);
    }

    it = line.find("roteste");
    if(it != line.npos) {
        it2 = line.find("figura", it+1);
        read(x, line, it2);

        it2 = line.find("cu", it+1);
        read(y, line, it2);

        it2 = line.find("punctul", it+1);
        read(dir.X, line, it2);
        read(dir.Y, line, it2);

        figs[x]->Rotate(dir, y);
    }

    it = line.find("sterge");
    if(it != line.npos) {
        read(x, line, it);
        figs[x]->Erase();
    }
}
