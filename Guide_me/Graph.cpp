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
int  Graph::deletePath(string country1, string country2, string methodName)
{
    unordered_map<string, set<pair<TravelMethod, string>>>::iterator it1 = graph.find(country1);
    unordered_map<string, set<pair<TravelMethod, string>>>::iterator it2 = graph.find(country2);
    if (it1 == graph.end() || it2 == graph.end() || it1 == it2)
    {
        return 0;
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
    //Path between country1 and country2 not found
    if (!found)return -1;

    // Search for the specific path in edges2 and remove it
    for (auto& it : edges2) {
        if (it.second == country1 && it.first.name == methodName)
        {
            edges2.erase(it);
            // Path between country1 and country2 deleted successfully
            return 1;
            break;
        }
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

list<string> Graph::allCountries()
{
    list <string>ans;
    for (auto count : graph) {
        ans.push_back(count.first);
    }
    return ans;
}

list<string> Graph::BFS(string startNode, unordered_map<string, bool> visited)
{
    queue<string> q;
    visited[startNode] = true;
    q.push(startNode);
    list<string>path;
    while (!q.empty()) {
        string currentNode = q.front();
        path.push_back(currentNode);
        for (auto neighbor : graph[currentNode]) {
            if (!visited[neighbor.second]) {
                visited[neighbor.second] = true;
                q.push(neighbor.second);
            }
        }
        q.pop();
    }
    return path;
}
list<string> Graph::DFS(string startNode, unordered_map<string, bool> visited) {
    list<string>path;
    stack<string> s;
    s.push(startNode);
    visited[startNode] = true;
    while (!s.empty()) {
        string currentNode = s.top();
        s.pop();
        for (pair<TravelMethod, string>neighbor : graph[currentNode]) {
            if (!visited[neighbor.second]) {
                //s.push(currentNode);
                s.push(neighbor.second);
                visited[neighbor.second] = true;
                //break;
            }
        }
        path.push_back(currentNode);
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


void Graph::updatePath(string country1, string country2, string methodName, string newmethodName, int newCost) {
    int oldCost;
    for (auto it = graph[country1].begin(); it != graph[country1].end(); it++) {
        if (it->second == country2 && it->first.name == methodName) {
            //oldCost = it->first.cost;
            pair<TravelMethod, string>newItem = { TravelMethod(newmethodName,newCost),country2 };
            graph[country1].erase(it);
            graph[country1].insert(newItem);
            return;
        }
    }
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

string Graph::printGraph() {
    string result;
    bool fl = 0;
    result = " Graph Contents:\n";
    result += "******************\n";
    result += "Countries: \n";
    for (auto it : graph)
        result += "\t" + it.first + "\n";
    result += "====================================\n";
    for (auto& node : graph) {
        result += "Country : " + node.first;
        if (!fl)result += "\n";
        // result+=
        for (const auto& edge : node.second) {
            result += "\t      -> " + edge.second + " (Method: " + edge.first.name + ", Cost: " + std::to_string(edge.first.cost) + ")\n";
        }
        result += "====================================\n\n";
    }
    result += "is Complete Graph? ";
    result += (isComplete() ? "Yes" : "No");
    result += "\n\n**************************************\n";

    return result;
}

void Graph::writeFiles()
{
    ofstream file("Data.txt");
    for (auto country : graph) {
        file << country.first << ' ' << country.second.size();
        for (auto neighbor : country.second)
            file << ' ' << neighbor.first.name << ' ' << neighbor.first.cost << ' ' << neighbor.second;
        file << endl;
    }
    file.close();
}

void Graph::readFiles()
{
    ifstream file("Data.txt");
    string nodeName;
    while (file >> nodeName) {
        graph.insert(make_pair(nodeName, set<pair<TravelMethod, string>>()));    //country node name
        int count;
        file >> count;  // neighbors count
        while (count--) {
            TravelMethod travelMethod;
            string neighborName;
            file >> travelMethod.name >> travelMethod.cost >> neighborName;
            graph[nodeName].insert(make_pair(travelMethod, neighborName));
        }
    }
    file.close();
}


Graph::Graph()
{
    readFiles();
}

Graph::~Graph()
{
    writeFiles();
}