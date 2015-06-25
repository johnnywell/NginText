//
//  main.c
//  Text Adventure Game
//
//  Created by Johnny Wellington dos Santos on 6/1/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "story.h"

int main(int argc, const char * argv[]) {
	char story_path[256];
	setbuf(stdout, NULL);
    //printf("Please inform the path to the story you want to play:\n> " );
	strcpy(story_path, "..\\NginText\\stories\\prototype.story");
	//gets(story_path);
	open_story(story_path);
    load_scene("@Inicio");
	system("pause");
    exit(0);
}
