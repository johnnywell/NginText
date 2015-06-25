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
#include "read.h"

int main(int argc, const char * argv[]) {
	char story_path[256];
    //printf("Please inform the path to the story you want to play:\n> " );
	strcpy(story_path, "C:\\Users\\johnn_000\\Documents\\GitHub\\NginText\\stories\\prototype.story");
	//gets(story_path);
	open_story(story_path);
    load_scene("@Inicio");
    printf("I found the scene %s you've asked me. What now?\n", story.scene.identifier);
	system("pause");
    exit(0);
}
