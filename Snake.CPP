#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
#include"Score.cpp"
#define BGI "c:\\turboc3\\bgi";


randmozie();
int fx= 50 + rand() % 600 , fy=30 + rand() % 400;
class snake : public score
{
private:
  int pos[2][50];
  int size;
  int score;
public:
  char keys[4],in;
  void eating(int);
  void move();
  void display_snake(int,int);
  void init_obj(int);
  int out(int);
  int xye(int,int,int);
  void ai();
  void aii();
  void aik();
  void ail();
  void aij();
  int check(char);

};
int snake::xye(int x,int y,int n)
{
 if(x<=pos[0][n]+4&&x>=pos[0][n]-4&&y<=pos[1][n]+4&&y>=pos[1][n]-4)
  return 1;
else
 return 0;
}

int snake::check(char a)
{
 if(a=='l')
 {
   for(int i=1;i<size;i++)
   {
    if(xye(pos[0][0]+5,pos[1][0],i))
    {
     return 0;
   }
 }
}
else if(a=='j')
{
 for(int i=1;i<size;i++)
 {
  if(xye(pos[0][0]-5,pos[1][0],i))
  {
   return 0;
 }
}
}
else if(a=='k')
{
 for(int i=1;i<size;i++)
 {
  if(xye(pos[0][0],pos[1][0]+5,i))
  {
   return 0;
 }
}
}
else if(a=='i')
{
 for(int i=1;i<size;i++)
 {
  if(xye(pos[0][0],pos[1][0]-5,i))
  {
   return 0;
 }
}
}
return 1;
}

void snake::ail()
{
 if(pos[0][0]<=fx-3 && check('l'))
  in='l';
else if(pos[0][0]>=fx-3 && pos[0][0]<=fx+3)
{
  if(fy+3<pos[1][0] && check('i'))
   in='i';
 else if(fy-3>pos[1][0] && check('k'))
   in='k';
}
else if(check('i'))
  in='i';
else if(check('k'))
  in='k';
}
void snake::aij()
{
  if(pos[0][0]>=fx+3 && check('j'))
    in='j';
  else if(pos[0][0]>=fx-3 && pos[0][0]<=fx+3)
  {
    if(fy+3<pos[1][0] && check('i'))
     in='i';
   else if(fy-3>pos[1][0] && check('k'))
     in='k';
 }
 else if(check('i'))
  in='i';
else if(check('k'))
  in='k';
}
void snake::aik()
{
  if(pos[0][0]>=fx+3 && check('j'))
    in='j';
  else if(pos[0][0]<=fx-3 && check('l'))
    in='l';
  else if(pos[0][0]>=fx-3 && pos[0][0]<=fx+3)
  {
    if(check('k'))
     in='k';
   else if(check('j'))
     in='j';
   else
     in='l';
 }
 else if(check('j'))
   in='j';
 else
   in='l';
}
void snake::aii()
{
 if(pos[0][0]>=fx+3 && check('j'))
  in='j';
else if(pos[0][0]<=fx-3 && check('l'))
  in='l';
else if(pos[0][0]>=fx-3 && pos[0][0]<=fx+3)
{
  if(check('i'))
   in='i';
 else if(check('j'))
   in='j';
 else
   in='l';
}
else if(check('j'))
 in='j';
else
 in='l';
}

void snake::ai()
{
 if(in=='l')
 {
  ail();
}
else if(in=='j')
{
 aij();
}
else if(in=='i')
{
 aii();
}
else if(in=='k')
{
 aik();
}
}
void food()
{
  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,YELLOW);
  pieslice(fx,fy,0,360,3);
}

void snake::eating(int nop)
{
  if (pos[0][0]>=fx-3 && pos[0][0]<=fx+3 && pos[1][0]>=fy-3 && pos[1][0]<=fy+3)
  {
    sound(310);
    delay(50);
    nosound();
    randomize();
    fx = 30 + rand() % 600;
    fy = 30 + rand() % 400;
    size++;
    change(1);
    if(nop==1)
    {
      h_a();
      tot(1);
    }
  }
}


void snake::move()
{
  int x2, y2, x1, y1;

  x1 = pos[0][0];
  y1 = pos[1][0];

  for (int i = 1; i<size; i++)
  {
    x2 = pos[0][i];
    y2 = pos[1][i];
    pos[0][i] = x1;
    pos[1][i] = y1;
    x1 = x2;
    y1 = y2;
  }
  if (in == keys[3])
  {
    pos[0][0] += 5;
    if(pos[0][0]>=627)
      pos[0][0]=15;
  }
  if (in == keys[2])
  {
    pos[1][0] += 5;
    if(pos[1][0]>=455)
      pos[1][0]=18;

  }
  if (in == keys[0])
  {
    pos[1][0] -= 5;
    if(pos[1][0]<=18)
      pos[1][0]=455;

  }
  if (in == keys[1])
  {
    pos[0][0] -= 5;
    if(pos[0][0]<=10)
      pos[0][0]=627;

  }
}

