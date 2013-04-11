//
//  drawing.c
//  domino
//
//  Created by Dennis Stengele on 02.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//
																		

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "drawing.h"
#include "macros.h"
#include "vars.h"
#include "logic.h"

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

void drawDomino(int left, int right, int orientation) {
	if (orientation == 0) {
		switch (left) {
			case 0:
				printf("\u2610");
				break;
			case 1:
				printf("\u2680");
				break;
			case 2:
				printf("\u2681");
				break;
			case 3:
				printf("\u2682");
				break;
			case 4:
				printf("\u2683");
				break;
			case 5:
				printf("\u2684");
				break;
			case 6:
				printf("\u2685");
				break;
			default:
				break;
		}
		switch (right) {
			case 0:
				printf("\u2610");
				break;
			case 1:
				printf("\u2680");
				break;
			case 2:
				printf("\u2681");
				break;
			case 3:
				printf("\u2682");
				break;
			case 4:
				printf("\u2683");
				break;
			case 5:
				printf("\u2684");
				break;
			case 6:
				printf("\u2685");
				break;
			default:
				break;
		}
	}
	
	if (orientation == 1) {
		switch (left) {
			case 0:
				printf("\u2610");
				break;
			case 1:
				printf("\u2680");
				break;
			case 2:
				printf("\u2681");
				break;
			case 3:
				printf("\u2682");
				break;
			case 4:
				printf("\u2683");
				break;
			case 5:
				printf("\u2684");
				break;
			case 6:
				printf("\u2685");
				break;
			default:
				break;
		}
		CURDOWN(1);
		CURLEFT(1);
		switch (right) {
			case 0:
				printf("\u2610");
				break;
			case 1:
				printf("\u2680");
				break;
			case 2:
				printf("\u2681");
				break;
			case 3:
				printf("\u2682");
				break;
			case 4:
				printf("\u2683");
				break;
			case 5:
				printf("\u2684");
				break;
			case 6:
				printf("\u2685");
				break;
			default:
				break;
		}
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
				drawDomino((int)(player1.domino[i] / 10), player1.domino[i] % 10, 0);
				GOTO(3+i, 10);
				COLOR(35);
				printf("%d", i);
			} else {
				GOTO(i-7, 2);
				COLOR(30);
				drawDomino((int)(player1.domino[i] / 10), player1.domino[i] % 10, 0);
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
				COLOR(30);
				drawDomino((int)(player2.domino[i] / 10), player2.domino[i] % 10, 0);
			} else {
				GOTO(i-7, 44);
				COLOR(35);
				printf("%d", i);
				COLOR(30);
				drawDomino((int)(player1.domino[i] / 10), player1.domino[i] % 10, 0);
			}
		}
	}

}