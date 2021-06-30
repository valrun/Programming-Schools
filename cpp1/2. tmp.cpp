
#include <TXLib.h>
#include <math.h>
//____________________________________________
void controlKeyboardState();
void measureGUI();
void drawGUI();

void drawGun();

double toRadian(int angle);
double rotationX(double x, double angle, double length);
double rotationY(double y, double angle, double length);
double distance(double x1, double y1, double x2, double y2);
//____________________________________________
bool isBulletFly = false;

int u0 = 100;
int goals = 0;
int fails = 0;

int t = 0;
int xStart;
int yStart;
int angleStart;
int uStart;
bool up;

int xBullet;
int yBullet;
int rBullet = 10;

int angleGun = 45;
int xGun = 63;
int yGun = 500;

int xGoal;
int yGoal;
int rGoal = 30;
int kx;
int ky;

int xBegin = 250;
int xEnd = 800;
int yBegin = 0;
int yEnd = 500;

//____________________________________________
int main()
{
    txCreateWindow (800, 500);
    txSetFillColour(TX_WHITE);
    txClear();

    srand(time(NULL));
    yGoal = rand() % (yEnd - yBegin - 2 * rGoal) + yBegin + rGoal;
    xGoal = rand() % (xEnd - xBegin - 2 * rGoal) + xBegin + rGoal;

    kx = rand() % 2;
    kx = (kx == 0 ? -1 : 1);
    ky = rand() % 2;
    ky = (ky == 0 ? -1 : 1);

    while(true)
    {
        controlKeyboardState();
        measureGUI();
        drawGUI();
    }
}
//____________________________________________
void controlKeyboardState()
{
    if (GetAsyncKeyState(0x52))
    {
        isBulletFly = false;
        t = 0;
        fails++;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        angleGun--;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        angleGun++;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        u0 += 5;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        u0 -= 5;
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (!isBulletFly)
        {
            isBulletFly = true;
            xStart = rotationX(xGun, toRadian(90 - angleGun), 2.25 * xGun);
            yStart = rotationY(yGun, toRadian(90 - angleGun), 2.25 * xGun);
            angleStart = angleGun;
            uStart = u0;
            up = true;
        }
    }
}
//____________________________________________
void measureGUI()
{
    xGoal += kx;
    yGoal += ky;
    //________
    kx = (xGoal <= 250 + rGoal ||  xGoal >= 800 - rGoal ? -kx : kx);
    ky = (yGoal <= rGoal ||  yGoal >= 500 - rGoal ? -ky : ky);

    angleGun = (angleGun > 90 ? 90 : angleGun);
    angleGun = (angleGun < 0 ? 0 : angleGun);

    u0 = (u0 < 75 ? 75 : u0);
    u0 = (u0 > 125 ? 125 : u0);
    //________

    if (isBulletFly)
    {
        xBullet = uStart * t * cos(toRadian(angleStart)) / 3 + xStart;
        yBullet = - uStart * t * sin(toRadian(angleStart)) / 3 + 0.5 * 9.8 * t * t / 9 + yStart;
        t++;
    }
    else
    {
        xBullet = rotationX(xGun, toRadian(90 - angleGun), 2.25 * xGun);
        yBullet = rotationY(yGun, toRadian(90 - angleGun), 2.25 * xGun);
    }
    //________
    if (xBullet - rBullet <= 0)
    {
        isBulletFly = false;
        t = 0;
        fails++;
    }
    if (yBullet >= 500 - rBullet)
    {
        xStart = xBullet;
        yStart = yBullet;
        t = 1;
        up = !up;
    }
    if (xBullet >= 800 - rBullet)
    {
        xStart = xBullet;
        yStart = yBullet;
        angleStart = 180 - angleStart;
        t = 1;
    }
    if (yBullet <= 0 + rBullet)
    {
        xStart = xBullet;
        yStart = yBullet;
        angleStart =  360 - angleStart;
        t = 1;
        up = !up;
    }
    //________
    if (distance(xBullet, yBullet, xGoal, yGoal) < rBullet + rGoal)
    {
        isBulletFly = false;
        t = 0;
        goals++;
        yGoal = rand() % (yEnd - yBegin - 2 * rGoal) + yBegin + rGoal;
        xGoal = rand() % (xEnd - xBegin - 2 * rGoal) + xBegin + rGoal;
    }
}
//____________________________________________
void drawGUI()
{

    txBegin;

    txSetColour(TX_WHITE,1);
    txSetFillColour(TX_WHITE);
    txClear();

    //BACKGROUND
    txSetFillColour(TX_YELLOW);
    txRectangle(xBegin, yBegin, xEnd, yEnd);

    //TABLOSPEED
    txSetColour(TX_BLACK, 1);

    txSetFillColour(TX_WHITE);
    txRectangle(20, 80, 80, 280);

    txSetFillColour(TX_ORANGE);
    txRectangle(20, 80 + (125 - u0) * 4, 80, 280);

    //TABLO
    txSetColour(TX_LIGHTGREEN, 1);
    txSetFillColour(TX_LIGHTGREEN);
    txRectangle(10, 8, 53, 45);

    txSetColour(TX_BLACK, 1);
    txTextOut(10, 10, "Goals");
    txTextOut(10, 30, "Fails");

    txSetColour(TX_LIGHTCYAN, 1);
    txSetFillColour(TX_LIGHTCYAN );
    txRectangle(53, 8, 85, 45);

    txSetColour(TX_BLACK, 1);
    char str[3];
    sprintf(str,"%d",goals);
    txTextOut(55, 10, str);

    sprintf(str,"%d",fails);
    txTextOut(55, 30, str);




    //BYLLET
    txSetColour(TX_GREEN, 1);
    txSetFillColour(TX_GREEN);

    txCircle(xBullet, yBullet, rBullet);

    //GUN
    drawGun();

    //GOAL
    txSetColour(TX_PINK, 1);
    txSetFillColour(TX_PINK);

    txCircle(xGoal, yGoal, rGoal);


    txEnd;
    txSleep(5);

}
//____________________________________________
void drawGun()
{
    txSetColour(TX_BLACK, 20);
    txSetFillColour(TX_BLACK);

    txCircle(xGun, yGun, xGun);
    txLine(xGun, yGun, rotationX(xGun, toRadian(90 - angleGun), 2.25 * xGun), rotationY(yGun, toRadian(90 - angleGun), 2.25 * xGun));
}
//____________________________________________
double toRadian(int angle)
    {
        return angle * M_PI / 180.;
    }

double rotationX(double x, double angle, double length)
    {
        return x + sin(angle) * length;
    }

double rotationY(double y, double angle, double length)
    {
        return y * 1.0 - cos(angle) * length;
    }

double distance(double x1, double y1, double x2, double y2)
    {
        return sqrt ((( x1 - x2 ) * ( x1 - x2 )) + (( y1 - y2 ) * ( y1 - y2 )));
    }
