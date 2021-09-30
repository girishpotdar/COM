#include <Windows.h>
#include <process.h>
#include "HeaderForClientOfContainmentComponentWithRegFile.h"	// given and writtten by server

//Global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global variable declaration
ISum* gpISum;
ISubtract* gpISubtract = NULL;
IMultiplication* gpIMultiplication = NULL;
IDivision* gpIDivision = NULL;


//Entry point function - WinMain
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
	int iNum1, iNum2, iSum, iSub, iMultiplication, iDivision;
	TCHAR str[255];

	//code
	switch (iMsg) {
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void**)&gpISum);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISum interface cannot be obtained."), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// initialize arguments hardcoded
		iNum1 = 65;
		iNum2 = 45;

		// call SumOfTwoIntegers() of ISum to get the sum
		gpISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);

		// display the result
		wsprintf(str, TEXT("Sum of %d and %d = %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		// call QueryInterface() on ISum, to get ISubtract's pointer
		hr = gpISum->QueryInterface(IID_ISubtract, (void**)&gpISubtract);

		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISubtract Interface can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// as ISum is now not needed onwards, release it
		gpISum->Release();
		gpISum = NULL; //make released interface NULL
		//again initialize arguments hardcoded
		iNum1 = 155;
		iNum2 = 55;

		// again call SumOfTwoIntegers() of ISum to get the new sum
		gpISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSub);

		// display the result
		wsprintf(str, TEXT("Subtraction of %d and %d = %d"), iNum1, iNum2, iSub);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		// call QueryInterface() on gpISubtract, to get IMultiplication's pointer
		hr = gpISubtract->QueryInterface(IID_IMultiplication, (void**)&gpIMultiplication);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("IMultiplication Interface can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// as ISubtract is now not needed onwards, release it
		gpISubtract->Release();
		gpISubtract = NULL;	//make released interface NULL

		iNum1 = 30;
		iNum2 = 25;

		// call MultiplicationOfTwoIntegers() of IMultiplication to get the Multiplication
		gpIMultiplication->MultiplicationOfTwoIntegers(iNum1, iNum2, &iMultiplication);

		// display the result
		wsprintf(str, TEXT("Multiplication of %d and %d = %d"), iNum1, iNum2, iMultiplication);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);


		// call QueryInterface() on gpIMultiplication, to get IDivision's pointer
		hr = gpIMultiplication->QueryInterface(IID_IDivision, (void**)&gpIDivision);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("IDivision Interface can not be obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}

		// as IMultiplication is now not needed onwards, release it
		gpIMultiplication->Release();
		gpIMultiplication = NULL;	//make released interface NULL

		iNum1 = 200;
		iNum2 = 25;

		// call DivisionOfTwoIntegers() of IDivision to get the Division
		gpIDivision->DivisionOfTwoIntegers(iNum1, iNum2, &iDivision);

		// display the result
		wsprintf(str, TEXT("Division of %d and %d = %d"), iNum1, iNum2, iDivision);
		MessageBox(hwnd, str, TEXT("Result"), MB_OK);

		// as IDivision is now not needed onwards, release it
		gpIDivision->Release();
		gpIDivision = NULL;	//make released interface NULL

		// exit the application
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		SafeInterfaceRelease();
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
	if (gpISum)
	{
		gpISum->Release();
		gpISum = NULL;
	}
	if (gpISubtract)
	{
		gpISubtract->Release();
		gpISubtract = NULL;
	}
	if (gpIMultiplication)
	{
		gpIMultiplication->Release();
		gpIMultiplication = NULL;
	}
	if (gpIDivision)
	{
		gpIDivision->Release();
		gpIDivision = NULL;
	}
}
