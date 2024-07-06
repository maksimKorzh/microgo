#include <stdio.h>
#include <string.h>
#define F "                    \n"
#define O " ...................\n"
#define G F O O O O O O O O O O O O O O O O O O O F
int d[]={88,340,352,100,69,129,363,297,311,
371,143,77,213,227,73,367,215,225,115,325,220};                                   // Opening moves
int I=441,S=21,E=0,B=1,W=2,M=4,L=8;char b[]=G;
int s=1,k,m,r,e;int g[360],l[720];int n[]={-1,-21,21,1};
void C(int q,int c){int t=b[q]-'`';if(b[q]<=' ')return;                           // Count liberties
if(t>0&&(t&c)&&!(t&M)){b[q]|=M;g[r++]=q;for(int i=0;i<4;i++)
C(q+n[i],c);}else if(b[q]=='.'){b[q]=(t+50)|L+'`';l[e++]=q;}}
void R(){memset(g,0,360*sizeof(int));memset(l,0,720*sizeof(int));                 // Restore board after
r=0;e=0;for(int i=0;i<I;i++){if(b[i]>'.'){char t=(b[i]-'`')&3;
t+=t?'`':'.';b[i]=t;}}}
int Y(int q){int c=-1,o=-1;for(int i=0;i<4;i++){if(b[q+n[i]]<=' ')                // Is square in diamond shape?
continue;if(b[q+n[i]]=='.')return 0;if(c==-1){c=(b[q+n[i]]-'`')&3;
o=3-c;}else if(((b[q+n[i]]-'`')&3)==o)return 0;}return c;}
int P(int q,int c){if(b[q]!='.'||q==k)return 0;int _k=k;k=E; b[q]=c;              // Put stone on board, handle captures
for(int i=0;i<I;i++){if(b[i]<='.')continue;if((b[i]-'`')&(3-(c-'`'))){
C(i,3-(c-'`'));if(!e){if(r==1&&Y(q)==3-s)k=g[0];for(int j=0;j<r;j++)
b[g[j]]='.';}R();}}C(q,c-'`');int suicide=e?0:1;R();if(suicide){b[q]='.';
k=_k;return 0;}s=3-s;return 1;}
int X(int x){if(!x){int v=0,a=0,w=0;for(int q=0;q<I;q++){                         // Recursively search fighting moves at depth 6
if(b[q]<=' '||b[q]=='.')continue;if(b[q]=='a')a+=1;if(b[q]=='b')
w+=1;}v+=(a-w);return(s==B)?v:-v;};int h=-10000;int u[100];
memset(u,0,100*sizeof(int));int y=0;for(int q=0;q<I;q++){
if(b[q]<=' '||b[q]=='.')continue;C(q,b[q]-'`');if(e<3){for(int j=0;j<e;j++)
{int f=0;for(int z=0;z<y;z++)if(u[z]==l[j])f=1;if(!f)u[y++]=l[j];}}R();}
for(int q=0;q<(y<7?y:6);q++){if(u[q]==k)continue;char _b[]=G;strcpy(_b,b);
int _s=s;int _k=k;if(!P(u[q],s+'`'))continue;int p=-X(x-1);if(p>h){h=p;
if(x==6)m=u[q];}strcpy(b,_b);s=_s;k=_k;}return h;}
void T(int z){for(int q=0;q<21;q++){if(b[d[q]]=='.'&&!(Y(d[q]))){m=d[q];          // Play away if no forcing moves
return;}}int i=100;for(int q=0;q<I;q++){if((b[q]-'`')==3-s){int a=0;
C(q,b[q]-'`');if(e<i){i=e;a=l[0];}else if(e)a=l[z?(e-1):0];R();int c=0;
for(int j=0;j<4;j++)if(b[a+n[j]]=='.')c++;if(a&&c&&a!=k)m=a;}}}
void D(){setbuf(stdin,NULL);setbuf(stdout,NULL);char u[10000];while(1){           // GTP communication
memset(u,0,sizeof(u));fflush(stdout);if(!fgets(u,10000,stdin))continue;
if(u[0]=='\n')continue;if(strncmp(u,"name",4)==0)printf("= Micro Go\n");
if(strncmp(u,"version",7)==0)printf("= by Code Monkey King\n\n");
else if(strncmp(u,"protocol_version",16)==0)printf("= 1\n\n");
else if(strncmp(u,"showboard",9)==0)printf("= %s %d %d\n\n",b,s,k);
else if(strncmp(u,"clear_board",11)==0){strcpy(b,G);s=B,k=m=E;printf("=\n\n");}
else if(strncmp(u,"genmove",7)==0){s=(u[8]=='B')?B:W;m=0;int p=X(6);
if(m)P(m,s+'`');else{T(1);if(!m)T(0);}char c[20];int y=(m/21)-1,x=(m%21)-1;
c[0]='A'+x+(x>=8);sprintf(c+1,"%d",19-y);c[3]='\0';c[0]='A'+x+(x>=8);
if(!m)printf("= pass\n\n");else {P(m,s+'`');printf("= %s\n\n",c);}}
else if(strncmp(u,"play",4)==0){int c=u[5]=='B'?'a':'b';int x=u[7]-'A'+1-(u[7]>'I'?1:0);
int y;sscanf(u,"play %*c %*c%d",&y);y=S-1-y;P(y*S+x,c);printf("=\n\n");}
else if(strncmp(u,"quit",4)==0)break;else printf("=\n\n");}}int main(){D();}
