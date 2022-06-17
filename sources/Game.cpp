
#include <random>

#include "Game.hpp"

namespace ariel
{
    using namespace std;
    void Game::calc_winner(Team &h, Team &a)
    {
        unsigned int some = 50;
        unsigned seed = some;
        std::default_random_engine e(seed);
        std::normal_distribution<> d{75, 19};
        std::normal_distribution<> d1{74, 20};
        int sum_name = 0;

        // For uniq distribution use ascii of the names and run it in
        // a loop in order to get random answer
        for (unsigned long i = 0; i < h.get_name().size(); i++)
        {
            if (h.get_los() + h.get_vic() < 19)
            {
                sum_name += int(h.get_name().at(i)) + int(a.get_name().at(0));
            }
            else
            {
                sum_name += int(h.get_name().at(i)) + int(a.get_name().at(0));
            }
        }
        int home_result = d(e);
        int away_result = d1(e);
        for (unsigned long i = 0; i < sum_name; i++)
        {
            home_result = d(e);
            away_result = d(e);
        }
        while (((home_result < 55) || (home_result > 100)) || ((away_result < 50) || (away_result > 100)))
        {
            home_result = d(e);
            away_result = d(e);
        }

        int dis_final = 0;
        bool victory = true;
        if (h.get_talent() > a.get_talent())
        {
            home_result += 10;
        }
        else
        {
            away_result += 10;
        }
        if (home_result > away_result)
        {
            dis_final = home_result - away_result;
        }
        else if (home_result < away_result)
        {
            dis_final = away_result - home_result;
            victory = false;
        }
        else
        {
            dis_final = away_result - home_result;
            if (away_result % 2 == 0)
            {
                victory = false;
            }
        }

        // if(h.get_name() == "nuggets" || a.get_name() == "nuggets"){
        //     cout << 1+ h.get_los() + h.get_vic() << ". " + h.get_name() + " vs. " + a.get_name() + " ";
        //     cout << home_result << " " << away_result << endl;
        // }

        if (victory)
        {
            h.number_victory_house++;
            h.set_dis(dis_final);
            a.set_dis(-dis_final);
            h.set_vic();
            a.set_los();
        }
        else
        {
            a.number_victory_away++;
            h.set_dis(-dis_final);
            a.set_dis(dis_final);
            a.set_vic();
            h.set_los();
        }
        h.set_rawvic(victory);
        h.set_rawlos(!victory);
        h.set_pointset(home_result);
        h.set_pointget(away_result);

        a.set_rawvic(!victory);
        a.set_rawlos(victory);
        a.set_pointset(away_result);
        a.set_pointget(home_result);
    }
}