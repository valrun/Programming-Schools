#include <TXLib.h>
#include <math.h>
//____________________
enum ChooseGraph
{
    Sin, Parabola, Hyperbola, Module, Nothing
};
//____________________
void controlKeyboardState();
void measureGUI();
void drawGUI();

void graph();

double xCordToPix(double xCord);
double yCordToPix(double yCord);
double module(double a);
bool equalDouble(double a1, double a2);
//____________________
const int WINDOW_WIDTH = 701;
const int WINDOW_HEIGHT = 701;

const int PIX = 18;
const int PIX_IN_CORD = 40;
//____________________
double xArr[PIX * PIX_IN_CORD];
double yArr[PIX * PIX_IN_CORD];
bool isArr[PIX * PIX_IN_CORD];

bool click = true;
ChooseGraph chooseGraph = Nothing;
int lengthButton = 100;

double kx = 0;
double ky = 0;

double mashX = 1.0;
double mashY = 1.0;

int kParabola = 1;
int tmpkParabola = 0;
//____________________
int main()
{
    txCreateWindow (WINDOW_WIDTH, WINDOW_HEIGHT);
    txSetFillColour(TX_WHITE);
    txClear();

    for (int i = 0; i < PIX * PIX_IN_CORD / 2; i++)
    {
        xArr[PIX * PIX_IN_CORD / 2 + i] = i / float(PIX_IN_CORD);
        xArr[PIX * PIX_IN_CORD / 2 - i] = -1 * i / float(PIX_IN_CORD);
        isArr[PIX * PIX_IN_CORD / 2 + i] = true;
        isArr[PIX * PIX_IN_CORD / 2 - i] = true;
    }
    xArr[0] = -1 * PIX / 2;
    isArr[0] = true;

    while(true)
    {
        controlKeyboardState();
        measureGUI();
        drawGUI();
    }
}
//____________________
void controlKeyboardState()
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        kx += 0.1;
        click = true;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        kx -= 0.1;
        click = true;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        ky += 0.1;
        click = true;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        ky -= 0.1;
        click = true;
    }

    if (GetAsyncKeyState(0x44))
    {
        mashX *= 1.1;
        click = true;
    }
    if (GetAsyncKeyState(0x41))
    {
        mashX /= 1.1;
        click = true;
    }
    if (GetAsyncKeyState(0x57))
    {
        mashY *= 1.1;
        click = true;
    }
    if (GetAsyncKeyState(0x53))
    {
        mashY /= 1.1;
        click = true;
    }

    if (txMouseButtons() == 1)
    {
        if (txMouseY() >= WINDOW_HEIGHT - lengthButton)
        {
            if (txMouseX() < lengthButton)
            {
                chooseGraph = Sin;
            }
            else if (txMouseX() < lengthButton * 2)
            {
                chooseGraph = Parabola;
            }
            else if (txMouseX() < lengthButton * 3)
            {
                chooseGraph = Hyperbola;
            }
            else if (txMouseX() < lengthButton * 4)
            {
                chooseGraph = Module;
            }
            else if (txMouseX() < lengthButton * 5)
            {
                chooseGraph  = Nothing;
            }
        }
        click = true;
        ky = 0;
        kx = 0;
        mashX = 1;
        mashY = 1;
    }

    if (GetAsyncKeyState(0x30))
    {
        tmpkParabola = tmpkParabola * 10;
    }
    if (GetAsyncKeyState(0x31))
    {
        tmpkParabola = tmpkParabola * 10 + 1;
    }
    if (GetAsyncKeyState(0x32))
    {
        tmpkParabola = tmpkParabola * 10 + 2;
    }
    if (GetAsyncKeyState(0x33))
    {
        tmpkParabola = tmpkParabola * 10 + 3;
    }
    if (GetAsyncKeyState(0x34))
    {
        tmpkParabola = tmpkParabola * 10 + 4;
    }
    if (GetAsyncKeyState(0x35))
    {
        tmpkParabola = tmpkParabola * 10 + 5;
    }
    if (GetAsyncKeyState(0x36))
    {
        tmpkParabola = tmpkParabola * 10 + 6;
    }
    if (GetAsyncKeyState(0x37))
    {
        tmpkParabola = tmpkParabola * 10 + 7;
    }
    if (GetAsyncKeyState(0x38))
    {
        tmpkParabola = tmpkParabola * 10 + 8;
    }
    if (GetAsyncKeyState(0x39))
    {
        tmpkParabola = tmpkParabola * 10 + 9;
    }

    if (GetAsyncKeyState(0x0D))
    {
        kParabola = tmpkParabola;
        tmpkParabola = 0;
        click = true;
    }
}

