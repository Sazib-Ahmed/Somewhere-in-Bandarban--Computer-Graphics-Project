#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<cstdio>
#include <GL/gl.h>
#define PI          3.141516
#include<math.h>
#include <cmath>
#include<stdlib.h>
#include <mmsystem.h>
#include <MMSystem.h>
#include <ctime>
#include <cstdlib>



 // GLUT, include glu.h and gl.h
#include <vector>

using namespace std;
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


bool tower_light=true;
GLfloat counter_position=0;
GLfloat counter_speed=1.5;


bool fire_light=true;
GLfloat fire_light_position=0;
GLfloat fire_light_speed=4.5;

bool cloud1=false,cloud2=false,cloud3=false,cloud4=false;
GLfloat cloud_light_position=0;
GLfloat cloud_light_speed=1;

bool mountain1_light=false,mountain1_shadow_light=false,mountain2_shadow_light=false,mountain3_shadow_light=false;

GLfloat position = 0;
GLfloat plane_position= 0;
GLfloat raft_position= 0;
GLfloat speed = 1;
GLfloat plane_speed= 3;
GLfloat raft_speed= 1;
GLfloat position_raft= 10;
GLfloat waterfall_on_river_speed= .7;
GLfloat waterfall_on_river_position= -20;



GLfloat water_shade_position1 = 0, water_shade_position2 = 0, water_shade_position3 = 0, water_shade_position4 = 0, water_shade_position5 = 0, water_shade_position6 = 0;
GLfloat water_shade_speed = 1;

GLfloat cloud_position1 = 150, cloud_position2 = 400, cloud_position3 = -1600, cloud_position4 = -1200;
GLfloat cloud_speed1 = .7, cloud_speed2 = .5, cloud_speed3 =  .3, cloud_speed4 = .5;

GLfloat waterfall_shade_position1 = 0, waterfall_shade_position2 = 0, waterfall_shade_position3 = 0;
GLfloat speed1 = 2;

GLfloat smoke_position1 = 0;
GLfloat smoke_speed1 = .3;
GLfloat smoke_position2 = 0;
GLfloat smoke_speed2 = .5;
GLfloat smoke_position3 = 0;
GLfloat smoke_speed3 = .7;


GLfloat bird_position = -150;
GLfloat bird_wings_position = 0;
GLfloat bird_speed = .5;
GLfloat bird_wing_speed= .2;


GLfloat sun_position_x=0;
GLfloat sun_position_y=0;

GLfloat moon_position_x=0;
GLfloat moon_position_y=0;
GLfloat moon_speed = .1;


void update(int value)
{

    if(plane_position > 3000) plane_position = 0;
    plane_position += plane_speed;

    if(raft_position > 1920) raft_position = 0;
    raft_position += raft_speed;

    if(waterfall_shade_position1 > 103) waterfall_shade_position1 = 0;
    waterfall_shade_position1 += speed1;

    if(waterfall_shade_position2 > 78) waterfall_shade_position2 = 0;
    waterfall_shade_position2 += speed1;

    if(waterfall_shade_position3 > 50) waterfall_shade_position3 = 0;
    waterfall_shade_position3 += speed1;


    if(waterfall_on_river_position > 1) waterfall_on_river_position = -10;
    waterfall_on_river_position += waterfall_on_river_speed;


    if(smoke_position1 > 8) smoke_position1 = 0;
    smoke_position1 += smoke_speed1;
    if(smoke_position2 > 8) smoke_position2 = 0;
    smoke_position2 += smoke_speed2;
    if(smoke_position3 > 8) smoke_position3 = 0;
    smoke_position3 += smoke_speed3;


    if(water_shade_position1 > 1500) water_shade_position1 = -700;
    water_shade_position1 += water_shade_speed;

    if(water_shade_position2 > 500) water_shade_position2 = -1800;
    water_shade_position2 += water_shade_speed;

    if(water_shade_position3 > 1800) water_shade_position3= -100;
    water_shade_position3 += water_shade_speed;

    if(water_shade_position4 > 400) water_shade_position4 = -1600;
    water_shade_position4 += water_shade_speed;

    if(water_shade_position5 > 800) water_shade_position5 = -1200;
    water_shade_position5 += water_shade_speed;

    if(water_shade_position6 > 1500) water_shade_position6 = -800;
    water_shade_position6 += water_shade_speed;


    if(cloud_position1 > 1950) cloud_position1 = -300;
    cloud_position1 += cloud_speed1;

    if(cloud_position2 > 1950) cloud_position2 = -150;
    cloud_position2 += cloud_speed2;

    if(cloud_position3 > 200) cloud_position3 = -1950;
    cloud_position3 += cloud_speed3;

    if(cloud_position4 > 150)cloud_position4 = -1900;
    cloud_position4 += cloud_speed4;

    if(bird_position > 1950)bird_position = -150;
    bird_position += bird_speed;

    if(bird_wings_position > 3)bird_wings_position = 0;
    bird_wings_position += bird_wing_speed;



    if(sun_position_x > 3100)sun_position_x = -5000;
    sun_position_x += speed;

    if(moon_position_x >500)moon_position_x = -350;
    moon_position_x += moon_speed;




    if(counter_position > 100){
            counter_position = 0;

    }
    counter_position += counter_speed;

    if(counter_position<50)tower_light=true;
    if(counter_position>50)tower_light=false;


    if(fire_light_position > 40){
            fire_light_position = 0;

    }
    fire_light_position += fire_light_speed;

    if(fire_light_position<20)fire_light=true;
    if(fire_light_position>20)fire_light=false;



    if(cloud_light_position > 500){
            cloud_light_position = 0;

    }
    cloud_light_position += cloud_light_speed;

    if(cloud_light_position==30||cloud_light_position==33||cloud_light_position==36||cloud_light_position==40||cloud_light_position==45){
            cloud1=true;
            mountain1_light=true;
    }
    else {
            cloud1=false;
    }
    if(cloud_light_position==300||cloud_light_position==303||cloud_light_position==306||cloud_light_position==310||cloud_light_position==315){
            cloud2=true;
    }
    else {
            cloud2=false;
    }
    if(cloud_light_position==100||cloud_light_position==103||cloud_light_position==106||cloud_light_position==110||cloud_light_position==115){
            cloud3=true;
    }
    else {
            cloud3=false;
    }
    if(cloud_light_position==430||cloud_light_position==433||cloud_light_position==436||cloud_light_position==440||cloud_light_position==445){
            cloud4=true;
    }
    else {
            cloud4=false;
    }

    if(cloud_light_position==30||cloud_light_position==33||cloud_light_position==36||cloud_light_position==40||cloud_light_position==45||cloud_light_position==100||cloud_light_position==103||cloud_light_position==106||cloud_light_position==110||cloud_light_position==115||cloud_light_position==300||cloud_light_position==303||cloud_light_position==306||cloud_light_position==310||cloud_light_position==315||cloud_light_position==430||cloud_light_position==433||cloud_light_position==436||cloud_light_position==440||cloud_light_position==445){
            mountain1_light=true;
            mountain1_shadow_light=true;
            mountain2_shadow_light=true;
            mountain3_shadow_light=true;
    }
    else {
            mountain1_light=false;
            mountain1_shadow_light=false;
            mountain2_shadow_light=false;
            mountain3_shadow_light=false;
    }




    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void circle(float x, float y, float radius, float height)
{
    int triangleAmount = 360;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= 360; i++)
        glVertex2f(x + (radius * cos(i * 2 * 3.1416 / triangleAmount)), y + (height * sin(i * 2 * 3.1416 / triangleAmount)));
    glEnd();
}

//for circle with 2 color shade
void moon(float x, float y, float radius, float height,float r1, float g1, float b1,float r2, float g2, float b2)
{
    int triangleAmount = 360;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r1,g1,b1);
    glVertex2f(x, y); // center of circle
    glColor3f(r2,g2,b2);
    for (int i = 0; i <= 360; i++)
        glVertex2f(x + (radius * cos(i * 2 * 3.1416 / triangleAmount)), y + (height * sin(i * 2 * 3.1416 / triangleAmount)));
    glEnd();
}


void anti_clock_circle(float p, float q, float radius, float height, float angle)
{
    int triangleAmount = 360;
    float a,b=0;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p+(a*cos(angle)-b*sin(angle)), q+(a*sin(angle)+b*cos(angle))); // center of circle
    for (int i = 0; i <= 360; i++){
        //x=a*cos(angle)-b*sin(angle);  //anti clock formula for x
        //y=a*sin(angle)+b*cos(angle);  //anti clock formula for y
        //x1=(a + (radius * cos(i * 2 * 3.1416 / triangleAmount))); //circle points formula with height for x
        //y1=(b + (height * sin(i * 2 * 3.1416 / triangleAmount))); //circle points formula with height for y

        //upper 4 line combine
        glVertex2f(p+((a + (radius * cos(i * 2 * 3.1416 / triangleAmount)))*cos(angle)-(b + (height * sin(i * 2 * 3.1416 / triangleAmount)))*sin(angle)), q+((a + (radius * cos(i * 2 * 3.1416 / triangleAmount)))*sin(angle)+(b + (height * sin(i * 2 * 3.1416 / triangleAmount)))*cos(angle)));
    }
    glEnd();
}


void bezier_curve3(float x1, float y1, float x2, float y2,float x3, float y3)
{
    float t=0;
    glVertex2f(((x1*pow((1-t),2))+x2*2*t*(1-t)+x3*pow(t,2)),((y1*pow((1-t),2))+y2*2*t*(1-t)+y3*pow(t,2)));
    for (int i = 0; i <=100 ; i++){
        t+=.01;
        glVertex2f(((x1*pow((1-t),2))+x2*2*t*(1-t)+x3*pow(t,2)),((y1*pow((1-t),2))+y2*2*t*(1-t)+y3*pow(t,2)));
        glVertex2f(((x1*pow((1-t),2))+x2*2*t*(1-t)+x3*pow(t,2)),((y1*pow((1-t),2))+y2*2*t*(1-t)+y3*pow(t,2)));
    }
}

void bezier_curve4(float x1, float y1, float x2, float y2,float x3, float y3,float x4, float y4)
{
    float t=0;
    glVertex2f(((x1*pow((1-t),3))+x2*3*t*pow((1-t),2)+x3*3*pow(t,2)*(1-t)+x4*pow(t,3)),((y1*pow((1-t),3))+y2*3*t*pow((1-t),2)+y3*3*pow(t,2)*(1-t)+y4*pow(t,3)));
    for (int i = 0; i <=100 ; i++){
        t+=.01;
        glVertex2f(((x1*pow((1-t),3))+x2*3*t*pow((1-t),2)+x3*3*pow(t,2)*(1-t)+x4*pow(t,3)),((y1*pow((1-t),3))+y2*3*t*pow((1-t),2)+y3*3*pow(t,2)*(1-t)+y4*pow(t,3)));
        glVertex2f(((x1*pow((1-t),3))+x2*3*t*pow((1-t),2)+x3*3*pow(t,2)*(1-t)+x4*pow(t,3)),((y1*pow((1-t),3))+y2*3*t*pow((1-t),2)+y3*3*pow(t,2)*(1-t)+y4*pow(t,3)));
    }
}


//function for moving birds
void bird1(float x, float y){

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(x,y);
    glVertex2f(x+8,y);
    glEnd();

    glLineWidth(2);
    glPushMatrix();
    glTranslatef(0,-bird_wings_position,0);
    glBegin(GL_LINES);
    glVertex2f(x+5,y+3);
    glVertex2f(x+5,y);
    glEnd();
    glPopMatrix();
    }


