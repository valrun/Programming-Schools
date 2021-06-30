#include "TXLib.h"
#include <math.h>
#include <stdio.h>

enum FaceType
{
    Normal, Surprise, Angry
};

void drawFace(int x, int y, int r, COLORREF color, int mouthOpenPercent, FaceType type);
double degreeToRadians(int angle);
void animateFaceSimple(int startX, int startY, int animationDistance, int faceR, int repeatCount);
void animateFace(int startX, int y, int animationDistance, int faceR, int repeatCount);
void animateFaceSin(int startX, int startY, int animationDistance, int faceR);

int main()
{
    int windowWidth = 800;
    int windowHeight = 600;
    txCreateWindow(windowWidth, windowHeight);
    int r = 100;
    animateFaceSin(r, windowHeight / 2, windowWidth - 2 * r, r);
}

void animateFaceSimple(int startX, int startY, int animationDistance, int faceR, int repeatCount)
{
    int r = faceR, x = startX, y = startY;
    for(int i = 0; i < repeatCount; i++)
    {
        int finishX = startX + animationDistance;
        while(x <= finishX)
        {
            txBegin();
            txSetFillColor(TX_WHITE);
            txClear();
            drawFace(x, y, r, TX_BLACK, 30, Normal);
            txEnd();
            x++;
        }
        finishX = startX;
        while(x >= finishX)
        {
            txBegin();
            txSetFillColor(TX_WHITE);
            txClear();
            drawFace(x, y, r, TX_BLACK, 30, Normal);
            txEnd();
            x--;
        }
    }
}

void animateFace(int startX, int startY, int animationDistance, int faceR, int repeatCount)
{
    int r = faceR, x = startX, y = startY;
    int finishX = startX + animationDistance;
    int k = 1;
    int i = 0;


    //printf("%d", finishX);
    while(i < repeatCount)
    {
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        drawFace(x, y, r, TX_BLACK, 30, Normal);
        txEnd();
        if (x * k >= finishX * k)
        {
            finishX =  finishX - animationDistance * k;
            //printf("%d", finishX);
            k = -k;
            i++;
        }
        x += k;
    }
}

int sign(double value)
{
    return (value >= 0) - (value < 0);
}

void animateFaceSin(int startX, int startY, int animationDistance, int faceR)
{
    int r = faceR, x = startX, y = startY;
    int k = 1;
    int i = 0;

    int tmpX = x;

    //printf("%d", finishX);
    while(true)
    {
        double sinus = sin((tmpX - startX) * M_PI / animationDistance);
        k = sign(sinus);
        tmpX = startX + (tmpX - startX + 1) % (animationDistance * 2);
        x += k;
        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();
        drawFace(x, y, r, TX_BLACK, 30, Normal);
        txEnd();
        txSleep(10);
    }
}


void drawFace(int x, int y, int r, COLORREF color, int mouthOpenPercent, FaceType type)
{
    txSetColor(color);

    //draw head
    txCircle(x, y, r);

    //draw eyes
    int eyeR = r / 4;
    int eyeXShift = r * 0.38;
    int eyeYShift = r * 0.38;
    int eye1X = x - eyeXShift;
    int eye2X = x + eyeXShift;
    int eyeY = y - eyeYShift;

    txCircle(eye1X, eyeY, eyeR);
    txCircle(eye2X, eyeY, eyeR);

    //draw eye pupils
    int eyePupilR = eyeR / 5;
    if (eyePupilR == 0)
    {
        eyePupilR = 1;
    }
    txSetFillColor(TX_BLACK);
    txCircle(eye1X, eyeY, eyePupilR);
    txCircle(eye2X, eyeY, eyePupilR);

    //draw mouth
    txSetFillColor(TX_RED);
    int mouthWidth = 2 * r / 3;
    int mouthX = x - mouthWidth / 2;
    int mouthY = y + r / 3;
    if (mouthOpenPercent > 100)
    {
        mouthOpenPercent = 100;
    }
    int mouthHeight = mouthOpenPercent / 100. * r / 3;
    if (mouthHeight <= 0)
    //Проблемы с доступом в джойказино&
    {
        mouthHeight = 1;
    }
    txEllipse(mouthX, mouthY, mouthX + mouthWidth, mouthY + mouthHeight);

    //draw brows
    int browAngle = 0;
    switch(type)
    {
        case Surprise:
            browAngle = 20;
            break;
        case Angry:
            browAngle = -25;
            break;
    }

    int browLength = eyeR * 1.8;
    int browDistance = eyeR * 1.2;
    int leftBrowX1 = x - browDistance / 2 - browLength;
    int leftBrowX2 = leftBrowX1 + browLength * cos(degreeToRadians(browAngle));
    int rightBrowX1 = x + browDistance / 2 + browLength;
    int rightBrowX2 = rightBrowX1 + browLength * cos(degreeToRadians(180 - browAngle));
    int browExternalY = eyeY - eyeR * 1.5;
    int browInternalY = browExternalY - browLength * sin(degreeToRadians(browAngle));
    txLine(leftBrowX1, browExternalY, leftBrowX2, browInternalY);
    txLine(rightBrowX1, browExternalY, rightBrowX2, browInternalY);
}

double degreeToRadians(int angle)
{
    return angle * M_PI / 180;
}
