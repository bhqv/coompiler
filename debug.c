#include <bits/types/stack_t.h>
#include <stdint.h>
#include <stdio.h>

#include "debug.h"
#include "chunk.h"

void disassembleChunk(Chunk *chunk, const char *name){
    printf("==%s==\n", name);
    
    for (int offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);

    }
}

static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

int disassembleInstruction(Chunk *chunk, int offset) {
    printf("%04d ", offset);

    uint8_t instrunction = chunk -> code[offset];
    switch (instrunction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instrunction);
            return offset + 1;
    }
}