void tree_type1(float x, float y, float height,float r1, float g1, float b1,float r2, float g2, float b2,float r3, float g3, float b3)
{

    int block = round(height/11);
    int half_block = round((height/11)/2);

    glColor3f(r1,g1,b1);
    circle((x-(2*block)),(y+(6*block)),(3*block),(3*block));
    circle((x+(2*block)),(y+(6*block)),(3*block),(3*block));
    circle(x,(y+(9*block)-half_block),(3*block),(3*block));

    glColor3f(r2,g2,b2);
    circle((x-(2*block)),(y+(5*block)),(2*block),(2*block));
    circle(x , (y+(7*block)),(2*block),(2*block));
    circle((x+(2*block)),(y+(5*block)),(2*block),(2*block));

    glBegin(GL_TRIANGLES);
    glColor3f(r3,g3,b3);
    glVertex2f(x , (y+(6*block)));
    glVertex2f((x-half_block) ,y);
    glVertex2f((x+half_block) ,y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((x-(2*block)), (y+(5*block)));
    glVertex2f(x , (y+(4*block)-half_block));
    glVertex2f(x , (y+(3*block)-half_block));
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((x+(2*block)), (y+(5*block)));
    glVertex2f(x , (y+(4*block)-half_block));
    glVertex2f(x , (y+(3*block)-half_block));
    glEnd();
}


void tree_type2(float x, float y, float height,float r1, float g1, float b1,float r2, float g2, float b2,float r3, float g3, float b3)
{

    int block = round(height/11);
    int half_block = round((height/11)/2);

    glColor3f(r1,g1,b1);
    circle((x-(3*block)), (y+(6*block)-half_block),(half_block+2*block),(half_block+2*block));
    glColor3f(r2,g2,b2);
    circle(x , (y+(9*block)),(half_block+2*block),(half_block+2*block));
    circle(x+((3*block)) , (y+(8*block)),(half_block+block),(half_block+block));
    circle(x , (y+(5*block)),(2*block),(2*block));
    circle(x , (y+(7*block)),(2*block),(2*block));
    circle((x-(3*block)+half_block), (y+(6*block)),(half_block+2*block),(half_block+2*block));
    circle((x+(4*block)-half_block),(y+(5*block)+half_block),(half_block+2*block),(half_block+2*block));

    glBegin(GL_TRIANGLES);
    glColor3f(r3,g3,b3);
    glVertex2f(x , (y+(9*block)));
    glVertex2f((x-half_block) ,y);
    glVertex2f((x+half_block) ,y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((x-(3*block)), (y+(6*block)));
    glVertex2f(x , (y+(4*block)-half_block));
    glVertex2f(x , (y+(3*block)-half_block));
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((x+(2*block)), (y+(5*block)));
    glVertex2f(x , (y+(4*block)-half_block));
    glVertex2f(x , (y+(3*block)-half_block));
    glEnd();
}



void tree_type3(float x, float y, float height,float r1, float g1, float b1,float r2, float g2, float b2,float r3, float g3, float b3)
{

    int block = round(height/11);
    int half_block = round((height/11)/2);

    glColor3f(r2,g2,b2);

    circle((x-(2*block)-half_block),(y+(7*block)),(2*block)-half_block,(2*block)-half_block);
    circle((x-(2*block)), (y+(4*block)),(1*block),(1*block));
    circle((x-(1*block)),(y+(5*block)-half_block),(half_block),(half_block));
    circle((x-(3*block)),(y+(4*block)),(half_block),(half_block));
    circle((x-(3*block)+half_block),(y+(5*block)),(half_block),(half_block));

    glColor3f(r1,g1,b1);
    circle((x-(2*block)),(y+(7*block)+half_block),(2*block)-half_block,(2*block)-half_block);
    circle((x+(1*block)+half_block),(y+(6*block)),(2*block)-half_block,(2*block)-half_block);
    circle((x),(y+(6*block)),(2*block)-half_block,(2*block)-half_block);
    circle((x+(2*block)+half_block),(y+(8*block)),(1*block),(1*block));
    circle((x+(1*block)),(y+(7*block)),(2*block)-half_block,(2*block)-half_block);
    circle(x-block,(y+(9*block)-half_block),(2*block)-half_block,(2*block)-half_block);
    circle(x+block,(y+(9*block)+half_block),(2*block)-half_block,(2*block)-half_block);


    glBegin(GL_TRIANGLES);
    glColor3f(r3,g3,b3);
    glVertex2f(x , (y+(8*block)));
    glVertex2f((x-half_block) ,y);
    glVertex2f((x+half_block) ,y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((x-(2*block)), (y+(4*block)));
    glVertex2f(x , (y+(3*block)-half_block));
    glVertex2f(x , (y+(2*block)-half_block));
    glEnd();
}


void mountain1(){

    glBegin(GL_POLYGON);
    glVertex2f(0,425);glVertex2f(0,641);glVertex2f(27,639);glVertex2f(35,639);glVertex2f(44,635);glVertex2f(153,615);
    glVertex2f(166,610);glVertex2f(174,607);glVertex2f(214,623);glVertex2f(259,646);glVertex2f(275,653);glVertex2f(295,662);
    glVertex2f(309,668);glVertex2f(313,669);glVertex2f(321,670);glVertex2f(331,668);glVertex2f(346,666);glVertex2f(359,662);
    glVertex2f(365,659);glVertex2f(374,657);glVertex2f(380,654);glVertex2f(387,651);glVertex2f(391,649);glVertex2f(401,657);
    glVertex2f(410,664);glVertex2f(421,672);glVertex2f(437,683);glVertex2f(455,696);glVertex2f(471,708);glVertex2f(491,721);
    glVertex2f(507,730);glVertex2f(523,738);glVertex2f(530,739);glVertex2f(540,736);glVertex2f(553,724);glVertex2f(564,714);
    glVertex2f(579,703);glVertex2f(597,689);glVertex2f(611,678);glVertex2f(620,667);glVertex2f(628,657);glVertex2f(631,658);
    glVertex2f(635,656);glVertex2f(640,652);glVertex2f(644,650);glVertex2f(652,647);glVertex2f(655,646);glVertex2f(658,644);
    glVertex2f(664,643);glVertex2f(669,643);glVertex2f(677,644);glVertex2f(683,648);glVertex2f(690,654);glVertex2f(705,663);
    glVertex2f(716,671);glVertex2f(725,677);glVertex2f(734,683);glVertex2f(745,691);glVertex2f(755,698);glVertex2f(764,704);
    glVertex2f(778,715);glVertex2f(788,723);glVertex2f(799,731);glVertex2f(808,735);glVertex2f(817,743);glVertex2f(821,742);
    glVertex2f(833,737);glVertex2f(837,736);glVertex2f(842,733);glVertex2f(848,730);glVertex2f(853,727);glVertex2f(859,724);
    glVertex2f(864,720);glVertex2f(870,716);glVertex2f(876,714);glVertex2f(880,712);glVertex2f(884,711);glVertex2f(891,711);
    glVertex2f(897,713);glVertex2f(902,717);glVertex2f(907,720);glVertex2f(910,724);glVertex2f(916,729);glVertex2f(932,741);
    glVertex2f(950,753);glVertex2f(971,768);glVertex2f(991,785);glVertex2f(1014,799);glVertex2f(1026,807);glVertex2f(1039,814);
    glVertex2f(1052,822);glVertex2f(1062,826);glVertex2f(1069,829);glVertex2f(1032,811);glVertex2f(1043,817);glVertex2f(1050,821);
    glVertex2f(1060,825);glVertex2f(1067,828);glVertex2f(1074,830);glVertex2f(1116,814);glVertex2f(1131,803);glVertex2f(1145,792);
    glVertex2f(1164,785);glVertex2f(1205,764);glVertex2f(1234,751);glVertex2f(1265,740);glVertex2f(1285,726);glVertex2f(1293,720);
    glVertex2f(1323,729);glVertex2f(1345,737);glVertex2f(1366,743);glVertex2f(1375,745);glVertex2f(1401,733);glVertex2f(1419,716);
    glVertex2f(1438,704);glVertex2f(1455,694);glVertex2f(1467,689);glVertex2f(1476,678);glVertex2f(1478,676);glVertex2f(1498,688);
    glVertex2f(1518,699);glVertex2f(1536,708);glVertex2f(1633,664);glVertex2f(1671,648);glVertex2f(1682,645);glVertex2f(1815,592);
    glVertex2f(1884,610);glVertex2f(1920,425);
    glEnd();
}


void mountain1_shadow_1(){

    glBegin(GL_POLYGON);
    glVertex2f(630,657);glVertex2f(629,656);glVertex2f(629,653);glVertex2f(630,650);glVertex2f(631,647);glVertex2f(633,644);
    glVertex2f(634,641);glVertex2f(637,637);glVertex2f(639,635);glVertex2f(640,632);glVertex2f(642,630);glVertex2f(643,628);
    glVertex2f(642,625);glVertex2f(639,625);glVertex2f(635,625);glVertex2f(632,626);glVertex2f(627,627);glVertex2f(623,628);
    glVertex2f(620,630);glVertex2f(616,631);glVertex2f(612,633);glVertex2f(608,635);glVertex2f(605,637);glVertex2f(601,640);
    glVertex2f(596,642);glVertex2f(593,644);glVertex2f(590,646);glVertex2f(587,647);glVertex2f(586,650);glVertex2f(588,651);
    glVertex2f(591,651);glVertex2f(594,649);glVertex2f(597,647);glVertex2f(601,647);glVertex2f(605,648);glVertex2f(605,650);
    glVertex2f(602,653);glVertex2f(600,657);glVertex2f(596,660);glVertex2f(593,664);glVertex2f(589,667);glVertex2f(584,669);
    glVertex2f(581,672);glVertex2f(575,674);glVertex2f(577,676);glVertex2f(581,678);glVertex2f(581,680);glVertex2f(578,682);
    glVertex2f(575,683);glVertex2f(571,685);glVertex2f(567,687);glVertex2f(561,690);glVertex2f(558,693);glVertex2f(554,696);
    glVertex2f(550,699);glVertex2f(547,702);glVertex2f(545,705);glVertex2f(545,708);glVertex2f(546,711);glVertex2f(546,713);
    glVertex2f(544,716);glVertex2f(541,718);glVertex2f(538,722);glVertex2f(536,724);glVertex2f(537,728);glVertex2f(535,732);
    glVertex2f(533,736);glVertex2f(530,739);glVertex2f(540,736);glVertex2f(553,724);glVertex2f(564,714);glVertex2f(579,703);
    glVertex2f(597,689);glVertex2f(611,678);glVertex2f(620,667);glVertex2f(628,657);
    glEnd();
}


void mountain1_shadow_2(){

    glBegin(GL_POLYGON);
    glVertex2f(1279,722);glVertex2f(1273,721);glVertex2f(1268,719);glVertex2f(1265,716);glVertex2f(1261,713);glVertex2f(1256,709);
    glVertex2f(1255,703);glVertex2f(1257,698);glVertex2f(1263,695);glVertex2f(1268,692);glVertex2f(1271,690);glVertex2f(1276,687);
    glVertex2f(1284,682);glVertex2f(1288,678);glVertex2f(1294,674);glVertex2f(1302,670);glVertex2f(1299,668);glVertex2f(1290,670);
    glVertex2f(1278,675);glVertex2f(1269,679);glVertex2f(1259,685);glVertex2f(1250,689);glVertex2f(1240,694);glVertex2f(1230,699);
    glVertex2f(1222,704);glVertex2f(1214,709);glVertex2f(1207,713);glVertex2f(1201,714);glVertex2f(1195,712);glVertex2f(1187,707);
    glVertex2f(1182,703);glVertex2f(1176,698);glVertex2f(1170,696);glVertex2f(1162,701);glVertex2f(1160,707);glVertex2f(1156,712);
    glVertex2f(1152,718);glVertex2f(1149,725);glVertex2f(1142,732);glVertex2f(1137,735);glVertex2f(1131,739);glVertex2f(1128,746);
    glVertex2f(1127,747);glVertex2f(1127,754);glVertex2f(1124,763);glVertex2f(1120,766);glVertex2f(1118,767);glVertex2f(1120,769);
    glVertex2f(1122,773);glVertex2f(1122,778);glVertex2f(1119,784);glVertex2f(1115,789);glVertex2f(1111,794);glVertex2f(1108,799);
    glVertex2f(1102,803);glVertex2f(1096,809);glVertex2f(1093,814);glVertex2f(1087,819);glVertex2f(1082,824);glVertex2f(1076,829);
    glVertex2f(1074,830);glVertex2f(1116,814);glVertex2f(1131,803);glVertex2f(1145,792);glVertex2f(1164,785);glVertex2f(1205,764);
    glVertex2f(1234,751);glVertex2f(1265,740);glVertex2f(1285,726);
    glEnd();
}

void mountain1_shadow_3() {

    glBegin(GL_POLYGON);
    glVertex2f(1469,673);glVertex2f(1468,676);glVertex2f(1465,676);glVertex2f(1461,676);glVertex2f(1457,675);glVertex2f(1455,673);
    glVertex2f(1456,670);glVertex2f(1457,668);glVertex2f(1459,666);glVertex2f(1460,664);glVertex2f(1461,661);glVertex2f(1461,660);
    glVertex2f(1459,659);glVertex2f(1456,660);glVertex2f(1453,662);glVertex2f(1450,664);glVertex2f(1447,666);glVertex2f(1443,668);
    glVertex2f(1438,670);glVertex2f(1434,672);glVertex2f(1430,675);glVertex2f(1425,678);glVertex2f(1422,680);glVertex2f(1420,684);
    glVertex2f(1422,687);glVertex2f(1419,691);glVertex2f(1411,691);glVertex2f(1409,692);glVertex2f(1405,693);glVertex2f(1402,695);
    glVertex2f(1399,697);glVertex2f(1397,699);glVertex2f(1395,701);glVertex2f(1395,703);glVertex2f(1394,705);glVertex2f(1394,706);
    glVertex2f(1396,707);glVertex2f(1398,707);glVertex2f(1402,706);glVertex2f(1405,706);glVertex2f(1406,707);glVertex2f(1407,708);
    glVertex2f(1405,710);glVertex2f(1395,720);glVertex2f(1393,721);glVertex2f(1391,722);glVertex2f(1390,722);glVertex2f(1388,722);
    glVertex2f(1386,723);glVertex2f(1385,724);glVertex2f(1384,726);glVertex2f(1382,727);glVertex2f(1380,728);glVertex2f(1378,729);
    glVertex2f(1376,729);glVertex2f(1374,730);glVertex2f(1373,731);glVertex2f(1372,732);glVertex2f(1371,734);glVertex2f(1372,735);
    glVertex2f(1374,736);glVertex2f(1376,735);glVertex2f(1378,735);glVertex2f(1379,735);glVertex2f(1381,734);glVertex2f(1382,735);
    glVertex2f(1382,737);glVertex2f(1380,739);glVertex2f(1375,745);glVertex2f(1401,733);glVertex2f(1419,716);glVertex2f(1438,704);
    glVertex2f(1455,694);
    glEnd();
}


void mountain2() {

    glBegin(GL_POLYGON);
    glVertex2f(0,639);glVertex2f(38,635);glVertex2f(47,633);glVertex2f(70,639);glVertex2f(81,634);glVertex2f(114,645);
    glVertex2f(119,642);glVertex2f(156,659);glVertex2f(193,638);glVertex2f(199,636);glVertex2f(218,620);glVertex2f(229,613);
    glVertex2f(237,610);glVertex2f(243,607);glVertex2f(254,609);glVertex2f(280,611);glVertex2f(296,610);glVertex2f(304,610);
    glVertex2f(315,604);glVertex2f(327,597);glVertex2f(347,589);glVertex2f(373,581);glVertex2f(407,578);glVertex2f(439,577);
    glVertex2f(463,591);glVertex2f(472,596);glVertex2f(482,598);glVertex2f(487,599);glVertex2f(507,597);glVertex2f(551,600);
    glVertex2f(564,605);glVertex2f(575,600);glVertex2f(596,590);glVertex2f(613,583);glVertex2f(655,578);glVertex2f(662,576);
    glVertex2f(686,565);glVertex2f(748,537);glVertex2f(769,532);glVertex2f(793,534);glVertex2f(821,519);glVertex2f(845,513);
    glVertex2f(881,503);glVertex2f(900,425);glVertex2f(0,425);
    glEnd();
}

void mountain3() {

    //glBegin(GL_POLYGON);
    //glVertex2f(1920,425);
    glVertex2f(0,425);glVertex2f(0,427);glVertex2f(40,431);glVertex2f(74,436);glVertex2f(141,448);
    glVertex2f(189,450);glVertex2f(249,455);glVertex2f(321,465);glVertex2f(404,484);glVertex2f(439,488);glVertex2f(465,491);
    glVertex2f(491,496);glVertex2f(516,498);glVertex2f(612,493);glVertex2f(637,485);glVertex2f(649,482);glVertex2f(670,480);glVertex2f(693,482);
    glVertex2f(722,485);glVertex2f(734,487);glVertex2f(770,491);glVertex2f(808,498);glVertex2f(829,499);glVertex2f(847,503);
    glVertex2f(865,509);glVertex2f(881,512);glVertex2f(892,516);glVertex2f(906,514);glVertex2f(919,510);glVertex2f(942,506);
    glVertex2f(956,503);glVertex2f(978,500);glVertex2f(987,502);glVertex2f(996,506);glVertex2f(1004,511);glVertex2f(1025,516);
    glVertex2f(1043,517);glVertex2f(1063,519);glVertex2f(1082,519);glVertex2f(1090,525);glVertex2f(1104,531);glVertex2f(1111,539);
    glVertex2f(1126,545);glVertex2f(1140,551);glVertex2f(1152,551);glVertex2f(1164,551);glVertex2f(1176,549);glVertex2f(1186,551);
    glVertex2f(1196,553);glVertex2f(1211,556);glVertex2f(1220,562);glVertex2f(1229,566);glVertex2f(1239,569);glVertex2f(1255,573);
    glVertex2f(1269,577);glVertex2f(1281,582);glVertex2f(1289,587);glVertex2f(1305,599);glVertex2f(1330,609);glVertex2f(1442,604);
    glVertex2f(1457,602);glVertex2f(1468,599);glVertex2f(1479,598);glVertex2f(1491,600);glVertex2f(1505,604);glVertex2f(1518,608);
    glVertex2f(1527,611);glVertex2f(1547,610);glVertex2f(1563,611);glVertex2f(1584,615);glVertex2f(1597,618);glVertex2f(1609,620);
    glVertex2f(1620,622);glVertex2f(1641,629);glVertex2f(1654,634);glVertex2f(1665,635);glVertex2f(1673,640);glVertex2f(1685,645);
    glVertex2f(1696,645);glVertex2f(1709,645);glVertex2f(1725,642);glVertex2f(1735,638);glVertex2f(1746,636);glVertex2f(1761,632);
    glVertex2f(1777,628);glVertex2f(1791,628);glVertex2f(1800,629);glVertex2f(1811,633);glVertex2f(1819,635);glVertex2f(1826,636);
    glVertex2f(1842,636);glVertex2f(1851,634);glVertex2f(1862,634);glVertex2f(1870,634);glVertex2f(1880,636);glVertex2f(1890,638);
    glVertex2f(1899,640);glVertex2f(1908,644);glVertex2f(1920,640);
    glVertex2f(1920,425);glVertex2f(1668, 425);
    //glEnd();
}

void mountain_front_land() {

    //glBegin(GL_POLYGON);
    glVertex2f(1100, 430);
    glVertex2f(1668, 425);glVertex2f(1641, 419);glVertex2f(1633, 419);glVertex2f(1621, 418);glVertex2f(1611, 418);
    glVertex2f(1579, 418);glVertex2f(1569, 418);glVertex2f(1558, 418);glVertex2f(1550, 420);glVertex2f(1542, 420);glVertex2f(1528, 420);
    glVertex2f(1516, 420);glVertex2f(1504, 418);glVertex2f(1495, 415);glVertex2f(1480, 415);glVertex2f(1474, 415);glVertex2f(1455, 415);
    glVertex2f(1440, 415);glVertex2f(1427, 416);glVertex2f(1420, 417);glVertex2f(1395, 419);glVertex2f(1386, 419);glVertex2f(1374, 419);
    glVertex2f(1364, 419);glVertex2f(1351, 417);glVertex2f(1340, 417);glVertex2f(1333, 417);glVertex2f(1318, 417);glVertex2f(1304, 417);
    glVertex2f(1288, 417);glVertex2f(1266, 417);glVertex2f(1250, 417);glVertex2f(1231, 418);glVertex2f(1212, 418);glVertex2f(1188, 418);
    glVertex2f(1172, 418);glVertex2f(1154, 420);glVertex2f(1123, 421);glVertex2f(1099, 421);glVertex2f(1090, 421);glVertex2f(1079, 420);
    glVertex2f(1067, 419);glVertex2f(1053, 417);glVertex2f(1043, 417);glVertex2f(1035, 417);glVertex2f(1018, 419);glVertex2f(996, 418);
    glVertex2f(983, 418);glVertex2f(970, 418);glVertex2f(951, 416);glVertex2f(939, 416);glVertex2f(925, 417);glVertex2f(909, 416);
    glVertex2f(882, 417);glVertex2f(870, 420);glVertex2f(861, 420);glVertex2f(809, 420);glVertex2f(795, 419);glVertex2f(780, 418);
    glVertex2f(767, 418);glVertex2f(754, 418);glVertex2f(741, 419);glVertex2f(703, 421);glVertex2f(691, 419);glVertex2f(672, 419);
    glVertex2f(661, 419);glVertex2f(650, 419);glVertex2f(635, 419);glVertex2f(615, 417);glVertex2f(604, 418);glVertex2f(590, 420);
    glVertex2f(563, 421);glVertex2f(549, 420);glVertex2f(536, 420);glVertex2f(525, 419);glVertex2f(504, 417);glVertex2f(493, 419);
    glVertex2f(471, 418);glVertex2f(457, 418);glVertex2f(442, 417);glVertex2f(423, 418);glVertex2f(397, 418);glVertex2f(374, 417);
    glVertex2f(354, 415);glVertex2f(332, 415);glVertex2f(310, 415);glVertex2f(288, 416);glVertex2f(272, 419);glVertex2f(255, 420);
    glVertex2f(238, 419);glVertex2f(223, 418);glVertex2f(208, 417);glVertex2f(194, 417);glVertex2f(176, 417);glVertex2f(165, 417);
    glVertex2f(153, 418);glVertex2f(135, 419);glVertex2f(124, 420);glVertex2f(89, 421);glVertex2f(72, 417);glVertex2f(63, 417);
    glVertex2f(54, 417);glVertex2f(44, 419);glVertex2f(35, 419);glVertex2f(25, 418);glVertex2f(17, 415);glVertex2f(14, 414);
    glVertex2f(0, 420);
    //glEnd();
}

void mountain4() {

    glBegin(GL_POLYGON);
    glVertex2f(1668,425);glVertex2f(1668,429);glVertex2f(1668,434);glVertex2f(1669,441);glVertex2f(1668,448);glVertex2f(1668,456);
    glVertex2f(1670,466);glVertex2f(1671,474);glVertex2f(1673,479);glVertex2f(1674,480);glVertex2f(1675,482);glVertex2f(1676,484);
    glVertex2f(1676,487);glVertex2f(1677,492);glVertex2f(1679,504);glVertex2f(1679,506);glVertex2f(1679,508);glVertex2f(1679,509);
    glVertex2f(1680,511);glVertex2f(1680,512);glVertex2f(1685,524);glVertex2f(1685,525);glVertex2f(1685,526);glVertex2f(1685,527);
    glVertex2f(1690,537);glVertex2f(1690,538);glVertex2f(1690,539);glVertex2f(1691,540);glVertex2f(1696,543);glVertex2f(1701,547);
    glVertex2f(1704,549);glVertex2f(1708,551);glVertex2f(1709,553);glVertex2f(1710,555);glVertex2f(1713,560);glVertex2f(1715,565);
    glVertex2f(1718,570);glVertex2f(1723,581);glVertex2f(1727,584);glVertex2f(1732,586);glVertex2f(1738,589);glVertex2f(1742,591);
    glVertex2f(1745,592);glVertex2f(1749,594);glVertex2f(1751,595);glVertex2f(1753,594);glVertex2f(1754,594);glVertex2f(1755,594);
    glVertex2f(1757,595);glVertex2f(1758,595);glVertex2f(1763,602);glVertex2f(1764,605);glVertex2f(1769,605);glVertex2f(1770,606);
    glVertex2f(1772,607);glVertex2f(1774,608);glVertex2f(1775,609);glVertex2f(1775,610);glVertex2f(1778,619);glVertex2f(1780,624);
    glVertex2f(1780,625);glVertex2f(1785,626);glVertex2f(1788,626);glVertex2f(1791,625);glVertex2f(1794,624);glVertex2f(1797,623);
    glVertex2f(1803,622);glVertex2f(1807,621);glVertex2f(1809,620);glVertex2f(1812,621);glVertex2f(1816,623);glVertex2f(1817,623);
    glVertex2f(1817,624);glVertex2f(1820,629);glVertex2f(1823,632);glVertex2f(1826,636);glVertex2f(1829,642);glVertex2f(1835,655);
    glVertex2f(1837,657);glVertex2f(1842,667);glVertex2f(1845,670);glVertex2f(1847,671);glVertex2f(1851,671);glVertex2f(1855,671);
    glVertex2f(1857,673);glVertex2f(1859,676);glVertex2f(1860,681);glVertex2f(1862,684);glVertex2f(1866,686);glVertex2f(1875,687);
    glVertex2f(1882,688);glVertex2f(1889,691);glVertex2f(1896,695);glVertex2f(1901,700);glVertex2f(1907,709);glVertex2f(1914,717);
    glVertex2f(1920,724);glVertex2f(1920,425);
    glEnd();
}

void water() {

    glVertex2f(0,425);glVertex2f(1920,425);glVertex2f(1920,300);glVertex2f(0,300);
    glEnd();
}

waterfall_with_shade_1() {

    glVertex2f(1725,425);glVertex2f(1725,426);glVertex2f(1725,428);glVertex2f(1726,431);glVertex2f(1726,434);glVertex2f(1727,439);
    glVertex2f(1728,444);glVertex2f(1728,446);glVertex2f(1729,449);glVertex2f(1730,457);glVertex2f(1731,465);glVertex2f(1733,475);
    glVertex2f(1734,486);glVertex2f(1735,492);glVertex2f(1738,510);glVertex2f(1739,515);glVertex2f(1741,525);glVertex2f(1742,536);
    glVertex2f(1745,552);glVertex2f(1747,562);glVertex2f(1748,572);glVertex2f(1749,574);glVertex2f(1750,575);glVertex2f(1752,575);
    glVertex2f(1754,576);glVertex2f(1755,577);glVertex2f(1754,581);glVertex2f(1754,587);glVertex2f(1755,591);glVertex2f(1754,594);
    glVertex2f(1756,594);glVertex2f(1757,595);glVertex2f(1758,595);glVertex2f(1759,592);glVertex2f(1760,588);glVertex2f(1760,584);
    glVertex2f(1759,580);glVertex2f(1759,577);glVertex2f(1758,575);glVertex2f(1756,574);glVertex2f(1754,573);glVertex2f(1752,572);
    glVertex2f(1752,571);glVertex2f(1752,567);glVertex2f(1752,565);glVertex2f(1752,555);glVertex2f(1753,547);glVertex2f(1754,535);
    glVertex2f(1755,503);glVertex2f(1757,485);glVertex2f(1757,465);glVertex2f(1759,454);glVertex2f(1759,444);glVertex2f(1760,436);
    glVertex2f(1760,430);glVertex2f(1760,425);
}

waterfall_with_shade_2() {

    glVertex2f(1760,425);glVertex2f(1760,430);glVertex2f(1760,436);glVertex2f(1759,444);glVertex2f(1759,454);glVertex2f(1757,465);
    glVertex2f(1757,485);glVertex2f(1755,503);glVertex2f(1754,535);glVertex2f(1753,547);glVertex2f(1752,555);glVertex2f(1752,565);
    glVertex2f(1752,567);glVertex2f(1752,571);glVertex2f(1752,572);glVertex2f(1754,573);glVertex2f(1756,574);glVertex2f(1758,575);
    glVertex2f(1759,577);glVertex2f(1759,580);glVertex2f(1760,584);glVertex2f(1760,588);glVertex2f(1759,592);glVertex2f(1758,595);
    glVertex2f(1757,595);glVertex2f(1756,594);glVertex2f(1754,594);glVertex2f(1755,591);glVertex2f(1754,587);glVertex2f(1754,581);
    glVertex2f(1755,577);glVertex2f(1754,576);glVertex2f(1752,575);glVertex2f(1750,575);glVertex2f(1749,574);glVertex2f(1748,572);
    glVertex2f(1747,562);glVertex2f(1745,552);glVertex2f(1742,536);glVertex2f(1741,525);glVertex2f(1739,515);glVertex2f(1738,510);
    glVertex2f(1735,492);glVertex2f(1734,486);glVertex2f(1733,475);glVertex2f(1731,465);glVertex2f(1730,457);glVertex2f(1729,449);
    glVertex2f(1728,446);glVertex2f(1728,444);glVertex2f(1727,439);glVertex2f(1726,434);glVertex2f(1726,431);glVertex2f(1725,428);
    glVertex2f(1725,426);glVertex2f(1725,425);

    glEnd();
}

void water_shade1() {

    glVertex2f(1139,362);glVertex2f(1148,367);glVertex2f(1329,368);glVertex2f(1398,368);glVertex2f(1514,369);glVertex2f(1517,366);
    glVertex2f(1635,366);glVertex2f(1661,366);glVertex2f(1717,366);glVertex2f(1719,365);glVertex2f(1719,364);glVertex2f(1717,362);
    glVertex2f(1713,361);glVertex2f(1623,359);glVertex2f(1302,359);glVertex2f(1278,361);glVertex2f(1251,361);glVertex2f(1212,362);
    glVertex2f(1182,362);glVertex2f(1160,362);glVertex2f(1145,361);glVertex2f(1141,362);

    glEnd();
}

void water_shade2() {

    glVertex2f(303,346);glVertex2f(304,347);glVertex2f(304,347);glVertex2f(304,347);glVertex2f(305,347);glVertex2f(306,348);
    glVertex2f(376,348);glVertex2f(377,348);glVertex2f(378,348);glVertex2f(378,347);glVertex2f(379,347);glVertex2f(380,347);
    glVertex2f(382,347);glVertex2f(383,347);glVertex2f(565,347);glVertex2f(317,340);glVertex2f(316,341);glVertex2f(315,341);
    glVertex2f(314,341);glVertex2f(313,341);glVertex2f(312,342);glVertex2f(311,342);glVertex2f(310,342);glVertex2f(309,342);
    glVertex2f(308,343);glVertex2f(307,343);glVertex2f(306,343);glVertex2f(305,344);glVertex2f(304,344);glVertex2f(304,345);
    glVertex2f(303,345);glVertex2f(303,346);

    glEnd();
}

void water_shade3() {

    glVertex2f(1678,381);glVertex2f(1679,382);glVertex2f(1679,382);glVertex2f(1679,382);glVertex2f(1680,382);glVertex2f(1681,383);
    glVertex2f(1751,383);glVertex2f(1752,383);glVertex2f(1753,383);glVertex2f(1753,382);glVertex2f(1754,382);glVertex2f(1755,382);
    glVertex2f(1757,382);glVertex2f(1758,382);glVertex2f(1940,382);glVertex2f(1692,375);glVertex2f(1691,376);glVertex2f(1690,376);
    glVertex2f(1689,376);glVertex2f(1688,376);glVertex2f(1687,377);glVertex2f(1686,377);glVertex2f(1685,377);glVertex2f(1684,377);
    glVertex2f(1683,378);glVertex2f(1682,378);glVertex2f(1681,378);glVertex2f(1680,379);glVertex2f(1679,379);glVertex2f(1679,380);
    glVertex2f(1678,380);glVertex2f(1678,381);
    glEnd();
}

void water_shade4() {

    glVertex2f(78,377);glVertex2f(78,377);glVertex2f(78,377);glVertex2f(82,372);glVertex2f(83,372);glVertex2f(86,372);
    glVertex2f(89,371);glVertex2f(91,371);glVertex2f(99,370);glVertex2f(221,373);glVertex2f(532,377);glVertex2f(532,377);
    glVertex2f(488,373);glVertex2f(507,373);glVertex2f(513,372);glVertex2f(521,372);glVertex2f(528,372);glVertex2f(531,373);
    glVertex2f(532,377);glVertex2f(532,377);glVertex2f(532,377);glVertex2f(516,377);glVertex2f(532,377);glVertex2f(532,377);
    glVertex2f(78,377);glVertex2f(78,377);glVertex2f(78,377);

    glEnd();
}

void water_shade5() {

    glVertex2f(1027,394);glVertex2f(1027,394);glVertex2f(1023,394);glVertex2f(1021,398);glVertex2f(1019,399);glVertex2f(1015,399);
    glVertex2f(1005,399);glVertex2f(998,399);glVertex2f(937,398);glVertex2f(1027,394);glVertex2f(1027,394);glVertex2f(1027,394);
    glVertex2f(596,394);glVertex2f(596,394);glVertex2f(596,394);glVertex2f(596,394);glVertex2f(596,394);glVertex2f(596,394);
    glVertex2f(601,390);glVertex2f(604,389);glVertex2f(606,389);glVertex2f(596,394);glVertex2f(1027,394);glVertex2f(1027,394);
    glVertex2f(1027,394);

    glEnd();
}

void water_shade6() {

    glVertex2f(1115,403);glVertex2f(1126,403);glVertex2f(1126,403);glVertex2f(1365,403);glVertex2f(1365,403);glVertex2f(1365,403);
    glVertex2f(1365,403);glVertex2f(1365,403);glVertex2f(1365,403);glVertex2f(1365,403);glVertex2f(1365,397);glVertex2f(1354,397);
    glVertex2f(1126,403);glVertex2f(1126,403);glVertex2f(1126,403);glVertex2f(1126,403);

    glEnd();
}

void big_tree_root_with_shade1() {

    glVertex2f(0,367);glVertex2f(4,365);glVertex2f(4,363);glVertex2f(4,358);glVertex2f(4,354);glVertex2f(4,350);
    glVertex2f(4,346);glVertex2f(4,342);glVertex2f(4,337);glVertex2f(5,334);glVertex2f(6,330);glVertex2f(7,326);
    glVertex2f(9,322);glVertex2f(11,319);glVertex2f(15,315);glVertex2f(17,312);glVertex2f(21,307);glVertex2f(21,309);
    glVertex2f(24,314);glVertex2f(26,320);glVertex2f(27,324);glVertex2f(29,328);glVertex2f(30,333);glVertex2f(31,338);
    glVertex2f(32,342);glVertex2f(32,348);glVertex2f(33,357);glVertex2f(62,358);glVertex2f(63,350);glVertex2f(63,344);
    glVertex2f(63,338);glVertex2f(63,334);glVertex2f(63,328);glVertex2f(63,323);glVertex2f(64,320);glVertex2f(64,314);
    glVertex2f(65,309);glVertex2f(67,307);glVertex2f(68,307);glVertex2f(73,308);glVertex2f(76,312);glVertex2f(79,316);
    glVertex2f(83,320);glVertex2f(87,327);glVertex2f(90,334);glVertex2f(94,340);glVertex2f(96,344);glVertex2f(98,350);
    glVertex2f(100,355);glVertex2f(110,363);glVertex2f(183,358);glVertex2f(178,355);glVertex2f(173,352);glVertex2f(166,347);
    glVertex2f(160,343);glVertex2f(156,339);glVertex2f(152,335);glVertex2f(149,331);glVertex2f(143,326);glVertex2f(140,323);
    glVertex2f(137,319);glVertex2f(136,317);glVertex2f(137,316);glVertex2f(137,314);glVertex2f(139,313);glVertex2f(144,314);
    glVertex2f(151,315);glVertex2f(159,316);glVertex2f(167,318);glVertex2f(171,319);glVertex2f(177,322);glVertex2f(182,324);
    glVertex2f(187,325);glVertex2f(191,327);glVertex2f(199,329);glVertex2f(204,329);glVertex2f(220,328);glVertex2f(228,329);
    glVertex2f(236,328);

}

void big_tree_root_with_shade2() {

    glVertex2f(230,292);glVertex2f(225,293);glVertex2f(219,293);glVertex2f(213,292);glVertex2f(209,293);glVertex2f(201,293);
    glVertex2f(194,291);glVertex2f(188,289);glVertex2f(183,286);glVertex2f(177,283);glVertex2f(173,281);glVertex2f(170,279);
    glVertex2f(167,277);glVertex2f(163,276);glVertex2f(158,276);glVertex2f(153,276);glVertex2f(147,275);glVertex2f(140,274);
    glVertex2f(138,274);glVertex2f(133,275);glVertex2f(129,275);glVertex2f(125,276);glVertex2f(123,275);glVertex2f(120,273);
    glVertex2f(119,271);glVertex2f(117,269);glVertex2f(117,269);glVertex2f(114,267);glVertex2f(111,264);glVertex2f(109,260);
    glVertex2f(106,255);glVertex2f(104,250);glVertex2f(102,245);glVertex2f(101,241);glVertex2f(99,238);glVertex2f(96,235);
    glVertex2f(94,231);glVertex2f(93,224);glVertex2f(93,219);glVertex2f(93,214);glVertex2f(94,209);glVertex2f(95,204);
    glVertex2f(96,200);glVertex2f(95,196);glVertex2f(95,191);glVertex2f(94,186);glVertex2f(96,178);glVertex2f(96,172);
    glVertex2f(97,167);glVertex2f(97,161);glVertex2f(97,156);glVertex2f(98,151);glVertex2f(99,148);glVertex2f(102,145);
    glVertex2f(104,144);glVertex2f(102,146);glVertex2f(104,144);glVertex2f(106,142);glVertex2f(107,139);glVertex2f(109,135);
    glVertex2f(109,133);glVertex2f(111,131);glVertex2f(119,131);glVertex2f(125,129);glVertex2f(131,127);glVertex2f(135,124);
    glVertex2f(139,119);glVertex2f(140,115);glVertex2f(143,110);glVertex2f(146,106);glVertex2f(150,102);glVertex2f(156,97);
    glVertex2f(161,94);glVertex2f(169,90);glVertex2f(174,86);glVertex2f(177,83);glVertex2f(179,79);glVertex2f(180,75);
    glVertex2f(173,71);glVertex2f(165,68);glVertex2f(157,69);glVertex2f(151,69);glVertex2f(145,70);glVertex2f(136,69);
    glVertex2f(128,72);glVertex2f(120,76);glVertex2f(114,77);glVertex2f(106,79);glVertex2f(101,80);glVertex2f(96,81);
    glVertex2f(94,79);glVertex2f(95,76);glVertex2f(95,73);glVertex2f(90,70);glVertex2f(85,69);glVertex2f(83,65);
    glVertex2f(81,63);glVertex2f(78,59);glVertex2f(75,58);glVertex2f(73,56);glVertex2f(71,56);glVertex2f(67,58);
    glVertex2f(64,61);glVertex2f(60,66);glVertex2f(57,71);glVertex2f(54,76);glVertex2f(51,81);glVertex2f(49,82);
    glVertex2f(47,81);glVertex2f(45,80);glVertex2f(41,78);glVertex2f(39,74);glVertex2f(35,70);glVertex2f(33,65);
    glVertex2f(30,60);glVertex2f(27,57);glVertex2f(23,55);glVertex2f(19,54);glVertex2f(16,56);glVertex2f(13,59);
    glVertex2f(9,61);glVertex2f(6,62);glVertex2f(3,61);glVertex2f(0,59);

    glEnd();
}

void tree_leaf4() {

    glVertex2f(307,372);glVertex2f(304,282);glVertex2f(307,282);glVertex2f(308,281);glVertex2f(310,279);glVertex2f(312,277);
    glVertex2f(314,277);glVertex2f(318,277);glVertex2f(320,276);glVertex2f(323,275);glVertex2f(327,275);glVertex2f(330,275);
    glVertex2f(335,278);glVertex2f(338,278);glVertex2f(342,281);glVertex2f(343,283);glVertex2f(345,286);glVertex2f(347,287);
    glVertex2f(349,287);glVertex2f(353,284);glVertex2f(357,284);glVertex2f(364,282);glVertex2f(368,281);glVertex2f(376,281);
    glVertex2f(384,284);glVertex2f(392,286);glVertex2f(396,288);glVertex2f(402,290);glVertex2f(411,296);glVertex2f(416,299);
    glVertex2f(419,303);glVertex2f(422,308);glVertex2f(423,314);glVertex2f(428,319);glVertex2f(430,325);glVertex2f(434,334);
    glVertex2f(437,342);glVertex2f(437,348);glVertex2f(436,350);glVertex2f(435,352);glVertex2f(434,354);glVertex2f(431,358);
    glVertex2f(429,364);glVertex2f(429,370);glVertex2f(428,376);glVertex2f(424,384);glVertex2f(422,391);glVertex2f(418,396);
    glVertex2f(414,398);glVertex2f(406,398);glVertex2f(403,398);glVertex2f(400,398);glVertex2f(397,400);glVertex2f(397,402);
    glVertex2f(398,407);glVertex2f(396,411);glVertex2f(394,415);glVertex2f(390,420);glVertex2f(388,423);glVertex2f(387,427);
    glVertex2f(385,431);glVertex2f(383,435);glVertex2f(380,439);glVertex2f(375,444);glVertex2f(373,447);glVertex2f(369,451);
    glVertex2f(367,454);glVertex2f(363,457);glVertex2f(357,460);glVertex2f(350,463);glVertex2f(342,467);glVertex2f(333,468);
    glVertex2f(327,471);glVertex2f(319,471);glVertex2f(312,477);glVertex2f(309,480);glVertex2f(305,483);glVertex2f(300,486);
    glVertex2f(293,488);glVertex2f(283,488);glVertex2f(274,488);glVertex2f(269,486);glVertex2f(264,484);glVertex2f(259,480);
    glVertex2f(256,475);glVertex2f(257,471);glVertex2f(257,468);glVertex2f(251,465);glVertex2f(244,461);glVertex2f(240,453);
    glVertex2f(237,444);glVertex2f(235,439);glVertex2f(235,434);glVertex2f(233,426);glVertex2f(229,419);glVertex2f(224,413);
    glVertex2f(215,407);glVertex2f(214,404);glVertex2f(213,401);glVertex2f(210,394);glVertex2f(211,394);glVertex2f(209,389);
    glVertex2f(213,381);glVertex2f(213,377);glVertex2f(215,372);glVertex2f(215,368);glVertex2f(212,364);glVertex2f(209,360);
    glVertex2f(207,356);glVertex2f(206,351);glVertex2f(207,344);glVertex2f(211,339);glVertex2f(214,334);glVertex2f(216,329);
    glVertex2f(218,324);glVertex2f(217,318);glVertex2f(215,311);glVertex2f(215,305);glVertex2f(216,296);glVertex2f(219,287);
    glVertex2f(219,282);glVertex2f(221,278);glVertex2f(224,276);glVertex2f(225,275);glVertex2f(231,274);glVertex2f(234,272);
    glVertex2f(240,270);glVertex2f(244,270);glVertex2f(248,269);glVertex2f(256,269);glVertex2f(260,269);glVertex2f(269,267);
    glVertex2f(277,267);glVertex2f(280,269);glVertex2f(283,270);glVertex2f(286,274);glVertex2f(289,274);glVertex2f(292,275);
    glVertex2f(297,277);glVertex2f(300,278);glVertex2f(303,279);glVertex2f(305,280);glVertex2f(307,282);

    glEnd();
}

void tree_leaf3() {

    glVertex2f(5,482);glVertex2f(-8,360);glVertex2f(-2,359);glVertex2f(-2,359);glVertex2f(3,357);glVertex2f(8,354);
    glVertex2f(13,352);glVertex2f(15,351);glVertex2f(19,349);glVertex2f(29,344);glVertex2f(33,342);glVertex2f(41,340);
    glVertex2f(45,340);glVertex2f(52,339);glVertex2f(59,339);glVertex2f(65,343);glVertex2f(72,346);glVertex2f(80,346);
    glVertex2f(84,346);glVertex2f(89,343);glVertex2f(97,340);glVertex2f(102,338);glVertex2f(107,336);glVertex2f(116,336);
    glVertex2f(125,338);glVertex2f(134,342);glVertex2f(141,347);glVertex2f(147,352);glVertex2f(153,356);glVertex2f(157,358);
    glVertex2f(165,355);glVertex2f(170,352);glVertex2f(175,351);glVertex2f(183,351);glVertex2f(192,354);glVertex2f(200,356);
    glVertex2f(207,359);glVertex2f(211,371);glVertex2f(211,381);glVertex2f(211,389);glVertex2f(211,396);glVertex2f(214,404);
    glVertex2f(218,411);glVertex2f(223,419);glVertex2f(230,426);glVertex2f(234,431);glVertex2f(237,436);glVertex2f(238,443);
    glVertex2f(238,449);glVertex2f(236,456);glVertex2f(234,464);glVertex2f(230,471);glVertex2f(227,479);glVertex2f(223,489);
    glVertex2f(220,498);glVertex2f(217,507);glVertex2f(211,516);glVertex2f(203,523);glVertex2f(193,531);glVertex2f(187,538);
    glVertex2f(183,545);glVertex2f(178,553);glVertex2f(162,558);glVertex2f(146,563);glVertex2f(135,569);glVertex2f(126,575);
    glVertex2f(118,582);glVertex2f(110,589);glVertex2f(99,595);glVertex2f(94,598);glVertex2f(81,602);glVertex2f(66,602);
    glVertex2f(57,600);glVertex2f(52,598);glVertex2f(42,599);glVertex2f(34,606);glVertex2f(21,611);glVertex2f(4,614);
    glVertex2f(-14,614);glVertex2f(-24,619);glVertex2f(-39,621);glVertex2f(-70,618);glVertex2f(-77,610);glVertex2f(-81,605);
    glVertex2f(-87,597);glVertex2f(-91,592);glVertex2f(-96,580);glVertex2f(-104,576);glVertex2f(-116,572);glVertex2f(-130,568);
    glVertex2f(-141,558);glVertex2f(-142,555);glVertex2f(-144,548);glVertex2f(-147,543);glVertex2f(-163,538);glVertex2f(-167,530);
    glVertex2f(-171,521);glVertex2f(-176,515);glVertex2f(-175,504);glVertex2f(-182,495);glVertex2f(-187,489);glVertex2f(-185,483);
    glVertex2f(-189,477);glVertex2f(-192,471);glVertex2f(-196,466);glVertex2f(-197,460);glVertex2f(-199,454);glVertex2f(-199,447);
    glVertex2f(-199,440);glVertex2f(-201,433);glVertex2f(-202,424);glVertex2f(-199,414);glVertex2f(-200,405);glVertex2f(-204,397);
    glVertex2f(-204,386);glVertex2f(-199,374);glVertex2f(-191,362);glVertex2f(-189,357);glVertex2f(-179,352);glVertex2f(-173,349);
    glVertex2f(-164,346);glVertex2f(-159,346);glVertex2f(-146,346);glVertex2f(-139,344);glVertex2f(-129,341);glVertex2f(-113,336);
    glVertex2f(-102,331);glVertex2f(-94,328);glVertex2f(-82,328);glVertex2f(-69,331);glVertex2f(-62,333);glVertex2f(-52,338);
    glVertex2f(-48,337);glVertex2f(-43,337);glVertex2f(-37,336);glVertex2f(-28,338);glVertex2f(-21,342);glVertex2f(-15,343);
    glVertex2f(-12,346);glVertex2f(-9,349);glVertex2f(-5,352);glVertex2f(-2,355);glVertex2f(-2,361);

    glEnd();
}

void tree_leaf2() {

    glVertex2f(94,450);glVertex2f(17,600);glVertex2f(15,606);glVertex2f(17,620);glVertex2f(17,625);glVertex2f(18,631);
    glVertex2f(19,642);glVertex2f(21,655);glVertex2f(29,668);glVertex2f(36,663);glVertex2f(42,668);glVertex2f(48,678);
    glVertex2f(52,684);glVertex2f(58,687);glVertex2f(65,688);glVertex2f(76,684);glVertex2f(82,677);glVertex2f(86,673);
    glVertex2f(98,677);glVertex2f(98,690);glVertex2f(105,698);glVertex2f(111,701);glVertex2f(121,708);glVertex2f(132,708);
    glVertex2f(145,709);glVertex2f(155,710);glVertex2f(157,710);glVertex2f(172,704);glVertex2f(178,695);glVertex2f(193,688);
    glVertex2f(203,689);glVertex2f(212,692);glVertex2f(218,692);glVertex2f(228,688);glVertex2f(235,680);glVertex2f(239,673);
    glVertex2f(244,667);glVertex2f(253,664);glVertex2f(262,651);glVertex2f(265,646);glVertex2f(274,644);glVertex2f(283,639);
    glVertex2f(288,635);glVertex2f(288,619);glVertex2f(294,610);glVertex2f(301,606);glVertex2f(307,603);glVertex2f(308,594);
    glVertex2f(307,586);glVertex2f(303,579);glVertex2f(311,571);glVertex2f(320,566);glVertex2f(325,547);glVertex2f(322,536);
    glVertex2f(325,519);glVertex2f(323,504);glVertex2f(318,492);glVertex2f(313,487);glVertex2f(308,481);glVertex2f(300,481);
    glVertex2f(280,464);glVertex2f(273,459);glVertex2f(276,438);glVertex2f(274,436);glVertex2f(271,419);glVertex2f(261,378);
    glVertex2f(231,366);

    glEnd();
}

void tree_leaf1() {

    glVertex2f(3,600);glVertex2f(0,600);glVertex2f(3,599);glVertex2f(4,597);glVertex2f(6,595);glVertex2f(8,595);
    glVertex2f(10,595);glVertex2f(14,594);glVertex2f(16,593);glVertex2f(19,593);glVertex2f(23,593);glVertex2f(26,596);
    glVertex2f(31,596);glVertex2f(34,599);glVertex2f(38,601);glVertex2f(39,604);glVertex2f(41,605);glVertex2f(43,605);
    glVertex2f(45,602);glVertex2f(49,602);glVertex2f(53,600);glVertex2f(60,599);glVertex2f(64,599);glVertex2f(72,602);
    glVertex2f(80,604);glVertex2f(88,606);glVertex2f(92,608);glVertex2f(98,614);glVertex2f(107,617);glVertex2f(112,621);
    glVertex2f(115,626);glVertex2f(118,632);glVertex2f(119,637);glVertex2f(124,643);glVertex2f(126,652);glVertex2f(130,660);
    glVertex2f(133,666);glVertex2f(133,668);glVertex2f(132,670);glVertex2f(131,672);glVertex2f(130,676);glVertex2f(127,682);
    glVertex2f(125,688);glVertex2f(125,694);glVertex2f(124,702);glVertex2f(120,709);glVertex2f(118,714);glVertex2f(114,716);
    glVertex2f(110,716);glVertex2f(102,716);glVertex2f(99,716);glVertex2f(96,718);glVertex2f(93,720);glVertex2f(93,725);
    glVertex2f(94,729);glVertex2f(92,733);glVertex2f(90,738);glVertex2f(86,741);glVertex2f(84,745);glVertex2f(83,749);
    glVertex2f(81,753);glVertex2f(79,757);glVertex2f(76,762);glVertex2f(71,765);glVertex2f(69,769);glVertex2f(65,772);
    glVertex2f(63,775);glVertex2f(59,778);glVertex2f(53,781);glVertex2f(46,785);glVertex2f(38,786);glVertex2f(29,789);
    glVertex2f(23,789);glVertex2f(15,795);glVertex2f(8,798);glVertex2f(5,801);glVertex2f(1,804);glVertex2f(-4,806);
    glVertex2f(-11,806);glVertex2f(-21,806);glVertex2f(-30,804);glVertex2f(-35,802);glVertex2f(-40,798);glVertex2f(-45,793);
    glVertex2f(-48,789);glVertex2f(-47,786);glVertex2f(-47,783);glVertex2f(-53,779);glVertex2f(-60,771);glVertex2f(-64,762);
    glVertex2f(-67,757);glVertex2f(-69,752);glVertex2f(-69,744);glVertex2f(-71,737);glVertex2f(-75,731);glVertex2f(-80,725);
    glVertex2f(-89,722);glVertex2f(-90,719);glVertex2f(-91,712);glVertex2f(-94,712);glVertex2f(-93,707);glVertex2f(-95,699);
    glVertex2f(-91,695);glVertex2f(-91,690);glVertex2f(-89,686);glVertex2f(-89,682);glVertex2f(-92,678);glVertex2f(-95,674);
    glVertex2f(-97,669);glVertex2f(-98,662);glVertex2f(-97,657);glVertex2f(-93,652);glVertex2f(-90,647);glVertex2f(-88,642);
    glVertex2f(-86,636);glVertex2f(-87,629);glVertex2f(-89,623);glVertex2f(-89,614);glVertex2f(-88,605);glVertex2f(-85,600);
    glVertex2f(-85,596);glVertex2f(-83,594);glVertex2f(-80,593);glVertex2f(-79,592);glVertex2f(-73,590);glVertex2f(-70,588);
    glVertex2f(-64,588);glVertex2f(-60,587);glVertex2f(-56,587);glVertex2f(-48,587);glVertex2f(-44,585);glVertex2f(-35,585);
    glVertex2f(-27,587);glVertex2f(-24,588);glVertex2f(-21,592);glVertex2f(-18,592);glVertex2f(-15,593);glVertex2f(-12,595);
    glVertex2f(-7,596);glVertex2f(-4,597);glVertex2f(-1,598);glVertex2f(1,600);

    glEnd();
}

void bamboo_raft() {

    glVertex2f(1860,337);glVertex2f(1797,325);glVertex2f(1797,325);glVertex2f(1796,325);glVertex2f(1796,326);glVertex2f(1796,326);
    glVertex2f(1796,327);glVertex2f(1796,327);glVertex2f(1796,328);glVertex2f(1796,328);glVertex2f(1796,329);glVertex2f(1796,329);
    glVertex2f(1796,329);glVertex2f(1796,330);glVertex2f(1797,330);glVertex2f(1797,330);glVertex2f(1797,330);glVertex2f(1797,331);
    glVertex2f(1797,331);glVertex2f(1797,331);glVertex2f(1797,332);glVertex2f(1798,332);glVertex2f(1798,333);glVertex2f(1798,333);
    glVertex2f(1799,333);glVertex2f(1799,333);glVertex2f(1799,334);glVertex2f(1799,334);glVertex2f(1799,334);glVertex2f(1799,335);
    glVertex2f(1799,335);glVertex2f(1799,335);glVertex2f(1800,336);glVertex2f(1800,336);glVertex2f(1800,336);glVertex2f(1800,336);
    glVertex2f(1801,337);glVertex2f(1800,337);glVertex2f(1801,338);glVertex2f(1801,339);glVertex2f(1802,339);glVertex2f(1802,340);
    glVertex2f(1802,340);glVertex2f(1802,340);glVertex2f(1802,341);glVertex2f(1803,341);glVertex2f(1803,341);glVertex2f(1803,342);
    glVertex2f(1804,342);glVertex2f(1804,343);glVertex2f(1804,343);glVertex2f(1804,344);glVertex2f(1804,344);glVertex2f(1804,345);
    glVertex2f(1805,345);glVertex2f(1805,345);glVertex2f(1805,345);glVertex2f(1806,345);glVertex2f(1914,347);glVertex2f(1915,347);
    glVertex2f(1915,347);glVertex2f(1915,346);glVertex2f(1915,346);glVertex2f(1916,345);glVertex2f(1916,345);glVertex2f(1915,344);
    glVertex2f(1915,344);glVertex2f(1916,343);glVertex2f(1917,343);glVertex2f(1917,342);glVertex2f(1917,342);glVertex2f(1917,342);
    glVertex2f(1917,341);glVertex2f(1917,341);glVertex2f(1917,341);glVertex2f(1917,341);glVertex2f(1917,341);glVertex2f(1918,340);
    glVertex2f(1918,340);glVertex2f(1918,339);glVertex2f(1918,339);glVertex2f(1918,339);glVertex2f(1917,338);glVertex2f(1918,338);
    glVertex2f(1918,338);glVertex2f(1918,337);glVertex2f(1918,337);glVertex2f(1918,337);glVertex2f(1918,336);glVertex2f(1919,336);
    glVertex2f(1919,335);glVertex2f(1919,335);glVertex2f(1918,335);glVertex2f(1918,335);glVertex2f(1919,334);glVertex2f(1919,334);
    glVertex2f(1919,334);glVertex2f(1920,333);glVertex2f(1920,333);glVertex2f(1920,332);glVertex2f(1920,332);glVertex2f(1919,332);
    glVertex2f(1920,332);glVertex2f(1920,331);glVertex2f(1920,331);glVertex2f(1920,330);glVertex2f(1920,330);glVertex2f(1920,329);
    glVertex2f(1921,329);glVertex2f(1921,329);glVertex2f(1921,328);glVertex2f(1920,327);glVertex2f(1920,327);glVertex2f(1920,327);
    glVertex2f(1920,327);glVertex2f(1797,325);

    glEnd();
}

void human() {

    glVertex2f(1844,362);glVertex2f(1844,350);glVertex2f(1843,350);glVertex2f(1843,350);glVertex2f(1843,349);glVertex2f(1842,349);
    glVertex2f(1842,348);glVertex2f(1841,347);glVertex2f(1841,347);glVertex2f(1840,346);glVertex2f(1840,345);glVertex2f(1839,345);
    glVertex2f(1838,345);glVertex2f(1838,345);glVertex2f(1838,344);glVertex2f(1838,343);glVertex2f(1838,342);glVertex2f(1838,341);
    glVertex2f(1838,340);glVertex2f(1838,339);glVertex2f(1838,338);glVertex2f(1838,337);glVertex2f(1837,337);glVertex2f(1836,337);
    glVertex2f(1836,336);glVertex2f(1834,336);glVertex2f(1834,336);glVertex2f(1834,337);glVertex2f(1834,338);glVertex2f(1834,339);
    glVertex2f(1834,341);glVertex2f(1834,342);glVertex2f(1834,343);glVertex2f(1833,345);glVertex2f(1833,345);glVertex2f(1832,346);
    glVertex2f(1832,347);glVertex2f(1832,348);glVertex2f(1832,350);glVertex2f(1833,351);glVertex2f(1834,353);glVertex2f(1835,354);
    glVertex2f(1836,356);glVertex2f(1836,357);glVertex2f(1836,358);glVertex2f(1836,359);glVertex2f(1836,360);glVertex2f(1836,362);
    glVertex2f(1835,363);glVertex2f(1835,364);glVertex2f(1834,365);glVertex2f(1833,366);glVertex2f(1832,367);glVertex2f(1831,368);
    glVertex2f(1830,369);glVertex2f(1829,370);glVertex2f(1828,371);glVertex2f(1827,372);glVertex2f(1826,374);glVertex2f(1825,375);
    glVertex2f(1824,377);glVertex2f(1824,378);glVertex2f(1823,379);glVertex2f(1823,380);glVertex2f(1824,381);glVertex2f(1825,382);
    glVertex2f(1825,382);glVertex2f(1826,382);glVertex2f(1827,381);glVertex2f(1828,381);glVertex2f(1829,379);glVertex2f(1829,377);
    glVertex2f(1830,376);glVertex2f(1832,375);glVertex2f(1832,374);glVertex2f(1833,372);glVertex2f(1834,372);glVertex2f(1834,373);
    glVertex2f(1833,374);glVertex2f(1832,376);glVertex2f(1832,378);glVertex2f(1832,379);glVertex2f(1832,381);glVertex2f(1833,382);
    glVertex2f(1834,385);glVertex2f(1835,385);glVertex2f(1835,386);glVertex2f(1837,386);glVertex2f(1838,387);glVertex2f(1839,387);
    glVertex2f(1840,388);glVertex2f(1842,388);glVertex2f(1843,388);glVertex2f(1844,388);glVertex2f(1845,388);glVertex2f(1847,388);
    glVertex2f(1847,387);glVertex2f(1848,387);glVertex2f(1849,386);glVertex2f(1850,385);glVertex2f(1851,384);glVertex2f(1852,383);
    glVertex2f(1852,382);glVertex2f(1853,381);glVertex2f(1853,380);glVertex2f(1853,378);glVertex2f(1853,377);glVertex2f(1853,375);
    glVertex2f(1852,374);glVertex2f(1852,373);glVertex2f(1851,372);glVertex2f(1850,372);glVertex2f(1848,371);glVertex2f(1847,371);
    glVertex2f(1847,370);glVertex2f(1846,370);glVertex2f(1845,370);glVertex2f(1846,370);glVertex2f(1846,370);glVertex2f(1848,369);
    glVertex2f(1849,369);glVertex2f(1851,368);glVertex2f(1851,367);glVertex2f(1852,366);glVertex2f(1853,367);glVertex2f(1853,367);
    glVertex2f(1853,368);glVertex2f(1853,368);glVertex2f(1853,369);glVertex2f(1854,371);glVertex2f(1855,371);glVertex2f(1855,370);
    glVertex2f(1855,369);glVertex2f(1856,367);glVertex2f(1856,366);glVertex2f(1856,365);glVertex2f(1856,364);glVertex2f(1855,363);
    glVertex2f(1854,362);glVertex2f(1853,362);glVertex2f(1851,362);glVertex2f(1851,363);glVertex2f(1850,363);glVertex2f(1851,362);
    glVertex2f(1851,361);glVertex2f(1851,360);glVertex2f(1851,359);glVertex2f(1851,357);glVertex2f(1851,356);glVertex2f(1853,355);
    glVertex2f(1854,354);glVertex2f(1854,353);glVertex2f(1855,352);glVertex2f(1856,351);glVertex2f(1856,350);glVertex2f(1857,349);
    glVertex2f(1857,348);glVertex2f(1856,347);glVertex2f(1856,346);glVertex2f(1855,345);glVertex2f(1856,344);glVertex2f(1855,343);
    glVertex2f(1856,342);glVertex2f(1856,340);glVertex2f(1856,339);glVertex2f(1856,338);glVertex2f(1857,338);glVertex2f(1856,337);
    glVertex2f(1855,337);glVertex2f(1854,336);glVertex2f(1853,336);glVertex2f(1853,337);glVertex2f(1852,337);glVertex2f(1852,339);
    glVertex2f(1852,341);glVertex2f(1851,343);glVertex2f(1851,344);glVertex2f(1851,345);glVertex2f(1850,345);glVertex2f(1849,346);
    glVertex2f(1849,347);glVertex2f(1848,349);glVertex2f(1847,349);glVertex2f(1846,350);glVertex2f(1845,350);glVertex2f(1844,350);

    glEnd();
}

void human_dress() {

    glVertex2f(1844,354);glVertex2f(1844,354);glVertex2f(1844,350);glVertex2f(1844,350);glVertex2f(1843,350);glVertex2f(1843,349);
    glVertex2f(1842,349);glVertex2f(1842,348);glVertex2f(1842,348);glVertex2f(1841,347);glVertex2f(1841,346);glVertex2f(1840,346);
    glVertex2f(1840,345);glVertex2f(1839,345);glVertex2f(1838,345);glVertex2f(1837,345);glVertex2f(1836,345);glVertex2f(1835,345);
    glVertex2f(1834,345);glVertex2f(1833,345);glVertex2f(1833,345);glVertex2f(1832,345);glVertex2f(1832,346);glVertex2f(1832,346);
    glVertex2f(1832,347);glVertex2f(1832,348);glVertex2f(1832,349);glVertex2f(1832,350);glVertex2f(1832,350);glVertex2f(1833,351);
    glVertex2f(1833,352);glVertex2f(1833,352);glVertex2f(1834,353);glVertex2f(1834,354);glVertex2f(1835,355);glVertex2f(1835,355);
    glVertex2f(1835,356);glVertex2f(1836,356);glVertex2f(1836,357);glVertex2f(1836,357);glVertex2f(1836,357);glVertex2f(1837,356);
    glVertex2f(1838,356);glVertex2f(1838,356);glVertex2f(1839,356);glVertex2f(1840,355);glVertex2f(1841,355);glVertex2f(1843,355);
    glVertex2f(1844,355);glVertex2f(1846,355);glVertex2f(1847,356);glVertex2f(1848,356);glVertex2f(1850,356);glVertex2f(1850,356);
    glVertex2f(1851,356);glVertex2f(1851,357);glVertex2f(1851,357);glVertex2f(1852,356);glVertex2f(1853,356);glVertex2f(1853,355);
    glVertex2f(1854,355);glVertex2f(1854,354);glVertex2f(1855,354);glVertex2f(1855,353);glVertex2f(1856,351);glVertex2f(1856,350);
    glVertex2f(1857,350);glVertex2f(1857,349);glVertex2f(1857,348);glVertex2f(1856,347);glVertex2f(1856,346);glVertex2f(1855,345);
    glVertex2f(1855,345);glVertex2f(1854,345);glVertex2f(1852,344);glVertex2f(1851,344);glVertex2f(1850,345);glVertex2f(1850,345);
    glVertex2f(1849,346);glVertex2f(1849,347);glVertex2f(1849,348);glVertex2f(1848,348);glVertex2f(1847,349);glVertex2f(1847,350);
    glVertex2f(1846,350);glVertex2f(1845,350);glVertex2f(1844,350);

    glEnd();
}

void human_head() {

    glVertex2f(1847,385);glVertex2f(1844,370);glVertex2f(1844,371);glVertex2f(1844,372);glVertex2f(1844,373);glVertex2f(1844,375);
    glVertex2f(1843,377);glVertex2f(1843,377);glVertex2f(1844,378);glVertex2f(1845,379);glVertex2f(1845,379);glVertex2f(1844,379);
    glVertex2f(1843,380);glVertex2f(1843,380);glVertex2f(1842,381);glVertex2f(1842,382);glVertex2f(1841,383);glVertex2f(1840,383);
    glVertex2f(1839,384);glVertex2f(1838,385);glVertex2f(1836,385);glVertex2f(1836,385);glVertex2f(1835,386);glVertex2f(1836,386);
    glVertex2f(1837,387);glVertex2f(1838,387);glVertex2f(1839,388);glVertex2f(1840,388);glVertex2f(1841,388);glVertex2f(1842,388);
    glVertex2f(1842,389);glVertex2f(1843,388);glVertex2f(1844,388);glVertex2f(1845,388);glVertex2f(1846,388);glVertex2f(1847,388);
    glVertex2f(1848,388);glVertex2f(1849,388);glVertex2f(1849,387);glVertex2f(1850,387);glVertex2f(1851,386);glVertex2f(1852,385);
    glVertex2f(1852,384);glVertex2f(1853,383);glVertex2f(1853,382);glVertex2f(1853,381);glVertex2f(1853,380);glVertex2f(1854,378);
    glVertex2f(1854,376);glVertex2f(1853,375);glVertex2f(1853,373);glVertex2f(1852,372);glVertex2f(1850,371);glVertex2f(1848,371);
    glVertex2f(1848,371);glVertex2f(1846,370);glVertex2f(1845,370);glVertex2f(1844,370);glVertex2f(1843,370);

    glEnd();
}

void plane() {

    glVertex2f(1888,897);glVertex2f(1888,900);glVertex2f(1888,900);glVertex2f(1890,901);glVertex2f(1894,903);glVertex2f(1895,905);
    glVertex2f(1896,905);glVertex2f(1897,905);glVertex2f(1898,905);glVertex2f(1899,905);glVertex2f(1899,904);glVertex2f(1898,903);
    glVertex2f(1898,901);glVertex2f(1897,900);glVertex2f(1897,900);glVertex2f(1898,899);glVertex2f(1900,899);glVertex2f(1901,900);
    glVertex2f(1920,902);glVertex2f(1920,902);glVertex2f(1920,901);glVertex2f(1919,901);glVertex2f(1915,895);glVertex2f(1914,895);
    glVertex2f(1913,895);glVertex2f(1913,894);glVertex2f(1911,894);glVertex2f(1899,895);glVertex2f(1899,895);glVertex2f(1898,895);
    glVertex2f(1897,894);glVertex2f(1897,893);glVertex2f(1898,891);glVertex2f(1898,888);glVertex2f(1898,887);glVertex2f(1898,887);
    glVertex2f(1898,886);glVertex2f(1897,886);glVertex2f(1896,886);glVertex2f(1895,887);glVertex2f(1894,887);glVertex2f(1886,894);
    glVertex2f(1885,894);glVertex2f(1885,894);glVertex2f(1884,895);glVertex2f(1882,895);glVertex2f(1866,896);glVertex2f(1865,896);
    glVertex2f(1864,896);glVertex2f(1863,896);glVertex2f(1862,897);glVertex2f(1861,897);glVertex2f(1861,897);glVertex2f(1861,898);
    glVertex2f(1861,898);glVertex2f(1862,898);glVertex2f(1862,899);glVertex2f(1863,899);glVertex2f(1863,899);glVertex2f(1864,900);
    glVertex2f(1865,900);glVertex2f(1865,900);glVertex2f(1865,901);glVertex2f(1866,901);glVertex2f(1866,901);glVertex2f(1867,901);
    glVertex2f(1868,901);glVertex2f(1868,901);glVertex2f(1869,901);glVertex2f(1870,901);glVertex2f(1875,901);glVertex2f(1886,901);
    glVertex2f(1889,902);

    glEnd();
}

void land_shade() {

    glBegin(GL_POLYGON);
    glVertex2f(864,59);glVertex2f(830,53);glVertex2f(798,57);glVertex2f(768,61);glVertex2f(742,63);glVertex2f(718,67);
    glVertex2f(704,69);glVertex2f(702,69);glVertex2f(704,75);glVertex2f(734,79);glVertex2f(750,77);glVertex2f(770,79);
    glVertex2f(796,79);glVertex2f(816,79);glVertex2f(844,81);glVertex2f(886,81);glVertex2f(922,79);glVertex2f(968,79);
    glVertex2f(996,75);glVertex2f(1032,75);glVertex2f(1056,73);glVertex2f(1068,73);glVertex2f(1072,73);glVertex2f(1076,73);
    glVertex2f(1078,71);glVertex2f(1078,69);glVertex2f(1072,67);glVertex2f(1058,67);glVertex2f(1044,65);glVertex2f(1002,63);
    glVertex2f(968,63);glVertex2f(950,61);glVertex2f(930,61);glVertex2f(918,61);glVertex2f(904,61);glVertex2f(900,61);
    glVertex2f(898,57);glVertex2f(910,57);glVertex2f(930,57);glVertex2f(952,55);glVertex2f(964,53);glVertex2f(986,53);
    glVertex2f(1002,51);glVertex2f(1016,49);glVertex2f(1030,49);glVertex2f(1034,47);glVertex2f(1024,45);glVertex2f(1002,43);
    glVertex2f(984,39);glVertex2f(968,37);glVertex2f(946,35);glVertex2f(932,35);glVertex2f(912,35);glVertex2f(896,35);
    glVertex2f(870,35);glVertex2f(854,35);glVertex2f(830,35);glVertex2f(810,35);glVertex2f(804,39);glVertex2f(802,43);
    glVertex2f(810,45);glVertex2f(820,47);glVertex2f(824,49);glVertex2f(828,51);glVertex2f(828,55);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(949,247);glVertex2f(932,244);glVertex2f(916,246);glVertex2f(901,248);glVertex2f(888,249);glVertex2f(876,251);
    glVertex2f(869,252);glVertex2f(868,252);glVertex2f(869,255);glVertex2f(884,257);glVertex2f(892,256);glVertex2f(902,257);
    glVertex2f(915,257);glVertex2f(925,257);glVertex2f(939,258);glVertex2f(960,258);glVertex2f(978,257);glVertex2f(1001,257);
    glVertex2f(1015,255);glVertex2f(1033,255);glVertex2f(1045,254);glVertex2f(1051,254);glVertex2f(1053,254);glVertex2f(1055,254);
    glVertex2f(1056,253);glVertex2f(1056,252);glVertex2f(1053,251);glVertex2f(1046,251);glVertex2f(1039,250);glVertex2f(1018,249);
    glVertex2f(1001,249);glVertex2f(992,248);glVertex2f(982,248);glVertex2f(976,248);glVertex2f(969,248);glVertex2f(967,248);
    glVertex2f(966,246);glVertex2f(972,246);glVertex2f(982,246);glVertex2f(993,245);glVertex2f(999,244);glVertex2f(1010,244);
    glVertex2f(1018,243);glVertex2f(1025,242);glVertex2f(1032,242);glVertex2f(1034,241);glVertex2f(1029,240);glVertex2f(1018,239);
    glVertex2f(1009,237);glVertex2f(1001,236);glVertex2f(990,235);glVertex2f(983,235);glVertex2f(973,235);glVertex2f(965,235);
    glVertex2f(952,235);glVertex2f(944,235);glVertex2f(932,235);glVertex2f(922,235);glVertex2f(919,237);glVertex2f(918,239);
    glVertex2f(922,240);glVertex2f(927,241);glVertex2f(929,242);glVertex2f(931,243);glVertex2f(931,245);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(599,227);glVertex2f(582,224);glVertex2f(566,226);glVertex2f(551,228);glVertex2f(538,229);glVertex2f(526,231);
    glVertex2f(519,232);glVertex2f(518,232);glVertex2f(519,235);glVertex2f(534,237);glVertex2f(542,236);glVertex2f(552,237);
    glVertex2f(565,237);glVertex2f(575,237);glVertex2f(589,238);glVertex2f(610,238);glVertex2f(628,237);glVertex2f(651,237);
    glVertex2f(665,235);glVertex2f(683,235);glVertex2f(695,234);glVertex2f(701,234);glVertex2f(703,234);glVertex2f(705,234);
    glVertex2f(706,233);glVertex2f(706,232);glVertex2f(703,231);glVertex2f(696,231);glVertex2f(689,230);glVertex2f(668,229);
    glVertex2f(651,229);glVertex2f(642,228);glVertex2f(632,228);glVertex2f(626,228);glVertex2f(619,228);glVertex2f(617,228);
    glVertex2f(616,226);glVertex2f(622,226);glVertex2f(632,226);glVertex2f(643,225);glVertex2f(649,224);glVertex2f(660,224);
    glVertex2f(668,223);glVertex2f(675,222);glVertex2f(682,222);glVertex2f(684,221);glVertex2f(679,220);glVertex2f(668,219);
    glVertex2f(659,217);glVertex2f(651,216);glVertex2f(640,215);glVertex2f(633,215);glVertex2f(623,215);glVertex2f(615,215);
    glVertex2f(602,215);glVertex2f(594,215);glVertex2f(582,215);glVertex2f(572,215);glVertex2f(569,217);glVertex2f(568,219);
    glVertex2f(572,220);glVertex2f(577,221);glVertex2f(579,222);glVertex2f(581,223);glVertex2f(581,225);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(406,100);glVertex2f(537,110);glVertex2f(537,108);glVertex2f(539,105);glVertex2f(542,104);glVertex2f(544,104);
    glVertex2f(546,104);glVertex2f(549,106);glVertex2f(553,106);glVertex2f(558,105);glVertex2f(563,104);glVertex2f(566,104);
    glVertex2f(569,102);glVertex2f(571,100);glVertex2f(574,98);glVertex2f(577,97);glVertex2f(580,94);glVertex2f(580,93);
    glVertex2f(580,91);glVertex2f(579,89);glVertex2f(575,87);glVertex2f(572,85);glVertex2f(569,83);glVertex2f(564,81);
    glVertex2f(560,80);glVertex2f(551,80);glVertex2f(547,79);glVertex2f(545,79);glVertex2f(541,77);glVertex2f(541,75);
    glVertex2f(542,73);glVertex2f(543,71);glVertex2f(545,71);glVertex2f(550,71);glVertex2f(557,70);glVertex2f(561,69);
    glVertex2f(564,67);glVertex2f(566,64);glVertex2f(566,61);glVertex2f(563,57);glVertex2f(557,54);glVertex2f(550,52);
    glVertex2f(543,51);glVertex2f(530,51);glVertex2f(524,50);glVertex2f(508,47);glVertex2f(498,47);glVertex2f(485,46);
    glVertex2f(473,45);glVertex2f(462,44);glVertex2f(449,42);glVertex2f(435,40);glVertex2f(416,38);glVertex2f(402,37);
    glVertex2f(387,36);glVertex2f(368,36);glVertex2f(351,36);glVertex2f(331,38);glVertex2f(313,40);glVertex2f(300,41);
    glVertex2f(287,43);glVertex2f(278,46);glVertex2f(257,49);glVertex2f(245,51);glVertex2f(239,54);glVertex2f(237,58);
    glVertex2f(241,62);glVertex2f(246,63);glVertex2f(249,65);glVertex2f(251,68);glVertex2f(247,71);glVertex2f(231,71);
    glVertex2f(219,72);glVertex2f(199,72);glVertex2f(186,72);glVertex2f(173,73);glVertex2f(165,75);glVertex2f(157,78);
    glVertex2f(146,80);glVertex2f(137,83);glVertex2f(135,85);glVertex2f(134,86);glVertex2f(134,89);glVertex2f(134,90);
    glVertex2f(135,92);glVertex2f(137,94);glVertex2f(139,97);glVertex2f(142,98);glVertex2f(145,100);glVertex2f(151,103);
    glVertex2f(155,104);glVertex2f(158,105);glVertex2f(162,106);glVertex2f(165,107);glVertex2f(172,108);glVertex2f(176,109);
    glVertex2f(185,111);glVertex2f(189,111);glVertex2f(192,112);glVertex2f(197,112);glVertex2f(203,113);glVertex2f(207,113);
    glVertex2f(213,114);glVertex2f(216,114);glVertex2f(219,115);glVertex2f(225,116);glVertex2f(231,117);glVertex2f(239,117);
    glVertex2f(243,119);glVertex2f(251,119);glVertex2f(259,119);glVertex2f(264,120);glVertex2f(269,120);glVertex2f(274,122);
    glVertex2f(283,122);glVertex2f(288,122);glVertex2f(292,123);glVertex2f(297,123);glVertex2f(307,123);glVertex2f(319,124);
    glVertex2f(328,124);glVertex2f(338,124);glVertex2f(354,124);glVertex2f(364,123);glVertex2f(377,123);glVertex2f(386,123);
    glVertex2f(396,123);glVertex2f(407,123);glVertex2f(422,123);glVertex2f(430,123);glVertex2f(444,123);glVertex2f(456,121);
    glVertex2f(470,118);glVertex2f(481,118);glVertex2f(499,116);glVertex2f(511,116);glVertex2f(519,116);glVertex2f(525,114);
    glVertex2f(531,113);glVertex2f(540,111);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1143,270);glVertex2f(1250,274);glVertex2f(1252,272);glVertex2f(1252,269);glVertex2f(1252,267);glVertex2f(1247,265);
    glVertex2f(1242,264);glVertex2f(1235,262);glVertex2f(1234,256);glVertex2f(1218,255);glVertex2f(1212,255);glVertex2f(1205,253);
    glVertex2f(1187,251);glVertex2f(1172,250);glVertex2f(1162,247);glVertex2f(1151,247);glVertex2f(1142,247);glVertex2f(1132,247);
    glVertex2f(1124,247);glVertex2f(1113,247);glVertex2f(1109,249);glVertex2f(1107,250);glVertex2f(1109,252);glVertex2f(1115,253);
    glVertex2f(1120,255);glVertex2f(1124,257);glVertex2f(1119,258);glVertex2f(1112,258);glVertex2f(1105,258);glVertex2f(1099,259);
    glVertex2f(1092,260);glVertex2f(1089,261);glVertex2f(1098,266);glVertex2f(1101,267);glVertex2f(1108,268);glVertex2f(1118,268);
    glVertex2f(1126,271);glVertex2f(1131,272);glVertex2f(1138,274);glVertex2f(1147,274);glVertex2f(1154,275);glVertex2f(1164,275);
    glVertex2f(1175,277);glVertex2f(1181,277);glVertex2f(1192,277);glVertex2f(1201,277);glVertex2f(1212,277);glVertex2f(1250,274);
    glEnd();

}

void fire1(){

    glBegin(GL_POLYGON);
    glVertex2f(673, 154);glVertex2f(673, 140);glVertex2f(671, 141);glVertex2f(668, 142);glVertex2f(666, 145);glVertex2f(664, 147);
    glVertex2f(662, 150);glVertex2f(659, 155);glVertex2f(659, 157);glVertex2f(658, 159);glVertex2f(658, 163);glVertex2f(659, 166);
    glVertex2f(660, 170);glVertex2f(661, 173);glVertex2f(662, 175);glVertex2f(663, 176);glVertex2f(665, 175);glVertex2f(667, 174);
    glVertex2f(669, 173);glVertex2f(670, 173);glVertex2f(671, 174);glVertex2f(671, 175);glVertex2f(670, 176);glVertex2f(669, 178);
    glVertex2f(668, 180);glVertex2f(668, 182);glVertex2f(668, 184);glVertex2f(669, 185);glVertex2f(669, 186);glVertex2f(670, 187);
    glVertex2f(670, 188);glVertex2f(671, 188);glVertex2f(673, 189);glVertex2f(674, 190);glVertex2f(675, 190);glVertex2f(676, 191);
    glVertex2f(676, 191);glVertex2f(676, 190);glVertex2f(676, 188);glVertex2f(676, 188);glVertex2f(676, 187);glVertex2f(676, 186);
    glVertex2f(676, 186);glVertex2f(676, 185);glVertex2f(677, 185);glVertex2f(678, 185);glVertex2f(679, 186);glVertex2f(679, 187);
    glVertex2f(680, 187);glVertex2f(681, 189);glVertex2f(682, 191);glVertex2f(682, 193);glVertex2f(682, 194);glVertex2f(683, 196);
    glVertex2f(683, 198);glVertex2f(684, 198);glVertex2f(685, 197);glVertex2f(686, 196);glVertex2f(687, 195);glVertex2f(687, 194);
    glVertex2f(688, 193);glVertex2f(689, 192);glVertex2f(690, 190);glVertex2f(690, 189);glVertex2f(691, 188);glVertex2f(691, 187);
    glVertex2f(691, 186);glVertex2f(691, 185);glVertex2f(692, 185);glVertex2f(692, 184);glVertex2f(693, 184);glVertex2f(693, 184);
    glVertex2f(694, 185);glVertex2f(695, 185);glVertex2f(696, 186);glVertex2f(697, 188);glVertex2f(698, 188);glVertex2f(697, 187);
    glVertex2f(697, 185);glVertex2f(696, 183);glVertex2f(696, 182);glVertex2f(696, 181);glVertex2f(697, 179);glVertex2f(697, 178);
    glVertex2f(697, 177);glVertex2f(697, 176);glVertex2f(698, 174);glVertex2f(698, 173);glVertex2f(698, 172);glVertex2f(699, 172);
    glVertex2f(699, 172);glVertex2f(699, 172);glVertex2f(700, 172);glVertex2f(701, 173);glVertex2f(702, 175);glVertex2f(703, 176);
    glVertex2f(704, 177);glVertex2f(704, 178);glVertex2f(705, 177);glVertex2f(705, 176);glVertex2f(705, 175);glVertex2f(705, 173);
    glVertex2f(704, 172);glVertex2f(704, 170);glVertex2f(704, 169);glVertex2f(703, 167);glVertex2f(703, 166);glVertex2f(703, 165);
    glVertex2f(703, 164);glVertex2f(703, 163);glVertex2f(704, 162);glVertex2f(704, 161);glVertex2f(705, 161);glVertex2f(706, 160);
    glVertex2f(706, 160);glVertex2f(707, 159);glVertex2f(707, 159);glVertex2f(708, 159);glVertex2f(708, 158);glVertex2f(709, 158);
    glVertex2f(707, 156);glVertex2f(705, 154);glVertex2f(702, 151);glVertex2f(700, 149);glVertex2f(697, 147);glVertex2f(694, 144);
    glVertex2f(691, 142);glVertex2f(688, 141);glVertex2f(682, 139);glVertex2f(679, 138);glVertex2f(675, 139);glVertex2f(673, 140);
    glEnd();

}

void fire2(){

    glBegin(GL_POLYGON);
    glVertex2f(677, 143);glVertex2f(673, 140);glVertex2f(671, 143);glVertex2f(669, 145);glVertex2f(669, 146);glVertex2f(668, 147);
    glVertex2f(667, 149);glVertex2f(665, 152);glVertex2f(664, 156);glVertex2f(664, 157);glVertex2f(664, 159);glVertex2f(664, 160);
    glVertex2f(664, 162);glVertex2f(664, 164);glVertex2f(665, 165);glVertex2f(666, 163);glVertex2f(667, 162);glVertex2f(668, 161);
    glVertex2f(669, 160);glVertex2f(669, 159);glVertex2f(670, 159);glVertex2f(670, 159);glVertex2f(671, 160);glVertex2f(672, 161);
    glVertex2f(673, 163);glVertex2f(674, 165);glVertex2f(674, 167);glVertex2f(674, 167);glVertex2f(674, 167);glVertex2f(674, 169);
    glVertex2f(674, 171);glVertex2f(675, 172);glVertex2f(674, 172);glVertex2f(674, 174);glVertex2f(675, 175);glVertex2f(675, 177);
    glVertex2f(675, 177);glVertex2f(676, 176);glVertex2f(676, 174);glVertex2f(677, 173);glVertex2f(679, 171);glVertex2f(680, 170);
    glVertex2f(681, 169);glVertex2f(683, 168);glVertex2f(684, 168);glVertex2f(685, 169);glVertex2f(686, 170);glVertex2f(686, 172);
    glVertex2f(686, 174);glVertex2f(687, 173);glVertex2f(689, 171);glVertex2f(690, 169);glVertex2f(690, 168);glVertex2f(691, 166);
    glVertex2f(691, 166);glVertex2f(691, 166);glVertex2f(692, 166);glVertex2f(692, 166);glVertex2f(692, 168);glVertex2f(693, 168);
    glVertex2f(693, 170);glVertex2f(694, 169);glVertex2f(695, 167);glVertex2f(695, 164);glVertex2f(695, 162);glVertex2f(695, 160);
    glVertex2f(695, 159);glVertex2f(694, 157);glVertex2f(694, 156);glVertex2f(693, 155);glVertex2f(694, 154);glVertex2f(696, 155);
    glVertex2f(697, 156);glVertex2f(697, 156);glVertex2f(698, 157);glVertex2f(699, 158);glVertex2f(699, 158);glVertex2f(699, 157);
    glVertex2f(699, 155);glVertex2f(698, 153);glVertex2f(698, 152);glVertex2f(697, 151);glVertex2f(696, 148);glVertex2f(695, 147);
    glVertex2f(695, 146);glVertex2f(694, 145);glVertex2f(694, 144);glVertex2f(691, 142);glVertex2f(689, 141);glVertex2f(689, 141);
    glVertex2f(686, 140);glVertex2f(684, 139);glVertex2f(681, 138);glVertex2f(678, 138);glVertex2f(676, 139);glVertex2f(675, 139);
    glVertex2f(674, 139);glVertex2f(673, 140);
    glEnd();
}

void fire3(){

    glBegin(GL_POLYGON);
    glVertex2f(679, 142);glVertex2f(679, 138);glVertex2f(679, 138);glVertex2f(678, 139);glVertex2f(677, 138);glVertex2f(677, 139);
    glVertex2f(677, 140);glVertex2f(676, 140);glVertex2f(676, 141);glVertex2f(675, 142);glVertex2f(675, 142);glVertex2f(674, 143);
    glVertex2f(673, 144);glVertex2f(673, 145);glVertex2f(672, 146);glVertex2f(672, 147);glVertex2f(672, 148);glVertex2f(672, 148);
    glVertex2f(671, 149);glVertex2f(672, 148);glVertex2f(673, 148);glVertex2f(673, 148);glVertex2f(673, 147);glVertex2f(674, 147);
    glVertex2f(674, 147);glVertex2f(675, 147);glVertex2f(675, 147);glVertex2f(675, 147);glVertex2f(675, 147);glVertex2f(675, 148);
    glVertex2f(675, 148);glVertex2f(675, 148);glVertex2f(675, 149);glVertex2f(675, 151);glVertex2f(675, 152);glVertex2f(675, 153);
    glVertex2f(675, 154);glVertex2f(675, 155);glVertex2f(675, 156);glVertex2f(675, 157);glVertex2f(675, 157);glVertex2f(675, 157);
    glVertex2f(675, 157);glVertex2f(675, 157);glVertex2f(675, 158);glVertex2f(676, 158);glVertex2f(676, 157);glVertex2f(676, 157);
    glVertex2f(677, 157);glVertex2f(678, 156);glVertex2f(678, 156);glVertex2f(679, 155);glVertex2f(680, 154);glVertex2f(680, 154);
    glVertex2f(681, 153);glVertex2f(681, 152);glVertex2f(682, 152);glVertex2f(682, 151);glVertex2f(682, 151);glVertex2f(682, 151);
    glVertex2f(682, 150);glVertex2f(682, 150);glVertex2f(682, 150);glVertex2f(683, 150);glVertex2f(683, 151);glVertex2f(683, 152);
    glVertex2f(684, 153);glVertex2f(684, 154);glVertex2f(684, 154);glVertex2f(685, 155);glVertex2f(685, 157);glVertex2f(685, 157);
    glVertex2f(685, 158);glVertex2f(685, 158);glVertex2f(685, 159);glVertex2f(685, 159);glVertex2f(686, 159);glVertex2f(686, 159);
    glVertex2f(686, 158);glVertex2f(686, 157);glVertex2f(687, 156);glVertex2f(687, 155);glVertex2f(688, 155);glVertex2f(688, 153);
    glVertex2f(688, 152);glVertex2f(689, 150);glVertex2f(689, 149);glVertex2f(689, 149);glVertex2f(689, 148);glVertex2f(689, 148);
    glVertex2f(689, 148);glVertex2f(689, 148);glVertex2f(689, 147);glVertex2f(689, 147);glVertex2f(689, 147);glVertex2f(689, 147);
    glVertex2f(688, 147);glVertex2f(688, 146);glVertex2f(689, 146);glVertex2f(689, 146);glVertex2f(689, 146);glVertex2f(691, 147);
    glVertex2f(692, 148);glVertex2f(692, 147);glVertex2f(691, 145);glVertex2f(691, 145);glVertex2f(690, 143);glVertex2f(689, 142);
    glVertex2f(689, 141);glVertex2f(689, 141);glVertex2f(687, 140);glVertex2f(685, 139);glVertex2f(684, 139);glVertex2f(682, 139);
    glVertex2f(682, 139);glVertex2f(681, 139);glVertex2f(680, 138);glVertex2f(678, 138);
    glEnd();
}

void day() {
    glClearColor(0.61f,0.95f,1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLineWidth(2);

    //Sky with shade
    glBegin(GL_POLYGON);
    glColor3f(0.18f,0.64f,1.0f);
    glVertex2f(0,1080);glVertex2f(0,425);glVertex2f(1920,425);glVertex2f(1920,1080);
    glColor3f(0.97f,1.0f,0.7f);
    glVertex2f(0,425);glVertex2f(0,1080);glVertex2f(1920,1080);glVertex2f(1920,425);
    glEnd();


    //Sun
    glPushMatrix();
    glTranslatef(sun_position_x*.1,sun_position_x*.05,0);
    glColor3f(1.0f,0.97f,0.45f);
    circle(1700, 900, 100, 100);
    glPopMatrix();

    //Cloud 1
    glPushMatrix();
    glTranslatef(+cloud_position1,0,0);
    glColor3f(1.0f,1.0f,1.0f);
    circle(0, 1000, 25, 25);
    circle(90, 1000, 20, 20);
    circle(30, 1030, 30, 30);
    circle(25, 1015, 25, 25);
    circle(25, 1005, 25, 25);
    circle(60, 1027, 20, 20);
    circle(35, 1040, 20, 20);
    circle(70, 1015, 20, 20);
    circle(70, 1000, 20, 20);
    circle(50, 1000, 20, 20);
    glPopMatrix();


    // Cloud 2
    glPushMatrix();
    glTranslatef(+cloud_position2,0,0);
    circle(16,880,15,15);
    circle(29,891,9,9);
    circle(58,890,27,27);
    circle(85,881,20,20);

    glBegin(GL_QUADS);
    glVertex2f(17, 883);
    glVertex2f(85, 883);
    glVertex2f(85, 861);
    glVertex2f(17, 865);
    glEnd();
    glPopMatrix();


    //cloud 3
    glPushMatrix();
    glTranslatef(-cloud_position3,0,0);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    circle(74,840,16,16);
    circle(95,840,10,10);
    circle(108,834,6,6);
    circle(122,831,10,10);
    circle(132,825,10,10);
    circle(144,816,6,6);

    glBegin(GL_QUADS);
    glVertex2f(12, 818);
    glVertex2f(146, 818);
    glVertex2f(144, 810);
    glVertex2f(13, 810);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(20, 832);
    glVertex2f(138, 832);
    glVertex2f(138, 817);
    glVertex2f(20, 817);
    glEnd();
    glPopMatrix();


    //cloud 4
    glPushMatrix();
    glTranslatef(-cloud_position4,0,0);
    circle(23, 933, 21, 21);
    circle(50, 949, 20, 20);
    circle(80, 943, 14, 14);
    circle(90, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    glPopMatrix();


    //Plane
    glPushMatrix();
    glTranslatef(-plane_position,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f,0.63f,0.72f);
    plane();
    glPopMatrix();

    //Mountain 1
    glColor3f(0.35f,0.96f,0.6f);
    mountain1();

    //Mountain1 Shadow 1
    glColor3f(0.56f,1.0f,0.75f);
    mountain1_shadow_1();

    //Mountain1 Shadow 2
    mountain1_shadow_2();

    //Mountain1 Shadow 3
    mountain1_shadow_3();

    //Mountain 2
    glColor3f(0.18f,0.8f,0.45f);
    mountain2();

    //Water
    glBegin(GL_QUADS);
    glColor3f(0.61f,0.95f,1.0f);
    water();

    //Mountain 3 front land
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.4f,0.1f);
    mountain_front_land();
    //Mountain 3
    glColor3f(0.0f,0.6f,0.26f);
    mountain3();
    glEnd();


    //Tree type 1 on mountain
    tree_type1(885, 513, 65,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type1(550, 490, 65,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type1(1700, 425, 80,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type1(540, 604, 40,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type1(355, 613, 40,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type1(1650, 630, 65,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type1(830, 737, 20,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);

    //Tree type 2 on mountain
    tree_type2(995, 504, 65,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type2(1528, 607, 60,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);
    tree_type2(1083, 515, 67,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);
    tree_type2(421, 478, 70,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);
    tree_type2(731, 540, 40,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);
    tree_type2(1559, 692, 20,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);
    tree_type2(1216,703, 30,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);
    tree_type2(1142,549, 60,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);

    //Tree type 3 on mountain
    tree_type3(1774, 627, 70,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(1600, 616, 70,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(636, 489, 75,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(1339, 606, 70,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(380,653, 20,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(297,617, 40,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(1216,703, 30,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(995, 504, 65,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type3(350, 468, 70,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);




    //House 1 on mountain 3(middle house)////////////////////////////////////////////////////////////////////////
    glLineWidth(1);

    glBegin(GL_POLYGON);
    glColor3f(0.5f,0.41f,0.13f);
    glVertex2f(1395, 642);glVertex2f(1378, 628);glVertex2f(1408, 624);glVertex2f(1399, 633);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(1352, 624);glVertex2f(1361, 633);glVertex2f(1395, 642);glVertex2f(1378, 628);
    glEnd();

    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(1399, 633);glVertex2f(1412, 633);glVertex2f(1421, 624);glVertex2f(1408, 624);
    glEnd();


    //roof line
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1378, 628);glVertex2f(1395, 641);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glVertex2f(1399, 633);glVertex2f(1412, 633);
    glVertex2f(1412, 633);glVertex2f(1421, 624);
    glEnd();

    //roof line
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1394, 640);glVertex2f(1406, 624);
    glEnd();


    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.61f,0.52f,0.21f);
    glVertex2f(1356, 624);glVertex2f(1378, 628);glVertex2f(1378, 611);glVertex2f(1356, 611);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.75f,0.63f,0.25f);
    glVertex2f(1378, 628);glVertex2f(1417, 624);glVertex2f(1417, 611);glVertex2f(1378, 611);
    glEnd();

    //roof border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glEnd();

     //Gate
    glBegin(GL_QUADS);
    glColor3f(0.41f,0.31f,0.0f);
    glVertex2f(1395, 611);glVertex2f(1395, 620);glVertex2f(1399, 620);glVertex2f(1399, 611);
    //Gate's Left window
    glVertex2f(1382, 620);glVertex2f(1382, 615);glVertex2f(1391, 615);glVertex2f(1391, 620);
    //Gate's right window
    glVertex2f(1403, 620);glVertex2f(1403, 615);glVertex2f(1412, 615);glVertex2f(1412, 620);
    glEnd();


    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.27f,0.21f,0.01f);
    glVertex2f(1361, 620);glVertex2f(1365, 620);glVertex2f(1365, 615);glVertex2f(1361, 615);
    //Left wall's right window
    glVertex2f(1370, 620);glVertex2f(1374, 620);glVertex2f(1374, 615);glVertex2f(1370, 615);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1355, 615);glVertex2f(1355, 611);
    glVertex2f(1357, 615);glVertex2f(1357, 611);
    glVertex2f(1361, 615);glVertex2f(1361, 611);
    glVertex2f(1365, 615);glVertex2f(1365, 611);
    glVertex2f(1369, 615);glVertex2f(1369, 611);
    glVertex2f(1378, 615);glVertex2f(1378, 611);
    glVertex2f(1382, 615);glVertex2f(1382, 611);
    glVertex2f(1391, 615);glVertex2f(1391, 611);
    glVertex2f(1395, 615);glVertex2f(1395, 611);
    glVertex2f(1399, 615);glVertex2f(1399, 611);
    glVertex2f(1408, 615);glVertex2f(1408, 611);
    glVertex2f(1412, 615);glVertex2f(1412, 611);
    glVertex2f(1417, 615);glVertex2f(1417, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1354, 615);glVertex2f(1382, 615);
    glVertex2f(1382, 615);glVertex2f(1421, 615);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1354, 611);glVertex2f(1382, 611);glVertex2f(1382, 611);glVertex2f(1421, 611);
    //Pillar
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1395, 611);glVertex2f(1395, 601);
    glVertex2f(1390, 611);glVertex2f(1390, 602);
    glVertex2f(1404, 611);glVertex2f(1404, 603);
    glVertex2f(1412, 611);glVertex2f(1412, 603);
    glVertex2f(1417, 611);glVertex2f(1417, 603);
    glVertex2f(1374, 611);glVertex2f(1374, 603);
    glVertex2f(1367, 611);glVertex2f(1367, 606);
    glVertex2f(1361, 611);glVertex2f(1361, 607);
    glEnd();

    //House 2 on mountain 3 (left most house)////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.5f,0.41f,0.13f);
    glVertex2f(578, 528);glVertex2f(595, 514);glVertex2f(565, 510);glVertex2f(574, 519);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(621, 510);glVertex2f(612, 519);glVertex2f(578, 528);glVertex2f(595, 514);
    glEnd();

    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(574, 519);glVertex2f(561, 519);glVertex2f(552, 510);glVertex2f(565, 510);
    glEnd();


    //roof lines
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(595, 514);glVertex2f(578, 527);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glVertex2f(574, 519);glVertex2f(561, 519);
    glVertex2f(561, 519);glVertex2f(552, 510);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(579, 526);glVertex2f(567, 510);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.75f,0.63f,0.25f);//glColor3f(0.61f,0.52f,0.21f);
    glVertex2f(617, 510);glVertex2f(595, 514);glVertex2f(595, 497);glVertex2f(617, 497);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.61f,0.52f,0.21f);//glColor3f(0.75f,0.63f,0.25f);
    glVertex2f(595, 514);glVertex2f(556, 510);glVertex2f(556, 497);glVertex2f(595, 497);
    glEnd();

    //roof border
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glEnd();


    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.41f,0.31f,0.0f);
    glVertex2f(578, 497);glVertex2f(578, 506);glVertex2f(574, 506);glVertex2f(574, 497);
    //Gate's Left window
    glVertex2f(591, 506);glVertex2f(591, 501);glVertex2f(582, 501);glVertex2f(582, 506);
    // Gate's right window
    glVertex2f(570, 506);glVertex2f(570, 501);glVertex2f(561, 501);glVertex2f(561, 506);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.27f,0.21f,0.01f);
    glVertex2f(612, 506);glVertex2f(608, 506);glVertex2f(608, 501);glVertex2f(612, 501);
    //Left wall's right window
    glVertex2f(603, 506);glVertex2f(599, 506);glVertex2f(599, 501);glVertex2f(603, 501);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(619, 501);glVertex2f(619, 497);
    glVertex2f(616, 501);glVertex2f(616, 497);
    glVertex2f(612, 501);glVertex2f(612, 497);
    glVertex2f(608, 501);glVertex2f(608, 497);
    glVertex2f(604, 501);glVertex2f(604, 497);
    glVertex2f(595, 501);glVertex2f(595, 497);
    glVertex2f(591, 501);glVertex2f(591, 497);
    glVertex2f(582, 501);glVertex2f(582, 497);
    glVertex2f(578, 501);glVertex2f(578, 497);
    glVertex2f(574, 501);glVertex2f(574, 497);
    glVertex2f(565, 501);glVertex2f(565, 497);
    glVertex2f(561, 501);glVertex2f(561, 497);
    glVertex2f(556, 501);glVertex2f(556, 497);
    glVertex2f(553, 501);glVertex2f(553, 497);
    glVertex2f(619, 501);glVertex2f(591, 501);
    glVertex2f(591, 501);glVertex2f(552, 501);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(619, 497);glVertex2f(591, 497);
    glVertex2f(591, 497);glVertex2f(552, 497);
    //pillar
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(578, 497);glVertex2f(578, 487);
    glVertex2f(583, 497);glVertex2f(583, 488);
    glVertex2f(569, 497);glVertex2f(569, 489);
    glVertex2f(561, 497);glVertex2f(561, 489);
    glVertex2f(556, 497);glVertex2f(556, 489);
    glVertex2f(599, 497);glVertex2f(599, 489);
    glVertex2f(606, 497);glVertex2f(606, 492);
    glVertex2f(612, 497);glVertex2f(612, 493);
    glEnd();

    //House 3 on mountain (right most house)////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    glBegin(GL_POLYGON);
    glColor3f(0.5f,0.41f,0.13f);
    glVertex2f(1818, 662);glVertex2f(1801, 648);glVertex2f(1831, 644);glVertex2f(1822, 653);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(1775, 644);glVertex2f(1784, 653);glVertex2f(1818, 662);glVertex2f(1801, 648);
    glEnd();

    //roof lines
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 648);glVertex2f(1818, 661);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();
    //roof lines
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1817, 660);glVertex2f(1829, 644);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.61f,0.52f,0.21f);
    glVertex2f(1779, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 631);glVertex2f(1779, 631);
    glEnd();
    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.75f,0.63f,0.25f);
    glVertex2f(1801, 648);glVertex2f(1840, 644);
    glVertex2f(1840, 631);glVertex2f(1801, 631);
    glEnd();

    //roof lines
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();

    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.41f,0.31f,0.0f);
    glVertex2f(1818, 631);glVertex2f(1818, 640);
    glVertex2f(1822, 640);glVertex2f(1822, 631);
    //Gate's Left window
    glVertex2f(1805, 640);glVertex2f(1805, 635);
    glVertex2f(1814, 635);glVertex2f(1814, 640);
    // Gate's right window
    glVertex2f(1826, 640);glVertex2f(1826, 635);
    glVertex2f(1835, 635);glVertex2f(1835, 640);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.27f,0.21f,0.01f);
    glVertex2f(1784, 640);glVertex2f(1788, 640);
    glVertex2f(1788, 635);glVertex2f(1784, 635);
    //Left wall's right window
    glVertex2f(1793, 640);glVertex2f(1797, 640);
    glVertex2f(1797, 635);glVertex2f(1793, 635);
    glEnd();


    //railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1777, 635);glVertex2f(1777, 631);
    glVertex2f(1780, 635);glVertex2f(1780, 631);
    glVertex2f(1784, 635);glVertex2f(1784, 631);
    glVertex2f(1788, 635);glVertex2f(1788, 631);
    glVertex2f(1792, 635);glVertex2f(1792, 631);
    glVertex2f(1801, 635);glVertex2f(1801, 631);
    glVertex2f(1805, 635);glVertex2f(1805, 631);
    glVertex2f(1814, 635);glVertex2f(1814, 631);
    glVertex2f(1818, 635);glVertex2f(1818, 631);
    glVertex2f(1822, 635);glVertex2f(1822, 631);
    glVertex2f(1831, 635);glVertex2f(1831, 631);
    glVertex2f(1835, 635);glVertex2f(1835, 631);
    glVertex2f(1840, 635);glVertex2f(1840, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1777, 635);glVertex2f(1805, 635);
    glVertex2f(1805, 635);glVertex2f(1844, 635);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1777, 631);glVertex2f(1805, 631);
    glVertex2f(1805, 631);glVertex2f(1844, 631);
    //pillar
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1818, 631);glVertex2f(1818, 621);
    glVertex2f(1813, 631);glVertex2f(1813, 622);
    glVertex2f(1827, 631);glVertex2f(1827, 623);
    glVertex2f(1835, 631);glVertex2f(1835, 623);
    glVertex2f(1840, 631);glVertex2f(1840, 623);
    glVertex2f(1844, 631);glVertex2f(1844, 623);
    glVertex2f(1797, 631);glVertex2f(1797, 627);
    glVertex2f(1790, 631);glVertex2f(1790, 626);
    glVertex2f(1784, 631);glVertex2f(1784, 627);
    glEnd();


    //waterfall front water shade
    glPushMatrix();
    glTranslatef(0,-waterfall_on_river_position,0);
    glColor3f(0.41f,0.89f,0.92f);
    circle(1765, 425, 50, 8);
    glPopMatrix();

    //cell tower/////////////////////////////////////////////
    //Middle white line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.8f,0.8f,0.8f);
    glVertex2f(1893, 917);glVertex2f(1893, 685);

    //Middle red line
    glBegin(GL_LINES);
    glColor3f(0.93f,0.27f,0.12f);
    glVertex2f(1893, 737);glVertex2f(1893, 788);
    glVertex2f(1893, 840);glVertex2f(1893, 865);
    glVertex2f(1893, 891);glVertex2f(1893, 917);
    glEnd();

    // white Part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.77f,0.77f,0.77f);
    glVertex2f(1893, 927);glVertex2f(1893, 917);
    //1
    glVertex2f(1868, 685);glVertex2f(1874, 737);
    glVertex2f(1868, 685);glVertex2f(1870, 699);
    glVertex2f(1870, 699);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1873, 724);
    glVertex2f(1873, 724);glVertex2f(1874, 737);

    glVertex2f(1915, 685);glVertex2f(1912, 737);
    glVertex2f(1915, 685);glVertex2f(1914, 699);
    glVertex2f(1914, 699);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1913, 724);
    glVertex2f(1913, 724);glVertex2f(1912, 737);

    glVertex2f(1868, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1912, 737);

    glVertex2f(1915, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1874, 737);
    //1 horizontal

    glVertex2f(1870, 699);glVertex2f(1893, 699);
    glVertex2f(1893, 699);glVertex2f(1914, 699);

    glVertex2f(1873, 724);glVertex2f(1893, 724);
    glVertex2f(1893, 724);glVertex2f(1913, 724);

    //3
    glVertex2f(1879, 788);glVertex2f(1884, 840);
    glVertex2f(1908, 788);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1880, 802);
    glVertex2f(1880, 802);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1882, 828);
    glVertex2f(1882, 828);glVertex2f(1884, 840);

    glVertex2f(1908, 788);glVertex2f(1907, 802);
    glVertex2f(1907, 802);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1905, 828);
    glVertex2f(1905, 828);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1904, 840);

    glVertex2f(1908, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1884, 840);

    //horizontal
    glVertex2f(1880, 802);glVertex2f(1893, 802);
    glVertex2f(1893, 802);glVertex2f(1907, 802);

    glVertex2f(1882, 828);glVertex2f(1893, 828);
    glVertex2f(1893, 828);glVertex2f(1905, 828);


    //4
    glVertex2f(1886, 865);glVertex2f(1887, 872);
    glVertex2f(1887, 872);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1887, 885);
    glVertex2f(1887, 885);glVertex2f(1887, 891);

    glVertex2f(1902, 865);glVertex2f(1902, 872);
    glVertex2f(1902, 872);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1901, 885);
    glVertex2f(1901, 885);glVertex2f(1901, 891);

    glVertex2f(1886, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1901, 891);

    glVertex2f(1902, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1887, 891);
    //horizontal line
    glVertex2f(1887, 872);glVertex2f(1893, 872);
    glVertex2f(1893, 872);glVertex2f(1902, 872);

    glVertex2f(1887, 885);glVertex2f(1893, 885);
    glVertex2f(1893, 885);glVertex2f(1901, 885);

    glEnd();


    //Darker White part
    glBegin(GL_LINES);
    glColor3f(0.6f,0.6f,0.6f);
    //1
    glVertex2f(1893, 685);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1893, 737);

    glVertex2f(1893, 685);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1893, 737);
    //3

    glVertex2f(1893, 788);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1893, 840);

    glVertex2f(1893, 788);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1893, 840);
    //4
    glVertex2f(1893, 865);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1893, 891);

    glVertex2f(1893, 865);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1893, 891);
    glEnd();


    //Red part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.93f,0.32f,0.18f);
    //2
    glVertex2f(1874, 737);glVertex2f(1875, 750);
    glVertex2f(1875, 750);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1878, 776);
    glVertex2f(1878, 776);glVertex2f(1879, 788);

    glVertex2f(1912, 737);glVertex2f(1911, 750);
    glVertex2f(1911, 750);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1909, 776);
    glVertex2f(1909, 776);glVertex2f(1908, 788);

    glVertex2f(1874, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1908, 788);
    glVertex2f(1912, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1879, 788);

    glVertex2f(1893, 737);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1893, 788);
    glVertex2f(1893, 737);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1893, 788);
    //2 horizontal

    glVertex2f(1875, 750);glVertex2f(1893, 750);
    glVertex2f(1893, 750);glVertex2f(1911, 750);

    glVertex2f(1878, 776);glVertex2f(1893, 776);
    glVertex2f(1893, 776);glVertex2f(1909, 776);


    //3

    glVertex2f(1884, 840);glVertex2f(1884, 847);
    glVertex2f(1884, 847);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1885, 860);
    glVertex2f(1885, 860);glVertex2f(1886, 865);

    glVertex2f(1904, 840);glVertex2f(1904, 847);
    glVertex2f(1904, 847);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1903, 860);
    glVertex2f(1903, 860);glVertex2f(1902, 865);


    glVertex2f(1884, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1902, 865);

    glVertex2f(1904, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1886, 865);

    glVertex2f(1893, 840);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1893, 865);

    glVertex2f(1893, 840);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1893, 865);

    glVertex2f(1884, 847);glVertex2f(1893, 847);
    glVertex2f(1893, 847);glVertex2f(1904, 847);

    glVertex2f(1885, 860);glVertex2f(1893, 860);
    glVertex2f(1893, 860);glVertex2f(1903, 860);

    //5

    glVertex2f(1887, 891);glVertex2f(1887, 898);
    glVertex2f(1887, 898);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1887, 911);
    glVertex2f(1887, 911);glVertex2f(1887, 917);

    glVertex2f(1901, 891);glVertex2f(1901, 898);
    glVertex2f(1901, 898);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1901, 911);
    glVertex2f(1901, 911);glVertex2f(1901, 917);

    glVertex2f(1887, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1901, 917);

    glVertex2f(1901, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1887, 917);

    glVertex2f(1893, 891);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1893, 917);

    glVertex2f(1893, 891);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1893, 917);

    glVertex2f(1887, 898);glVertex2f(1893, 898);
    glVertex2f(1893, 898);glVertex2f(1901, 898);

    glVertex2f(1887, 911);glVertex2f(1893, 911);
    glVertex2f(1893, 911);glVertex2f(1901, 911);

    glVertex2f(1887, 917);glVertex2f(1893, 917);
    glVertex2f(1893, 917);glVertex2f(1901, 917);
    glEnd();



    //cell tower drum holder
    glBegin(GL_LINES);

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1887, 885);glVertex2f(1878, 885);
    glVertex2f(1901, 885);glVertex2f(1909, 885);

    glVertex2f(1887, 891);glVertex2f(1878, 891);
    glVertex2f(1901, 891);glVertex2f(1909, 891);


    glVertex2f(1887, 904);glVertex2f(1878, 904);
    glVertex2f(1901, 904);glVertex2f(1909, 904);

    glVertex2f(1887, 911);glVertex2f(1878, 911);
    glVertex2f(1901, 911);glVertex2f(1909, 911);


    glEnd();

    //cell tower long drum
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.83f,0.83f,0.83f);
    glVertex2f(1880, 880);glVertex2f(1880, 896);
    glVertex2f(1908, 880);glVertex2f(1908, 896);
    glColor3f(0.59f,0.59f,0.59f);
    glVertex2f(1882, 880);glVertex2f(1882, 896);
    glVertex2f(1906, 880);glVertex2f(1906, 896);
    glVertex2f(1893, 880);glVertex2f(1893, 896);
    glVertex2f(1895, 880);glVertex2f(1895, 896);
    glEnd();


    //cell tower drum
    glColor3f(0.59f,0.59f,0.59f);
    circle(1881,908,5,8);
    circle(1906,908,5,8);
    glColor3f(0.83f,0.83f,0.83f);
    circle(1878,908,5,8);
    circle(1909,908,5,8);

    //Tower Light(off)
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.93f,0.32f,0.18f);
    glVertex2f(1899,917);
    glVertex2f(1899,920);
    glEnd();



    //Mountain 4
    glColor3f(0.0f,0.4f,0.1f);
    mountain4();

    //Waterfall with shade
    glBegin(GL_POLYGON);
    glColor3f(0.7f,0.88f,1.00f);
    waterfall_with_shade_1();
    glColor3f(0.30f,0.89f,1.0f);
    waterfall_with_shade_2();


    glLineWidth(1);
    //waterfall shade 1
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position1,0);
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(1752,545);glVertex2f(1752,530);
    glVertex2f(1746,540);glVertex2f(1746,525);
    glEnd();
    glPopMatrix();

    //waterfall shade 2
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position2,0);
    glBegin(GL_LINES);
    glVertex2f(1754,520);glVertex2f(1754,510);
    glVertex2f(1747,515);glVertex2f(1747,500);
    glVertex2f(1741,525);glVertex2f(1741,510);
    glEnd();
    glPopMatrix();

    //waterfall shade 3
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position3,0);
    glBegin(GL_LINES);
    glVertex2f(1752,495);glVertex2f(1752,480);
    glVertex2f(1745,493);glVertex2f(1745,475);
    glVertex2f(1738,490);glVertex2f(1738,475);
    glEnd();

    glPopMatrix();

    //River front Land
    glBegin(GL_POLYGON);
    glColor3f(0.54f,0.85f,0.31f);
    glVertex2f(0,0);glVertex2f(0,300);glVertex2f(1920,300);glVertex2f(1920,0);
    glEnd();

    //Trees on mountain front
    tree_type1(1700, 425, 75,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);

    //ALL land shades
    glColor3f(0.69f,1.0f,0.53f);
    land_shade();

    //Road
    glBegin(GL_POLYGON);
    glColor3f(0.88f,0.9f,0.67f);
    glVertex2f(1920,0);
    bezier_curve4(1230,0,1550,150,1300,280,1590,298);
    glVertex2f(1920,300);

    //Road's left side hill
    glEnd();
    glLineWidth(2);
    glBegin(GL_POLYGON);
    glColor3f(0.34f,0.56f,0.19f);
    glVertex2f(1920,100);
    glVertex2f(1920,0);
    bezier_curve4(1600,0,1700,150,1400,250,1590,298);
    bezier_curve3(1590,298,1700,330,1920,340);
    glEnd();

    //Moving water shade STARTS
    glPushMatrix();
    glTranslatef(-water_shade_position1,0,0);
    //Water shade 1(Moving)
    glBegin(GL_POLYGON);
    glColor3f(0.41f,0.89f,0.92f);
    water_shade1();
    glPopMatrix();

    glPushMatrix();
    //Water shade 2(Moving)
    glTranslatef(-water_shade_position2,0,0);
    glBegin(GL_POLYGON);
    water_shade2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position3,0,0);
    //Water shade 3(Moving)
    glBegin(GL_POLYGON);;
    water_shade3();
    glPopMatrix();


    //Water shade 4(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position4,0,0);
    glBegin(GL_POLYGON);
    water_shade4();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-water_shade_position5,0,0);
    glBegin(GL_POLYGON);
    water_shade5();
    glPopMatrix();

    //Water shade 5(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position6,0,0);
    glBegin(GL_POLYGON);
    water_shade6();
    glPopMatrix();






    glLineWidth(2);

    glPushMatrix();
    glTranslatef(-raft_position,-position_raft,0);
    //Bamboo raft
    glBegin(GL_POLYGON);
    glColor3f(0.22f,0.45f,0.0f);
    bamboo_raft();


    //Raft vertical line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1913,330);glVertex2f(1907,348);
    glVertex2f(1891,347);glVertex2f(1895,330);
    glVertex2f(1870,347);glVertex2f(1874,330);
    glVertex2f(1816,347);glVertex2f(1807,328);
    glVertex2f(1828,329);glVertex2f(1836,346);
    glVertex2f(1853,347);glVertex2f(1848,329);
    glEnd();

    //bamboo stick
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1820,385);glVertex2f(1912,347);
    glEnd();

    //Human
    glBegin(GL_POLYGON);
    glColor3f(0.77f,0.63f,0.43f);
    human();

    //Head
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    human_head();

    //Human dress
    glBegin(GL_POLYGON);
    glColor3f(0.35f,0.36f,0.38f);
    human_dress();
    glPopMatrix();




    //Tent 1(left tent)______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);//glColor3f(0.89f, 0.55f, 0.0f);
    glVertex2f(276,169);glVertex2f(271,207);glVertex2f(456,318);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(354,133);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);
    glVertex2f(456,318);glVertex2f(551,185);glVertex2f(542,187);glVertex2f(450,318);
    glEnd();

    //roof
    glBegin(GL_POLYGON);

    glColor3f(0.89f, 0.55f, 0.0f);//glColor3f(1.0f, 0.67f, 0.14f);
    glVertex2f(252,203);glVertex2f(346,317);glVertex2f(456,318);glVertex2f(343,177);
    glEnd();

    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.72f, 0.27f);
    glVertex2f(354,133);glVertex2f(344,182);glVertex2f(452,314);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(461,142);
    glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(454,251);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);
    glVertex2f(461,140);glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(455,251);glVertex2f(454,251);glVertex2f(450,139);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(290,141);glVertex2f(296,141);glVertex2f(293,119);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(221,192);glVertex2f(228,192);glVertex2f(225,174);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(581,167);glVertex2f(587,167);glVertex2f(584,147);
    glEnd();



    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(289,134);glVertex2f(340,178);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(220,184);glVertex2f(253,204);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(588,158);glVertex2f(548,187);
    glEnd();



    //Tent 2(right tent)______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.89f, 0.55f, 0.0f);
    glVertex2f(926,199);glVertex2f(931,237);glVertex2f(746,348);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(848,163);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);
    glVertex2f(746,348);glVertex2f(651,215);glVertex2f(660,217);glVertex2f(752,348);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.67f, 0.14f);
    glVertex2f(950,233);glVertex2f(856,347);glVertex2f(746,348);glVertex2f(859,207);
    glEnd();

    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.72f, 0.27f);
    glVertex2f(848,163);glVertex2f(855,205);glVertex2f(724,308);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(741,172);
    glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(748,281);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);
    glVertex2f(741,170);glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(747,281);glVertex2f(748,281);glVertex2f(752,169);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(912,171);glVertex2f(906,171);glVertex2f(909,149);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(981,222);glVertex2f(974,222);glVertex2f(977,204);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(621,197);glVertex2f(615,197);glVertex2f(618,177);
    glEnd();

    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(913,164);glVertex2f(860,207);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(982,214);glVertex2f(949,234);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(614,188);glVertex2f(654,217);
    glEnd();


    //Big tree
    glBegin(GL_POLYGON);
    //Light color
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(0, 200);
    //Most dark color
    glColor3f(0.49,0.25,0.0f);
    big_tree_root_with_shade1();
    //Dark color
    glColor3f(0.51f,0.26f,0.0f);
    big_tree_root_with_shade2();


    //Big tree leaf
    glBegin(GL_POLYGON);
    glColor3f(0.35f,0.7f,0.0f);
    tree_leaf1();
    glBegin(GL_POLYGON);
    glColor3f(0.01f,0.61f,0.0f);
    tree_leaf2();
    glBegin(GL_POLYGON);
    glColor3f(0.42f,0.88f,0.17f);
    tree_leaf3();
    glBegin(GL_POLYGON);
    glColor3f(0.66f,0.95f,0.12f);
    tree_leaf4();


    //River front 3 right side trees
    tree_type1(1910,90, 450,0.57f,1.0f,0.14f,0.4f,0.79f,0.0f,0.56f,0.33f,0.0f);
    tree_type3(1590, 270, 275,0.49f,0.74f,0.02f,0.27f,0.63f,0.1f,0.56f,0.33f,0.0f);
    tree_type2(1350, 200, 300,0.5f,0.61f,0.12f,0.66f,0.8f,0.15f,0.56f,0.33f,0.0f);


    glLineWidth(2);

    //Campfire wood

    //campfire wood dark tail circle
    glColor3f(0.56f,0.33f,0.0f);
    circle(655, 144,5,6);
    circle(710, 144,5,6);

    //Wood 1
    glBegin(GL_QUADS);
    glColor3f(0.56f,0.33f,0.0f);
    glVertex2f(646, 133);
    glVertex2f(650, 118);
    glVertex2f(711, 138);
    glVertex2f(709, 150);
    glEnd();

    //Wood 1 shades
    glBegin(GL_LINES);
    glColor3f(0.45f,0.28f,0.17f);
    glVertex2f(651,126);
    glVertex2f(678,136);
    glVertex2f(652,122);
    glVertex2f(676,130);
    glVertex2f(683,135);
    glVertex2f(713,143);
    glVertex2f(686,132);
    glVertex2f(700,136);
    glEnd();
    //Wood 2
    glBegin(GL_QUADS);
    glColor3f(0.56f,0.33f,0.0f);
    glVertex2f(713, 119);
    glVertex2f(715, 132);
    glVertex2f(656, 149);
    glVertex2f(653, 137);
    glEnd();
    //Wood 2 shades
    glBegin(GL_LINES);
    glColor3f(0.45f,0.28f,0.17f);
    glVertex2f(713,122);
    glVertex2f(670,135);
    glVertex2f(714,127);
    glVertex2f(700,131);
    glVertex2f(715,130);
    glVertex2f(698,135);
    glVertex2f(650,145);
    glVertex2f(675,137);
    glVertex2f(655,149);
    glVertex2f(664,146);
    glEnd();

    //campfire wood light circle
    glColor3f(0.89f,0.71f,0.51f);
    circle(648, 125,4,7);
    circle(714, 125,4,7);

    //Birds
    glPushMatrix();
    glTranslatef(bird_position,-bird_position*.1,0);
    glColor3f(0.24f,0.37f,0.4f);
    bird1(30,835);
    bird1(50,840);
    bird1(70,845);
    bird1(90,860);
    bird1(73,865);
    bird1(63,840);
    bird1(80,850);
    bird1(60,870);
    bird1(45,880);
    bird1(37,845);
    bird1(30,885);
    bird1(22,841);
    glPopMatrix();


    glFlush(); // Render now
}

