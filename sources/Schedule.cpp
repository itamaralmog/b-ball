#include "Schedule.hpp"

using namespace std;

#include <cmath>

namespace ariel
{
    string Schedule::double_round_robin()
    {
        int rounds = ((TEAM - 1) * 2);
        int matchesPerRound = (TEAM / 2);
        for (int round = 0; round < rounds; round++)
        {
            for (int match = 0; match < matchesPerRound; match++)
            {
                int home = (round + match) % (TEAM - 1);
                int away = (TEAM - 1 - match + round) % (TEAM - 1);
                if (match == 0)
                {
                    away = (TEAM - 1);
                }
                string round_string;
                int halfround = (TEAM - 1);
                if (round < halfround)
                {
                    // nba->league
                    games_in_sch.push_back(&nba->league.at((unsigned long)home));
                    games_in_sch.push_back(&nba->league.at((unsigned long)away));
                    round_string = to_string(home + 1) + " - " + to_string(away + 1);
                }
                else
                {
                    games_in_sch.push_back(&nba->league.at((unsigned long)away));
                    games_in_sch.push_back(&nba->league.at((unsigned long)home));
                    round_string = to_string(away + 1) + " - " + to_string(home + 1);
                }
                if (match != 9)
                {
                    sch.at((unsigned long)round) += round_string + " | ";
                }
                else
                {
                    sch.at((unsigned long)round) += round_string;
                }
            }
        }
        for (unsigned long game = 0; game < games_in_sch.size(); game += 2)
        {
            // Game{(games_in_sch.at(game)),(games_in_sch.at(game+1))};
            Game *g = new Game();
            g->calc_winner(*(games_in_sch.at(game)), *(games_in_sch.at(game + 1)));
        }
        string rounds_string;
        for (int round = 0; round < rounds; round++)
        {
            rounds_string += sch.at((unsigned long)round) + "\n";
        }
        return rounds_string;
    }
    std::string Schedule::rounds_results()
    {
        string rounds_result_final = "";
        for (unsigned long t = 1; t < TEAM; t++)
        {
            Team temp = nba->league.at(t);
            int j = t - 1;
            while (j >= 0 && temp.get_vic() >= nba->league.at((unsigned long)j).get_vic())
            {
                nba->league.at((unsigned long)j + 1) = nba->league.at((unsigned long)j);
                j = j - 1;
            }
            nba->league.at((unsigned long)j + 1) = temp;
        }
        for (unsigned long t = 1; t < TEAM; t++)
        {
            Team temp = nba->league.at(t);
            unsigned long j = t - 1;
            while (j >= 0 && temp.get_vic() == nba->league.at(j).get_vic() && abs(temp.get_dis()) > abs(nba->league.at(j).get_dis()))
            {
                nba->league.at(j + 1) = nba->league.at(j);
                j = j - 1;
            }
            nba->league.at(j + 1) = temp;
        }

        int max_name_size = 0;
        for (unsigned long t = 0; t < TEAM; t++)
        {
            if (max_name_size < nba->league.at(t).get_name().size())
            {
                max_name_size = nba->league.at(t).get_name().size();
            }
        }
        string space = "";
        for (int i = 0; i < max_name_size - 5; i++)
        {
            space += " ";
        }
        rounds_result_final += "    ";
        rounds_result_final += "TEAM:";
        rounds_result_final += space;
        rounds_result_final += " |";
        rounds_result_final += "victory:";
        rounds_result_final += "|";
        rounds_result_final += "loses:  ";
        rounds_result_final += " |";
        rounds_result_final += "distance:";
        rounds_result_final += "|";
        rounds_result_final += " set: - get:";
        rounds_result_final += "\n";
        for (unsigned long t = 0; t < TEAM; t++)
        {
            string space1 = "";
            for (int i = 0; i < max_name_size - (int)nba->league.at(t).get_name().size(); i++)
            {
                space1 += " ";
            }
            string space2 = "";
            if (nba->league.at(t).get_vic() < 10)
            {
                space2 = " ";
            }
            string space3 = "";
            if (nba->league.at(t).get_los() < 10)
            {
                space3 = " ";
            }
            string space4 = "";
            if (abs(nba->league.at(t).get_dis()) < 100)
            {
                space4 = " ";
                if (abs(nba->league.at(t).get_dis()) < 10)
                {
                    space4 += " ";
                }
            }
            string space5 = "";
            if (t + 1 < 10)
            {
                space5 = " ";
            }

            rounds_result_final += to_string(t + 1) + ". " + space5 
            + nba->league.at(t).get_name() + space1 
            + " |" + " vic:" + to_string(nba->league.at(t).vic) + space2 
            + " |" + " lose:" + to_string(nba->league.at(t).los) + space3 
            + " |" + " dis:" + to_string(abs(nba->league.at(t).dis)) + space4 
            + " |" + " " + to_string(nba->league.at(t).absorb_points) +
            +" - " + to_string(nba->league.at(t).scored_points) + "\n";
        }
        return rounds_result_final;
    }
    int Schedule::ret_raw_vic_max()
    {
        int max = 0;
        for (unsigned long t = 0; t < TEAM; t++)
        {
            if (max < nba->league.at(t).row_victory)
            {
                max = nba->league.at(t).row_victory;
            }
        }
        return max;
    }
    int Schedule::ret_raw_los_max()
    {
        int max = 0;
        for (unsigned long t = 0; t < TEAM; t++)
        {
            if (max < nba->league.at(t).row_lose)
            {
                max = nba->league.at(t).row_lose;
            }
        }
        return max;
    }
    int Schedule::ret_amount_of_get_vs_set()
    {
        int max = 0;
        for (unsigned long t = 0; t < TEAM; t++)
        {
            if (nba->league.at(t).get_pointset() > nba->league.at(t).get_pointget())
            {
                max++;
            }
        }
        return max;
    }
    int Schedule::max_victory_house()
    {
        int max = 0;
        for (unsigned long i = 0; i < TEAM; i++)
        {
            if (nba->league.at(i).number_victory_house > max)
            {
                max = nba->league.at(i).number_victory_house;
            }
        }
        return max;
    }
    int Schedule::max_victory_away()
    {
        int max = 0;
        for (unsigned long i = 0; i < TEAM; i++)
        {
            if (nba->league.at(i).number_victory_away > max)
            {
                max = nba->league.at(i).number_victory_away;
            }
        }
        return max;
    }
}