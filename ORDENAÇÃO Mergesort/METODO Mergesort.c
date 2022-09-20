#include <stdio.h>
#include <stdlib.h>

void ordem(int *v, int n);
void ordenar(int *v, int *c, int i, int f);
void crescente(int *v, int *c, int i, int m, int f);

int main (void) {
  int i;
  int v[8] = { 2, 0, 0, 2, 3, 3, 6, 2 };
  printf("Aluno: Jeová Victor RA: 20023362-5\n\n\n");
  printf("\nquantidade de vendas desordenadas\n");
  for(i=0;i<8;i++){
    printf("| %d ", v[i]);
  }
  printf("\n\nvendas por barraca :\n");
    printf("1° : %d\n", v[0]);
    printf("2° : %d\n", v[1]);
    printf("3° : %d\n", v[2]);
    printf("4° : %d\n", v[3]);
    printf("5° : %d\n", v[4]);
    printf("6° : %d\n", v[5]);
    printf("7° : %d\n", v[6]);
    printf("8° : %d\n", v[7]);;

  printf("\nquantidade de vendas ordenadas \n");
  ordem(v, 8);

  for (i = 0; i < 8; i++) printf("| %d ", v[i]);
  printf("\n\nvendas por barraca de maneira ordenada :\n");
    printf("1° : %d\n", v[0]);
    printf("2° : %d\n", v[1]);
    printf("3° : %d\n", v[2]);
    printf("4° : %d\n", v[3]);
    printf("5° : %d\n", v[4]);
    printf("6° : %d\n", v[5]);
    printf("7° : %d\n", v[6]);
    printf("8° : %d\n", v[7]);;
  putchar('\n');

  return 0;
}

void ordem(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  ordenar(v, c, 0, n - 1);
  free(c);
}

void ordenar(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  ordenar(v, c, i, m);
  ordenar(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;

  crescente(v, c, i, m, f);
}


void crescente(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}