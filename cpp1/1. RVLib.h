#include "TXLib.h"
#include <math.h>
//#include <iostream>
//#include <stdio.h>
//#include <cstdlib>
//#include <ctime>
//________________________________________________________________
enum Side
{
    Left, Right
};

enum PlaceEyeball
{
    Center, Borderland
};
//________________________________________________________________
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

double findAngel(double x0, double y0, double x, double y)
    {
        if ( x0 < x && y0 >= y)
        {
            return atan2(abs(x - x0), abs(y - y0));
        }
        else if ( x0 <= x && y0 < y)
        {
            return M_PI * 0.5 + atan2(abs(y - y0), abs(x - x0));
        }
        else if ( x0 > x && y0 <= y)
        {
            return M_PI + atan2(abs(x - x0), abs(y - y0));
        }
        else if ( x0 >= x && y0 > y)
        {
            return M_PI * 1.5 + atan2(abs(y - y0), abs(x - x0));
        }
        else
        {
            return 0;
        }

    }

double turnX(double Xcenter, double Ycenter, double x, double y, double angle)
{
    return  rotationX(Xcenter, angle + findAngel(Xcenter, Ycenter, x, y), distance(Xcenter, Ycenter, x , y));
}

double turnY(double Xcenter, double Ycenter, double x, double y, double angle)
{
    return  rotationY(Ycenter, angle + findAngel(Xcenter, Ycenter, x, y), distance(Xcenter, Ycenter, x , y));
}
//________________________________________________________________

