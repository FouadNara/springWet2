#include "Node.h"
#include "Team.h"

bool invertedNode::isEliminated() const
{
    return eliminated;
}

invertedNode* invertedNode::getParent() const
{
    return parent;
}

Player* invertedNode::getPlayer() const
{
    return player_ptr;
}

Team* invertedNode::getTeam() const
{
    return team_ptr;
}

int invertedNode::getMatches() const
{
    return numOfMatches;
}

permutation_t invertedNode::getPartialPermutation() const
{
    return partial_spirit;
}

void invertedNode::setEliminated() 
{
    eliminated = true;
}

void invertedNode::setParent(invertedNode* other)
{
    parent = other;
}

void invertedNode::setTeam(Team* team)
{
    team_ptr = team;
}

void invertedNode::setMatches(int value)
{
    numOfMatches = value;
}

void invertedNode::increaseMatches()
{
    numOfMatches += 1;
}
void invertedNode :: setPartial_spirit (permutation_t value)
{
    partial_spirit = value;
}

void invertedNode::nullifyPlayer()
{
    player_ptr = nullptr;
}