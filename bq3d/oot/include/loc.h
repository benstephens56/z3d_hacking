#ifndef LOC_H
#define LOC_H

#include <stdint.h>

typedef struct  {
	uint32_t index;
} entry_t;

void init(void);

extern const entry_t ref[];
extern entry_t loc[];

extern const int loc_len;
extern const int seed;

#endif //LOC_H