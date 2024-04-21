#pragma once
#pragma once
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

class TravelMethod
{
public:
    string name;
    int cost;
    TravelMethod();
    TravelMethod(string name, int cost);
    bool operator<(const TravelMethod& t2) const;
};


class Graph
{
private:
    //  map string name as a key and a set of edges (
    //  each edge contain a pair of string (which is the other node name) and transportation method
    //  transportation method contains name and cost
    unordered_map<string, set<pair<string, TravelMethod>>> map;
public:
    void addPath(string country1, string country2, string methodName, int cost);
    void updatePath(string country1, string country2, string methodName, string newName, int newCost);
    void deletePath(string country1, string country2, string methodName);
    void addCountry(string country);
    void deleteCountry(string country);
    bool isComplete();
    //BFS();
    //DFS();
    //getPaths(string country1, string country2, long cost);
};

