#pragma once

#include <vector>
#include <string>

#include "Agent.h"
#include "Graph.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Party;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const;
    Coalition &getCoalition(int coalitionId);
    vector<Agent> &getAgents();
    void addPartyToCoal(int CoalitionId, int PartyId);
    void addPartyToActual(int CoalitionId, int PartyId, int Mandates);


private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> coalitions;
    vector<Coalition> mActualCoalitions;
};

