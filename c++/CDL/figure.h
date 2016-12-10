#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
#define X first
#define Y second

class Figure
{
    static int static_ID;
    int ID;
    string name;
    bool erased;
    vector<pii> pts;

public:

    Figure(const vector<pii>& p);
    Figure(const pii O, const int L);
    Figure(const pii O, const int L, const int l);

    void Erase();
    void Translate(const pii dir, const int L);
    void Rotate(const pii p, int deg);
    bool IntersectsWith(Figure& F);

    friend ostream& operator<<(std::ostream& os, Figure &F);

private:

    void ConvexHull();
    void ConvexHullAdd(vector<int>& st, vector<bool>& viz, int i);
    bool HasPointInside(const Figure& F);
    bool TwoLinesIntersect(const Figure& F);
    inline bool LineIntersects(const pii& A1, const pii& A2, const pii& B1, const pii& B2);
    inline int cross_product(const pii& O, const pii& A, const pii& B);
};

#endif // FIGURE_H
