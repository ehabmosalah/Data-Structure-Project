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