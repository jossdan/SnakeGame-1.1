#include"snake.cpp"

void main()
{    
    int know=0,j=1,ch,no_of_players,gd=DETECT,gm,c=WHITE,tough=100;
    char ps[2][15];
    int ee=0;
    snake jack[2];

    if(ee==1)
      jack[0].highs_init();


    _setcursortype(_NOCURSOR);
    textcolor(LIGHTGRAY);
    cout<<"init";
    clrscr();

    ///////game title/////////
    initgraph(&gd,&gm,BGI);
    text3D(180,220,6,GREEN,LIGHTGREEN,DEFAULT_FONT,4,"SLITHER.IO");

    char a[2];
    for(int i=200; i<=440; i+=1)
    {
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  bar(200,280,i,290);
  setcolor(WHITE);
  settextstyle(0,HORIZ_DIR,1.5);
  outtextxy(200,270,"Loading....");
  delay(15);
    }
    setcolor(BLACK);
    settextstyle(0,HORIZ_DIR,1.5);
    outtextxy(200,270,"Loading....");
    setcolor(WHITE);
    outtextxy(200,270,"GameLoaded");
    delay(20);
    closegraph();
    //////////////////////////

    do
    {
  ch=snake_menu();
  clrscr();

  jack[0].init_obj(0);
  jack[1].init_obj(1);

  switch(ch)
  {

  case 1:
      no_of_players=1;
      initgraph(&gd,&gm,BGI);
      while((j==12?j=1:j=j,input(jack,no_of_players)))
      {
    display_border(j,tough);
    food();
    j++;
    know=jack[0].out(0);
    if(know)
    {
        know=1;
        break;
    }
    jack[0].display_snake(c,0);
    jack[0].eating(1);
    jack[0].move();

    sprintf(ps[0],"Score:%d",jack[0].scor());
    sprintf(ps[1],"Highscore:%d",jack[0].high_s());

    setcolor(WHITE);

    outtextxy(15,20,ps[0]);
    outtextxy(535,20,ps[1]);

    if(know)
    {
        for(int i=10;; i++)
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
      jack[0].sort();
      closegraph();
      break;
  case 2:
      no_of_players=2;
      char player[20];
      initgraph(&gd,&gm,BGI);
      while(input(jack,no_of_players))
      {
    display_border(j,tough);
    food();
    j++;
    for(int i=0; i<no_of_players; i++)
    {
        know=jack[i].out(i);
        if(know)
      break;
        if(i==0)
      sprintf(ps[0],"p1 score:%d",jack[i].scor());
        if(i==1)
      sprintf(ps[1],"p2 score:%d",jack[i].scor());
        jack[i].display_snake(c,i);
        jack[i].eating(2);
        jack[i].move();
    }
    setcolor(WHITE);
    outtextxy(540,20,ps[1]);
    outtextxy(15,20,ps[0]);
    if(know)
    {
        if(know==1)
      strcpy(player,"Player 1 is out");
        if(know==2)
      strcpy(player,"Player 2 is out");
        for(i=10;; i++)
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
         jack[0].init_obj(0);
        jack[1].init_obj(1);
        no_of_players=2;
        initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
        while(input(jack,no_of_players,1))
        {
          display_border(j,tough);
          food();
          j++;
          for(int i=0;i<no_of_players;i++)
          {
      know=jack[i].out(i);
      if(know)
      {
         know+=i;
      }
      jack[i].display_snake(c,i);
      jack[i].move();
      jack[i].eating(2);
        }
        if(know)
    {
       for(int q=1;q<=31;q++)
       {
        cleardevice();
       display_border(q,tough);
       settextstyle(DEFAULT_FONT,HORIZ_DIR,q%8);
       settextjustify(CENTER_TEXT,CENTER_TEXT);
       outtextxy(getmaxx()/2,getmaxy()/2,"GAME OVER");
       delay(100);
       }
       getch();
       break;
    }
        delay(tough);
        cleardevice();
        }
        closegraph();
        break;
  case 4:
      int tgh;
      textcolor(WHITE);
      gotoxy(32,2);
      cout<<"1.NORMAL";
      gotoxy(32,3);
      cout<<"2.HIGH";
      gotoxy(32,4);
      cout<<"3.ADVENTURE";
      cout<<"\nEnter your choice:";
      cin>>tgh;
      if(tgh==1)
    tough=100;
      else if(tgh==2)
    tough=60;
      else if(tgh==3)
    tough=30;
      else
    tough=100;
      clrscr();
      break;


  case 5:
      jack[0].dis5();
      getch();
      clrscr();
      break;
  case 6:
      return;
  }
    } while(1);
}


int user_menu()
{
    textcolor(WHITE);
    int y=10,ch;
    char k,m;
    while(1)
    {
  gotoxy(32,10);
  cout<<"1.CREATE PROFILE";
  gotoxy(32,11);
  cout<<"2.LOGIN/SIGN.IN ";
  gotoxy(32,12);
  cout<<"3.DELETE PROFILE";
  gotoxy(32,13);
  cout<<"4.EXIT";
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
        exit(0);
    return ch;
      }
      if(k==72)
      {
    if(y>10)
        y--;
    else
        y=13;
    clrscr();
      }
      if(k==80)
      {
    if(y<13)
        y++;
    else
        y=10;
    clrscr();
      }
  }
    }
}
int playstation_menu()
{
    textcolor(WHITE);
    int y=10,ch;
    char k,m;
    while(1)
    {
  gotoxy(32,10);
  cout<<"1.SLITHER.IO";
  gotoxy(32,11);
  cout<<"2.SIMULATION";
  gotoxy(32,12);
  cout<<"3.2046";
  gotoxy(32,13);
  cout<<"4.Exit";
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
    else if(y==11)
        ch=2;
    else if(y==12)
        ch=3;
    else if(y==13)
      ch=4;
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
        y=13;
    clrscr();
      }
      if(k==80)
      {
    sound(900);
    delay(10);
    nosound();
    if(y<13)
        y++;
    else
        y=10;
    clrscr();
      }
  }
    }
}
