#include "Game.hpp"
#pragma once
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
    }

    void Game::start_game(){
        this->team_in->points_good=(rand()%(100-55+1))+55;
        this->team_out->points_good=(rand()%(100-50+1))+50;
        team_in->points_good+=10;
        team_out->points_good+=10;
    }

    string Game:: winner(){
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

            return team_in->name;
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
            return team_out->name;
        }
    }

}