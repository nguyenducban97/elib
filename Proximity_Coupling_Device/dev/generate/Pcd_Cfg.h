#ifndef PCD_CFG_H
#define PCD_CFG_H

#include "Pcd_Type.h"
#include "spi.h"
#include "gpio.h"

#define SPI_CHANNEL hspi1
#define SPI_IRQ_HANDLER SPI1_IRQn
#define EXTI_PIN
#define EXTI_IRQ_HANDLER EXTI4_IRQn

const Pcd_Type Pcd_Config = {
    0x00U,
    0x00U,
    FALSE,
    0x70U
};

#endif /* PCD_CFG_H */