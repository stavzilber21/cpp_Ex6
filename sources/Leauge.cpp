#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
#include "Leauge.hpp"
#include "random"
int MAX =20;
using namespace std;
namespace ball{

    Leauge::Leauge(){}

    Leauge::Leauge(vector<Team*> new_team){
        if(new_team.size() > MAX){
            throw invalid_argument("20 is the max number");
        }
        for(unsigned int i = 0; i < MAX ; i++){
            this->teams.push_back(new_team.at(i));
        }
    }
    void Leauge::Leauge_in_random(){
        vector<string>names;
        for (unsigned int i = 0; i < MAX; ++i) {
            char ch = 'a';
            string str;
            str.push_back(ch);
            names.push_back(str);
            ch++;
            str.clear();
        } //'a','b', ...
        double t;
        for (unsigned int i = 0; i < MAX; ++i) {
            t = rand()/RAND_MAX;
            this->teams.push_back(new Team(names.at(i),t));
        }
    }
    void Leauge::Leauge_half(vector<Team*> other_team_list){}
    void Leauge::initial_leauge(){}


}
