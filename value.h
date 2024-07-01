#ifndef clox_value_h 
#define vlox_value_h 
#include "common.h"

typedef double Value;

typedef struct{
    int count; 
    int capacity;
    Value* values;  

} ValueArray; 

void initValueArray(ValueArray* array); 
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);

#endif