void drawCat(int x, int y, int widthHead, PlaceEyeball placeEyeball, int angleEyeball, int percentageOfEyeballFromEye, int percentageOfMove)
    {
        int width = widthHead;
        COLORREF colorRED = RGB (255, 0, 0);
        double height = 0.66 * width;

        //FEET
        txSetFillColour(colorRED);
        txSetColour(colorRED);

        double feetY1 = y + 1.12 * height;
        double feetY2 = y + 1.66 * height;
        double feetWidth = 0.06 * width;

        double step , k = 0.002;

        if (percentageOfMove <= 25)
        {
            step = percentageOfMove * width * k;
        }
        else if (percentageOfMove <= 50)
        {
            step = ( 50 - percentageOfMove ) * width * k;
        }
        else if (percentageOfMove <= 75)
        {
            step = ( -1 ) * ( percentageOfMove - 50 ) * width * k;
        }
        else
        {
            step = ( -1 ) * ( 100 - percentageOfMove ) * width * k;
        }

        double feetX1 = x + 0.6 * width;
        double feetX2 = feetX1 + step;
        POINT feet1 [4] = { { feetX1, feetY1 }, { feetX1 + feetWidth, feetY1 },
        { feetX2 + feetWidth, feetY2 }, { feetX2, feetY2 } };
        txPolygon (feet1 , 4);

        feetX1 = x + 0.7 * width;
        feetX2 = feetX1 - step;
        POINT feet2 [4] = { { feetX1, feetY1 }, { feetX1 + feetWidth, feetY1 },
        { feetX2 + feetWidth ,feetY2 },{ feetX2, feetY2 } };
        txPolygon (feet2 , 4);

        feetX1 =  x + 1.2 * width ;
        feetX2 = feetX1 - step;
        POINT feet3 [4] = { { feetX1, feetY1 }, { feetX1 + feetWidth, feetY1 },
        { feetX2 + feetWidth, feetY2 }, { feetX2, feetY2 } };
        txPolygon (feet3 , 4);

        feetX1 = x + 1.3 * width;
        feetX2 = feetX1 + step;
        POINT feet4 [4] = { { feetX1, feetY1 }, { feetX1 + feetWidth, feetY1 },
        { feetX2 + feetWidth, feetY2 },{ feetX2, feetY2 } };
        txPolygon (feet4 , 4);

        //TAIL
        txSetFillColour(colorRED);
        txSetColour(colorRED);

        double tailY1 = y + 0.33 * height;
        double tailY2 = y + height;
        double tailWidth = 0.09 * width;

        double tailX1 = x + 1.65 * width;
        double tailX2 = x + 1.4 * width;

        POINT tail [4] = { { tailX1, tailY1 }, { tailX1 + tailWidth, tailY1 },
        { tailX2 + tailWidth, tailY2 }, { tailX2, tailY2 } };
        txPolygon (tail , 4);

        txCircle(tailX1 + tailWidth / 2, tailY1,tailWidth / 2);

        //BODY
        txSetColour(colorRED);
        txSetFillColour(colorRED);
        txEllipse(x + 0.4 * width, y + 0.7 * height, x + 1.55 * width, y + 1.35 * height);

        //HEAD
        txSetFillColour(colorRED);
        txSetColour(TX_RED);

        txChord (x, y, x + width, y + height, 170, 200);

        txSetColour(colorRED);
        int angleDUGI = 120;
        txChord (x, y, x + width, y + height, 130, angleDUGI);
        txChord (x, y, x + width, y + height, 290, angleDUGI);

        //EAR
        txSetFillColour(TX_WHITE);
        txSetColour(TX_WHITE);

        double earY1 = 0.36, earY2 = 0.2;

        double earX11 = 0.15, earX12 = 0.207, earX13 = 0.25;
        double earX21 = 0.85, earX22 = 0.803, earX23 = 0.75;

        txLine(x + earX11 * width, y + earY1 * height, x + earX13 * width, y + earY1 * height);
        txLine(x + earX12 * width, y + earY2 * height, x + earX13 * width, y + earY1 * height);
        txLine(x + earX11 * width, y + earY1 * height, x + earX12 * width, y + earY2 * height);

        txLine(x + earX21 * width, y + earY1 * height, x + earX23 * width, y + earY1 * height);
        txLine(x + earX22 * width, y + earY2 * height, x + earX23 * width, y + earY1 * height);
        txLine(x + earX21 * width, y + earY1 * height, x + earX22 * width, y + earY2 * height);

        //EYES
        txSetFillColour(TX_WHITE);
        txSetColour(TX_WHITE);

        double eyesR = 0.1 * height, eyesX = x + 0.3 * width, eyesY = y + 0.6 * height;

        txCircle(eyesX, eyesY, eyesR);
        txCircle(eyesX + 0.4 * width, eyesY, eyesR);

        //eyeballs
        txSetColour(TX_BLACK);
        txSetFillColour(TX_BLACK);
        double eyeballsR = percentageOfEyeballFromEye * eyesR / 100.;

        if (placeEyeball == Borderland)
        {
            double length = eyesR - eyeballsR;//length from the center eyes to the borderland
            double angleEyeballRadian = toRadian(angleEyeball);
            eyesX = rotationX(eyesX, angleEyeballRadian, length);
            eyesY = rotationY(eyesY, angleEyeballRadian, length);
        }

        txCircle(eyesX ,eyesY, eyeballsR);
        txCircle(eyesX + 0.4 * width, eyesY, eyeballsR);

        //MOUTH
        txSetFillColour(TX_WHITE);
        txSetColour(TX_WHITE, 2);

        double mouthX1 = 0.5 , mouthX2 = 0.4;
        double mouthY1 = 0.76 , mouthY2 = 0.86;

        txArc (x + mouthX1 * width, y + mouthY1 * height, x + mouthX2 * width, y + mouthY2 * height, 220, 150);
        txArc (x + mouthX1 * width, y + mouthY1 * height, x + (1 - mouthX2) * width, y + mouthY2 * height, 170, 150);

        //NOSE
        txSetFillColour(TX_PINK);
        txSetColour(TX_PINK, 1);

        double noseY = 0.73;
        double noseX = 0.47;

        POINT nose [3] = { { x + 0.5 * width, y + 0.81 * height }, { x + noseX * width, y + noseY * height },
        { x + (1 - noseX) * width, y + noseY * height}};
        txPolygon (nose , 3);
    }
//________________________________________________________________

void drawSun(int x, int y, int width, int angleRays)
    {
        txSetColour(TX_YELLOW);
        txSetFillColour(TX_YELLOW);
        double X0 = x + 0.5 * width, Y0 = y + 0.5 * width;//X and zero

        txCircle(X0, Y0, 0.143 * width);

        //LONG
        txSetColour(TX_YELLOW, width / 20);
        double turnAngle = toRadian(angleRays);
        for (int i = 0; i < 360; i = i + 90)
        {
            turnAngle = toRadian(angleRays + i);
            txLine(rotationX(X0, turnAngle, 0.214 * width), rotationY(Y0, turnAngle, 0.214 * width),rotationX(X0, turnAngle, 0.5 * width), rotationY(Y0, turnAngle, 0.5 * width));
        }

        //MIDDLE
        txSetColour(TX_YELLOW, (width / 40));
        for (int i = 0; i < 360; i = i + 45)
        {
            turnAngle = toRadian(angleRays + i);
            txLine(rotationX(X0, turnAngle, 0.214 * width), rotationY(Y0, turnAngle, 0.214 * width), rotationX(X0, turnAngle, 0.4 * width), rotationY(Y0, turnAngle, 0.4 * width));
        }

        //SHIRT
        txSetColour(TX_YELLOW, (width / 60));

        for (int i = 22.5; i < 360;i = i + 45)
        {
            turnAngle = toRadian(angleRays + i);
            txLine(rotationX(X0, turnAngle, 0.214 * width), rotationY(Y0, turnAngle, 0.214 * width), rotationX(X0, turnAngle, 0.3 * width), rotationY(Y0, turnAngle, 0.3 * width));
        }
    }