void measureGUI()
{

    if (click)
    {
        switch(chooseGraph)
        {
            case Sin:
                for (int i = 0; i < PIX * PIX_IN_CORD; i++)
                {

                    yArr[i] = (sin((xArr[i] - kx) / mashX) + ky) * mashY;
                    isArr[i] = true;
                }
                break;

            case Parabola:
                for (int i = 0; i < PIX * PIX_IN_CORD; i++)
                {
                    yArr[i] = (pow((xArr[i] - kx) / mashX, 2) * kParabola + ky) * mashY ;
                    /*
                    !!!!!!!!!!!!!!!!!!!!!!
                    !!!!!!!!!!!!!!!!!!!
                    !!!!!!!!!!!!!!!!!
                    !!!!!!!!!!!!!!
                    !!!!!!!!!!
                    */
                    isArr[i] = true;
                }
                break;

            case Hyperbola:
                for (int i = 0; i < PIX * PIX_IN_CORD; i++)
                {
                    if (!equalDouble(xArr[i] - kx, 0.0))
                    {
                        yArr[i] = (1 / ((xArr[i] - kx) / mashX) + ky) * mashY;
                        isArr[i] = true;
                    }
                    else
                    {
                        isArr[i] = false;
                    }
                }
                break;

            case Module:
                for (int i = 0; i < PIX * PIX_IN_CORD; i++)
                {
                    yArr[i] = (module(module(module(module(module((xArr[i] - kx) / mashX) - 1) - 1) - 1) - 1) + ky) * mashY;
                    isArr[i] = true;
                }
                break;

            case Nothing:
                for (int i = 0; i < PIX * PIX_IN_CORD; i++)
                {
                    isArr[i] = false;
                }
                break;
        }
        click = false;
    }
}

void drawGUI()
{
    txBegin;
    txSetFillColor(TX_WHITE);
    txClear();

    //Ox and Oy
    txSetColour(TX_GRAY,1);

    double Ox = (WINDOW_WIDTH + 1) / 2 + kx * PIX_IN_CORD * mashX;
    double Oy = (WINDOW_HEIGHT + 1) / 2 - ky * PIX_IN_CORD * mashY;

    for (int i = 0; i < WINDOW_WIDTH ; i += PIX_IN_CORD * mashY)
    {
        txLine(0, Oy + i, WINDOW_WIDTH, Oy + i);
        txLine(0, Oy - i, WINDOW_WIDTH, Oy - i);
    }
    for (int i = 0; i < WINDOW_HEIGHT ; i += PIX_IN_CORD * mashX)
    {
        txLine (Ox + i, 0, Ox + i, WINDOW_HEIGHT);
        txLine (Ox- i, 0, Ox - i, WINDOW_HEIGHT);
    }

    txSetColour(TX_BLACK,4);

    txLine(0, (WINDOW_HEIGHT + 1) / 2, WINDOW_WIDTH, (WINDOW_HEIGHT + 1) / 2);
    txLine((WINDOW_WIDTH + 1) / 2, 0, (WINDOW_WIDTH + 1) / 2, WINDOW_HEIGHT);

    //GRAPH
    graph();

    //BUTTON and NAME
    COLORREF colorArr[] = {TX_LIGHTGREEN, TX_LIGHTCYAN, TX_YELLOW, TX_LIGHTBLUE, TX_PINK};

    for (int i = 0; i < 5; i++)
    {
        txSetFillColour(colorArr[i]);
        txSetColour(colorArr[i]);

        txRectangle(i * lengthButton, WINDOW_HEIGHT - lengthButton, (i + 1) * lengthButton, WINDOW_HEIGHT);

        txSetFillColour(TX_GRAY);
        txSetColour(TX_GRAY);
        txSelectFont ("Comic Sans MS", 50);

        switch(i)
        {
        case 0:
            txDrawText(i * lengthButton, WINDOW_HEIGHT - lengthButton, (i + 1) * lengthButton, WINDOW_HEIGHT, "Sin x");
            break;

        case 1:
            txDrawText(i * lengthButton, WINDOW_HEIGHT - lengthButton, (i + 1) * lengthButton, WINDOW_HEIGHT, "x^2");
            break;

        case 2:
            txDrawText(i * lengthButton, WINDOW_HEIGHT - lengthButton, (i + 1) * lengthButton, WINDOW_HEIGHT, "1/x");
            break;

        case 3:
            txDrawText(i * lengthButton, WINDOW_HEIGHT - lengthButton, (i + 1) * lengthButton, WINDOW_HEIGHT, "|x|-1..");
            break;

        case 4:
            txDrawText(i * lengthButton, WINDOW_HEIGHT - lengthButton, (i + 1) * lengthButton, WINDOW_HEIGHT, "Del");
            break;
        }

    }

    txEnd;
    txSleep(5);
}
//_____________________________
void graph()
{
    txSetFillColour(TX_ORANGE);
    txSetColour(TX_ORANGE, 2);
    for (int i = 0; i < PIX * PIX_IN_CORD - 1; i ++)
    {
        if (isArr[i] && isArr[i + 1])
        {
            txLine(xCordToPix(xArr[i]), yCordToPix(yArr[i]), xCordToPix(xArr[i + 1]), yCordToPix(yArr[i + 1]));
        }
    }
}
//______________________________
double xCordToPix(double xCord)
{
    return (WINDOW_WIDTH + 1) / 2 + xCord * PIX_IN_CORD;
}
double yCordToPix(double yCord)
{
    return (WINDOW_HEIGHT + 1) / 2 - yCord * PIX_IN_CORD;
}

double module(double a)
{
    if (a >= 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

bool equalDouble(double a1, double a2)
{
    a1 = a1 * 10000;
    a2 = a2 * 10000;
    int b1 = a1 / 1;
    int b2 = a2 / 1;
    if (b1 == b2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
