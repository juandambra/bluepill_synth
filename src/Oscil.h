#ifndef OSCIL_H_
#define OSCIL_H_
#include "main.h"


template <int NUM_TABLE_CELLS, int UPDATE_RATE>
class Oscil
{
public:
Oscil(const float32_t * TABLE_NAME) : table(TABLE_NAME)
{
}

inline
float32_t next()
{
        incrementPhase();
        return readTable();
}

inline
void setFreq(float32_t frequency)
{
        {
                phase = 0;
                phase_increment = ( NUM_TABLE_CELLS / (float32_t)UPDATE_RATE)*frequency;
        }
}

inline
void setTable(const float32_t * TABLE_NAME)
{
        table = TABLE_NAME;
}

private:

inline
void incrementPhase()
{
        phase += phase_increment;
        if (phase >= NUM_TABLE_CELLS-1)
                phase -= NUM_TABLE_CELLS-1;

}

inline
float32_t readTable()
{
        uint16_t indexBase = floor(phase);
        #if (INTERPOLATE == 1)
        q15_t indexFract = phase - indexBase;
        float32_t value1 = table[indexBase];
        float32_t value2 = table[indexBase+1];
        return value1 + ((value2 - value1) * indexFract);
        #else
        return table[indexBase];  //sin interpolacion
        #endif
}

q15_t phase;
volatile q15_t phase_increment;
const float32_t * table;
};
#endif
