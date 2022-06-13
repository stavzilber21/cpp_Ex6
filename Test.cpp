#pragma once
#include "doctest.h"
#include <vector>
#include <stdexcept>
#include <string>

//#include "sources/Team.cpp"
#include "sources/Game.cpp"
#include "sources/Leauge.cpp"
#include "sources/Schedule.cpp"

using namespace std;
using namespace ball;

TEST_CASE ("CHECK 1"){
    CHECK(new Team("a",0.5));
    CHECK(new Team("b",0.5));
    CHECK(new Team("c",0.5));
    CHECK(new Team("d",0.5));
    CHECK(new Team("s",0.5));
    CHECK_THROWS(new Team(" ",0.5));
    CHECK_THROWS(new Team("\n",0.5));
    CHECK_THROWS(new Team("\t",0.5));
    Team* t = new Team("a",0.5);
    Leauge leauge;
    vector<Team*> te;
    double tal;
    int new_name = 0;
    for (unsigned int i = 0; i < 20; ++i) {
        tal = rand() % 1;
        te.push_back(new Team(to_string(new_name), tal));
        new_name += 1;
    }
    Schedule schedule(te);
    CHECK(leauge.teams=te);
    CHECK_EQ(te.size(),20);
    CHECK_NE(t->name,"stav");
    te.push_back(t);
    CHECK_THROWS(leauge.teams=te); //bigger 20
}

TEST_CASE ("CHECK 2"){
    Team* t1 = new Team("a",0.5);
    Team* t2 = new Team("b",0.4);
    Game game(t1, t2);
    CHECK_EQ(t1->talent,0.5);
    CHECK_NE(t1->talent,0.6);
    CHECK_EQ(t2->talent,0.4);
    CHECK_NE(t2->talent,0.6);
    CHECK_EQ(t1->name,"a");
    CHECK_NE(t1->name,"stav");
    CHECK_EQ(t2->name,"b");
    CHECK_NE(t2->name,"a");
}