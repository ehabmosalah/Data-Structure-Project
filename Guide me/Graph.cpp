#include "Graph.h"

TravelMethod::TravelMethod()
{
    name = "unKnown";
    cost = 0;
}

TravelMethod::TravelMethod(string name, int cost)
{
    this->name = name;
    this->cost = cost;
}

bool TravelMethod::operator<(const TravelMethod& t2) const
{
    if (cost == t2.cost)
        return name < t2.name;
    return cost < t2.cost;
}

void Graph::deletePath(string country1, string country2, string methodName)
{
    unordered_map<string, set<pair<string, TravelMethod>>>::iterator it1 = map.find(country1);
    unordered_map<string, set<pair<string, TravelMethod>>>::iterator it2 = map.find(country2);
    if (it1 == map.end() || it2 == map.end())
    {
        cout << "the country not found\n";
        return;
    }
    set<pair<string, TravelMethod>>& edges1 = it1->second;
    set<pair<string, TravelMethod>>& edges2 = it2->second;

    bool found = false;
    // Search for a specific path in edges1 and remove it
    
    for (auto& it : edges1) {
        if (it.first == country2 && it.second.name == methodName)
        {
            edges1.erase(it);
            found = true;
            break;
        }
    }
   
    // Search for the specific path in edges2 and remove it
    for (auto& it : edges2) {
        if (it.first == country1 && it.second.name == methodName)
        {
            edges2.erase(it);
            break;
        }
    }

    if (found)
    {
        cout << "Path between " << country1 << " and " << country2 << " with method " << methodName << " deleted successfully\n";
    }
    else
    {
        cout << "Path between " << country1 << " and " << country2 << " with method " << methodName << " not found\n";
    }

}

bool Graph::isComplete()  
{

    if (map.empty()) {
        cout << "Graph is empty\n";
        return false;
    }

    int nodesNumber = map.size();
    
    for (auto& it : map) {
        string country = it.first;
        set<pair<string, TravelMethod>>& edges = it.second;
        int edgeCount = edges.size();
        cout << "Country " << country << " has " << edgeCount << " edges\n";
        if (edgeCount != (nodesNumber - 1))
        {
            return false;
        }
    }
    return true;
}

