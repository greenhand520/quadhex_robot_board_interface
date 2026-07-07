# Board Event
# Event and protection status

bool   charger_connected   # Is charger connected
bool   fan_enabled         # Is fan enabled
uint8  charge_phase        # Charge phase (0=Unknown, 1=NotCharging, 2=PreCharge, 3=Cc, 4=Cv, 5=Full, 6=Husb238Fault, 7=Unsupported)
uint16 protection_flags    # Protection flags bitmask (bit0=ServoOvercurrent, bit1=ServoThermal, bit2=Dcdc5vThermal, bit3=ChargeDerating, bit4=ChargeThermal, bit5=BatteryLow)
uint16 error_flags		   # Error flags bitmask (bit0=UNKNOWN_ERROR, bit1=UART1_ERROR, bit2=UART2_ERROR, bit3=I2C1_ERROR, bit4=I2C3_ERROR, bit5=SPI1_ERROR, bit6=USB_ERROR, bit7=DMA_ERROR)
