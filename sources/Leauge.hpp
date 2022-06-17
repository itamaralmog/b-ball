#pragma once

#include "Team.hpp"

#include <time.h>
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <vector>

const unsigned long MAX_TEAMS = 20;
// using namespace std;

namespace ariel
{
    inline std::vector<std::string> names = {"nuggets", "lakers", "jass", "suns", "kings", "76ers", "raptors", "bulls", "bucks", "pacers", "heat", "magic", "spurs", "nets", "knicks", "pistons", "hornets", "warriors", "hawks", "clippers"};
    inline std::vector<double> talent_teams = {0.99, 0.92, 0.93, 0.97, 0.89, 0.99, 0.82, 0.99, 0.90, 0.81, 0.97, 0.87, 0.84, 0.85, 0.81, 0.82, 0.79, 0.99, 0.79, 0.85};
    class League
    {
        // private:
        //     std::vector<Team *> league;

    public:
        std::vector<Team> league;
        League(std::vector<Team> teams);
        bool is_in(std::string &str);
        ~League() = default;
    };
}