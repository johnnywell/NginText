//
//  read.c
//  Text Adventure Game
//
//  Created by Johnny Wellington dos Santos on 6/1/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#include "read.h"


void open_story(char *filename){
    story.file_pointer= fopen(filename, "r");
    if(story.file_pointer == NULL){
        printf("Ops, I can't read your history.\n"
               "Are you sure it's ok with the file?\n");
        exit(1);
    }
    else{
        printf("The file is fine, and it's open\n");
    }
};


void load_scene(char *scene_identifier){
    char *current_identifier_pointer;
	char buffer[SCENE_DESCRIPTION_MAX_COLS];
    
    fseek(story.file_pointer, 0, SEEK_SET);
    while(!feof(story.file_pointer)){
		current_identifier_pointer = fgets(buffer, sizeof(buffer), story.file_pointer);
		buffer[strcspn(buffer, "\r\n")] = 0; // Removes the new line character
		if (strcmp(buffer, scene_identifier) == 0){
			strcpy(story.scene.identifier, buffer);
			break;
        }
        
    }
};
