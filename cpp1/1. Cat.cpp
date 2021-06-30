#include "1. RVLib.h"
//________________________________________________________________
void animateScene1();
void animateScene2();
void animateScene3();
//________________________________________________________________
int main()
    {
    txCreateWindow (800, 600);
    txSetFillColour(TX_WHITE);
    txClear();

    animateScene1();
    animateScene2();
    animateScene3();

    return 0;
    }
//________________________________________________________________
void animateScene1()
{
    int i = 0;
    int angleCat = 300 , percentageOfMoveCat = 0 , percentageOfEyeballFromEyeCat = 55 , xCat = 800 , yCat = 300 , widthCat = 200;
    int angleSun = 0, xSun = 10 , ySun = 10 , widthSun = 180;
    int xTARDIS = 800 , yTARDIS = 0, widthTARDIS = 10 , RTARDIS = 128 , GTARDIS = 128, BTARDIS = 128 , forColor = 0;
    bool flagForColor = true;
    int xMouse = -184 , yMouse = 300 , widthMouse = 184 , forXMouse = 1 , forYMouse = 1;
    Side tailMouse = Left;


    while (xCat >= 600)
    {
       txBegin;
       txSetFillColour(RGB(168, 216, 255));
       txClear();
       txSetFillColour(RGB(32, 232, 14));
       txSetColour(TX_BLACK);
       txRectangle(0, 320, 800, 600);
       drawCat(xCat, yCat, widthCat, Center, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
       drawSun(xSun, ySun, widthSun, angleSun);
       drawMouse(xMouse, yMouse, widthMouse, tailMouse);
       txEnd;

       xCat--;
       xMouse++;
       percentageOfMoveCat++;
       angleSun++;

        if (percentageOfMoveCat == 100)
        {
            percentageOfMoveCat = 1;
        }

        if (angleSun == 360)
        {
            angleSun = 0;
        }

        txSleep(2);
    }

    while (i < 4)
    {
       txBegin;
       txSetFillColour(RGB(168, 216, 255));
       txClear();
       txSetFillColour(RGB(32, 232, 14));
       txSetColour(TX_BLACK);
       txRectangle(0, 320, 800, 600);
       drawCat (xCat, yCat, widthCat, Borderland, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
       drawSun(xSun, ySun, widthSun, angleSun);
       drawMouse(xMouse, yMouse, widthMouse, tailMouse);
       txEnd;

       angleSun++;

       xMouse += forXMouse;
       yMouse += forYMouse;

       if (angleCat > 180 && angleCat < 320)
       {
           angleCat -= forYMouse;
       }

       if (angleCat == 180)
       {
           angleCat = 181;
       }

       if (angleCat == 320)
       {
           angleCat = 319;
       }

        if (angleSun == 360)
        {
            angleSun = 0;
        }

        if (xMouse > 400)
        {
            forXMouse = -1;
            tailMouse = Right;
        }

        if (xMouse < 100)
        {
            forXMouse = 1;
            tailMouse = Left;
        }

        if (yMouse > 400)
        {
            forYMouse = -1;
            i++;
        }

        if (yMouse < 250)
        {
            forYMouse = 1;
            i++;
        }

        txSleep(1);
    }

    while (yMouse < 600)
    {
       txBegin;
       txSetFillColour(RGB(168, 216, 255));
       txClear();
       txSetFillColour(RGB(32, 232, 14));
       txSetColour(TX_BLACK);
       txRectangle(0, 320, 800, 600);
       drawCat (xCat, yCat, widthCat, Borderland, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
       drawSun(xSun, ySun, widthSun, angleSun);
       drawMouse(xMouse, yMouse, widthMouse, tailMouse);
       txEnd;

       xMouse += forXMouse * 2;
       yMouse += forYMouse * 2;

       if (angleCat >= 220)
       {
           angleCat -= forYMouse;
       }

       angleSun++;

        if (angleSun == 360)
        {
            angleSun = 0;
        }

        txSleep(1);
    }

    while (xCat>=17)
    {
       txBegin;
       txSetFillColour(RGB(168, 216, 255));
       txClear();
       txSetFillColour(RGB(32, 232, 14));
       txSetColour(TX_BLACK);
       txRectangle(0, 320, 800, 600);
       drawCat(xCat, yCat, widthCat, Center, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
       drawSun(xSun, ySun, widthSun, angleSun);
       txEnd;

       xCat--;
       percentageOfMoveCat++;
       angleSun++;

        if (percentageOfMoveCat == 100)
        {percentageOfMoveCat = 1;}
        if (angleSun == 360)
        {angleSun = 0;}

        txSleep(2);
    }

    i = 0;
    angleCat = 45;
    while (xTARDIS > 400)
    {
       txBegin;
       txSetFillColour(RGB(168, 216, 255));
       txClear();
       txSetFillColour(RGB(32, 232, 14));
       txSetColour(TX_BLACK);
       txRectangle(0, 320, 800, 600);
       drawCat(xCat,yCat, widthCat, Borderland, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
       drawSun(xSun, ySun, widthSun, angleSun);
       drawTARDIS(xTARDIS,yTARDIS, widthTARDIS, RGB(RTARDIS, GTARDIS, BTARDIS));
       txEnd;

       angleSun++;
       i++;

       xTARDIS -= 2;
       yTARDIS++;
       widthTARDIS++;

       GTARDIS = forColor;
       BTARDIS = 255 - forColor;
       RTARDIS = forColor;

       if (i == 10)
       {
        i = 0;
        percentageOfEyeballFromEyeCat++;
        angleCat++;

       }

        if (angleSun == 360)
        {angleSun = 0;}

        if (forColor < 255 && flagForColor)
        {
            forColor += 4;
        }
        else if (forColor > 0)
        {
            forColor -= 4;
            flagForColor = false;
        }
        else
        {
            flagForColor = true;
        }

        txSleep(2);
    }

    while (xCat + widthCat * 2 > 0)
    {
       txBegin;
       txSetFillColour(RGB(168, 216, 255));
       txClear();
       txSetFillColour(RGB(32, 232, 14));
       txSetColour(TX_BLACK);
       txRectangle(0, 320, 800, 600);
       drawCat(xCat, yCat, widthCat, Center, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
       drawSun(xSun, ySun, widthSun, angleSun);
       drawTARDIS(xTARDIS,yTARDIS, widthTARDIS, RGB(RTARDIS, GTARDIS, BTARDIS));
       txEnd;

       xCat--;
       angleSun++;

       GTARDIS = forColor;
       BTARDIS = 255 - forColor;
       RTARDIS = forColor;

       percentageOfMoveCat++;

        if (percentageOfMoveCat == 100)
        {
            percentageOfMoveCat = 1;
        }
        if (angleSun == 360)
        {angleSun = 0;}

        if (forColor < 255 && flagForColor)
        {
            forColor += 4;
        }
        else if (forColor > 0)
        {
            forColor -= 4;
            flagForColor = false;
        }
        else
        {
            flagForColor = true;
        }

        txSleep(2);
    }
}
//________________________________________________________________
void animateScene2()
{
    int xCat = 800 , yCat = 50 , widthCat = 150 , angleCat = 300 , percentageOfEyeballFromEyeCat = 55 , percentageOfMoveCat = 0;
    COLORREF water = RGB(0, 204, 255);
    int Raquarium = 270 , xaquarium = 300 , yaquarium = 300;
    int xFish = xaquarium - Raquarium , widthFish = 200 , yFish = yaquarium - 0.5 * widthFish , angleTailFish = -30 , forTailFish = 1 , forXFish = 1 , forYFish = -1;
    Side bodySideFish = Right;

    while (xCat >= 0 - 2 * widthCat)
    {
       txBegin;
       txSetFillColour(RGB(150, 75, 0));
       txClear();
       txSetFillColour(RGB(255, 255, 82));
       txSetColour(TX_BLACK);
       txRectangle(0, 250, 800, 600);
       drawCat(xCat, yCat, widthCat, Center, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);

       txSetFillColour(water);
       txSetColour(TX_WHITE);
       txEllipse(60, 470, 540, 600);
       txCircle(xaquarium, yaquarium, Raquarium);

       drawFish(xFish, yFish, widthFish, angleTailFish, bodySideFish);
       txEnd;

       xCat--;
       percentageOfMoveCat++;

       if (percentageOfMoveCat == 100)
       {
            percentageOfMoveCat = 1;
       }

       xFish += forXFish;
       yFish += forYFish;
       angleTailFish += forTailFish;

       if (angleTailFish < -40)
       {
           forTailFish = 1;
       }

       if (angleTailFish > 40)
       {
           forTailFish = -1;
       }

       if (xFish < xaquarium - Raquarium + 20)
       {
           forXFish = 1;
           bodySideFish = Right;
       }

       if (xFish + widthFish > xaquarium + Raquarium - 20)
       {
           forXFish = -1;
           bodySideFish = Left;
       }

       if (yFish < yaquarium - Raquarium + 20)
       {
           forYFish = 1;
       }

       if (yFish + 0.8 * widthFish > yaquarium + Raquarium - 20)
       {
           forYFish = -1;
       }

       txSleep(2);
    }

}
//________________________________________________________________
void animateScene3()
{
    srand(time(NULL));

    int xCat = 800 , yCat = 100 , widthCat = 400 , angleCat = 300 , percentageOfEyeballFromEyeCat = 60 , percentageOfMoveCat = 0;
    int k = 1;

    int n = 50;

    int angle[n];
    int x[n];
    int y[n];
    int width[n];

    for (int i = 0 ; i < n ; i++)
    {
        angle[i] =  rand() % 361;
        x[i] = rand() % 700;
        y[i] = rand() % 600;
        width[i] = 1 + rand() % 200;
    }

    while (xCat > 100)
    {
        txBegin;
        txSetFillColour(TX_BLACK);
        txClear();
        for (int i = 0 ; i < n ; i++)
        {
            drawPizza(x[i], y[i], width[i], angle[i]);
        }
        drawCat(xCat, yCat, widthCat, Center, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
        txEnd;
        txSleep(3);

        for (int i = 0 ; i < n ; i++)
        {
            angle[i]++;

            if (angle[i] == 360)
            {
                angle[i] = 0;
            }
        }

        xCat--;
        percentageOfMoveCat++;

        if (percentageOfMoveCat == 100)
        {
            percentageOfMoveCat = 1;
        }

    }

        while (true)
    {
        txBegin;
        txSetFillColour(TX_BLACK);
        txClear();
        for (int i = 0 ; i < n ; i++)
        {
            drawPizza(x[i], y[i], width[i], angle[i]);
        }
        drawCat(xCat, yCat, widthCat, Borderland, angleCat, percentageOfEyeballFromEyeCat, percentageOfMoveCat);
        txEnd;
        txSleep(3);

        for (int i = 0 ; i < n ; i++)
        {
            angle[i]++;

            if (angle[i] == 360)
            {
                angle[i] = 0;
            }
        }

        percentageOfMoveCat++;

        if (percentageOfMoveCat == 100)
        {
            percentageOfMoveCat = 1;
        }

        angleCat++;

        if (angleCat == 360)
        {
            angleCat = 0;
        }

        percentageOfEyeballFromEyeCat += k;

        if (percentageOfEyeballFromEyeCat == 100)
        {
            k = -1;
        }

        if (percentageOfEyeballFromEyeCat == 10)
        {
            k = 1;
        }
    }
}
//________________________________________________________________
