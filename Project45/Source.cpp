#include<stdio.h>
#include<conio.h>
#include<tccore/custom.h>
#include<tccore/method.h>

//TC_customization_libraries - preference- DLLs

#define DLLAPI _declspec(dllexport)

int iStatus = ITK_ok;
//Fnction Declaration

extern "C" {

	extern DLLAPI int Dll_Project_register_callbacks();
	extern DLLAPI int PLM_execute_callbacks1(int *decision, va_list argv);
	extern DLLAPI int PLM_execute_callbacks2(int *decision, va_list argv);

	//Function Definition
	extern DLLAPI int Dll_Project_register_callbacks()
	{
		iStatus = CUSTOM_register_exit("Dll_Project", "USER_init_module", (CUSTOM_EXIT_ftn_t)PLM_execute_callbacks1);
		iStatus = CUSTOM_register_exit("Dll_Project", "USER_exit_module", (CUSTOM_EXIT_ftn_t)PLM_execute_callbacks2);
		return iStatus;
	}
	extern DLLAPI int PLM_execute_callbacks1(int *decision, va_list argv)
	{
		*decision = ALL_CUSTOMIZATIONS;
		printf("\n------------------DLL REGISTRATION-------------\n");
		printf("\n-----LOGIN SUCCESS---------\n");

		return iStatus;
	}

	extern DLLAPI int PLM_execute_callbacks2(int *decision, va_list argv)
	{
		*decision = ALL_CUSTOMIZATIONS;
		printf("\n-----LOGOUT SUCCESS---------\n");
		return iStatus;
	}
}

