//
//  drawing.c
//  domino
//
//  Created by Dennis Stengele on 02.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//
																		

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#include "drawing.h"
#include "macros.h"
#include "vars.h"
#include "logic.h"

int dice[7] = {0, 1, 2, 3, 4, 5, 6};

void initBoard(void) {
	CLS;
	for (int i = 1; i <= 17; i++) {
		GOTO(i, 11);
		COLOR(1);
		printf("+");
	}
	for (int i = 1; i <= 17; i++) {
		GOTO(i, 40);
		COLOR(1);
		printf("+");
	}
	
	for (int i = 11; i < 40; i++) {
		GOTO(1, i);
		COLOR(1);
		printf("+");
	}
	for (int i = 11; i < 40; i++) {
		GOTO(5, i);
		COLOR(1);
		printf("+");
	}
	for (int i = 11; i < 40; i++) {
		GOTO(9, i);
		COLOR(1);
		printf("+");
	}
	for (int i = 11; i < 40; i++) {
		GOTO(13, i);
		COLOR(1);
		printf("+");
	}
	for (int i = 11; i < 40; i++) {
		GOTO(17, i);
		COLOR(1);
		printf("+");
	}
	printf("\n");
}

void drawDomino(int first, int second, int placement) {
	
	switch (placement) {
		case 0:
			GOTO(2, 12);
			printf("%d", dice[first]);
			CURDOWN(1);
			CURLEFT(1);
			printf("%d", dice[second]);
			break;
		case 1:
			GOTO(2, 13);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 2:
			GOTO(2, 15);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 3:
			GOTO(2, 17);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 4:
			GOTO(2, 19);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 5:
			GOTO(2, 21);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 6:
			GOTO(2, 23);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 7:
			GOTO(2, 25);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 8:
			GOTO(2, 27);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 9:
			GOTO(2, 29);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 10:
			GOTO(2, 31);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 11:
			GOTO(2, 33);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 12:
			GOTO(2, 35);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 13:
			GOTO(2, 37);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 14:
			GOTO(2, 39);
			printf("%d", dice[first]);
			CURDOWN(1);
			CURLEFT(1);
			printf("%d", dice[second]);
			break;
		case 15:
			GOTO(4, 38);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 16:
			GOTO(4, 36);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 17:
			GOTO(4, 34);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 18:
			GOTO(4, 32);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 19:
			GOTO(4, 30);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 20:
			GOTO(4, 28);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 21:
			GOTO(4, 26);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 22:
			GOTO(4, 24);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 23:
			GOTO(4, 22);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 24:
			GOTO(4, 20);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 25:
			GOTO(4, 18);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 26:
			GOTO(4, 16);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 27:
			GOTO(4, 14);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		case 28:
			GOTO(4, 12);
			printf("%d", dice[first]);
			printf("%d", dice[second]);
			break;
		default:
			break;
	}
	GOTO(18, 50);
}

void drawPlayerStack(void) {
		// Clear Stack Views
	for (int i = 3; i <= 17; i++) {
		for (int j = 1; j <= 10; j++) {
			GOTO(i, j);
			printf(" ");
		}
	}
	
	for (int i = 3; i <= 17; i++) {
		for (int j = 41; j <= 50; j++) {
			GOTO(i, j);
			printf(" ");
		}
	}

		// Spieler 1
	for (int i = 0; i <= 27; i++) {
		if (player1.domino[i] != -1) {
			if (i < 10) {
				GOTO(3+i, 7);
				COLOR(30);
				printf("%d%d", dice[(int)(player1.domino[i] / 10)], dice[(player1.domino[i] % 10)]);
				GOTO(3+i, 10);
				COLOR(35);
				printf("%d", i);
			} else {
				GOTO(i-7, 2);
				COLOR(30);
				printf("%d%d", dice[(int)(player1.domino[i] / 10)], dice[(player1.domino[i] % 10)]);
				GOTO(3+i, 5);
				COLOR(35);
				printf("%d", i);
			}
		}
		
	}
	
		// Spieler 2
	for (int i = 0; i <= 27; i++) {
		if (player2.domino[i] != -1) {
			if (i < 10) {
				GOTO(3+i, 41);
				COLOR(35);
				printf("%d", i);
				GOTO(3+i, 43);
				COLOR(30);
				printf("%d%d", dice[(int)(player2.domino[i] / 10)], dice[(player2.domino[i] % 10)]);
			} else {
				GOTO(3+i, 46);
				COLOR(35);
				printf("%d", i);
				GOTO(i-7, 48);
				COLOR(30);
				printf("%d%d", dice[(int)(player2.domino[i] / 10)], dice[(player2.domino[i] % 10)]);
			}
		}
		
	}
}