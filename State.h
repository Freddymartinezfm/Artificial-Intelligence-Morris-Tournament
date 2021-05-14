#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>

// int evaluated = 0;


class State {
    int min_max_value;
    int alpha;
    int beta;
    std::string current_board;
    std::string best_board;
    int depth_limit;

    State();

    State(int v, const std::string b);
    bool is_full(const State &state);

    
    int static_estimation (State &s);

    std::list<int> neighbors(int location);

    friend class Game;

};

#endif