void display_border(int j,int oi)
{
  int k;

  if(oi==15)
    k=RED;
  else
    k=j;

  setcolor(k);
  setfillstyle(SOLID_FILL,k);

  bar(10,10,5,465);
  bar(630,10,635,465);
  bar(5,10,635,17);
  bar(10,465,635,458);
}

void snake::display_snake(int c,int z)
{
  for (int i = 0; i < size; i++)
  {
    int x, y,color;

    x = pos[0][i];
    y = pos[1][i];

    if(z==0)
      color=RED;
    if(z==1)
      color=BLUE;
    if(z==3)
      c=color=BLACK;

    if(i!=0)
    {
      setcolor(c);
      setfillstyle(SOLID_FILL,c);
    }
    else
    {
      setcolor(color);
      setfillstyle(SOLID_FILL,color);
    }
    pieslice(x,y,0,360,3);
  }
}

int input(snake sam[],int n,int x=0)
{
 if(x)
 {
  sam[1].ai();
}
char q,G;
if (kbhit())
{
  q = getch();
  if(q==' ')
  {
    setcolor(YELLOW);
    outtextxy(getmaxx()/2-110,getmaxy()/2-25,"GAME PAUSED PRESS space TO START");
    outtextxy(getmaxx()/2-60,getmaxy()/2,"PRESS esc TO EXIT");
    while(1)
    {
      if(kbhit())
        G=getch();
      if(G==' ')
        break;
      if(G==27)
        return 0;
    }
  }
  else
  {
    for(int i=0; i<(x==0?n:1); i++)
    {
      if (q == sam[i].keys[0] && sam[i].in!=sam[i].keys[2])
        sam[i].in = q;
      else if(q == sam[i].keys[1] && sam[i].in!=sam[i].keys[3])
        sam[i].in=q;
      else if( q == sam[i].keys[2] && sam[i].in!=sam[i].keys[0])
        sam[i].in=q;
      else if( q == sam[i].keys[3] && sam[i].in!=sam[i].keys[1])
        sam[i].in=q;
    }
  }
}
if(q=='e')
  return 1;
else
  return 1;
}

int snake::out(int sno)
{
  for(int i=0; i<size; i++)
  {
    for(int j=i+1; j<size; j++)
    {
      if(pos[1][i]==pos[1][j])
      {
        if(pos[0][i]==pos[0][j])
        {
          return sno+1;
        }
      }
    }
  }
  return 0;
}
void snake::init_obj(int j)
{
  if(j==0)
  {
    keys[0]=72;
    keys[1]=75;
    keys[2]=80;
    keys[3]=77;
    in=77;
    pos[0][0] = 50;
    pos[1][0] = 49;
    pos[0][1] = 49;
    pos[1][1] = 49;
    pos[0][2]=100;
    pos[1][2]=100;
  }
  else if(j==1)
  {
    keys[0]='i';
    keys[1]='j';
    keys[2]='k';
    keys[3]='l';
    in='l';
    pos[0][0] = 50;
    pos[1][0] = 60;
    pos[0][1] = 49;
    pos[1][1] = 60;
    pos[0][2]=100;
    pos[1][2]=100;
  }
  size = 2;
  s=0;
  total=0;
}


int snake_menu()
{
  _setcursortype(_NOCURSOR);
  int y=10,ch;
  char k,m;
  textcolor(WHITE);
  while(1)
  {
    gotoxy(32,10);
    cout<<"1.SINGLE PLAYER";
    gotoxy(32,11);
    cout<<"2.DUAL PLAYER";
    gotoxy(32,12);
    cout<<"3.AI";
    gotoxy(32,13);
    cout<<"3.DIFFICULTY";
    gotoxy(32,14);
    cout<<"4.SCOREBOARD";
    gotoxy(32,15);
    cout<<"5.EXIT GAME";
    gotoxy(30,y);
    cout<<"->";
    if(kbhit())
    {
      k=getch();
      if(k==' '||k==13)
      {
        sound(950);
        delay(20);
        nosound();
        if(y==10)
          ch=1;
        if(y==11)
          ch=2;
        if(y==12)
          ch=3;
        if(y==13)
          ch=4;
        if(y==14)
          ch=5;
        if(y==15)
          ch=6;
        return ch;
      }
      if(k==72)
      {
        sound(900);
        delay(10);
        nosound();
        if(y>10)
          y--;
        else
          y=14;
        clrscr();
      }
      if(k==80)
      {
        sound(900);
        delay(10);
        nosound();
        if(y<15)
          y++;
        else
          y=10;
        clrscr();
      }
    }
  }
}

void text3D(int x, int y, int depth, int bgcolor, int fgcolor,int font,int size, char *caption)
{
    int i;
    setcolor(bgcolor);
    settextstyle(font,HORIZ_DIR,size);
    for(i=0; i<depth; i++)
  outtextxy(x+i,y+i,caption);
    setcolor(fgcolor);
    outtextxy(x+i,y+i,caption);

}

