//
//  CPU piece.h
//  Tic-Tac-Toe
//
//  Created by Leron Julian on 10/12/16.
//  Copyright © 2016 Leron Julian. All rights reserved.
//

#ifndef CPU_piece_h
#define CPU_piece_h
class CPU_piece{
private:
    char cpu;
public:
    void setCpuPiece(char cpu2);
    char getCpuPiece() const;
};
void CPU_piece::setCpuPiece(char cpu2){
    cpu = cpu2;
}

char CPU_piece::getCpuPiece() const{
    return cpu;
}


#endif /* CPU_piece_h */
