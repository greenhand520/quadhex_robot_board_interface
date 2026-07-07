# Board Configuration Snapshot
# Current board configuration values

float32 servo_current_limit    # Servo current limit (A)
float32 servo_temp_limit       # Servo temperature limit (°C)
float32 temp_5v_limit          # 5V temperature limit (°C)
float32 charge_max_current     # Charge max current (A)
float32 charge_temp_derating   # Charge temp derating (°C)
float32 charge_temp_limit      # Charge temp limit (°C)
float32 charge_stop_voltage    # Charge stop voltage (V)
float32 charge_stop_percentage # Charge stop percentage (0.0-1.0)
bool    charge_enable          # Charge enable
bool    servo_power_on         # Servo power state
bool    power_5v_on            # 5V power state
bool    charge_on              # Charge state
bool    bat_ext_out_on         # Battery extra output state
bool    reset                  # reset
bool    shutdown               # shutdown
uint8   tx_log_level           # The log level sent by mcu to the host computer（0: OFF 1:DEBUG 2:INFO 3:WARN 4:ERROR）
