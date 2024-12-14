#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "errors.h"
#include <string.h>

void free_all_data(node_t *head);
int select_elems(node_t *head, const char *finder);

#endif
