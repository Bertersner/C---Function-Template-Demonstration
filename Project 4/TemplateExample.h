
// Byron Burdette
// COP2535.0M1



/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                            CLASS SPECIFICATION FILE FOR THE CLASS TemplateExample
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/





/**********************************************                PREPROCESSOR DIRECTIVES            **************************************************/
#pragma once                                                 //   include guard ensures this file is included, but only once

#include<iostream>                                           //   includes the library for standard I/O stream objects
#include<vector>                                             //   includes the library for vector containers
#include<fstream>                                            //   includes the library for file stream objects
#include<string>                                             //   includes the library for string types
#include<algorithm>                                          //   includes the library for functions designed to be used on ranges of elements
/**********************************************************************************************************************************************************/


using namespace std;                                         //   lifts all entities in the standard namespace into the current global namespace



class TemplateExample                                        //   begins the class declaration
{
private:
   ifstream inFile;                                          //   declares an input filestream object "inFile" which we'll use to access the file we need to populate our vectors
   vector<int> intVector;                                    //   declares an int vector "intVector" to store the integers from the input file
   vector<string> strVector;                                 //   declares a string vector "strVector" to store the strings from the input file

public:

   /*   THIS MARKS THE BEGINNING OF THE DEFAULT CONSTRUCTOR. The purpose of this function is to open up the input file and use the data inside it to populate our two vectors.
      For the purposes of this assignment, it is assumed that the input file will contain only good integer and string values. To populate the vectors, we begin by storing 
      the next value from the input file in a string variable. Then we attempt to convert that string to an int. If the conversion is successful, then we have and int which
      will be stored in the integer vector. Otherwise, the value is a string and will be stored in the string vector.    */
   TemplateExample()
   {
      inFile.open("minmax.txt");                                //   open up our input file "minmax.txt"
      string str;                                               //   declare a string variable "str"
      int temp;                                                 //   declare an int variable "temp"

      while (inFile >> str)                                     //   read the next value from the input file and store it in the string "str"
      {
         try                                                    //   attempt to execute the following statements...
         {
            temp = stoi(str);                                   //   convert the string "str" to an integer and store it in "temp"
            intVector.push_back(temp);                          //   store the integer "temp" in the integer vector
         }
         catch (exception e) { strVector.push_back(str); }      //   if the conversion failed, it means we're dealing with a string instead of an int. Catch the exception and simply store the string in the string vector
      }

   }                                                            //   THIS MARKS THE END OF THE DEFAULT CONSTRUCTOR


   /*   THIS MARKS THE BEGINNING FO THE FUNCTION TEMPLATE "min". The purpose of this function is to take in a vector of unknown type and return the minimum value stored in the vector.
      The use of a function template here allows us to use one function for both the integer and string vectors   */
   template <class T>                                                  //   template prefex marks the beginning of the function template
   T min(vector <T> v) { return *min_element(begin(v), end(v)); }      //   return the minimum value stored in the vector


   /*   THIS MARKS THE BEGINNING FO THE FUNCTION TEMPLATE "max". The purpose of this function is to take in a vector of unknown type and return the maximum value stored in the vector.
      The use of a function template here allows us to use one function for both the integer and string vectors   */
   template <class T>                                       //   template prefix marks the beginning of the function template
   T max(vector <T> v) { return *max_element(begin(v), end(v)); }      //   return the minimum value stored in the vector


   /*   THIS MARKS THE BEGINNING OF THE FUNCTION "getIntVector". The purpose of this function is to provide a safe way of referencing the integer vector outside of the class. I chose to pass the
      vector by reference to avoid making copies of a large vector in the event the vector becomes very large. However, this would leave the vector vulnerable. To protect the contents of the function,
      I chose to make the function "const" which forces every member in the function to be constant, which prevents the members from being modified.   */
   const vector<int>& getIntVector() const { return intVector; }


   /*   THIS MARKS THE BEGINNING OF THE FUNCTION "getStrVector". The purpose of this function is to provide a safe way of referencing the string vector outside of the class. I chose to pass the
      vector by reference to avoid making copies of a large vector in the event the vector becomes very large. However, this would leave the vector vulnerable. To protect the contents of the function,
      I chose to make the function "const" which forces every member in the function to be constant, which prevents the members from being modified.   */
   const vector<string>& getStrVector() const { return strVector; }
};

/*********************************************************************************************************************************************************
**********************************************************************************************************************************************************
                                            THIS MARKS THE END OF THE CLASS SPECIFICATION FILE
**********************************************************************************************************************************************************
**********************************************************************************************************************************************************/