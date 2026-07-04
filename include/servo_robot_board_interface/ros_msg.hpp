#pragma once

#include <cstdint>
#include <string>
#include <array>
#include <algorithm>

// Message includes
#include "servo_robot_board_interface/msg/board_power.hpp"
#include "servo_robot_board_interface/msg/board_thermal.hpp"
#include "servo_robot_board_interface/msg/board_system.hpp"
#include "servo_robot_board_interface/msg/board_event.hpp"
#include "servo_robot_board_interface/msg/board_config.hpp"

// Service includes
#include "servo_robot_board_interface/srv/board_query_config.hpp"
#include "servo_robot_board_interface/srv/board_query_all_config.hpp"
#include "servo_robot_board_interface/srv/board_write_config.hpp"
#include "servo_robot_board_interface/srv/board_switch.hpp"

namespace servo_robot_board_interface {

    // Topic names
    inline const std::string TOPIC_BOARD_POWER = "/robot/board/power";
    inline const std::string TOPIC_BOARD_THERMAL = "/robot/board/thermal";
    inline const std::string TOPIC_BOARD_SYSTEM = "/robot/board/system";
    inline const std::string TOPIC_BOARD_EVENT = "/robot/board/event";
    inline const std::string TOPIC_BOARD_CONFIG = "/robot/board/config";

    // Service names
    inline const std::string SERVICE_QUERY_CONFIG = "/robot/board/query_config";
    inline const std::string SERVICE_QUERY_ALL_CONFIG = "/robot/board/query_all_config";
    inline const std::string SERVICE_WRITE_CONFIG = "/robot/board/write_config";
    inline const std::string SERVICE_SWITCH = "/robot/board/switch";

    // Type aliases
    using PowerMsg = msg::BoardPower;
    using ThermalMsg = msg::BoardThermal;
    using SystemMsg = msg::BoardSystem;
    using EventMsg = msg::BoardEvent;
    using ConfigMsg = msg::BoardConfig;

    using QueryConfigSrv = srv::BoardQueryConfig;
    using QueryAllConfigSrv = srv::BoardQueryAllConfig;
    using WriteConfigSrv = srv::BoardWriteConfig;
    using SwitchSrv = srv::BoardSwitch;

    // Charge phase enum
    enum class ChargePhase : uint8_t {
        UNKNOWN = 0,
        NOT_CHARGING = 1,
        PRE_CHARGE = 2,
        CC = 3,
        CV = 4,
        FULL = 5,
        HUSB238_FAULT = 6,
        UNSUPPORTED = 7
    };

    constexpr std::array<const char*, 8> CHARGE_PHASE_NAMES = {
        "Unknown",
        "NotCharging",
        "PreCharge",
        "Cc",
        "Cv",
        "Full",
        "Husb238Fault",
        "Unsupported"
    };

    inline const char* charge_phase_to_str(ChargePhase phase) {
        const auto index = static_cast<uint8_t>(phase);
        if (index < CHARGE_PHASE_NAMES.size()) {
            return CHARGE_PHASE_NAMES[index];
        }
        return CHARGE_PHASE_NAMES[0];
    }

    // Protection flags
    enum ProtectionFlag : uint16_t {
        SERVO_OVERCURRENT = 1 << 0,
        SERVO_THERMAL     = 1 << 1,
        DCDC_5V_THERMAL   = 1 << 2,
        CHARGE_DERATING   = 1 << 3,
        CHARGE_THERMAL    = 1 << 4,
        BATTERY_LOW       = 1 << 5,
    };

    // Config type enum
    enum class ConfigType : uint8_t {
        RESET = 0x01,
        SHUTDOWN = 0x02,
        SWITCH_SERVO_POWER = 0x10,
        SWITCH_5V_POWER = 0x11,
        SWITCH_CHARGE = 0x12,
        SWITCH_BAT_EXT_OUT = 0x13,
        SET_RGB = 0x14,
        POWER_SERVO_CURRENT_LIMIT = 0x21,
        POWER_SERVO_TEMP_LIMIT = 0x22,
        POWER_5V_TEMP_LIMIT = 0x23,
        CHARGE_MAX_CURRENT = 0x24,
        CHARGE_TEMP_DERATING = 0x25,
        CHARGE_TEMP_LIMIT = 0x26,
        CHARGE_STOP_VOLTAGE = 0x27,
        CHARGE_STOP_CAPACITY = 0x28,
    };

    // Switch type enum
    enum class SwitchType : uint8_t {
        SERVO_POWER = 0x10,
        FIVE_V_POWER = 0x11,
        CHARGE = 0x12,
        BAT_EXT_OUT = 0x13,
    };

}