//________________________________________________________________
void drawMouse(int x, int y, int width, Side tailSide)
    {
        double height =  width * (170 / 182.);

        txSetColour(TX_BLACK);

        //EARS
        txSetFillColour(TX_GRAY);

        double earsX1 = 0.604 , earsX2 = 0.209;
        double earsY = 0.141;
        double rBig = 0.11 * width;
        double rSmall = 0.055 * width;

        txCircle(x + earsX1 * width, y + earsY * height, rBig);
        txCircle(x + earsX2 * width, y + earsY * height, rBig);

        txSetFillColour(TX_PINK);
        txCircle(x + earsX1 * width, y + earsY * height, rSmall);
        txCircle(x + earsX2 * width, y + earsY * height, rSmall);

        //LEGS
        txSetFillColour(TX_GRAY);
        txSetColour(TX_BLACK);

        double legsY1 = 0.941 , legsY2 = 1.059;

        txChord(x + 0.121 * width, y + legsY1 * height, x + 0.368 * width, y + legsY2 * height, 0, 180);
        txChord(x + 0.445 * width, y + legsY1 * height, x + 0.692 * width, y + legsY2 * height, 0, 180);

        //HANDS
        txSetColour(TX_BLACK);
        txSetFillColour(TX_GRAY);

        double handsR = y + 0.623 * height;

        txEllipse(x, y + 0.529 * height, x + 0.176 * width, handsR);
        txEllipse(x + 0.637 * width, y + 0.529 * height, x + 0.813 * width, handsR);

        //TAIL
        int forxtail;
        int forsidetail;

        if (tailSide == Right)
        {
            forxtail = 0;
            forsidetail = 1;
        }
        else
        {
            forxtail = width;
            forsidetail = -1;
        }

        POINT tail [10] = {{x + forxtail + forsidetail * 0.604 * width, y + 0.853 * height}, {x + forxtail + forsidetail * 0.736 * width, y + 0.906 * height},
        {x + forxtail + forsidetail * 0.824 * width, y + 0.835 * height}, {x + forxtail + forsidetail * 0.901 * width, y + 0.706 * height},
        {x + forxtail + forsidetail * 0.989 * width, y + 0.647 * height}, {x + forxtail + forsidetail * width, y + 0.676 * height},
        {x + forxtail + forsidetail * 0.956 * width, y + 0.694 * height}, {x + forxtail + forsidetail * 0.856 * width, y + 0.835 * height},
        {x + forxtail + forsidetail * 0.813 * width, y + 0.894 * height}, {x + forxtail + forsidetail * 0.758 * width, y + 0.929 * height}};
        txPolygon(tail , 10);

        //BODY
        txEllipse(x + 0.132 * width, y + 0.141 * height, x + 0.681 * width, y + height);

        //BELLY
        txSetFillColour(TX_PINK);
        txEllipse(x + 0.302 * width, y + 0.576 * height, x + 0.51 * width, y + 0.953 * height);

        //EYES
        txSetFillColour(TX_BLACK);

        double eyesY = 0.276;
        double eyesR = 0.37;

        txEllipse(x + 0.291 * width, y + eyesY * height, x + 0.318 * width, y + eyesR * height);
        txEllipse(x + 0.495 * width, y + eyesY * height, x + 0.522 * width, y + eyesR * height);

        //NOSE
        txSetFillColour(TX_PINK);
        txEllipse(x + 0.374 * width, y + 0.4 * height, x + 0.44 * width, y + 0.447 * height);

        //MOUTH
        txSetFillColour(TX_WHITE);

        double mouthY1 = 0.47;
        double mouthY2 = 0.529;
        double mouthY3 = 0.447;


        POINT mouth [7] = {{x + 0.406 * width, y + 0.447 * height}, {x + 0.352 * width, y + mouthY1 * height},
        {x + 0.406 * width, y + mouthY2 * height}, {x + 0.406 * width, y + mouthY3 * height}, {x + 0.462 * width, y + mouthY1 * height},
        {x + 0.406 * width, y + mouthY2 * height}, {x + 0.406 * width, y + mouthY3 * height}};
        txPolygon(mouth , 7);

    }
