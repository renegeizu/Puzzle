#include <piece.h>

using namespace std;

Piece::Piece(){
	left	= -1;
	top		= -1;
	right	= -1;
	bottom	= -1;
    id      = -1;
}

Piece::Piece(const Piece& p){
	this->left      = p.getLeftSide();
	this->top		= p.getTopSide();
	this->right	    = p.getRightSide();
	this->bottom	= p.getBottomSide();
    this->id        = p.getId();
}

Piece::Piece(int left, int top, int right, int bottom, int id){
	this->left		= left;
	this->top		= top;
	this->right		= right;
	this->bottom	= bottom;
    this->id        = id;
}

Piece::~Piece(){
	left	= -1;
	top		= -1;
	right	= -1;
	bottom	= -1;
    id      = -1;
}

Piece& Piece::operator=(const Piece& p){
    if(this != &p){
        this->left      = p.getLeftSide();
        this->top       = p.getTopSide();
        this->right     = p.getRightSide();
        this->bottom    = p.getBottomSide();
        this->id        = p.getId();
    }
    return *this;
}

int Piece::getPosition(int position) const{
    if(position == 0){
       return left;
    }else if(position == 1){
        return top;
    }else if(position == 2){
        return right;
    }else if(position == 3){
        return bottom;
    }else{
        return -1;
    }
}
		
void Piece::setPosition(int position, int value){
    if(position == 0){
        left = value;
    }else if(position == 1){
        top = value;
    }else if(position == 2){
        right = value;
    }else if(position == 3){
        bottom = value;
    }
}

int Piece::getLeftSide() const{
	return left;
}
		
void Piece::setLeftSide(int left){
	this->left = left;
}

int Piece::getTopSide() const{
	return top;
}
		
void Piece::setTopSide(int top){
	this->top = top;
}

int Piece::getRightSide() const{
	return right;
}
		
void Piece::setRightSide(int right){
	this->right = right;
}

int Piece::getBottomSide() const{
	return bottom;
}
		
void Piece::setBottomSide(int bottom){
	this->bottom = bottom;
}

int Piece::getId() const{
    return id;
}
		
void Piece::setId(int id){
    this->id = id;
}

void Piece::rotate(){
    int auxLeft = this->left, auxTop = this->top, auxRight = this->right, auxBottom = this->bottom;
    this->left = auxBottom;
    this->top = auxLeft;
    this->right = auxTop;
    this->bottom = auxRight;
}

bool Piece::empty() const{
	if(left == -1 || top == -1 || right == -1 || bottom == -1 || id == -1){
		return true;
	}else{
		return false;
	}
}

string Piece::toString(){
    string result = "ID: " + to_string(id) + ", Values: " + to_string(left) + ", " + to_string(top) + ", " + to_string(right) + ", " + to_string(bottom);
    return result;
}

bool Piece::isCorner(){
    if(left == 0 && (top == 0 || right == 0 || bottom == 0)){
        return true;
    }else if(top == 0 && (right == 0 || bottom == 0 || left == 0)){
        return true;
    }else if(right == 0 && (bottom == 0 || left == 0 || top == 0)){
        return true;
    }else if(bottom == 0 && (left == 0 || top == 0 || right == 0)){
        return true;
    }else{
        return false;
    }
}

bool Piece::isBorder(){
    if(left == 0 || top == 0 || right == 0 || bottom == 0){
        return true;
    }else{
        return false;
    }
}

void Piece::erase(){
    left    = -1;
    top     = -1;
    bottom  = -1;
    right   = -1;
    id      = -1;
}