void cover() {
    //glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glClearColor(0.61f,0.95f,1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLineWidth(2);

    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(0,1080);glVertex2f(0,0);glVertex2f(1920,0);glVertex2f(1920,1080);
    glColor3f(0.38f,0.0f,1.0f);
    glVertex2f(0,0);glVertex2f(0,1080);glVertex2f(1920,1080);glVertex2f(1920,0);
    glColor3f(1.0f,0.84f,0.0f);
    glVertex2f(0,0);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    renderBitmapString(772, 999, 0.0f, GLUT_BITMAP_HELVETICA_18, " 01047 - COMPUTER GRAPHICS [A]");
    renderBitmapString(800, 945, 0.0f, GLUT_BITMAP_HELVETICA_18, "  Somewhere in Bandarban");
    renderBitmapString(791, 885, 0.0f, GLUT_BITMAP_HELVETICA_18, "      Submitted by Group- 4");
    renderBitmapString(676, 756, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID                                 Name                                                 Contribution ");
    renderBitmapString(676, 702, 0.0f, GLUT_BITMAP_HELVETICA_18, "20-42076-1                MD. Sazib Ahmed                                    100% ");
    renderBitmapString(860, 270, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted to");
    renderBitmapString(860, 216, 0.0f, GLUT_BITMAP_HELVETICA_18, "MAHFUJUR RAHAMAN");
    renderBitmapString(860, 189, 0.0f, GLUT_BITMAP_HELVETICA_12, "FACULTY OF SCIENCE & TECHNOLOGY");
    renderBitmapString(860, 162, 0.0f, GLUT_BITMAP_HELVETICA_10, "American International University-Bangladesh");

 glFlush(); // Render now
}

void night() {

    glClearColor(0.61f,0.95f,1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLineWidth(2);

    //Sky with shade
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.23f);
    glVertex2f(0,1080);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(0,425);
    glVertex2f(1920,425);
    glColor3f(0.0f,0.0f,0.23f);
    glVertex2f(1920,1080);

    glEnd();

    //Stars with circle
    glColor3f(0.61f,0.98f,1.0f);
    circle(304, 821, 1, 1);circle(356, 856, 1, 1);circle(608, 817, 1, 1);circle(755, 829, 1, 1);circle(844, 856, 1, 1);circle(869, 903, 1, 1);
    circle(761, 929, 1, 1);circle(735, 882, 1, 1);circle(787, 895, 1, 1);circle(619, 900, 1, 1);circle(899, 823, 1, 1);circle(1745, 780, 1, 1);
    circle(1835, 833, 1, 1);circle(1844, 1024, 1, 1);circle(1805, 966, 1, 1);circle(1515, 1019, 1, 1);circle(1475, 906, 1, 1);circle(1421, 818, 1, 1);
    circle(1250, 794, 1, 1);circle(879, 1025, 1, 1);circle(651, 1012, 1, 1);circle(431, 979, 1, 1);circle(318, 1041, 1, 1);circle(266, 861, 1, 1);
    circle(61, 930, 1, 1);circle(147, 954, 1, 1);circle(162, 777, 1, 1);circle(413, 726, 1, 1);circle(772, 845, 1, 1);circle(608, 845, 1, 1);
    circle(953, 926, 1, 1);circle(903, 824, 1, 1);circle(705, 703, 1, 1);circle(1182, 802, 1, 1);circle(1736, 660, 1, 1);circle(1608, 703, 1, 1);
    circle(1639, 1012, 1, 1);circle(1076, 982, 1, 1);circle(934, 806, 1, 1);circle(580, 827, 1, 1);circle(306, 870, 1, 1);circle(247, 765, 1, 1);
    circle(362, 1047, 1, 1);circle(1315, 787, 1, 1);circle(1200, 900,1,1);circle(37, 1064, 1, 1);circle(38, 991, 1, 1);circle(190, 959, 1, 1);
    circle(339, 969, 1, 1);circle(258, 1015, 1, 1);circle(184, 903, 1, 1);circle(156, 1000, 1, 1);circle(138, 1042, 1, 1);circle(532, 959, 1, 1);
    circle(494, 858, 1, 1);circle(403, 809, 1, 1);circle(381, 899, 1, 1);circle(312, 929, 1, 1);circle(127, 866, 1, 1);circle(37, 833, 1, 1);
    circle(109, 717, 1, 1);circle(160, 790, 1, 1);circle(315, 718, 1, 1);circle(403, 675, 1, 1);circle(523, 754, 1, 1);circle(699, 766, 1, 1);
    circle(621, 727, 1, 1);circle(597, 911, 1, 1);circle(627, 995, 1, 1);circle(833, 1043, 1, 1);circle(1009, 1049, 1, 1);circle(1142, 988, 1, 1);
    circle(967, 942, 1, 1);circle(955, 1018, 1, 1);circle(1332, 1004, 1, 1);circle(1475, 936, 1, 1);circle(1380, 864, 1, 1);circle(1261, 821, 1, 1);
    circle(1155, 876, 1, 1);circle(1021, 875, 1, 1);circle(1145, 926, 1, 1);circle(1434, 973, 1, 1);circle(1559, 1046, 1, 1);circle(1921, 1079, 1, 1);
    circle(1848, 1034, 1, 1);circle(1890, 1040, 1, 1);circle(1871, 927, 1, 1);circle(1824, 821, 1, 1);circle(1718, 736, 1, 1);circle(1610, 712, 1, 1);
    circle(1456, 766, 1, 1);circle(1627, 846, 1, 1);circle(1705, 914, 1, 1);circle(1563, 917, 1, 1);circle(1422, 831, 1, 1);circle(1295, 772, 1, 1);
    circle(1223, 836, 1, 1);circle(1149, 932, 1, 1);circle(1149, 994, 1, 1);circle(925, 1048, 1, 1);circle(707, 1034, 1, 1);circle(713, 935, 1, 1);
    circle(899, 941, 1, 1);circle(811, 979, 1, 1);circle(485, 1001, 1, 1);circle(371, 1037, 1, 1);circle(65, 1043, 1, 1);circle(172, 818, 1, 1);
    circle(297, 760, 1, 1);circle(555, 750, 1, 1);circle(445, 815, 1, 1);circle(351, 912, 1, 1);circle(475, 927, 1, 1);circle(522, 867, 1, 1);
    circle(627, 930, 1, 1);circle(982, 885, 1, 1);circle(985, 821, 1, 1);circle(1115, 977, 1, 1);circle(1554, 1031, 1, 1);circle(1840, 1051, 1, 1);
    circle(1453, 807, 1, 1);circle(1307, 766, 1, 1);circle(899, 772, 1, 1);circle(508, 771, 1, 1);circle(186, 733, 1, 1);


    //Moon
    glPushMatrix();
    glTranslatef(-moon_position_x,-moon_position_x*.5,0);
    moon(1700, 900, 100, 100,0.61,0.98,1,0.58,0.85,1);
    //Moon shades
    glColor3f(0.47f,0.77f,1.0f);
    anti_clock_circle(1770, 950, 8, 15, .7);
    anti_clock_circle(1660, 840, 20, 30, .7);
    anti_clock_circle(1758, 837, 9, 16, -.7);
    anti_clock_circle(1758, 865, 8, 10, -.5);
    anti_clock_circle(1620, 870, 5, 8, .7);
    anti_clock_circle(1637, 960, 3, 5, -.5);
    glPopMatrix();



    //Cloud 1
    glPushMatrix();
    glTranslatef(+cloud_position1,0,0);

    //light color
    glColor3f(0.36f,0.6f,0.81f);
    circle(95, 1000, 20, 20);
    circle(65, 1027, 20, 20);
    circle(40, 1040, 20, 20);
    circle(75, 1015, 20, 20);

    //dark color
    glColor3f(0.07f,0.22f,0.55f);
    circle(0, 1000, 25, 25);
    circle(90, 1000, 20, 20);
    circle(30, 1030, 30, 30);
    circle(25, 1015, 25, 25);
    circle(25, 1005, 25, 25);
    circle(60, 1027, 20, 20);
    circle(35, 1040, 20, 20);
    circle(70, 1015, 20, 20);
    circle(70, 1000, 20, 20);
    circle(50, 1000, 20, 20);
    glPopMatrix();


    // Cloud 2
    glPushMatrix();
    glTranslatef(+cloud_position2,0,0);

    //light color
    glColor3f(0.36f,0.6f,0.81f);
    circle(63,890,27,27);
    circle(90,881,20,20);

    //Dark color
    glColor3f(0.07f,0.22f,0.55f);
    circle(16,880,15,15);
    circle(29,891,9,9);
    circle(58,890,27,27);
    circle(85,881,20,20);

    glBegin(GL_QUADS);
    glColor3f(0.07f,0.22f,0.55f);
    glVertex2f(17, 883);
    glVertex2f(85, 883);
    glVertex2f(85, 861);
    glVertex2f(17, 865);
    glEnd();
    glPopMatrix();


    //cloud 3
    glPushMatrix();
    glTranslatef(-cloud_position3,0,0);
    //light color
    glColor3f(0.07f,0.22f,0.55f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    //dark color
    glColor3f(0.36f,0.6f,0.81f);
    circle(80,842,16,16);
    circle(100,841,10,10);
    circle(112,837,6,6);
    circle(126,833,10,10);
    circle(137,825,10,10);
    circle(149,816,6,6);
    glColor3f(0.07f,0.22f,0.55f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    circle(74,840,16,16);
    circle(80,827,30,15);
    circle(95,840,10,10);
    circle(108,834,6,6);
    circle(122,831,10,10);
    circle(132,825,10,10);
    circle(144,816,6,6);

    glBegin(GL_QUADS);
    glColor3f(0.07f,0.22f,0.55f);
    glVertex2f(12, 818);
    glVertex2f(146, 818);
    glVertex2f(144, 810);
    glVertex2f(13, 810);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.07f,0.22f,0.55f);
    glVertex2f(20, 832);
    glVertex2f(138, 832);
    glVertex2f(138, 817);
    glVertex2f(20, 817);
    glEnd();
    glPopMatrix();


    //cloud 4
    glPushMatrix();
    glTranslatef(-cloud_position4,0,0);
    //light color
    glColor3f(0.36f,0.6f,0.81f);
    circle(23, 933, 21, 21);
    circle(55, 949, 20, 20);
    circle(83, 944, 14, 14);
    circle(95, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    //dark color
    glColor3f(0.07f,0.22f,0.55f);
    circle(23, 933, 21, 21);
    circle(50, 949, 20, 20);
    circle(80, 943, 14, 14);
    circle(90, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    glPopMatrix();


    //Plane
    glPushMatrix();
    glTranslatef(-plane_position,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.12f,0.27f,0.5f);
    plane();
    glPopMatrix();

    //Mountain 1
    glColor3f(0.0f,0.11f,0.33f);
    mountain1();

    //Mountain1 Shadow 1
    glColor3f(0.0f,0.42f,0.71f);
    mountain1_shadow_1();

    //Mountain1 Shadow 2
    mountain1_shadow_2();

    //Mountain1 Shadow 3
    mountain1_shadow_3();

    //Mountain 2
    //glColor3f(0.07f,0.18f,0.37f);
    glColor3f(0.0f,0.16f,0.37f);
    mountain2();

    //Water
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.42f,0.63f);
    water();

    //Mountain 3 front land
    glBegin(GL_POLYGON);
    glColor3f(0.06f,0.17f,0.37f);
    mountain_front_land();
    //Mountain 3
    glColor3f(0.09f,0.23f,0.48f);
    mountain3();
    glEnd();


    //Tree type 1 on mountain
    tree_type1(885, 513, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(550, 490, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(1700, 425, 80,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(540, 604, 40,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(355, 613, 40,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(1650, 630, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(830, 737, 20,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);

    //Tree type 1 on mountain
    tree_type2(995, 504, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type2(1528, 607, 60,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1083, 515, 67,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(421, 478, 70,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(731, 540, 40,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1559, 692, 20,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1216,703, 30,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1142,549, 60,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);

    //Tree type 1 on mountain
    tree_type3(1774, 627, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(1600, 616, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(636, 489, 75,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(1339, 606, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(380,653, 20,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(297,617, 40,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(1216,703, 30,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(995, 504, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(350, 468, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);


    //House 1 on mountain 3(middle house)////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //Second flower
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1395, 642);glVertex2f(1378, 628);glVertex2f(1408, 624);glVertex2f(1399, 633);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.27f,0.59f);
    glVertex2f(1352, 624);glVertex2f(1361, 633);glVertex2f(1395, 642);glVertex2f(1378, 628);
    glEnd();

    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(1399, 633);glVertex2f(1412, 633);glVertex2f(1421, 624);glVertex2f(1408, 624);
    glEnd();

    //rood lines
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1378, 628);glVertex2f(1395, 641);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glVertex2f(1399, 633);glVertex2f(1412, 633);
    glVertex2f(1412, 633);glVertex2f(1421, 624);
    glEnd();


    //rood lines
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1394, 640);glVertex2f(1406, 624);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.01f,0.38f);
    glVertex2f(1356, 624);glVertex2f(1378, 628);glVertex2f(1378, 611);glVertex2f(1356, 611);
    glEnd();

    //Right wall
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1378, 628);glVertex2f(1417, 624);glVertex2f(1417, 611);glVertex2f(1378, 611);
    glEnd();

    //roof lines
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glEnd();

     //Gate
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1395, 611);glVertex2f(1395, 620);glVertex2f(1399, 620);glVertex2f(1399, 611);
    //Gate's Left window
    glVertex2f(1382, 620);glVertex2f(1382, 615);glVertex2f(1391, 615);glVertex2f(1391, 620);
    // Gate's right window
    glVertex2f(1403, 620);glVertex2f(1403, 615);glVertex2f(1412, 615);glVertex2f(1412, 620);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1361, 620);glVertex2f(1365, 620);glVertex2f(1365, 615);glVertex2f(1361, 615);
    //Left wall's right window
    glVertex2f(1370, 620);glVertex2f(1374, 620);glVertex2f(1374, 615);glVertex2f(1370, 615);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1355, 615);glVertex2f(1355, 611);
    glVertex2f(1357, 615);glVertex2f(1357, 611);
    glVertex2f(1361, 615);glVertex2f(1361, 611);
    glVertex2f(1365, 615);glVertex2f(1365, 611);
    glVertex2f(1369, 615);glVertex2f(1369, 611);
    glVertex2f(1378, 615);glVertex2f(1378, 611);
    glVertex2f(1382, 615);glVertex2f(1382, 611);
    glVertex2f(1391, 615);glVertex2f(1391, 611);
    glVertex2f(1395, 615);glVertex2f(1395, 611);
    glVertex2f(1399, 615);glVertex2f(1399, 611);
    glVertex2f(1408, 615);glVertex2f(1408, 611);
    glVertex2f(1412, 615);glVertex2f(1412, 611);
    glVertex2f(1417, 615);glVertex2f(1417, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1354, 615);glVertex2f(1382, 615);
    glVertex2f(1382, 615);glVertex2f(1421, 615);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1354, 611);glVertex2f(1382, 611);glVertex2f(1382, 611);glVertex2f(1421, 611);
    //Pillar
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1395, 611);glVertex2f(1395, 601);
    glVertex2f(1390, 611);glVertex2f(1390, 602);
    glVertex2f(1404, 611);glVertex2f(1404, 603);
    glVertex2f(1412, 611);glVertex2f(1412, 603);
    glVertex2f(1417, 611);glVertex2f(1417, 603);
    glVertex2f(1374, 611);glVertex2f(1374, 603);
    glVertex2f(1367, 611);glVertex2f(1367, 606);
    glVertex2f(1361, 611);glVertex2f(1361, 607);
    glEnd();

    //House 2 on mountain 3(left most house)////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //second floor
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.01f,0.38f);
    glVertex2f(578, 528);glVertex2f(595, 514);glVertex2f(565, 510);glVertex2f(574, 519);
    glEnd();


    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(621, 510);glVertex2f(612, 519);glVertex2f(578, 528);glVertex2f(595, 514);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.27f,0.59f);
    glVertex2f(574, 519);glVertex2f(561, 519);glVertex2f(552, 510);glVertex2f(565, 510);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(595, 514);glVertex2f(578, 527);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glVertex2f(574, 519);glVertex2f(561, 519);
    glVertex2f(561, 519);glVertex2f(552, 510);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(579, 526);glVertex2f(567, 510);
    glEnd();


    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(617, 510);glVertex2f(595, 514);glVertex2f(595, 497);glVertex2f(617, 497);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.01f,0.38f);
    glVertex2f(595, 514);glVertex2f(556, 510);glVertex2f(556, 497);glVertex2f(595, 497);
    glEnd();


    //roof lines
    glLineWidth(2);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glEnd();


    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(578, 497);glVertex2f(578, 506);glVertex2f(574, 506);glVertex2f(574, 497);
    //Gate's Left window
    glVertex2f(591, 506);glVertex2f(591, 501);glVertex2f(582, 501);glVertex2f(582, 506);
    // Gate's right window
    glVertex2f(570, 506);glVertex2f(570, 501);glVertex2f(561, 501);glVertex2f(561, 506);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(612, 506);glVertex2f(608, 506);glVertex2f(608, 501);glVertex2f(612, 501);
    //Left wall's right window
    glVertex2f(603, 506);glVertex2f(599, 506);glVertex2f(599, 501);glVertex2f(603, 501);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(619, 501);glVertex2f(619, 497);
    glVertex2f(616, 501);glVertex2f(616, 497);
    glVertex2f(612, 501);glVertex2f(612, 497);
    glVertex2f(608, 501);glVertex2f(608, 497);
    glVertex2f(604, 501);glVertex2f(604, 497);
    glVertex2f(595, 501);glVertex2f(595, 497);
    glVertex2f(591, 501);glVertex2f(591, 497);
    glVertex2f(582, 501);glVertex2f(582, 497);
    glVertex2f(578, 501);glVertex2f(578, 497);
    glVertex2f(574, 501);glVertex2f(574, 497);
    glVertex2f(565, 501);glVertex2f(565, 497);
    glVertex2f(561, 501);glVertex2f(561, 497);
    glVertex2f(556, 501);glVertex2f(556, 497);
    glVertex2f(553, 501);glVertex2f(553, 497);
    glVertex2f(619, 501);glVertex2f(591, 501);
    glVertex2f(591, 501);glVertex2f(552, 501);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(619, 497);glVertex2f(591, 497);
    glVertex2f(591, 497);glVertex2f(552, 497);
    //pillar
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(578, 497);glVertex2f(578, 487);
    glVertex2f(583, 497);glVertex2f(583, 488);
    glVertex2f(569, 497);glVertex2f(569, 489);
    glVertex2f(561, 497);glVertex2f(561, 489);
    glVertex2f(556, 497);glVertex2f(556, 489);
    glVertex2f(599, 497);glVertex2f(599, 489);
    glVertex2f(606, 497);glVertex2f(606, 492);
    glVertex2f(612, 497);glVertex2f(612, 493);
    glEnd();


    //House 3 on mountain 3(right most house)////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //second floor
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1818, 662);glVertex2f(1801, 648);glVertex2f(1831, 644);glVertex2f(1822, 653);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(1775, 644);glVertex2f(1784, 653);glVertex2f(1818, 662);glVertex2f(1801, 648);
    glEnd();
    //roof lines
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 648);glVertex2f(1818, 661);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();
    //roof lines
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1817, 660);glVertex2f(1829, 644);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1779, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 631);glVertex2f(1779, 631);
    glEnd();


    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1801, 648);glVertex2f(1840, 644);
    glVertex2f(1840, 631);glVertex2f(1801, 631);
    glEnd();

    //roof lines
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();

    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1818, 631);glVertex2f(1818, 640);
    glVertex2f(1822, 640);glVertex2f(1822, 631);
    //Gate's Left window
    glVertex2f(1805, 640);glVertex2f(1805, 635);
    glVertex2f(1814, 635);glVertex2f(1814, 640);
    // Gate's right window
    glVertex2f(1826, 640);glVertex2f(1826, 635);
    glVertex2f(1835, 635);glVertex2f(1835, 640);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1784, 640);glVertex2f(1788, 640);
    glVertex2f(1788, 635);glVertex2f(1784, 635);
    //Left wall's right window
    glVertex2f(1793, 640);glVertex2f(1797, 640);
    glVertex2f(1797, 635);glVertex2f(1793, 635);
    glEnd();

    //railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1777, 635);glVertex2f(1777, 631);
    glVertex2f(1780, 635);glVertex2f(1780, 631);
    glVertex2f(1784, 635);glVertex2f(1784, 631);
    glVertex2f(1788, 635);glVertex2f(1788, 631);
    glVertex2f(1792, 635);glVertex2f(1792, 631);
    glVertex2f(1801, 635);glVertex2f(1801, 631);
    glVertex2f(1805, 635);glVertex2f(1805, 631);
    glVertex2f(1814, 635);glVertex2f(1814, 631);
    glVertex2f(1818, 635);glVertex2f(1818, 631);
    glVertex2f(1822, 635);glVertex2f(1822, 631);
    glVertex2f(1831, 635);glVertex2f(1831, 631);
    glVertex2f(1835, 635);glVertex2f(1835, 631);
    glVertex2f(1840, 635);glVertex2f(1840, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1777, 635);glVertex2f(1805, 635);
    glVertex2f(1805, 635);glVertex2f(1844, 635);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1777, 631);glVertex2f(1805, 631);
    glVertex2f(1805, 631);glVertex2f(1844, 631);
    //pillar
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1818, 631);glVertex2f(1818, 621);
    glVertex2f(1813, 631);glVertex2f(1813, 622);
    glVertex2f(1827, 631);glVertex2f(1827, 623);
    glVertex2f(1835, 631);glVertex2f(1835, 623);
    glVertex2f(1840, 631);glVertex2f(1840, 623);
    glVertex2f(1844, 631);glVertex2f(1844, 623);
    glVertex2f(1797, 631);glVertex2f(1797, 627);
    glVertex2f(1790, 631);glVertex2f(1790, 626);
    glVertex2f(1784, 631);glVertex2f(1784, 627);
    glEnd();






    //waterfall front water shade
    glPushMatrix();
    glTranslatef(0,-waterfall_on_river_position,0);
    glColor3f(0.36f,0.67f,0.86f);
    circle(1765, 425, 50, 8);
    glPopMatrix();

    //cell tower/////////////////////////////////////////////

    //Middle white line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.31f,0.41f,0.64f);
    glVertex2f(1893, 917);glVertex2f(1893, 685);

    //Middle red line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.29f);
    glVertex2f(1893, 737);glVertex2f(1893, 788);
    glVertex2f(1893, 840);glVertex2f(1893, 865);
    glVertex2f(1893, 891);glVertex2f(1893, 917);
    glEnd();

    // white Part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.28f,0.37f,0.56f);
    glVertex2f(1893, 927);glVertex2f(1893, 917);
    //1
    glVertex2f(1868, 685);glVertex2f(1874, 737);
    glVertex2f(1868, 685);glVertex2f(1870, 699);
    glVertex2f(1870, 699);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1873, 724);
    glVertex2f(1873, 724);glVertex2f(1874, 737);

    glVertex2f(1915, 685);glVertex2f(1912, 737);
    glVertex2f(1915, 685);glVertex2f(1914, 699);
    glVertex2f(1914, 699);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1913, 724);
    glVertex2f(1913, 724);glVertex2f(1912, 737);

    glVertex2f(1868, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1912, 737);

    glVertex2f(1915, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1874, 737);
    //1 horizontal

    glVertex2f(1870, 699);glVertex2f(1893, 699);
    glVertex2f(1893, 699);glVertex2f(1914, 699);

    glVertex2f(1873, 724);glVertex2f(1893, 724);
    glVertex2f(1893, 724);glVertex2f(1913, 724);

    //3
    glVertex2f(1879, 788);glVertex2f(1884, 840);
    glVertex2f(1908, 788);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1880, 802);
    glVertex2f(1880, 802);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1882, 828);
    glVertex2f(1882, 828);glVertex2f(1884, 840);

    glVertex2f(1908, 788);glVertex2f(1907, 802);
    glVertex2f(1907, 802);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1905, 828);
    glVertex2f(1905, 828);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1904, 840);

    glVertex2f(1908, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1884, 840);

    //horizontal
    glVertex2f(1880, 802);glVertex2f(1893, 802);
    glVertex2f(1893, 802);glVertex2f(1907, 802);

    glVertex2f(1882, 828);glVertex2f(1893, 828);
    glVertex2f(1893, 828);glVertex2f(1905, 828);


    //4
    glVertex2f(1886, 865);glVertex2f(1887, 872);
    glVertex2f(1887, 872);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1887, 885);
    glVertex2f(1887, 885);glVertex2f(1887, 891);

    glVertex2f(1902, 865);glVertex2f(1902, 872);
    glVertex2f(1902, 872);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1901, 885);
    glVertex2f(1901, 885);glVertex2f(1901, 891);

    glVertex2f(1886, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1901, 891);

    glVertex2f(1902, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1887, 891);

    //horizontal


    glVertex2f(1887, 872);glVertex2f(1893, 872);
    glVertex2f(1893, 872);glVertex2f(1902, 872);

    glVertex2f(1887, 885);glVertex2f(1893, 885);
    glVertex2f(1893, 885);glVertex2f(1901, 885);



    glEnd();

    //Darker White part
    glBegin(GL_LINES);
    glColor3f(0.23f,0.31f,0.48);
    //1
    glVertex2f(1893, 685);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1893, 737);

    glVertex2f(1893, 685);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1893, 737);
    //3

    glVertex2f(1893, 788);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1893, 840);

    glVertex2f(1893, 788);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1893, 840);
    //4
    glVertex2f(1893, 865);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1893, 891);

    glVertex2f(1893, 865);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1893, 891);
    glEnd();


    //Red part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.29f);
    //2
    glVertex2f(1874, 737);glVertex2f(1875, 750);
    glVertex2f(1875, 750);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1878, 776);
    glVertex2f(1878, 776);glVertex2f(1879, 788);

    glVertex2f(1912, 737);glVertex2f(1911, 750);
    glVertex2f(1911, 750);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1909, 776);
    glVertex2f(1909, 776);glVertex2f(1908, 788);

    glVertex2f(1874, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1908, 788);
    glVertex2f(1912, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1879, 788);

    glVertex2f(1893, 737);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1893, 788);
    glVertex2f(1893, 737);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1893, 788);
    //2 horizontal

    glVertex2f(1875, 750);glVertex2f(1893, 750);
    glVertex2f(1893, 750);glVertex2f(1911, 750);

    glVertex2f(1878, 776);glVertex2f(1893, 776);
    glVertex2f(1893, 776);glVertex2f(1909, 776);


    //3

    glVertex2f(1884, 840);glVertex2f(1884, 847);
    glVertex2f(1884, 847);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1885, 860);
    glVertex2f(1885, 860);glVertex2f(1886, 865);

    glVertex2f(1904, 840);glVertex2f(1904, 847);
    glVertex2f(1904, 847);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1903, 860);
    glVertex2f(1903, 860);glVertex2f(1902, 865);


    glVertex2f(1884, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1902, 865);

    glVertex2f(1904, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1886, 865);

    glVertex2f(1893, 840);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1893, 865);

    glVertex2f(1893, 840);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1893, 865);

    glVertex2f(1884, 847);glVertex2f(1893, 847);
    glVertex2f(1893, 847);glVertex2f(1904, 847);

    glVertex2f(1885, 860);glVertex2f(1893, 860);
    glVertex2f(1893, 860);glVertex2f(1903, 860);

    //5

    glVertex2f(1887, 891);glVertex2f(1887, 898);
    glVertex2f(1887, 898);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1887, 911);
    glVertex2f(1887, 911);glVertex2f(1887, 917);

    glVertex2f(1901, 891);glVertex2f(1901, 898);
    glVertex2f(1901, 898);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1901, 911);
    glVertex2f(1901, 911);glVertex2f(1901, 917);

    glVertex2f(1887, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1901, 917);

    glVertex2f(1901, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1887, 917);

    glVertex2f(1893, 891);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1893, 917);

    glVertex2f(1893, 891);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1893, 917);

    glVertex2f(1887, 898);glVertex2f(1893, 898);
    glVertex2f(1893, 898);glVertex2f(1901, 898);

    glVertex2f(1887, 911);glVertex2f(1893, 911);
    glVertex2f(1893, 911);glVertex2f(1901, 911);

    glVertex2f(1887, 917);glVertex2f(1893, 917);
    glVertex2f(1893, 917);glVertex2f(1901, 917);





    //cell tower drum holder
    glBegin(GL_LINES);

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1887, 885);glVertex2f(1878, 885);
    glVertex2f(1901, 885);glVertex2f(1909, 885);

    glVertex2f(1887, 891);glVertex2f(1878, 891);
    glVertex2f(1901, 891);glVertex2f(1909, 891);


    glVertex2f(1887, 904);glVertex2f(1878, 904);
    glVertex2f(1901, 904);glVertex2f(1909, 904);

    glVertex2f(1887, 911);glVertex2f(1878, 911);
    glVertex2f(1901, 911);glVertex2f(1909, 911);


    glEnd();

    //cell tower long drum
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.54f,0.65f,0.88f);
    glVertex2f(1880, 880);glVertex2f(1880, 896);
    glVertex2f(1908, 880);glVertex2f(1908, 896);
    glColor3f(0.38f,0.49f,0.75f);
    glVertex2f(1882, 880);glVertex2f(1882, 896);
    glVertex2f(1906, 880);glVertex2f(1906, 896);
    glVertex2f(1893, 880);glVertex2f(1893, 896);
    glVertex2f(1895, 880);glVertex2f(1895, 896);
    glEnd();


    //cell tower drum
    glColor3f(0.24f,0.43f,0.73f);
    circle(1881,908,5,8);
    circle(1906,908,5,8);
    glColor3f(0.54f,0.65f,0.88f);
    circle(1878,908,5,8);
    circle(1909,908,5,8);

    //light
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.29f);
    glVertex2f(1899,917);
    glVertex2f(1899,920);
    glEnd();

    if(tower_light)moon(1899,919,6,6,1.0,0.0,0.0,0,0.1,0.35);



    //Mountain 4
    glColor3f(0.06f,0.17f,0.37f);
    mountain4();

    //Waterfall with shade
    glBegin(GL_POLYGON);
    glColor3f(0.36f,0.67f,0.86f);
    waterfall_with_shade_1();
    glColor3f(0.0f,0.42f,0.63f);
    waterfall_with_shade_2();


    glLineWidth(1);
    //waterfall shade 1
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position1,0);
    glBegin(GL_LINES);
    glColor3f(0.47f,0.77f,1.0f);
    glVertex2f(1752,545);glVertex2f(1752,530);
    glVertex2f(1746,540);glVertex2f(1746,525);
    glEnd();
    glPopMatrix();

    //waterfall shade 2
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position2,0);
    glBegin(GL_LINES);
    glVertex2f(1754,520);glVertex2f(1754,510);
    glVertex2f(1747,515);glVertex2f(1747,500);
    glVertex2f(1741,525);glVertex2f(1741,510);
    glEnd();
    glPopMatrix();

    //waterfall shade 3
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position3,0);
    glBegin(GL_LINES);
    glVertex2f(1752,495);glVertex2f(1752,480);
    glVertex2f(1745,493);glVertex2f(1745,475);
    glVertex2f(1738,490);glVertex2f(1738,475);
    glEnd();

    glPopMatrix();

    //River front Land
    glBegin(GL_POLYGON);
    glColor3f(0.02f,0.22f,0.44f);
    glVertex2f(0,0);glVertex2f(0,300);glVertex2f(1920,300);glVertex2f(1920,0);
    glEnd();

    //fire surrounding light
    moon(680, 137, 200, 90,1,0.8,0,0.02,0.22,0.44);
    if(fire_light)moon(680, 137, 200, 90,0.96,0.77,0,0.02,0.22,0.44);


    //Trees on mountain front(beside water fall)
    tree_type1(1700, 425, 75,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);

    //ALL land shades

    glColor3f(0.0f,0.33f,0.62f);
    land_shade();



    //Moving water shade STARTS
    glPushMatrix();
    glTranslatef(-water_shade_position1,0,0);
    //Water shade 1(Moving)
    glBegin(GL_POLYGON);
    glColor3f(0.36f,0.67f,0.86f);
    water_shade1();
    glPopMatrix();

    glPushMatrix();
    //Water shade 2(Moving)
    glTranslatef(-water_shade_position2,0,0);
    glBegin(GL_POLYGON);
    water_shade2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position3,0,0);
    //Water shade 3(Moving)
    glBegin(GL_POLYGON);;
    water_shade3();
    glPopMatrix();


    //Water shade 4(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position4,0,0);
    glBegin(GL_POLYGON);
    water_shade4();
    glPopMatrix();

    //Water shade 5(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position5,0,0);
    glBegin(GL_POLYGON);
    water_shade5();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position6,0,0);
    glBegin(GL_POLYGON);
    water_shade6();
    glPopMatrix();

    //Mountain 3 front land
    glColor3f(0.09f,0.23f,0.48f);
    mountain_front_land();
    glLineWidth(2);

    //Road
    glBegin(GL_POLYGON);
    glColor3f(0.22f,0.18f,0.35f);
    glVertex2f(1920,0);
    bezier_curve4(1230,0,1550,150,1300,280,1590,298);
    glColor3f(0.11f,0.11f,0.31f);
    glVertex2f(1920,300);

    //Road's left side hill
    glEnd();
    glLineWidth(2);
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.11f,0.33f);
    glVertex2f(1920,100);
    glVertex2f(1920,0);
    bezier_curve4(1600,0,1700,150,1400,250,1590,298);
    bezier_curve3(1590,298,1700,330,1920,340);
    glEnd();



    //Tent 1(on left)______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.13f,0.28f);//glColor3f(0.09f,0.29f,0.74f);//glColor3f(0.57f,0.45f,0.38f);
    glVertex2f(276,169);glVertex2f(271,207);glVertex2f(456,318);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(354,133);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);
    glVertex2f(456,318);glVertex2f(551,185);glVertex2f(542,187);glVertex2f(450,318);
    glEnd();



    //Front with gate
    glBegin(GL_POLYGON);

    glColor3f(0.74f, 0.46f, 0.16f);//glColor3f(0.99f,0.62f,0.25f);
    glVertex2f(354,133);
    glVertex2f(347,175);
    glColor3f(0.99f,0.62f,0.25f);
    glVertex2f(452,314);
    glVertex2f(542,187);
    glVertex2f(526,145);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.14f,0.37f);
    glVertex2f(252,203);glVertex2f(346,317);glVertex2f(456,318);
    glVertex2f(340,176);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.4f,0.24f,0.0f);
    glVertex2f(461,140);glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(455,251);glVertex2f(454,251);glVertex2f(450,139);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.18f,0.11f,0.0f);
    glVertex2f(290,141);glVertex2f(296,141);glVertex2f(293,119);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(221,192);glVertex2f(228,192);glVertex2f(225,174);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(581,167);glVertex2f(587,167);glVertex2f(584,147);
    glEnd();



    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.18f,0.11f,0.0f);
    glVertex2f(289,134);glVertex2f(340,178);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(220,184);glVertex2f(253,204);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(588,158);glVertex2f(548,187);
    glEnd();



    //Tent 2(on right)______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.57f,0.45f,0.38f);
    glVertex2f(926,199);glVertex2f(931,237);glVertex2f(746,348);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(848,163);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.74f, 0.46f, 0.16f);
    glVertex2f(746,348);glVertex2f(651,215);glVertex2f(660,217);glVertex2f(752,348);
    glEnd();

    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(0.99f,0.62f,0.25f);
    glVertex2f(848,163);glVertex2f(857,211);glVertex2f(750,344);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(741,172);
    glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(748,281);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(0.09f,0.29f,0.74f);
    glVertex2f(950,233);glVertex2f(856,347);
    glColor3f(0.17f,0.64f,0.98f);
    glVertex2f(746,348);
    glColor3f(0.09f,0.29f,0.74f);
    glVertex2f(859,207);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.4f,0.24f,0.0f);
    glVertex2f(741,170);glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(747,281);glVertex2f(748,281);glVertex2f(752,169);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f,0.18f,0.0f);
    glVertex2f(912,171);glVertex2f(906,171);glVertex2f(909,149);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(981,222);glVertex2f(974,222);glVertex2f(977,204);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.58f,0.3f,0.0f);
    glVertex2f(621,197);glVertex2f(615,197);glVertex2f(618,177);
    glEnd();

    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.3f,0.18f,0.0f);
    glVertex2f(913,164);glVertex2f(860,207);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(982,214);glVertex2f(949,234);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.49,0.25,0.0f);
    glVertex2f(614,188);glVertex2f(654,217);
    glEnd();


    //Big tree
    glBegin(GL_POLYGON);
    //Light color
    glColor3f(0.02f,0.02f,0.09f);
    glVertex2f(0, 200);
    //Most dark color
    glColor3f(0.02f,0.02f,0.09f);
    big_tree_root_with_shade1();
    //Dark color
    glColor3f(0.02f,0.02f,0.09f);
    big_tree_root_with_shade2();


    //Big tree leaf
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.05f,0.24f);
    tree_leaf1();
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.07f,0.28f);
    tree_leaf2();
    glBegin(GL_POLYGON);
    glColor3f(0.02f,0.03f,0.17f);
    tree_leaf3();
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.07f,0.25f);
    tree_leaf4();



    //River front 3 right side trees
    tree_type1(1910,90, 450,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type2(1350, 200, 300,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type3(1590, 270, 275,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);


    glLineWidth(2);

    //Campfire wood

    //campfire wood dark tail circle
    glColor3f(0.56f,0.33f,0.0f);
    circle(655, 144,5,6);
    circle(710, 144,5,6);

    //Wood 1
    glBegin(GL_QUADS);
    glColor3f(0.56f,0.33f,0.0f);
    glVertex2f(646, 133);
    glVertex2f(650, 118);
    glVertex2f(711, 138);
    glVertex2f(709, 150);
    glEnd();

    //Wood 1 shades
    glBegin(GL_LINES);
    glColor3f(0.45f,0.28f,0.17f);
    glVertex2f(651,126);
    glVertex2f(678,136);
    glVertex2f(652,122);
    glVertex2f(676,130);
    glVertex2f(683,135);
    glVertex2f(713,143);
    glVertex2f(686,132);
    glVertex2f(700,136);
    glEnd();
    //Wood 2
    glBegin(GL_QUADS);
    glColor3f(0.56f,0.33f,0.0f);
    glVertex2f(713, 119);
    glVertex2f(715, 132);
    glVertex2f(656, 149);
    glVertex2f(653, 137);
    glEnd();
    //Wood 2 shades
    glBegin(GL_LINES);
    glColor3f(0.45f,0.28f,0.17f);
    glVertex2f(713,122);
    glVertex2f(670,135);
    glVertex2f(714,127);
    glVertex2f(700,131);
    glVertex2f(715,130);
    glVertex2f(698,135);
    glVertex2f(650,145);
    glVertex2f(675,137);
    glVertex2f(655,149);
    glVertex2f(664,146);
    glEnd();

    //campfire wood light circle
    glColor3f(0.89f,0.71f,0.51f);
    circle(648, 125,4,7);
    circle(714, 125,4,7);


    //Moving fire 1
    glPushMatrix();
    glTranslatef(0,+smoke_position1,0);
    glBegin(GL_POLYGON);
    glColor3f(0.96f,0.47f,0.24f);
    fire1();
    glPopMatrix();
    //Fire shade 1
    glColor3f(0.96f,0.47f,0.24f);
    fire1();

    //Moving fire 2
    glPushMatrix();
    glTranslatef(0,+smoke_position2,0);
    glBegin(GL_POLYGON);
    glColor3f(0.98f,0.76f,0.22f);
    fire2();
    glPopMatrix();

        //Fire shade 2
    glColor3f(0.98f,0.76f,0.22f);
    fire2();

    //Moving fire 3
    glPushMatrix();
    glTranslatef(0,+smoke_position3,0);
    glBegin(GL_POLYGON);
    glColor3f(0.99f,0.89f,0.67f);
    fire3();
    glPopMatrix();


    //Fire shade 3
    glColor3f(0.99f,0.89f,0.67f);
    fire3();


    glFlush(); // Render now
}

void sunset() {
    glClearColor(0.61f,0.95f,1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLineWidth(2);


    glBegin(GL_POLYGON);
    glColor3f(0.84f,0.14f,0.26f);
    glVertex2f(0,1080);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0,425);
    glVertex2f(1920,425);
    glColor3f(0.84f,0.14f,0.26f);
    glVertex2f(1920,1080);

    glEnd();



    //Sun
    glPushMatrix();
    glTranslatef(-moon_position_x,-moon_position_x*.5,0);
    glColor3f(1.0f,0.93f,0.0f);
    circle(1700, 900, 100, 100);
    glPopMatrix();

    //Cloud 1
    glPushMatrix();
    glTranslatef(+cloud_position1,0,0);

    glColor3f(0.98f,0.83f,0.34f);
    circle(95, 1000, 20, 20);
    circle(65, 1027, 20, 20);
    circle(40, 1040, 20, 20);
    circle(75, 1015, 20, 20);

    glColor3f(0.93f,0.61f,0.49f);
    circle(0, 1000, 25, 25);
    circle(90, 1000, 20, 20);
    circle(30, 1030, 30, 30);
    circle(25, 1015, 25, 25);
    circle(25, 1005, 25, 25);
    circle(60, 1027, 20, 20);
    circle(35, 1040, 20, 20);
    circle(70, 1015, 20, 20);
    circle(70, 1000, 20, 20);
    circle(50, 1000, 20, 20);



    glPopMatrix();


    // Cloud 2
    glPushMatrix();
    glTranslatef(+cloud_position2,0,0);
    glColor3f(0.98f,0.83f,0.34f);
    //circle(16,880,15,15);
    //circle(29,891,9,9);
    circle(63,890,27,27);
    circle(90,881,20,20);

    glColor3f(0.93f,0.61f,0.49f);
    circle(16,880,15,15);
    circle(29,891,9,9);
    circle(58,890,27,27);
    circle(85,881,20,20);

    glBegin(GL_QUADS);
    glColor3f(0.93f,0.61f,0.49f);
    glVertex2f(17, 883);
    glVertex2f(85, 883);
    glVertex2f(85, 861);
    glVertex2f(17, 865);
    glEnd();
    glPopMatrix();


    //cloud 3
    glPushMatrix();
    glTranslatef(-cloud_position3,0,0);
    glColor3f(0.93f,0.61f,0.49f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);

    glColor3f(0.98f,0.83f,0.34f);
    circle(80,842,16,16);
    circle(100,841,10,10);
    circle(112,837,6,6);
    circle(126,833,10,10);
    circle(137,825,10,10);
    circle(149,816,6,6);
    glColor3f(0.93f,0.61f,0.49f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    circle(74,840,16,16);
    circle(80,827,30,15);
    circle(95,840,10,10);
    circle(108,834,6,6);
    circle(122,831,10,10);
    circle(132,825,10,10);
    circle(144,816,6,6);

    glBegin(GL_QUADS);
    glColor3f(0.93f,0.61f,0.49f);
    glVertex2f(12, 818);
    glVertex2f(146, 818);
    glVertex2f(144, 810);
    glVertex2f(13, 810);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.93f,0.61f,0.49f);
    glVertex2f(20, 832);
    glVertex2f(138, 832);
    glVertex2f(138, 817);
    glVertex2f(20, 817);
    glEnd();
    glPopMatrix();


    //cloud 4
    glPushMatrix();
    glTranslatef(-cloud_position4,0,0);
    glColor3f(0.98f,0.83f,0.34f);
    circle(23, 933, 21, 21);
    circle(55, 949, 20, 20);
    circle(83, 944, 14, 14);
    circle(95, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    glColor3f(0.93f,0.61f,0.49f);
    circle(23, 933, 21, 21);
    circle(50, 949, 20, 20);
    circle(80, 943, 14, 14);
    circle(90, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    glPopMatrix();


    //Plane
    glPushMatrix();
    glTranslatef(-plane_position,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.64f,0.25f,0.0f);
    plane();
    glPopMatrix();

    //Mountain 1
    glColor3f(1.0f,0.43f,0.26f);
    mountain1();

    //Mountain1 Shadow 1
    glColor3f(1.0f,0.5f,0.29f);
    mountain1_shadow_1();

    //Mountain1 Shadow 2
    mountain1_shadow_2();

    //Mountain1 Shadow 3
    mountain1_shadow_3();

    //Mountain 2
    glColor3f(0.94f,0.28f,0.23f);
    mountain2();


    //Water
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.56f,0.29f);
    water();

    //Mountain 3 front land
    glBegin(GL_POLYGON);
    glColor3f(0.6f,0.18f,0.11f);
    mountain_front_land();
    //Mountain 3
    glColor3f(0.81,0.18f,0.25f);
    mountain3();
    glEnd();




    // type 1 on mountain
    tree_type1(885, 513, 65,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type1(550, 490, 65,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type1(1700, 425, 80,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type1(540, 604, 40,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type1(355, 613, 40,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type1(1650, 630, 65,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type1(830, 737, 20,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type2(995, 504, 65,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);

    tree_type2(1528, 607, 60,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);
    tree_type2(1083, 515, 67,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);
    tree_type2(421, 478, 70,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);
    tree_type2(731, 540, 40,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);
    tree_type2(1559, 692, 20,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);
    tree_type2(1216,703, 30,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);
    tree_type2(1142,549, 60,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);

    tree_type3(1774, 627, 70,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(1600, 616, 70,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(636, 489, 75,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(1339, 606, 70,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(380,653, 20,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(297,617, 40,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(1216,703, 30,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(995, 504, 65,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(350, 468, 70,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);




    //House 1 on mountain 3////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //Second floor
    glBegin(GL_POLYGON);
    glColor3f(0.49f,0.29f,0.06f);
    glVertex2f(1395, 642);glVertex2f(1378, 628);glVertex2f(1408, 624);glVertex2f(1399, 633);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1352, 624);glVertex2f(1361, 633);glVertex2f(1395, 642);glVertex2f(1378, 628);
    glEnd();

    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1399, 633);glVertex2f(1412, 633);glVertex2f(1421, 624);glVertex2f(1408, 624);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1378, 628);glVertex2f(1395, 641);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glVertex2f(1399, 633);glVertex2f(1412, 633);
    glVertex2f(1412, 633);glVertex2f(1421, 624);
    glEnd();



    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1394, 640);glVertex2f(1406, 624);
    glEnd();

    //Right wall
    glBegin(GL_QUADS);
    glColor3f(0.49f,0.29f,0.06f);
    glVertex2f(1356, 624);glVertex2f(1378, 628);glVertex2f(1378, 611);glVertex2f(1356, 611);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.73f,0.47f,0.11f);
    glVertex2f(1378, 628);glVertex2f(1417, 624);glVertex2f(1417, 611);glVertex2f(1378, 611);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glEnd();

     //Gate
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1395, 611);glVertex2f(1395, 620);glVertex2f(1399, 620);glVertex2f(1399, 611);
    //Gate's Left window
    glVertex2f(1382, 620);glVertex2f(1382, 615);glVertex2f(1391, 615);glVertex2f(1391, 620);
    // Gate's right window
    glVertex2f(1403, 620);glVertex2f(1403, 615);glVertex2f(1412, 615);glVertex2f(1412, 620);
    glEnd();


    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1361, 620);glVertex2f(1365, 620);glVertex2f(1365, 615);glVertex2f(1361, 615);
    //Left wall's right window
    glVertex2f(1370, 620);glVertex2f(1374, 620);glVertex2f(1374, 615);glVertex2f(1370, 615);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1355, 615);glVertex2f(1355, 611);
    glVertex2f(1357, 615);glVertex2f(1357, 611);
    glVertex2f(1361, 615);glVertex2f(1361, 611);
    glVertex2f(1365, 615);glVertex2f(1365, 611);
    glVertex2f(1369, 615);glVertex2f(1369, 611);
    glVertex2f(1378, 615);glVertex2f(1378, 611);
    glVertex2f(1382, 615);glVertex2f(1382, 611);
    glVertex2f(1391, 615);glVertex2f(1391, 611);
    glVertex2f(1395, 615);glVertex2f(1395, 611);
    glVertex2f(1399, 615);glVertex2f(1399, 611);
    glVertex2f(1408, 615);glVertex2f(1408, 611);
    glVertex2f(1412, 615);glVertex2f(1412, 611);
    glVertex2f(1417, 615);glVertex2f(1417, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1354, 615);glVertex2f(1382, 615);
    glVertex2f(1382, 615);glVertex2f(1421, 615);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1354, 611);glVertex2f(1382, 611);glVertex2f(1382, 611);glVertex2f(1421, 611);
    //Pillar
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1395, 611);glVertex2f(1395, 601);
    glVertex2f(1390, 611);glVertex2f(1390, 602);
    glVertex2f(1404, 611);glVertex2f(1404, 603);
    glVertex2f(1412, 611);glVertex2f(1412, 603);
    glVertex2f(1417, 611);glVertex2f(1417, 603);
    //glVertex2f(1421, 611);glVertex2f(1421, 603);
    glVertex2f(1374, 611);glVertex2f(1374, 603);
    glVertex2f(1367, 611);glVertex2f(1367, 606);
    glVertex2f(1361, 611);glVertex2f(1361, 607);
    glEnd();

    //House 2 on mountain 3////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //Second floor
    glBegin(GL_POLYGON);
    glColor3f(0.49f,0.29f,0.06f);
    glVertex2f(578, 528);glVertex2f(595, 514);glVertex2f(565, 510);glVertex2f(574, 519);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(621, 510);glVertex2f(612, 519);glVertex2f(578, 528);glVertex2f(595, 514);
    glEnd();

    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(574, 519);glVertex2f(561, 519);glVertex2f(552, 510);glVertex2f(565, 510);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(595, 514);glVertex2f(578, 527);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glVertex2f(574, 519);glVertex2f(561, 519);
    glVertex2f(561, 519);glVertex2f(552, 510);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(579, 526);glVertex2f(567, 510);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.73f,0.47f,0.11f);//glColor3f(0.49f,0.29f,0.06f);
    glVertex2f(617, 510);glVertex2f(595, 514);glVertex2f(595, 497);glVertex2f(617, 497);
    glEnd();

    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.49f,0.29f,0.06f);//glColor3f(0.73f,0.47f,0.11f);
    glVertex2f(595, 514);glVertex2f(556, 510);glVertex2f(556, 497);glVertex2f(595, 497);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glEnd();


    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(578, 497);glVertex2f(578, 506);glVertex2f(574, 506);glVertex2f(574, 497);
    //Gate's Left window
    glVertex2f(591, 506);glVertex2f(591, 501);glVertex2f(582, 501);glVertex2f(582, 506);
    // Gate's right window
    glVertex2f(570, 506);glVertex2f(570, 501);glVertex2f(561, 501);glVertex2f(561, 506);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(612, 506);glVertex2f(608, 506);glVertex2f(608, 501);glVertex2f(612, 501);
    //Left wall's right window
    glVertex2f(603, 506);glVertex2f(599, 506);glVertex2f(599, 501);glVertex2f(603, 501);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(619, 501);glVertex2f(619, 497);
    glVertex2f(616, 501);glVertex2f(616, 497);
    glVertex2f(612, 501);glVertex2f(612, 497);
    glVertex2f(608, 501);glVertex2f(608, 497);
    glVertex2f(604, 501);glVertex2f(604, 497);
    glVertex2f(595, 501);glVertex2f(595, 497);
    glVertex2f(591, 501);glVertex2f(591, 497);
    glVertex2f(582, 501);glVertex2f(582, 497);
    glVertex2f(578, 501);glVertex2f(578, 497);
    glVertex2f(574, 501);glVertex2f(574, 497);
    glVertex2f(565, 501);glVertex2f(565, 497);
    glVertex2f(561, 501);glVertex2f(561, 497);
    glVertex2f(556, 501);glVertex2f(556, 497);
    glVertex2f(553, 501);glVertex2f(553, 497);
    glVertex2f(619, 501);glVertex2f(591, 501);
    glVertex2f(591, 501);glVertex2f(552, 501);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(619, 497);glVertex2f(591, 497);
    glVertex2f(591, 497);glVertex2f(552, 497);
    //pillar
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(578, 497);glVertex2f(578, 487);
    glVertex2f(583, 497);glVertex2f(583, 488);
    glVertex2f(569, 497);glVertex2f(569, 489);
    glVertex2f(561, 497);glVertex2f(561, 489);
    glVertex2f(556, 497);glVertex2f(556, 489);
    glVertex2f(599, 497);glVertex2f(599, 489);
    glVertex2f(606, 497);glVertex2f(606, 492);
    glVertex2f(612, 497);glVertex2f(612, 493);
    glEnd();


    //House 3 on mountain 3////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //Second floor
    glBegin(GL_POLYGON);
    glColor3f(0.49f,0.29f,0.06f);
    glVertex2f(1818, 662);glVertex2f(1801, 648);glVertex2f(1831, 644);glVertex2f(1822, 653);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1775, 644);glVertex2f(1784, 653);glVertex2f(1818, 662);glVertex2f(1801, 648);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 648);glVertex2f(1818, 661);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1817, 660);glVertex2f(1829, 644);
    glEnd();


    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.49f,0.29f,0.06f);
    glVertex2f(1779, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 631);glVertex2f(1779, 631);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.73f,0.47f,0.11f);
    glVertex2f(1801, 648);glVertex2f(1840, 644);
    glVertex2f(1840, 631);glVertex2f(1801, 631);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();

    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1818, 631);glVertex2f(1818, 640);
    glVertex2f(1822, 640);glVertex2f(1822, 631);
    //Gate's Left window
    glVertex2f(1805, 640);glVertex2f(1805, 635);
    glVertex2f(1814, 635);glVertex2f(1814, 640);
    // Gate's right window
    glVertex2f(1826, 640);glVertex2f(1826, 635);
    glVertex2f(1835, 635);glVertex2f(1835, 640);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.08f,0.02f);
    glVertex2f(1784, 640);glVertex2f(1788, 640);
    glVertex2f(1788, 635);glVertex2f(1784, 635);
    //Left wall's right window
    glVertex2f(1793, 640);glVertex2f(1797, 640);
    glVertex2f(1797, 635);glVertex2f(1793, 635);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1777, 635);glVertex2f(1777, 631);
    glVertex2f(1780, 635);glVertex2f(1780, 631);
    glVertex2f(1784, 635);glVertex2f(1784, 631);
    glVertex2f(1788, 635);glVertex2f(1788, 631);
    glVertex2f(1792, 635);glVertex2f(1792, 631);
    glVertex2f(1801, 635);glVertex2f(1801, 631);
    glVertex2f(1805, 635);glVertex2f(1805, 631);
    glVertex2f(1814, 635);glVertex2f(1814, 631);
    glVertex2f(1818, 635);glVertex2f(1818, 631);
    glVertex2f(1822, 635);glVertex2f(1822, 631);
    glVertex2f(1831, 635);glVertex2f(1831, 631);
    glVertex2f(1835, 635);glVertex2f(1835, 631);
    glVertex2f(1840, 635);glVertex2f(1840, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1777, 635);glVertex2f(1805, 635);
    glVertex2f(1805, 635);glVertex2f(1844, 635);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.02f);
    glVertex2f(1777, 631);glVertex2f(1805, 631);
    glVertex2f(1805, 631);glVertex2f(1844, 631);
    //pillar
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1818, 631);glVertex2f(1818, 621);
    glVertex2f(1813, 631);glVertex2f(1813, 622);
    glVertex2f(1827, 631);glVertex2f(1827, 623);
    glVertex2f(1835, 631);glVertex2f(1835, 623);
    glVertex2f(1840, 631);glVertex2f(1840, 623);
    glVertex2f(1844, 631);glVertex2f(1844, 623);
    glVertex2f(1797, 631);glVertex2f(1797, 627);
    glVertex2f(1790, 631);glVertex2f(1790, 626);
    glVertex2f(1784, 631);glVertex2f(1784, 627);
    glEnd();





    //waterfall front water shade
    glPushMatrix();
    glTranslatef(0,-waterfall_on_river_position,0);
    glColor3f(0.84f,0.41f,0.18f);
    circle(1765, 425, 50, 8);
    glPopMatrix();

    //cell tower/////////////////////////////////////////////
    //tower light

    //Middle white line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.66f,0.31f,0.0f);
    glVertex2f(1893, 917);glVertex2f(1893, 685);

    //Middle red line
    glBegin(GL_LINES);
    glColor3f(0.54f,0.2f,0.0f);
    glVertex2f(1893, 737);glVertex2f(1893, 788);
    glVertex2f(1893, 840);glVertex2f(1893, 865);
    glVertex2f(1893, 891);glVertex2f(1893, 917);
    glEnd();

    // white Part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.61f,0.29f,0.0f);
    glVertex2f(1893, 927);glVertex2f(1893, 917);
    //1
    glVertex2f(1868, 685);glVertex2f(1874, 737);
    glVertex2f(1868, 685);glVertex2f(1870, 699);
    glVertex2f(1870, 699);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1873, 724);
    glVertex2f(1873, 724);glVertex2f(1874, 737);

    glVertex2f(1915, 685);glVertex2f(1912, 737);
    glVertex2f(1915, 685);glVertex2f(1914, 699);
    glVertex2f(1914, 699);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1913, 724);
    glVertex2f(1913, 724);glVertex2f(1912, 737);

    glVertex2f(1868, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1912, 737);

    glVertex2f(1915, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1874, 737);
    //1 horizontal

    glVertex2f(1870, 699);glVertex2f(1893, 699);
    glVertex2f(1893, 699);glVertex2f(1914, 699);

    glVertex2f(1873, 724);glVertex2f(1893, 724);
    glVertex2f(1893, 724);glVertex2f(1913, 724);

    //3
    glVertex2f(1879, 788);glVertex2f(1884, 840);
    glVertex2f(1908, 788);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1880, 802);
    glVertex2f(1880, 802);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1882, 828);
    glVertex2f(1882, 828);glVertex2f(1884, 840);

    glVertex2f(1908, 788);glVertex2f(1907, 802);
    glVertex2f(1907, 802);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1905, 828);
    glVertex2f(1905, 828);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1904, 840);

    glVertex2f(1908, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1884, 840);

    //horizontal
    glVertex2f(1880, 802);glVertex2f(1893, 802);
    glVertex2f(1893, 802);glVertex2f(1907, 802);

    glVertex2f(1882, 828);glVertex2f(1893, 828);
    glVertex2f(1893, 828);glVertex2f(1905, 828);


    //4
    glVertex2f(1886, 865);glVertex2f(1887, 872);
    glVertex2f(1887, 872);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1887, 885);
    glVertex2f(1887, 885);glVertex2f(1887, 891);

    glVertex2f(1902, 865);glVertex2f(1902, 872);
    glVertex2f(1902, 872);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1901, 885);
    glVertex2f(1901, 885);glVertex2f(1901, 891);

    glVertex2f(1886, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1901, 891);

    glVertex2f(1902, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1887, 891);

    //horizontal


    glVertex2f(1887, 872);glVertex2f(1893, 872);
    glVertex2f(1893, 872);glVertex2f(1902, 872);

    glVertex2f(1887, 885);glVertex2f(1893, 885);
    glVertex2f(1893, 885);glVertex2f(1901, 885);





