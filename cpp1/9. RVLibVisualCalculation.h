//9. RVLibVisualCalculation.h
#include <TxLib.h>

void controlKeyboardState();
void measureGUI();
void drawGUI();

void drawCalculation()
{
    int size = 500;
    txCreateWindow (size, size);
    size = size / 5;
    txSetFillColour(TX_WHITE);
    txClear();
    while(true)
    {
        controlKeyboardState();
        measureGUI();
        drawGUI();
    }
}

void controlKeyboardState()
{

}
void measureGUI()
{

}
void drawGUI()
{
     COLORREF line = TX_LIGHTBLUE;
     COLORREF field = RGB (168, 255, 255);
     COLORREF deleteB = RGB (73, 71, 194);
     COLORREF digits = RGB (233, 203, 175);
     COLORREF sign = RGB (163, 245, 163);
     txSetColor (line);

     //Field
     txSetFillColor (field);
     txRectangle (0, 0, 400, 100);

     //<-
     txSetFillColor (deleteB);
     txRectangle (400, 0, 500, 100);

     //7
     txSetFillColor (digits);
     txRectangle (0, 100, 100, 200);

     //8
     txSetFillColor (digits);
     txRectangle (100, 100, 200, 200);

     //9
     txSetFillColor (digits);
     txRectangle (200, 100, 300, 200);

     //4
     txSetFillColor (digits);
     txRectangle (0, 200, 100, 300);

     //5
     txSetFillColor (digits);
     txRectangle (100, 200, 200, 300);

     //6
     txSetFillColor (digits);
     txRectangle (200, 200, 300, 300);

     //1
     txSetFillColor (digits);
     txRectangle (0, 300, 100, 400);

     //2
     txSetFillColor (digits);
     txRectangle (100, 300, 200, 400);

     //3
     txSetFillColor (digits);
     txRectangle (200, 300, 300, 400);

     //0
     txSetFillColor (digits);
     txRectangle (100, 400, 200, 500);

     //+
     txSetFillColor (sign);
     txRectangle (300, 100, 400, 200);

     //-
     txSetFillColor (sign);
     txRectangle (400, 100, 500, 200);

     //*
     txSetFillColor (sign);
     txRectangle (300, 200, 400, 300);

     //:
     txSetFillColor (sign);
     txRectangle (400, 200, 500, 300);

     //(
     txSetFillColor (sign);
     txRectangle (300, 300, 400, 400);

     //)
     txSetFillColor (sign);
     txRectangle (400, 300, 500, 400);

     //.
     txSetFillColor (sign);
     txRectangle (0, 400, 100, 500);

     //=
     txSetFillColor (sign);
     txRectangle (200, 400, 400, 500);

     //C
     txSetFillColor (sign);
     txRectangle (400, 400, 500, 500);



}
