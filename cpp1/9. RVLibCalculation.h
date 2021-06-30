//9. RVLibCalculation.h
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "9. StackStr.h"
#include "8. RVLibStack.h";
//#include "9. RVLibVisualCalculation.h"


char inversionBrackts(char brackts)
{
    switch (brackts)
    {
    case '(':
        brackts = ')';
        break;
    case '[':
        brackts = ']';
        break;
    case '{':
        brackts = '}';
        break;
    case ')':
        brackts = '(';
        break;
    case ']':
        brackts = '[';
        break;
    case '}':
        brackts = '{';
        break;
    }
    return brackts;
}

bool isBracketsCorrect(char* str)
{
    StackStr brackets;
    brackets.create();

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            brackets.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            char out;
            brackets.getTop(& out);
            if (str[i] != inversionBrackts(out) || !brackets.isEmpty())
            {
                brackets.destruct();
                return false;
            }
            else
            {
                brackets.pop(& out);
            }
        }
    }
    bool a = brackets.isEmpty();
    brackets.destruct();
    return !a;
}

int degree(int a, int b)
{
    int d = 1;
    for (int i = 0; i < b; i ++)
    {
        d *= a;
    }
    return d;
}

enum TokenType
{
    Operand, Operation, Bracket, Space
};
enum SignType
{
    Plus, Minus, Multiply, Divise, Degree, Open, Close
};

int priority(SignType sign)
{
    switch (sign)
    {
    case Plus: return 2;
        break;
    case Minus: return 2;
        break;
    case Multiply: return 3;
        break;
    case Divise: return 3;
        break;
    case Degree: return 4;
        break;
    case Open: return 0;
        break;
    case Close: return 0;
        break;
    }
}

struct Token
{
    TokenType type;
    union
    {
        int val;
        SignType sign;
    };

    bool strToToken(char* str, int* pos);

    bool isBrackets(char* str, int* pos);
    bool isNumber(char* str, int* pos);
    bool isOperation(char* str, int* pos);
    bool print();

};

bool Token::strToToken(char* str, int* pos)
{
    if (str[*pos] == ' ')
    {
        type = Space;
        (*pos)++;
        return true;
    }
    else if (isBrackets(str, pos))
    {
        return true;
    }
    else if (isNumber(str, pos))
    {
        return true;
    }
    else if (isOperation(str, pos))
    {
        return true;
    }
    return false;
}

bool Token::isBrackets(char* str, int* pos)
{
    if (inversionBrackts(str[*pos]) != str[*pos])
    {
        type = Bracket;
        if (str[*pos] == '(' || str[*pos] == '{' || str[*pos] == '[')
        {
            sign = Open;
        }
        else
        {
            sign = Close;
        }
        (*pos)++;
        return true;
    }
    return false;
}

bool Token::isNumber(char* str, int* pos)
{
    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    bool number = false;
    bool number2 = false;
    for (int i = 0; i < 10; i++)
    {
        if (str[*pos] == arr[i])
        {
            number = true;
            number2 = true;
            val = i;
            (*pos)++;
            break;
        }
    }

    while (number)
    {
        number = false;

        for (int i = 0; i < 10; i++)
        {
            if (str[*pos] == arr[i])
            {
                val = val * 10 + i;
                number = true;
                (*pos)++;
                break;
            }
        }
    }
    return number2;

}

bool Token::isOperation(char* str, int* pos)
{
    if ('+' == str[*pos])
    {
        type = Operation;
        sign = Plus;
        (*pos)++;
        return true;
    }
    else if ('-' == str[*pos])
    {
        type = Operation;
        sign = Minus;
        (*pos)++;
        return true;
    }
    else if ('*' == str[*pos])
    {
        type = Operation;
        sign = Multiply;
        (*pos)++;
        return true;
    }
    else if (':' == str[*pos] || '/' == str[*pos])
    {
        type = Operation;
        sign = Divise;
        (*pos)++;
        return true;
    }
    else if ('^' == str[*pos])
    {
        type = Operation;
        sign = Degree;
        (*pos)++;
        return true;
    }
    return false;
}

bool Token::print()
{
    switch (type)
    {
    case Operand: printf("Operand ");
            printf("%d \n",val);
            return true;
            break;
    case Operation: printf("Operation ");
                switch (sign)
                {
                case Plus: printf("Plus ");
                    break;
                case Minus: printf("Minus ");
                    break;
                case Multiply: printf("Multiply ");
                    break;
                case Divise: printf("Divise ");
                    break;
                case Degree: printf("Degree ");
                    break;
                case Open: printf("Open ");
                    break;
                case Close: printf("Close ");
                    break;
                }
                printf("\n");
                return true;
                break;
    case Bracket: printf("Bracket ");
            printf("%d ", priority(sign));
            printf("\n");
            return true;
            break;
    case Space: printf("Space ");
            printf("\n");
            return true;
            break;
    }
}



struct StackSign
{

    SignType* arr;
    int top;
    int memory;

    void create();
    void destruct();

    void push(SignType x);
    bool pop(SignType* out);
    bool getTop(SignType* out);

