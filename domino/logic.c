//
//  logic.c
//  domino
//
//  Created by Dennis Stengele on 06.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"
#include "macros.h"
#include "vars.h"
#include "drawing.h"

struct Player initPlayer(int number) {
	
	struct Player player;
	
	GOTO(18,1);
	printf("Spieler %d: Bitte Name eingeben: ", number);
	COLOR(33);
	if (number == 1) {
		GOTO(1,1);
		scanf("%s", &player.name[0]);
	}
	else {
		GOTO(1,41);
		scanf("%s", &player.name[0]);
	}
	GOTO(1, 10);
	COLOR(30);
	printf("###############################\n");
	printf("         #                             #         ");
	for (int i = 0; i <= 27; i++) {
		player.domino[i] = -1;
	}
	GOTO(18, 0);
	EMPTY;
	COLOR(30);
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

void initNewRound(void) {
	srandom((int)time(NULL));
	for (int i = 0; i <= 6; i++) {
		if (player1.domino[i] == -1) {
			int nextDomino = ((int)random() % 26);
			while (stack[nextDomino] == -1) {
				nextDomino = ((int)random() % 26);
			}
			player1.domino[i] = stack[nextDomino];
			stack[nextDomino] = -1;
		} else {
			return;
		}
	}
	
	for (int i = 0; i <= 6; i++) {
		if (player2.domino[i] == -1) {
			int nextDomino = ((int)random() % 26);
			while (stack[nextDomino] == -1) {
				nextDomino = ((int)random() % 26);
			}
			player2.domino[i] = stack[nextDomino];
			stack[nextDomino] = -1;
		} else {
			return;
		}
	}
	drawPlayerStack();
	
	int firstDominoIndex = ((int)random() % 26);
	while (stack[firstDominoIndex] == -1 || firstDominoIndex == 0) {
		firstDominoIndex = ((int)random() % 26);
	}
	int firstDomino = stack[firstDominoIndex];
	stack[firstDominoIndex] = -1;
	
	GOTO(9, 24);
	COLOR(31);
	drawDomino((int)(firstDomino / 10), firstDomino % 10, 0);
}

int *playRound(void) {
	int next;
	int *ergebnis = malloc(2*sizeof(int));
	
	GOTO(18, 1);
	COLOR(32);
	printf("Nächster Zug?");
	scanf("%d", &next);
	GOTO(18, 1);
	
	ergebnis[0] = 6;
	ergebnis[1] = 8;
	
	return ergebnis;
}