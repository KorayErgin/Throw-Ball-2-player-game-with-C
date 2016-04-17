#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define PI 3.14159265359

volatile int timer;
void timerr()
{
timer--;	
}
END_OF_FUNCTION(timerr)
void main()
{

int enb=0;
		srand(time(0));
allegro_init();
install_timer();
install_keyboard();
install_mouse();
install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
SAMPLE *kir=load_sample("kirma.wav");
set_gfx_mode( GFX_AUTODETECT_WINDOWED, 900, 560, 0, 0);
bas:
timer=20;
LOCK_FUNCTION(timerr);
LOCK_VARIABLE(timer);
install_int_ex(timerr,SECS_TO_TIMER(1));
BITMAP *bmp= load_bitmap("yikim.bmp", NULL);
BITMAP *duvar=load_bitmap("wall.bmp",NULL);
BITMAP *yik=load_bitmap("yikim.bmp",NULL);
BITMAP *enter=load_bitmap("enter.bmp",NULL);
BITMAP *enter2=load_bitmap("araenter.bmp",NULL);
BITMAP *top;
BITMAP *cik=load_bitmap("cikis.bmp",NULL);
BITMAP *player1= load_bitmap("player1.bmp",NULL);
BITMAP *player2= load_bitmap("player2.bmp",NULL);
int pause;
int sayi,uzun;
int ismap=0,isshot=0,yatay,dikey,yatay2,dikey2;
int aci=10,aci2=10,j=0,ilkx,ilky,ilkx2,ilky2,indis=0;
int yikim[31];
int sira=0,hak1=3,hak2=3,skor1=0,skor2=0;
int hedef1[2],hedef2[2];
int k,k2,ruzgar,deneme=0;
int onceki[2]={0,0};
float sure,cosx,siny,hiz=10,hiz2=10,hipo;
int b1x=0,b1y=500,s1=0,s2=0,x=50,y=50;
blit(bmp, screen, 0,0,0,0,900,800);
blit(cik, screen, 0,0,700,50,840,150);

  
top=load_bitmap("ball.bmp",NULL);
 while(!key[KEY_ENTER])
 {
 		textprintf_ex(screen,font,350,200, makecol(255,0,0) ,makecol(0,0,0) ," Gunun Skoru: %d ",enb );
 			textprintf_ex(screen,font,350,250, makecol(255,0,0) ,makecol(0,0,0) ,"    Oyuncu Kontrolleri :");
        textprintf_ex(screen,font,350,310, makecol(255,0,0) ,makecol(0,0,0) ,"    W(+)  S(-) Player2 Hiz ayari  ");
        textprintf_ex(screen,font,350,330, makecol(255,0,0) ,makecol(0,0,0) ,"    D(+)  A(-) Player2 Aci ayari  ");
           textprintf_ex(screen,font,350,270, makecol(255,0,0) ,makecol(0,0,0) ,"   UP(+)  DOWN(-) Player1 Hiz ayari  ");
        textprintf_ex(screen,font,350,290, makecol(255,0,0) ,makecol(0,0,0) ," RIGHT(+)  LEFT(-) Player1 Aci ayari  ");
 	 show_mouse(screen);
 	 while(mouse_b&&1)
	 {
	 	int x=mouse_x;
	 	int y=mouse_y;
	 	int z=mouse_z;
	 	rest(100);
	    textprintf_ex(screen,font,620,30, makecol(255,0,0) ,makecol(0,0,0) ,"Kordinat: %d  %d  %d",x,y,z);
	  
	   if(x<900&&x>700&&y>50&&y<135) exit(0); 	
	 }
	
	 
 blit(enter, screen, 0,0,330,400,120,110);
 rest(300);
 blit(enter2, screen, 0,0,330,400,120,110);
 rest(300);
 textprintf_ex(screen,font,280,530, makecol(255,0,0) ,makecol(0,0,0) ,"OYUNA BASLAMAK iCiN ENTER TUSUNA BASiNiZ" );

}


 blit(bmp, screen, 0,0,0,0,900,800);
while(!key[KEY_ESC]){
	if(key[KEY_P]){
 	pause=1;
 	int hafiza=timer;
 	while(pause!=0)
 	{
 		if(key[KEY_P]) pause=0;
 		readkey();
 	}
 	timer=hafiza;
 }
	if(timer==0&& sira==0){sira=1;timer=20;}
	else if(timer==0&& sira==1){sira=0;timer=20;}
	 textprintf_centre_ex(screen,font,475,30, makecol(255,0,0) ,makecol(0,0,0) ,"Sure:%d ",timer);

		textprintf_ex(screen,font,680,60, makecol(255,0,0) ,makecol(0,0,0) ,"Player 2 Skor: %d",skor2 );
			textprintf_ex(screen,font,90,60, makecol(255,0,0) ,makecol(0,0,0) ,"Player 1 Skor: %d",skor1 );
	if(ismap==0&&b1x<900 &&b1y<800)	{

    k = rand()%4+1;
    k2=rand()%4+11;
	ruzgar=rand()%20+1;
		    
	textprintf_ex(screen,font,333,30, makecol(255,0,0) ,makecol(0,0,0) ,"ruzgar:%d ",ruzgar );

while(15!=s1)
{
	
    uzun = rand()%6+1;;
while(uzun!=s2)
{
	
	blit(duvar, screen, 0 ,0,b1x,b1y,60,60);

b1y-=60;
s2++;
if(s2==uzun&& k==s1) //resim konumu p1
{
     blit(player1, screen, 0,0,b1x,b1y-15,200,100);
     hedef2[0]=b1x;
	 hedef2[1]=b1y-15;
     yatay=b1x+45;
     ilkx=b1x+45;
     dikey=b1y-15;
     ilky=b1y-15;
}
if(s1==k2&&s2==uzun)
{
	 blit(player2, screen, 0,0,b1x,b1y-15,200,100);
	 hedef1[0]=b1x;
	 hedef1[1]=b1y-15;
	 yatay2=b1x+45;
	 dikey2=b1y-15;
	 ilkx2=b1x+45;
	 ilky2=b1y-15;
}

}
yikim[2*s1+1]=b1x;
yikim[2*s1+2]=b1y;
s1++;
b1x+=60;
b1y=500;
s2=0; 

}

}
int sayici1=0,sayici2=0;
if(sayici1==0&&key[KEY_RIGHT]&&aci<80){aci+=10; rest(80); sayici1++;}   //Hýz ve aci ayari player 1
if(sayici1==0&&key[KEY_LEFT]&&aci>0){ aci-=10; rest(80); sayici1++;}
if(sayici2==0&&key[KEY_UP]&&hiz<=90){hiz+=10; rest(80); sayici2++;}
if(sayici2==0&&key[KEY_DOWN]&&hiz>=10){ hiz-=10; rest(80); sayici2++;}
textprintf_ex(screen,font,30,30, makecol(255,0,0) ,makecol(0,0,0) ,"Player 1   Atis acisi: %d hiz :%2.0f ",aci,hiz);

sayici1=0;
sayici2=0;
if(sayici1==0&&key[KEY_D]&&aci2<80){aci2+=10; rest(80); sayici1++;}   //Hýz ve aci ayari player 2
if(sayici1==0&&key[KEY_A]&&aci2>0){ aci2-=10; rest(80); sayici1++;}
if(sayici2==0&&key[KEY_W]&&hiz2<=90){hiz2+=10; rest(80); sayici2++;}
if(sayici2==0&&key[KEY_S]&&hiz2>=10){ hiz2-=10; rest(80); sayici2++;}
textprintf_ex(screen,font,600,30, makecol(255,0,0) ,makecol(0,0,0) ,"Player 2 Atis acisi: %d hiz :%2.0f ",aci2,hiz2);
	
if(isshot<3&&key[KEY_SPACE]&&sira==0)
{

yatay=ilkx;
dikey=ilky;	   

	cosx=hiz*cos(aci*PI/180);
	siny=hiz*sin(aci*PI/180);
int i=0;
 while(deneme ==0&&i!=99)
 {
   	blit(top,screen,0,0,yatay,dikey,15,15);
    rest(50);
    indis=yatay/60;
  
    blit(bmp, screen, 0,0,yatay,dikey,25,25);
     if(hedef1[0]+100>yatay&&hedef1[0]<=yatay && hedef1[1]<=dikey)
	{
		
		textprintf_ex(screen,font,433,60, makecol(255,0,0) ,makecol(0,0,0) ,"Player 1 VURDU" );
		 rest(1999);
		blit(enter2,screen,0,0,430,60,130,50);
		skor1=skor1+(timer/4)*100;
		play_sample(kir,255,128,1000,FALSE);
		break;
	}
    if(yikim[2*indis+2]<=dikey) 
	{
	blit(yik,screen,0,0,yikim[2*indis+1],yikim[2*indis+2],60,600-yikim[2*indis+2]);
    play_sample(kir,255,128,1000,FALSE);
	yikim[2*indis+1]=550;
    yikim[2*indis+2]=550;
    break;

	}
	
	yatay+=cosx;
	yatay+=ruzgar;
   	dikey-=siny;
   	siny-=10;
     i++;
     
}
sira=1;
rest(100);
timer=20;
}

if(isshot<3&&key[KEY_SPACE]&&sira==1)
{

yatay2=ilkx2;
dikey2=ilky2;		  

	cosx=hiz2*cos(aci2*PI/180);
	siny=hiz2*sin(aci2*PI/180);
	
int i=0;
 while(deneme ==0&&i!=99)
 {
   	blit(top,screen,0,0,yatay2,dikey2,15,15);
   	rest(50);
    indis=yatay2/60;
    blit(bmp, screen, 0,0,yatay2,dikey2,25,25);
  if(hedef2[0]+110>=yatay2 &&hedef2[0]-20<=yatay2&& hedef2[1]-20<=dikey2)
	{
		
	   textprintf_ex(screen,font,433,60, makecol(255,0,0) ,makecol(0,0,0) ,"Player 2 VURDU" );
	   rest(1999);
	   blit(enter2,screen,0,0,430,60,130,50);
	   skor2=skor2+(timer/4)*100;
	   play_sample(kir,255,128,1000,FALSE);
       break;
	}
  
   if(yikim[2*indis+2]<=dikey2) 
	{
	blit(yik,screen,0,0,yikim[2*indis+1],yikim[2*indis+2],60,600-yikim[2*indis+2]);
    play_sample(kir,255,128,1000,FALSE);
	yikim[2*indis+1]=550;
    yikim[2*indis+2]=550;
    break;
   
	}
     
	yatay2-=cosx;
	yatay2-=ruzgar;
   	dikey2-=siny;
   	siny-=10;
     i++;
     
}
sira=0;
rest(100);
timer=20;
}

}

if(skor1>skor2)
{
textprintf_ex(screen,font,433,200, makecol(255,0,0) ,makecol(0,0,0) ,"Player 1 KAZANDI" );
enb=skor1;
rest(1200);
}
else if(skor2>skor1)
{

textprintf_ex(screen,font,433,200, makecol(255,0,0) ,makecol(0,0,0) ,"Player 2 KAZANDI" );
enb=skor2;
rest(1200);
}

destroy_bitmap(bmp);
destroy_bitmap(duvar);
clear_keybuf();
goto bas;
} END_OF_MAIN();

