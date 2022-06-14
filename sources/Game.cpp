#include "Game.hpp"
//#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Team.hpp"
#include "random"
using namespace std;
namespace ball {

    Game::Game(Team* in,Team* out ){
        this->team_in=in;
        this->team_out=out;
        team_in->points_good = start_game(55,100);
        team_out->points_good = start_game(50,100);
        if(team_in->talent>team_out->talent){
            team_in->points_good+=10;
        }
        else{
            team_out->points_good+=10;
        }
        cout<<"the points of team home: "<<endl;
        cout<<team_in->points_good <<endl;
        cout<<"the points of team out: " <<endl;
        cout<<team_out->points_good<<endl;
        winner();
    }

    int Game::start_game(double min, double max){
        double e = (min + max)/2;
        double sigma = (max - min)/6;
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<float> d(e, sigma);
        return static_cast<int>(round(d(gen)));
    }

    void Game:: winner(){
        if(team_in->points_good > team_out->points_good){
            team_in->num_wins+=1;
            team_out->num_losses+=1;
            team_in->num_wins_in_a_row+=1;
            team_out->num_losses_in_a_row+=1;
            if(team_in->num_wins_in_a_row > team_in->num_wins_in_a_row_last){
                team_in->num_wins_in_a_row_last=team_in->num_wins_in_a_row;
            }
            if(team_out->num_losses_in_a_row > team_out->num_losses_in_a_row_last){
                team_out->num_losses_in_a_row_last=team_out->num_losses_in_a_row;
            }
            team_in->num_losses_in_a_row=0;
            team_out->num_wins_in_a_row=0;

            cout<<"The group winner is: " << this->team_in->name << endl;
        }
        else if(team_in->points_good <= team_out->points_good){
            team_out->num_wins+=1;
            team_in->num_losses+=1;
            team_out->num_wins_in_a_row+=1;
            team_in->num_losses_in_a_row+=1;
            if(team_out->num_wins_in_a_row > team_out->num_wins_in_a_row_last){
                team_out->num_wins_in_a_row_last=team_out->num_wins_in_a_row;
            }
            if(team_in->num_losses_in_a_row > team_in->num_losses_in_a_row_last){
                team_in->num_losses_in_a_row_last=team_in->num_losses_in_a_row;
            }
            team_out->num_losses_in_a_row=0;
            team_in->num_wins_in_a_row=0;
            cout<<"The group winner is: " << this->team_out->name << endl;
        }
    }

}