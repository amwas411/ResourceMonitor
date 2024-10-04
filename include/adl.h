#ifndef ADL_H_
#define ADL_H_

#include "adl_sdk.h"

typedef int   (*ADL_Main_ControlX2_Create)(ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADLThreadingModel threadingModel);
typedef int   (*ADL2_Main_ControlX2_Create)(ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADL_CONTEXT_HANDLE* context, ADLThreadingModel threadingModel);
typedef int   (*ADL2_Main_ControlX3_Create)(ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADL_CONTEXT_HANDLE* context, ADLThreadingModel threadingModel, int adlCreateOptions);
typedef int   (*ADL_Main_Control_Create)(ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters);
typedef int   (*ADL2_Main_Control_Create)(ADL_MAIN_MALLOC_CALLBACK callback, int iEnumConnectedAdapters, ADL_CONTEXT_HANDLE* context);
typedef int   (*ADL2_Main_Control_Refresh)(ADL_CONTEXT_HANDLE context);
typedef int   (*ADL_Main_Control_Refresh)();
typedef int   (*ADL_Main_Control_Destroy)();
typedef int   (*ADL2_Main_Control_Destroy)(ADL_CONTEXT_HANDLE context);
typedef void* (*ADL2_Main_Control_GetProcAddress)(ADL_CONTEXT_HANDLE context, void* lpModule, char* lpProcName);
typedef void* (*ADL_Main_Control_GetProcAddress)(void* lpModule, char* lpProcName);
typedef int	  (*ADL2_RegisterEvent)(ADL_CONTEXT_HANDLE context, int eventID, void* evntHandle);
typedef int	  (*ADL2_UnRegisterEvent)(ADL_CONTEXT_HANDLE context, int eventID, void* evntHandle);
typedef int	  (*ADL2_RegisterEventX2)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);
typedef int	  (*ADL2_UnRegisterEventX2)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);
typedef int	  (*ADL2_PerGPU_GDEvent_Register)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);
typedef int	  (*ADL2_PerGPU_GDEvent_UnRegister)(ADL_CONTEXT_HANDLE context, int iAdapterIndex, int clientID, int eventID, void* evntHandle);

#endif /* ADL_H_ */