import math
import csv

# Funkcje dla algorytmów
def A1(n):
    return 1000 * math.log(n, 2)

def A2(n):
    return 100 * n

def A3(n):
    return 10 * n * math.log(n, 2)

def A4(n):
    return n ** 2

def A5(n):
    return n ** 3

def A6(n):
    return 2 ** n

# Lista rozmiarów danych
sizes = [1, 5, 10, 25, 50, 100, 102, 103, 110, 200, 250, 500, 1000]

# Liczba operacji na sekundę
operations_per_second = 1500170

# Obliczanie czasów dla każdego algorytmu i rozmiaru danych
results = []

for n in sizes:
    times = [
        A1(n) / operations_per_second,
        A2(n) / operations_per_second,
        A3(n) / operations_per_second,
        A4(n) / operations_per_second,
        A5(n) / operations_per_second,
        A6(n) / operations_per_second
    ]
    results.append([n] + times)

# Zapisywanie wyników do pliku CSV
with open('algorithm_times.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["n", "A1", "A2", "A3", "A4", "A5", "A6"])
    writer.writerows(results)

print("Wyniki zapisano do pliku 'algorithm_times.csv'.")
