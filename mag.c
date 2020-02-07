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

#include "mag.h"
//#include "math.h"
#include "sensor_nine_axis.h"

float mag(float* old_x, float* old_y, float* old_z, float* new_x, float* new_y, float* new_z){

    float dxx = *new_x - *old_x;
    float dxy = *new_y - *old_y;
    float dxz = *new_z - *old_z;
    
    *old_x = *new_x;
    *old_y = *new_y;
    *old_z = *new_z;
    
    float magn = dxx*dxx + dxy*dxy + dxz*dxz;
    
    return(magn);
    
}



/* [] END OF FILE */
