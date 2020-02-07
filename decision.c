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
#include "stdio.h"
#include "project.h"
#include "decision.h"

uint8_t decision(float val){
    float dyskinesiathresh = 1000.0f;
    float tremormin = 500.0f;
    float tremormax = 1000.0f;
    float bradykinesiathresh = 500.0f;
    if(val>dyskinesiathresh){
        return 1;
    }
    if(val>tremormin && val< tremormax){
        return 2;
    }
    if(val<bradykinesiathresh){
        return 3;
    }
    return 0;
}
/* [] END OF FILE */
