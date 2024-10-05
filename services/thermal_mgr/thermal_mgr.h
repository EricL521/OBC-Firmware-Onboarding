#pragma once

#include "lm75bd.h"
#include "errors.h"

typedef enum {
  THERMAL_MGR_EVENT_MEASURE_TEMP_CMD,
  THERMAL_MGR_EVENT_CHECK_SAFE_TEMP_CMD,
  
} thermal_mgr_event_type_t;

typedef struct {
  thermal_mgr_event_type_t type;
} thermal_mgr_event_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes thermal manager
 * 
 * @param config Configuration options for thermal manager
 */
void initThermalSystemManager(lm75bd_config_t *config);

/**
 * @brief adds an event to the thermal manager queue
 * 
 * @param event the event to add
 */
error_code_t thermalMgrSendEvent(thermal_mgr_event_t *event);
/**
 * @brief Adds an event to the beginning of the thermal manager queue
 * 
 * @param event the event to add
 */
error_code_t thermalMgrSendEventToFront(thermal_mgr_event_t *event);

/**
 * @brief Test function that logs temperature to console
 * 
 * @param tempC Temperature to print
 */
void addTemperatureTelemetry(float tempC);

/**
 * @brief Test function that logs that we are over safe operating temperature
 */
void overTemperatureDetected(void);

/**
 * @brief Test function that logs that we are in safe operating temperature
 */
void safeOperatingConditions(void);

#ifdef __cplusplus
}
#endif
