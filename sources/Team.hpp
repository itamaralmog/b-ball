#pragma once

#include <iostream>

namespace ariel
{
    class Team
    {
    private:
    public:
        double talent;
        std::string name;
        int vic;
        int los;
        int dis;
        int row_victory;
        int row_lose;
        int middle_row_victory;
        int middle_row_lose;
        int scored_points;
        int absorb_points;
        int number_victory_house;
        int number_victory_away;
        Team(const std::string& n, double t);
        ~Team() = default;
        double get_talent();
        std::string get_name();
        int get_vic();
        void set_vic(); /////
        int get_los();
        void set_los(); ///////
        int get_dis();
        void set_dis(int disg); //////
        int get_rawvicmax();
        void set_rawvicmax();
        int get_rawlosmax();
        void set_rawlosmax();
        int get_rawvic();
        void set_rawvic(bool v); /////
        int get_rawlos();
        void set_rawlos(bool l); /////
        int get_pointget();
        void set_pointget(int p); //////
        int get_pointset();
        void set_pointset(int p); ///////
    };

}
