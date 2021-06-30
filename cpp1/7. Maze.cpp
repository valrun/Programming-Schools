#include "7. RVLibMaze.h"


Item createArray(Item** arr);
void printArray(Item** arr);
void printArrayVal(Item** pitch);


using namespace std;

int main()
{
    int sizePitch = 5;
    Item** pitch = (Item**)malloc(sizePitch * sizeof(Item*));
    for (int i = 0; i < sizePitch; i++)
    {
        pitch[i] = (Item*)calloc(sizePitch, sizeof(Item));
    }

    for (int i = 0; i < sizePitch; i++)
    {
        for (int j = 0; j < sizePitch; j++)
        {
            pitch[i][j].x = j;
            pitch[i][j].y = i;
            pitch[i][j].val = 0;
        }
    }
    createArray(pitch);
    printArray(pitch);

    pitch[0][0].val = 1;


    Queue q;
    q.create();
    q.add(pitch[0][0]);

    bool carrot = false;
    Item tmp;

    while(q.isEmpty())
    {
        if (q.type() == Carrot)
        {
            carrot = true;
            break;
        }

        if (q.y() - 1 >= 0)//no
        {
            if (pitch[q.y() - 1][q.x()].val == 0 && pitch[q.y() - 1][q.x()].type != Wall)
            {
                pitch[q.y() - 1][q.x()].val = pitch[q.y()][q.x()].val + 1;
                q.add(pitch[q.y() - 1][q.x()]);
            }
        }

        if (q.y() + 1 < sizePitch)//no
        {
            if (pitch[q.y() + 1][q.x()].val == 0 && pitch[q.y() + 1][q.x()].type != Wall)
            {
                pitch[q.y() + 1][q.x()].val = pitch[q.y()][q.x()].val + 1;
                q.add(pitch[q.y() + 1][q.x()]);
            }
        }

        if (q.x() - 1 >= 0)//no
        {
            if (pitch[q.y()][q.x() - 1].val == 0 && pitch[q.y()][q.x() - 1].type != Wall)
            {
                pitch[q.y()][q.x() - 1].val = pitch[q.y()][q.x()].val + 1;
                q.add(pitch[q.y()][q.x() - 1]);
            }
        }

        if (q.x() + 1 < sizePitch)//yes
        {
            if (pitch[q.y()][q.x() + 1].val == 0 && pitch[q.y()][q.x() + 1].type != Wall) //no
            {
                pitch[q.y()][q.x() + 1].val = pitch[q.y()][q.x()].val + 1;
                q.add(pitch[q.y()][q.x() + 1]);
            }
        }

        q.poll(&tmp);
    }

    printf("\n");

    if (carrot)
    {
        int x = q.x();
        int y = q.y();
        int val = q.val();

        while (val > 1)
        {
            if (y - 1 >= 0 && pitch[y - 1][x].val == val - 1)
            {
                pitch[y - 1][x].type = Way;
                val--;
                y--;
            }
            else if (y + 1 < sizePitch && pitch[y + 1][x].val == val - 1)
            {
                pitch[y + 1][x].type = Way;
                val--;
                y++;
            }
            else if (x - 1 >= 0 && pitch[y][x - 1].val == val - 1)
            {
                pitch[y][x - 1].type = Way;
                val--;
                x--;
            }
            else if (x + 1 < sizePitch && pitch[y][x + 1].val == val - 1)
            {
                pitch[y][x + 1].type = Way;
                val--;
                x++;
            }
        }
        printArray(pitch);
    }
    else
    {
        printf("!NO CARROT!");
    }
    q.destruct();

    return 0;
}

Item createArray(Item** pitch)
{
    pitch[0][0].type = Rabbit;
    pitch[0][1].type = Blank;
    pitch[0][2].type = Wall;
    pitch[0][3].type = Blank;
    pitch[0][4].type = Carrot;
    //___________________
    pitch[1][0].type = Blank;
    pitch[1][1].type = Blank;
    pitch[1][2].type = Wall;
    pitch[1][3].type = Blank;
    pitch[1][4].type = Blank;
    //___________________
    pitch[2][0].type = Blank;
    pitch[2][1].type = Blank;
    pitch[2][2].type = Blank;
    pitch[2][3].type = Wall;
    pitch[2][4].type = Blank;
    //___________________
    pitch[3][0].type = Blank;
    pitch[3][1].type = Blank;
    pitch[3][2].type = Blank;
    pitch[3][3].type = Wall;
    pitch[3][4].type = Wall;
    //___________________
    pitch[4][0].type = Blank;
    pitch[4][1].type = Blank;
    pitch[4][2].type = Blank;
    pitch[4][3].type = Wall;
    pitch[4][4].type = Blank;
    //___________________
}

void printArray(Item** pitch)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            switch(pitch[i][j].type)
            {
            case Carrot:
                printf ("%2c",'!');
                break;

            case Rabbit:
                printf ("%2c",'@');
                break;

            case Wall:
                printf ("%2c",'#');
                break;

            case Blank:
                printf ("%2c",'.');
                break;

            case Way:
                printf ("%2c",'$');
                break;
            }
        }
        printf("\n");
    }
}

void printArrayVal(Item** pitch)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%2d ", pitch[i][j].val);
        }
        printf("\n");
    }
}

