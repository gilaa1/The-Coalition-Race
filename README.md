# The Coalition Race

In a faraway democracy, SPLand, there is a political crisis, they can't form a government in
years. The SPLand president decided to change the method of forming a coalition by
letting multiple "agents" from different parties try their best to create a 61 coalition as fast as
possible.

The simulator is based on a graph that contains:

  ● Parties as vertices
  
  ● Collaborations as edges (2 parties that agree to cooperate)
  
  ● “Similarity score” as edge weight, for every 2 connected parties

Here is an example for a graph at the beginning of the simulation. The colors represent the
state of the parties (will be explained later).

<img width="330" alt="image" src="https://github.com/gilaa1/The-Coalition-Race/assets/118897225/68f4b374-e5df-424c-89ff-5dae6494ae15">

The program will receive a config file (JSON) as input, which includes the parties' details (id,
name, number of mandates, join policy), the graph, and the list of agents (id, party id, selection
policy). “Join policy” and “Selection policy” will be explained later.
Each agent belongs to a party. In every step, the agent offers an adjacent party to join. When a
party has decided to join a coalition, it should clone the agent who made the offer to the
newly joined party (so the joined party can now help the coalition).
To clarify:

● Coalition is a set of connected parties (in SPLand, connectivity is enough).

● In each party, there is a single agent if the party belongs to a coalition (state Joined).

● The total number of agents in the simulation equals the number of parties in the graph
belonging to some coalition (state Joined).

**Example
**Suppose an agent from party#0 offered party#1 to join its coalition.
If party#1 accepts the offer, it adds itself to the coalition and adds a clone of the agent to the
vector of agents (as well as updating the id and party id).

<img width="401" alt="image" src="https://github.com/gilaa1/The-Coalition-Race/assets/118897225/ee639b12-4c7d-45e3-89e7-e4e3cd245e8b">

**Classes-**

**Simulation** - This class is responsible for managing the simulation resources and making
simulation steps. This object is created by Parser using the
initial values from the JSON configuration file. The Simulation object contains

  ● Graph
  
  ● Vector of Agents

**Graph** – This class is represented by an adjacency matrix (edges) and parties vector
(vertices). Since the graph is undirected, you may assume that the matrix is symmetric.
Note that an edge exists if and only if the weight is greater than 0.

**Party** – A vertex in the graph. Each party has an id, name, number of mandates, join policy
and party state. The states are:
1. Waiting (Green in Image) - the party is not a part of any coalition yet, and also didn’t get offers yet.
2. CollectingOffers (Orange in Image)- after receiving the first offer, the party changes its state and starts
collecting offers from Agents for joining coalitions.
The party has a “cooldown” - a timer of exactly 3 iterations, until moving to the next
state by joining some coalition. Note, if a party got the first offer at the end of iteration 𝑖,
it will join some coalition at the beginning of iteration 𝑖 + 3.
Note - the iteration is counted even if the party did not get an offer in that iteration.
3. Joined (Red in Image)- after 3 iterations, the party uses JoinPolicy::join(...) method for deciding which
offer to accept. After joining a coalition, the party’s state won’t change anymore and it
cannot join any other coalitions

**Agent** – This class has agentId, partyId (each agent associated with a single party), and
selection policy. In each step, an agent is trying to select a neighboring party (in the graph)
using SelectionPolicy::select(...) and offers the party to join its coalition.
SelectionPolicy - an abstract class that represents a strategy algorithm for selecting the next
party to offer. It has the abstract method SelectionPolicy::select(...) that will be implemented in
the derived classes:

  ● MandatesSelectionPolicy - Selects the neighboring party with the most mandates.
  
  ● EdgeWeightSelectionPolicy - Selects the neighboring party with the highest edge weight.
  
If the maximum mandates/edge weight is not unique, take the first party (with the lower id).



## Copyright Notice

© 2023/Fall by Ronit Kfir and Gil Adi.

This project is a result of academic work completed as part of the Computer Science program at Ben-Gurion University of the Negev.

All rights reserved. Unauthorized use, distribution, or reproduction of this work without express written permission from the author is strictly prohibited.

For inquiries, please contact [Your Email Address].
