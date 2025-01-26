# Prosta gra 2D w SFML

## Opis

Jest to prosta gra 2D napisana w C++ z użyciem biblioteki SFML. Gra składa się z 5 poziomów, w których gracz, sterując postacią i patrząc z góry, musi pokonać wszystkich przeciwników.

## Sterowanie

*   **Ruch:** Klawisze strzałek lub WASD
*   **Strzelanie:** Lewy przycisk myszy

## Instalacja (Linux)

**Zakładając, że masz już wszystkie pliki gry w jednym folderze oraz zainstalowany kompilator g++:**

1. Otwórz terminal w folderze z grą.
2. Skompiluj grę:

    ```bash
    g++ *.cpp -o gra -lsfml-graphics -lsfml-window -lsfml-system
    ```

3. Uruchom grę:

    ```bash
    ./gra
    ```

    ## Struktura projektu

*   **Enemy.cpp/Enemy.h**: Klasa reprezentująca pojedynczego przeciwnika.
*   **EnemyManager.cpp/EnemyManager.h**: Zarządzanie przeciwnikami (tworzenie, usuwanie, aktualizacja stanu).
*   **Environment.cpp/Environment.h**: Klasa obsługująca elementy otoczenia
*   **Game.cpp/Game.h**: Główna klasa gry, zarządzająca logiką i pętlą gry.
*   **GameState.h**: Definicja stanów gry
*   **Menu.cpp/Menu.h**: Obsługa menu głównego gry.
*   **Player.cpp/Player.h**: Klasa reprezentująca postać gracza.
*   **Projectile.cpp/Projectile.h**: Klasa reprezentująca pociski.
*   **ProjectileManager.cpp/ProjectileManager.h**: Zarządzanie pociskami.
*   **UI.cpp/UI.h**: Elementy interfejsu użytkownika (np. wyświetlanie punktów, życia).
