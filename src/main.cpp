#include <string>
#include <fstream>
#include <iostream>
#include <piece.h>
#include <vector>

using namespace std;

/**
 * @brief Read rows, columns and pieces from an archive
 * @param path Path of the archive
 * @param rows Rows of the puzzle
 * @param cols Columns of the puzzle
 * @param pieces Vector of pieces
 */
void readPuzzle(string path, int &rows, int &cols, vector<Piece> &pieces){
    // The buffer is opened to the file
    ifstream file(path);
    // The variables of the faces of the piece are declared
	int left, top, right, bottom;
    // While not at the end of the file
	if(!file.eof()){
        // The number of rows and columns is obtained
		file >> rows;
		file >> cols;
        int id = 1;
        // The pieces are stored
		while(id <= rows*cols){
			file >> left;
			file >> top;
			file >> right;
			file >> bottom;
            Piece aux(left, top, right, bottom, id);
			pieces.push_back(aux);
            id++;
		}
	}
    // The file is closed
	file.close();
}


/**
 * @brief Determine if a piece is already in use or can be used
 * @param board Boards with the solution (and used piece)
 * @param id Id of the piece to compare
 * @return True if the piece can be used, false otherwise
 */
bool validatePiece(vector<Piece> board, int id){
    // All parts are checked in the solution matrix
    for(Piece aux : board){
        if(aux.getId() == id){
            // If the piece is, it cant be used
            return false;
        }
    }
    // If the piece is not, it can be used
    return true;
}


/**
 * @brief Determine if a piece can be used in a position
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the array
 * @param index Position of the matrix to evaluate
 * @param pPiece Piece to evaluate
 * @param board Matrix of the current solution
 * @return True if the piece can be used, false otherwise
 */