/*

*/


    glEnd();

    //Darker White part
    glBegin(GL_LINES);
    glColor3f(0.52f,0.24f,0.0f);
    //1
    glVertex2f(1893, 685);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1893, 737);

    glVertex2f(1893, 685);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1893, 737);
    //3

    glVertex2f(1893, 788);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1893, 840);

    glVertex2f(1893, 788);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1893, 840);
    //4
    glVertex2f(1893, 865);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1893, 891);

    glVertex2f(1893, 865);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1893, 891);




    glEnd();


    //Red part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.12f,0.05f,0.0f);
    //2
    glVertex2f(1874, 737);glVertex2f(1875, 750);
    glVertex2f(1875, 750);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1878, 776);
    glVertex2f(1878, 776);glVertex2f(1879, 788);

    glVertex2f(1912, 737);glVertex2f(1911, 750);
    glVertex2f(1911, 750);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1909, 776);
    glVertex2f(1909, 776);glVertex2f(1908, 788);

    glVertex2f(1874, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1908, 788);
    glVertex2f(1912, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1879, 788);

    glVertex2f(1893, 737);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1893, 788);
    glVertex2f(1893, 737);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1893, 788);
    //2 horizontal

    glVertex2f(1875, 750);glVertex2f(1893, 750);
    glVertex2f(1893, 750);glVertex2f(1911, 750);

    glVertex2f(1878, 776);glVertex2f(1893, 776);
    glVertex2f(1893, 776);glVertex2f(1909, 776);


    //3

    glVertex2f(1884, 840);glVertex2f(1884, 847);
    glVertex2f(1884, 847);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1885, 860);
    glVertex2f(1885, 860);glVertex2f(1886, 865);

    glVertex2f(1904, 840);glVertex2f(1904, 847);
    glVertex2f(1904, 847);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1903, 860);
    glVertex2f(1903, 860);glVertex2f(1902, 865);


    glVertex2f(1884, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1902, 865);

    glVertex2f(1904, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1886, 865);

    glVertex2f(1893, 840);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1893, 865);

    glVertex2f(1893, 840);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1893, 865);

    glVertex2f(1884, 847);glVertex2f(1893, 847);
    glVertex2f(1893, 847);glVertex2f(1904, 847);

    glVertex2f(1885, 860);glVertex2f(1893, 860);
    glVertex2f(1893, 860);glVertex2f(1903, 860);

    //5

    glVertex2f(1887, 891);glVertex2f(1887, 898);
    glVertex2f(1887, 898);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1887, 911);
    glVertex2f(1887, 911);glVertex2f(1887, 917);

    glVertex2f(1901, 891);glVertex2f(1901, 898);
    glVertex2f(1901, 898);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1901, 911);
    glVertex2f(1901, 911);glVertex2f(1901, 917);

    glVertex2f(1887, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1901, 917);

    glVertex2f(1901, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1887, 917);

    glVertex2f(1893, 891);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1893, 917);

    glVertex2f(1893, 891);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1893, 917);

    glVertex2f(1887, 898);glVertex2f(1893, 898);
    glVertex2f(1893, 898);glVertex2f(1901, 898);

    glVertex2f(1887, 911);glVertex2f(1893, 911);
    glVertex2f(1893, 911);glVertex2f(1901, 911);

    glVertex2f(1887, 917);glVertex2f(1893, 917);
    glVertex2f(1893, 917);glVertex2f(1901, 917);
    glEnd();



    //cell tower drum holder
    glBegin(GL_LINES);

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1887, 885);glVertex2f(1878, 885);
    glVertex2f(1901, 885);glVertex2f(1909, 885);

    glVertex2f(1887, 891);glVertex2f(1878, 891);
    glVertex2f(1901, 891);glVertex2f(1909, 891);


    glVertex2f(1887, 904);glVertex2f(1878, 904);
    glVertex2f(1901, 904);glVertex2f(1909, 904);

    glVertex2f(1887, 911);glVertex2f(1878, 911);
    glVertex2f(1901, 911);glVertex2f(1909, 911);


    glEnd();

    //cell tower long drum
    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(1.0f,0.65f,0.0f);
    glVertex2f(1880, 880);glVertex2f(1880, 896);
    glVertex2f(1908, 880);glVertex2f(1908, 896);
    glColor3f(0.47f,0.24f,0.0f);
    glVertex2f(1882, 880);glVertex2f(1882, 896);
    glVertex2f(1906, 880);glVertex2f(1906, 896);
    glVertex2f(1893, 880);glVertex2f(1893, 896);
    glVertex2f(1895, 880);glVertex2f(1895, 896);
    glEnd();


    //cell tower drum
    glColor3f(0.47f,0.24f,0.0f);
    circle(1881,908,5,8);
    circle(1906,908,5,8);
    glColor3f(1.0f,0.65f,0.0f);
    //glColor3f(0.84f,0.55f,0.0f);
    circle(1878,908,5,8);
    circle(1909,908,5,8);

    //light
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.12f,0.05f,0.0f);
    glVertex2f(1899,917);
    glVertex2f(1899,920);
    glEnd();

    if(tower_light)moon(1899,919,3,3,1.0,0.0,0.0,0.88,0.34,0.2);



    //Mountain 4
    glColor3f(0.71f,0.17f,0.18f);
    mountain4();

    //Waterfall with shade
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.56f,0.29f);
    waterfall_with_shade_1();
    glColor3f(0.84f,0.41f,0.18f);
    waterfall_with_shade_2();

    glLineWidth(2);
    glLineWidth(1);
    //waterfall shade 1
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position1,0);
    glBegin(GL_LINES);
    glColor3f(1.0f,0.73f,0.0f);
    glVertex2f(1752,545);glVertex2f(1752,530);
    glVertex2f(1746,540);glVertex2f(1746,525);
    glEnd();
    glPopMatrix();

    //waterfall shade 2
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position2,0);
    glBegin(GL_LINES);
    glVertex2f(1754,520);glVertex2f(1754,510);
    glVertex2f(1747,515);glVertex2f(1747,500);
    glVertex2f(1741,525);glVertex2f(1741,510);
    glEnd();
    glPopMatrix();

    //waterfall shade 3
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position3,0);
    glBegin(GL_LINES);
    glVertex2f(1752,495);glVertex2f(1752,480);
    glVertex2f(1745,493);glVertex2f(1745,475);
    glVertex2f(1738,490);glVertex2f(1738,475);
    glEnd();

    glPopMatrix();

    //River front Land
    glBegin(GL_POLYGON);
    glColor3f(0.61f,0.18f,0.17f);
    glVertex2f(0,0);glVertex2f(0,300);glVertex2f(1920,300);glVertex2f(1920,0);
    glEnd();

    //Trees on mountain front
    tree_type1(1700, 425, 75,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);

    //ALL land shades
    glColor3f(0.7f,0.2f,0.17f);
    land_shade();

    //Road
    glBegin(GL_POLYGON);
    glColor3f(0.43f,0.25f,0.25f);
    glVertex2f(1920,0);
    bezier_curve4(1230,0,1550,150,1300,280,1590,298);
    glVertex2f(1920,300);

    //Road's left side hill
    glEnd();
    glLineWidth(2);
    glBegin(GL_POLYGON);
    glColor3f(0.46f,0.16f,0.16f);
    glVertex2f(1920,100);
    glVertex2f(1920,0);
    bezier_curve4(1600,0,1700,150,1400,250,1590,298);
    bezier_curve3(1590,298,1700,330,1920,340);
    glEnd();

    //Moving water shade STARTS
    glPushMatrix();
    glTranslatef(-water_shade_position1,0,0);
    //Water shade 1(Moving)
    glBegin(GL_POLYGON);
    glColor3f(0.84f,0.41f,0.18f);
    water_shade1();
    glPopMatrix();

    glPushMatrix();
    //Water shade 2(Moving)
    glTranslatef(-water_shade_position2,0,0);
    glBegin(GL_POLYGON);
    water_shade2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position3,0,0);
    //Water shade 3(Moving)
    glBegin(GL_POLYGON);;
    water_shade3();
    glPopMatrix();


    //Water shade 4(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position4,0,0);
    glBegin(GL_POLYGON);
    water_shade4();
    glPopMatrix();

    //Water shade 5(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position5,0,0);
    glBegin(GL_POLYGON);
    water_shade5();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position6,0,0);
    glBegin(GL_POLYGON);
    water_shade6();
    glPopMatrix();

