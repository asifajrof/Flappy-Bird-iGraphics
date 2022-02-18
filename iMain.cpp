#include<dir.h>
#include<cstdio>
#include<fstream>
#include<windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include "iGraphics.h"

using namespace std;

int y =300,deadbirdx,deadbirdy,jumpcount=0,birdpic=0,startingbirdx=150 ,gamespeedchange=2,jumpflag=0, flag=0 ,prev_flag,scoreflag=1, downspeed=0,x1=500,x2=700,x3=900,x4=1100,score=0,c1=250,c2=340,c3=500,c4=610,c5=680,c6=850,scoredemo,i,shownumber,scorex=650,scorey=400,highscore;
FILE *fp;


/*startingbirdx means the animation of the bird moving
flag means different pages, 0-- start, 1-- Run, 2--End, 3-- Pause,4-- quit 5--dead animation
prev_flag -- when quitting, if press no, turns back to the previous page
scoreflag -- to control the removing of the file and writing it again
downspeed -- the fall of the bird
x -- pillars x coordinate
c- cloud x coordinate
scoredemo -- shows the changing score
scorex,scorey -- coordinates for the score*/


void birdpicchange()//this function creates the bird animation
{
    if(birdpic==0)
        birdpic=1;
    else
        birdpic=0;
}

void birdjumping()//this function makes the jump of the bird while flying
{
    if(jumpflag==1)
    {
        y=y+3;
        jumpcount++;
        if(jumpcount==15)
            jumpflag=2;
    }
    if(jumpflag==2)
    {
        y=y-1;
        jumpcount--;
        if(jumpcount==0)
            jumpflag=0;
    }
}

void downspeedchange()//this function controls the acceleration
{
    if(flag==1 && jumpflag==0)
       {
        downspeed=downspeed+1;
        y=y-downspeed;
       }
    if(score==20)
        gamespeedchange=2;
    if(score==100)
        gamespeedchange=3;

    if(flag==5)
    {
        deadbirdx=deadbirdx+7;
        deadbirdy=deadbirdy+5;
        if(y<32)
            y=32;
    }

    if(deadbirdy>420)
        flag=2;
}

void scoreshow()
{

        scoredemo=score;
        i=0;
        while(scoredemo!=0)
        {
            shownumber=scoredemo%10;
            scoredemo=scoredemo/10;
            if(shownumber==0)
                drawTexture((scorex-i*32),scorey,score0);
            if(shownumber==1)
                drawTexture((scorex-i*32),scorey,score1);
            if(shownumber==2)
                drawTexture((scorex-i*32),scorey,score2);
            if(shownumber==3)
                drawTexture((scorex-i*32),scorey,score3);
            if(shownumber==4)
                drawTexture((scorex-i*32),scorey,score4);
            if(shownumber==5)
                drawTexture((scorex-i*32),scorey,score5);
            if(shownumber==6)
                drawTexture((scorex-i*32),scorey,score6);
            if(shownumber==7)
                drawTexture((scorex-i*32),scorey,score7);
            if(shownumber==8)
                drawTexture((scorex-i*32),scorey,score8);
            if(shownumber==9)
                drawTexture((scorex-i*32),scorey,score9);

            i++;

        }
}

void highscoreshow()
{

        scoredemo=highscore;
        i=0;
        while(scoredemo!=0)
        {
            shownumber=scoredemo%10;
            scoredemo=scoredemo/10;
            if(shownumber==0)
                drawTexture((scorex-i*32),scorey-47,score0);
            if(shownumber==1)
                drawTexture((scorex-i*32),scorey-47,score1);
            if(shownumber==2)
                drawTexture((scorex-i*32),scorey-47,score2);
            if(shownumber==3)
                drawTexture((scorex-i*32),scorey-47,score3);
            if(shownumber==4)
                drawTexture((scorex-i*32),scorey-47,score4);
            if(shownumber==5)
                drawTexture((scorex-i*32),scorey-47,score5);
            if(shownumber==6)
                drawTexture((scorex-i*32),scorey-47,score6);
            if(shownumber==7)
                drawTexture((scorex-i*32),scorey-47,score7);
            if(shownumber==8)
                drawTexture((scorex-i*32),scorey-47,score8);
            if(shownumber==9)
                drawTexture((scorex-i*32),scorey-47,score9);

            i++;

        }
}

