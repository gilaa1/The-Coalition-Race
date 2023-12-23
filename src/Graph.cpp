#include "Graph.h"
#include "Coalition.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges)
{
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{

    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return (mVertices[partyId]);
}

Party &Graph::getParty(int partyId)
{
    return (mVertices[partyId]);
}

const vector<int> Graph::getNeighborsOf(int id) const
{
    vector<int> Neighbors{};
    for (unsigned int i = 0; i < mEdges[id].size(); i++)
    {
        if (mEdges[id][i] > 0)
            Neighbors.push_back(i);
    }
    return Neighbors;
}

void Graph::addOffer(int PartyId, Coalition &coalition)
{
    vector<int> info = vector<int>{};
    info.push_back(coalition.getCoalitionMandates());
    info.push_back(coalition.getCoalitionId());
    getParty(PartyId).getOffers().push_back(info);
    if (getParty(PartyId).getState() == Waiting)
    {
        getParty(PartyId).setState(CollectingOffers);
        getParty(PartyId).setTimer();
    }
}

vector<Party> &Graph::getVertices()
{
    return mVertices;
}

const vector<Party> &Graph::getVertices() const
{
    return mVertices;
}
