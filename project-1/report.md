# Implementacja tablicy dynamicznej w C++
**Autor:** *Zachariasz Jażdżewski*

# Spełnione wymagania podstawowe
**1. Dynamiczna tablica**
- Spełnione w pliku: `dynamicarray.cpp`
- Implementacja dynamicznej tablicy znajduje się w klasie `AiSD::DynamicArray<T>` (linia `6`).
- Konstruktor `DynamicArray(size_t capacity)` dynamicznie alokuje pamięć dla tablicy o podanej pojemności (linia `13`)
- Tablica przechowuje elementy typu `T`, zawiera pola prywatne `capacity` i `size` reprezentujące jej rozmiar fizyczny i logiczny kolejno (linia `7`)

**2. Operacje na tablicy**
Spełnione w metodach klasy `DynamicArray<T>`:
- `IsEmpty()` - zwraca `true` jeżeli tablica jest pusta, `false` w przeciwnym przypadku (linia `21`)
- `IsFull()` - zwraca `true` jeżeli tablica jest pełna, `false` w przeciwnym przypadku (linia `25`)
- `Space()` - zwraca ilość wolnego miejsca w tablicy (linia `29`)
- Przeciążony `operator []` – daje dostęp do elementów tablicy na podstawie indeksu `i` tak jak wbudowany operator `[]` (linia `33`)
- `PushBack(T t)` – wstawia element `t` na koniec tablicy  (linia `41`)
- `PopBack()` – usuwa ostatni element tablicy (linia `45`)
- `PushFront(T t)` – wstawia element `t` na początek tablicy, przesuwając pozostałe elementy (linia `51`)
- `PopFront()` – usuwa pierwszy element, przesuwając pozostałe (linia `59`)
- `Insert(T t, size_t i)` – wstawia element `t` na indeks `i` (linia `66`)
- `Erase(size_t i)` – usuwa element na indeksie `i` (linia `74`)

**3. Metoda wyświetlająca zawartość tablicy `Print()` (linia `81`)**

**4. Metoda `SaveToFile(const std::string& filename)` zapisująca zawartość tablicy do pliku (linia `89`)**

# Testowanie
Kod testujący znajduje się w tym samym pliku co implementacja tablicy, w funkcji `main()`.

Demonstracja spełnionych wymagań:
- Tworzenie dynamicznej tablicy
- Dodawanie i usuwanie elementów (`PushBack()`, `PopBack()`, `PushFront()`, `PopFront()`, `Insert()`, `Erase()`)
- Sprawdzanie stanu tablicy (`IsEmpty()`, `IsFull()`)
- Wyświetlanie zawartości tablicy i wolnego miejsca (`Print()`, `Space()`)
- Zapis do pliku (`SaveToFile()`). Program tworzy plik `output.txt`

# Sposób uruchomienia
1. **Kompilacja**
	```
	g++ dynamicarray.cpp -o dynamicarray
	```
2. **Uruchomienie**
	```
	./dynamicarray
	```

Wynik działania pojawi się w terminalu oraz zostanie zapisany w pliku `output.txt`.
