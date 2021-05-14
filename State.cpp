#include "State.h"
#include <iostream>
#include <string>
#include <fstream>


 State::State(){

 }

State::State(int v, const std::string b) : min_max_value(v), current_board(b), best_board(""), depth_limit(0), alpha(0), beta(0){
       for (int i = 0; i < BOARD_SIZE; i++){
           current_board[i] = b[i];
       }
    }

    bool State::is_full(const State &state){
        for (int i = 0; i < BOARD_SIZE; i++){
            if (state.current_board[i] == 'x'){
                return false;
            }
        }
        return true;
    }


int State::static_estimation (State &s) {
    int numWhitePieces = 0;
    int numBlackPieces = 0;
    
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++){
        if (s.current_board[i] == 'B'){
            numBlackPieces++;
        } else if (s.current_board[i] == 'W') { 
            numWhitePieces++;
        }  
    }
    this->min_max_value = (numWhitePieces - numBlackPieces);
    this->best_board = s.current_board;
    return (numWhitePieces - numBlackPieces);
}


std::list<int> State::neighbors(int location){
    std::list<int> neighbors;
    switch (location) {
        case 0:
            neighbors.push_back(1);
            neighbors.push_back(3);
            neighbors.push_back(8);
            return neighbors;
            break;
        case 1:
            neighbors.push_back(0);
            neighbors.push_back(4);
            neighbors.push_back(2);
            break;
        case 2:
            neighbors.push_back(1);
            neighbors.push_back(5);
            neighbors.push_back(3);
            break;
        case 3:
            neighbors.push_back(0);
            neighbors.push_back(6);
            neighbors.push_back(4);
            break;
        case 4:
            neighbors.push_back(3);
            neighbors.push_back(5);
            neighbors.push_back(1);
            break;
        case 5:
            neighbors.push_back(4);
            neighbors.push_back(7);
            neighbors.push_back(12);
            break;
        case 6:
            neighbors.push_back(3);
            neighbors.push_back(7);
            neighbors.push_back(10);
            break;
        case 7:
            neighbors.push_back(6);
            neighbors.push_back(11);
            neighbors.push_back(5);
            break;
        case 8:
            neighbors.push_back(20);
            neighbors.push_back(0);
            neighbors.push_back(9);
            break;
        case 9:
            neighbors.push_back(8);
            neighbors.push_back(17);
            neighbors.push_back(3);
            neighbors.push_back(10);
            break;
        case 10:
            neighbors.push_back(9);
            neighbors.push_back(14);
            neighbors.push_back(6);
            break;
        case 11:
            neighbors.push_back(7);
            neighbors.push_back(12);
            neighbors.push_back(16);
            break;
        case 12:
            neighbors.push_back(5);
            neighbors.push_back(11);
            neighbors.push_back(13);
            neighbors.push_back(19);
            break;
        case 13:
            neighbors.push_back(2);
            neighbors.push_back(12);
            neighbors.push_back(22);
            break;
        case 14:
            neighbors.push_back(17);
            neighbors.push_back(15);
            neighbors.push_back(10);
            break;
        case 15:
            neighbors.push_back(14);
            neighbors.push_back(18);
            neighbors.push_back(16);
            break;
        case 16:
            neighbors.push_back(15);
            neighbors.push_back(16);
            neighbors.push_back(11);
            break;
        case 17:
            neighbors.push_back(9);
            neighbors.push_back(20);
            neighbors.push_back(18);
            break;
        case 18:
            neighbors.push_back(15);
            neighbors.push_back(17);
            neighbors.push_back(19);
            neighbors.push_back(21);
            break;
        case 19:
            neighbors.push_back(16);
            neighbors.push_back(18);
            neighbors.push_back(22);
            break;
        case 20:
            neighbors.push_back(8);
            neighbors.push_back(17);
            neighbors.push_back(21);
            break;
        case 21:
            neighbors.push_back(18);
            neighbors.push_back(20);
            neighbors.push_back(22);
            break;
        case 22:
            neighbors.push_back(13);
            neighbors.push_back(19);
            neighbors.push_back(21);
            break;
        
    }
            return neighbors;
}