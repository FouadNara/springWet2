// 
// 234218 Data Structures 1.
// Semester: 2023A (winter).
// Wet Exercise #2.
// 
// Recommended TAB size to view this file: 8.
// 
// The following header file contains all methods we expect you to implement.
// You MAY add private methods and fields of your own.
// DO NOT erase or modify the signatures of the public methods.
// DO NOT modify the preprocessors in this file.
// DO NOT use the preprocessors in your other code files.
// 

#ifndef WORLDCUP23A2_H_
#define WORLDCUP23A2_H_

#include "wet2util.h"
#include "AVLtree.h"

#define TIE 0
#define FIRST_WON_BY_ABILITY 1
#define FIRST_WON_BY_SPIRIT 2
#define SEC_WON_BY_ABILITY 3
#define SEC_WON_BY_SPIRIT 4

#define WINNER_POINTS 3
#define TIE_POINTS 1

class world_cup_t {
private:
	//
	// Here you may add anything you want
	//
	AVLtree<TeamID> teamsByID;
	AVLtree<PointlessAbility> teamsByPointless;
	HashTable players;

	// AUX_FUNCTIONS
	int compare( int first, int sec, int first_is_winner, int sec_is_winner)
	{
		if(first > sec)
		{
			return first_is_winner;
		}
		else if (first < sec)
		{
			return sec_is_winner;
		}
		return TIE;
	}
	
public:
	// <DO-NOT-MODIFY> {
	
	world_cup_t();
	virtual ~world_cup_t();
	
	StatusType add_team(int teamId);
	
	StatusType remove_team(int teamId);
	
	StatusType add_player(int playerId, int teamId,
	                      const permutation_t &spirit, int gamesPlayed,
	                      int ability, int cards, bool goalKeeper);
	
	output_t<int> play_match(int teamId1, int teamId2);
	
	output_t<int> num_played_games_for_player(int playerId);
	
	StatusType add_player_cards(int playerId, int cards);
	
	output_t<int> get_player_cards(int playerId);
	
	output_t<int> get_team_points(int teamId);
	
	output_t<int> get_ith_pointless_ability(int i);
	
	output_t<permutation_t> get_partial_spirit(int playerId);
	
	StatusType buy_team(int teamId1, int teamId2);
	
	// } </DO-NOT-MODIFY>
};

#endif // WORLDCUP23A1_H_
