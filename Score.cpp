class score
{
protected:
  int s,top_five[6],high_score;
  int total;

public:
  void reset_s()
  {
    s=0;
  }
  void tot(int n)
  {
    total+=n;
  }
  void change(int n)
  {
    s+=n;
  }
  int scor();
  void sort();
  int high_s();
  void highs_init();
  void dis5();
  void h_a()
  {
    if(s>high_score)
      high_score=s;
  }

};

void score::highs_init()
{
  for(int i=0; i<6; i++)
    top_five[i]=0;
  high_score=0;

}
void score::sort()
{
  int i,j,t,flag=0;
  for(i=0; i<6; i++)
  {
    if(top_five[i]==high_score)
    {
      flag=1;
      break;
    }
  }

  if(flag==0)
  {
    top_five[5]=high_score;
    for(i=0; i<6; i++)
    {
      for(j=i+1; j<6; j++)
      {
        if(top_five[i]<top_five[j])
        {
          t=top_five[i];
          top_five[i]=top_five[j];
          top_five[j]=t;
        }
      }
    }
  }
}
int score::high_s()
{
  return high_score;
}
int score::scor()
{
  return s;
}



void score::dis5()
{
  gotoxy(30,2);
  cout<<"TOP FIVE SCORE::BOARD";
  for(int i=0; i<5; i++)
  {
    gotoxy(38,4+i);
    cout<<i+1<<"::"<<top_five[i];
  }
  textcolor(BLINK+LIGHTGRAY);
  gotoxy(29,10);
  cprintf("PRESS ANY KEY TO GO BACK");
  textcolor(LIGHTGRAY);
}
