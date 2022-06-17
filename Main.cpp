#include <iostream>
#include <random>

#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

// #include "doctest.h"

int main()
{
    ariel::Team a{"nuggets1",0.99};
    std::vector<ariel::Team> teams_in_from_main;
    teams_in_from_main.push_back(a);
    ariel::Schedule nba_s{teams_in_from_main};
    std::cout << nba_s.double_round_robin() << std::endl;
    std::cout << nba_s.rounds_results() << std::endl;
    std::cout << nba_s.ret_raw_vic_max() << std::endl;
    std::cout << nba_s.ret_raw_los_max() << std::endl;
    std::cout << nba_s.ret_amount_of_get_vs_set() << std::endl;
    std::cout << nba_s.max_victory_house() << std::endl;
    std::cout << nba_s.max_victory_away() << std::endl;
}