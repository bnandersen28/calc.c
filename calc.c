//Bayleigh Andersen
//February 27, 2024
//CSCI 304
/*This program prints out a menu and options, along with a value displayed in different bases. The default value
is 0 and the menu should be displayed until a valid option is inputed.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
char print_menu(); //Is this global variable okay? 


short get_operand (char mode) // read in numeric value in mode; return value
{
    short input_val;  //How can I ensure first input is used for adding and subtracting
    char bin_str;       //If input_val is only defined in here
    switch(mode)
    {
        case 'O': 
            printf("Enter octal value: ");
            scanf("%ho",&input_val);
            printf("%o\n\n", input_val);
            break;
        case 'H':
            printf("Enter hex value: ");
            scanf("%hx", &input_val);
            printf("%x\n\n", input_val);
            break;
        case 'D':
            printf("Enter decimal value: ");
            scanf("%hd", &input_val);
            printf("%d\n\n", input_val);
            break;
        case 'B':
            printf("Enter binary value: ");
            scanf("%s",&bin_str);
            printf("%s\n\n",bin_str);
            return bin_str; //Do I need to include to avoid crashes with last line in function?
        default:
            break; 
    }
   
    return input_val;
   

}

//unsigned short get_binary_op (bin_str bin) // convert bin str to short; return value
//void convert_to_binary (short val, bin_str bin) // convert val to binary str for output
// If function is void how is there output?

void print_bases (short input_val, char mode) // print out base values and str for mode
{
    char modestring[4]= "   ";
    
    //Set mode string based on mode
    switch(mode)
    {
        case 'D':
            strcpy(modestring, "Dec");
            break;
        case 'H':
            strcpy(modestring, "Hex");
            break;
        case 'O':
            strcpy(modestring, "Oct");
            break;
        case 'B':
            strcpy(modestring, "Bin");
        default:
            break;
    }
    
///How to make sure values are updated based on operations? 

    printf("****************************************\n");
    printf("*  Base Values:        Input Mode: %s *\n",modestring); 
    ///printf("*    Binary  :  %16") get variable from convert to binary function
    printf("*    Hex     :  %04hX                   *\n",input_val);
    printf("*    Octal   :  %06ho                 *\n",input_val);
    printf("*    Decimal :  %-6hd                 *\n",input_val);
    printf("****************************************\n");
    printf("\n"); 

}





char print_menu (void) // print menu; get option until valid; return option
{
    
    char mode= 'D';
    char input[3];
    int valid = 0; 

while (!valid){
    printf("Please select one of the following options:\n"); //Keep showing until valid input
    printf("\n");
    printf("B Binary Mode            & AND with Value             + Add to Value\n");
    printf("O  Octal Mode            | OR with Value              - Subtract from value\n");
    printf("H  Hexadecimal Mode      ^ XOR with Value             N Negate value\n");
    printf("D  Decimal Mode          ~ Complement Value\n");
    printf("\n");
    printf("C  Clear Value           < Shift Value Left\n");
    printf("S  Set Value             > Shift Value Right\n");
    printf("\n");
    printf("Q  Quit\n");
    printf("\n");
    printf("Option: ");
    scanf("%s", input);
    printf("%s\n",input);


/// check if valid
    mode = toupper(input[0]);
    valid = 1;
    char valid_input[17] = "OHDCSQB&|^~<>+-N";
    if (strlen(input)!= 1|| !strchr(valid_input, mode)) 
    {
        printf("\nInvalid option: %s\n\n",input);
        valid = 0; 

    }
    }
    return mode;

                }

int main (void) // main menu loop; execute option or call
// appropriate function
{  
    int quit= 0; 
    short input_val = 0; 
    char mode = 'D';
    short operator; 

    while (!quit)
    {   print_bases(input_val,mode);

        switch(print_menu())
        {
            case 'O':
                mode='O';
                printf("Mode: Octal\n\n");
                break;
            
            case 'H':
                printf("Mode: Hexadecimal\n\n"); 
                mode='H';
                break;
            case 'D':
                printf("Mode: Decimal\n\n");
                mode='D';
                break;
            case 'C': 
                input_val = 0;
                printf("\n");
                break;
            case 'S':
                input_val = get_operand(mode);
                break;
            case 'Q': 
                quit = 1;
                break;
            case 'B':
                printf("Mode: Binary\n\n");
                mode= 'B';
                break; // edit after binary functions determined
            case '<':
                printf("Enter number of positions to left shift value: \n\n");
                mode = '<'; //Ensure calculations made based on mode
                break; 
            case '>':
                printf("Enter number of positions to right shift value: \n\n");
                mode = '>'; //Ensure calculations based on mode
                break;
            case '+':
                  //Uses add function
                break; 
            case '-':
                //Uses subtract function
                break;  
            default:
                break;  
        

                }
                }
                return 0;}
    
    

void add (short *val, char mode) // call get_operand to get value in mode
 // to add to val; detect pos/neg overflow
{
    

} 