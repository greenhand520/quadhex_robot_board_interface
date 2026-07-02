#pragma once

#include <cstdint>
#include <string>
#include <array>
#include <algorithm>

#include "servo_robot_board_interface/msg/config.hpp"
#include "servo_robot_board_interface/msg/state.hpp"
#include "servo_robot_board_interface/msg/charge_state.hpp"
#include "servo_robot_board_interface/srv/modify_config.hpp"

namespace servo_robot_board_interface {

  
    inline const std::string TOPIC_BOARD_STATE = "/robot/board/state";
    
    inline const std::string TOPIC_BOARD_CONFIG = "/robot/board/config";
    
    inline const std::string SRV_COMPUTE_HAND_EYE_TRANSFORM = "/robot/board/modify_config";
    
    
    using Config = servo_robot_board_interface::msg::Config;
    using State = servo_robot_board_interface::msg::State;
    using ChargeState = servo_robot_board_interface::msg::ChargeState;
    using ModifyConfig = servo_robot_board_interface::srv::ModifyConfig;
    


	enum class ChargeStatus : uint8_t {
		UNKNOWN = 0,
		NOT_CHARGED = 1,
		PRE_CHARGE = 2,
		CC = 3,
		CV = 4,
		FULL = 5,
		HUSB238A_FAULT = 6,
		CHARGER_UNSUPPORTED = 7
	};

	constexpr std::array<const char*, 8> CHARGE_STATUS_NAMES = {
		"UNKNOWN",
		"NOT_CHARGED",
		"PRE_CHARGE",
		"CC",
		"CV",
		"FULL",
		"HUSB238A_FAULT",
		"CHARGER_UNSUPPORTED"
	};
	

	inline const char* charge_status_to_str(ChargeStatus status) {
		const auto index = static_cast<uint8_t>(status);
		if (index < CHARGE_STATUS_NAMES.size()) {
		    return CHARGE_STATUS_NAMES[index];
		}
		return CHARGE_STATUS_NAMES[0];
	}
	

	inline ChargeStatus str_to_charge_status(const std::string& str) {
		auto it = std::find_if(CHARGE_STATUS_NAMES.begin(), CHARGE_STATUS_NAMES.end(),
		    [&str](const char* name) { return str == name; });
		if (it != CHARGE_STATUS_NAMES.end()) {
		    return static_cast<ChargeStatus>(std::distance(CHARGE_STATUS_NAMES.begin(), it));
		}
		return ChargeStatus::UNKNOWN;
	}

}
