//
//  monster.c
//  NginText
//
//  Created by Johnny Wellington dos Santos on 6/10/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#include "monster.h"


//struct monster {
//    char name[20];
//    int power;
//    int health;
//};

struct monster list[5];





struct monster *return_monsters(){
    struct monster m1;
    strcpy(m1.name, "Capiroto");
    list[0] = m1;
    return list;
}