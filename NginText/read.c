//
//  read.c
//  Text Adventure Game
//
//  Created by Johnny Wellington dos Santos on 6/1/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#include "read.h"

FILE *file_pointer;

FILE *open_story(char *filename){
    file_pointer = fopen(filename, "r");
    if(file_pointer == NULL){
        printf("Ops, não consigo ler a sua história.\n"
               "Será que está tudo certo com o formato do arquivo?\n");
        exit(1);
    }
    else{
        printf("Tudo certo com a abertura do arquivo, mas eu ainda não sei o "
               "que fazer com ele. Por isso vou fecha-lo :/");
        return file_pointer;
    }
};
