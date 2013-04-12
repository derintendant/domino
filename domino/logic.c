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
	printf("Spieler %d: Bitte Name eingeben", number);
	COLOR(33);
	if (number == 1) {
		GOTO(1,1);
		scanf("%s", &player.name[0]);
	}
	else {
		GOTO(1,41);
		scanf("%s", &player.name[0]);
	}
	GOTO(1, 11);
	COLOR(30);
	          printf("++++++++++++++++++++++++++++++\n");
	printf("          +                            +         ");
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
	int firstDomino = stack[firstDominoIndex];
	while (stack[firstDominoIndex] == -1 || firstDomino % 11 == 0) {
		firstDominoIndex = ((int)random() % 26);
		firstDomino = stack[firstDominoIndex];
	}
	stack[firstDominoIndex] = -1;
	
	GOTO((4 * gameRound - 2), 25);
	COLOR(31);
	drawDomino((int)(firstDomino / 10), firstDomino % 10, 7);
	edge1 = (int)(firstDomino / 10);
	edge2 = (firstDomino % 10);
}

int *playRound(void) {
	int *ergebnis = malloc(2*sizeof(int));
	
	int currentPlayer = 1;
	if (gameRound == 2 || gameRound == 4) {
		currentPlayer = 2;
	}
	while (1) {						// Abbruchbedingungen für Runde
		nextTurn(currentPlayer);
		switch (currentPlayer) {
			case 1:
				currentPlayer = 2;
				break;
			case 2:
				currentPlayer = 1;
			default:
				break;
		}
	}
	
	ergebnis[0] = 6;
	ergebnis[1] = 8;
	
	return ergebnis;
}

