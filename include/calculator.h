/**
 *  @file   operator.ino
 *  @brief  This source code contains the 'Operator' class that will keep track of the operator precedence of the
 *          calculator.
 * 
 *  This source code will contain the necessary attributes and methods to keep track of the correct order to solve
 *  the operations.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   19/04/2026
 *  @bug    No known bugs.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "vector.h"

enum class StatusCode : uint8_t
{
    ONGOING,
    SYNTAX_ERROR,
    MATH_ERROR,
    STACK_ERROR,
    SAFE_TERMINATION
};

class Calculator
{
    private:
        TokenVector tokens;
        int currWholePart = 0;
        float currFractionPart= 0.0;
        float decimalMultiplier = 0.1;
        bool isTypingDecimal = false;
        StatusCode status = StatusCode::ONGOING;
        uint8_t minusCtr = 0;

    private:
        void loadDigit(char digit);
        void executeOperation(int operationIndex);
        void storeNumber();

    public:
        bool isFinished();
        void input(char key);
        float output();
        void reset();
};

#endif