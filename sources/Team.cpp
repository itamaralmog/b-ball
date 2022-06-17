#include "Team.hpp"

using namespace std;

namespace ariel
{
    Team::Team(const string &n, double t)
    {
        this->talent = t;
        this->name = n;
        vic = 0;
        los = 0;
        dis = 0;
        row_victory = 0;
        row_lose = 0;
        middle_row_victory = 0;
        middle_row_lose = 0;
        scored_points = 0;
        absorb_points = 0;
        number_victory_house = 0;
        number_victory_away = 0;
    }
    double Team::get_talent()
    {
        return this->talent;
    }
    string Team::get_name()
    {
        return this->name;
    }
    int Team::get_vic()
    {
        return this->vic;
    }
    void Team::set_vic()
    {
        this->vic++;
    }
    int Team::get_los()
    {
        return this->los;
    }
    void Team::set_los()
    {
        this->los++;
    }
    int Team::get_dis()
    {
        return this->dis;
    }
    void Team::set_dis(int disg)
    {
        this->dis += disg;
    }
    int Team::get_rawvicmax()
    {
        return this->row_victory;
    }
    void Team::set_rawvicmax()
    {
        this->row_victory += 1;
    }
    int Team::get_rawlosmax()
    {
        return this->row_lose;
    }

    void Team::set_rawlosmax()
    {
        this->row_lose++;
    }
    int Team::get_rawvic()
    {
        return this->middle_row_victory;
    }
    void Team::set_rawvic(bool v)
    {
        if (v)
        {
            this->middle_row_victory++;
            if (this->middle_row_victory > this->row_victory)
            {
                this->set_rawvicmax();
            }
        }
        else
        {
            this->middle_row_victory = 0;
        }
    }
    int Team::get_rawlos()
    {
        return this->middle_row_lose;
    }
    void Team::set_rawlos(bool l)
    {
        if (l)
        {
            this->middle_row_lose++;
            if (this->middle_row_lose > this->row_victory)
            {
                this->set_rawlosmax();
            }
        }
        else
        {
            this->middle_row_lose = 0;
        }
    }
    int Team::get_pointget()
    {
        return this->scored_points;
    }
    void Team::set_pointget(int p)
    {
        this->scored_points += p;
    }
    int Team::get_pointset()
    {
        return this->absorb_points;
    }
    void Team::set_pointset(int p)
    {
        this->absorb_points += p;
    }

}
