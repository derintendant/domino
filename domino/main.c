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

int stack[28];

int main(int argc, const char * argv[])
{
	
	
	initBoard();									// Spielfeld zeichnen
	struct Player player1 = initPlayer(1);			// Spieler Eins initialisieren
	struct Player player2 = initPlayer(2);			// Spieler Zwei Initialisieren
	initGame(stack);								// Steinstapel initialisieren
	
    GOTO(10,4);
	drawDomino(4, 3, 0);
	
	
	
	
	
    return 0;
}

