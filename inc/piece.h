#ifndef _PIECE_H_
#define _PIECE_H_

#include <string>

using namespace std;
 
/**
 * @file 
 * @brief Piece Class
 *
 */
class Piece{
	
	private:

        int left;	///< Left side of the piece
		int top;	///< Top side of the piece
		int right;	///< Right side of the piece
		int bottom;	///< Bottom side of the piece
        int id;	    ///< Id of the piece

	public:

		/**
		 * @brief Empty constructor
		 */
		Piece();

		/**
		 * @brief Object constructor
		 * @param p Piece object
		 */
		Piece(const Piece& p);

		/**
		 * @brief Parameterized constructor
		 * @param left Left side of the piece
		 * @param top Top side of the piece
		 * @param right Right side of the piece
		 * @param bottom Bottom side of the piece
		 * @param id Id of the piece
		 * @pre All parameters must be different from -1
		 */
		Piece(int left, int top, int right, int bottom, int id);


		/**
		 * @brief Destructor
		 */
		~Piece();

		/**
		 * @brief Operator Overload
         * @param p Piece to copy
		 */
        Piece& operator=(const Piece& p);


		/**
		 * @brief Returns the value of the side of the piece (0 = Left)
		 * @param position Value on the side of the piece (0 = Left)
		 * @return Value of the side
		 */
		int getPosition(int position) const;
		
		
		/**
		 * @brief Set the value on the side of the piece
		 * @param position Value on the side of the piece (0 = Left)
		 * @param value Piece side value
		 * @pre position must be 0, 1, 2, 3
		 */
		void setPosition(int position, int value);				


		/**
		 * @brief Returns the value of the left side of the piece
		 * @return Value of the left side
		 */
		int getLeftSide() const;
		
		
		/**
		 * @brief Set the value on the left side of the piece
		 * @param left Value on the left side of the piece
		 * @pre left must be different from -1
		 */
		void setLeftSide(int left);
		
		
		/**
		 * @brief Returns the value of the top side of the piece
		 * @return Value of the top side
		 */
		int getTopSide() const;
		
		
		/**
		 * @brief Set the value on the top side of the piece
		 * @param top Value on the top side of the piece
		 * @pre top must be different from -1
		 */
		void setTopSide(int top);
		
		
		/**
		 * @brief Returns the value of the right side of the piece
		 * @return Value of the right side
		 */
		int getRightSide() const;
		
		
		/**
		 * @brief Set the value on the right side of the piece
		 * @param right Value on the right side of the piece
		 * @pre right must be different from -1
		 */
		void setRightSide(int right);
		
		
		/**
		 * @brief Returns the value of the bottom side of the piece
		 * @return Value of the bottom side
		 */
		int getBottomSide() const;
		
		
		/**
		 * @brief Set the value on the bottom side of the piece
		 * @param bottom Value on the bottom side of the piece
		 * @pre bottom must be different from -1
		 */
		void setBottomSide(int bottom);


        /**
		 * @brief Returns the value of the id of the piece
		 * @return Value of the id of the piece
		 */
		int getId() const;
		
		
		/**
		 * @brief Set the value on the id of the piece
		 * @param id Value on the id of the piece
		 * @pre id must be different from -1
		 */
		void setId(int id);


		/**
		 * @brief Rotate de piece
		 */
		void rotate();
		
		
		/**
		 * @brief Returns if the piece is empty
		 * @return Returns true if empty, false otherwise
		 */
		bool empty() const;


        /**
		 * @brief Returns the piece as a string
		 * @return Returns a string
		 */
		string toString();


        /**
		 * @brief Returns if the piece is a corner
		 * @return Returns true if it is a corner, false otherwise
		 */
		bool isCorner();


        /**
		 * @brief Returns if the piece is a border
		 * @return Returns true if it is a border, false otherwise
		 */
		bool isBorder();

    
        /**
		 * @brief Erase the values of the piece
		 */
		void erase();

};

#endif
