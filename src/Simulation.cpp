#include "Simulation.h"
#include "Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions{}, mActualCoalitions{}
{
    // initial coalitions
    for (unsigned int i = 0; i < mAgents.size(); i++)
    {
        vector<int> coal = vector<int>{};
        coal.push_back(mAgents[i].getPartyId());
        coalitions.push_back(coal); // initial output vector
        Coalition actual(mGraph.getParty(mAgents[i].getPartyId()).getMandates(), mAgents[i].getPartyId(), i);
        mActualCoalitions.push_back(actual); // initial coalitions vector
        mGraph.getParty(mAgents[i].getPartyId()).setCoalitionId(i);
    }
}

void Simulation::step()
{
    if (!shouldTerminate())
    {
        for (int i = 0; i < mGraph.getNumVertices(); i++)
            mGraph.getParty(i).step(*this);
        for (unsigned int i = 0; i < mAgents.size(); i++)
            mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    bool check = false;
    for (unsigned int i = 0; i < mActualCoalitions.size(); i++)
    {
        if (mActualCoalitions[i].getCoalitionMandates() >= 61)
        {
            check = true;
        }
    }
    if (!check)
    {
        bool check2 = true;
        for (int i = 0; i < mGraph.getNumVertices(); i++)
        {
            if (mGraph.getParty(i).getState() != Joined)
            {
                check2 = false;
                break;
            }
        }
        if (check2)
            check = true;
    }
    return check;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent> &Simulation::getAgents()
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}

Coalition &Simulation::getCoalition(int coalitionId)
{
    return mActualCoalitions[coalitionId];
}

const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return coalitions;
}

void Simulation::addPartyToCoal(int CoalitionId, int PartyId)
{ // add party to output vector
    coalitions[CoalitionId].push_back(PartyId);
}
void Simulation::addPartyToActual(int CoalitionId, int PartyId, int Mandates)
{ // add party to coalition and clone agent
    mActualCoalitions[CoalitionId].addParty(Mandates, PartyId);
    int agentId = mAgents.size();
    Agent newAgent = Agent(mAgents[CoalitionId]);
    newAgent.setAgentId(agentId);
    newAgent.setPartyId(PartyId);
    newAgent.setIsIdle(false);
    mAgents.push_back(newAgent);
}