#pragma once
#include <vector>
#include "Party.h"

using std::string;
using std::vector;

class Coalition;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    const vector<int> getNeighborsOf(int id) const;
    void addOffer(int PartyId, Coalition &coalition);
    vector<Party> &getVertices();
    const vector<Party> &getVertices() const;


private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
