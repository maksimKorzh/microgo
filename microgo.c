#include <stdio.h>
#include <string.h>
#define F "                    \n"
#define O " ...................\n"
#define G F O O O O O O O O O O O O O O O O O O O F

char *move[]={
  "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX",
  "XX", "A19","B19","C19","D19","E19","F19","G19","H19","J19","K19","L19","M19","N19","O19","P19","Q19","R19","S19","T19","XX",
  "XX", "A18","B18","C18","D18","E18","F18","G18","H18","J18","K18","L18","M18","N18","O18","P18","Q18","R18","S18","T18","XX",
  "XX", "A17","B17","C17","D17","E17","F17","G17","H17","J17","K17","L17","M17","N17","O17","P17","Q17","R17","S17","T17","XX",
  "XX", "A16","B16","C16","D16","E16","F16","G16","H16","J16","K16","L16","M16","N16","O16","P16","Q16","R16","S16","T16","XX",
  "XX", "A15","B15","C15","D15","E15","F15","G15","H15","J15","K15","L15","M15","N15","O15","P15","Q15","R15","S15","T15","XX",
  "XX", "A14","B14","C14","D14","E14","F14","G14","H14","J14","K14","L14","M14","N14","O14","P14","Q14","R14","S14","T14","XX",
  "XX", "A13","B13","C13","D13","E13","F13","G13","H13","J13","K13","L13","M13","N13","O13","P13","Q13","R13","S13","T13","XX",
  "XX", "A12","B12","C12","D12","E12","F12","G12","H12","J12","K12","L12","M12","N12","O12","P12","Q12","R12","S12","T12","XX",
  "XX", "A11","B11","C11","D11","E11","F11","G11","H11","J11","K11","L11","M11","N11","O11","P11","Q11","R11","S11","T11","XX",
  "XX", "A10","B10","C10","D10","E10","F10","G10","H10","J10","K10","L10","M10","N10","O10","P10","Q10","R10","S10","T10","XX",
  "XX", "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "J9", "K9", "L9", "M9", "N9", "O9", "P9", "Q9", "R9", "S9", "T9", "XX",
  "XX", "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "J8", "K8", "L8", "M8", "N8", "O8", "P8", "Q8", "R8", "S8", "T8", "XX",
  "XX", "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "J7", "K7", "L7", "M7", "N7", "O7", "P7", "Q7", "R7", "S7", "T7", "XX",
  "XX", "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "J6", "K6", "L6", "M6", "N6", "O6", "P6", "Q6", "R6", "S6", "T6", "XX",
  "XX", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "J5", "K5", "L5", "M5", "N5", "O5", "P5", "Q5", "R5", "S5", "T5", "XX",
  "XX", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "J4", "K4", "L4", "M4", "N4", "O4", "P4", "Q4", "R4", "S4", "T4", "XX",
  "XX", "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "J3", "K3", "L3", "M3", "N3", "O3", "P3", "Q3", "R3", "S3", "T3", "XX",
  "XX", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "J2", "K2", "L2", "M2", "N2", "O2", "P2", "Q2", "R2", "S2", "T2", "XX",
  "XX", "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "J1", "K1", "L1", "M1", "N1", "O1", "P1", "Q1", "R1", "S1", "T1", "XX",
  "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"
};

int I=441,S=21,E=0,B=1,W=2,M=4,L=8;char b[]=G;int s=1,k,m,r,e;
int g[360],l[720],n[]={1,-1,21,-21};

void C(int q, int c){int t=b[q]-'`';if(b[q]<=' ')return; // count
if(t>0&&(t&c)&&!(t&M)){b[q]|=M;g[r++]=q;for(int i=0;i<4;i++)
C(q+n[i],c);}else if(b[q]=='.'){b[q]=(t+50)|L+'`';l[e++]=q;}}

void R(){memset(g,0,360*sizeof(int));memset(l,0,720*sizeof(int)); // restore
r=0;e=0;for(int i=0;i<I;i++){if(b[i]>'.'){char t=(b[i]-'`')&3;
t+=t?'`':'.';b[i]=t;}}}

int Y(int q){int c=-1,o=-1;for(int i=0;i<4;i++){if(b[q+n[i]]<=' ') // in eye
continue;if(b[q+n[i]]=='.')return 0;if(c==-1){c=(b[q+n[i]]-'`')&3;
o=3-c;}else if(((b[q+n[i]]-'`')&3)==o)return 0;}return c;}

