#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <deque>


struct State;

std::list<State> generate_moves_mid_game_end_game_black(State &);
std::list<State> generate_move(State &);

int static BOARD_SIZE;
int static evaluated = 0 ;

struct State {
    int value;
    int alpha;
    int beta;
    std::string current_board;
    std::string best_board;
    int depth_limit;

    State(){}

    State(int v, const std::string b) : value(v), current_board(b), best_board(""), depth_limit(0), alpha(0), beta(0){
       for (int i = 0; i < BOARD_SIZE; i++){
           current_board[i] = b[i];
       }
    }

    bool full(const State &state){
        for (int i = 0; i < BOARD_SIZE; i++){
            if (state.current_board[i] == 'x'){
                return false;
            } 
        }
        return true;
    }

std::list<int> neighbors(int location){
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

};

std::ostream& operator<<(const std::ostream & os, const State & rhs){
        for (int i = 0; i < BOARD_SIZE; i++)
           std::cout <<  rhs.current_board[i];
        std::cout <<  "\n";
    }
bool close_mill(int position, State &state){
    auto C =  state.current_board[position];
    switch (position) {
        case 0: 
            if (state.current_board[1] == C && state.current_board[2] == C ||
                state.current_board[3] == C && state.current_board[8] == C ||
                state.current_board[8] == C && state.current_board[20] == C){
                return true;
            } else {
                return false;
            }
        break;

        case 1:
            if (state.current_board[0] == C && state.current_board[2] == C){
                return true;
            } else {
                return false;
            }
            break;
        case 2:
         if (state.current_board[1] == C && state.current_board[0] == C ||
                state.current_board[5] == C && state.current_board[7] == C ||
                state.current_board[13] == C && state.current_board[22] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 3:
         if (state.current_board[0] == C && state.current_board[6] == C ||
                state.current_board[9] == C && state.current_board[17] == C ||
                state.current_board[4] == C && state.current_board[5] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 4:
            if (state.current_board[3] == C && state.current_board[5] == C) return true;
            else return false;
            break;
        case 5:
         if (state.current_board[2] == C && state.current_board[7] == C ||
                state.current_board[19] == C && state.current_board[12] == C ||
                state.current_board[3] == C && state.current_board[4] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 6:
         if (state.current_board[10] == C && state.current_board[14] == C ||
                state.current_board[3] == C && state.current_board[0] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 7:
         if (state.current_board[5] == C && state.current_board[2] == C ||
                state.current_board[11] == C && state.current_board[16] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 8:
         if (state.current_board[20] == C && state.current_board[0] == C ||
                state.current_board[9] == C && state.current_board[10] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 9:
         if (state.current_board[17] == C && state.current_board[3] == C ||
                state.current_board[8] == C && state.current_board[10] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 10:
         if (state.current_board[9] == C && state.current_board[8] == C ||
                state.current_board[14] == C && state.current_board[6] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 11:
         if (state.current_board[16] == C && state.current_board[7] == C ||
                state.current_board[12] == C && state.current_board[13] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 12:
         if (state.current_board[11] == C && state.current_board[13] == C ||
                state.current_board[5] == C && state.current_board[19] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 13:
         if (state.current_board[22] == C && state.current_board[2] == C ||
                state.current_board[12] == C && state.current_board[11] == C){
                return true;
            } else {
                return false;
            }
        break;
        case 14:
         if (state.current_board[17] == C && state.current_board[20] == C ||
                state.current_board[15] == C && state.current_board[16] == C ||
                state.current_board[10] == C && state.current_board[6] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 15:
         if (state.current_board[14] == C && state.current_board[16] == C ||
                state.current_board[18] == C && state.current_board[21] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 16:
         if (state.current_board[19] == C && state.current_board[22] == C ||
                state.current_board[15] == C && state.current_board[14] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 17:
         if (state.current_board[20] == C && state.current_board[14] == C ||
                state.current_board[9] == C && state.current_board[3] == C ||
                state.current_board[18] == C && state.current_board[19] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 18:
         if (state.current_board[21] == C && state.current_board[15] == C ||
                state.current_board[19] == C && state.current_board[17] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 19:
         if (state.current_board[12] == C && state.current_board[5] == C ||
                state.current_board[18] == C && state.current_board[17] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 20:
         if (state.current_board[17] == C && state.current_board[14] == C ||
                state.current_board[21] == C && state.current_board[22] == C ||
                state.current_board[8] == C && state.current_board[0] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 21:
         if (state.current_board[20] == C && state.current_board[22] == C ||
                state.current_board[15] == C && state.current_board[18] == C){
                return true;
            } else {
                return false;
            }
        break;
        
        case 22:
         if (state.current_board[21] == C && state.current_board[20] == C ||
                state.current_board[19] == C && state.current_board[16] == C ||
                state.current_board[13] == C && state.current_board[2] == C){
                return true;
            } else {
                return false;
            }
        break;

        default:
            std::cout << "not valid\n";


    }
}

std::list<State> generate_remove(int position, State &state, std::list<State> L){
    for (int i = 0; i < BOARD_SIZE; i++){
        if (state.current_board[i] == 'B' && !(close_mill(i, state))) {
            State copy = state;
            copy.current_board[i] = 'x';
            L.push_back(copy); 
            
        } else if (state.current_board[i] == 'B' && close_mill(i, state)){
            if (state.current_board[i] == 'B') {
                State copy = state;
                copy.current_board[i] == 'x';
                L.push_back(copy); 
            }
        }
        evaluated++;
    }
    return L;
}

std::list<State> generate_remove_black(int position, State &state, std::list<State> L){
    for (int i = 0; i < BOARD_SIZE; i++){
        if (state.current_board[i] == 'W' && !(close_mill(i, state))) {
            State copy = state;
            copy.current_board[i] = 'x';
            L.push_back(copy); 
            
        } else if (state.current_board[i] == 'W' && close_mill(i, state)){
            if (state.current_board[i] == 'W') {
                State copy = state;
                copy.current_board[i] == 'x';
                L.push_back(copy); 
            }
        }
        evaluated++;
    }
    return L;
}

 std::list<State> generate_add(State &state){
     std::list<State> states;

     for (int j = 0; j < BOARD_SIZE; j++){
         if (state.current_board[j] == 'x'){
            State copy = state;
            copy.current_board[j] = 'W';
            if (close_mill(j, copy)){
                states = generate_remove(j, copy, states);
            } else {
                evaluated++;
                states.push_back(copy);
            }
         } 
     }
     return states;
}

std::list<State> generate_add_black(State &state){
     std::list<State> states;

     for (int j = 0; j < BOARD_SIZE; j++){
         if (state.current_board[j] == 'x'){
            State copy = state;
            copy.current_board[j] = 'B';
            if (close_mill(j, copy)){
                states = generate_remove_black(j, copy, states);
            } else {
                evaluated++;
                states.push_back(copy);
            }
         } 
     }
     return states;
}

 std::list<State> generate_opening_moves(State &state){
        return generate_add(state);
}

std::list<State> generate_hopping(State &state){
    /*
    * create empty list to be returned
    * for each location in the board
    * 
    */
   std::list<State> L;
   for (int location = 0; location < BOARD_SIZE; location++){
       std::cout << state.current_board[location] << " ";
       if (state.current_board[location] == 'W'){
        for (int b = 0; b < BOARD_SIZE; b++){
            if (state.current_board[b] == 'x'){
                State copy = state;
                copy.current_board[location] = 'x';
                copy.current_board[b] == 'W';
                 if (close_mill(b, copy)){
                    L = generate_remove_black(b, copy, L);
                } else {
                    L.push_back(copy);
                }

            }
        }
            return L;
       }
   }
}

State create_initial_position(const std::string in, const std::string out, int depth){
    std::ifstream input_file_stream;
    std::ofstream output_file_stream;
    input_file_stream.open(in, std::ios::in);
    output_file_stream.open(out, std::ios::out);
    std::string line;
    while (input_file_stream){
        input_file_stream >> line;
    }
    BOARD_SIZE = line.size();
    State state(0, line);
    std::cout << "Input Position:\t\t"<< state ;
    state.depth_limit = depth;
    output_file_stream << " " << state.current_board;
    return state;
}

/*******
 * 
 * GenerateMovesMidgameEndgame 
 * Input: a board position 
 * Output: a list L of board positions
 * if the board has 3 white pieces
 *      return the list produced by GenerateHopping applied to the board.
 * else 
 *      return the list produced by GenerateMove applied to the board.
 * 
*/

std::list<State> generate_moves_mid_game_end_game_black(State &state){
    const int MAXIMUM_BLACK_PIECES = 3;
    int num_black_pieces = 0;
    for (int location = 0; location < BOARD_SIZE; location++){
        if (state.current_board[location] == 'B') {
            num_black_pieces++;
            if (num_black_pieces == MAXIMUM_BLACK_PIECES) {
                return generate_hopping(state);
            } else {
                return generate_move(state); // TODO generate_move_black 
            }
        }
    } 
}

std::list<State> generate_opening_moves_black(State &state){
        return generate_add_black(state);
 
}

int static_estimation(State &s) {
    /**
     * @brief 
     * 
     * 
     */
    int numWhitePieces = 0;
    int numBlackPieces = 0;
     std::list<State> list = generate_moves_mid_game_end_game_black(s);
    int num_black_moves = list.size();
    
    for (int i = 0; i < BOARD_SIZE; i++){
        if (s.current_board[i] == 'B'){
            numBlackPieces++;
        } else if (s.current_board[i] == 'W') { 
            numWhitePieces++;
        }  
    }
    if (numBlackPieces <= 2) return 10000;
    else if (numWhitePieces <= 2) return -10000;
    else if (num_black_moves == 0) return 10000;
    else return 1000 * (numWhitePieces - numBlackPieces) - num_black_moves;
}

int MinMax(State &state, int depth_limit, int alpha, int beta){
    int MaxMinPruning(State&, int, int alpha, int beta);
    int best_score = 0;
    State best(0, "");
    if (depth_limit == 0 || state.full(state)) {
        return static_estimation(state);
    } else {
        int value = 99999;
        State move;
        std::list<State> moves = generate_opening_moves_black(state);
        for (State child : moves){
         state.value = std::min(value,  MaxMinPruning(child, depth_limit - 1, alpha, beta));
         if ( move.value <= alpha) {
              state = child;
               state.best_board = child.current_board;
              state.value = move.value;
             return  move.value;
         } else {
             beta = std::min( move.value, beta);
         }

        return  move.value;
        }
    }
}

int MaxMinPruning(State &state, int depth_limit, int alpha, int beta){
    int MinMax(State&, int, int, int);
    State move;
    if (depth_limit == 0 || state.full(state)) {
        return static_estimation(state);
    } else {
        int value = -99999;
       
        std::list<State> moves = generate_opening_moves(state);
        for (State child : moves){
            state.value = std::max(value,  MinMax(child, depth_limit - 1, alpha, beta));
            state.best_board = child.current_board;
            if (move.value >= beta) {
                beta = move.value;
                // std::cout << state;
                return move.value;
            } else {
                alpha = std::max(move.value, alpha);
            }

            state.best_board = child.best_board;
                state.value = move.value;
           
        return value;
        }
    }  
}
 std::list<State> generate_move(State &state){
     std::list<State> states;
     State copy;
     for (int location = 0; location < BOARD_SIZE; location++){
         if (state.current_board[location] == 'W'){
            std::list<int> n = state.neighbors(location);

            for (auto j : n){
                if (state.current_board[j] == 'x'){
                    copy = state;
                    copy.current_board[location] = 'x';
                    copy.current_board[j] = 'W';
                    if (close_mill(j, copy)){
                        states = generate_remove(j, copy, states);
                    } else {
                        states.push_back(copy);
                    }
                }  
            }
           
         }
     }
     return states;
}
/*******
 * 
 * GenerateMovesMidgameEndgame 
 * Input: a board position 
 * Output: a list L of board positions
 * if the board has 3 white pieces
 *      return the list produced by GenerateHopping applied to the board.
 * else 
 *      return the list produced by GenerateMove applied to the board.
 * 
*/

std::list<State> generate_moves_mid_game_end_game(State &state){
    const int MAXIMUM_WHITE_PIECES = 3;
    int num_white_pieces = 0;

    for (int location = 0; location < BOARD_SIZE; location++){
        if (state.current_board[location] == 'W') {
            num_white_pieces++;
            if (num_white_pieces == MAXIMUM_WHITE_PIECES) {
                return generate_hopping(state);
            } else {
                return generate_move(state);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    switch (argc) {
        case 1:
            std::cerr << "Please include input & output files: ";
            std::cerr << std::endl;
            exit(1);
            break;
        case 2:
            std::cerr << "Please include output file: ";
            std::cerr << std::endl;
            break;
        case 3:
            std::cerr << "Please include 'Depth Limit'";
            std::cerr << std::endl;
            break;
        case 4: case 6:  case 7:
            try {
                std::ofstream output_file_stream;
                output_file_stream.open(argv[2], std::ios::out);
                State s0 = create_initial_position(argv[1], argv[2], std::stoi(argv[3]));
                // TODO value () to return best move 
                auto i = MaxMinPruning(s0, s0.depth_limit, 0, 0);
                std::cout << "Output Position:\t" << s0.best_board << "\n";
                std::cout << "Positions Evaluated:\t" << evaluated << "\n";
                std::cout << "MINIMAX Value:\t" << s0.value << "\n";
            }
            catch (...){
                std::cout << "Unknown Error. " << std::endl;
            }
            break;   
    }
    return 0;
}


