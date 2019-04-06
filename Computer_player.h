#include<string>
#include<vector>


using namespace std;


class Computer_player: public Player {
private:

    string name_;
    char move2;
    int row;
    int column;

public:
       Computer_player()
       : name_("player2")
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

       ~Computer_player(){}

        bool check_line_match_(int dr, int dc, int r, int c)
        {   
            if(r+dr < 0 || r+dr >7)
                return false;
            if(c+dc < 0 || c+dc >7)
                return false;
            return check_line_match_( dr, dc, r+dr,c+dc);
        }
        
  };