//
//  logic.h
//  domino
//
//  Created by Dennis Stengele on 06.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//

#ifndef domino_logic_h
#define domino_logic_h

typedef struct Player {
	char name[9];
	int score;
	int domino[28];
} Player ;

struct Player initPlayer(int);
void initGame(int[28]);
void initNewRound(void);
int *playRound(void);
void nextTurn(int);


#endif
