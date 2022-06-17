#pragma once
#include "Game.hpp"
#include "Leauge.hpp"
// #include "Team.hpp"
#include <iostream>

#define TEAM 20
// using namespace std;

namespace ariel
{
    class Schedule
    {
    // private:
        // std::vector<Team *> teams_in;


    public:
        League *nba;
        std::vector<std::string> sch; // schedule
        std::vector<Team *> games_in_sch;
        Schedule(std::vector<Team> teams)
        {

            this->nba = new League(teams);
            sch.assign(((TEAM - 1) * 2), " ");
        }
        ~Schedule() = default;
        std::string double_round_robin();
        std::string rounds_results();
        int ret_raw_vic_max();
        int ret_raw_los_max();
        int ret_amount_of_get_vs_set();
        int max_victory_house();
        int max_victory_away();
    };

}

// 1 - 20 | 2 - 18 | 3 - 17 | 4 - 16 | 5 - 15 | 6 - 14 | 7 - 13 | 8 - 12 | 9 - 10