void damagecheck()
{
    birdjumping();

    startingbirdx=startingbirdx+3;

    if(flag==1){
    x1=x1-gamespeedchange;
    x2=x2-gamespeedchange;
    x3=x3-gamespeedchange;
    x4=x4-gamespeedchange;
    if(x1<0)
    {
        x1=x1+800;
        score++;
    }
    if(x2<0)
    {
        x2=x2+800;
        score++;
    }
    if(x3<0)
    {
        x3=x3+800;
        score++;
    }
    if(x4<0)
    {
        x4=x4+800;
        score++;
    }

    if(y<30 || y >430)
        flag=5;
    if(x1<50 && (y>290 || y<200))
        flag=5;
    if(x2<50 && (y>340 || y<252))
        flag=5;
    if(x3<50 && (y>270 || y<185))
        flag=5;
    if(x4<50 && (y>350 || y<280))
        flag=5;

    c1=c1-2*gamespeedchange;
    c2=c2-2*gamespeedchange;
    c3=c3-2*gamespeedchange;
    c4=c4-2*gamespeedchange;
    c5=c5-2*gamespeedchange;
    c6=c6-2*gamespeedchange;
    if(c1<0)
    {
        c1=c1+800;
    }
    if(c2<0)
    {
        c2=c2+800;
    }
    if(c3<0)
    {
        c3=c3+800;
    }
    if(c4<0)
    {
        c4=c4+800;
    }
    if(c5<0)
    {
        c5=c5+800;
    }
    if(c6<0)
    {
        c6=c6+800;
    }
    }
}

void iDraw()
{
	if(flag==0)
    {
        iClear();
        drawTexture(0,0,startingimage);
        if(birdpic==0)
            drawTexture(startingbirdx,400,bird);
        if(birdpic==1)
            drawTexture(startingbirdx,402,bird2);
        if(startingbirdx>520)
            startingbirdx=130;
    }
    else if(flag==5)
    {
        iClear();
        drawTexture(0,0,gamebackground);

        drawTexture(20+deadbirdx,deadbirdy,birddead);

        drawTexture(c1,410,cloud);
        drawTexture(c2,370,cloud);
        drawTexture(c3,380,cloud);
        drawTexture(c4,390,cloud);
        drawTexture(c5,420,cloud);
        drawTexture(c6,370,cloud);

        drawTexture(20,y,bird);

        drawTexture(x1,0,pillerdown1);
        drawTexture(x1,320,pillerup);
        drawTexture(x2,0,pillerdown2);
        drawTexture(x2,370,pillerup);
        drawTexture(x3,0,pillerdown3);
        drawTexture(x3,300,pillerup);
        drawTexture(x4,0,pillerdown4);
        drawTexture(x4,380,pillerup);

        drawTexture((scorex-0*32),scorey,score0);
        drawTexture((scorex-1*32),scorey,score0);
        drawTexture((scorex-2*32),scorey,score0);
        drawTexture((scorex-3*32),scorey,score0);
        drawTexture((scorex-4*32),scorey,score0);

        scoreshow();

    }


	else if(flag==1)
    {
        iClear();
        drawTexture(0,0,gamebackground);

        drawTexture(c1,410,cloud);
        drawTexture(c2,370,cloud);
        drawTexture(c3,380,cloud);
        drawTexture(c4,390,cloud);
        drawTexture(c5,420,cloud);
        drawTexture(c6,370,cloud);

        if(birdpic==0)
            drawTexture(20,y,bird);
        if(birdpic==1)
            drawTexture(20,y,bird2);

        drawTexture(x1,0,pillerdown1);
        drawTexture(x1,320,pillerup);
        drawTexture(x2,0,pillerdown2);
        drawTexture(x2,370,pillerup);
        drawTexture(x3,0,pillerdown3);
        drawTexture(x3,300,pillerup);
        drawTexture(x4,0,pillerdown4);
        drawTexture(x4,380,pillerup);

        drawTexture((scorex-0*32),scorey,score0);
        drawTexture((scorex-1*32),scorey,score0);
        drawTexture((scorex-2*32),scorey,score0);
        drawTexture((scorex-3*32),scorey,score0);
        drawTexture((scorex-4*32),scorey,score0);

        scoreshow();

        //iFilledRectangle(0,0,30,450);

        deadbirdx=0;
        deadbirdy=y;
    }
    else if(flag==3)
        drawTexture(240,70,pause);

    else if(flag==4)
        drawTexture(115,170,quit);

    else
    {
        drawTexture(0,0,endingimage);
        if(score>=highscore && scoreflag==1)
        {
            scoreflag=0;

            highscore=score;
            fclose(fp);

            fp= fopen("score.bin", "wb+");
            fprintf(fp, "%d", highscore);
        }

        if(score==highscore)
            drawTexture(535,300,highscoreimage);

        scorex=550;
        scorey=215;

        drawTexture((scorex-0*32),scorey,score0);
        drawTexture((scorex-1*32),scorey,score0);
        drawTexture((scorex-2*32),scorey,score0);
        drawTexture((scorex-3*32),scorey,score0);
        drawTexture((scorex-4*32),scorey,score0);

        scoreshow();

        drawTexture((scorex-0*32),scorey-47,score0);
        drawTexture((scorex-1*32),scorey-47,score0);
        drawTexture((scorex-2*32),scorey-47,score0);
        drawTexture((scorex-3*32),scorey-47,score0);
        drawTexture((scorex-4*32),scorey-47,score0);

        highscoreshow();
    }
}


