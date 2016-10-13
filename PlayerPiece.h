//
//  PlayerPiece.h
//  Tic-Tac-Toe
//
//  Created by Leron Julian on 10/12/16.
//  Copyright © 2016 Leron Julian. All rights reserved.
//

#ifndef PlayerPiece_h
#define PlayerPiece_h
class Player_piece{
private:
    char player;
public:
    void setPlayerPiece(char player2);
    char getPlayerPiece() const;
};
void Player_piece::setPlayerPiece(char player2){
    player = player2;
}

char Player_piece::getPlayerPiece() const{
    return player;
}
#endif /* PlayerPiece_h */
