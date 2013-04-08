//
//  logic.c
//  domino
//
//  Created by Dennis Stengele on 06.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include "macros.h"

struct Player initPlayer(int number) {
	
	struct Player player;
	
	GOTO(18,1);
	printf("Spieler %d: Bitte Name eingeben: ", number);
	
	if (number == 1) {
		GOTO(1,1);
	}
	else {
		GOTO(1,42);
	}
	scanf("%s", &player.name[0]);
	player.score = 0;
	for (int i = 0; i <= 27; i++) {
		player.domino[i] = -1;
	}
	
	return player;
}

void initGame(int *stack) {
	stack[0] = 0;
	stack[1] = 1;
	stack[2] = 2;
	stack[3] = 3;
	stack[4] = 4;
	stack[5] = 5;
	stack[6] = 6;
	stack[7] = 11;
	stack[8] = 12;
	stack[9] = 13;
	stack[10] = 14;
	stack[11] = 15;
	stack[12] = 16;
	stack[13] = 22;
	stack[14] = 23;
	stack[15] = 24;
	stack[16] = 25;
	stack[17] = 26;
	stack[18] = 33;
	stack[19] = 34;
	stack[20] = 35;
	stack[21] = 36;
	stack[22] = 44;
	stack[23] = 45;
	stack[24] = 46;
	stack[25] = 55;
	stack[26] = 56;
	stack[27] = 66;
}