int P(int q,int c){if(b[q]!='.'||q==k)return 0;int _k=k;k=E; b[q]=c;// set stone
for(int i=0;i<I;i++){if(b[i]<='.')continue;if((b[i]-'`')&(3-(c-'`'))){
C(i,3-(c-'`'));if(!e){if(r==1&&Y(q)==3-s)k=g[0];for(int j=0;j<r;j++)
b[g[j]]='.';}R();}}

  C(q,c);
  int suicide = e ? 0:1;
  R();
  if (suicide) {
    b[q] = '.';
    k=_k;
    return 0;
  } 

s=3-s;return 1;}


int evaluate() {
  int eval = 0;
  int blackStones = 0;
  int whiteStones = 0;
  for (int q = 0; q < I; q++) {
    if(b[q]<=' '||b[q]=='.')continue;

    if (b[q]=='a') blackStones += 1;
    if (b[q]=='b') whiteStones += 1;
  } eval += (blackStones - whiteStones);
  return (s==B) ? eval : -eval;
}

int search(int depth) { /* Recursively search fighting moves */
if (!depth) return evaluate();
int bestScore = -10000; int u[100];
memset(u,0,100*sizeof(int));int y=0; for (int q=0;q<I;q++){
if(b[q]<=' '||b[q]=='.')continue;C(q,b[q]);if(e<3){for(int j=0;j<e;j++)
{int f=0;for(int z=0;z<y;z++)if(u[z]==l[j])f=1;if(!f)u[y++]=l[j];}}R();}
for (int q=0;q<y;q++){
  if (u[q]==k) continue;
  char _b[]=G;strcpy(_b,b);
  int _s=s;
  int _k=k;


  if (!P(u[q],s+'`')) continue;


  int eval = -search(depth-1);
  if (eval > bestScore) {
    bestScore=eval;
    m=u[q];
  }

  strcpy(b,_b);
  s=_s;
  k=_k;
}

  return bestScore;
}

void D(){setbuf(stdin,NULL);setbuf(stdout,NULL);char u[10000];while(1){ // GTP communication
memset(u,0,sizeof(u));fflush(stdout);if(!fgets(u,10000,stdin))continue;
if(u[0]=='\n')continue;if(strncmp(u,"name",4)==0)printf("= Micro Go\n");
if(strncmp(u,"version",7)==0)printf("= by Code Monkey King\n\n");
else if(strncmp(u,"protocol_version",16)==0)printf("= 1\n\n");
else if(strncmp(u,"showboard",9)==0)printf("= %s %d\n\n",b,s);
else if(strncmp(u,"clear_board",11)==0){strcpy(b,G);s=B,k=m=E;printf("=\n\n");}
else if(strncmp(u,"genmove",7)==0){
  s=(u[8]=='B')?B:W;
  m=0;
  //printf("generating move for side %d\n",s);
  int score = search(6);
  if (score != -10000) {
    P(m,s+'`');
    printf("= %s\n\n", move[m]);
    //printf("= %d %d\n\n", m,score);
  } else {
    for (int q=0;q<I;q++){
      if((b[q]-'`')==3-s) {
        for (int i=0;i<4;i++){
          if (b[q+n[i]]=='.') {
            int count = 0;
            for (int j=0;j<4;j++) if (b[q+n[i]+j]!='.')count++;
            //if (count>2)m=q+n[i];
            break;
          }
        }
      }
    }
    printf("= %s\n\n",move[m]);
    P(m,s+'`');
    //printf("= pass\n\n");
  }
}
else if(strncmp(u,"play",4)==0){int c=u[5]=='B'?'a':'b';int x=u[7]-'A'+1-(u[7]>'I'?1:0);
int y;sscanf(u,"play %*c %*c%d",&y);y=S-1-y;P(y*S+x,c);printf("=\n\n");}
else if(strncmp(u,"quit",4)==0)break;else printf("=\n\n");}}

void debug() {
  P(2*S+4,'a');
  P(2*S+5,'b');
  P(3*S+5,'a');
  P(3*S+4,'b');
  P(4*S+4,'a');
  P(4*S+5,'b');
  P(3*S+3,'a');
  P(3*S+6,'b');
  P(16*S+16,'a');
  P(3*S+4,'b');
  P(3*S+7,'a');
  P(16*S+4,'b');
  P(2*S+6,'a');
  P(16*S+3,'b');
  P(4*S+6,'a');
  P(16*S+2,'b');
  P(3*S+5,'a');
  printf("%s %d %d\n", b,k,s);
  int score = search(1);
  printf("score %d  bestMove %d\n", score,m);
  printf("%s %d %d\n", b,k,s);
}

int main() {
  D();
  //debug();
}
