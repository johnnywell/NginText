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

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


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
#define SCENE_DESCRIPTION_MAX_LINES 256
#define SCENE_DESCRIPTION_MAX_COLS 256

// ------ Structures definitions ------

typedef struct scene_option {
    char *identifier;
    char target[SCENE_IDENTIFIER_LENGTH];
};


typedef struct new_scene {
    char identifier[SCENE_IDENTIFIER_LENGTH];
    char description[SCENE_DESCRIPTION_MAX_LINES][SCENE_DESCRIPTION_MAX_COLS];
    struct scene_option options[SCENE_MAX_OPTIONS];
	char *selected_option;
    
};

typedef struct new_story {
    FILE *file_pointer;
    struct new_scene scene;
    long previews_position_in_file;
    long position_in_file;
    char current_char;
	char *current_line;
    char *previews_scene_identifier;
	char *current_description_line;
};

// const char *scene_identifier_regex = "^@[a-zA-Z0-9_]+$";

// Defines a global story structure
struct new_story story;


void open_story();
void load_scene();

#endif /* defined(__Text_Adventure_Game__read__) */
