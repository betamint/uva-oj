#include<stdio.h>
#include<string.h>
#define MAX 100 + 5
#define WIDTH 60
int char_cmp(char* x, char* y);
int main() {
  int list_len;
  char names[MAX][WIDTH];
  int name_len_max;
  int columns;
  int rows;
  while(scanf("%d", &list_len) != EOF) {
    name_len_max = 0;
    
    int i;
    for(i = 0; i < list_len; i++) {
      scanf("%s", names[i]);
      int j = strlen(names[i]);
      if(j > name_len_max)
	name_len_max = j;
    }

    qsort(names, list_len, WIDTH * sizeof(char), char_cmp);
    columns = (WIDTH + 2)/(name_len_max + 2);
    if((list_len % columns) == 0)
      rows = list_len / columns;
    else
      rows = list_len / columns + 1;

    for(i = 0; i < 60; i++)
      printf("-");
    printf("\n");

    int j;
    for(i = 0; i < rows; i++) {
      int is_last_blank = (list_len%rows != 0)&&(i >= list_len%rows);
      for(j = 0; j < columns - is_last_blank; j++) {
	int index = j*rows + i;
	printf("%s", names[index]);
	int k;
	for(k = 0; k < name_len_max - strlen(names[index]) + 2; k++)
	  printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}
int char_cmp(char* x, char* y) {
  return strcmp(x, y);
}
