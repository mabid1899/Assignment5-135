#include "cmpt_error.h"    // These are the only permitted includes!
#include <iostream>        //
#include <string>          // Don't include anything else.
#include <algorithm>
#include <cassert>
#include "board.h"
using namespace std;

// for background colors
const string red = "\033[0;31m";
const string green = "\033[1;32m";
const string yellow = "\033[1;33m";
const string cyan = "\033[0;36m";
const string magenta = "\033[0;35m";
const string reset_color = "\033[0m";
void get_a_cell();
void test();
void calculate_valid_moves(Board board, char c);

int main()
{
	char input;
	cout<<" Enter white or black(w/b)"<<"\n";
	cin>>input;
	cout << "You are "<<input<<"\n";

	// ---- exception handling -----  
	// try{
	// 	if(input != 'w' || input != 'b')
	// 		throw(input);
	// 	catch(char s){
	// 		cout<<s<<"is not a valid choice"
	// 	}
	// }
	Board board(8,8);
	board.print();
	//board();
	//test();
}


void test() {
    cout << "This is "
         << red            // set text color to red
         << "red"
         << reset_color    // reset text color
         << ", and this is "
         << yellow         // set text color to yellow
         << "yellow"
         << reset_color    // reset text color
         << ".\n";
}

// checks for valid moves to display on the screen
void calculate_valid_moves(char c, Board board)
{
	Board new_board = board;

	for(int i = 0; i < new_board.height(); ++i) {
            for(int j = 0; j < new_board.width(); ++j) {
                if(char(new_board[i][j]) == '')
            }                                     // maze[i][j] (which is of type Tile)
            cout << "\n";                         // to its underlying char
        }

}