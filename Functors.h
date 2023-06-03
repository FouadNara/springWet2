#ifndef FUNCTORS_H_
#define FUNCTORS_H_
#include "Team.h"


class TeamID
{
    public:
    int operator()(const Team* team1, const Team* team2) const
    {
        if(team1->getTeamID() < team2->getTeamID())
        {
            return -1;
        }
        if(team1->getTeamID() > team2->getTeamID())
        {
            return 1;
        }
        return 0;
    }
};


class PointlessAbility
{
    public:
    int operator()(const Team* team1, const Team* team2) const
    {
        if(team1->getTeamSigma() < team2->getTeamSigma())
        {
            return -1;
        }
        if(team1->getTeamSigma() > team2->getTeamSigma())
        {
            return 1;
        }
        TeamID temp;
        int res = temp(team1,team2);
        return res;
    }
};

#endif