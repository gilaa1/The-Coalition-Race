#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
#include "Coalition.h"
#include "Party.h"

void LastOfferJoinPolicy::Join(Simulation &simulation, Party &p)
{
  int coalitionId = p.getOffers()[p.getOffers().size() - 1][1];
  simulation.addPartyToCoal(coalitionId, p.getId());
  simulation.addPartyToActual(coalitionId, p.getId(), p.getMandates());
  p.setCoalitionId(coalitionId);
}

JoinPolicy *LastOfferJoinPolicy::Clone() const
{
  return new LastOfferJoinPolicy();
}
