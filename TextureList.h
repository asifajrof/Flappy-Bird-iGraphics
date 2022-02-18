#include "texture.h"

texture cloud,quit,bird,bird2,birddead,pause,pillerup,pillerdown1,pillerdown2,pillerdown3,pillerdown4,endingimage,startingimage,gamebackground,score0,score1,score2,score3,score4,score5,score6,score7,score8,score9,highscoreimage;

void textureInit()
{
    cloud.Create("cloud.bmp");
    quit.Create("quit.bmp");
	bird.Create("bird.bmp");
	bird2.Create("bird2.bmp");
	birddead.Create("birddead.bmp");
	pause.Create("pause.bmp");
	pillerup.Create("p_up.bmp");
	pillerdown1.Create("p_down1.bmp");
	pillerdown2.Create("p_down2.bmp");
	pillerdown3.Create("p_down3.bmp");
	pillerdown4.Create("p_down4.bmp");
	endingimage.Create("end.bmp");
	startingimage.Create("starting.bmp");
	gamebackground.Create("background.bmp");
	score0.Create("score0.bmp");
	score1.Create("score1.bmp");
	score2.Create("score2.bmp");
	score3.Create("score3.bmp");
	score4.Create("score4.bmp");
	score5.Create("score5.bmp");
	score6.Create("score6.bmp");
	score7.Create("score7.bmp");
	score8.Create("score8.bmp");
	score9.Create("score9.bmp");
    highscoreimage.Create("highscore.bmp");

}



/**
How to use texture image:

1. in TextureList.h: declare texture type variables as needed. For every image, you need to declare one texture type variable.

Example:

texture textureVariable;


2. in TextureList.h: in the function textureInit(): initialize the texture variable that you declared in step 1 with the name
of the image file.

Example: suppose you have an image file named: "google.bmp"
then, you initialize as follows:

textureVariable.Create("google.bmp");


3. in the main cpp file in iDraw function: use drawTexture function to draw the image. drawTexture takes three arguments.

-> first argument   : lower left x-coordinate of the image
-> second argument  : lower left y-coordinate of the image
-> third argument   : name of the textureVariable declared in step 1


Example:

drawTexture(100, 200, textureVariable);
**/
