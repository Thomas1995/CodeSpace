#include "figure.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Figure::static_ID = 0;

Figure::Figure(const vector<pii>& p) : name("Poligon"), pts(p), erased(false), ID(static_ID++) {}

Figure::Figure(const pii O, const int L) : name("Patrat"), erased(false), ID(static_ID++) {
    pts.push_back(O);
    pts.push_back(make_pair(O.X,O.Y+L));
    pts.push_back(make_pair(O.X+L,O.Y));
    pts.push_back(make_pair(O.X+L,O.Y+L));
}

Figure::Figure(const pii O, const int L, const int l) : name("Dreptunghi"), erased(false), ID(static_ID++) {
    pts.push_back(O);
    pts.push_back(make_pair(O.X,O.Y+l));
    pts.push_back(make_pair(O.X+L,O.Y));
    pts.push_back(make_pair(O.X+L,O.Y+l));
}

void Figure::Erase() {
    erased = true;
}

void Figure::Translate(const pii dir, const int L) {
    for(int i=0;i<pts.size();++i) {
        pts[i].X += dir.X * L;
        pts[i].Y += dir.Y * L;
    }
}

void Figure::Rotate(const pii p, int deg) {
    deg %= 360;

    for(int i=0;i<pts.size();++i) {
        pts[i].X -= p.X;
        pts[i].Y -= p.Y;

        if(deg == 270) {
            swap(pts[i].X, pts[i].Y);
            pts[i].Y = -pts[i].Y;
        }
        else if(deg == 180) {
            pts[i].X = -pts[i].X;
            pts[i].Y = -pts[i].Y;
        }
        else if(deg == 90) {
            swap(pts[i].X, pts[i].Y);
            pts[i].X = -pts[i].X;
        }

        pts[i].X += p.X;
        pts[i].Y += p.Y;
    }
}

bool Figure::IntersectsWith(Figure& F) {
    if(erased || F.erased)
        return false;

    if(ID == F.ID)
        return true;

    ConvexHull();
    F.ConvexHull();

    pts.push_back(pts[0]);
    F.pts.push_back(F.pts[0]);

    if( TwoLinesIntersect(F) || HasPointInside(F) || F.HasPointInside(*this) ) {
        pts.pop_back();
        F.pts.pop_back();
        return true;
    }

    pts.pop_back();
    F.pts.pop_back();
    return false;
}

ostream& operator<<(ostream& os, Figure &F) {
    sort(F.pts.begin(), F.pts.end());

    if(F.erased) return os;
    os << F.ID << " " << F.name << ":\n";
    for(auto it : F.pts) {
        os << it.X << " " << it.Y << "\n";
    }
    return os;
}

inline int Figure::cross_product(const pii& O, const pii& A, const pii& B) {
    int sgn = (A.X - O.X) * (B.Y - O.Y) - (B.X - O.X) * (A.Y - O.Y);
    if(sgn >= 1) return 1;
    if(sgn <= -1) return -1;
    return sgn;
}

void Figure::ConvexHullAdd(vector<int>& st, vector<bool>& viz, int i) {
    while(st.size() >= 2 && cross_product(pts[st[st.size()-2]], pts[st.back()], pts[i]) < 0) {
        viz[st.back()] = false;
        st.pop_back();
    }
    st.push_back(i);
    viz[i] = true;
}

void Figure::ConvexHull() {
    if(pts.size() <= 2) return;

    sort(pts.begin(), pts.end());
    vector<bool> viz(pts.size(), false);
    vector<int> st;

    st.push_back(0);
    st.push_back(1);
    viz[1] = true;

    int i;
    for(i=2;i<pts.size()-1;++i) if(!viz[i]) ConvexHullAdd(st, viz, i);
    for(i=pts.size()-1;i>=0;--i) if(!viz[i]) ConvexHullAdd(st, viz, i);

    st.pop_back();
    vector<pii> tmp(pts.size());
    for(int i=0;i<st.size();++i)
        tmp[i] = pts[st[i]];

    pts = tmp;
}

inline bool Figure::LineIntersects(const pii& A1, const pii& A2, const pii& B1, const pii& B2) {
    if( ( cross_product(A1, A2, B1) * cross_product(A1, A2, B2) ) < 0 &&
        ( cross_product(B1, B2, A1) * cross_product(B1, B2, A2) ) < 0 )
        return true;

    return false;
}

bool Figure::HasPointInside(const Figure& F) {
    bool ok;
    for(int j=F.pts.size()-2;j>=0;--j) {
        ok = true;
        for(int i=1;i<pts.size();++i) {
            if( cross_product(pts[i-1], pts[i], F.pts[j]) < 0) {
                ok = false;
                break;
            }
        }

        if(ok == true)
            return true;
    }

    return false;
}

bool Figure::TwoLinesIntersect(const Figure& F) {
    for(int i=1;i<pts.size();++i)
        for(int j=1;j<F.pts.size();++j)
            if(LineIntersects(pts[i-1], pts[i], F.pts[j-1], F.pts[j]))
                return true;
}
