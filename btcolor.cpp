#include <iostream>
#include "redblackt.h"
#include <fstream>

using namespace std;

//ENUM COLOR FANCY STUFF
bool isValid(char**& grid, const int& row, const int& col, const int& maxrow, const int& maxcol, RedBlackTree<char,int>& mymaptree){
	if ( row +1 < maxrow){
		if (grid[row][col] != grid[row+1][col]){
			if (mymaptree.find(grid[row+1][col]) != mymaptree.end() ){
				if ( (mymaptree.find(grid[row][col]))->second == (mymaptree.find(grid[row+1][col]))->second ){
					return false;
				}
			}
		}
	}
	if ( col + 1 < maxcol){
		if (grid[row][col] != grid[row][col+1]){
			if (mymaptree.find(grid[row][col+1]) != mymaptree.end() ){
				if ( (mymaptree.find(grid[row][col]))->second == (mymaptree.find(grid[row][col+1]))->second ){
					return false;
				}
			}
		}
	}
	if ( row - 1 >= 0){
		if (grid[row][col] != grid[row-1][col]){
			if (mymaptree.find(grid[row-1][col]) != mymaptree.end() ){
				if ( (mymaptree.find(grid[row][col]))->second == (mymaptree.find(grid[row-1][col]))->second ){
					return false;
				}
			}
		}
	}
	if ( col - 1 >= 0){
		if (grid[row][col] != grid[row][col-1]){
			if (mymaptree.find(grid[row][col-1]) != mymaptree.end() ){
				if ( (mymaptree.find(grid[row][col]))->second == (mymaptree.find(grid[row][col-1]))->second ){
					return false;
				}
			}
		}
	}

	return true;
	
}


bool allCountriesAlright(char**& grid, const int& row, const int& col, const int& maxrow, const int& maxcol, RedBlackTree<char,int>& mymaptree){
	for (int i=0; i < maxrow; i++){
		for (int j=0; j < maxcol; j++){
			if (!isValid(grid,i,j,maxrow,maxcol,mymaptree)){
				return false;
			}
		}
	}
	return true;
}


bool search(char**& grid, const int& row, const int& col,const int& maxrow, const int& maxcol, RedBlackTree<char,int>& mymaptree){
	
	if ( row >= 0 && row < maxrow && col >= 0 && col < maxcol){
		
		if ( (mymaptree.find(grid[row][col]))->second == 0 ){
			
			for(int i =1; i <= 4; i++){
				
				(mymaptree.find(grid[row][col]))->second = i;
		
				if (isValid(grid,row,col, maxrow, maxcol, mymaptree)){
					cout << "(" << row << ", " << col << ")" << " -  " << grid[row][col] << " : " << i << endl;
						if (col < maxcol -1){
							if (search(grid,row,col+1, maxrow, maxcol, mymaptree) == true){
								return true;
							}
						}
						else{
							if (search(grid,row+1, 0, maxrow,maxcol,mymaptree) == true){
								return true;
							}
						}			
				}
			}
			mymaptree.find(grid[row][col])->second = 0;
			return false;
		}
		else{
			if (isValid(grid,row,col,maxrow,maxcol,mymaptree)){
				int mycolor = mymaptree.find(grid[row][col])->second;
				cout << "(" << row << ", " << col << ")" << " -  " << grid[row][col] << " : " << mycolor << endl;
				if (col < maxcol -1){
					return search(grid,row,col+1, maxrow, maxcol, mymaptree);								
				}
				else{
					return search(grid,row+1, 0, maxrow,maxcol,mymaptree);
				}
			}
			else{
				return false;
			}
								
		}
	}
	else{
		return allCountriesAlright(grid, row, col, maxrow,maxcol, mymaptree);
	}

}


int main(int argc, char* argv[]){

	ifstream ifile(argv[1]);

	int N = 0;
	ifile >> N;
	int maxrow = 0;
	ifile >> maxrow;
	int maxcol = 0;
	ifile >> maxcol;
	if(N == 0 || maxrow == 0 || maxcol == 0){
		cout << "Error: Wrong input format!" << endl;
		return -1;
	}
	char** grid = new char*[maxrow];
	for ( int i =0; i < maxrow; i++){
		grid[i] = new char[maxcol];
	}
	for (int i = 0; i < maxrow; i++){
		for ( int j =0; j < maxcol; j++){
			 ifile >> grid[i][j];
		}
	}

	RedBlackTree<char,int> mymaptree;

	for (int i = 0; i < maxrow; i++){
		for ( int j =0; j < maxcol; j++){
			 if (mymaptree.find(grid[i][j]) == mymaptree.end()){
			 	 mymaptree.insert(pair<char,int>(grid[i][j],0));
			 }
		}
	}
	mymaptree.print();

	bool temp = search(grid,0,0,maxrow,maxcol,mymaptree);
	cout << temp << endl;
	for(RedBlackTree<char,int>::iterator it = mymaptree.begin(); it != mymaptree.end(); ++it){
		cout << it->first << ": " << it->second << endl;
	}

	for (int i =0; i < maxrow; i++){
		delete[] grid[i];
	}
	delete[] grid;

return 0;
}

