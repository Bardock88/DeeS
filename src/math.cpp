/*
    Copyright 2019-2020 Hydr8gon

    This file is part of NooDS.

    NooDS is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NooDS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with NooDS. If not, see <https://www.gnu.org/licenses/>.
*/

#include <cmath>

#include "math.h"
#include "defines.h"

void Math::divide()
{
    // Set the division by zero error bit
    // The bit only gets set if the full 64-bit denominator is zero, even in 32-bit mode
    if (divDenom == 0) divCnt |= BIT(14); else divCnt &= ~BIT(14);

    // Calculate the division result and remainder
    switch (divCnt & 0x0003) // Division mode
    {
        case 0: // 32-bit / 32-bit
            if ((int32_t)divDenom != 0)
            {
                divResult    = (int32_t)divNumer / (int32_t)divDenom;
                divRemResult = (int32_t)divNumer % (int32_t)divDenom;
            }
            break;

        case 1: case 3: // 64-bit / 32-bit
            if ((int32_t)divDenom != 0)
            {
                divResult    = divNumer / (int32_t)divDenom;
                divRemResult = divNumer % (int32_t)divDenom;
            }
            break;

        case 2: // 64-bit / 64-bit
            if (divDenom != 0)
            {
                divResult    = divNumer / divDenom;
                divRemResult = divNumer % divDenom;
            }
            break;
    }
}

void Math::squareRoot()
{
    // Calculate the square root result
    switch (sqrtCnt & 0x0001) // Square root mode
    {
        case 0: // 32-bit
            sqrtResult = sqrt((uint32_t)sqrtParam);
            break;

        case 1: // 64-bit
            sqrtResult = sqrt(sqrtParam);
            break;
    }
}

void Math::writeDivCnt(uint16_t mask, uint16_t value)
{
    // Write to the DIVCNT register
    mask &= 0x0003;
    divCnt = (divCnt & ~mask) | (value & mask);

    divide();
}

void Math::writeDivNumerL(uint32_t mask, uint32_t value)
{
    // Write to the DIVNUMER register
    divNumer = (divNumer & ~((uint64_t)mask)) | (value & mask);

    divide();
}

void Math::writeDivNumerH(uint32_t mask, uint32_t value)
{
    // Write to the DIVNUMER register
    divNumer = (divNumer & ~((uint64_t)mask << 32)) | ((uint64_t)(value & mask) << 32);

    divide();
}

void Math::writeDivDenomL(uint32_t mask, uint32_t value)
{
    // Write to the DIVDENOM register
    divDenom = (divDenom & ~((uint64_t)mask)) | (value & mask);

    divide();
}

void Math::writeDivDenomH(uint32_t mask, uint32_t value)
{
    // Write to the DIVDENOM register
    divDenom = (divDenom & ~((uint64_t)mask << 32)) | ((uint64_t)(value & mask) << 32);

    divide();
}

void Math::writeSqrtCnt(uint16_t mask, uint16_t value)
{
    // Write to the SQRTCNT register
    mask &= 0x0001;
    sqrtCnt = (sqrtCnt & ~mask) | (value & mask);

    squareRoot();
}

void Math::writeSqrtParamL(uint32_t mask, uint32_t value)
{
    // Write to the DIVDENOM register
    sqrtParam = (sqrtParam & ~((uint64_t)mask)) | (value & mask);

    squareRoot();
}

void Math::writeSqrtParamH(uint32_t mask, uint32_t value)
{
    // Write to the SQRTPARAM register
    sqrtParam = (sqrtParam & ~((uint64_t)mask << 32)) | ((uint64_t)(value & mask) << 32);

    squareRoot();
}
