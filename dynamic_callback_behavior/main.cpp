#include <stdio.h>
#include <wchar.h>
#include <functional>
#include <atlbase.h>
#include <atlstr.h>

#include "CCallbackObj.h"

int __cdecl wmain(int, WCHAR**)
{
    CComPtr<CCallbackObj> obj = new CCallbackObj();
    CComPtr<ICallbackObj> pCallback;

    HRESULT hr = obj->QueryInterface(__uuidof(ICallbackObj), reinterpret_cast<void**>(&pCallback));
    if (FAILED(hr))
    {
        wprintf(L"Well crap, QI failed on CCallbackObj for an ICallbackObj\n");
        return 1;
    }

    obj->SetCallback([](){
        wprintf(L"Woooooooo\n");
    });
    pCallback->Bang();

    obj->SetCallback([](){
        wprintf(L"Lulz\n");
    });
    pCallback->Bang();

    obj->SetCallback([](){
        wprintf(L"Bongo\n");
    });
    pCallback->Bang();

    return 0;
}

