#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
#include "Coalition.h"
#include "Party.h"

void MandatesJoinPolicy::Join(Simulation &simulation, Party &p)
{
    int maxMandates = 0;
    int maxCoalitionId = -1;
    // choose coalition to join
    for (unsigned int i = 0; i < p.getOffers().size(); i++)
    {
        if (p.getOffers()[i][0] > maxMandates)
        {
            maxMandates = p.getOffers()[i][0];
            maxCoalitionId = p.getOffers()[i][1];
        }
    }
    simulation.addPartyToCoal(maxCoalitionId, p.getId());
    simulation.addPartyToActual(maxCoalitionId, p.getId(), p.getMandates());
    p.setCoalitionId(maxCoalitionId);
}

JoinPolicy *MandatesJoinPolicy::Clone() const
{
    return new MandatesJoinPolicy();
}
