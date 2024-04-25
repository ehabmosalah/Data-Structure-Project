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
    unordered_map<string, set<pair<string, TravelMethod>>>::iterator it1 = graph.find(country1);
    unordered_map<string, set<pair<string, TravelMethod>>>::iterator it2 = graph.find(country2);
    if (it1 == graph.end() || it2 == graph.end())
    {
        //cout << "the country not found\n";
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
       // cout << "Path between " << country1 << " and " << country2 << " with method " << methodName << " deleted successfully\n";
    }
    else
    {
       // cout << "Path between " << country1 << " and " << country2 << " with method " << methodName << " not found\n";
    }

}

bool Graph::isComplete()  
{

    if (graph.empty()) {
      //  cout << "Graph is empty\n";
        return false;
    }

    int nodesNumber = graph.size();
    
    for (auto& it : graph) {
        string country = it.first;
        set<pair<string, TravelMethod>>& edges = it.second;
        int edgeCount = edges.size();
       // cout << "Country " << country << " has " << edgeCount << " edges\n";
        if (edgeCount != (nodesNumber - 1))
        {
            return false;
        }
    }
    return true;
}


unordered_map<string, vector<pair<string, TravelMethod>>> Graph::BFS(map<string, vector<pair<string, TravelMethod>>>& adjList, string startNode, map <string, bool> visited)
{
    unordered_map<string, vector<pair<string, TravelMethod>>> path;
    queue<string> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        string currentNode = q.front();
        q.pop();
        for (auto neighbor : adjList[currentNode]) {
            if (!visited[neighbor.second.name]) {
                visited[neighbor.second.name] = true;
                q.push(neighbor.second.name);
            }
        }
    }
    return path;
}
unordered_map<string, vector<pair<string, TravelMethod>>> Graph::DFS(map<string, vector<pair<string, TravelMethod>>>& adjList, string  startNode, map <string, bool> visited) {

    unordered_map<string, vector<pair<string, TravelMethod>>>path;
    stack<string> s;
    s.push(startNode);
    visited[startNode] = true;

    while (!s.empty()) {
        string currentNode = s.top();
        TravelMethod method;
        s.pop();
        for (auto neighbor : adjList[currentNode]) {
            if (!visited[neighbor.second.name]) {
                method = neighbor.second;
                s.push(neighbor.second.name);
                visited[neighbor.second.name] = true;
            }
        }
        path[startNode].push_back({ currentNode ,method });

    }
    return path;
}


void Graph::deleteCountry(string country) {
    for (auto city : graph[country]) {
        for (auto x : graph[city.first]) {
            if (x.first == country) graph[x.first].erase(x);
        }
    }
    auto it = graph.find(country);
    if (it != graph.end())  graph.erase(it);
}
unordered_map<string, set<pair<string, TravelMethod>>> graph;
void Graph::updatePath(string country1, string country2, string methodName, string newmethodName, int newCost) {
    int oldCost;
    for (auto x : graph[country1]) {
        if (x.first == country2 && x.second.name == methodName) {
            oldCost = x.second.cost;
            x.second.name = newmethodName;
            x.second.cost = newCost;
        }
    }
    TravelMethod way;
    way.name = methodName;
    way.cost = oldCost;
    set<pair<string, TravelMethod>>::iterator it;
    it = graph[country2].find({ country1,way });
    it->second.name == newmethodName;
    it->second.cost == newCost;

}
