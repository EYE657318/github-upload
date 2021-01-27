// need doucumentation for each member function - similar to your last
// project

#ifndef MYTIME_H
#define MUTIME_H
#include <iostream>

using namespace std;
    
class MyTime
{   
  public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    //MyTime();           vestigal
    MyTime(int h = 0, int m = 0);   
   /**           Function: Conctructor
   Sets h to 0 and m to 0 if not otherwise specified
   @param h - the number of hours.
   @param m - the number of minutes.
   */
      
    void Reset(int h, int m);   
    /**   Function: Reset
    sets h and m to the numbers specified.
    @param h - the number of hours
    @param m - the number of minutes
    */ 
   
    MyTime operator + (const MyTime& t2); 
    /** Function: overloaded +
    Adds the hours of one MyTime to another, then does the same with minutes. Returns a class of the result.
    @param t2 - the class for which this is not a member.
    */
  
    MyTime operator - (const MyTime& t2); 
     /** Function: overloaded -
     Returns a MyTime class where the hours and minutes are that of one MyTime minus another's.
     @param t2 - the class for which this is not a member.

    */
 
    MyTime operator * (int num);    
     /** Function: overloaded *
     Multiplies the hours and minutes of a MyTime class by a number
     @param num - the number to be multiplied by
    */
 
    MyTime operator / (int num);    
     /** Function: overloaded /
     Divides the hours and minutes of a MyTime class by a number
     @param num - the number to be divided by
    */

    

    bool operator == (const MyTime& t2);          //becomes a member of t1  //compares hours and minutes
     /** Function: overloaded ==
     Checks if the total time of two MyTimes are equal
     @param t2 - the class for which this is not a member
    */

    bool operator < (const MyTime& t2);        //becomes a member of t1    //converts hours into minutes and adds then, checks vs t2
     /** Function: overloaded <
     Checks if the total time of the first MyTime is smaller than the other
     @param t2 - the class for which this is not a member
    */

    bool operator <= (const MyTime& t2);             //same as above, but with the equals
     /** Function: overloaded <=
     Checks if the total time of the first MyTime is smaller than or equal to the second
     @param t2 - the class for which this is not a member
    */

    istream& input(std::istream& ins);
     /** Function: input
      Used to input two numbers into the hours and minutes of a class
      @param ins - the istream the numbers are coming from
    */            

    ostream& output(std::ostream& outs) const;
     /** Function: output
      Used to output the hours and minutes of a MyTime class into standard time form (h:m)
      @param outs - where information is being outputted.
    */

    int get_hours() const{return hours;}
     /** Function: get_hours
      Returns the hours in the MyTime class
    */
    int get_minutes() const{return minutes;}
     /** Function: get_minutes
      Returns the minutes in the MyTime class
    */
   
  private:
      void simplify();
       /** Function: simplufy
        Converts minutes into hours when applicable
    */
      int hours;      // hours can be > 24
      int minutes;   // 0 <= minutes <= 59
 };

 std::istream& operator >>(std::istream& fin, MyTime& t);   
  /** Function: overloaded >>
    Calls input to take in informaiton for a MyTime
    @param fin - where the input is coming from
    @param t -  the MyTime class
    */ 
    
 std::ostream& operator <<(std::ostream& fout, const MyTime& t);     
  /** Function: overloaded << 
    Calls output to print the information in a MyTime
    @param fout - where the output is going 
    @param t - the MyTime class
    */
   
#endif
 
