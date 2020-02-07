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
#ifndef SENSOR_NINE_AXIS_H
#define SENSOR_NINE_AXIS_H

#include "project.h"
#include "stdio.h"

#define SENSOR_ADDRESS 0x68//b110100X
#define ENABLE_FIFO 0x40 //address 0x03
#define ENABLE_WAKEUP_INT //0x
//z#define ackNack 1u

float get_x_accel();
float get_y_accel();
float get_z_accel();
float get_x_gyro();
float get_y_gryo();
float get_z_gyro();
float get_temp();
float get_x_gauss();
float get_y_gauss();
float get_z_gauss();


void set_accel_fs_sel();
void wakeup_sensor();
void enable_wakeup_interrupt();
void enable_fifo_buffer();
void select_bank(int bank);

int twos_Complement_to_int(uint8_t highByte,uint8_t lowByte);

#endif

/* [] END OF FILE */
