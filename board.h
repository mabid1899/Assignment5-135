
#include <string> 
#include<vector>

using namespace std;

enum class Tile : char {
    player1='x', player2='o', cell='.'
};

class Board {
    // a board is a 2-dimensional vector of Tiles
    vector<vector<Tile>> board;

    // this struct is needed by the iterative flood method below
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

    	void print() const {
        for(int i = 0; i < height(); ++i) {
            for(int j = 0; j < width(); ++j) {
                cout << " "<<char(board[i][j]) << " ";  // char(maze[i][j]) converts
            }                                     // maze[i][j] (which is of type Tile)
            cout << "\n";                         // to its underlying char
        }
        
      }
};
