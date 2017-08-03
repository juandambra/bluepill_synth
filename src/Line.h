
#ifndef LINE_H_
#define LINE_H_

#include <arm_math.h>


/** For linear changes with a minimum of calculation at each step. For instance,
   you can use Line to make an oscillator glide from one frequency to another,
   pre-calculating the required phase increments for each end and then letting your
   Line change the phase increment with only a simple addition at each step.
   @tparam T the type of numbers to use. For example, Line \<int\> myline; makes a
   Line which uses ints.
   @note Watch out for underflows in the internal calcualtion of Line() if you're not
   using floats (but on the other hand try to avoid lots of floats, they're too slow!).
   If it seems like the Line() is not working, there's a good chance you need to
   scale up the numbers you're using, so internal calculations don't get truncated
   away. Use Mozzi's fixed-point number types in mozzi_fixmath.h, which enable you to
   represent fractional numbers. Google "fixed point arithmetic" if this is new to
   you.
 */


template <class T>
class Line
{
private:
volatile T current_value;  // volatile because it could be set in control interrupt and updated in audio
volatile T step_size;
const uint16_t control_rate;

public:
/** Constructor. Use the template parameter to set the type of numbers you
   want to use. For example, Line \<int\> myline; makes a Line which uses ints.
 */
Line(const uint16_t control) : control_rate(control)
{
}


/** Increments one step along the line.
   @return the next value.
 */
inline
T next()
{
								current_value += step_size;
								//Serial.println(current_value);
								return current_value;
}



/** Set the current value of the line.
   The Line will continue incrementing from this
   value using any previously calculated step size.
   @param value the number to set the Line's current_value to.
 */
inline
void set(T value)
{
								current_value=value;
}



/** Given a target value and the number of steps to take on the way, this calculates the step size needed to get there from the current value.
   @param targetvalue the value to move towards.
   @param num_steps how many steps to take to reach the target.
 */
inline
void set(T targetvalue, T seconds)
{
								T numerator;
								numerator = targetvalue-current_value;
								step_size = (T)numerator/(seconds*control_rate);


}

/** Given a new starting value, target value and the number of steps to take on the way, this sets the step size needed to get there.
   @param startvalue the number to set the Line's current_value to.
   @param targetvalue the value to move towards.
   @param num_steps how many steps to take to reach the target.
 */
inline
void set(T startvalue, T targetvalue, T num_steps)
{
								set(startvalue);
								set(targetvalue, num_steps);
}


};


// template <>
// class Line <unsigned int>
// {
// private:
// volatile unsigned int current_value;  // volatile because it could be set in control interrupt and updated in audio
// volatile int step_size;
//
// public:
// /** Constructor. Use the template parameter to set the type of numbers you
//    want to use. For example, Line \<int\> myline; makes a Line which uses ints.
//  */
// Line ()
// {
//         ;
// }
//
//
//
// /** Increments one step along the line.
//    @return the next value.
//  */
// inline
// int next()
// {
//         current_value += step_size;
//         //Serial.println(current_value);
//         return current_value;
// }
//
//
//
// /** Set the current value of the line.
//    The Line will continue incrementing from this
//    value using any previously calculated step size.
//    @param value the number to set the Line's current_value to.
//  */
// inline
// void set(int value)
// {
//         current_value=value;
// }
//
//
//
// /** Given a target value and the number of steps to take on the way, this calculates the step size needed to get there from the current value.
//    @param targetvalue the value to move towards.
//    @param num_steps how many steps to take to reach the target.
//  */
// inline
// void set(int targetvalue, int num_steps)
// {
//         int numerator;
//         numerator = targetvalue-current_value;
//         step_size = (int)numerator/num_steps;
//
//
// }
//
// /** Given a new starting value, target value and the number of steps to take on the way, this sets the step size needed to get there.
//    @param startvalue the number to set the Line's current_value to.
//    @param targetvalue the value to move towards.
//    @param num_steps how many steps to take to reach the target.
//  */
// inline
// void set(int startvalue, int targetvalue, int num_steps)
// {
//         set(startvalue);
//         set(targetvalue, num_steps);
// }
// };
#endif
