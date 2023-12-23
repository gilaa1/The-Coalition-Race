#include "Coalition.h"
#include "Simulation.h"

Coalition::Coalition(int mandates, int partyId, int coalitionId) : mCoalitionMandates(mandates), mPartiesIds{}, mCoalitionId(coalitionId)
{
    mPartiesIds.push_back(partyId);
}

int Coalition::getCoalitionMandates() const
{
    return mCoalitionMandates;
}

int Coalition::getCoalitionId() const
{
    return mCoalitionId;
}

void Coalition::addParty(int mandates, int id)
{
    mCoalitionMandates += mandates;
    mPartiesIds.push_back(id);
}