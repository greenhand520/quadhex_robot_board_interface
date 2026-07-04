from enum import IntEnum
from servo_robot_board_interface.msg import (
    BoardPower,
    BoardThermal,
    BoardSystem,
    BoardEvent,
    BoardConfig,
)
from servo_robot_board_interface.srv import (
    BoardQueryConfig,
    BoardQueryAllConfig,
    BoardWriteConfig,
    BoardSwitch,
)

# Topic names
TOPIC_BOARD_POWER = "/robot/board/power"
TOPIC_BOARD_THERMAL = "/robot/board/thermal"
TOPIC_BOARD_SYSTEM = "/robot/board/system"
TOPIC_BOARD_EVENT = "/robot/board/event"
TOPIC_BOARD_CONFIG = "/robot/board/config"

# Service names
SERVICE_QUERY_CONFIG = "/robot/board/query_config"
SERVICE_QUERY_ALL_CONFIG = "/robot/board/query_all_config"
SERVICE_WRITE_CONFIG = "/robot/board/write_config"
SERVICE_SWITCH = "/robot/board/switch"


class ChargePhase(IntEnum):
    UNKNOWN = 0
    NOT_CHARGING = 1
    PRE_CHARGE = 2
    CC = 3
    CV = 4
    FULL = 5
    HUSB238_FAULT = 6
    UNSUPPORTED = 7

    def __str__(self) -> str:
        return self.name

    @staticmethod
    def from_str(s: str) -> "ChargePhase":
        try:
            return ChargePhase[s.upper()]
        except KeyError:
            return ChargePhase.UNKNOWN


class ProtectionFlag(IntEnum):
    SERVO_OVERCURRENT = 1 << 0
    SERVO_THERMAL = 1 << 1
    DCDC_5V_THERMAL = 1 << 2
    CHARGE_DERATING = 1 << 3
    CHARGE_THERMAL = 1 << 4
    BATTERY_LOW = 1 << 5


class ConfigType(IntEnum):
    RESET = 0x01
    SHUTDOWN = 0x02
    SWITCH_SERVO_POWER = 0x10
    SWITCH_5V_POWER = 0x11
    SWITCH_CHARGE = 0x12
    SWITCH_BAT_EXT_OUT = 0x13
    SET_RGB = 0x14
    POWER_SERVO_CURRENT_LIMIT = 0x21
    POWER_SERVO_TEMP_LIMIT = 0x22
    POWER_5V_TEMP_LIMIT = 0x23
    CHARGE_MAX_CURRENT = 0x24
    CHARGE_TEMP_DERATING = 0x25
    CHARGE_TEMP_LIMIT = 0x26
    CHARGE_STOP_VOLTAGE = 0x27
    CHARGE_STOP_CAPACITY = 0x28


class SwitchType(IntEnum):
    SERVO_POWER = 0x10
    FIVE_V_POWER = 0x11
    CHARGE = 0x12
    BAT_EXT_OUT = 0x13
