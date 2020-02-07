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

#include "sensor_nine_axis.h"

/*Name of I2C block in top diagram must be I2C_1*/
float get_x_accel(){
  uint8_t highByte;
  uint8_t lowByte;
  float x_accel;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x2D,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x2E,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);

  /*combine 2 bytes into 1*/
  int x_accel_prescale = twos_Complement_to_int(highByte,lowByte);

  /*Get Scale factor*/
  //Hard code to 00 -> 2g
  float scaleFactor = 16384.0;

  /*Divde by scalar, multiply by 9.8 to get m/s^2*/
  x_accel = (x_accel_prescale/scaleFactor)*9.8;
  
  return x_accel;
}
float get_y_accel(){
  uint8_t highByte;
  uint8_t lowByte;
  float y_accel;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x2F,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x30,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);

  /*combine 2 bytes into 1*/
  int y_accel_prescale = twos_Complement_to_int(highByte,lowByte);

  /*Get Scale factor*/
  //Hard code to 00 -> 2g
  float scaleFactor = 16384.0;

  /*Divde by scalar, multiply by 9.8 to get m/s^2*/
  y_accel = (y_accel_prescale/scaleFactor)*9.8;
  
  return y_accel;
}
float get_z_accel(){
  uint8_t highByte;
  uint8_t lowByte;
  float z_accel;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x31,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x32,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);

  /*combine 2 bytes into 1*/
  int z_accel_prescale = twos_Complement_to_int(highByte,lowByte);

  /*Get Scale factor*/
  //Hard code to 00 -> 2g
  float scaleFactor = 16384.0;

  /*Divde by scalar, multiply by 9.8 to get m/s^2*/
  z_accel = (z_accel_prescale/scaleFactor)*9.8;
  
  return z_accel;
}

float get_x_gyro(){
  uint8_t highByte;
  uint8_t lowByte;
  float x_gyro;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x33,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x34,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);  

  /*combine 2 bytes into 1*/
  int x_gyro_prescale = twos_Complement_to_int(highByte,lowByte);

  /*Get Scale factor*/
  //Hard code to 00 -> 131.0
  float scaleFactor = 131.0;

  /*Divde by scalar*/
  x_gyro = (x_gyro_prescale/scaleFactor);
  
  return x_gyro;
    
}

float get_y_gryo(){
  uint8_t highByte;
  uint8_t lowByte;
  float y_gyro;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x35,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x36,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);

  /*combine 2 bytes into 1*/
  int y_gyro_prescale = twos_Complement_to_int(highByte,lowByte);

  /*Get Scale factor*/
  //Hard code to 00 -> 131.0
  float scaleFactor = 131.0;

  /*Divde by scalar*/
  y_gyro = (y_gyro_prescale/scaleFactor);
  
  return y_gyro;
}
float get_z_gyro(){
  uint8_t highByte;
  uint8_t lowByte;
  float z_gyro;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x37,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x38,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);
   
  /*combine 2 bytes into 1*/
  int z_gyro_prescale = twos_Complement_to_int(highByte,lowByte);

  /*Get Scale factor*/
  //Hard code to 00 -> 131.0
  float scaleFactor = 131.0;

  /*Divde by scalar*/
  z_gyro = (z_gyro_prescale/scaleFactor);
  
  return z_gyro;
}

float get_temp(){
  uint8_t highByte;
  uint8_t lowByte;
  float temp;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  /*Read Register 0x2D, store in tempHigh*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x39,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  /*Read Register 0x2E, store in tempLow*/
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x4A,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);    
   
  //TEMP_degC = ((TEMP_OUT – RoomTemp_Offset)/Temp_Sensitivity) + 21degC
  temp = (twos_Complement_to_int(highByte,lowByte)/333.87) + 21;
  
  return temp;
}

void set_accel_fs_sel();

void wakeup_sensor(){
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x06,30);
  I2C_1_MasterWriteByte(0x01,100);
  I2C_1_MasterSendStop(100);
}

float get_x_gauss(){
  uint8_t highByte;
  uint8_t lowByte;
  float x_gauss;
  cy_en_scb_i2c_command_t ackNack = 1u;
    
  select_bank(1);  
  CyDelay(10);
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x11,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&highByte,100);
  I2C_1_MasterSendStop(100);

  
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x12,30);
  I2C_1_MasterSendReStart(0x68,CY_SCB_I2C_READ_XFER,100);
  I2C_1_MasterReadByte(ackNack,&lowByte,100);
  I2C_1_MasterSendStop(100);    
  
  select_bank(0);
  
  x_gauss = (twos_Complement_to_int(lowByte,highByte));
  return x_gauss;
    
}
float get_y_gauss(){
   return 0.0;   
}

float get_z_gauss(){
   return 0.0;   
}

void enable_wakeup_interrupt(){
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x10,30);
  I2C_1_MasterWriteByte(0x08,100);
  I2C_1_MasterSendStop(100);   
}
void enable_fifo_buffer();
void select_bank(int bank){
    uint8_t value = 0x00;
    switch(bank){
        case 0: 
            value = 0x00;
            break;
        case 1:
            value = 0x10;
            break;
        case 2:
            value = 0x20;
            break;
        
        case 3:
            value = 0x30;
            break;
        
    }
  I2C_1_MasterSendStart(0x68,CY_SCB_I2C_WRITE_XFER,100);
  I2C_1_MasterWriteByte(0x7F,30);
  I2C_1_MasterWriteByte(value,100);
  I2C_1_MasterSendStop(100);   
}

int twos_Complement_to_int(uint8_t highByte,uint8_t lowByte){
    int smallInt = (highByte <<8 ) | lowByte;
    const int negative = (smallInt & (1 << 15)) != 0;
    int nativeInt;

    if (negative)
        nativeInt = smallInt | ~((1 << 16) - 1);
    else
        nativeInt = smallInt;   
        
    return nativeInt;
}


/* [] END OF FILE */