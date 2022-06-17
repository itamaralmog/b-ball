#pragma once

#include <iostream>

#include "Team.hpp"

namespace ariel
{
    class Game
    {
    private:
        Team *home;
        Team *away;
        // std::string winner;

    public:
        Game() //Team &h, Team &a
        {
           // The team that win
        // The winner
        // this->winner = home->get_name();

        }
        ~Game() = default;
        // std::string get_winner();
        void calc_winner(Team &h, Team &a);
    };
}

// 1-20|2-19|3-18|4-17|5-16|6-15|7-14|8-13|9-12|10-11