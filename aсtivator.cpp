#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
void main2(string commands) {
    commands;
    // Преобразуем narrow string в wide string
    wstring wcommands(commands.begin(), commands.end());

    // Получаем handle к процессу cmd.exe с правами администратора
    HANDLE hToken;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, &hToken))
    {
        TOKEN_ELEVATION elevation;
        DWORD dwSize = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(hToken, TokenElevation, &elevation, dwSize, &dwSize))
        {
            if (elevation.TokenIsElevated)
            {
                // Выполняем команды с правами администратора
                ShellExecute(NULL, L"runas", L"cmd.exe", wcommands.c_str(), NULL, SW_SHOW);
            }
            else
            {
                cout << "Не удалось получить права администратора." << endl;
            }
        }
        else
        {
            cout << "Не удалось получить информацию о токене." << endl;
        }
        CloseHandle(hToken);
    }
    else
    {
        cout << "Не удалось открыть токен процесса." << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "\t\t\thttps://github.com/VLOD-ZDOV/\n";
    cout << "\t\t\tПрограмма Активации Виндовс  \n";
    cout << "\t\t\t-----------------------------\n";
    char what_windows;
    cout << "What activation:" << endl;
    cout << "1) Windows 11/10 pro" << endl;
    cout << "2) Windows 11/10 Workstation (Рабочие станции)" << endl;
    cout << "3) Windows 11/10 Ltsc (Корпоративная)" << endl;

    cin >> what_windows;
    if (what_windows == 1) {
        // Создаем строку с командами
        string commands = "cmd /k \"slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX  & slmgr /skms kms.digiboy.ir & slmgr /ato\"";
        main2(commands);
    };
    if (what_windows == 2) {
        // Создаем строку с командами
        string commands = "cmd /k \"slmgr /ipk NRG8B-VKK3Q-CXVCJ-9G2XF-6Q84J  & slmgr /skms kms.digiboy.ir & slmgr /ato\"";
        main2(commands);
    }
    if (what_windows == 3) {
        // Создаем строку с командами
        string commands = "cmd /k \"slmgr /ipk NPPR9-FWDCX-D2C8J-H872K-2YT43  & slmgr /skms kms.digiboy.ir & slmgr /ato\"";
        main2(commands);
    }
}