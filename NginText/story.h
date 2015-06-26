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
//#include 'slre.h'

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

typedef struct option_t {
    char *identifier;
    char *target;
};


typedef struct scene_t {
    char *identifier;
    struct option_t options[SCENE_MAX_OPTIONS];
	char *selected_option;    
	char *description;
};

typedef struct story_t {
    FILE *file_pointer;
    struct scene_t scene;
	char *current_line;
    char *previews_scene_identifier;
};

// const char *scene_identifier_regex = "^@[a-zA-Z0-9_]+$";

// Defines a global story structure
struct story_t story;


void open_story();
void load_scene();

#endif /* defined(__Text_Adventure_Game__read__) */
