//
//  read.c
//  Text Adventure Game
//
//  Created by Johnny Wellington dos Santos on 6/1/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#include "story.h"


void open_story(char *filename){
    story.file_pointer= fopen(filename, "r");
    if(story.file_pointer == NULL){
        printf("Ops, I can't read your history.\n"
               "Are you sure it's ok with the file?\n");
        exit(1);
    }
};

//int get_line(char **line, FILE *fp)
//{
//	int tam = 2;
//	int start = 0;
//
//	if ((*line = (char *)malloc(tam)) == NULL) {
//		fprintf(stderr, "Erro: malloc line\n");
//		exit(1);
//	}
//	while (fgets(*line + start, tam, fp) != NULL) {
//		if (strchr(*line, &#9; \n&#9;) != NULL)
//			return 1;
//		start += tam - 1;
//		*line = (char *)realloc(*line, start + 1 + tam);
//	}
//	return -1;
//}


void print_line_char_by_char(char *line){
	int index = 0;
	int	delay = 50;
	while (line[index] != NULL){
		putchar(line[index]);
		#ifdef _WIN32
		Sleep(delay);
		#else
		usleep(delay * 1000);  /* sleep for 100 milliSeconds */
		#endif
		index++;
	}
}


void print_prompt(){
	int delay = 100;
	printf("> \r");	
	#ifdef _WIN32
	Sleep(delay);
	#else
	usleep(delay * 1000);  /* sleep for 100 milliSeconds */
	#endif

}


void load_scene(char *scene_identifier){
	char buffer[SCENE_DESCRIPTION_MAX_COLS];
	char choice[SCENE_OPTION_IDENTIFIER_LENGTH] = { NULL };
    
	// set position to the begining of the file
    fseek(story.file_pointer, 0, SEEK_SET);
    while(!feof(story.file_pointer)){
		story.current_line = fgets(buffer, sizeof(buffer), story.file_pointer);
		buffer[strcspn(buffer, "\r\n")] = 0; // Removes the new line character
		if (strcmp(buffer, scene_identifier) == 0){
			
			// load scene description
			while (strcmp(story.current_description_line = fgets(buffer, sizeof(buffer), story.file_pointer), "\n") != 0)
				print_line_char_by_char(story.current_description_line);

			for (int i = 0; i < SCENE_MAX_OPTIONS; i++){
				while (strcmp(story.scene.options[i].identifier = fgets(buffer, sizeof(buffer), story.file_pointer), "\n") != 0){
					printf("%s", story.scene.options[i].identifier);
				}
				break;
				// TODO: Handle options
					
			}
        }
        
    }
};
