#include "../include/SelectionPolicy.h"
#include "Agent.h"
#include "Graph.h"
#include "Coalition.h"

int MandatesSelectionPolicy::Select(vector<int> neighbors, Graph &mGraph, Coalition &coal, int mPartyId)
{
        int maxMandates = 0;
        int PartyRock = -1;
        for (int neighborId : neighbors)
        {
                switch (mGraph.getParty(neighborId).getState())
                {
                case Waiting:
                {
                        if (mGraph.getParty(neighborId).getMandates() > maxMandates)
                        {
                                maxMandates = mGraph.getParty(neighborId).getMandates();
                                PartyRock = neighborId;
                        }
                }
                break;

                case CollectingOffers:
                {
                        bool check = true;
                        for (vector<int> &offer : mGraph.getParty(neighborId).getOffers())
                        {
                                if (offer[1] == coal.getCoalitionId())
                                        check = false;
                        }
                        if (check)
                        {
                                if (mGraph.getParty(neighborId).getMandates() > maxMandates)
                                {
                                        maxMandates = mGraph.getParty(neighborId).getMandates();
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

SelectionPolicy *MandatesSelectionPolicy::Clone() const
{
        return new MandatesSelectionPolicy();
}