void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && flag==1)
    {
        y=y+3;
        downspeed=0;
    }
    else if(button == GLUT_LEFT_BUTTON && flag==3 && mx<455 && mx>250 && my<387 && my>330 )
    {
        flag=1;
        downspeed=0;
    }
    else if(button == GLUT_LEFT_BUTTON && flag==3 && mx<455 && mx>250 && my<307 && my>245 )
    {
        flag=1;
        scoreflag=1;
        y =300;
        downspeed=0;
        x1=500;
        x2=700;
        x3=900;
        x4=1100;
        score=0;
        scorex=650;
        scorey=400;
        gamespeedchange=1;
    }
    else if(button == GLUT_LEFT_BUTTON && flag==3 && mx<455 && mx>250 && my<222 && my>160 )
    {

    }
    else if(button == GLUT_LEFT_BUTTON && flag==3 && mx<455 && mx>250 && my<140 && my>75 )
    {
        prev_flag=flag;
		flag=4;
    }
    else if(button == GLUT_LEFT_BUTTON && flag==4 && mx>180 && mx<290 && my>185 && my<230 )
    {
        exit(0);
    }
    else if(button == GLUT_LEFT_BUTTON && flag==4 && prev_flag==3 && mx>460 && mx<572 && my>180 && my<230 )
    {
        flag=1;
    }
    else if(button == GLUT_LEFT_BUTTON && flag==4 && mx>460 && mx<572 && my>180 && my<230 )
    {
        flag=prev_flag;
    }

}


void iKeyboard(unsigned char key)
{

	if (key == 'q' || key == 'Q')
    {
        prev_flag=flag;
		flag=4;
	}
	else if((key == 'p' || key == 'P') && flag==0)
    {
        flag=1;
    }
	else if((key == 'p' || key == 'P') && flag==1)
    {
        flag=3;
    }
    else if((key == 'j' || key == 'J') && flag==1)
    {
        jumpflag=1;
        downspeed=3;
    }
    else if((key == 'y' || key == 'Y') && flag==4)
    {
        exit(0);
    }
    else if((key == 'n' || key == 'N') && flag==4 && prev_flag==3)
    {
        flag=1;
    }
    else if((key == 'n' || key == 'N') && flag==4)
    {
        flag=prev_flag;
    }
    else if((key == 'p' || key == 'P') && flag==3)
    {
        flag=1;
        downspeed=0;
    }
    else if((key == 'r' || key == 'R') && flag==3)
    {
        flag=1;
        scoreflag=1;
        y =300;
        downspeed=0;
        x1=500;
        x2=700;
        x3=900;
        x4=1100;
        score=0;
        scorex=650;
        scorey=400;
        gamespeedchange=1;
    }
    else if((key == 'r' || key == 'R') && flag==2)
    {
        flag=1;
        scoreflag=1;
        y =300;
        downspeed=0;
        x1=500;
        x2=700;
        x3=900;
        x4=1100;
        score=0;
        scorex=650;
        scorey=400;
    }

}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
    {
		exit(0);
	}

}


int main()
{
    fp = fopen("score.bin", "rb+");
	fscanf(fp, "%d", &highscore);

//	PlaySound(TEXT("pacman"), NULL, SND_FILENAME | SND_ASYNC);

    iSetTimer(200,birdpicchange);
    iSetTimer(50,downspeedchange);
    iSetTimer(10,damagecheck);


	iInitialize(720, 450, "Flappy Bird");
	return 0;
}
