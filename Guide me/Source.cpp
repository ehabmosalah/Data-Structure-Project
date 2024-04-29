#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
#define FREE_PALESTINE            \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);



int main()
{
    Graph GuideMe;
    GuideMe.addCountry("aaa");
    GuideMe.addCountry("bbb");
    GuideMe.addCountry("ccc");
    GuideMe.addPath("aaa", "bbb", "bus", 100);
    GuideMe.addPath("aaa", "ccc", "bus", 100);
    GuideMe.addPath("ccc", "bbb", "bus", 100);
    cout << GuideMe.isComplete();


}
