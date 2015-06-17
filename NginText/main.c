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
//    if(argc < 2){
//        printf("Eu preciso de um arquivo .story para ler. Sem ele não sei o "
//               "que fazer. :/");
//        exit(0);
//    }
    char story_path[256] = "/Users/johnny/Workspace/C/NginText/stories/prototype.story";
//    printf("Please inform the path to the story you want to play:\n> " );
    open_story(story_path);
    load_scene("@Inicio");
    printf("%s", story.current_scene_identifier);
    exit(0);
}