/*

    glLineWidth(2);
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.6f,0.26f);
    glVertex2f(890,475);
    bezier_curve4(1700, 425,1260,410,1000,426,500,415);
    bezier_curve4(500,415,400,425,200,425,0,410);
    glEnd();

*/



   //Mountain 3 front land
     glColor3f(0.81f,0.18f,0.25f);
     mountain_front_land();


    glLineWidth(2);

    glPushMatrix();
    glTranslatef(-raft_position,-position_raft,0);
    //Bamboo raft
    glBegin(GL_POLYGON);
    glColor3f(0.41f,0.19f,0.0f);
    bamboo_raft();


    //Raft vertical line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1913,330);glVertex2f(1907,348);
    glVertex2f(1891,347);glVertex2f(1895,330);
    glVertex2f(1870,347);glVertex2f(1874,330);
    glVertex2f(1816,347);glVertex2f(1807,328);
    glVertex2f(1828,329);glVertex2f(1836,346);
    glVertex2f(1853,347);glVertex2f(1848,329);
    glEnd();

    //bamboo stick
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1820,385);glVertex2f(1912,347);
    glEnd();

    //Human
    glBegin(GL_POLYGON);
    glColor3f(0.58f,0.27f,0.0f);
    human();

    //Head
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    human_head();

    //Human dress
    glBegin(GL_POLYGON);
    glColor3f(0.32f,0.15f,0.0f);
    human_dress();



    glPopMatrix();


    //Mountain 5 (River front Mountain)
    //glColor3f(0.0f,0.6f,0.26f);
    //mountain5();






    //Tent 1______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.37f,0.14f,0.14f);//glColor3f(0.45f,0.11f,0.07f);
    glVertex2f(276,169);glVertex2f(271,207);glVertex2f(456,318);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(354,133);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.37f,0.14f,0.14f);
    glVertex2f(456,318);glVertex2f(551,185);glVertex2f(542,187);glVertex2f(450,318);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(0.45f,0.11f,0.07f);//glColor3f(0.75f,0.34f,0.05f);
    glVertex2f(252,203);glVertex2f(346,317);glVertex2f(456,318);glVertex2f(343,177);
    glEnd();

    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(0.65f,0.19f,0.09f);
    glVertex2f(354,133);glVertex2f(344,182);glVertex2f(452,314);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(461,142);
    glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(454,251);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.37f,0.14f,0.14f);
    glVertex2f(461,140);glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(455,251);glVertex2f(454,251);glVertex2f(450,139);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(290,141);glVertex2f(296,141);glVertex2f(293,119);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(221,192);glVertex2f(228,192);glVertex2f(225,174);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(581,167);glVertex2f(587,167);glVertex2f(584,147);
    glEnd();



    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(289,134);glVertex2f(340,178);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(220,184);glVertex2f(253,204);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(588,158);glVertex2f(548,187);
    glEnd();



    //Tent 2______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.45f,0.11f,0.07f);
    glVertex2f(926,199);glVertex2f(931,237);glVertex2f(746,348);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(848,163);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.37f,0.14f,0.14f);
    glVertex2f(746,348);glVertex2f(651,215);glVertex2f(660,217);glVertex2f(752,348);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(0.75f,0.34f,0.05f);
    glVertex2f(950,233);glVertex2f(856,347);glVertex2f(746,348);glVertex2f(859,207);
    glEnd();

    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(0.65f,0.19f,0.09f);
    glVertex2f(848,163);glVertex2f(855,205);glVertex2f(724,308);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(741,172);
    glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(748,281);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.37f,0.14f,0.14f);
    glVertex2f(741,170);glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(747,281);glVertex2f(748,281);glVertex2f(752,169);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.11f,0.11f,0.11f);
    glVertex2f(912,171);glVertex2f(906,171);glVertex2f(909,149);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glVertex2f(981,222);glVertex2f(974,222);glVertex2f(977,204);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glVertex2f(621,197);glVertex2f(615,197);glVertex2f(618,177);
    glEnd();

    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glVertex2f(913,164);glVertex2f(860,207);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glVertex2f(982,214);glVertex2f(949,234);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glVertex2f(614,188);glVertex2f(654,217);
    glEnd();


    //Tree on mountain 5
    //glBegin(GL_POLYGON);
    //glColor3f(0.02f,0.58f,0.1f);
    //glVertex2f(1920, 420);
    //glColor3f(0.0f,0.42f,0.06f);
    //tree_0n_mountain5();


    //Big tree
    glBegin(GL_POLYGON);
    //Light color
    glColor3f(0.31f,0.0f,0.0f);
    glVertex2f(0, 200);
    //Most dark color
    glColor3f(0.31f,0.0f,0.0f);
    big_tree_root_with_shade1();
    //Dark color
    glColor3f(0.31f,0.0f,0.0f);
    big_tree_root_with_shade2();


    //Big tree leaf
    glBegin(GL_POLYGON);
    glColor3f(0.6f,0.18f,0.11f);
    tree_leaf1();
    glBegin(GL_POLYGON);
    glColor3f(0.45f,0.15f,0.05f);
    tree_leaf2();
    glBegin(GL_POLYGON);
    glColor3f(0.59f,0.27f,0.0f);
    tree_leaf3();
    glBegin(GL_POLYGON);
    glColor3f(0.64f,0.3f,0);
    tree_leaf4();


    //Right side tree branch
    //glBegin(GL_POLYGON);
    //glColor3f(0.49,0.25,0.0f);
    //right_tree_branch();


    //River front 3 right side trees
    tree_type1(1910,90, 450,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type3(1590, 270, 275,0.6f,0.18f,0.11f,0.45f,0.15f,0.05f,0.0f,0.0f,0.02f);
    tree_type2(1350, 200, 300,0.45f,0.15f,0.05f,0.6f,0.18f,0.11f,0.0f,0.0f,0.02f);


    glLineWidth(2);

    //Campfire wood

    //campfire wood dark tail circle
    glColor3f(0.31f,0.0f,0.0f);
    circle(655, 144,5,6);
    circle(710, 144,5,6);

    //Wood 1
    glBegin(GL_QUADS);
    glColor3f(0.31f,0.0f,0.0f);
    glVertex2f(646, 133);
    glVertex2f(650, 118);
    glVertex2f(711, 138);
    glVertex2f(709, 150);
    glEnd();

    //Wood 1 shades
    glBegin(GL_LINES);
    glColor3f(0.16f,0.07f,0.0f);
    glVertex2f(651,126);
    glVertex2f(678,136);
    glVertex2f(652,122);
    glVertex2f(676,130);
    glVertex2f(683,135);
    glVertex2f(713,143);
    glVertex2f(686,132);
    glVertex2f(700,136);
    glEnd();
    //Wood 2
    glBegin(GL_QUADS);
    glColor3f(0.31f,0.0f,0.0f);
    glVertex2f(713, 119);
    glVertex2f(715, 132);
    glVertex2f(656, 149);
    glVertex2f(653, 137);
    glEnd();
    //Wood 2 shades
    glBegin(GL_LINES);
    glColor3f(0.16f,0.07f,0.0f);
    glVertex2f(713,122);
    glVertex2f(670,135);
    glVertex2f(714,127);
    glVertex2f(700,131);
    glVertex2f(715,130);
    glVertex2f(698,135);
    glVertex2f(650,145);
    glVertex2f(675,137);
    glVertex2f(655,149);
    glVertex2f(664,146);
    glEnd();

    //campfire wood front light circle
    glColor3f(0.59f,0.29f,0.03f);
    circle(648, 125,4,7);
    circle(714, 125,4,7);

    //Birds
    glPushMatrix();
    glTranslatef(bird_position,-bird_position*.1,0);
    glColor3f(0.2f,0.08f,0.0f);
    bird1(30,835);
    bird1(50,840);
    bird1(70,845);
    bird1(90,860);
    bird1(73,865);
    bird1(63,840);
    bird1(80,850);
    bird1(60,870);
    bird1(45,880);
    bird1(37,845);
    bird1(30,885);
    bird1(22,841);
    glPopMatrix();


    glFlush(); // Render now
}

