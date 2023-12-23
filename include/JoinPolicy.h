#pragma once
#include <vector>

using std::vector;
class Party;
class Coalition;
class Simulation;

class JoinPolicy 
{
    public:
        virtual void Join(Simulation &simulation, Party &p)=0;
        virtual JoinPolicy* Clone() const=0;
        virtual ~JoinPolicy()  = default;

};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        void Join(Simulation &simulation, Party &p) override;
        JoinPolicy* Clone() const override;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        void Join(Simulation &simulation, Party &p) override;
        JoinPolicy* Clone() const override;
};