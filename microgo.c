#include <stdio.h>                                     // Standard input/output functions
#define F "                    \n"                     // Offboard line
#define O " ...................\n"                     // Empty line
#define G F O O O O O O O O O O O O O O O O O O O F    // Empty board
int I=441,S=21,E=0,B=1,W=2,M=4,L=8;                    // Square: size, width, empty, black, white, marker, liberties
char b[]=G;int s,k,m;int g[360],l[720];                // Board: position, side, ko, group, liberties



int main() {
  b[3*S+3]=B+'`';
  printf("%s", b);
}
