// Aufgabe 03 Funktionen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Aufgabe 1
// Schreiben Sie eine Funktion Maximum der zwei int-Werte übergeben werden und die
// den größten der beiden Werte zurückliefert.

// Aufgabe 2
// Schreiben Sie eine Funktion Maximum der drei int-Werte übergeben werden und die
// den größten der drei Werte zurückliefert.

// Lösung 2a
// Versuchen Sie zuerst eine Lösung mit if (und else). 

// Lösung 2b
// Anschließend versuchen Sie eine Lösung nur mit Hilfe des
// Bedingungsoperators-Operators (?:).

// Aufgabe 3
// Versuchen Sie eine weitere Funktion Maximum mit drei int-Werten zu programmieren 
// in der Sie zur Lösung nur die erste Maximum-Funktion (mit 2 Argumenten) verwenden.

// Geben Sie die jeweiligen Werte für die Funktionen über die Konsole ein.

#include <iostream>
#include <sstream>

using namespace std;

int maximum(int, int);
int maximum2a(int, int, int);
int maximum2b(int, int, int);
int maximum(int, int, int);

int readConsole();

void main()
{
    locale::global(locale("German_germany"));

    int nummer1, nummer2, nummer3;

    nummer1 = readConsole();

    nummer2 = readConsole();

    cout << endl << "Das Maximum ist: " << maximum(nummer1, nummer2) << endl;

    nummer1 = readConsole();

    nummer2 = readConsole();

    nummer3 = readConsole();

    cout << endl << "2.(a) Das Maximum ist: " << maximum2a(nummer1, nummer2, nummer3) << endl;
    cout << endl << "2.(b) Das Maximum ist: " << maximum2b(nummer1, nummer2, nummer3) << endl;
    cout << endl << "3.    Das Maximum ist: " << maximum(nummer1, nummer2, nummer3) << endl;
}

int maximum(int nummer1 , int nummer2)
{
    return nummer1 > nummer2 ? nummer1 : nummer2;
}

int maximum2a(int nummer1, int nummer2, int nummer3)
{
    if (nummer1 > nummer2)
        if (nummer1 > nummer3) 
            return nummer1; 
        else 
            return nummer3;
    else
        if (nummer2 > nummer3) 
            return nummer2; 
        else 
            return nummer3;
}

int maximum2b(int nummer1, int nummer2, int nummer3)
{
    return nummer1 > nummer2 ? 
        (nummer1 > nummer3 ? nummer1 : nummer3) : (nummer2 > nummer3 ? nummer2 : nummer3);
}

int maximum(int nummer1, int nummer2, int nummer3)
{
    return maximum(maximum(nummer1, nummer2), nummer3);
}

int readConsole()
{
    int retValue = 0;

    bool eingabeOK = false;

    string eingabe;

    do
    {
        cout << "\nBitte einen ganzzahligen Wert eingeben: " << endl;

        getline(cin, eingabe);

        try
        {
            retValue = stoi(eingabe);

            eingabeOK = true;
        }
        catch (invalid_argument ex)
        {
            cerr << "Ungültige Eingabe: " << ex.what() << endl;
        }
        catch (out_of_range ex)
        {
            cerr << "Ungültige Eingabe: " << ex.what() << endl;
        }
        catch (exception ex)
        {
            cerr << "Ungültige Eingabe: " << ex.what() << endl;
        }

       

    } while (!eingabeOK);

    return retValue;
}