void thunderstorm() {

    glClearColor(0.61f,0.95f,1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glLineWidth(2);



    //Sky with shade
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.23f);
    glVertex2f(0,1080);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(0,425);
    glVertex2f(1920,425);
    glColor3f(0.0f,0.0f,0.23f);
    glVertex2f(1920,1080);

    glEnd();

    //Stars
    glColor3f(0.61f,0.98f,1.0f);
    circle(304, 821, 1, 1);circle(356, 856, 1, 1);circle(608, 817, 1, 1);circle(755, 829, 1, 1);circle(844, 856, 1, 1);circle(869, 903, 1, 1);
    circle(761, 929, 1, 1);circle(735, 882, 1, 1);circle(787, 895, 1, 1);circle(619, 900, 1, 1);circle(899, 823, 1, 1);circle(1745, 780, 1, 1);
    circle(1835, 833, 1, 1);circle(1844, 1024, 1, 1);circle(1805, 966, 1, 1);circle(1515, 1019, 1, 1);circle(1475, 906, 1, 1);circle(1421, 818, 1, 1);
    circle(1250, 794, 1, 1);circle(879, 1025, 1, 1);circle(651, 1012, 1, 1);circle(431, 979, 1, 1);circle(318, 1041, 1, 1);circle(266, 861, 1, 1);
    circle(61, 930, 1, 1);circle(147, 954, 1, 1);circle(162, 777, 1, 1);circle(413, 726, 1, 1);circle(772, 845, 1, 1);circle(608, 845, 1, 1);
    circle(953, 926, 1, 1);circle(903, 824, 1, 1);circle(705, 703, 1, 1);circle(1182, 802, 1, 1);circle(1736, 660, 1, 1);circle(1608, 703, 1, 1);
    circle(1639, 1012, 1, 1);circle(1076, 982, 1, 1);circle(934, 806, 1, 1);circle(580, 827, 1, 1);circle(306, 870, 1, 1);circle(247, 765, 1, 1);
    circle(362, 1047, 1, 1);circle(1315, 787, 1, 1);circle(1200, 900,1,1);circle(37, 1064, 1, 1);circle(38, 991, 1, 1);circle(190, 959, 1, 1);
    circle(339, 969, 1, 1);circle(258, 1015, 1, 1);circle(184, 903, 1, 1);circle(156, 1000, 1, 1);circle(138, 1042, 1, 1);circle(532, 959, 1, 1);
    circle(494, 858, 1, 1);circle(403, 809, 1, 1);circle(381, 899, 1, 1);circle(312, 929, 1, 1);circle(127, 866, 1, 1);circle(37, 833, 1, 1);
    circle(109, 717, 1, 1);circle(160, 790, 1, 1);circle(315, 718, 1, 1);circle(403, 675, 1, 1);circle(523, 754, 1, 1);circle(699, 766, 1, 1);
    circle(621, 727, 1, 1);circle(597, 911, 1, 1);circle(627, 995, 1, 1);circle(833, 1043, 1, 1);circle(1009, 1049, 1, 1);circle(1142, 988, 1, 1);
    circle(967, 942, 1, 1);circle(955, 1018, 1, 1);circle(1332, 1004, 1, 1);circle(1475, 936, 1, 1);circle(1380, 864, 1, 1);circle(1261, 821, 1, 1);
    circle(1155, 876, 1, 1);circle(1021, 875, 1, 1);circle(1145, 926, 1, 1);circle(1434, 973, 1, 1);circle(1559, 1046, 1, 1);circle(1921, 1079, 1, 1);
    circle(1848, 1034, 1, 1);circle(1890, 1040, 1, 1);circle(1871, 927, 1, 1);circle(1824, 821, 1, 1);circle(1718, 736, 1, 1);circle(1610, 712, 1, 1);
    circle(1456, 766, 1, 1);circle(1627, 846, 1, 1);circle(1705, 914, 1, 1);circle(1563, 917, 1, 1);circle(1422, 831, 1, 1);circle(1295, 772, 1, 1);
    circle(1223, 836, 1, 1);circle(1149, 932, 1, 1);circle(1149, 994, 1, 1);circle(925, 1048, 1, 1);circle(707, 1034, 1, 1);circle(713, 935, 1, 1);
    circle(899, 941, 1, 1);circle(811, 979, 1, 1);circle(485, 1001, 1, 1);circle(371, 1037, 1, 1);circle(65, 1043, 1, 1);circle(172, 818, 1, 1);
    circle(297, 760, 1, 1);circle(555, 750, 1, 1);circle(445, 815, 1, 1);circle(351, 912, 1, 1);circle(475, 927, 1, 1);circle(522, 867, 1, 1);
    circle(627, 930, 1, 1);circle(982, 885, 1, 1);circle(985, 821, 1, 1);circle(1115, 977, 1, 1);circle(1554, 1031, 1, 1);circle(1840, 1051, 1, 1);
    circle(1453, 807, 1, 1);circle(1307, 766, 1, 1);circle(899, 772, 1, 1);circle(508, 771, 1, 1);circle(186, 733, 1, 1);



    //Moon
    glPushMatrix();
    glTranslatef(-moon_position_x,-moon_position_x*.5,0);
    moon(1700, 900, 100, 100,0.61,0.98,1,0.58,0.85,1);
    glColor3f(0.47f,0.77f,1.0f);
    anti_clock_circle(1770, 950, 8, 15, .7);
    anti_clock_circle(1660, 840, 20, 30, .7);
    anti_clock_circle(1758, 837, 9, 16, -.7);
    anti_clock_circle(1758, 865, 8, 10, -.5);
    anti_clock_circle(1620, 870, 5, 8, .7);
    anti_clock_circle(1637, 960, 3, 5, -.5);


    glPopMatrix();


    //Cloud 1
    glPushMatrix();
    glTranslatef(+cloud_position1,0,0);
    //light shade
    glColor3f(0.36f,0.6f,0.81f);
    circle(95, 1000, 20, 20);
    circle(65, 1027, 20, 20);
    circle(40, 1040, 20, 20);
    circle(75, 1015, 20, 20);

    //main cloud
    glColor3f(0.07f,0.22f,0.55f);
    circle(0, 1000, 25, 25);
    circle(90, 1000, 20, 20);
    circle(30, 1030, 30, 30);
    circle(25, 1015, 25, 25);
    circle(25, 1005, 25, 25);
    circle(60, 1027, 20, 20);
    circle(35, 1040, 20, 20);
    circle(70, 1015, 20, 20);
    circle(70, 1000, 20, 20);
    circle(50, 1000, 20, 20);

    if(cloud1){

    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(35,988);
    glVertex2f(13,953);
    glVertex2f(25,953);
    glVertex2f(55,989);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(34,965);
    glVertex2f(10,934);
    glVertex2f(23,934);
    glVertex2f(45,964);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(24,945);
    glVertex2f(1,904);
    glVertex2f(39,942);
    glEnd();



        //light shade
    glColor3f(0.0f,0.11f,0.33f);
    circle(95, 1000, 20, 20);
    circle(65, 1027, 20, 20);
    circle(40, 1040, 20, 20);
    circle(75, 1015, 20, 20);

    //main cloud
    glColor3f(0.36f,0.6f,0.81f);
    circle(0, 1000, 25, 25);
    circle(90, 1000, 20, 20);
    circle(30, 1030, 30, 30);
    circle(25, 1015, 25, 25);
    circle(25, 1005, 25, 25);
    circle(60, 1027, 20, 20);
    circle(35, 1040, 20, 20);
    circle(70, 1015, 20, 20);
    circle(70, 1000, 20, 20);
    circle(50, 1000, 20, 20);
    }



    glPopMatrix();


    // Cloud 2
    glPushMatrix();
    glTranslatef(+cloud_position2,0,0);
    //light shade
    glColor3f(0.36f,0.6f,0.81f);

    circle(63,890,27,27);
    circle(90,881,20,20);
    //main cloud
    glColor3f(0.07f,0.22f,0.55f);
    circle(16,880,15,15);
    circle(29,891,9,9);
    circle(58,890,27,27);
    circle(85,881,20,20);

    glBegin(GL_QUADS);
    glColor3f(0.07f,0.22f,0.55f);
    glVertex2f(17, 883);
    glVertex2f(85, 883);
    glVertex2f(85, 861);
    glVertex2f(17, 865);
    glEnd();


    if(cloud2){
        //light shade
    glColor3f(0.0f,0.11f,0.33f);
    circle(63,890,27,27);
    circle(90,881,20,20);
    //main cloud

    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(45,870);
    glVertex2f(23,835);
    glVertex2f(35,835);
    glVertex2f(65,871);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(44,847);
    glVertex2f(20,816);
    glVertex2f(33,816);
    glVertex2f(55,846);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(34,827);
    glVertex2f(11,786);
    glVertex2f(49,824);
    glEnd();

    glColor3f(0.36f,0.6f,0.81f);
    circle(16,880,15,15);
    circle(29,891,9,9);
    circle(58,890,27,27);
    circle(85,881,20,20);

    glBegin(GL_QUADS);
    glColor3f(0.36f,0.6f,0.81f);
    glVertex2f(17, 883);
    glVertex2f(85, 883);
    glVertex2f(85, 861);
    glVertex2f(17, 865);
    glEnd();


    }
    glPopMatrix();



    //cloud 3
    glPushMatrix();
    glTranslatef(-cloud_position3,0,0);
    glColor3f(1.07f,0.22f,0.55f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    //main cloud
    glColor3f(.36f,0.6f,0.81f);
    circle(80,842,16,16);
    circle(100,841,10,10);
    circle(112,837,6,6);
    circle(126,833,10,10);
    circle(137,825,10,10);
    circle(149,816,6,6);
    glColor3f(0.07f,0.22f,0.55f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    circle(74,840,16,16);
    circle(80,827,30,15);
    circle(95,840,10,10);
    circle(108,834,6,6);
    circle(122,831,10,10);
    circle(132,825,10,10);
    circle(144,816,6,6);

    glBegin(GL_QUADS);
    glColor3f(0.07f,0.22f,0.55f);
    glVertex2f(12, 818);
    glVertex2f(146, 818);
    glVertex2f(144, 810);
    glVertex2f(13, 810);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.07f,0.22f,0.55f);
    glVertex2f(20, 832);
    glVertex2f(138, 832);
    glVertex2f(138, 817);
    glVertex2f(20, 817);
    glEnd();


    if(cloud3){



    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(79,817);
    glVertex2f(57,782);
    glVertex2f(69,782);
    glVertex2f(99,818);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(78,794);
    glVertex2f(54,763);
    glVertex2f(67,763);
    glVertex2f(89,793);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(68,774);
    glVertex2f(45,733);
    glVertex2f(83,771);
    glEnd();


        //light shade
    glColor3f(0.0f,0.11f,0.33f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    //main cloud
    glColor3f(0.36f,0.6f,0.81f);
    circle(80,842,16,16);
    circle(100,841,10,10);
    circle(112,837,6,6);
    circle(126,833,10,10);
    circle(137,825,10,10);
    circle(149,816,6,6);
    glColor3f(0.36f,0.6f,0.81f);
    circle(13,817,7,7);
    circle(24,824,9,9);
    circle(40,832,12,12);
    circle(54,836,7,7);
    circle(74,840,16,16);
    circle(80,827,30,15);
    circle(95,840,10,10);
    circle(108,834,6,6);
    circle(122,831,10,10);
    circle(132,825,10,10);
    circle(144,816,6,6);

    glBegin(GL_QUADS);
    glColor3f(0.36f,0.6f,0.81f);
    glVertex2f(12, 818);
    glVertex2f(146, 818);
    glVertex2f(144, 810);
    glVertex2f(13, 810);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.36f,0.6f,0.81f);
    glVertex2f(20, 832);
    glVertex2f(138, 832);
    glVertex2f(138, 817);
    glVertex2f(20, 817);
    glEnd();

    }

    glPopMatrix();





    //cloud 4
    glPushMatrix();
    glTranslatef(-cloud_position4,0,0);
    glColor3f(0.36f,0.6f,0.81f);
    circle(23, 933, 21, 21);
    circle(55, 949, 20, 20);
    circle(83, 944, 14, 14);
    circle(95, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    //main cloud
    glColor3f(0.07f,0.22f,0.55f);
    circle(23, 933, 21, 21);
    circle(50, 949, 20, 20);
    circle(80, 943, 14, 14);
    circle(90, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);


    if(cloud4){


    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(45,908);
    glVertex2f(23,873);
    glVertex2f(35,873);
    glVertex2f(65,909);


    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.61f,0.98f,1.0f);
    glVertex2f(44,885);
    glVertex2f(20,854);
    glVertex2f(33,854);
    glVertex2f(55,884);


    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(34,865);
    glVertex2f(11,824);
    glVertex2f(49,862);
    glEnd();


        //light shade
    glColor3f(0.0f,0.11f,0.33f);
    circle(23, 933, 21, 21);
    circle(55, 949, 20, 20);
    circle(83, 944, 14, 14);
    circle(95, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);
    //main cloud
    glColor3f(0.36f,0.6f,0.81f);
    circle(23, 933, 21, 21);
    circle(50, 949, 20, 20);
    circle(80, 943, 14, 14);
    circle(90, 932, 17, 17);
    circle(68, 923, 21, 21);
    circle(43, 917, 17, 17);
    circle(23, 933, 22, 22);

    }

    glPopMatrix();

    //Plane
    glPushMatrix();
    glTranslatef(-plane_position,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.12f,0.27f,0.5f);
    plane();
    glPopMatrix();

    //Mountain 1

    glColor3f(0.0f,0.11f,0.33f);
    mountain1();

    if(mountain1_light)
    {
        glColor3f(0.09f,0.23f,0.48f);
        mountain1();
    }

    //Mountain1 Shadow 1
    glColor3f(0.0f,0.42f,0.71f);
    mountain1_shadow_1();

    //Mountain1 Shadow 2
    mountain1_shadow_2();

    //Mountain1 Shadow 3
    mountain1_shadow_3();


    if(mountain1_shadow_light)
    {
        glColor3f(0.36f,0.67f,0.86f);
        mountain1_shadow_1();
    }
    if(mountain2_shadow_light)
    {
        glColor3f(0.36f,0.67f,0.86f);
        mountain1_shadow_2();
    }
    if(mountain3_shadow_light)
    {
        glColor3f(0.36f,0.67f,0.86f);
        mountain1_shadow_3();
    }


    //Mountain 2
    //glColor3f(0.07f,0.18f,0.37f);
    glColor3f(0.0f,0.16f,0.37f);
    mountain2();


    //Water
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.42f,0.63f);
    water();


    //Mountain 3 front land
    glBegin(GL_POLYGON);
    glColor3f(0.06f,0.17f,0.37f);
    mountain_front_land();
    //Mountain 3
    glColor3f(0.09f,0.23f,0.48f);
    mountain3();
    glEnd();



    //Tree type 1 on mountain
    tree_type1(885, 513, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(550, 490, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(1700, 425, 80,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(540, 604, 40,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(355, 613, 40,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(1650, 630, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type1(830, 737, 20,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type2(995, 504, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);

    tree_type2(1528, 607, 60,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1083, 515, 67,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(421, 478, 70,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(731, 540, 40,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1559, 692, 20,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1216,703, 30,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type2(1880,100, 400,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);

    tree_type3(1774, 627, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(1600, 616, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(636, 489, 75,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(1339, 606, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(380,653, 20,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(297,617, 40,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(1216,703, 30,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(995, 504, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type3(350, 468, 70,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);




    //House 1 on mountain 3////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //Second flower
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1395, 642);glVertex2f(1378, 628);glVertex2f(1408, 624);glVertex2f(1399, 633);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.27f,0.59f);
    glVertex2f(1352, 624);glVertex2f(1361, 633);glVertex2f(1395, 642);glVertex2f(1378, 628);
    glEnd();

    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(1399, 633);glVertex2f(1412, 633);glVertex2f(1421, 624);glVertex2f(1408, 624);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1378, 628);glVertex2f(1395, 641);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glVertex2f(1399, 633);glVertex2f(1412, 633);
    glVertex2f(1412, 633);glVertex2f(1421, 624);
    glEnd();



    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1394, 640);glVertex2f(1406, 624);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.01f,0.38f);
    glVertex2f(1356, 624);glVertex2f(1378, 628);glVertex2f(1378, 611);glVertex2f(1356, 611);
    glEnd();

    //Right wall
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1378, 628);glVertex2f(1417, 624);glVertex2f(1417, 611);glVertex2f(1378, 611);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1352, 624);glVertex2f(1378, 628);
    glVertex2f(1395, 641);glVertex2f(1408, 624);
    glVertex2f(1378, 628);glVertex2f(1421, 624);
    glEnd();

     //Gate
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1395, 611);glVertex2f(1395, 620);glVertex2f(1399, 620);glVertex2f(1399, 611);
    //Gate's Left window
    glVertex2f(1382, 620);glVertex2f(1382, 615);glVertex2f(1391, 615);glVertex2f(1391, 620);
    // Gate's right window
    glVertex2f(1403, 620);glVertex2f(1403, 615);glVertex2f(1412, 615);glVertex2f(1412, 620);
    glEnd();


    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1361, 620);glVertex2f(1365, 620);glVertex2f(1365, 615);glVertex2f(1361, 615);
    //Left wall's right window
    glVertex2f(1370, 620);glVertex2f(1374, 620);glVertex2f(1374, 615);glVertex2f(1370, 615);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1355, 615);glVertex2f(1355, 611);
    glVertex2f(1357, 615);glVertex2f(1357, 611);
    glVertex2f(1361, 615);glVertex2f(1361, 611);
    glVertex2f(1365, 615);glVertex2f(1365, 611);
    glVertex2f(1369, 615);glVertex2f(1369, 611);
    glVertex2f(1378, 615);glVertex2f(1378, 611);
    glVertex2f(1382, 615);glVertex2f(1382, 611);
    glVertex2f(1391, 615);glVertex2f(1391, 611);
    glVertex2f(1395, 615);glVertex2f(1395, 611);
    glVertex2f(1399, 615);glVertex2f(1399, 611);
    glVertex2f(1408, 615);glVertex2f(1408, 611);
    glVertex2f(1412, 615);glVertex2f(1412, 611);
    glVertex2f(1417, 615);glVertex2f(1417, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1421, 615);glVertex2f(1421, 611);
    glVertex2f(1354, 615);glVertex2f(1382, 615);
    glVertex2f(1382, 615);glVertex2f(1421, 615);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1354, 611);glVertex2f(1382, 611);glVertex2f(1382, 611);glVertex2f(1421, 611);
    //Pillar
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1382, 611);glVertex2f(1382, 603);
    glVertex2f(1395, 611);glVertex2f(1395, 601);
    glVertex2f(1390, 611);glVertex2f(1390, 602);
    glVertex2f(1404, 611);glVertex2f(1404, 603);
    glVertex2f(1412, 611);glVertex2f(1412, 603);
    glVertex2f(1417, 611);glVertex2f(1417, 603);
    //glVertex2f(1421, 611);glVertex2f(1421, 603);
    glVertex2f(1374, 611);glVertex2f(1374, 603);
    glVertex2f(1367, 611);glVertex2f(1367, 606);
    glVertex2f(1361, 611);glVertex2f(1361, 607);
    glEnd();

    //House 2 on mountain 3////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //second flowar
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.01f,0.38f);
    glVertex2f(578, 528);glVertex2f(595, 514);glVertex2f(565, 510);glVertex2f(574, 519);
    glEnd();


    //Right side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(621, 510);glVertex2f(612, 519);glVertex2f(578, 528);glVertex2f(595, 514);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.27f,0.59f);
    glVertex2f(574, 519);glVertex2f(561, 519);glVertex2f(552, 510);glVertex2f(565, 510);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(595, 514);glVertex2f(578, 527);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glVertex2f(574, 519);glVertex2f(561, 519);
    glVertex2f(561, 519);glVertex2f(552, 510);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(579, 526);glVertex2f(567, 510);
    glEnd();


    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(617, 510);glVertex2f(595, 514);glVertex2f(595, 497);glVertex2f(617, 497);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.01f,0.38f);
    glVertex2f(595, 514);glVertex2f(556, 510);glVertex2f(556, 497);glVertex2f(595, 497);
    glEnd();


    glLineWidth(2);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(621, 510);glVertex2f(595, 514);
    glVertex2f(578, 527);glVertex2f(565, 510);
    glVertex2f(595, 514);glVertex2f(552, 510);
    glEnd();


    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(578, 497);glVertex2f(578, 506);glVertex2f(574, 506);glVertex2f(574, 497);
    //Gate's Left window
    glVertex2f(591, 506);glVertex2f(591, 501);glVertex2f(582, 501);glVertex2f(582, 506);
    // Gate's right window
    glVertex2f(570, 506);glVertex2f(570, 501);glVertex2f(561, 501);glVertex2f(561, 506);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(612, 506);glVertex2f(608, 506);glVertex2f(608, 501);glVertex2f(612, 501);
    //Left wall's right window
    glVertex2f(603, 506);glVertex2f(599, 506);glVertex2f(599, 501);glVertex2f(603, 501);
    glEnd();

    //Railing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(619, 501);glVertex2f(619, 497);
    glVertex2f(616, 501);glVertex2f(616, 497);
    glVertex2f(612, 501);glVertex2f(612, 497);
    glVertex2f(608, 501);glVertex2f(608, 497);
    glVertex2f(604, 501);glVertex2f(604, 497);
    glVertex2f(595, 501);glVertex2f(595, 497);
    glVertex2f(591, 501);glVertex2f(591, 497);
    glVertex2f(582, 501);glVertex2f(582, 497);
    glVertex2f(578, 501);glVertex2f(578, 497);
    glVertex2f(574, 501);glVertex2f(574, 497);
    glVertex2f(565, 501);glVertex2f(565, 497);
    glVertex2f(561, 501);glVertex2f(561, 497);
    glVertex2f(556, 501);glVertex2f(556, 497);
    glVertex2f(553, 501);glVertex2f(553, 497);
    glVertex2f(619, 501);glVertex2f(591, 501);
    glVertex2f(591, 501);glVertex2f(552, 501);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(619, 497);glVertex2f(591, 497);
    glVertex2f(591, 497);glVertex2f(552, 497);
    //pillar
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(591, 497);glVertex2f(591, 489);
    glVertex2f(578, 497);glVertex2f(578, 487);
    glVertex2f(583, 497);glVertex2f(583, 488);
    glVertex2f(569, 497);glVertex2f(569, 489);
    glVertex2f(561, 497);glVertex2f(561, 489);
    glVertex2f(556, 497);glVertex2f(556, 489);
    glVertex2f(599, 497);glVertex2f(599, 489);
    glVertex2f(606, 497);glVertex2f(606, 492);
    glVertex2f(612, 497);glVertex2f(612, 493);
    glEnd();


    //House 3 on mountain 3////////////////////////////////////////////////////////////////////////
    glLineWidth(1);
    //second floor
    glBegin(GL_POLYGON);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1818, 662);glVertex2f(1801, 648);glVertex2f(1831, 644);glVertex2f(1822, 653);
    glEnd();

    //left side roof
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.42f,0.71f);
    glVertex2f(1775, 644);glVertex2f(1784, 653);glVertex2f(1818, 662);glVertex2f(1801, 648);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 648);glVertex2f(1818, 661);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.29f,0.16f,0.0f);
    glVertex2f(1817, 660);glVertex2f(1829, 644);
    glEnd();

    //left wall
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1779, 644);glVertex2f(1801, 648);
    glVertex2f(1801, 631);glVertex2f(1779, 631);
    glEnd();


    //right wall
    glBegin(GL_QUADS);
    glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(1801, 648);glVertex2f(1840, 644);
    glVertex2f(1840, 631);glVertex2f(1801, 631);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1775, 644);glVertex2f(1801, 648);
    glVertex2f(1818, 661);glVertex2f(1831, 644);
    glVertex2f(1801, 648);glVertex2f(1844, 644);
    glEnd();

    //Gate
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1818, 631);glVertex2f(1818, 640);
    glVertex2f(1822, 640);glVertex2f(1822, 631);
    //Gate's Left window
    glVertex2f(1805, 640);glVertex2f(1805, 635);
    glVertex2f(1814, 635);glVertex2f(1814, 640);
    // Gate's right window
    glVertex2f(1826, 640);glVertex2f(1826, 635);
    glVertex2f(1835, 635);glVertex2f(1835, 640);
    glEnd();

    //Left wall's left window
    glBegin(GL_QUADS);
    glColor3f(0.91f,0.63f,0.3f);
    glVertex2f(1784, 640);glVertex2f(1788, 640);
    glVertex2f(1788, 635);glVertex2f(1784, 635);
    //Left wall's right window
    glVertex2f(1793, 640);glVertex2f(1797, 640);
    glVertex2f(1797, 635);glVertex2f(1793, 635);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1777, 635);glVertex2f(1777, 631);
    glVertex2f(1780, 635);glVertex2f(1780, 631);
    glVertex2f(1784, 635);glVertex2f(1784, 631);
    glVertex2f(1788, 635);glVertex2f(1788, 631);
    glVertex2f(1792, 635);glVertex2f(1792, 631);
    glVertex2f(1801, 635);glVertex2f(1801, 631);
    glVertex2f(1805, 635);glVertex2f(1805, 631);
    glVertex2f(1814, 635);glVertex2f(1814, 631);
    glVertex2f(1818, 635);glVertex2f(1818, 631);
    glVertex2f(1822, 635);glVertex2f(1822, 631);
    glVertex2f(1831, 635);glVertex2f(1831, 631);
    glVertex2f(1835, 635);glVertex2f(1835, 631);
    glVertex2f(1840, 635);glVertex2f(1840, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1844, 635);glVertex2f(1844, 631);
    glVertex2f(1777, 635);glVertex2f(1805, 635);
    glVertex2f(1805, 635);glVertex2f(1844, 635);
    glEnd();

    glLineWidth(2);
    //Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(1777, 631);glVertex2f(1805, 631);
    glVertex2f(1805, 631);glVertex2f(1844, 631);
    //pillar
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1805, 631);glVertex2f(1805, 623);
    glVertex2f(1818, 631);glVertex2f(1818, 621);
    glVertex2f(1813, 631);glVertex2f(1813, 622);
    glVertex2f(1827, 631);glVertex2f(1827, 623);
    glVertex2f(1835, 631);glVertex2f(1835, 623);
    glVertex2f(1840, 631);glVertex2f(1840, 623);
    glVertex2f(1844, 631);glVertex2f(1844, 623);
    glVertex2f(1797, 631);glVertex2f(1797, 627);
    glVertex2f(1790, 631);glVertex2f(1790, 626);
    glVertex2f(1784, 631);glVertex2f(1784, 627);
    glEnd();




    //waterfall front water shade
    glPushMatrix();
    glTranslatef(0,-waterfall_on_river_position,0);
    glColor3f(0.36f,0.67f,0.86f);
    circle(1765, 425, 50, 8);
    glPopMatrix();






    //cell tower/////////////////////////////////////////////

    //Middle white line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.31f,0.41f,0.64f);
    glVertex2f(1893, 917);glVertex2f(1893, 685);

    //Middle red line
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.29f);
    glVertex2f(1893, 737);glVertex2f(1893, 788);
    glVertex2f(1893, 840);glVertex2f(1893, 865);
    glVertex2f(1893, 891);glVertex2f(1893, 917);
    glEnd();

    // white Part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.28f,0.37f,0.56f);
    glVertex2f(1893, 927);glVertex2f(1893, 917);
    //1
    glVertex2f(1868, 685);glVertex2f(1874, 737);
    glVertex2f(1868, 685);glVertex2f(1870, 699);
    glVertex2f(1870, 699);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1873, 724);
    glVertex2f(1873, 724);glVertex2f(1874, 737);

    glVertex2f(1915, 685);glVertex2f(1912, 737);
    glVertex2f(1915, 685);glVertex2f(1914, 699);
    glVertex2f(1914, 699);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1913, 724);
    glVertex2f(1913, 724);glVertex2f(1912, 737);

    glVertex2f(1868, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1912, 737);

    glVertex2f(1915, 685);glVertex2f(1893, 711);
    glVertex2f(1893, 711);glVertex2f(1874, 737);
    //1 horizontal

    glVertex2f(1870, 699);glVertex2f(1893, 699);
    glVertex2f(1893, 699);glVertex2f(1914, 699);

    glVertex2f(1873, 724);glVertex2f(1893, 724);
    glVertex2f(1893, 724);glVertex2f(1913, 724);

    //3
    glVertex2f(1879, 788);glVertex2f(1884, 840);
    glVertex2f(1908, 788);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1880, 802);
    glVertex2f(1880, 802);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1882, 828);
    glVertex2f(1882, 828);glVertex2f(1884, 840);

    glVertex2f(1908, 788);glVertex2f(1907, 802);
    glVertex2f(1907, 802);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1905, 828);
    glVertex2f(1905, 828);glVertex2f(1904, 840);

    glVertex2f(1879, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1904, 840);

    glVertex2f(1908, 788);glVertex2f(1893, 815);
    glVertex2f(1893, 815);glVertex2f(1884, 840);

    //horizontal
    glVertex2f(1880, 802);glVertex2f(1893, 802);
    glVertex2f(1893, 802);glVertex2f(1907, 802);

    glVertex2f(1882, 828);glVertex2f(1893, 828);
    glVertex2f(1893, 828);glVertex2f(1905, 828);


    //4
    glVertex2f(1886, 865);glVertex2f(1887, 872);
    glVertex2f(1887, 872);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1887, 885);
    glVertex2f(1887, 885);glVertex2f(1887, 891);

    glVertex2f(1902, 865);glVertex2f(1902, 872);
    glVertex2f(1902, 872);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1901, 885);
    glVertex2f(1901, 885);glVertex2f(1901, 891);

    glVertex2f(1886, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1901, 891);

    glVertex2f(1902, 865);glVertex2f(1893, 878);
    glVertex2f(1893, 878);glVertex2f(1887, 891);

    //horizontal


    glVertex2f(1887, 872);glVertex2f(1893, 872);
    glVertex2f(1893, 872);glVertex2f(1902, 872);

    glVertex2f(1887, 885);glVertex2f(1893, 885);
    glVertex2f(1893, 885);glVertex2f(1901, 885);