//________________________________________________________________
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void drawTARDIS(int x, int y, int width, COLORREF colorLamp)
    {
        /*
        TARDIS
        TARDIS
        TARDIS
        */

        //BODY
        txSetColour(TX_BLUE);
        txSetFillColour(TX_BLUE);

        double bodyX = 0.045;
        double bodyY1 = 0.045 , bodyY2 = 0.09 , bodyY3 = 0.136 , bodyY4 = 1.409;
        double bodyX1 = 0.455 , bodyX2 = 0.136;

        txRectangle(x + bodyX * width, y + bodyY3 * width, x + (1 - bodyX) * width, y + bodyY4 * width);

        txRectangle(x + bodyX1 * width, y, x + (1 - bodyX1) * width, y + bodyY1 * width);
        txRectangle(x + bodyX2 * width, y + bodyY2 * width, x + (1 - bodyX2) * width, y + bodyY3 * width);

        txRectangle(x, y + bodyY4 * width, x + width, y + 1.5 * width);

        //LAMP
        txSetColour(colorLamp);
        txSetFillColour(colorLamp);

        txRectangle(x + bodyX1 * width, y + bodyY1 * width, x + (1 - bodyX1) * width, y + bodyY2 * width);

        //POLICE BOX
        txSetColour(TX_BLACK);
        txSetFillColour(TX_BLACK);

        txRectangle(x + 0.182 * width, y + 0.182 * width, x + 0.818 * width, y + 0.273 * width);

        //WINDOWS
        //!!!!!!!
        double windowX1 = 0.182 , windowX2 = 0.273;
        double dwindowX = 0.363;
        double windowY1 = 0.364 , windowY2 = 0.181;
        double dwindowY = 0.272;
        //!!!!!!!

        txSetFillColour(TX_WHITE);
        txSetColour(TX_BLACK,2);

        for (double i = windowX1; i <= dwindowX + windowX1; i += dwindowX)
        {
            txRectangle(x + i * width, y + windowY1 * width, x + (i + windowX2) * width, y + (windowY1 + windowY2) * width);

            txLine(x + (i + (windowX2 / 3)) * width, y + windowY1 * width, x + (i + (windowX2 / 3)) * width, y + (windowY1 + windowY2) * width);
            txLine(x + (i + (windowX2 / 3 * 2)) * width, y + windowY1 * width, x + (i + (windowX2 / 3 * 2)) * width, y + (windowY1 + windowY2) * width);

            txLine(x + i * width, y + (windowY1 * 2 + windowY2) / 2 * width, x + (i + windowX2) * width, y + (windowY1 * 2 + windowY2) / 2 * width);
        }

        txSetColour(TX_BLACK, 1);

        //WHITE PIECE
        txSetFillColour(TX_WHITE);
        txSetColour(TX_WHITE);

        txRectangle(x + windowX1 * width, y + (windowY1 + dwindowY) * width, x + (windowX1 + windowX2) * width, y + (windowY1 + windowY2 + dwindowY) * width);

        //BLUE PIECES
        txSetFillColour(RGB(0, 71, 171));
        txSetColour(RGB(0, 71, 171));

        txRectangle(x + (windowX1 + dwindowX) * width, y + (windowY1 + dwindowY) * width, x + (windowX1 + windowX2 + dwindowX) * width, y + (windowY1 + windowY2 + dwindowY) * width);

        for (double i = windowX1; i <= windowX1 + dwindowX; i += dwindowX)
        {
            for (double j = (windowY2 + dwindowY) * 2; j <= (windowY2 + dwindowY) * 3; j += dwindowY)
            {
                txRectangle(x + i * width, y + j * width, x + (i + windowX2) * width, y + (j + windowY2) * width);
            }
        }


    }
//________________________________________________________________

