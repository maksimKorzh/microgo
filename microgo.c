#include <stdio.h>
#include <string.h>
#define F "                    \n"
#define O " ...................\n"
#define G F O O O O O O O O O O O O O O O O O O O F
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

int P(int q,int c){m=q;if(b[q]!='.'||q==k)return 0;b[q]=c;k=E; // set stone
for(int i=0;i<I;i++){if(b[i]<='.')continue;if((b[i]-'`')&(3-(c-'`'))){
C(i,3-(c-'`'));if(!e){if(r==1&&Y(q)==3-s)k=g[0];for(int j=0;j<r;j++)
b[g[j]]='.';}R();}}s=3-s;}

int search(int depth) { /* Recursively search fighting moves */
if (!depth) return 0; int bestScore = -10000; int u[100];
memset(u,0,100*sizeof(int));int y=0; for (int q=0;q<I;q++){
if(b[q]<=' '||b[q]=='.')continue;C(q,b[q]);if(e<3){for(int j=0;j<e;j++)
{int f=0;for(int z=0;z<y;z++)if(u[z]==l[j])f=1;if(!f)u[y++]=l[j];}}R();}
for (int i=0; i <y;i++)printf("urgent %d\n", u[i]);
  
  /*for (let sq of getUrgentMoves()) {
    for (let offset of [1, -1, size, -size])
      if (board[sq+offset] == OFFBOARD && depth == 1) continue;
    if (sq == ko) continue;
    let oldBoard = JSON.stringify(board);
    let oldSide = side;
    let oldKo = ko;
    if (!setStone(sq, side, false)) continue;
    let eval = -search(depth-1);
    if (eval > bestScore) {
      bestScore = eval;
      bestMove = sq;
    } board = JSON.parse(oldBoard);
    side = oldSide;
    ko = oldKo;
  };return bestScore;*/
}

void D(){setbuf(stdin,NULL);setbuf(stdout,NULL);char u[10000];while(1){ // GTP communication
memset(u,0,sizeof(u));fflush(stdout);if(!fgets(u,10000,stdin))continue;
if(u[0]=='\n')continue;if(strncmp(u,"name",4)==0)printf("= Micro Go\n");
if(strncmp(u,"version",7)==0)printf("= by Code Monkey King\n\n");
else if(strncmp(u,"protocol_version",16)==0)printf("= 1\n\n");
else if(strncmp(u,"showboard",9)==0)printf("= %s\n",b);
else if(strncmp(u,"clear_board",11)==0){strcpy(b,G);s=1,k=m=E;printf("=\n\n");}
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
  search(1);
  printf("%s %d\n", b,k);
}

int main() {
  //D();
  debug();
}
