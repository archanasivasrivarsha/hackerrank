#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41
typedef struct {
    int length;
    int width;
    int height;
} box;

// Function to check if the box can fit in the tunnel
int is_lower_than_max_height(box b) {
    return b.height < MAX_HEIGHT;
}

// Function to compute the volume of a box
int get_volume(box b) {
    return b.length * b.width * b.height;
}
int main()