bool validatePosition(int rows, int cols, int index, Piece &pPiece, vector<Piece> board){
    if(index == 0){ // Corner Top Left
        // Its checked if the piece belongs to a corner of the puzzle
        if(pPiece.isCorner()){
            // The piece is positioned correctly
            while(pPiece.getTopSide() != 0 || pPiece.getLeftSide() != 0){
                pPiece.rotate();
            }
            // The piece can be used
            return true;
        }
        // The piece cant be used
        return false;
    }else if(index == (cols-1)){ // Corner Top Right
        // Its checked if the piece belongs to a corner of the puzzle
        if(pPiece.isCorner()){
            // The piece is positioned correctly
            while(pPiece.getTopSide() != 0 || pPiece.getRightSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-1].getRightSide() == pPiece.getLeftSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else if(index == (rows*cols-cols)){ // Corner Bottom Left
        // Its checked if the piece belongs to a corner of the puzzle
        if(pPiece.isCorner()){
            // The piece is positioned correctly
            while(pPiece.getBottomSide() != 0 || pPiece.getLeftSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-cols].getBottomSide() == pPiece.getTopSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else if(index == (cols*rows-1)){ // Corner Bottom Right
        // Its checked if the piece belongs to a corner of the puzzle
        if(pPiece.isCorner()){
            // The piece is positioned correctly
            while(pPiece.getBottomSide() != 0 || pPiece.getRightSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-1].getRightSide() == pPiece.getLeftSide() && board[index-cols].getBottomSide() == pPiece.getTopSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else if(index > 0 && index < cols-1){ // Border Top
        // Check that the piece is not a corner but belongs to the puzzle frame
        if(!pPiece.isCorner() && pPiece.isBorder()){
            // The piece is positioned correctly
            while(pPiece.getTopSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-1].getRightSide() == pPiece.getLeftSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else if(index > (rows*cols-cols) && index < (cols*rows-1)){ // Border Bottom
        // Check that the piece is not a corner but belongs to the puzzle frame
        if(!pPiece.isCorner() && pPiece.isBorder()){
            // The piece is positioned correctly
            while(pPiece.getBottomSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-1].getRightSide() == pPiece.getLeftSide() && board[index-cols].getBottomSide() == pPiece.getTopSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else if(index%cols == 0){ // Border Left
        // Check that the piece is not a corner but belongs to the puzzle frame
        if(!pPiece.isCorner() && pPiece.isBorder()){
            // The piece is positioned correctly
            while(pPiece.getLeftSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-cols].getBottomSide() == pPiece.getTopSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else if((index+1)%cols == 0){ // Border Right
        // Check that the piece is not a corner but belongs to the puzzle frame
        if(!pPiece.isCorner() && pPiece.isBorder()){
            // The piece is positioned correctly
            while(pPiece.getRightSide() != 0){
                pPiece.rotate();
            }
            // Check that the piece fits with the pieces around it
            if(board[index-cols].getBottomSide() == pPiece.getTopSide() && board[index-1].getRightSide() == pPiece.getLeftSide()){
                // The piece can be used
                return true;
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }else{ // Center
        // Check that the piece belongs to the center of the puzzle
        if(!pPiece.isCorner() && !pPiece.isBorder()){
            int leftSide = board[index-1].getRightSide();
            int topSide = board[index-cols].getBottomSide();
            for(int k = 0; k < 4; k++){
                // Check that the piece fits with the pieces around it
                if(pPiece.getPosition(k) == leftSide && pPiece.getPosition((k+1)%4) == topSide){
                    while(pPiece.getLeftSide() != leftSide){
                        pPiece.rotate();
                    }
                    // The piece can be used
                    return true;
                }
            }
            // The piece cant be used
            return false;
        }
        // The piece cant be used
        return false;
    }
}


/**
 * @brief Print the puzzle matrix on the screen
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @param sol Board with puzzle solution
 * @param board Board with possible puzzle solution
 * @return Returns true if the solutions are equal, false otherwise
 */
bool compareSolutions(int rows, int cols, vector<Piece> sol, vector<Piece> board){
    int alfa = board[0].getId(), beta = board[cols-1].getId();
    // The upper left corners match
    if(sol[0].getId() == alfa){
        // Check that the upper right corners also match
        if(sol[cols-1].getId() == beta){
            int indexBoard = 1, indexSol = 1;
            // Check that the intermediate pieces match
            while(indexSol > 0 && indexSol < cols-1){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard++;
                indexSol++;
            }
            return true;
        // It is checked if the lower left corner of the solution matches the upper right corner of the possible solution
        }else if(sol[cols*rows-cols].getId() == beta){
            int indexBoard = 1, indexSol = cols;
            // Check that the intermediate pieces match
            while(indexSol > 0 && indexSol < rows*cols-cols && indexSol%cols == 0){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard++;
                indexSol += cols;
            }
            return true;
        }
        return false;
    // Check that the upper left corner of the solution matches the upper right corner of the possible solution
    }else if(sol[0].getId() == beta){
        // Check that the upper right corner of the solution matches the upper left corner of the possible solution
        if(sol[cols-1].getId() == alfa){
            int indexBoard = cols-2, indexSol = 1;
            // Check that the intermediate pieces match
            while(indexSol > 0 && indexSol < cols-1){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard--;
                indexSol++;
            }
            return true;
        // Check that the lower left corner of the solution matches the upper left corner of the possible solution
        }else if(sol[cols*rows-cols].getId() == alfa){
            int indexBoard = cols-2, indexSol = cols*rows-cols*2;
            // Check that the intermediate pieces match
            while(indexSol > 0 && indexSol < rows*cols-cols && (indexSol+1)%cols == 0){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard--;
                indexSol -= cols;
            }
            return true;
        }
        return false;
    // Check that the lower right corner of the solution matches the upper left corner of the possible solution
    }else if(sol[cols*rows-1].getId() == alfa){
        // Check that the upper left corner of the solution matches the upper right corner of the possible solution
        if(sol[cols-1].getId() == beta){
            int indexBoard = 1, indexSol = cols*rows-1-cols;
            // Check that the intermediate pieces match
            while(indexSol > cols*rows-cols && indexSol < cols*rows-1){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard++;
                indexSol -= cols;
            }
            return true;
        // Check that the lower left corner of the solution matches the upper right corner of the possible solution
        }else if(sol[cols*rows-cols].getId() == beta){
            int indexBoard = 1, indexSol = cols*rows-2;
            // Check that the intermediate pieces match
            while(indexSol > cols*rows-cols && indexSol < cols*rows-1){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard++;
                indexSol--;
            }
            return true;
        }
        return false;
    // Check that the lower right corner of the solution matches the upper right corner of the possible solution
    }else if(sol[cols*rows-1].getId() == beta){
        // Check that the upper right corner of the solution matches the upper left corner of the possible solution
        if(sol[cols-1].getId() == alfa){
            int indexBoard = cols-2, indexSol = cols*rows-1-cols;
            // Check that the intermediate pieces match
            while(indexSol > cols*rows-cols && indexSol < cols*rows-1){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard--;
                indexSol -= cols;
            }
            return true;
        // Check that the lower left corner of the solution matches the upper left corner of the possible solution
        }else if(sol[cols*rows-cols].getId() == alfa){
            int indexBoard = cols-2, indexSol = cols*rows-2;
            // Check that the intermediate pieces match
            while(indexSol > cols*rows-cols && indexSol < cols*rows-1){
                // If the piece does not match, the solutions will be different
                if(sol[indexSol].getId() != board[indexBoard].getId()){
                    return false;
                }
                indexBoard--;
                indexSol--;
            }
            return true;
        }
        return false;
    }
    return false;
}


/**
 * @brief Print the puzzle matrix on the screen
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @param board Board with puzzle solution
 */
void printMatrix(int rows, int cols, vector<Piece> board){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << board[i*cols+j].getId() << '\t';
        }
        cout << endl;
    }
    cout << endl;
}


/**
 * @brief Determine if a piece can be used in a position
 * @param rows Number of rows in the matrix
 * @param cols Number of columns in the matrix
 * @param index Position of the matrix to evaluate
 * @param pieces Matrix of all puzzle pieces
 * @return Returns true if the solution has been found, false otherwise
 */
bool solvePuzzle(int rows, int cols, int index, vector<Piece> pieces, vector<vector<Piece>> &solutions){
    static vector<Piece> board;
    if(index == cols*rows){
        solutions.push_back(board);
    }else{
        if(index == cols && solutions.size() != 0){
            for(vector<Piece> sol : solutions){
                if(compareSolutions(rows, cols, sol, board)){
                    return false;
                }   
            }
        }
        // For each piece
        for(Piece p : pieces){
            // It is checked if the part has already been used
            if(validatePiece(board, p.getId())){
                // It is checked if the piece fits in position
                if(validatePosition(rows, cols, index, p, board)){
                    board.push_back(p); 
                    // It is resolved by recurrence      
                    if(solvePuzzle(rows, cols, index+1, pieces, solutions)){
                        // A solution has been found
                        return true;
                    }
                    board.pop_back();
                }
            }
        }
    }
    // The solution has been found
    if(index == 0 && solutions.size() != 0){
        return true;
    }
    return false;
}


int main(int argc, char* argv[]){
    int rows, cols;
    vector<Piece> pieces;
    vector<vector<Piece>> sol;
    if(argc == 2){
        // File data is read
        readPuzzle(argv[1], rows, cols, pieces);
    }else{
        return -1;
    }
    // The function is called to solve the puzzle
    solvePuzzle(rows, cols, 0, pieces, sol);
    // For each solution
    for(vector<Piece> p : sol){
        // The solutions are shown
        printMatrix(rows, cols, p);
    }
    return 0;
}
