#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

static Dnode* AllocDnode() {
    return calloc(1, sizeof(Dnode));
}

