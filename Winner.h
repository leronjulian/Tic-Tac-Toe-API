//
//  Winner.h
//  Tic-Tac-Toe
//
//  Created by Leron Julian on 10/12/16.
//  Copyright © 2016 Leron Julian. All rights reserved.
//

#ifndef Winner_h
#define Winner_h
class Winner{
private:
    char winningPiece;
public:
    void setWinningPiece(char winner);
    char getWinningPiece() const;
};

void Winner::setWinningPiece(char winner){
    winningPiece = winner;
}

char Winner::getWinningPiece() const{
    return winningPiece;
}
#endif /* Winner_h */