    bool isEmpty();
    void print();
};
//__________________________________________________
void StackSign::create()
{
    memory = 10;
    arr = (SignType*)calloc(memory, sizeof(SignType));
    top = -1;
}

void StackSign::destruct()
{
    free(arr);
    arr = NULL;
    memory = 0;
}

void StackSign::push(SignType x)
{
    top++;
    if (top == memory - 1)
    {
        memory += 10;
        arr = (SignType*)realloc(arr, memory * sizeof(SignType));
    }
    arr[top] = x;
}

bool StackSign::pop(SignType* out)
{
    if (top > -1)
    {
        *out = arr[top--];
        return true;
    }
    else
    {
        return false;
    }

}

bool StackSign::getTop(SignType* out)
{
    if (top > -1)
    {
        *out = arr[top];
        return true;
    }
    else
    {
        return false;
    }
}

bool StackSign::isEmpty()
{
    return top != -1;
}

void StackSign::print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%ñ", arr[i]);
    }
    printf("\n");
}
//_________________________



struct TokenArr
{
    Token* arr;
    int count;
    int memory;

   bool strToArr(char* str);
   void print();
   void create();
   void destruct();

   void toRPN();
   int fromRPN();
};
//________________
void TokenArr::create()
{
    memory = 20;
    count = 0;
    arr = (Token*)calloc(memory, sizeof(Token));
}

void TokenArr::destruct() //??????
{
    free(arr);
    arr = NULL;
    memory = 0;
}

bool TokenArr::strToArr(char* str)
{
    int i = 0;
    count = 0;
    while (i < strlen(str))
    {
        if (arr[count].strToToken(str, &i))
        {
            count++;
            //printf("%d \n", i);
        }
        else
        {
            return false;
        }
    }
    return true;
}

void TokenArr::print()
{
     for (int i = 0; i < count; i++)
     {
        arr[i].print();
     }
}

void TokenArr::toRPN()
{
    StackSign StackSign;
    StackSign.create();

    Token* Output;
    int countOutput;
    int memoryOutput;

    memoryOutput = 20;
    countOutput = 0;
    Output = (Token*)calloc(memory, sizeof(Token));

    for (int i = 0; i < count; i++)
     {
         switch (arr[i].type)
        {
        case Operand:
            Output[countOutput] = arr[i];
            countOutput++;
            break;

        case Operation:
            if (StackSign.isEmpty())
            {
                SignType tmp;
                StackSign.getTop(&tmp);
                if (priority(arr[i].sign) > priority(tmp))
                {
                    StackSign.push(arr[i].sign);
                }
                else
                {
                    Token tmpToken;
                    while ( priority(tmp) >= priority(arr[i].sign))
                    {
                         StackSign.pop(&tmp);
                         tmpToken.type = Operation;
                         tmpToken.sign = tmp;
                         Output[countOutput] = tmpToken;
                         countOutput++;
                         if (StackSign.isEmpty())
                         {
                             StackSign.getTop(&tmp);
                         }
                         else
                         {
                             break;
                         }

                    }
                    StackSign.push(arr[i].sign);
                }

            }
            else
            {
                StackSign.push(arr[i].sign);
            }
            break;

        case Bracket:
            if (arr[i].sign == Open)
            {
                StackSign.push(arr[i].sign);

            }
            else
            {
                SignType tmp;
                Token tmpToken;
                StackSign.pop(&tmp);
                while (Open != tmp)
                {
                    tmpToken.type = Operation;
                    tmpToken.sign = tmp;
                    Output[countOutput] = tmpToken;
                    countOutput++;
                    StackSign.pop(&tmp);
                }
            }
            break;

        case Space:
            break;
        }
     }

     SignType tmp;
     Token tmpToken;
     while (StackSign.isEmpty())
     {
        StackSign.pop(&tmp);
        tmpToken.type = Operation;
        tmpToken.sign = tmp;
        Output[countOutput] = tmpToken;
        countOutput++;
     }

     StackSign.destruct();
     for (int i = 0; i < countOutput; i++)
     {
         arr[i] = Output[i];
         //arr[i].print();
     }
     count = countOutput;
}

int TokenArr::fromRPN()
{
    Stack stackOperand;
    stackOperand.create();
    int a, b;

    for (int i = 0; i < count; i++)
    {
        if (arr[i].type == Operand)
        {
            stackOperand.push(arr[i].val);
            //printf("!");
        }
        else
        {
            stackOperand.pop(&b);
             //printf("%d " , b);
            stackOperand.pop(&a);
             //printf("%d " , a);

            switch (arr[i].sign)
            {
            case Plus: a = a + b; //printf("+");
                break;
            case Minus: a = a - b; //printf("(");
                break;
            case Multiply: a = a * b; //printf("@");
                break;
            case Divise: a = a / b; //printf("/");
                break;
            case Degree: a = degree(a , b);
                break;
            }
            stackOperand.push(a);
        }
    }

    stackOperand.pop(&b);
    stackOperand.destruct();
    //printf("\n");
    return b;
}
//__________________
