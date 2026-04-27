/**
 *  @file   vector.cpp
 *  @brief  This source code contains the method definitions for all classes in vector.h
 * 
 *  This file contains the necessary function definitions of the classes written in
 *  vector.h. Mainly, this file focus on the OperatorVector, since that is the class that needs
 *  a new function definition, and is not a template.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   17/04/2026
 *  @bug    No known bugs.
 */

#include "vector.h"

void OperatorVector::update(int index)
{
    // Members of the operator class is decremented to account for an operation being
    // finished.
    for (index; index < this->size; index++)
    {
        this->elements[index].leftIndex--;
        this->elements[index].rightIndex--;
    }
}