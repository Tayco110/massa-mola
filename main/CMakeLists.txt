set(LIBRARY_SRCS
    includes/vl53l0x-arduino/VL53L0X.cpp
    includes/motor_driver/motor_driver.cpp
    includes/sensor_driver/sensor_driver.cpp
    includes/serial_driver/serial_driver.cpp
	)
set(srcs ${LIBRARY_SRCS} 
    main.cpp)
set(include_dirs
    includes/
    includes/utils
    includes/vl53l0x-arduino/
    includes/motor_driver/
    includes/sensor_driver/
    includes/serial_driver/
	)
idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS ${include_dirs}
)
