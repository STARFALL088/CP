#include <stdio.h>
#include <string.h>
char *line;
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", line);
    printf("%d %d\n", sizeof(line), strlen(line));
  }
}