# servo_robot_board_interface

ROS2 interface package for servo robot board communication.

**[中文版](README.md)**

## Overview

This package defines the communication interface between PC (ROS2 nodes) and STM32 board:
- **Messages (msg)**: Uplink data (STM32 → PC)
- **Services (srv)**: Downlink operations (PC → STM32)

> Protocol definition: [servo-robot-protocol](https://github.com/greenhand520/servo_robot_board_tools/tree/dev/crates/servo-robot-protocol)

## Message Types (Uplink Data)

| Message | Description | Update Rate |
|---------|-------------|-------------|
| `BoardPower` | Power data (servo/battery voltage, current) | 20Hz |
| `BoardThermal` | Temperature data (servo, 5V, MCU, charge, battery) | 5Hz |
| `BoardSystem` | System info (device ID, uptime, CPU, memory) | 1Hz |
| `BoardEvent` | Event notifications (charger, fan, protection flags) | Triggered |
| `BoardConfig` | Configuration snapshot with switch states | Event triggered |

## Service Types (Downlink Operations)

| Service | Description |
|---------|-------------|
| `BoardQueryConfig` | Query single configuration parameter |
| `BoardQueryAllConfig` | Query all configuration parameters |
| `BoardWriteConfig` | Write configuration parameter |
| `BoardSwitch` | Switch operations (servo power, 5V, charge, battery extra output) |

## Topic and Service Names

### Topics
```
/robot/board/power      # Power data
/robot/board/thermal    # Temperature data
/robot/board/system     # System information
/robot/board/event      # Event notifications
/robot/board/config     # Configuration snapshot
```

### Services
```
/robot/board/query_config       # Query single config
/robot/board/query_all_config   # Query all configs
/robot/board/write_config       # Write config
/robot/board/switch             # Switch operations
```

## C++ Usage Example

```cpp
#include "servo_robot_board_interface/ros_msg.hpp"

using namespace servo_robot_board_interface;

// Subscribe to power data
auto sub = node->create_subscription<PowerMsg>(
    TOPIC_BOARD_POWER, 10,
    [](const PowerMsg::SharedPtr msg) {
        RCLCPP_INFO(node->get_logger(), "Voltage: %.1fV", msg->servo_voltage);
    });

// Query config
auto client = node->create_client<QueryConfigSrv>(SERVICE_QUERY_CONFIG);
auto request = std::make_shared<QueryConfigSrv::Request>();
request->config_type = static_cast<uint8_t>(ConfigType::POWER_SERVO_CURRENT_LIMIT);
auto result = client->async_send_request(request);
```

## Python Usage Example

```python
from servo_robot_board_interface_msg.ros_msg import *

# Subscribe to power data
sub = node.create_subscription(
    BoardPower,
    TOPIC_BOARD_POWER,
    lambda msg: print(f"Voltage: {msg.servo_voltage:.1f}V"),
    10
)

# Query config
client = node.create_client(BoardQueryConfig, SERVICE_QUERY_CONFIG)
request = BoardQueryConfig.Request()
request.config_type = ConfigType.POWER_SERVO_CURRENT_LIMIT
future = client.call_async(request)
```

## Enum Types

### ChargePhase
| Value | Name | Description |
|-------|------|-------------|
| 0 | Unknown | Unknown |
| 1 | NotCharging | Not charging |
| 2 | PreCharge | Pre-charge |
| 3 | Cc | Constant Current |
| 4 | Cv | Constant Voltage |
| 5 | Full | Full |
| 6 | Husb238Fault | Charger chip fault |
| 7 | Unsupported | Unsupported |

### ProtectionFlag
| Bit | Name | Description |
|-----|------|-------------|
| 0 | SERVO_OVERCURRENT | Servo overcurrent |
| 1 | SERVO_THERMAL | Servo thermal |
| 2 | DCDC_5V_THERMAL | 5V thermal |
| 3 | CHARGE_DERATING | Charge derating |
| 4 | CHARGE_THERMAL | Charge thermal |
| 5 | BATTERY_LOW | Battery low |

### ConfigType
| Value | Name | Unit |
|-------|------|------|
| 0x01 | Reset | - |
| 0x02 | Shutdown | - |
| 0x10 | SwitchServoPower | bool |
| 0x11 | Switch5VPower | bool |
| 0x12 | SwitchCharge | bool |
| 0x13 | SwitchBatExtOut | bool |
| 0x21 | PowerServoCurrentLimit | A |
| 0x22 | PowerServoTempLimit | °C |
| 0x23 | Power5vTempLimit | °C |
| 0x24 | ChargeMaxCurrent | A |
| 0x25 | ChargeTempDerating | °C |
| 0x26 | ChargeTempLimit | °C |
| 0x27 | ChargeStopVoltage | V |
| 0x28 | ChargeStopCapacity | % |
| 0x29 | TxLogLevel | - |

### SwitchType
| Value | Name | Description |
|-------|------|-------------|
| 0x10 | ServoPower | Servo power |
| 0x11 | 5VPower | 5V power |
| 0x12 | Charge | Charge |
| 0x13 | BatExtOut | Battery extra output |

## Build

```bash
cd your_ros_ws
colcon build --packages-select servo_robot_board_interface
source install/setup.bash
```

## Dependencies

- `std_msgs`
- `rosidl_default_generators`
- `rosidl_default_runtime`

## License

GPL-3.0
