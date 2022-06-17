#include "doctest.h"

#include <iostream>
#include <random>

#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace doctest;

TEST_CASE("Game"){
    ariel::Team a{"nuggets1",0.999};
    ariel::Team b{"nets",0.87};
    std::vector<ariel::Team> teams_in_from_main;
    teams_in_from_main.push_back(a);
    teams_in_from_main.push_back(b);
    ariel::Schedule nba_s{teams_in_from_main};

    CHECK(nba_s.nba->league.at(0).get_name() == "nuggets1");
    for(unsigned long i = 0 ; i < nba_s.nba->league.size() ; i++){
        CHECK_EQ(0,nba_s.nba->league.at(i).get_los()+nba_s.nba->league.at(i).get_vic());
    }
    nba_s.double_round_robin();
    nba_s.rounds_results();
    for(unsigned long i = 0 ; i < nba_s.nba->league.size() ; i++){
        CHECK_EQ(38,nba_s.nba->league.at(i).get_los()+nba_s.nba->league.at(i).get_vic());
    }

    for(unsigned long i = 0 ; i < nba_s.nba->league.size() ; i++){
        if(nba_s.nba->league.at(i).get_talent() >= 0 && nba_s.nba->league.at(i).get_talent() <=1 ){
            CHECK_EQ(true,true);
        }
        else{
            CHECK_EQ(true,false);
        }
    }

    for(unsigned long i = 0 ; i < nba_s.nba->league.size() ; i++){
        if(nba_s.nba->league.at(i).get_pointget() <= 3800 && nba_s.nba->league.at(i).get_pointset() <= 3800 ){
            CHECK_EQ(true,true);
        }
        else{
            CHECK_EQ(true,false);
        }
    }

    for(unsigned long i = 0 ; i < nba_s.nba->league.size()-1 ; i++){
        if(nba_s.nba->league.at(i).get_vic() >=  nba_s.nba->league.at(i+1).get_vic()){
            CHECK_EQ(true,true);
        }
        else{
            CHECK_EQ(true,false);
        }
    }

    
    

}