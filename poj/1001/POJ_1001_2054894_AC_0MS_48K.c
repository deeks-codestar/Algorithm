// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include<stdio.h>
void main() {
  char s[7];
  int i, j = 1, n, m = 0, k, flag = -1;
  long int a[100] = {0};
  char st[395] = {'0'};
  a[0] = 1;
  while (scanf("%s %d", s, &n) != EOF) {
    for (i = 0; s[i]; i++);
    for (i--; i >= 0; i--) {
      if (s[i] == '.') {
        flag = (5 - i) * n;
        continue;
      } else {
        m += (s[i] - '0') * j;
        j *= 10;
      }
    }
    while (n--) {
      for (i = 0; i < 100; i++)
        a[i] *= m;
      for (i = 0; i < 100; i++) {
        a[i + 1] = a[i + 1] + (a[i] / 10000);
        a[i] = a[i] % 10000;
      }
    }
    for (i = 0, k = 0; i < 99; i++, k += 4) {
      st[k + 3] = a[i] / 1000 + '0';
      a[i] %= 1000;
      st[k + 2] = a[i] / 100 + '0';
      a[i] %= 100;
      st[k + 1] = a[i] / 10 + '0';
      a[i] %= 10;
      st[k] = a[i] + '0';
    }
    for (i = 395; i >= flag; i--) {
      if (st[i] != '0')
        break;
    }
    for (j = 0; j < flag; j++) {
      if (st[j] != '0')
        break;
    }
    if (i < j)
      printf("0\n");
    else {
      for (i; i >= j; i--) {
        if (i == flag - 1)
          printf(".");
        printf("%c", st[i]);
      }
      printf("\n");
    }
    for (i = 0; i < 100; i++)
      a[i] = 0;
    for (i = 0; i < 396; i++)
      st[i] = '\0';
    st[0] = '0';
    a[0] = 1;
    m = 0;
    j = 1;
    flag = -1;
  }
}