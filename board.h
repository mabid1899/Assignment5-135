#include <string> 
#include<vector>

using namespace std;

const string red = "\033[0;31m";
const string green = "\033[1;32m";
const string yellow = "\033[1;33m";
const string cyan = "\033[0;36m";
const string magenta = "\033[0;35m";
const string reset_color = "\033[0m";

void get_a_cell();

enum class Tile : char {
    player1='x', player2='o', cell='.', check = '?', check2 = 'c'
};

class Board {
    vector<vector<Tile>> board;
    int current_row;
    int current_column;

    struct Location {
        int row;
        int col;
    };

    public:
    	Board(int w, int h)
    	:board(h)
    	{ 
    		for(int i = 0; i < board.size(); ++i) {
            	board[i] = vector<Tile>(w, Tile::cell);
    		}
    		board[3][3] = Tile::player1;
    		board[3][4] = Tile::player2;
    		board[4][3] = Tile::player2;
    		board[4][4] = Tile::player1;	
    	}

    	int width() const { return board[0].size(); }
    	int height() const { return board.size(); }

    	// resets the board
    	void regame()
    	{

    		for(int i = 0; i < board.size(); ++i) {
            	board[i] = vector<Tile>(8, Tile::cell);
    		}
	    		board[3][3] = Tile::player1;
	    		board[3][4] = Tile::player2;
	    		board[4][3] = Tile::player2;
	    		board[4][4] = Tile::player1;		
    	}

    	void print() const {
	    	cout<<"   ";
	    	for(int i =0; i< 8;i++){
	    		cout<<" "<<green<<i<<" ";
	    	}
	    	cout<<reset_color;

	    	cout<<endl;
	        for(int i = 0; i < height(); ++i) {
	        	cout<<" "<<green<<i<<" "<<reset_color;
	            for(int j = 0; j < width(); ++j) {
	            	if(board[i][j] == Tile::check)
	            	{
	            		cout<<yellow<<" "<<char(board[i][j]) << " "<<reset_color; 
	            	}
	            	else
	               		 cout << " "<<char(board[i][j]) << " ";  // char(board[i][j]) converts
	            }                                      // board[i][j] (which is of type Tile)
	            cout << "\n";                          // to its underlying char
	        	}
   		 }

   		 // to check if row and board is in the cell
        bool in_board(int row, int col) const {
        	return (0 <= row && row < height())
           		   && (0 <= col && col < width());
    	}

    	void set(int r, int c, const Tile& t) {
        	assert(in_board(r, c));
       		board[r][c] = t;
   		 }

   		Tile get(int r, int c) const {
       		 assert(in_board(r, c));
       		 return board[r][c];
    	}

