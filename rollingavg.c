/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "math.h"
#include "stdio_user.h"
#include "rollingavg.h"

void rollingavg(float* avg, float m, int* n){
    float sum = (*avg)*((float)*n);
    *n ++;
    *avg = (sum + m)/((float)* n);
}
/* [] END OF FILE */
