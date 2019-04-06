/* Team of 2 - Assignment 5 - Reversi Game 

 Yash Vijay Bhavnani
 301318198
 ybhavnan@sfu.ca

 Muhammad Abid
 301328836
 abid@sfu.ca

 // Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////
*/


#include "cmpt_error.h" 
#include <iostream>        
#include <string>          
#include <algorithm>
#include <cassert>
#include "board.h"
#include "player.h"
#include "human_player.h"
#include "Computer_player.h"

using namespace std;

void get_a_cell();
void test();
void calculate_valid_moves(char c, Board board);

struct Location {
        int row;
        int col;
    };

int main()
{
	int row, column;
	int restart =  0;
	cout<<"\n";
	cout<<"Welcome to Reversi!!";
	cout << "You are x, computer is o"<<"\n";
	cout<<"Valid moves are indicated by "<<yellow<<" ? "<<reset_color<<"\n";

	 Board board(8,8);
     Human_player player_1;
     Computer_player player_2;


	board.check_valid_moves();

	while(restart == 0)
	{
		while(board.is_a_move() || board.can_make_a_move()) // while either player can make a move
		{
			if(board.is_a_move()){

			board.check_valid_moves();
			cout<<"\n";
			board.print();
			cout<<"x: "<<cyan<<board.count_x()<<reset_color<<"    "<<" o:"<<cyan<<board.count_o()<<reset_color<<"\n";
			cout<<"Enter a row: ";
		 	cin>>row;
		 		if (!cin.fail()){
			 	cout<<"Enter a column: ";
			 	cin>>column;
			 	cout<<"\n";

			 		if(!cin.fail())
			 		{
				 		if(board.is_move_valid(row,column)){
						 	board.set(row,column,Tile::player1);
						 	board.flip_board(row, column);
						 	board.get_a_move();
						 	board.flip_board2();
						 	board.clear();
						 	board.check_valid_moves();
						}
						else{
		 				cout<<"Please enter a valid move "<<"\n";
		 				board.check_valid_moves();	 		
						}
					}
					else{
						cin.clear();
						cin.ignore(10000,'\n');
						cout<<red<<"Error, invalid move "<<reset_color<<"\n";
					}
				}
				else{
					cin.clear();
					cin.ignore(10000,'\n');
					cout<<red<<"Error, invalid move "<<reset_color<<"\n";
				}		
		}

		else{
			board.get_a_move();
			cout<<"\n";
		    board.print();
		 	board.flip_board2();
		 	board.print();
		}
		 
	 }
	 
	 cout<<" Game over !!"<<"\n";
	 board.print();
	 int x = board.count_x();
	 int o =  board.count_o();

	 if(x>o)
	 	cout<<"You won!! your score: "<<x<<" computer score: "<<o<<"\n";
	 
	 if(x<o)
	 	cout<<"computer won!!; your score: "<<x<<" computer score: "<<o<<"\n";
	 
	 else if(x == o)
	 	cout<<" Match Drawn; your score: "<<x<<" computer score: "<<o<<"\n";

	 char decision;

	 cout<<"Do you want to play again, press y to restart"<<"\n";
	 cin>>decision;

	 if(!cin.fail()){
	 	if(decision == 'y'){
	 		restart = 0;
	 		board.regame();
	 		board.check_valid_moves();
	 	}
	 	else
	 		restart = -1;
	 }
	 else{
	 	cin.clear();
		cin.ignore(10000,'\n');
		cout<<red<<"Error, invalid move, Game over! "<<reset_color<<"\n";
	 }
	}
	 
	}

	
