#include <stdio.h>                                     // Standard input/output functions
#include <string.h>                                    // String manipulation
#define F "                    \n"                     // Offboard line
#define O " ...................\n"                     // Empty line
#define G F O O O O O O O O O O O O O O O O O O O F    // Empty board
int I=441,S=21,E=0,B=1,W=2,M=4,L=8;                    // Square: size, width, empty, black, white, marker, liberties
char b[]=G;int s,k,m,r,e;int g[360],l[720];            // Board: position, side, ko, counters, group, liberties
int n[]={1,-1,21,-21};                                 // Neighbor offsets
void C(int s, int c) {                                 // COUNT LIBERTIES & STONES IN GROUP (args: square, color)
  int t=b[s]-'`';                                      // Decode stone
  if (b[s]<=' ') return;                               // Stop if hit board edge
  if (t>0&&(t&c)&&!(t&M)) {                            // When hit a stone of a given color, not marked yet
    b[s]|=M; g[r++]=s;                                 // Mark stone, add stone to group list
    for (int i=0;i<4;i++)C(s+n[i],c);                  // Recursively find all stones and liberties in group
  } else if (t<0) {                                    // When hit an empty square
    b[s]=(t+50)|L+'`';l[e++]=s;                        // Mark liberty, add liberty to liberty list
  }
}
void R(){                                              // Clear markers
  memset(g, 0, 360*sizeof(int));r=0;                   // Reset group list
  memset(l, 0, 720*sizeof(int));e=0;                   // Reset liberty list
  for (int i=0;i<I;i++) {                              // Loop over board squares
    if (b[i]>'.') {                                    // Skip offboard squares
      char t = (b[i]-'`')&3;                           // Strip markers
      t += t?'`':'.'; b[i]=t;                          // Restore board
    }
  }
}
int main() {
  b[1*S+3]=B+'`';
  b[2*S+3]=B+'`';
  b[3*S+3]=B+'`';
  printf("%s", b);
  C(3*S+3, B);
  printf("%s", b);
  //for (int i=0; i < 20; i++) printf("%d %d\n", g[i], l[i]);
  R();
  printf("%s", b);
}
