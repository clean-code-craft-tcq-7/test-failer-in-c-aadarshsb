#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXIMUM_MAJOR_COLOURS 5
#define MAXIMUM_MINOR_COLOURS 5
#define TOTAL_COLOUR_COMBOS (MAXIMUM_MAJOR_COLOURS*MAXIMUM_MINOR_COLOURS)
#define MAX_SIZE_FOR_DIGITS 3

//Um zu testen, brauchen wir die lokalen konstanten als globale konstanten. 
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int i32MaximumStringSize; 

char SpaceString[10]={'\0'};

void PrintWithGoodCondition();
void PrintNumberWithSymbol(int f_i32InputDigit);
void PrintStringsWithSpace(const char* f_WireColour);
int GetMaximumStringCounts();
void ReturnSpaces(int );

//இந்த விக்கியின் படி, தவறாக வடிவமைக்கப்பட்ட ஒரு வரைபடத்தை எண்களிலிருந்து வண்ணங்களுக்கு அச்சிட முயற்சிக்கிறது. 
//Misaligned versucht, eine Karte von Zahlen zu Farben zu drucken, wie in diesem Wiki beschrieben
int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++)
        {
            //இருப்பினும், எண் மதிப்புகள் மற்றும் பிரிப்பான் (|) தவறாக வடிவமைக்கப்பட்டுள்ளன
            //Die numerischen Werte und das Trennzeichen (|) sind jedoch falsch ausgerichtet. Das beudetet "%d |"
            
            printf("%d | %s | %s\n", (i*5 + j), majorColor[i], minorColor[i]);
            assert(majorColor[i]==majorColor[i]);
            assert(minorColor[j]==minorColor[i]);
        }
    }
    return i * j;
}

//-----------functions to align the number, string and | symbol to look like a proper table------//
void ReturnSpaces(int f_i32Count)
{
    int Index=0;
    for(;Index<f_i32Count; Index++)
    {
        SpaceString[Index]=' ';
    }
    SpaceString[Index]='\0';
}

void PrintWithGoodCondition()
{
    for(int i=0; i< 5; i++)
    {
        for(int j=0; j<5 ;j++)
        {
            PrintNumberWithSymbol((i*5)+(j+1));
            PrintStringsWithSpace(majorColor[i]);
            PrintStringsWithSpace(minorColor[j]);
            printf(" \n");
        }
    }
}
void PrintNumberWithSymbol(int f_i32InputDigit)
{
    if(f_i32InputDigit >=0 && f_i32InputDigit <= 9)
    {
        ReturnSpaces(MAX_SIZE_FOR_DIGITS-1);
        printf("%d%s|",f_i32InputDigit,SpaceString);
    }
    else if(f_i32InputDigit >=10 && f_i32InputDigit <= 100)
    {
        ReturnSpaces(MAX_SIZE_FOR_DIGITS-2);
        printf("%d%s|",f_i32InputDigit,SpaceString);
    }
}

void PrintStringsWithSpace(const char* f_WireColour)
{
   ReturnSpaces(i32MaximumStringSize  - (int)strlen((const char*)f_WireColour));
   printf("%s%s|",f_WireColour,SpaceString);
}

int GetMaximumStringCounts()
{
    long unsigned int i32MaximumSize = 0;
    for (int i=0; i< MAXIMUM_MAJOR_COLOURS; i++)
    {
        if(strlen(majorColor[i]) > i32MaximumSize)
        {
            i32MaximumSize = strlen(majorColor[i]);
        }
    }
    for (int i=0; i< MAXIMUM_MAJOR_COLOURS; i++)
    {
        if(strlen(minorColor[i]) > i32MaximumSize)
        {
            i32MaximumSize = strlen(majorColor[i]);
        }
    }
    return (int)i32MaximumSize;
}
//-----------functions to align the number, string and | symbol to look like a proper table[ENDS]------//

int main() {
    i32MaximumStringSize =  GetMaximumStringCounts()+1;
    PrintWithGoodCondition();
    int result = printColorMap();
    //செயல்பாடு திறமையாக சோதிக்கப்படவில்லை.
    //Die Funktionalität ist nicht effizient testbar – der Fehler muss von Menschen untersucht werden.
    //Since the number j has to be added with 1, the test should return 30 isntead of 25. i.e., J should start at 1 and ends at 5
    assert(result == 30);
    //கவலைகளை பிரித்து தனித்தனியாக சோதித்து பாருங்கள்.
    //Denken Sie daran, die Bedenken zu trennen und sie einzeln zu testen.
    printf("All is well (maybe!)\n");
    return 0;
}
