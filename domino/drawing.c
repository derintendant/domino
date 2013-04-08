//
//  drawing.c
//  domino
//
//  Created by Dennis Stengele on 02.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//
																		

#include <stdio.h>
#include "drawing.h"
#include "macros.h"

void initBoard(void) {
	CLS;
	for (int i = 1; i <= 17; i++) {
		GOTO(i, 10);
		COLOR(1);
		printf("#");
	}
	for (int i = 1; i <= 17; i++) {
		GOTO(i, 40);
		COLOR(1);
		printf("#");
	}
	for (int i = 11; i < 40; i++) {
		GOTO(1, i);
		COLOR(1);
		printf("#");
	}
	for (int i = 11; i < 40; i++) {
		GOTO(17, i);
		COLOR(1);
		printf("#");
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
	
	if (orientation == 2) {
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
		CURLEFT(2);
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
	
	if (orientation == 3) {
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
		CURUP(1);
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