/*

*/


    glEnd();

    //Darker White part
    glBegin(GL_LINES);
    glColor3f(0.23f,0.31f,0.48);
    //1
    glVertex2f(1893, 685);glVertex2f(1871, 711);
    glVertex2f(1871, 711);glVertex2f(1893, 737);

    glVertex2f(1893, 685);glVertex2f(1914, 711);
    glVertex2f(1914, 711);glVertex2f(1893, 737);
    //3

    glVertex2f(1893, 788);glVertex2f(1881, 815);
    glVertex2f(1881, 815);glVertex2f(1893, 840);

    glVertex2f(1893, 788);glVertex2f(1906, 815);
    glVertex2f(1906, 815);glVertex2f(1893, 840);
    //4
    glVertex2f(1893, 865);glVertex2f(1887, 878);
    glVertex2f(1887, 878);glVertex2f(1893, 891);

    glVertex2f(1893, 865);glVertex2f(1901, 878);
    glVertex2f(1901, 878);glVertex2f(1893, 891);




    glEnd();


    //Red part
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.29f);
    //2
    glVertex2f(1874, 737);glVertex2f(1875, 750);
    glVertex2f(1875, 750);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1878, 776);
    glVertex2f(1878, 776);glVertex2f(1879, 788);

    glVertex2f(1912, 737);glVertex2f(1911, 750);
    glVertex2f(1911, 750);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1909, 776);
    glVertex2f(1909, 776);glVertex2f(1908, 788);

    glVertex2f(1874, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1908, 788);
    glVertex2f(1912, 737);glVertex2f(1893, 763);
    glVertex2f(1893, 763);glVertex2f(1879, 788);

    glVertex2f(1893, 737);glVertex2f(1876, 763);
    glVertex2f(1876, 763);glVertex2f(1893, 788);
    glVertex2f(1893, 737);glVertex2f(1910, 763);
    glVertex2f(1910, 763);glVertex2f(1893, 788);
    //2 horizontal

    glVertex2f(1875, 750);glVertex2f(1893, 750);
    glVertex2f(1893, 750);glVertex2f(1911, 750);

    glVertex2f(1878, 776);glVertex2f(1893, 776);
    glVertex2f(1893, 776);glVertex2f(1909, 776);


    //3

    glVertex2f(1884, 840);glVertex2f(1884, 847);
    glVertex2f(1884, 847);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1885, 860);
    glVertex2f(1885, 860);glVertex2f(1886, 865);

    glVertex2f(1904, 840);glVertex2f(1904, 847);
    glVertex2f(1904, 847);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1903, 860);
    glVertex2f(1903, 860);glVertex2f(1902, 865);


    glVertex2f(1884, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1902, 865);

    glVertex2f(1904, 840);glVertex2f(1893, 853);
    glVertex2f(1893, 853);glVertex2f(1886, 865);

    glVertex2f(1893, 840);glVertex2f(1885, 853);
    glVertex2f(1885, 853);glVertex2f(1893, 865);

    glVertex2f(1893, 840);glVertex2f(1903, 853);
    glVertex2f(1903, 853);glVertex2f(1893, 865);

    glVertex2f(1884, 847);glVertex2f(1893, 847);
    glVertex2f(1893, 847);glVertex2f(1904, 847);

    glVertex2f(1885, 860);glVertex2f(1893, 860);
    glVertex2f(1893, 860);glVertex2f(1903, 860);

    //5

    glVertex2f(1887, 891);glVertex2f(1887, 898);
    glVertex2f(1887, 898);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1887, 911);
    glVertex2f(1887, 911);glVertex2f(1887, 917);

    glVertex2f(1901, 891);glVertex2f(1901, 898);
    glVertex2f(1901, 898);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1901, 911);
    glVertex2f(1901, 911);glVertex2f(1901, 917);

    glVertex2f(1887, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1901, 917);

    glVertex2f(1901, 891);glVertex2f(1893, 904);
    glVertex2f(1893, 904);glVertex2f(1887, 917);

    glVertex2f(1893, 891);glVertex2f(1887, 904);
    glVertex2f(1887, 904);glVertex2f(1893, 917);

    glVertex2f(1893, 891);glVertex2f(1901, 904);
    glVertex2f(1901, 904);glVertex2f(1893, 917);

    glVertex2f(1887, 898);glVertex2f(1893, 898);
    glVertex2f(1893, 898);glVertex2f(1901, 898);

    glVertex2f(1887, 911);glVertex2f(1893, 911);
    glVertex2f(1893, 911);glVertex2f(1901, 911);

    glVertex2f(1887, 917);glVertex2f(1893, 917);
    glVertex2f(1893, 917);glVertex2f(1901, 917);





    //cell tower drum holder
    glBegin(GL_LINES);

    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1887, 885);glVertex2f(1878, 885);
    glVertex2f(1901, 885);glVertex2f(1909, 885);

    glVertex2f(1887, 891);glVertex2f(1878, 891);
    glVertex2f(1901, 891);glVertex2f(1909, 891);


    glVertex2f(1887, 904);glVertex2f(1878, 904);
    glVertex2f(1901, 904);glVertex2f(1909, 904);

    glVertex2f(1887, 911);glVertex2f(1878, 911);
    glVertex2f(1901, 911);glVertex2f(1909, 911);


    glEnd();

    //cell tower long drum
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.54f,0.65f,0.88f);
    glVertex2f(1880, 880);glVertex2f(1880, 896);
    glVertex2f(1908, 880);glVertex2f(1908, 896);
    glColor3f(0.38f,0.49f,0.75f);
    glVertex2f(1882, 880);glVertex2f(1882, 896);
    glVertex2f(1906, 880);glVertex2f(1906, 896);
    glVertex2f(1893, 880);glVertex2f(1893, 896);
    glVertex2f(1895, 880);glVertex2f(1895, 896);
    glEnd();


    //cell tower drum
    glColor3f(0.24f,0.43f,0.73f);
    circle(1881,908,5,8);
    circle(1906,908,5,8);
    glColor3f(0.54f,0.65f,0.88f);
    //glColor3f(0.83f,0.83f,0.83f);
    circle(1878,908,5,8);
    circle(1909,908,5,8);

    //light
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.29f);
    glVertex2f(1899,917);
    glVertex2f(1899,920);
    glEnd();

    if(tower_light)moon(1899,919,6,6,1.0,0.0,0.0,0,0.1,0.35);



    //Mountain 4
    glColor3f(0.06f,0.17f,0.37f);
    mountain4();

    //Waterfall with shade
    glBegin(GL_POLYGON);
    glColor3f(0.36f,0.67f,0.86f);
    waterfall_with_shade_1();
    glColor3f(0.0f,0.42f,0.63f);
    waterfall_with_shade_2();


    glLineWidth(1);
    //waterfall shade 1
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position1,0);
    glBegin(GL_LINES);
    glColor3f(0.47f,0.77f,1.0f);
    glVertex2f(1752,545);glVertex2f(1752,530);
    glVertex2f(1746,540);glVertex2f(1746,525);
    glEnd();
    glPopMatrix();

    //waterfall shade 2
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position2,0);
    glBegin(GL_LINES);
    glVertex2f(1754,520);glVertex2f(1754,510);
    glVertex2f(1747,515);glVertex2f(1747,500);
    glVertex2f(1741,525);glVertex2f(1741,510);
    glEnd();
    glPopMatrix();

    //waterfall shade 3
    glPushMatrix();
    glTranslatef(0,-waterfall_shade_position3,0);
    glBegin(GL_LINES);
    glVertex2f(1752,495);glVertex2f(1752,480);
    glVertex2f(1745,493);glVertex2f(1745,475);
    glVertex2f(1738,490);glVertex2f(1738,475);
    glEnd();

    glPopMatrix();

    //River front Land
    glBegin(GL_POLYGON);
    glColor3f(0.02f,0.22f,0.44f);
    glVertex2f(0,0);glVertex2f(0,300);glVertex2f(1920,300);glVertex2f(1920,0);
    glEnd();

    //fire sarrunding light


    //Trees on mountain front
    tree_type1(1700, 425, 75,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);

    //ALL land shades
    glColor3f(0.13f,0.45f,0.75f);
    land_shade();



    //Moving water shade STARTS
    glPushMatrix();
    glTranslatef(-water_shade_position1,0,0);
    //Water shade 1(Moving)
    glBegin(GL_POLYGON);
    glColor3f(0.36f,0.67f,0.86f);
    water_shade1();
    glPopMatrix();

    glPushMatrix();
    //Water shade 2(Moving)
    glTranslatef(-water_shade_position2,0,0);
    glBegin(GL_POLYGON);
    water_shade2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position3,0,0);
    //Water shade 3(Moving)
    glBegin(GL_POLYGON);;
    water_shade3();
    glPopMatrix();


    //Water shade 4(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position4,0,0);
    glBegin(GL_POLYGON);
    water_shade4();
    glPopMatrix();

    //Water shade 5(Moving)
    glPushMatrix();
    glTranslatef(-water_shade_position5,0,0);
    glBegin(GL_POLYGON);
    water_shade5();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-water_shade_position6,0,0);
    glBegin(GL_POLYGON);
    water_shade6();
    glPopMatrix();


    //Mountain 3 front land
     glColor3f(0.09f,0.23f,0.48f);
     mountain_front_land();


    glLineWidth(2);


   //Road
    glBegin(GL_POLYGON);
    glColor3f(0.22f,0.18f,0.35f);
    glVertex2f(1920,0);
    bezier_curve4(1230,0,1550,150,1300,280,1590,298);
    glColor3f(0.11f,0.11f,0.31f);
    glVertex2f(1920,300);

    //Road's left side hill
    glEnd();
    glLineWidth(2);
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.11f,0.33f);
    glVertex2f(1920,100);
    glVertex2f(1920,0);
    bezier_curve4(1600,0,1700,150,1400,250,1590,298);
    bezier_curve3(1590,298,1700,330,1920,340);
    glEnd();



    //Tent 1______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.13f,0.28f);//glColor3f(0.06f,0.31f,0.58f);
    glVertex2f(276,169);glVertex2f(271,207);glVertex2f(456,318);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(354,133);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.13f,0.28f);
    glVertex2f(456,318);glVertex2f(551,185);glVertex2f(542,187);glVertex2f(450,318);
    glEnd();



    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(0.06f,0.31f,0.58f);//glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(354,133);glVertex2f(344,182);glVertex2f(453,314);glVertex2f(542,187);glVertex2f(526,145);glVertex2f(461,142);
    glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(454,251);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    //glColor3f(0.09f,0.29f,0.74f);
    glColor3f(0.0f,0.14f,0.37f);
    glVertex2f(252,203);glVertex2f(346,317);glVertex2f(456,318);
    //glColor3f(0.0f,0.14f,0.37f);
    glVertex2f(340,176);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.13f,0.28f);
    glVertex2f(461,140);glVertex2f(457,251);glVertex2f(456,251);glVertex2f(456,251);glVertex2f(455,251);glVertex2f(455,251);
    glVertex2f(455,251);glVertex2f(454,251);glVertex2f(450,139);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(290,141);glVertex2f(296,141);glVertex2f(293,119);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(221,192);glVertex2f(228,192);glVertex2f(225,174);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(581,167);glVertex2f(587,167);glVertex2f(584,147);
    glEnd();



    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(289,134);glVertex2f(340,178);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(220,184);glVertex2f(253,204);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(588,158);glVertex2f(548,187);
    glEnd();



    //Tent 2______________________________________________________________

    //Side shade
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.14f,0.37f);//glColor3f(0.06f,0.31f,0.58f);//glColor3f(0.06f,0.31f,0.58f);//glColor3f(0.21f,0.34f,0.55f);
    glVertex2f(926,199);glVertex2f(931,237);glVertex2f(746,348);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(848,163);
    glEnd();

    //Thin roof side shad
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.13f,0.28f);
    glVertex2f(746,348);glVertex2f(651,215);glVertex2f(660,217);glVertex2f(752,348);
    glEnd();



    //Front with gate
    glBegin(GL_POLYGON);
    glColor3f(0.06f,0.31f,0.58f);//glColor3f(0.21f,0.34f,0.55f);//glColor3f(0.06f,0.31f,0.58f);
    glVertex2f(848,163);glVertex2f(855,205);glVertex2f(724,308);glVertex2f(660,217);glVertex2f(676,175);glVertex2f(741,172);
    glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(748,281);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(0.09f,0.29f,0.74f);

    glVertex2f(950,233);glVertex2f(856,347);
    glColor3f(0.17f,0.64f,0.98f);
    glVertex2f(746,348);
    glColor3f(0.09f,0.29f,0.74f);
    glVertex2f(859,207);
    glEnd();

    //Gate
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.13f,0.28f);
    glVertex2f(741,170);glVertex2f(745,281);glVertex2f(746,281);glVertex2f(746,281);glVertex2f(747,281);glVertex2f(747,281);
    glVertex2f(747,281);glVertex2f(748,281);glVertex2f(752,169);
    glEnd();

    //Tent anchor 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(912,171);glVertex2f(906,171);glVertex2f(909,149);
    glEnd();

    //Tent anchor 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(981,222);glVertex2f(974,222);glVertex2f(977,204);
    glEnd();

    //Tent anchor 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(621,197);glVertex2f(615,197);glVertex2f(618,177);
    glEnd();

    //Tent anchor 1 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(913,164);glVertex2f(860,207);
    glEnd();

    //Tent anchor 2 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(982,214);glVertex2f(949,234);
    glEnd();

    //Tent anchor 3 rope
    glBegin(GL_LINES);
    glColor3f(0.0f,0.06f,0.22f);
    glVertex2f(614,188);glVertex2f(654,217);
    glEnd();


    //Tree on mountain 5
    //glBegin(GL_POLYGON);
    //glColor3f(0.02f,0.58f,0.1f);
    //glVertex2f(1920, 420);
   // glColor3f(0.0f,0.42f,0.06f);
    //tree_0n_mountain5();

    //tree_type1(885, 513, 65,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    //Big tree
    glBegin(GL_POLYGON);
    //Light color
    glColor3f(0.02f,0.02f,0.09f);
    glVertex2f(0, 200);
    //Most dark color
    glColor3f(0.02f,0.02f,0.09f);
    big_tree_root_with_shade1();
    //Dark color
    glColor3f(0.02f,0.02f,0.09f);
    big_tree_root_with_shade2();


    //Big tree leaf
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.05f,0.24f);
    tree_leaf1();
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.07f,0.28f);
    tree_leaf2();
    glBegin(GL_POLYGON);
    glColor3f(0.02f,0.03f,0.17f);
    tree_leaf3();
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.07f,0.25f);
    tree_leaf4();


    //Right side tree branch
    //glBegin(GL_POLYGON);
    //glColor3f(0.49,0.25,0.0f);
    //right_tree_branch();


    //River front 3 right side trees
    tree_type1(1910,90, 450,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);
    tree_type2(1350, 200, 300,0.02f,0.03f,0.17f,0.0f,0.07f,0.25f,0.02f,0.02f,0.09f);
    tree_type3(1590, 270, 275,0.0f,0.07f,0.25f,0.02f,0.03f,0.17f,0.02f,0.02f,0.09f);



    glLineWidth(2);

    //Campfire wood
    //glColor3f(0.96f,0.47f,0.24f);

    //moon(680, 137, 100, 100,1.0,0.88,0.0,0.02,0.22,0.44);

    //campfire wood dark tail circle
    glColor3f(0.07f,0.04f,0.19f);
    circle(655, 144,5,6);
    circle(710, 144,5,6);

    //Wood 1
    glBegin(GL_QUADS);
    glColor3f(0.07f,0.04f,0.19f);
    glVertex2f(646, 133);
    glVertex2f(650, 118);
    glVertex2f(711, 138);
    glVertex2f(709, 150);
    glEnd();

    //Wood 1 shades
    glBegin(GL_LINES);
    glColor3f(0.02f,0.01f,0.07f);
    glVertex2f(651,126);
    glVertex2f(678,136);
    glVertex2f(652,122);
    glVertex2f(676,130);
    glVertex2f(683,135);
    glVertex2f(713,143);
    glVertex2f(686,132);
    glVertex2f(700,136);
    glEnd();
    //Wood 2
    glBegin(GL_QUADS);
    glColor3f(0.07f,0.04f,0.19f);
    glVertex2f(713, 119);
    glVertex2f(715, 132);
    glVertex2f(656, 149);
    glVertex2f(653, 137);
    glEnd();
    //Wood 2 shades
    glBegin(GL_LINES);
    glColor3f(0.02f,0.01f,0.07f);
    glVertex2f(713,122);
    glVertex2f(670,135);
    glVertex2f(714,127);
    glVertex2f(700,131);
    glVertex2f(715,130);
    glVertex2f(698,135);
    glVertex2f(650,145);
    glVertex2f(675,137);
    glVertex2f(655,149);
    glVertex2f(664,146);
    glEnd();

    //campfire wood light circle
    glColor3f(0.35f,0.29f,0.43f);
    circle(648, 125,4,7);
    circle(714, 125,4,7);

    float x=0, y = 0, x1= 0;
    glColor3f(0.61f,0.98f,1.0f);
    glPushMatrix();
    //glTranslatef(0,-270,0);
    glLineWidth(1);
    glBegin(GL_LINES);

    for(int i=10;i>=0;i--)
    {
        y=1+ (rand() % 1100);
        for(int j=0;j<=i;j++)
        {
            x= 1+ (rand() % 2100);
            glVertex3f(x,y,0);
            glVertex3f(x+20,y+43,0);
            //srand(time(0));

            //cout<<x<<endl;
        }
        for(int j=0;j<=i;j++)
        {
            x1=1+ (rand() % 2100);
            glVertex3f(x1,y,0);
            glVertex3f(x1+20,y+43,0);
            //srand(time(0));

        }
        //srand(time(0));

        //x=-50;
        //x1=-190;
    }
    glEnd();
    glPopMatrix();






    glFlush(); // Render now
}

