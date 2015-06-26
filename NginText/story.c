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

// Read a file until reach the c character
// then save it to the line variable
int read_story_until(char **line, FILE *fp, char c)
{
	int tam = 2;
	int start = 0;

	if ((*line = (char *)malloc(tam)) == NULL) {
		fprintf(stderr, "Erro: malloc line\n");
		exit(1);
	}
	while (fgets(*line + start, tam, story.file_pointer) != NULL) {
		if (strchr(*line, c) != NULL)
			return 1;
		start += tam - 1;
		*line = (char *)realloc(*line, start + 1 + tam);
	}
	return -1;
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


// Finds a scene and returns a pointer to it.
int find_scene(char *scene_identifier){
	//set position to the begining of the file
	fseek(story.file_pointer, 0, SEEK_SET);
	// while doesn't reach the end of file
	while (!feof(story.file_pointer)){
		read_story_until(&story.current_line, story.file_pointer, '\n');
		story.current_line[strcspn(story.current_line, "\r\n")] = 0; // Removes the new line character
		if (strcmp(story.current_line, scene_identifier) == 0){
			// pass the referece to the story
			story.scene.identifier = story.current_line;
			return 0;
		}
	}
	return 1;
}

// Prints the scene description
void print_scene_description(){
	int	delay = 40;
	int index = 0;
	read_story_until(&story.scene.description, story.file_pointer, '{');
	while (story.scene.description[index] != NULL){
		putchar(story.scene.description[index]);
#ifdef _WIN32
		Sleep(delay);
#else
		usleep(delay * 1000);  /* sleep for 100 milliSeconds */
#endif
		index++;
	}
}

int load_options(){
	char *buffer = NULL;
	
	read_story_until(&buffer, &story.file_pointer, '\n');
	buffer[strcspn(buffer, "\r\n")] = 0; // Removes the new line character
	int options_number = buffer[0] - '0'; // Converts char '4' to int 4
	for (int i = 0; i < options_number; i++){
		char target[SCENE_IDENTIFIER_LENGTH] = "@";
		read_story_until(&story.scene.options[i].identifier, &story.file_pointer, '|');
		story.scene.options[i].identifier[strcspn(story.scene.options[i].identifier, "|")] = 0;
		read_story_until(&story.scene.options[i].target, &story.file_pointer, '\n');
		story.scene.options[i].target[strcspn(story.scene.options[i].target, "\n")] = 0;
		strcat(target, story.scene.options[i].target);
		strcpy(story.scene.options[i].target, target);
		puts(story.scene.options[i].identifier);
	}
	return options_number;
}

void load_scene(char *scene_identifier){
	char option[SCENE_OPTION_IDENTIFIER_LENGTH];
	
	int options_number;

	//set position to the begining of the file
	fseek(story.file_pointer, 0, SEEK_SET);
	if (find_scene(scene_identifier, &story.file_pointer) == 0){
		print_scene_description();
		options_number = load_options();

		printf("> ");
		gets(option);
		for (int i = 0; i < options_number; i++){
			if (strcmp(story.scene.options[i].identifier, option) == 0){
				load_scene(story.scene.options[i].target);
			}
		}
	}
 
};
