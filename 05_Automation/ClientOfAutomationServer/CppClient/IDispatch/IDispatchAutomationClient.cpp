#include <Windows.h>
#include "AutomationServerWithRegFile.h"	// given and writtten by server

//Global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global variable declaration
IDispatch* gpIDispatch = NULL;


//Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("ComClient");
	HRESULT hr;

	//code
	// COM initialization
	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM library can not be initialized.\n Program will now exit."), TEXT("Program Error"), MB_OK);
		exit(0);
	}

	//STEP 1: Initialize WNDCLASSEX structure
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//STEP 2: Register class
	RegisterClassEx(&wndclass);

	//create the window in memory
	hwnd = CreateWindow(
		szAppName,
		TEXT("GAP : My First Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	//Show window
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//STEP 3: Draw Heart of the application
	//Message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// COM Un-initialization
	CoUninitialize();
	return (int)msg.wParam;
}


// Window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// function declarations
	void SafeInterfaceRelease(void);

	// variable declarations
	HRESULT hr;
	int iNum1, iNum2;
	TCHAR str[255];
	DISPID dispid;
	OLECHAR* szFunction1 = L"SumOfTwoIntegers";
	OLECHAR* szFunction2 = L"SubtractionOfTwoIntegers";
	VARIANT vArg[2], vRet;
	DISPPARAMS params;

	//code
	switch (iMsg) {
	case WM_CREATE:
		MessageBox(hwnd, NULL, TEXT("1!"), MB_OK);

		hr = CoCreateInstance(CLSID_MyMath, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&gpIDispatch);
		MessageBox(hwnd, NULL, TEXT("2!"), MB_OK);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("IDispatch interface cannot be obtained."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// Proper Automation Client's Code starts here :)

		iNum1 = 155;
		iNum2 = 145;

		// VARIANT
		VariantInit(vArg);
		vArg[0].vt = VT_INT;
		vArg[0].intVal = iNum2;

		vArg[1].vt = VT_INT;
		vArg[1].intVal = iNum1;

		// DISPPARAMS
		params.rgvarg = vArg;
		params.cArgs = 2;
		params.rgdispidNamedArgs = NULL;
		params.cNamedArgs = 0;

		// VARIANT
		VariantInit(&vRet);
		MessageBox(hwnd, NULL, TEXT("3!"), MB_OK);
		hr = gpIDispatch->GetIDsOfNames(IID_NULL, &szFunction1, 1, GetUserDefaultLCID(), &dispid);
		MessageBox(hwnd, NULL, TEXT("4!"), MB_OK);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("GetIDsOfNames failed."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		hr = gpIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &params, &vRet, NULL, NULL);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("Invoke failed."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		wsprintf(str, TEXT("Sum of %d and %d is %d"), iNum1, iNum2, vRet.lVal);
		MessageBox(hwnd, str, TEXT("Sum"), MB_OK);

		// SubtractionOfTwoIntegers block
		hr = gpIDispatch->GetIDsOfNames(IID_NULL, &szFunction2, 1, GetUserDefaultLCID(), &dispid);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("GetIDsOfNames SubtractionOfTwoIntegers failed."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		hr = gpIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &params, &vRet, NULL, NULL);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("Invoke SubtractionOfTwoIntegers failed."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		wsprintf(str, TEXT("Subtraction of %d and %d is %d"), iNum1, iNum2, vRet.lVal);
		MessageBox(hwnd, str, TEXT("Subtraction"), MB_OK);

		// release gpIDispatch
		if (gpIDispatch)
		{
			gpIDispatch->Release();
			gpIDispatch = NULL;
		}

		// exit the application
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		MessageBox(hwnd, NULL, TEXT("5!"), MB_OK);
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void SafeInterfaceRelease(void)
{
	// code
	if (gpIDispatch)
	{
		gpIDispatch->Release();
		gpIDispatch = NULL;
	}
}