void handleKeypress(unsigned char key, int x, int y) {

    switch (key) {
    case 'd':

        sndPlaySound("day.wav",SND_ASYNC);
        glutDisplayFunc(day);
        //glutPostRedisplay();
        break;

    case 's':

        sndPlaySound("sunset.wav",SND_ASYNC);
        glutDisplayFunc(sunset);
        break;

    case 'n':

        sndPlaySound("night.wav",SND_ASYNC);
        glutDisplayFunc(night);
        break;

    case 'c':
        PlaySound(NULL, NULL, 0);
        glutDisplayFunc(cover);
        break;

    case 't':

        sndPlaySound("thunder.wav",SND_ASYNC);
        glutDisplayFunc(thunderstorm);
        break;

    case 'f':
        glutFullScreen();
        break;

    case 'r':
        glutReshapeWindow(1920, 1080);
        glutInitWindowPosition(0, 0);
        break;

    case 'l':
        glutReshapeWindow(960, 540);
        glutInitWindowPosition(100, 100);
        break;

    case 'e':
        exit(0);
        break;
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char ** argv) {


    cout << endl;
    cout << " 01047 - COMPUTER GRAPHICS [A]" << endl;
    cout << "   Somewhere in Bandarban" << endl;
    cout << "       by Group- 4" <<  endl << endl;

    cout << "Submitted to" << endl;
    cout << "       MAHFUJUR RAHAMAN"<< endl;
    cout << "       FACULTY OF SCIENCE & TECHNOLOGY" << endl;
    cout << "       American International University-Bangladesh"<<  endl<< endl << endl;

    cout << "Key Functions:" << endl << endl;
    cout << "Press d : To Start Day Mode" << endl << endl;
    cout << "Press s : To Start Sunset Mode" << endl << endl;
    cout << "Press n : To Start Night Mode" << endl << endl;
    cout << "Press t : To Start Thunderstorm Mode" << endl << endl;
    cout << "Press c : To Go to Cover Page " << endl << endl;
    cout << "Press f : TO Expand to Full Screen " << endl << endl;
    cout << "Press l : TO Make Small Screen " << endl << endl;
    cout << "Press e : To Exit " << endl << endl;


    glutInit( & argc, argv);
    glutInitWindowSize(1920, 1080); // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Set the window's initial position according to the monitor
    glutCreateWindow("Somewhere in Bandarban"); // Create a window with the given title
    glOrtho(0, 1920, 0, 1080, -100, 100);
    glutDisplayFunc(cover); // Register display callback handler for window re-paint
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(20, update, 0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
