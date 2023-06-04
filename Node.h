#ifndef NODE_H_
#define NODE_H_

//I THINK IT IS BETTER TO WRITE IT AGAIN...

#include "HashTable.h"
//class Team;

//Node for inverted tree
class invertedNode
{
    public:
    invertedNode(Player* player, permutation_t perm)
    :eliminated(false),parent(nullptr), player_ptr(player), team_ptr(nullptr), numOfMatches(0), partial_spirit(perm)
    {}

    //GETTERS
    bool isEliminated() const;
    invertedNode* getParent() const;
    Player* getPlayer() const; 
    Team* getTeam() const;
    int getMatches() const;
    permutation_t getPartialPermutation() const;

    //SETTERS
    void setEliminated();
    void setParent(invertedNode* other);
    void setTeam(Team* team);
    void setMatches(int value);
    void increaseMatches();
    void setPartial_spirit(permutation_t value);
    void nullifyPlayer(); //ONLY USED IN DESTRUCTORS
    

    private:
    invertedNode* parent; 
    Player* player_ptr;
    Team* team_ptr;
};

#endif // NODE_H_