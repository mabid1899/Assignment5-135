#include<string>
#include<vector>


using namespace std;


class Human_player: public Player {
private:

    string name_;
    char move2;
    int row;
    int column;

public:
	   Human_player()
       : name_("player1")
       {}

       void cell(int x, int y)
       {
        row = x;
        column = y;
       }

        int get_row() 
        {
            return row;
        }
        int get_column()
        {
            return column;
        }

       string name()const{ return name_;}

       ~Human_player(){};

        bool check_line_match_(int dr, int dc, int r, int c)
        {   
            if(r+dr < 0 || r+dr >7)
                return false;
            if(c+dc < 0 || c+dc >7)
                return false;
            return check_line_match_( dr, dc, r+dr,c+dc);
        }
};