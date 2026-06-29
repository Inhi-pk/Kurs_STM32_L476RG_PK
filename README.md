# Kurs STM32 L476RG PK

Repozytorium zawiera zestaw projektów przygotowanych dla płytki **NUCLEO-L476RG** z mikrokontrolerem **STM32L476RG**. Projekty zostały wykonane w języku **C** w środowisku **STM32CubeIDE** z wykorzystaniem biblioteki **HAL**. Ćwiczenia są oparte na kursie **Forbot STM32L4**, głównie na częściach od **#2 do #17**.

Celem repozytorium jest zebranie kolejnych przykładów pokazujących praktyczną obsługę podstawowych i bardziej zaawansowanych peryferiów STM32: GPIO, UART, zegarów, RTC, watchdog, trybów oszczędzania energii, przerwań, timerów, PWM, enkodera, ADC, SPI, I2C, wyświetlacza TFT, pamięci EEPROM, czujników, diod WS2812B, pilota IR w standardzie NEC oraz magistrali 1-Wire.

## Spis treści

* [Opis projektu](#opis-projektu)
* [Wykorzystany sprzęt](#wykorzystany-sprzęt)
* [Wykorzystane środowisko](#wykorzystane-środowisko)
* [Zakres zrealizowanych ćwiczeń](#zakres-zrealizowanych-ćwiczeń)
* [Struktura repozytorium](#struktura-repozytorium)
* [Jak uruchomić projekt](#jak-uruchomić-projekt)
* [Najważniejsze zagadnienia](#najważniejsze-zagadnienia)
* [Uwagi](#uwagi)
* [Autor](#autor)
* [Źródła](#źródła)

## Opis projektu

Każdy katalog w repozytorium jest osobnym projektem STM32CubeIDE. Projekty pokazują stopniowe przejście od pierwszego uruchomienia płytki i prostego sterowania pinami do obsługi komunikacji szeregowej, czujników, pamięci zewnętrznych oraz modułów wymagających dokładnego sterowania czasowego.

Repozytorium może służyć jako:

* zbiór przykładów do nauki programowania STM32,
* dokumentacja wykonanych ćwiczeń z kursu STM32L4,
* baza do dalszego rozwijania własnych projektów embedded,
* materiał pomocniczy do praktyk, zajęć laboratoryjnych lub sprawozdania.

## Wykorzystany sprzęt

Podstawowa platforma sprzętowa:

* płytka **NUCLEO-L476RG**,
* mikrokontroler **STM32L476RG**,
* przewód USB do programowania i komunikacji UART przez ST-LINK,
* elementy elektroniczne używane w kursie Forbot STM32L4, między innymi:

  * diody LED i rezystory,
  * przyciski,
  * joystick analogowy,
  * enkoder,
  * ekspander portów SPI,
  * kolorowy wyświetlacz TFT SPI,
  * zewnętrzna pamięć EEPROM I2C,
  * czujnik ciśnienia i wysokości LPS25HB,
  * czujnik odległości HC-SR04,
  * wyświetlacze 7-segmentowe,
  * wzmacniacz operacyjny,
  * diody RGB WS2812B,
  * odbiornik podczerwieni i pilot IR NEC,
  * czujniki temperatury DS18B20.

## Wykorzystane środowisko

Do pracy z projektami potrzebne są:

* **STM32CubeIDE**,
* biblioteka **STM32 HAL**,
* kompilator **arm-none-eabi-gcc** dostarczany razem ze STM32CubeIDE,
* sterowniki ST-LINK,
* terminal UART, np. wbudowany terminal STM32CubeIDE, PuTTY, Tera Term lub inny monitor portu szeregowego.

Większość projektów zawiera typową strukturę wygenerowaną przez STM32CubeIDE:

```text
Core/
  Inc/
  Src/
  Startup/
Drivers/
*.ioc
.project
.cproject
STM32L476RGTX_FLASH.ld
STM32L476RGTX_RAM.ld
```

W niektórych projektach znajdują się również dodatkowe katalogi bibliotek, np. `hagl` dla obsługi grafiki.

## Zakres zrealizowanych ćwiczeń

| Część   | Katalog / projekt                                       | Tematyka                                                                                  |
| ------- | ------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| #2      | `część_02_pierwsze_uruchomienie`                        | Pierwsze uruchomienie płytki, konfiguracja środowiska, podstawowy projekt w STM32CubeIDE. |
| #3      | `część_03_konfigurowanie_pinu_jako_wejscie`             | Konfiguracja GPIO jako wejścia, obsługa przycisku i odczyt stanu pinu.                    |
| #3      | `część_03_linijka_LED`                                  | Sterowanie kilkoma diodami LED i praca z wieloma wyjściami GPIO.                          |
| #3      | `część_03_nauka_przypisywania_pinów`                    | Ćwiczenie przypisywania pinów oraz konfiguracji portów mikrokontrolera.                   |
| #3      | `część_03_podłączenie_zewnętrznej_diody`                | Podłączenie i sterowanie zewnętrzną diodą LED.                                            |
| #4      | `część_04_uart_pierwszy_projekt`                        | Pierwszy projekt z UART, wysyłanie danych przez port szeregowy.                           |
| #4      | `część_04_printf`                                       | Przekierowanie `printf()` na UART i wygodne debugowanie programu.                         |
| #4      | `część_04_odbieranie_wiadomości`                        | Odbiór danych z UART oraz reakcja programu na odebrane znaki.                             |
| #4      | `część_04_timeout_i_blokowanie_programu`                | Zagadnienie blokowania programu, timeoutów i wpływu funkcji HAL na działanie kodu.        |
| #5      | `część_05_komfiguracja_zegarów`                         | Konfiguracja taktowania mikrokontrolera, źródła zegara, RTC i watchdog.                   |
| #6      | `część_06_oszczędzanie_energii`                         | Tryby oszczędzania energii i ograniczanie poboru prądu.                                   |
| #7      | `część_07_przerwania`                                   | Przerwania sprzętowe, obsługa zdarzeń i reagowanie bez ciągłego sprawdzania stanu wejść.  |
| #7      | `część_07_przerwania_zliczanie`                         | Zliczanie zdarzeń z użyciem przerwań.                                                     |
| #8      | `część_08_liczniki`                                     | Podstawowa obsługa timerów sprzętowych.                                                   |
| #8      | `część_08_dioda_LED`                                    | Sterowanie diodą LED z wykorzystaniem timera.                                             |
| #8      | `część_08_licznik_diody`                                | Licznik sterujący zachowaniem diod LED.                                                   |
| #8      | `część_08_enkoder`                                      | Obsługa enkodera z użyciem liczników STM32.                                               |
| #9      | `część_09_przetworniki`                                 | Wprowadzenie do przetworników analogowo-cyfrowych.                                        |
| #9      | `część_09_przetworniki_analogowo_cyfrowe`               | Konfiguracja ADC i odczyt wartości analogowych.                                           |
| #9      | `część_09_pomiar_napięcia_zewnętrznego`                 | Pomiar napięcia zewnętrznego za pomocą ADC.                                               |
| #9      | `część_09_joystick`                                     | Odczyt położenia joysticka analogowego.                                                   |
| #10     | `część_10_Sterowanie_diodą_za_pomocą_ekspandera`        | Sterowanie wyjściami przez ekspander portów SPI.                                          |
| #10     | `część_10_Obsługa_przycisku_za_pomocą_ekspandera`       | Odczyt przycisku przez ekspander portów.                                                  |
| #10     | `część_10_Wydzielanie_kodu_do_własnej_biblioteki`       | Porządkowanie kodu i tworzenie własnej biblioteki.                                        |
| #11     | `część_11_Konfiguracja_projektu_z_wyświetlaczem`        | Konfiguracja projektu z kolorowym wyświetlaczem TFT.                                      |
| #11     | `część_11_Włączanie_pojedynczych_pikseli`               | Rysowanie pojedynczych pikseli na ekranie.                                                |
| #11     | `część_11_Rysowanie_prostokątów`                        | Rysowanie prostych figur graficznych.                                                     |
| #11     | `część_11_Wyświetlanie _obrazów`                        | Wyświetlanie obrazów na ekranie TFT.                                                      |
| #11     | `część_11_Wykorzystanie_gotowej_biblioteki_graficznej`  | Użycie biblioteki graficznej HAGL do obsługi wyświetlacza.                                |
| #11/#12 | `część_11_Zapis_do_pamięci_EEPROM`                      | Próby zapisu danych do zewnętrznej pamięci EEPROM.                                        |
| #12     | `część_12_Zapis_do_pamięci_EEPROM`                      | Obsługa zewnętrznej pamięci EEPROM przez I2C.                                             |
| #12     | `część_12_Licznik_uruchomień_układu`                    | Zapis trwałych danych w EEPROM, np. licznik uruchomień układu.                            |
| #13     | `część_13_Komunikacja_z_czujnikiem_LPS25HB`             | Komunikacja z czujnikiem LPS25HB przez I2C.                                               |
| #13     | `część_13_Odczyt_temperatury_z_czujnika_LPS25HB`        | Odczyt temperatury z czujnika LPS25HB.                                                    |
| #13     | `część_13_Pomiar_ciśnienia_za_pomocą_czujnika_LPS25HB`  | Pomiar ciśnienia atmosferycznego.                                                         |
| #13     | `część_13_Pomiar_ciśnienia_względnego`                  | Pomiar ciśnienia względnego.                                                              |
| #13     | `część_13_Pomiar_wysokości_bezwzględnej`                | Wyznaczanie wysokości bezwzględnej na podstawie ciśnienia.                                |
| #13     | `część_13_Pomiar_wysokości_względnej`                   | Wyznaczanie względnej zmiany wysokości.                                                   |
| #13     | `część_13_BIblioteka_dla_czujnika_LPS25HB`              | Wydzielenie obsługi czujnika LPS25HB do biblioteki.                                       |
| #14     | `część_14_Obsługa_czujnika_HC-SR04_za_pomocą_liczników` | Pomiar odległości czujnikiem ultradźwiękowym z użyciem timerów.                           |
| #14     | `część_14_Sprzętowy_pomiar_obu_zboczy_sygnału`          | Pomiar czasu impulsu przez sprzętową detekcję zboczy.                                     |
| #14     | `część_14_Obsługa_wyświetlaczy_7-segmentowych`          | Obsługa wyświetlaczy 7-segmentowych.                                                      |
| #14     | `część_14_Wyświetlanie_pomiarów_na_wyświetlaczu`        | Prezentacja wyników pomiarów na wyświetlaczu.                                             |
| #14     | `część_14_Wzmacniacz_operacyjny`                        | Praca z układem analogowym i pomiarem sygnału po wzmocnieniu.                             |
| #15     | `część_15_Podłączenie_diod_WS2812B_do_STM32L4`          | Sterowanie adresowalnymi diodami RGB WS2812B z użyciem timerów.                           |
| #16     | `część_16_Dekodowanie_NEC_za_pomocą_STM32L4`            | Dekodowanie sygnału z pilota IR w standardzie NEC.                                        |
| #16     | `część_16_Biblioteka_do_dekodowania_NEC`                | Utworzenie biblioteki do dekodowania ramek NEC.                                           |
| #16     | `część_16_Lampka_RGB – WS2812B_sterowane_pilotem`       | Projekt lampki RGB sterowanej pilotem IR.                                                 |
| #17     | `część_17_Implementacja _1-wire_przez_UART`             | Implementacja magistrali 1-Wire z wykorzystaniem UART.                                    |
| #17     | `część_17_Komunikacja_STM32L4_z_DS18B20`                | Komunikacja z termometrem DS18B20.                                                        |
| #17     | `część_17_Odczyt_z_wielu_DS18B20`                       | Odczyt temperatury z wielu czujników DS18B20.                                             |

## Struktura repozytorium

Repozytorium zostało uporządkowane według numerów części kursu. Każdy katalog odpowiada osobnemu ćwiczeniu lub wariantowi ćwiczenia.

Przykład:

```text
Kurs_STM32_L476RG_PK/
├── część_02_pierwsze_uruchomienie/
├── część_03_konfigurowanie_pinu_jako_wejscie/
├── część_04_uart_pierwszy_projekt/
├── część_08_enkoder/
├── część_11_Wykorzystanie_gotowej_biblioteki_graficznej/
├── część_12_Zapis_do_pamięci_EEPROM/
├── część_13_BIblioteka_dla_czujnika_LPS25HB/
├── część_16_Lampka_RGB – WS2812B_sterowane_pilotem/
└── część_17_Odczyt_z_wielu_DS18B20/
```

Typowy projekt zawiera:

* `Core/Inc` – pliki nagłówkowe aplikacji,
* `Core/Src` – pliki źródłowe aplikacji, w tym `main.c`,
* `Drivers` – biblioteki HAL/CMSIS,
* `*.ioc` – konfigurację projektu STM32CubeMX/STM32CubeIDE,
* pliki `.project` i `.cproject` – konfigurację projektu Eclipse/STM32CubeIDE,
* skrypty linkera `STM32L476RGTX_FLASH.ld` oraz `STM32L476RGTX_RAM.ld`.

## Jak uruchomić projekt

1. Pobierz repozytorium:

```bash
git clone <adres-repozytorium>
```

2. Otwórz **STM32CubeIDE**.

3. Wybierz:

```text
File -> Import -> Existing Projects into Workspace
```

4. Wskaż folder wybranego projektu, np.:

```text
część_04_uart_pierwszy_projekt
```

5. Zatwierdź import projektu.

6. Podłącz płytkę **NUCLEO-L476RG** do komputera przez USB.

7. Skompiluj projekt:

```text
Project -> Build Project
```

8. Wgraj program na płytkę:

```text
Run -> Debug
```

albo użyj przycisku **Debug/Run** w STM32CubeIDE.

9. W projektach korzystających z UART otwórz terminal portu szeregowego. Typowe parametry to:

```text
Baud rate: 115200
Data bits: 8
Parity: None
Stop bits: 1
Flow control: None
```

Parametry transmisji mogą się różnić zależnie od konkretnego projektu, dlatego w razie problemów najlepiej sprawdzić konfigurację UART w pliku `.ioc`.

## Najważniejsze zagadnienia

W repozytorium przećwiczono między innymi:

* konfigurację pinów GPIO jako wejścia i wyjścia,
* obsługę przycisków oraz diod LED,
* komunikację UART i wykorzystanie `printf()` do debugowania,
* problem funkcji blokujących i timeoutów,
* konfigurację zegarów mikrokontrolera,
* RTC oraz watchdog,
* tryby oszczędzania energii,
* przerwania zewnętrzne,
* liczniki sprzętowe, PWM oraz obsługę enkodera,
* pomiary analogowe z użyciem ADC,
* komunikację SPI z ekspanderem portów i wyświetlaczem,
* komunikację I2C z pamięcią EEPROM oraz czujnikiem LPS25HB,
* obsługę kolorowego wyświetlacza TFT,
* tworzenie prostych bibliotek w C,
* obsługę czujnika odległości HC-SR04,
* sterowanie wyświetlaczami 7-segmentowymi,
* obsługę diod WS2812B,
* dekodowanie sygnałów IR w standardzie NEC,
* implementację magistrali 1-Wire,
* odczyt temperatury z czujników DS18B20.

## Uwagi

* Projekty są przygotowane jako osobne przykłady edukacyjne, dlatego część kodu może się powtarzać między katalogami.
* Niektóre katalogi mogą zawierać pliki wygenerowane automatycznie przez STM32CubeIDE.
* W przypadku problemów z kompilacją warto sprawdzić ścieżki do bibliotek, zgodność wersji STM32CubeIDE oraz konfigurację projektu w pliku `.ioc`.
* W projektach wykorzystujących zewnętrzne moduły należy zwrócić uwagę na poprawne podłączenie zasilania, masy oraz linii komunikacyjnych.
* Projekty były przygotowywane w celach edukacyjnych i mogą wymagać dostosowania przed użyciem w większej aplikacji.

## Autor

**Paweł Kopczyński**

Projekt wykonany w ramach praktyki zawodowej w **Sieć Badawcza Łukasiewicz – Instytut Technologii Eksploatacji**.

## Źródła

* Kurs STM32L4 – Forbot
* Repozytorium GitHub – Kurs_STM32_L476RG_PK
* Dokumentacja STM32CubeIDE / STM32 HAL dostępna w środowisku STM32CubeIDE
