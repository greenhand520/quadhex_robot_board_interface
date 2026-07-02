from enum import IntEnum


TOPIC_BOARD_STATE = "/robot/board/state"

TOPIC_BOARD_CONFIG = "/robot/board/config"

SRV_COMPUTE_HAND_EYE_TRANSFORM = "/robot/board/modify_config"


class ChargeStatus(IntEnum):
    UNKNOWN = 0
    NOT_CHARGED = 1
    PRE_CHARGE = 2
    CC = 3
    CV = 4
    FULL = 5
    HUSB238A_FAULT = 6
    CHARGER_UNSUPPORTED = 7

    def __str__(self) -> str:
        return self.name

    @staticmethod
    def from_str(s: str) -> "ChargeStatus":
        try:
            return ChargeStatus[s.upper()]
        except KeyError:
            return ChargeStatus.UNKNOWN
