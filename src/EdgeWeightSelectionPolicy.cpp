#include "../include/SelectionPolicy.h"
#include "Agent.h"
#include "Graph.h"
#include "Coalition.h"

int EdgeWeightSelectionPolicy::Select(vector<int> neighbors, Graph &mGraph, Coalition &coal, int mPartyId)
{
        int maxWeight = 0;
        int PartyRock = -1;
        for (int neighborId : neighbors)
        {
                switch (mGraph.getParty(neighborId).getState())
                {
                case Waiting:
                {
                        if (mGraph.getEdgeWeight(mPartyId, neighborId) > maxWeight)
                        {
                                maxWeight = mGraph.getEdgeWeight(mPartyId, neighborId);
                                PartyRock = neighborId;
                        }
                }
                break;

                case CollectingOffers:
                {
                        bool check = true;
                        for (unsigned int i = 0; i < mGraph.getParty(neighborId).getOffers().size(); i++)
                        { // check if has another offer from coalition
                                if (mGraph.getParty(neighborId).getOffers()[i][1] == coal.getCoalitionId())
                                        check = false;
                        }
                        if (check)
                        {
                                if (mGraph.getEdgeWeight(mPartyId, neighborId) > maxWeight)
                                {
                                        maxWeight = mGraph.getEdgeWeight(mPartyId, neighborId);
                                        PartyRock = neighborId;
                                }
                        }
                }
                break;

                case Joined:
                        break;
                }
        }
        return PartyRock;
}

SelectionPolicy *EdgeWeightSelectionPolicy::Clone() const
{
        return new EdgeWeightSelectionPolicy();
}