#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug  1 19:35:50 2017

@author: juan
"""

import math

step = 512
pi = math.pi
steps_rad = (2 * pi / step)
def sinFunc(i):
    return (math.sin(i*steps_rad)+1)/2

def cosFunc(i):
        return (math.cos(i*steps_rad)+1)/2

def triangle(i):
    return 2*i/step
def triangleFunc(i):
    if i < step/2:
        value = triangle(i);
    else:
        value = 1 - triangle(i-step/2);
    return value

def sawFunc(i):
    value = triangle(i/2)
    return value

def squareFunc(i):
    if i > step/2:
        value = 1.0
    else:
        value = 0.0
    return value

def func_generator(steps,name,func):
    header = '''#ifndef {name}512_FLOAT_H_
#define {name}{steps}_FLOAT_H_
#include <arm_math.h>

#define {name}{steps}_NUM_CELLS {steps}
#define {name}{steps}_SAMPLERATE {steps}

const static float32_t {name}{steps}_DATA [] =
'''.format(steps=steps, name=name.upper()) + '{'
    
    footer = '''
};
#endif
'''

    f = open("{name}{steps}_float.h".format(steps=steps, name=name),"w")
    value0 = func(0)
    for line in header:
        f.write(line)
    for i in range(steps):
        if(i%5 == 0):
            f.write("\n")
            f.write("      ")
        value = func(i)
        print(value)
        f.write(str(value))
        f.write(",")
    f.write(str(value0))
    
    for line in footer:
        f.write(line)
    f.close()

func_generator(step,"sin",sinFunc)
func_generator(step,"square",squareFunc)
func_generator(step,"cos",cosFunc)
func_generator(step,"tri",triangleFunc)
func_generator(step,"saw",sawFunc)