    	int count_x(){
    		int count = 0;
    		for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) {
                if(char(board[i][j]) == 'x') 
                	count++;
               }
    		}
    		return count;
    	}

    	int count_o()
    	{
    		int count = 0;
    		for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) {
                if(char(board[i][j]) == 'o') 
                	count++;
               }
    		}
    		return count;

    	}

    	// checks if the cell matches the players cell
    	bool check_line_match(int dr, int dc, int r, int c)
        {
        	if(get(r,c) == Tile::player1)
        		return true;
        	if(r+dr < 0 || r+dr >7)
        		return false;
        	if(c+dc < 0 || c+dc >7)
        		return false;
        	return check_line_match(dr, dc, r+dr,c+dc);
        }

        // checks for the valid moves of the human player
   		 bool valid_move(int dr, int dc, int r, int c)
   		 {

   		 	if(r+dr < 0 || r+dr>7)
   		 		return false;
   		 	if(c+dc < 0 || c+dc>7)
   		 		return false;
   		 	if(get(r+dr, c+dc) != Tile::player2)
   		 		return false;
   		 	if(r+dr+dr < 0 || r+dr+dr > 7)
   		 		return false;
   		 	if(c+dc+dc < 0 || c+dc+dc > 7)
   		 		return false;

   		 	return check_line_match(dr, dc,r+dr+dr, c+dc+dc);
   		 }

   		 bool is_a_move()
   		 {
   		 	int dr = 1;
            int dc = 1;
            int count = 0;

    		vector<Location> valid_moves;// location is a struct itself
      		for(int start_row = 0; start_row < height(); ++start_row) {
            for(int start_col = 0; start_col < width(); ++start_col) {
                if(get(start_row,start_col) == Tile::check) {    
                	return true;
               		} 	 									// char(board[i][j]) converts
                	}
          		 }
          		 return false;                                             // board[i][j] (which is of type Tile)                            // to its underlying char
        	}
       

    	void check_valid_moves() { 
    		int dr = 1;
            int dc = 1;
            int count = 0;

    		vector<Location> valid_moves;// location is a struct itself
      		for(int start_row = 0; start_row < height(); ++start_row) {
            for(int start_col = 0; start_col < width(); ++start_col) {
                if(get(start_row,start_col) == Tile::cell) {    
                	
                	bool nw = valid_move(-1,-1,start_row, start_col);
                	bool nn = valid_move(-1, 0,start_row, start_col);
                	bool ne = valid_move(-1, 1,start_row, start_col);

                	bool ww = valid_move(0,-1,start_row, start_col);
                	bool ee = valid_move(0,1,start_row, start_col);

                	bool sw = valid_move(1,-1,start_row, start_col);
                	bool sn = valid_move(1, 0,start_row, start_col);
                	bool se = valid_move(1, 1,start_row, start_col);
                	
                		if(nn || nw || ne || ww || ee || sw || sn || se){
                      	
                			board[start_row][start_col] = Tile::check;
               			 } 
               			 									// char(board[i][j]) converts
                	}
          		 }                                             // board[i][j] (which is of type Tile)	                                // to its underlying char
        	}
        }

        bool is_move_valid(int start_row, int start_col)
        {
        	// }
                	bool nw = valid_move(-1,-1,start_row, start_col);
                	bool nn = valid_move(-1, 0,start_row, start_col);
                	bool ne = valid_move(-1, 1,start_row, start_col);

                	bool ww = valid_move(0,-1,start_row, start_col);
                	bool ee = valid_move(0,1,start_row, start_col);

                	bool sw = valid_move(1,-1,start_row, start_col);
                	bool sn = valid_move(1, 0,start_row, start_col);
                	bool se = valid_move(1, 1,start_row, start_col);

                	if(nn || nw || ne || ww || ee || sw || sn || se){
                			return true;
               		}  
               		return false;						
        }

        bool check_line_match2(int dr, int dc, int r, int c)
        {
        	if(get(r,c) == Tile::player2)
        		return true;
        	if(r+dr < 0 || r+dr >7)
        		return false;
        	if(c+dc < 0 || c+dc >7)
        		return false;
        	return check_line_match2(dr, dc, r+dr,c+dc);
        }

        bool valid_move2(int dr, int dc, int r, int c)
   		 {

   		 	if(r+dr < 0 || r+dr>7)
   		 		return false;
   		 	if(c+dc < 0 || c+dc>7)
   		 		return false;
   		 	if(get(r+dr, c+dc) != Tile::player1)
   		 		return false;
   		 	if(r+dr+dr < 0 || r+dr+dr > 7)
   		 		return false;
   		 	if(c+dc+dc < 0 || c+dc+dc > 7)
   		 		return false;

   		 	return check_line_match2(dr, dc,r+dr+dr, c+dc+dc);
   		 }

   		 //  gets the computers move
   		 bool can_make_a_move()
   		 {
   		 	int dr = 1;
            int dc = 1;

    		vector<Location> valid_moves;								// location is a struct itself
      		for(int start_row = 0; start_row < height(); ++start_row) {
           		 for(int start_col = 0; start_col < width(); ++start_col) {
                	if(get(start_row,start_col) == Tile::cell) {
               
                	bool nw = valid_move2(-1,-1,start_row, start_col);
                	bool nn = valid_move2(-1, 0,start_row, start_col);
                	bool ne = valid_move2(-1, 1,start_row, start_col);

                	bool ww = valid_move2(0,-1,start_row, start_col);
                	bool ee = valid_move2(0,1,start_row, start_col);

                	bool sw = valid_move2(1,-1,start_row, start_col);
                	bool sn = valid_move2(1, 0,start_row, start_col);
                	bool se = valid_move2(1, 1,start_row, start_col);

                		if(nn || nw || ne || ww || ee || sw || sn || se){
                			current_row =  start_row;
                			current_column =  start_col;
                			cout<<current_column<<current_row<<"\n";
                			return true;
               			}  
                	}
            	}
        	}
        return false;
   		}

        void get_a_move(){
            int dr = 1;
            int dc = 1;

    		vector<Location> valid_moves;// location is a struct itself
      		for(int start_row = 0; start_row < height(); ++start_row) {
            for(int start_col = 0; start_col < width(); ++start_col) {
                if(get(start_row,start_col) == Tile::cell) {
               
                	bool nw = valid_move2(-1,-1,start_row, start_col);
                	bool nn = valid_move2(-1, 0,start_row, start_col);
                	bool ne = valid_move2(-1, 1,start_row, start_col);

                	bool ww = valid_move2(0,-1,start_row, start_col);
                	bool ee = valid_move2(0,1,start_row, start_col);

                	bool sw = valid_move2(1,-1,start_row, start_col);
                	bool sn = valid_move2(1, 0,start_row, start_col);
                	bool se = valid_move2(1, 1,start_row, start_col);


                	if(nn || nw || ne || ww || ee || sw || sn || se){
                			
                			current_row =  start_row;
                			current_column =  start_col;
                			cout<<"computer's move: "<<current_row<<","<<current_column<<"\n";
                			board[start_row][start_col] = Tile::player2;
                			return;	
               		}  
                }
            }
        }
        
    }
    	void clear()
    	{
    		for(int start_row = 0; start_row < height(); ++start_row) {
            	for(int start_col = 0; start_col < width(); ++start_col){
            		if(get(start_row,start_col) == Tile::check){
            			board[start_row][start_col] = Tile::cell;
            		}
           		 }
    		}
    	}

        bool flip_board(int start_row, int start_col)
        {
        			flip_line(-1,-1,start_row, start_col);
                	flip_line(-1, 0,start_row, start_col);
                	flip_line(-1, 1,start_row, start_col);

                	flip_line(0,-1,start_row, start_col);
                	flip_line(0,1,start_row, start_col);

                	flip_line(1,-1,start_row, start_col);
                	flip_line(1, 0,start_row, start_col);
                	flip_line(1, 1,start_row, start_col);
        }

        bool flip_line(int dr, int dc, int r, int c)
        {
        	if(r+dr < 0 || r+dr>7)
   		 		return false;
   		 	if(c+dc < 0 || c+dc >7)
   		 		return false;
   		 	if(get(r+dr, c+dc) == Tile::cell)
   		 		return false;

   		 	if(get(r+dr, c+dc) == Tile::player1)
   		 		return true;
   		 	else{
   		 		if(flip_line(dr,dc,r+dr,c+dc)){
   		 			board[r+dr][c+dc] =  Tile::player1;
   		 			return true;
   		 		}
   		 		else{
   		 			return false;
   		 		}
   		 	}
   		 	if(r+dr+dr < 0 || r+dr+dr > 7)
   		 		return false;
   		 	if(c+dc+dc < 0 || c+dc+dc > 7)
   		 		return false;

   		 	return check_line_match(dr, dc,r+dr+dr, c+dc+dc);
        }

         bool flip_line2(int dr, int dc, int r, int c)
        {
        	if(r+dr < 0 || r+dr>7)
   		 		return false;
   		 	if(c+dc < 0 || c+dc >7)
   		 		return false;
   		 	if(get(r+dr, c+dc) == Tile::cell)
   		 		return false;

   		 	if(get(r+dr, c+dc) == Tile::player2)
   		 		return true;
   		 	else{
   		 		if(flip_line2(dr,dc,r+dr,c+dc)){
   		 			board[r+dr][c+dc] =  Tile::player2;
   		 			return true;
   		 		}
   		 		else{
   		 			return false;
   		 		}
   		 	}
   		 	if(r+dr+dr < 0 || r+dr+dr > 7)
   		 		return false;
   		 	if(c+dc+dc < 0 || c+dc+dc > 7)
   		 		return false;

   		 	return check_line_match2(dr, dc,r+dr+dr, c+dc+dc);
        }

        	// flips the board after opponenets move
 			bool flip_board2()
     	   {

        			flip_line2(-1,-1,current_row, current_column);
                	flip_line2(-1, 0,current_row, current_column);
                	flip_line2(-1, 1,current_row, current_column);

                	flip_line2(0,-1,current_row, current_column);
                	flip_line2(0,1,current_row, current_column);

                	flip_line2(1,-1,current_row, current_column);
                	flip_line2(1, 0,current_row, current_column);
                	flip_line2(1, 1,current_row, current_column);
        	}    

};
