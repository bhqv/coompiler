#ifndef coom_object_h
#define coom_object_h

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)

#define IS_STRING(value) isObjectType(value, OBJ_STRING)

#define AS_STRING(value) ((ObjString*)AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString*)AS_OBJ(balue))->chars)

typedef enum {
    OBJ_STRING
} ObjType;

struct Obj {
    ObjType type;
};

typedef struct {
    Obj obj;
    int length;
    char* chars;
} ObjString;


// struct ObjString {
//     Obj obj;
//     int length;
//     char* chars;
// };

ObjString* copyString(const char* chars, int length);
void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif
