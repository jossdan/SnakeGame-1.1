#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<string.h>
#include<stdio.h>

typedef char string[30];
randmozie();
int fx= 50 + rand() % 600 , fy=30 + rand() % 400;

struct snake
{
    private:
	int pos[2][50];
	int size;
	int score;
    public:
	char keys[4],in;
	void eating();
	void move();
	void display_snake(int,int);
	int scor();
	void Default(int);
	int xye(int,int,int);
	void ai();
	void aii();
	void aik();
	void ail();
	void aij();
	int check(char);
	int out(int);
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
int snake::scor()
{
   return score;
}

void snake::eating()
{
    if (pos[0][0]>=fx-3 && pos[0][0]<=fx+3 && pos[1][0]>=fy-3 && pos[1][0]<=fy+3)
    {
       if(scor()%9==0 && scor()!=0)
       sound(500);
       else
       sound(310);

       delay(50);
       nosound();
       randomize();
       fx = 30 + rand() % 600;
       fy = 30 + rand() % 400;
       size++;
       score++;
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
       pos[0][0]=10;
   }
   if (in == keys[2])
   {
      pos[1][0] += 5;
      if(pos[1][0]>=445)
	pos[1][0]=18;

   }
   if (in == keys[0])
   {
      pos[1][0] -= 5;
      if(pos[1][0]<=18)
	pos[1][0]=445;

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
{  if(x)
   {
      sam[1].ai();
   }
   char q,G;
   if (kbhit())
   {
	q = getch();
	if(q=='p')
	{

	   setcolor(YELLOW);
	   settextjustify(CENTER_TEXT,CENTER_TEXT);
	   outtextxy(getmaxx()/2,getmaxy()/2,"GAME PAUSED PRESS P TO START");
	   while(1)
	   {
	      if(kbhit())
		G=getch();
	      if(G=='p')
		break;
	   }
	}
	else
	{
	  for(int i=0;i<(x==0?n:1);i++)
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
      return 0;
   else
      return 1;
}

int snake::out(int sno)
{
   for(int i=0;i<size;i++)
   {
       for(int j=i+1;j<size;j++)
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
void snake::Default(int i)
{
    if(i==0)
    {
	keys[0]='w';
	keys[1]='a';
	keys[2]='s';
	keys[3]='d';
	in='d';
	pos[0][0] = 50;
	pos[1][0] = 49;
	pos[0][1] = 49;
	pos[1][1] = 49;
	pos[0][2]=100;
	pos[1][2]=100;
	size = 2;
	score=0;

    }
    else if(i==1)
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
	size = 2;
	score=0;
    }
}


int menu()
{
   _setcursortype(_NOCURSOR);
   int y=10,ch;
   char k,m;
   while(1)
   {
     gotoxy(32,10);
     cout<<"1.SINGLE PLAYER"  ;
     gotoxy(32,11);
     cout<<"2.DUAL PLAYER";
     gotoxy(32,12);
     cout<<"3.PLAY WITH AI";
     gotoxy(32,13);
     cout<<"4.HOW TO PLAY"  ;
     gotoxy(32,14);
     cout<<"5.CHANGE COLOUR"  ;
     gotoxy(32,15);
     cout<<"6.DIFFICULTY";
     gotoxy(69,24);
     cout<<"press Q quit";
     gotoxy(30,y);
     cout<<"->";
     if(kbhit())
     {
	k=getch();
	if(k=='q')
	{
	    clrscr();
	    for(int j=0;;j++)
	    {
	      gotoxy(24,12);
	      textcolor(j);
	      cout<<"THANK YOU FOR PLAYING OUR GAME!!";
	      if(j==15)
		j=0;
	      if(kbhit())
		break;
	      delay(100);
	      clrscr();
	    }
	    exit(0);
	}
	if(k==' ')
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
	if(k=='w')
	{
	  sound(900);
	  delay(10);
	  nosound();
	  if(y>10)
	     y--;
	  else
	     y=15;
	  clrscr();

	}
	if(k=='s')
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
void color_menu()
{

   string menu[10];
   strcpy(menu[0],"1.CYAN");
   strcpy(menu[1],"2.GREEN");
   strcpy(menu[2],"3.DARKGRAY");
   strcpy(menu[3],"4.BROWN");
   strcpy(menu[4],"5.BLUE");
   strcpy(menu[5],"6.MAGENTA");
   strcpy(menu[6],"7.LIGHTBLUE");
   strcpy(menu[7],"8.LIGHTGREEN");
   strcpy(menu[8],"9.WHITE");
   strcpy(menu[9],"10.ORANGE");

   int i;
   for(i=0;i<10;i++)
   {
       gotoxy(32,i+2);
       cout<<menu[i];
       delay(250);
   }
}
void main()
{
	clrscr();
	int know=0,ch;
	int gd=DETECT,gm;
	int c=WHITE;
	int tough=100;
	char ps[2][15];

	snake jack[5];
	jack[0].Default(0);
	jack[1].Default(1);

	_setcursortype(_NOCURSOR);

	int no_of_players;

	textcolor(LIGHTGRAY);
	cout<<"init";
	clrscr();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(getmaxx()/2,getmaxy()/2,"THE SNAKEGAME");
	getch();
	closegraph();
	do
	{
	  ch=menu();
	  clrscr();
	  switch(ch)
	  {
	    case 1:

	    int j=1;
	    jack[0].Default(0);
	    no_of_players=1;
	    initgraph(&gd,&gm,"C:\\TC\\BGI");
	    while(input(jack,no_of_players))
	    {
		if(j==12)
		   j=1;
		display_border(j,tough);
		food();
		j++;
		for(int i=0;i<no_of_players;i++)
		{
		   know=jack[i].out(i);
		   if(know)
		   {
		       know+=i;
		       break;
		   }
		   jack[i].display_snake(c,0);
		   jack[i].eating();
		   jack[i].move();
		   sprintf(ps[0],"Score:%d",jack[i].scor());
		}
		setcolor(WHITE);
		outtextxy(280,20,ps[0]);
		if(know)
		{
		   for(i=10;;i++)
		   {
		     setcolor(YELLOW);
		     outtextxy(i,219,"GAME OVER");
		     outtextxy(i+3,235,ps[0]);
		     if(i>=625)
		      i=0;

		      if(kbhit())
		      break;
		      delay(100);
		      cleardevice();
		      display_border(j,tough);
		      i+=2;
		   }
		   getch();
		   break;
		}
		delay(tough);
		cleardevice();
	    }
	    closegraph();
	    break;

	    case 2:

	    jack[0].Default(0);
	    jack[1].Default(1);
	    no_of_players=2;

	    char player[20];
	    initgraph(&gd,&gm,"C:\\TC\\BGI");
	    while(input(jack,no_of_players))
	    {
	       display_border(j,tough);
	       food();
	       j++;
	       for(int i=0;i<no_of_players;i++)
	       {
		   know=jack[i].out(i);

		   if(know)
		   break;

		   if(i==0)
		   sprintf(ps[0],"p1 score:%d",jack[i].scor());
		   if(i==1)
		   sprintf(ps[1],"p2 score:%d",jack[i].scor());

		   jack[i].display_snake(c,i);
		   jack[i].eating();
		   jack[i].move();

	       }
	       setcolor(WHITE);
	       outtextxy(540,20,ps[1]);
	       outtextxy(15,20,ps[0]);
	       if(know)
	       {
		  if(know==1)
		  strcpy(player,"player 1 is out");
		  if(know==2)
		  strcpy(player,"player 2 is out");

		  for(i=10;;i++)
		  {
		     setcolor(YELLOW);
		     outtextxy(i,219,"GAME OVER");
		     outtextxy(255,230,player);
		     outtextxy(255,240,ps[0]);
		     outtextxy(255,255,ps[1]);
		     if(i>=625)
		     i=0;
		     if(kbhit())
		     break;
		     delay(100);
		     cleardevice();
		     display_border(j,tough);
		     i+=5;
		  }
		  getch();
		  break;
		}
		delay(tough);
		cleardevice();
	    }
	    closegraph();
	    break;

	case 3:
	char ps[2][15];
	int tough2=tough;
	if(tough2==15)
	  tough2=30;
	jack[0].Default(0);
	jack[1].Default(1);
	no_of_players=2;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	while(input(jack,no_of_players,1))
	{
	   display_border(j,tough2);
	   food();
	   j++;
	   for(int i=0;i<no_of_players;i++)
	   {
	      know=jack[i].out(i);
	      if(know)
	      {
		know+=i;
		break;
	      }

	      if(i==0)
	      sprintf(ps[0],"p score:%d",jack[i].scor());
	      if(i==1)
	      sprintf(ps[1],"AI score:%d",jack[i].scor());

	      jack[i].display_snake(c,i);
	      jack[i].move();
	      jack[i].eating();
	   }
	   setcolor(WHITE);
	   outtextxy(540,20,ps[1]);
	   outtextxy(15,20,ps[0]);
	   if(know)
	   {
	      for(int q=1;;q++)
	      {
		   if(q==31)
		     q=1;
		   cleardevice();
		   display_border(q,0);
		   settextstyle(DEFAULT_FONT,HORIZ_DIR,q%8);
		   settextjustify(CENTER_TEXT,CENTER_TEXT);
		   outtextxy(getmaxx()/2,getmaxy()/2,"GAME OVER");
		   if(kbhit())
		     break;
		   delay(100);
	      }
	      getch();
	      break;
	   }
	   delay(tough2);
	   cleardevice();
	}
	closegraph();
	break;

	case 4:
	    cout<<"The game has the the facility of single player and multiplayer.\n";
	    cout<<"CONTROL KEYS\n";
	    cout<<"W,I --> move up\n";
	    cout<<"S,K --> move down\n";
	    cout<<"D,L --> move right\n";
	    cout<<"A,J --> move left\n";
	    cout<<"A,W,S,D can be used for single palyer mode!\n";
	    cout<<"A,W,S,D is for player 1 & I,J,K,L is for player 2 in dual player mode!!\n";
	    cout<<"Also contains various difficulty levels!!!";
	    gotoxy(24,25);
	    cout<<"Developed by:Guhan & JosephDanial";
	    gotoxy(78,25);
	    cout<<"v1";
	    getch();
	    clrscr();
	    break;

	case 5:

	    clrscr();
	    char val;
	    color_menu();
	    cout<<"\nenter your choice:";
	    cin>>val;
	    switch(val)
	    {
	      case '1':c=CYAN;break;
	      case '2':c=GREEN;break;
	      case '3':c=DARKGRAY;break;
	      case '4':c=BROWN;break;
	      case '5':c=BLUE;break;
	      case '6':c=MAGENTA;break;
	      case '7':c=LIGHTBLUE;break;
	      case '8':c=LIGHTGREEN;break;
	      case '9':c=WHITE;break;
	      case '10':c=LIGHTRED;break;
	      default:c=WHITE;
	    }
	    clrscr();
	    break;

	    case 6:
	    int tgh;
	    gotoxy(32,2);
	    cout<<"1.NORMAL";
	    gotoxy(32,3);
	    cout<<"2.HIGH";
	    gotoxy(32,4);
	    cout<<"3.ADVENTURE";
	    gotoxy(32,5);
	    cout<<"4.EXPERT(Think before you select)";
	    cout<<"\nEnter your choice:";
	    cin>>tgh;
	    if(tgh==1)
	      tough=100;
	    else if(tgh==2)
	      tough=60;
	    else if(tgh==3)
	      tough=30;
	    else if(tgh==4)
	      tough=15;
	    else
	      tough=100;
	    clrscr();
	    break;
	  }
	}while(1);
}



