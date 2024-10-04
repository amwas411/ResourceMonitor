#include "stdio.h"
#include "windows.h"
#include "locale.h"
#include "include/DateTimeHelper.h"
#include "include/adl.h"
#include "include/adl_overdrive5.h"
#include "include/adl_adapter.h"

void* __stdcall memory_alloc_function(int iSize)
{
	void* lpBuffer = malloc(iSize);
	return lpBuffer;
}

FARPROC TryLoadFunction(HMODULE hDLL, char* function)
{
	FARPROC proc = GetProcAddress(hDLL, function);
	if (proc == NULL)
	{
		printf("%s was not loaded\n", function);
		FreeLibrary(hDLL);
		exit(-1);
	}
	return proc;
}

int main(int argc, char* argv[])
{
	if (argc == 3 || argc == 4)
	{
		printf("The arguments supplied are %s %s %s.\n", argv[1], argv[2], argv[3]);
	}
	else 
	{
		printf("intervalInSeconds and workSeconds arguments must be supplied.\n");
		return -1;
	}

	int intervalInSeconds = atoi(argv[1]);
	int workSeconds = atoi(argv[2]);
	char* tag = argv[3];
	int numberofadapters = 0;
	int primaryAdapterId = 0;
	float mC_scale = 0.001;
	float volt_scale = 0.001;
	float mHz_scale = 0.01;
	int secondsPassed = 0;
	int bufSize = 100;
	LPWSTR lpLocaleName = L"en-US";

	HMODULE hDLL = LoadLibraryA("atiadlxx.dll");
	if (hDLL == NULL)
	{
		printf("Dll was not loaded.\n");
		return -1;
	}
	
	ADL_Main_Control_Destroy adl_main_control_destroy = 
		(ADL_Main_Control_Destroy)TryLoadFunction(hDLL, "ADL_Main_Control_Destroy");
	
	ADL_Main_Control_Create adl_main_control_create = 
		(ADL_Main_Control_Create)TryLoadFunction(hDLL, "ADL_Main_Control_Create");
	
	ADL_Adapter_NumberOfAdapters_Get adl_adapter_numberofadapters_get = 
		(ADL_Adapter_NumberOfAdapters_Get)TryLoadFunction(hDLL, "ADL_Adapter_NumberOfAdapters_Get");
	
	ADL_Overdrive5_Temperature_Get adl_overdrive5_temperature_get = 
		(ADL_Overdrive5_Temperature_Get)TryLoadFunction(hDLL, "ADL_Overdrive5_Temperature_Get");
	
	ADL_Adapter_Primary_Get adl_adapter_primary_get = 
		(ADL_Adapter_Primary_Get)TryLoadFunction(hDLL, "ADL_Adapter_Primary_Get");
	
	ADL_Overdrive5_CurrentActivity_Get adl_overdrive5_currentactivity_get = 
		(ADL_Overdrive5_CurrentActivity_Get)TryLoadFunction(hDLL, "ADL_Overdrive5_CurrentActivity_Get");

	ADLTemperature* tempInfo =	(ADLTemperature*)malloc(sizeof(ADLTemperature));
	LPWSTR lpDateStr =			(LPWSTR)malloc(sizeof(WCHAR) * bufSize);
	LPWSTR lpTimeStr =			(LPWSTR)malloc(sizeof(WCHAR) * bufSize);
	ADLPMActivity* lpActivity = (ADLPMActivity*)malloc(sizeof(ADLPMActivity));
	LPMEMORYSTATUSEX mem_stat = (LPMEMORYSTATUSEX)malloc(sizeof(MEMORYSTATUSEX));

	FILE* fptr = fopen("./Resmon_Log.txt", "a+");

	if (tempInfo == NULL)
	{
		printf("Not enough RAM.\n");
		goto dealloc;
	}
	if (lpDateStr == NULL)
	{
		printf("Not enough RAM\n");
		goto dealloc;
	}
	if (lpTimeStr == NULL)
	{
		printf("Not enough RAM\n");
		goto dealloc;
	}
	if (lpActivity == NULL)
	{
		printf("Not enough RAM\n");
		goto dealloc;
	}
	if (mem_stat == NULL)
	{
		printf("Not enough RAM\n");
		goto dealloc;
	}

	memset(tempInfo, 0, sizeof(ADLTemperature));
	memset(lpDateStr, 0, sizeof(WCHAR) * bufSize);
	memset(lpTimeStr, 0, sizeof(WCHAR) * bufSize);
	memset(lpActivity, 0, sizeof(ADLPMActivity));
	memset(mem_stat, 0, sizeof(MEMORYSTATUSEX));

	mem_stat->dwLength = sizeof(MEMORYSTATUSEX);
	
	if (adl_main_control_create(memory_alloc_function, 0) != ADL_OK)
	{
		printf("adl_main_control_create error");
		goto dealloc;
	}
	if (adl_adapter_numberofadapters_get(&numberofadapters) != ADL_OK)
	{
		printf("adl_adapter_numberofadapters_get error");
		goto dealloc;
	}
	if (numberofadapters < 1) {
		printf("No adapters were found.\n");
		goto dealloc;
	}
	if (adl_adapter_primary_get(&primaryAdapterId) != ADL_OK)
	{
		printf("adl_adapter_primary_get error");
		goto dealloc;
	}
	if (LoadCurrentDate(lpLocaleName, lpDateStr, bufSize) == 0)
	{
		printf("Error occured\n");
		goto dealloc;
	}

	if (tag != NULL)
	{
		fprintf(fptr, "%s\n", tag);
	}
	fwprintf(fptr, L"Date is %ls\n", lpDateStr);

	while (secondsPassed < workSeconds)
	{
		Sleep(intervalInSeconds * 1000);
		secondsPassed += intervalInSeconds;
		if (LoadCurrentTime(lpLocaleName, lpTimeStr, bufSize) == 0)
		{
			printf("Error occured\n");
			goto dealloc;
		}
		if (adl_overdrive5_currentactivity_get(primaryAdapterId, lpActivity))
		{
			printf("adl_overdrive5_currentactivity_get error");
			goto dealloc;
		}
		if (adl_overdrive5_temperature_get(primaryAdapterId, 0, tempInfo))
		{
			printf("adl_overdrive5_temperature_get error");
			goto dealloc;
		}
		if (GlobalMemoryStatusEx(mem_stat) == 0)
		{
			printf("GlobalMemoryStatusEx error\n");
			goto dealloc;
		}

		fwprintf(fptr, L"%ls : GPU: activity %d%%, temp %.0fC, clock %.0fMHz, mem clock %.0fMHz, voltage %.3fV; RAM: load %d%%\n", 
			lpTimeStr, 
			lpActivity->iActivityPercent, 
			tempInfo->iTemperature * mC_scale,
			lpActivity->iEngineClock * mHz_scale,
			lpActivity->iMemoryClock * mHz_scale,
			lpActivity->iVddc * volt_scale,
			mem_stat->dwMemoryLoad);
	}

	dealloc:
	fclose(fptr);
	free(mem_stat);
	free(tempInfo);
	free(lpTimeStr);
	free(lpDateStr);
	adl_main_control_destroy();
	FreeLibrary(hDLL);
	return 0;
}