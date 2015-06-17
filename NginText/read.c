////
////  read.c
////  Text Adventure Game
////
////  Created by Johnny Wellington dos Santos on 6/1/15.
////  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
////
//
//#include "read.h"
//
//
//void open_story(char *filename){
//    story.file_pointer= fopen(filename, "r");
//    if(story.file_pointer == NULL){
//        printf("Ops, I can't read your history.\n"
//               "Are you sure it's ok with the file?\n");
//        exit(1);
//    }
//    else{
//        printf("The file is fine, and it's open "
//               "I'm returning a pointer to the file to whom asked me.");
//    }
//};
//
//
//void load_scene(char *scene_identifier){
//    char *current_identifier_pointer;
//    char buffer[SCENE_IDENTIFIER_LENGTH];
//    
//    fseek(story.file_pointer, 0, SEEK_SET);
//    while(!feof(story.file_pointer)){
//        story.previews_position_in_file = ftell(story.file_pointer);
//        if((story.current_char = fgetc(story.file_pointer)) == SCENE_IDENTIFIER){
//            fseek(story.file_pointer, story.previews_position_in_file, SEEK_SET);
//            current_identifier_pointer = fgets(
//                buffer,
//                SCENE_IDENTIFIER_LENGTH,
//                story.file_pointer
//            );
//            story.current_scene_identifier[strcspn(buffer, "\r\n")] = 0;
//        }
//        
//    }
//};