void drawFish(int x, int y, int width, int angle,  Side bodySide)
    {
        int height = width * 0.8;

        int forXSide;
        int forSide;

        if (bodySide == Left)
        {
            forXSide = 0;
            forSide = 1;
        }
        else
        {
            forXSide = width;
            forSide = -1;
            angle = 360 - angle;
        }

        //TAIL
        txSetColour(TX_CYAN, 4);
        txSetFillColour(TX_MAGENTA );

         double xtail = x + 0.6 * width * forSide + forXSide;
         double ytail = y + 0.5 * height;

         double angle1R = toRadian(angle + 70 * forSide); //For 1 side
         double angle2R = toRadian(angle + 110 * forSide); //For 2 side
         double lengthtail = 0.4 * width;

        POINT fishTail [3] = {{xtail, ytail},{rotationX(xtail, angle1R, lengthtail), rotationY(ytail, angle1R, lengthtail)},
        {rotationX(xtail, angle2R, lengthtail), rotationY(ytail, angle2R, lengthtail)}};
        txPolygon(fishTail, 3);

        //BODY
        txSetColour(TX_GREEN, 10);
        txSetFillColour(TX_YELLOW);

        double bodyX = 0.8;

        POINT fishBody [3] = {{x + forXSide, y + 0.5 * height}, {x + bodyX * width * forSide + forXSide, y}, {x + bodyX * width * forSide + forXSide, y + height}};
        txPolygon(fishBody, 3);

        //HEAD
        txSetColour(TX_PINK, 7);
        txSetFillColour(TX_ORANGE);

        double headX = 0.2;
        double headY = 0.375;

        POINT fishHead [3] = {{x + forXSide, y + 0.5 * height}, {x + headX * width * forSide + forXSide, y + headY * height}, {x + headX * width * forSide + forXSide, y + (1 - headY) * height}};
        txPolygon(fishHead, 3);

        //EYE
        txSetColour(TX_LIGHTGREEN, 1);
        txSetFillColour(TX_BLUE);

        txCircle (x + 0.132 * width * forSide + forXSide, y + 0.5 * height, 0.02 * width);

    }
//________________________________________________________________

void drawPizza(int x, int y, int width, int angle)
    {

        double height = 1.5 * width;

        double Xcenter = x + 0.5 * width;
        double Ycenter = y + 0.5 * height;

        double Rangle = toRadian(angle);

      //CRISP
      txSetColour(TX_ORANGE);
      txSetFillColour(TX_ORANGE);

      POINT fishCrisp [3] = {{turnX(Xcenter, Ycenter, x, y, Rangle), turnY(Xcenter, Ycenter, x, y, Rangle)},
      {turnX(Xcenter, Ycenter, x + width, y, Rangle), turnY(Xcenter, Ycenter, x + width, y, Rangle)},
      {turnX(Xcenter, Ycenter, x + 0.5 * width, y + height, Rangle), turnY(Xcenter, Ycenter, x + 0.5 * width, y + height, Rangle)}};
      txPolygon (fishCrisp , 3);

      //DOUGH
      txSetColour(TX_YELLOW );
      txSetFillColour(TX_YELLOW );

      double kX = 0.05;
      double kY = 0.12;

      POINT fishDough [3] = {{turnX(Xcenter, Ycenter, x + kX * width, y + kY * height, Rangle), turnY(Xcenter, Ycenter, x + kX * width, y + kY * height, Rangle)},
      {turnX(Xcenter, Ycenter, x  + (1 - kX) * width, y + kY * height, Rangle), turnY(Xcenter, Ycenter, x  + (1 - kX) * width, y + kY * height, Rangle)},
      {turnX(Xcenter, Ycenter, x  + 0.5 * width, y + height, Rangle), turnY(Xcenter, Ycenter, x  + 0.5 * width, y + height, Rangle)}};
      txPolygon(fishDough , 3);

      //SAUSAGE
      txSetColour(TX_LIGHTRED);
      txSetFillColour(TX_LIGHTRED);

      double Rsausage = 0.11 * width;

      txCircle(turnX(Xcenter, Ycenter, x + 0.25 * width, y + 0.267 * height, Rangle), turnY(Xcenter, Ycenter, x + 0.25 * width, y + 0.267 * height, Rangle), Rsausage);
      txCircle(turnX(Xcenter, Ycenter, x + 0.75 * width, y + 0.233 * height, Rangle), turnY(Xcenter, Ycenter, x + 0.75 * width, y + 0.233 * height, Rangle), Rsausage);
      txCircle(turnX(Xcenter, Ycenter, x + 0.55 * width, y + 0.467 * height, Rangle), turnY(Xcenter, Ycenter, x + 0.55 * width, y + 0.467 * height, Rangle), Rsausage);
      txCircle(turnX(Xcenter, Ycenter, x + 0.5 * width, y + 0.717 * height, Rangle), turnY(Xcenter, Ycenter, x + 0.5 * width, y + 0.717 * height, Rangle), Rsausage);
    }
//________________________________________________________________
