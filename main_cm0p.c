
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
#include "project.h"
#include "stdio.h"
#include "stdio_user.h"
#include "sensor_nine_axis.h"
#include "mag.h"
#include "rollingavg.h"
#include "decision.h"
#include "stdlib.h"
#include "time.h"

float* avg;
int* n;

//bool ahhhhhhhhh = true; //change back to no assign 

cy_stc_ble_conn_handle_t connDeviceHandle;

/* BLE stack event handler defines how stack controller responds to BLE events */
void BleEventHandler(uint32 event, void *eventParam){
    cy_stc_ble_gatts_write_cmd_req_param_t* writeReqParam;
    
    switch(event)
    {
        /* Event generated when Cy_BLE_Start() is called */
        case CY_BLE_EVT_STACK_ON:
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
        break;
        
        /* Event generated when device is disconnected */
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
            /* Remove the device from the connection handle array */
            memset(&connDeviceHandle, CY_BLE_INVALID_CONN_HANDLE_VALUE, sizeof(cy_stc_ble_conn_handle_t));
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
        break;
            
        /* Event generated when PSoC receives write with response request */
        case CY_BLE_EVT_GATTS_WRITE_REQ:
            
            
            writeReqParam = (cy_stc_ble_gatts_write_cmd_req_param_t *) eventParam;
            uint8 received_byte = *(writeReqParam->handleValPair.value.val);
            
//            switch(received_byte)
//            {
//                case 0: // 0 - all
//                    ahhhhhhhhh = true; 
//                break;
//                
//                case 1: // 1 - odd
//                    ahhhhhhhhh = false;
//                break;
//            }
            Cy_BLE_GATTS_WriteRsp(writeReqParam->connHandle);
        break;
        
        /* Event generated at GAP Peripheral after a connection is completed */
        case CY_BLE_EVT_GATT_CONNECT_IND:
            /* Store the connection handle of the connected device */
            connDeviceHandle = *(cy_stc_ble_conn_handle_t *) eventParam;
        break;
    }
}
/* Packages byte and sends notification to connected device  */
void sendNotification(uint8 data){
    cy_stc_ble_gatt_handle_value_pair_t serviceHandle;
    cy_stc_ble_gatt_value_t notificationValue = { .val = &data, .len = sizeof(uint8)};
    serviceHandle.attrHandle = CY_BLE_DEVICE_INTERFACE_OUTBOUND_CHAR_HANDLE;
    serviceHandle.value = notificationValue;
    
    cy_en_ble_api_result_t result = Cy_BLE_GATTS_SendNotification(&connDeviceHandle, &serviceHandle);
    if(result != CY_BLE_SUCCESS){
        /* Failed to send notification */
    }
}

/* BLE middleware triggers this callback when the BLE Stack controller needs to process pending stack events */
void BlessISRHandler(void){
    Cy_BLE_ProcessEvents(); //process pending stack events
}


void interrupt_handler(){
    uint8 d = decision(*avg);
    
}

int main(void)
{
    cy_en_scb_i2c_status_t status;
    /* Buffer to write to the slave */
    uint8_t buffer[5U];
    /* Wait 100 ms until operation completion */
    uint32_t timeout = 100UL;
    __enable_irq(); /* Enable global interrupts. */
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR);
        srand(time(0));
    __enable_irq();
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 
    
    I2C_1_Start();
    cy_en_scb_i2c_command_t ackNack = 1u;
        
    UART_1_Start();
    setvbuf(stdin,NULL,_IONBF,0);

    __enable_irq(); /* Enable global interrupts. */
 
    /* Enable the BLE component */
    Cy_BLE_Start(BleEventHandler);
    while(Cy_BLE_GetState() != CY_BLE_STATE_ON)
    {
        Cy_BLE_ProcessEvents();
    }
    
    /* Register handler to process pending BLE stack events */
    Cy_BLE_RegisterAppHostCallback(BlessISRHandler);
    
    float old_xv; 
    float old_yv;
    float old_zv;
    float new_xv;
    float new_yv;
    float new_zv;
    
    wakeup_sensor();
    
    old_xv = 0.0;
    old_yv = 0.0;
    old_zv = 0.0;
    new_xv = 0.0;
    new_yv = 0.0;
    new_zv = 0.0;
    
    for(;;)
    {             
        CyDelay(100);
        float m = mag(&old_xv, &old_yv, &old_zv, &new_xv, &new_yv, &new_zv);
        uint8 d = decision(m);
        sendNotification(d);
        CyDelay(750);  // waits 0.5 seconds before updating value
        sendNotification(0);
        CyDelay(200);
        //printf("hello bihhh\r\n");
        new_xv = get_x_accel();
        new_yv = get_y_accel();
        new_zv = get_z_accel();
        printf("XACCEL: %10f\tYACCELL: %10f\tZACCEL: %10f\r\n",new_xv,new_yv,new_zv); 
        CyDelay(10);
        printf("MAGNITUDE: %10f\r\n", m);
        //printf("MAGNITUDE: %10f\r\n", 11111.0);
        CyDelay(100);
        enable_wakeup_interrupt();
    }
}
