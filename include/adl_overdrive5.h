#ifndef OVERDRIVE5_H_
#define OVERDRIVE5_H_

#include "adl_structures.h"

typedef int (*ADL2_Overdrive5_CurrentActivity_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPMActivity* lpActivity);
typedef int (*ADL_Overdrive5_CurrentActivity_Get)(int iAdapterIndex, ADLPMActivity* lpActivity);
typedef int (*ADL2_Overdrive5_ThermalDevices_Enum)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iThermalControllerIndex, ADLThermalControllerInfo* lpThermalControllerInfo);
typedef int (*ADL_Overdrive5_ThermalDevices_Enum)(int iAdapterIndex, int iThermalControllerIndex, ADLThermalControllerInfo* lpThermalControllerInfo);
typedef int (*ADL2_Overdrive5_Temperature_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iThermalControllerIndex, ADLTemperature* lpTemperature);
typedef int (*ADL_Overdrive5_Temperature_Get)(int iAdapterIndex, int iThermalControllerIndex, ADLTemperature* lpTemperature);
typedef int (*ADL2_Overdrive5_FanSpeedInfo_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedInfo* lpFanSpeedInfo);
typedef int (*ADL_Overdrive5_FanSpeedInfo_Get)(int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedInfo* lpFanSpeedInfo);
typedef int (*ADL2_Overdrive5_FanSpeed_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue* lpFanSpeedValue);
typedef int (*ADL_Overdrive5_FanSpeed_Get)(int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue* lpFanSpeedValue);
typedef int (*ADL2_Overdrive5_FanSpeed_Set)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue* lpFanSpeedValue);
typedef int (*ADL_Overdrive5_FanSpeed_Set)(int iAdapterIndex, int iThermalControllerIndex, ADLFanSpeedValue* lpFanSpeedValue);
typedef int (*ADL2_Overdrive5_FanSpeedToDefault_Set)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iThermalControllerIndex);
typedef int (*ADL_Overdrive5_FanSpeedToDefault_Set)(int iAdapterIndex, int iThermalControllerIndex);
typedef int (*ADL2_Overdrive5_ODParameters_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODParameters* lpOdParameters);
typedef int (*ADL_Overdrive5_ODParameters_Get)(int iAdapterIndex, ADLODParameters* lpOdParameters);
typedef int (*ADL2_Overdrive5_ODPerformanceLevels_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iDefault, ADLODPerformanceLevels* lpOdPerformanceLevels);
typedef int (*ADL_Overdrive5_ODPerformanceLevels_Get)(int iAdapterIndex, int iDefault, ADLODPerformanceLevels* lpOdPerformanceLevels);
typedef int (*ADL2_Overdrive5_ODPerformanceLevels_Set)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLODPerformanceLevels* lpOdPerformanceLevels);
typedef int (*ADL_Overdrive5_ODPerformanceLevels_Set)(int iAdapterIndex, ADLODPerformanceLevels* lpOdPerformanceLevels);
typedef int (*ADL2_Overdrive5_PowerControl_Caps)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpSupported);
typedef int (*ADL_Overdrive5_PowerControl_Caps)(int iAdapterIndex, int* lpSupported);
typedef int (*ADL2_Overdrive5_PowerControlInfo_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, ADLPowerControlInfo* lpPowerControlInfo);
typedef int (*ADL_Overdrive5_PowerControlInfo_Get)(int iAdapterIndex, ADLPowerControlInfo* lpPowerControlInfo);
typedef int (*ADL2_Overdrive5_PowerControl_Get)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* lpCurrentValue, int* lpDefaultValue);
typedef int (*ADL_Overdrive5_PowerControl_Get)(int iAdapterIndex, int* lpCurrentValue, int* lpDefaultValue);
typedef int (*ADL2_Overdrive5_PowerControl_Set)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int iValue);
typedef int (*ADL_Overdrive5_PowerControl_Set)(int iAdapterIndex, int iValue);
typedef int (*ADL2_Overdrive_Caps)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int* iSupported, int* iEnabled, int* iVersion);
typedef int (*ADL_Overdrive_Caps)(int iAdapterIndex, int* iSupported, int* iEnabled, int* iVersion);

#endif /* OVERDRIVE5_H_ */