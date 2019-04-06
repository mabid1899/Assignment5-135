#ifndef PLAYER_H
#define PLAYER_H 

#include<string>
#include<vector>

using namespace std;


class Player{

public:
	
	virtual void cell(int x, int y) = 0;
	virtual int get_row()  = 0;
	virtual int  get_column() = 0;
    virtual string name()const  = 0;
    virtual bool check_line_match_(int dr, int dc, int r, int c) = 0;
	virtual ~Player(){}
  };

  #endif