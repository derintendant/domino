//
//  main.c
//  domino
//
//  Created by Dennis Stengele on 02.04.13.
//  Copyright (c) 2013 Dennis Stengele. All rights reserved.
//

#include <stdio.h>
#include "drawing.h"
#include "logic.h"
#include "macros.h"
#include "vars.h"

int stack[28] = {0}, ergebnisGesamt[2][5] = {0}, *ergebnis, edge1, edge2, gameRound, nextPlacement[2] = {6, 8};
struct Player player1 = {.name = {0}, .score = 0, .domino = {0}};
struct Player player2 = {.name = {0}, .score = 0, .domino = {0}};

int main(int argc, const char * argv[])
{
	initBoard();									// Spielfeld zeichnen
	player1 = initPlayer(1);						// Spieler Eins initialisieren
	player2 = initPlayer(2);						// Spieler Zwei Initialisieren
	
	initGame(stack);
	initNewRound();
	
		// BEGIN Scoring
	
	gameRound = 1;
	ergebnis = playRound();
	ergebnisGesamt[0][0] += ergebnis[0];
	ergebnisGesamt[0][4] += ergebnis[0];
	ergebnisGesamt[1][0] += ergebnis[1];
	ergebnisGesamt[1][4] += ergebnis[1];
	
	gameRound = 2;
	ergebnis = playRound();
	ergebnisGesamt[0][1] += ergebnis[0];
	ergebnisGesamt[0][4] += ergebnis[0];
	ergebnisGesamt[1][1] += ergebnis[1];
	ergebnisGesamt[1][4] += ergebnis[1];
	
	gameRound = 3;
	ergebnis = playRound();
	ergebnisGesamt[0][2] += ergebnis[0];
	ergebnisGesamt[0][4] += ergebnis[0];
	ergebnisGesamt[1][2] += ergebnis[1];
	ergebnisGesamt[1][4] += ergebnis[1];
	
	gameRound = 4;
	ergebnis = playRound();
	ergebnisGesamt[0][3] += ergebnis[0];
	ergebnisGesamt[0][4] += ergebnis[0];
	ergebnisGesamt[1][3] += ergebnis[1];
	ergebnisGesamt[1][4] += ergebnis[1];
	
		// END Scoring
	
	
    return 0;
}

