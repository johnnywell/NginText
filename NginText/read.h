//
//  read.h
//  Text Adventure Game
//
//  Created by Johnny Wellington dos Santos on 6/1/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#ifndef __Text_Adventure_Game__read__
#define __Text_Adventure_Game__read__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_COMMENT_IDENTIFIER  "'''"
#define HEADER_IDENTIFIER '='
#define LINE_COMMENT_IDENTIFIER '#'
#define OPTION_IDENTIFIER '-'
#define REDIRECTO_IDENTIFIER '->'
#define SCENE_IDENTIFIER '@'
#define OPEN_LOCAL_VAR_IDENTIFIER '<'
#define CLOSE_LOCAL_VAR_IDENTIFIER '>'
#define OPEN_GLOBAL_VAR_IDENTIFIER '<<'
#define CLOSE_GLOBAL_VAR_IDENTIFIER '>>'

// Scene related constants
#define SCENE_IDENTIFIER_LENGTH 20
#define SCENE_OPTION_IDENTIFIER_LENGTH 10
#define SCENE_MAX_OPTIONS 5
#define SCENE_DESCRIPTION_MAX_LINES 100
#define SCENE_DESCRIPTION_MAX_COLS 100

// ------ Structures definitions ------

struct scene_option {
    char identifier[SCENE_OPTION_IDENTIFIER_LENGTH];
    char target[SCENE_IDENTIFIER_LENGTH];
};


struct scene {
    char identifier[SCENE_IDENTIFIER_LENGTH];
    char description[SCENE_DESCRIPTION_MAX_LINES][SCENE_DESCRIPTION_MAX_COLS];
    struct scene_option options[SCENE_MAX_OPTIONS];
    
};

struct story_factory {
    FILE *file_pointer;
    struct scene actual_scene;
    long previews_position_in_file;
    long position_in_file;
    char current_char;
    char current_scene_identifier[SCENE_IDENTIFIER_LENGTH];
    char previews_scene_identifier[SCENE_IDENTIFIER_LENGTH];
};

struct story_factory story;
//
//void open_story();
//void load_scene(char *scene_identifier);


void open_story(char *filename){
    story.file_pointer= fopen(filename, "r");
    if(story.file_pointer == NULL){
        printf("Ops, I can't read your history.\n"
               "Are you sure it's ok with the file?\n");
        exit(1);
    }
//    else{
//        printf("The file is fine, and it's open "
//               "I'm returning a pointer to the file to whom asked me.");
//    }
};


void load_scene(char *scene_identifier){
    char *current_identifier_pointer;
    char buffer[SCENE_IDENTIFIER_LENGTH];
    
    fseek(story.file_pointer, 0, SEEK_SET);
    do{
        story.previews_position_in_file = ftell(story.file_pointer);
        current_identifier_pointer = fgets(
                                           buffer,
                                           SCENE_DESCRIPTION_MAX_COLS,
                                           story.file_pointer
                                           );
        if (current_identifier_pointer == scene_identifier){
            strcpy(story.current_scene_identifier, buffer);
            buffer[strcspn(buffer, "\r\n")] = 0;
            break;
        }

        
        
//        if((story.current_char = fgetc(story.file_pointer)) == SCENE_IDENTIFIER){
//            fseek(story.file_pointer, story.previews_position_in_file, SEEK_SET);
//            current_identifier_pointer = fgets(
//                                               buffer,
//                                               SCENE_IDENTIFIER_LENGTH,
//                                               story.file_pointer
//                                               );
//            if (current_identifier_pointer == scene_identifier){
////                strcpy(story.current_scene_identifier, buffer);
//                buffer[strcspn(buffer, "\r\n")] = 0;
//                break;
//            }
//            
//        }
        
    }while(!feof(story.file_pointer));
};


#endif /* defined(__Text_Adventure_Game__read__) */
