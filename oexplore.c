#include <windows.h>
#include <exdisp.h>
#include <shellapi.h>

int start()
{
    CoInitialize(NULL);
    IWebBrowser2* pWebBrowser2 = NULL;
    HRESULT hr = CoCreateInstance(
        &CLSID_InternetExplorer,
        NULL,
        CLSCTX_LOCAL_SERVER,
        &IID_IWebBrowser2,
        (void**)&pWebBrowser2);
    if (SUCCEEDED(hr))
    {
        hr = pWebBrowser2->lpVtbl->put_Visible(
            pWebBrowser2, VARIANT_TRUE);
        if (SUCCEEDED(hr))
        {
            LPCWSTR commandLine = GetCommandLineW();
            int args = 0;
            LPWSTR* argv = CommandLineToArgvW(commandLine, &args);
            BSTR url = SysAllocString(
                args >= 2 ? argv[1] : L"http://www.bing.com/");
            LocalFree(argv);

            hr = pWebBrowser2->lpVtbl->Navigate(
                pWebBrowser2, url, NULL, NULL, NULL, NULL);
            if (FAILED(hr))
            {
                MessageBoxW(
                    NULL,
                    L"Couldn't navigate.",
                    L"Outernet Explorer",
                    MB_OK | MB_ICONEXCLAMATION);
            }
            SysFreeString(url);
        }
        else
        {
            MessageBoxW(
                NULL,
                L"Couldn't show Internet Explorer component.",
                L"Outernet Explorer",
                MB_OK | MB_ICONEXCLAMATION);
        }
        pWebBrowser2->lpVtbl->Release(pWebBrowser2);
    }
    else
    {
        MessageBoxW(
            NULL,
            L"Couldn't instantiate Internet Explorer component.",
            L"Outernet Explorer",
            MB_OK | MB_ICONEXCLAMATION);
    }
    CoUninitialize();
    ExitProcess(hr);
}
