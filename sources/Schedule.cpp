//#pragma once
#include "Schedule.hpp"
#include <iostream>
#include <vector>
#include "Leauge.hpp"
#include "Game.hpp"
using namespace std;
namespace ball{
    Schedule::Schedule(vector<Team*> other){
        this->teams=other;
    }
    vector<Game*>Schedule:: schedule (){
        if(this->teams.empty() || this->teams.size()>20){
            throw invalid_argument("the size of teams invalid");
        }
        vector<Game*> games;
        for (unsigned int i = 0; i < this->teams.size(); i++) {
            for (unsigned int j = i; j < this->teams.size(); j++) {
                if(i!=j){
                    games.push_back(new Game(this->teams.at(i), this->teams.at(j)));
                }
            }
        }
        for (unsigned int i = 0; i < this->teams.size(); i++) {
            for (unsigned int j = i; j < this->teams.size(); j++) {
                if(i!=j){
                    games.push_back(new Game(this->teams.at(j), this->teams.at(i)));
                }
            }
        }
        for (unsigned int i = 0; i < games.size(); ++i) {
            if(games.at(i)->team_in->points_good==games.at(i)->team_out->points_good){
                this->num_of_teko+=1;
            }
        }
        return games;
    }


}

