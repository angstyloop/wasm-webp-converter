# include <stdio.h>
# include <stdlib.h>
# include "emscripten.h"
# include "src/webp/encode.h"

# ifndef uint8_t
typedef unsigned char uint8_t;
# endif

EMSCRIPTEN_KEEPALIVE
int version() {
    return WebPGetEncoderVersion();
}

EMSCRIPTEN_KEEPALIVE
uint8_t* create_buffer(int width, int height) {
    return malloc(width * height * 4 * sizeof(uint8_t));
}

EMSCRIPTEN_KEEPALIVE
void free_buffer(uint8_t* p) {
    free(p);
}

// global
struct Result {
    int ptr;
    int size;
} result; 

EMSCRIPTEN_KEEPALIVE
void encode(uint8_t* img_in, int width, int height, float quality) {
    uint8_t* img_out;
    result.size = WebPEncodeRGBA(img_in, width, height, width * 4, quality, &img_out); // size in bytes
    result.ptr = (int)img_out;
}

EMSCRIPTEN_KEEPALIVE
void free_result(uint8_t* result) {
    WebPFree(result);
}

EMSCRIPTEN_KEEPALIVE
int get_result_ptr() {
    return result.ptr;
}

EMSCRIPTEN_KEEPALIVE
int get_result_size() {
    return result.size;
}
