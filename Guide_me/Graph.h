#pragma once
#include <unordered_map>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>

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
    // unordered_map<string, pair<string, TravelMethod>> path;
    void writeFiles();
    void readFiles();
public:
    unordered_map<string, set<pair<TravelMethod, string>>> graph;
    Graph();
    ~Graph();
    void addPath(string country1, string country2, string methodName, int cost);
    void updatePath(string country1, string country2, string methodName, string newmethodName, int newCost);
    int deletePath(string country1, string country2, string methodName);
    void addCountry(string country);
    void deleteCountry(string country);
    bool isComplete();
    string printGraph();
    list<string>allCountries();
    list<string> BFS(string startNode, unordered_map<string, bool> visited = {});
    list<string>  DFS(string startNode, unordered_map<string, bool> visited = {});
    set<pair<long, list<pair<TravelMethod, string>>>>getPaths(string country1, string country2, long cost, unordered_map<string, bool>visited = {});

};