void nextTurn(int currentPlayer) {
	int next = -1, possibleDominos[28] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, links, rechts, edge1New = -1, edge2New = -1;
	COMMAND;
	COLOR(32);
	printf("Spieler %d: Welchen Stein legen?                   ", currentPlayer);
	CURLEFT(17);
	
	if (currentPlayer == 1) {
		for (int i = 0; i <= 27; i++) {
			links = (int)(player1.domino[i] / 10);
			rechts = (player1.domino[i] % 10);
			if ((player1.domino[i] != -1) && ((links == edge1)  ||  (rechts == edge1)  ||  (links == edge2)  ||  (rechts == edge2))){
				int j = 0;
				while (possibleDominos[j] != -1) {
					j++;
				}
				possibleDominos[j] = i;
				printf("%d, ", i);
			}
		}
		
		CURLEFT(2);
		printf("  ");

		int ok = 0, i = 0;
		while (ok != 1) {			
			GOTO(2, 1);
			printf(" ");
			CURLEFT(1);
			scanf("%d", &next);
			for (i = 0; i <= 27; i++) {
				if (next == possibleDominos[i]) {
					ok = 1;
					GOTO(2, 1);
					printf(" ");
					player1.domino[next] = -1;
					drawPlayerStack();
				}
			}
		}
	}
	if (currentPlayer == 2) {
		for (int i = 0; i <= 27; i++) {
			links = (int)(player2.domino[i] / 10);
			rechts = (player2.domino[i] % 10);
			if ((player2.domino[i] != -1) && ((links == edge1)  ||  (rechts == edge1)  ||  (links == edge2)  ||  (rechts == edge2))){
				int j = 0;
				while (possibleDominos[j] != -1) {
					j++;
				}
				possibleDominos[j] = i;
				printf("%d, ", i);
			}
		}
		
		CURLEFT(2);
		printf("  ");
		
		int ok = 0, i = 0;
		while (ok != 1) {
			GOTO(2, 50);
			printf(" ");
			CURLEFT(1);
			scanf("%d", &next);
			for (i = 0; i <= 27; i++) {
				if (next == possibleDominos[i]) {
					ok = 1;
					GOTO(2, 1);
					printf(" ");
					player2.domino[next] = -1;
					drawPlayerStack();
				}
			}
		}
	}
	if (edge1 == edge2) {
		COMMAND;
		printf("Wo soll angelegt werden?");
		char choice = 'x';
		while (choice != 'l' && choice != 'r') {
			GOTO(2, (currentPlayer == 1 ? 1 : 49));
			scanf("%c", &choice);
		}
		switch (choice) {
			case 'l':
				drawDomino((int)(next / 10), (next % 10), nextPlacement[0]);
				if (nextPlacement[0] == 0) {
					nextPlacement[0] = 28;
				} else {
					nextPlacement[0]--;
				}
				break;
			case 'r':
				drawDomino((int)(next / 10), (next % 10), nextPlacement[1]);
				if (nextPlacement[1] == 28) {
					nextPlacement[1] = 0;
				} else {
					nextPlacement[1]++;
				}
				break;
			default:
				break;
		}
	} else {
		if ((int)(next / 10) == edge1 ) {
			if (nextPlacement[0] == 0) {											// hochkant links
				drawDomino((int)(next / 10), (next % 10), nextPlacement[0]);
				nextPlacement[0] = 28;
				edge1New = next % 10;
			}
			if (nextPlacement[0] == 14) {											// hochkant rechts
				drawDomino((next % 10), (int)(next / 10), 14);
				nextPlacement[0] = 13;
				edge1New = next % 10;
			}
			if ((nextPlacement[0] > 0) && (nextPlacement[0] < 7)) {					// quer oben links
				drawDomino((next % 10), (int)(next / 10), nextPlacement[0]);
				nextPlacement[0]--;
				edge1New = (int)(next / 10);
			}
			if ((nextPlacement[0] < 14) && (nextPlacement[0] > 7)) {				// quer oben rechts
				drawDomino((next % 10), (int)(next / 10), nextPlacement[0]);
				nextPlacement[0]--;
				edge1New = next % 10;
			}
			if ((nextPlacement[0] < 29) && (nextPlacement[0] > 14)) {				// quer unten
				drawDomino((int)(next / 10), (next % 10), nextPlacement[0]);
				nextPlacement[0]--;
				edge1New = next % 10;
			}
			goto hack1;
			
		}
		if ((next % 10) == edge1 ) {
			if (nextPlacement[0] == 0) {											// hochkant links
				drawDomino((next % 10), (int)(next / 10), nextPlacement[0]);
				nextPlacement[0] = 28;
				edge1New = (int)(next / 10);
			}
			if (nextPlacement[0] == 14) {											// hochkant rechts
				drawDomino((int)(next / 10), (next % 10), 14);
				nextPlacement[0] = 13;
				edge1New = (int)(next / 10);
			}
			if ((nextPlacement[0] > 0) && (nextPlacement[0] < 7)) {					// quer oben links
				drawDomino((int)(next / 10), (next % 10), nextPlacement[0]);
				nextPlacement[0]--;
				edge1New = (int)(next / 10);
			}
			if ((nextPlacement[0] < 14) && (nextPlacement[0] > 7)) {				// quer oben rechts
				drawDomino((int)(next / 10), (next % 10), nextPlacement[0]);
				nextPlacement[0]--;
				edge1New = next % 10;
			}
			if ((nextPlacement[0] < 29) && (nextPlacement[0] > 14)) {				// quer unten
				drawDomino((int)(next / 10), (next % 10), nextPlacement[0]);
				nextPlacement[0]--;
				edge1New = next % 10;
			}
			goto hack1;
		}
		if ((int)(next / 10) == edge2 ) {
			if (nextPlacement[0] == 0) {											// hochkant links
				drawDomino((int)(next / 10), (next % 10), nextPlacement[1]);
				nextPlacement[1] = 1;
				edge2New = (int)(next / 10);
			}
			if (nextPlacement[1] == 14) {											// hochkant rechts
				drawDomino((next % 10), (int)(next / 10), 14);
				nextPlacement[1] = 15;
				edge2New = (int)(next / 10);
			}
			if ((nextPlacement[1] > 0) && (nextPlacement[1] < 7)) {					// quer oben links
				drawDomino((int)(next / 10), (next % 10), nextPlacement[1]);
				nextPlacement[1]++;
				edge2New = next % 10;
			}
			if ((nextPlacement[1] < 14) && (nextPlacement[1] > 7)) {				// quer oben rechts
				drawDomino((int)(next / 10), (next % 10), nextPlacement[1]);
				nextPlacement[1]++;
				edge2New = (int)(next / 10);
			}
			if ((nextPlacement[1] < 29) && (nextPlacement[1] > 14)) {				// quer unten
				drawDomino((next % 10), (int)(next / 10), nextPlacement[1]);
				nextPlacement[1]++;
				edge2New = (next % 10);
			}
			goto hack1;
		}
		if ((next % 10) == edge2 ) {
			if (nextPlacement[1] == 0) {											// hochkant links
				drawDomino((next % 10), (int)(next / 10), nextPlacement[1]);
				nextPlacement[1] = 1;
				edge2New = next % 10;
			}
			if (nextPlacement[1] == 14) {											// hochkant rechts
				drawDomino((int)(next / 10), (next % 10), 14);
				nextPlacement[1] = 15;
				edge2New = next % 10;
			}
			if ((nextPlacement[1] > 0) && (nextPlacement[1] < 7)) {					// quer oben links
				drawDomino((int)(next / 10), (next % 10), nextPlacement[1]);
				nextPlacement[1]++;
				edge2New = next % 10;
			}
			if ((nextPlacement[1] < 14) && (nextPlacement[1] > 7)) {				// quer oben rechts
				drawDomino((int)(next / 10), (next % 10), nextPlacement[1]);
				nextPlacement[1]++;
				edge2New = next % 10;
			}
			if ((nextPlacement[1] < 29) && (nextPlacement[1] > 14)) {				// quer unten
				drawDomino((next % 10), (int)(next / 10), nextPlacement[1]);
				nextPlacement[1]++;
				edge2New = next % 10;
			}
			goto hack1;
		}
		hack1:
			edge1 = edge1New;
			edge2 = edge2New;
	}
}