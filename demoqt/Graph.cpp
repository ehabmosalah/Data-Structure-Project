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
    unordered_map<string, set<pair<TravelMethod, string>>>::iterator it1 = graph.find(country1);
    unordered_map<string, set<pair<TravelMethod, string>>>::iterator it2 = graph.find(country2);
    if (it1 == graph.end() || it2 == graph.end())
    {
        //cout << "the country not found\n";
        return;
    }
    set<pair<TravelMethod, string>>& edges1 = it1->second;
    set<pair<TravelMethod, string>>& edges2 = it2->second;

    bool found = false;
    // Search for a specific path in edges1 and remove it

    for (auto& it : edges1) {
        if (it.second == country2 && it.first.name == methodName)
        {
            edges1.erase(it);
            found = true;
            break;
        }
    }

    // Search for the specific path in edges2 and remove it
    for (auto& it : edges2) {
        if (it.second == country1 && it.first.name == methodName)
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
    for (auto node : graph) {
        unordered_map<string, bool>isNeighbor;
        for (auto neighbor : node.second)
            isNeighbor[neighbor.second] = true;
        if (isNeighbor.size() != graph.size() - 1) return false;
    }
    return true;
}

unordered_map<string, vector<pair<TravelMethod, string>>> Graph::BFS(map<string, vector<pair<TravelMethod, string>>>& adjList, string startNode, map <string, bool> visited)
{
    unordered_map<string, vector<pair<TravelMethod, string>>> path;
    queue<string> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        string currentNode = q.front();
        q.pop();
        for (auto neighbor : adjList[currentNode]) {
            if (!visited[neighbor.first.name]) {
                visited[neighbor.first.name] = true;
                q.push(neighbor.first.name);
            }
        }
    }
    return path;
}

unordered_map<string, vector<pair<TravelMethod, string>>> Graph::DFS(map<string, vector<pair<TravelMethod, string>>>& adjList, string  startNode, map <string, bool> visited) {

    unordered_map<string, vector<pair<TravelMethod, string>>>path;
    stack<string> s;
    s.push(startNode);
    visited[startNode] = true;

    while (!s.empty()) {
        string currentNode = s.top();
        TravelMethod method;
        s.pop();
        for (auto neighbor : adjList[currentNode]) {
            if (!visited[neighbor.first.name]) {
                method = neighbor.first;
                s.push(neighbor.first.name);
                visited[neighbor.first.name] = true;
            }
        }
        path[startNode].push_back({ method ,currentNode });

    }
    return path;
}


void Graph::deleteCountry(string country) {
    for (auto city : graph[country]) {
        for (auto x : graph[city.second]) {
            if (x.second == country) graph[x.second].erase(x);
        }
    }
    auto it = graph.find(country);
    if (it != graph.end())  graph.erase(it);
}
unordered_map<string, set<pair<TravelMethod, string>>> graph;
void Graph::updatePath(string country1, string country2, string methodName, string newmethodName, int newCost) {
    int oldCost;
    for (auto x : graph[country1]) {
        if (x.second == country2 && x.first.name == methodName) {
            oldCost = x.first.cost;
            x.first.name = newmethodName;
            x.first.cost = newCost;
        }
    }
    TravelMethod way;
    way.name = methodName;
    way.cost = oldCost;
    set<pair<TravelMethod, string>>::iterator it;
    it = graph[country2].find({ way ,country1 });
    it->first.name == newmethodName;
    it->first.cost == newCost;

}

void Graph::addCountry(string country)
{
    graph[country] = {};
}

void Graph::addPath(string country1, string country2, string methodName, int cost)
{
    TravelMethod travelMethod(methodName, cost);
    graph[country1].insert(make_pair(travelMethod, country2));
    graph[country2].insert(make_pair(travelMethod, country1));
}

set<pair<long, list<pair<TravelMethod, string>>>> Graph::getPaths(string country1, string country2, long cost, unordered_map<string, bool>visited)
{
    if (country1 == country2)
        return { make_pair(0, list< pair<TravelMethod, string>>()) };
    visited[country1] = true;
    set<pair<long, list<pair<TravelMethod, string>>>>allPaths;
    for (pair<TravelMethod, string> neighbor : graph[country1]) {
        if (visited[neighbor.second] || cost < neighbor.first.cost)
            continue;
        set<pair<long, list<pair<TravelMethod, string>>>> miniPaths;
        miniPaths = getPaths(neighbor.second, country2, cost - neighbor.first.cost, visited);
        for (pair<long, list<pair<TravelMethod, string>>> path : miniPaths)
        {
            path.first += neighbor.first.cost;
            path.second.push_front(neighbor);
            allPaths.insert(path);
        }
    }
    visited[country1] = false;
    return allPaths;
}