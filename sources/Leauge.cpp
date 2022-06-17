#include "Leauge.hpp"

namespace ariel
{

    League::League(std::vector<Team> teams)
    {
        this->league=teams;
        if(this->league.size()< MAX_TEAMS){
            this->league.emplace_back(Team{"nuggets",0.999});
        }
        for(unsigned long i = this->league.size() ; i < MAX_TEAMS ; i++){
            std::srand(static_cast<unsigned int>(std::time(nullptr))); 
            int rand_number = std::rand();
            int rand_20 = rand_number%20;
            while(this->is_in(names.at((unsigned long)rand_20))){
                rand_number = std::rand();
                rand_20 = rand_number%20;
            }
            std::srand( (unsigned)time( NULL ));
            float random_talent = (float) rand()/RAND_MAX;
            double rt = (double)random_talent;
            this->league.emplace_back(Team{names.at((unsigned long)rand_20),rt});
        }
    }
    bool League::is_in(std::string &str){
        for(unsigned long i = 0 ; i < this->league.size() ; i++){
            if(this->league.at(i).get_name() == str){
                return true;
            }
        }
        return false;
    }

}