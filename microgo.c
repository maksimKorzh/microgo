#include <stdio.h>                                     // Standard input/output functions
#include <string.h>                                    // String manipulation
#define F "                    \n"                     // Offboard line
#define O " ...................\n"                     // Empty line
#define G F O O O O O O O O O O O O O O O O O O O F    // Empty board
int I=441,S=21,E=0,B=1,W=2,M=4,L=8;                    // Square: size, width, empty, black, white, marker, liberties
char b[]=G;int s,k,m,r,e;int g[360],l[720];            // Board: position, side, ko, move, counters, group, liberties
int n[]={1,-1,21,-21};                                 // Neighbor offsets
void C(int q, int c) {                                 // COUNT LIBERTIES & STONES IN GROUP (args: square, color)
  int t=b[q]-'`';                                      // Decode stone
  if (b[q]<=' ') return;                               // Stop if hit board edge
  if (t>0&&(t&c)&&!(t&M)) {                            // When hit a stone of a given color, not marked yet
    b[q]|=M; g[r++]=s;                                 // Mark stone, add stone to group list
    for (int i=0;i<4;i++)C(q+n[i],c);                  // Recursively find all stones and liberties in group
  } else if (t<0) {                                    // When hit an empty square
    b[q]=(t+50)|L+'`';l[e++]=q;                        // Mark liberty, add liberty to liberty list
  }
}
void R(){                                              // CLEAR MARKERS
  memset(g, 0, 360*sizeof(int));r=0;                   // Reset group list
  memset(l, 0, 720*sizeof(int));e=0;                   // Reset liberty list
  for (int i=0;i<I;i++) {                              // Loop over board squares
    if (b[i]>'.') {                                    // Skip offboard squares
      char t = (b[i]-'`')&3;                           // Strip markers
      t += t?'`':'.'; b[i]=t;                          // Restore board
    }
  }
}
int P(int q,int c) {                                   // SET STONE (args: square, color)
  m=q;                                                 // Store move
  if (b[q]!='.'||q==k) return 0;                       // Don't play if square is occupied or ko
  b[q]=c;                                              // Put stone on board
  if (b[q]&c) {
    C(q,c);
    if(!e) {
      //if (e==1&& inEye(m)==3-s) k=l[0];
      for (int i=0;i<r;i++) b[g[i]]='.';               // Remove captured stones
    }
    R();
  }
}


void gtp()
{
  #define INPUT_BUFFER 10000
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  char input[INPUT_BUFFER];
  while (1) {
    memset(input, 0, sizeof(input));
    fflush(stdout);
    if (!fgets(input, INPUT_BUFFER, stdin)) continue;
    if (input[0] == '\n') continue;
    if (strncmp(input, "isready", 7) == 0) printf("readyok\n");
    else if (strncmp(input, "position", 8) == 0) printf("parsed position\n");
    else if (strncmp(input, "quit", 4) == 0) break;
    else printf("=\n");
  }
}

void debug() {
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

int main() {
  gtp();
  //debug();
}