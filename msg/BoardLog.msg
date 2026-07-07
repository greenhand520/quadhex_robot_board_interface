# Board log message
# Log levels
# uint8 LEVEL_OFF = 0
# uint8 LEVEL_DEBUG   = 1
# uint8 LEVEL_INFO    = 2
# uint8 LEVEL_WARN    = 3
# uint8 LEVEL_ERROR   = 4

# Log level
uint8 level

# Source file name (null-terminated in protocol)
string file_name

# Source function name (null-terminated in protocol)
string fun_name

# Log message content
string msg

