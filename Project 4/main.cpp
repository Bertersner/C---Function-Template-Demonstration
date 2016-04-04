
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
The end goal of this program is to demonstrate an appropriate use for function templates. I (the programmer) have been provided with a text file containing
both integer and string values. This program will read from that input file and store the integer values in an integer vector and the string values into
a string vector. Using function templates that will work with multiple data types, this program will output the minimum and maximum values stored in both
the integer and string vectors. One function template will return the minimum value for both of the vectors while a second function template will return the
maximum value for both of the vectors.
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/



#include "TemplateExample.h"                                                            //   include the class specification file for the class "TemplateExample"




/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
                                                 THIS MARKS THE BEGINNING OF THE MAIN FUNCTION
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/
int main()                                                                              //   begin function definition
{
   TemplateExample example;                                                             //   create an object "example" of type "TemplateExample"


   cout << "The min value of the integer vector is " << example.min(example.getIntVector()) << endl;     //   output the minimum value in the integer vector

   cout << "The max value of the integer vector is " << example.max(example.getIntVector()) << endl;     //   output the maximum value in the integer vector

   cout << "The min value of the string vector is " << example.min(example.getStrVector()) << endl;      //   output the minimum value in the string vector

   cout << "The max value of the string vector is " << example.max(example.getStrVector()) << endl;      //   output the maximum value in the string vector


   system("pause");                                                               //   pause before terminating the program so the user can see the output
   return 0;                                                                      //   terminate the program without errors
}                                                                                 //   end of the function definition
/**********************************************************************************************************************************************************
***********************************************************************************************************************************************************
                                                     THIS MARKS THE END OF THE MAIN FUNCTION
***********************************************************************************************************************************************************
***********************************************************************************************************************************************************/