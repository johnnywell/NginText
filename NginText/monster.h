//
//  monster.h
//  NginText
//
//  Created by Johnny Wellington dos Santos on 6/10/15.
//  Copyright (c) 2015 Johnny Wellington dos Santos. All rights reserved.
//

#ifndef __NginText__monster__
#define __NginText__monster__

#include <stdio.h>
#include <string.h>

struct monster {
    char name[20];
    int power;
    int health;
};

struct monster *return_monsters();

#endif /* defined(__NginText__monster__) */
