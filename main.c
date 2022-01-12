#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_SIZE (16 * 1024 * 1024)

int main(int argc, char **argv){
  if (argc < 2) {
    printf("Usage: %s <png file> \n", argv[0]);
    return 1;
  }
  char *buf = (char *)malloc(MAX_MEMORY_SIZE);
  if (!buf) {
    fprintf(stderr, "Couldn't allocate memory\n");
    return 1;
  }
  FILE *png_file = fopen(argv[1], "r");

  if (!png_file){
    perror("fopen");
    free(buf);
    return 1;
  }
  
  int size = fread(buf, 1, MAX_MEMORY_SIZE, png_file);
  printf("%d", size);
  fclose(png_file);
  free(buf);

  return 0;
}
