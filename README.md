# Magnates & Heroes

## Autorzy
Team 25/25:
- Zuzanna Damszel
- Ireneusz Okniński
- Paweł Rogóż
- Daniel Tomala

## Opis projektu / rozwiązywanego problemu
W ramach projektu tworzymy grę strategiczną Magnates & Wizards dla dwóch graczy. Rozgrywka polega na wyborze czterech postaci (z ośmiu dostępnych), które w następnej fazie będą ze sobą rywalizować. Wszystkie postaci różnią się między sobą, reprezentują wiele ciekawych umiejętności i sposobów ataku przeciwnika. Wraz z wyborem konkretnej postaci gracz dostaje możliwość wyboru pomiędzy szerokim zasięgiem ataku, zadawaniem większych obrażeń lub opcją zbalansowaną, co urozmaica rozgrywkę i daje graczom pole do przeprowadzenia ciekawszej bitwy. Gra kończy się wraz z pokonaniem wszystkich postaci przeciwnika.

W realizacji naszego projektu korzystamy z języka C++ oraz biblioteki SFML.

## Struktura repozytorium
W repozytorium **22L_PROI_PROJ_ZD_IO_PR_DT** znajdują się foldery *headers*, *src*, *tests*, *textures* oraz plik *main.cpp*. 

### Opis funkcji folderów:

#### headers:
Zawiera pliki nagłówkowe z rozszerzeniem *.hpp* używane w logice gry, jej rozgrywce i interfejsie graficznym. Umieszczonio w niej również plik *const.hpp* zawierający stałe używane w programie.

##### Podfoldery i pliki:

- ***game_logic***

    - ***heroes*** zawiera plik *hero.hpp*, w którym zadeklarowana jest klasa **Hero** oraz wszystkie dziedzicząse po niej klasy postaci: **Archer**, **Knight**, **Mage**, **IceDruid**, **Medic**, **Ninja**, **Catapult**, **Trebuchet** oraz plik *hero_attributes.hpp* zawierający atrybuty każdej postaci w trzech wariantach: damage, balanced, range.

    - ***weapons*** zawiera plik *weapon.hpp* z klasą bazową **Weapon** oraz pliki zawierające dziedziczące po niej klasy broni: **Bow**, **GroundDruidStaff**, **IceDruidStaff**, **MageWand**, **MedicalBox**,**Shuriken**, **Stone**, **Sword**.

    - *field.hpp* zawiera klasę **Field** reprezentującą pojedyncze pole na planszy

    - *board.hpp* zawiera klasę **Board** reprezentującą planszę, na której ma miejsce rozgrywka.

- ***gameplay***

    - *game.hpp* zawiera klasę **Game** będącą najwyższą warstwą programu, łączącą GUI z logiką gry

    - *game_controller.hpp* zawiera klasę **GameController** odpowiadającą za prowadzenie rozgrywki

- ***ui***

    - ***states*** - widoki w grze

    - *action_menu_buttons.hpp* - menu wyboru akcji postaci

    - *button.hpp* - przycisk interfejsu graficznego

    - *descriptions* - opisy postaci

    - *graphic_settings.hpp* - ustawienia graficzne okna gry

    - *HPbar.hpp* - pasek życia bohatera

    - *select_button.hpp* - przycisk wyboru postaci 

    - *loads.hpp* - dostępne ataki bohatera

#### source
Zawiera pliki źródłowe z rozszerzeniem *.cpp* zawierające implementację funkcji zadeklarowanych w plikach nagłówkowych.

##### Podfoldery i pliki:

- ***game_logic***

- ***gameplay***

- ***ui***

#### tests
Zawiera testy jednostkowe ogólnego działania gry

#### textures
Zawiera tekstury użwane w interfejsie graficznym

##### Podfoldery i pliki:

- ***backgrounds*** - tekstury tła 

- tekstury bohaterów

- tekstury przycisków

## Struktura programu
Aby umożliwić łatwe rozwijanie naszego projektu podzieliliśmy go na trzy główne pola:

- **Logika gry** - klasy reprezentujące najbardziej podstawowe części naszego programu. Od tej części rozpoczęliśmy jego tworzenie.

    - **Hero** - klasa Hero reprezentuje bohatera, czyli postać biorącą udział w rozgrywce. Jest ona niezbędna w kontekście logiki gry (atak, leczenie itp.)
        
        - **Knight** - rycerz jest najbardziej "zwykłym" rodzajem postaci. Może atakować jedynie sąsiadujące pola. Nie posiada umiejętności specjalnych.

        - **Archer** - łucznik posiada duży zasięg ataku, ale małe obrażenia i ilość życia. Nie posiada specjalnych umiejętności.

        - **Mage** - mag zadaje duże obrażenia wybranemu przeciwnikowi oraz mniejsze wszystkim z jego drużyny.

        - **IceDruid** - druid lodu zadaje obrażenia oraz zamraża przeciwnika. Zamrożona postać nie może sie poruszać oraz zadawać obrażen.

        - **Medic** - medyk zadaje niewielkie obrażenia, ale posiada umiejętność leczenia wybranej postaci ze swojej drużyny.

        - **Ninja** - postać mająca duży zakres ruchu, oraz mogąca wykonać 3 ataki w jednej turze.

        - **Catapult** - nie może się poruszać, zadaje duże obrażenia na obszarze jednego pola.

        - **Trebuchet** - podobnie jak katapulta, nie może się poruszać. Zadaje obrażenia przez 2 rundy na kilku sąsiadujących polach(również graczom swojej drużyny).

    - **Field** - reprezentuje pole na planszy. Została ona stworzona w celu uproszczenia logiki przeprowadzania działań podczas rozgrywki (np. ataku na danego zawodnika). Zawiera ona informacje o tym, czy znajduje się na nim Hero, umożliwia dodanie i usunięcie go z konkretnego pola

    - **Board** - reprezentuje całą planszę, umożliwia jej utworzenie i dostęp do informacji o konkretnym polu

    - **Weapon** - reprezentuje broń, którą może posiadać tylko konkretny typ Hero. Urozmaica ona rozgrywkę poprzez różnorodność atrybutów, które wnosi ze sobą dana broń.

    - **Wearable** - klasa nieużywana, miała reprezentować specjalne przedmioty, które mogą posiadać postaci.
    
    - **BubbleBooster** - klasa nieużywana, miała reprezentować bonus możliwy do podniesienia przez gracza.

    - **FieldBooster** - klasa nieużywana, miała reprezentować bonus ulepszający postać stojącą na danym polu.

- **Rozgrywka** - klasy odpowiadające za rozgrywkę. Mają za zadanie obsługę różnych interakcji pomiedzy obiektami klas znajgujących się w logice gry.
    
    - **Game** - główna klasa zarządzająca aplikacją. Odpowiada za stworzenie okna rozgrywki, stosu obiektów klasy State, będących kolejnymi widokami programu (więcej w opisie klasy state) oraz zainicjowanie logiki gry. Odpowiada również za renderowanie obiektu State będącego na szczycie stosu oraz obsługę zdarzeń. 

    - **GameController** - klasa odpowiedzialna za przeprowadzanie wszystkich akcji dostępnych w grze; zawiera funkcje leczenia postaci, przenoszenia postaci na inne pole, ataku bohaterów przeciwnika oraz sprawdzenia, czy wybrane przez gracza pole jest w zasięgu jego akcji (leczenia, poruszania się, ataku).

- **GUI** - graficzny interfejs użytkownika wykorzystuje klasy z logiki oraz rozgrywki i zapewnia komunikację pomiędzy użytkownikiem i aplikacją.
    
    - **State** - jest klasą bazową dla wszystkich widoków dostępnych w grze. Posiada pola będące wskaźnikami na atrybuty stworzone w klasie **Game**, obiekty tekstur, oraz długość i szerokość siatki (0.01 wysokości i 0.01 szerokości ekranu), które umożliwiają skalowanie. Klasa posiada metodę odczytującą współrzędne kursora myszy, oraz wirtualne metody odświeżania oraz renderowania implementowane w każdej klasie dziedziczącej po **State**. Pozwoliło nam to pracować równocześnie nad różnymi widokami. Przechodzenie pomiędzy nimi zrealizowaliśmy przy pomocy stosu. Gdy widok ma przejść na kolejny, w zależności od tego czy chcemy w przyszłości wrócić do obecnego, ustawiamy (lub nie) koniec danego widoku. Po tym dokładamy na stos nowy obiekt danego **State**. Gdy chcemy powrócić do poprzedniego, ustawiamy koniec danego widoku. Klasa **Game** wykrywa czy widok powinien być zdjęty ze stosu. Renderowany i odświeżany jest tylko szczyt stosu. W momencie gdy stos jest pusty aplikacja kończy działanie.

    - **MainMenuState** - widok startowego ekranu gry. Posiada przycisk START, po którego naciśnięciu przechodzimy do widoku wyboru postaci, oraz przycisk EXIT, którego naciśnięcie zamyka aplikację.

    - **CreateHeroesState** - widok wyboru postaci. Każdy z graczy może wybrać 4 dowolne postaci. Ich opis wyświetla się po najechaniu kursorem na dany przycisk. Można z niego wrócić do menu startowego lub przejść dalej do widoku ustawiania i konfiguracji postaci. W momencie gdy gracze nie wybrali poprawnej liczby postaci wyświetlany jest komunikat i przejście do następnego widoku nie jest możliwe.

    - **ConfigureHeroesState** - widok konfiguracji i ustawiania postaci na planszy. Gracze muszą ustawić swoją drużynę na wybranych przez siebie polach. Ponadto mogą wybrać styl gry każdej postaci. Do wyboru są Range - dający większy zasięg ataku lub poruszania się, Damage - dający większe obrażenia, oraz domyślny Balanced. Gracze mogą wrócić do wyboru postaci lub po ustawieniu całej drużyny na planszy przejść do rozgrywki.

    - **GameState** - widok głównej rozgrywki. Wyświetlana jest plansza oraz informacje o obecnej turze. Po naciśnięciu przez gracza na postać ze swojej drużyny wyświetlane jest menu wyboru akcji. Gracz może w danej turze wykonać 5 akcji lub w każdej chwili pominąć swoją turę. W momencie, gdy wszyscy gracze przeciwnika zginą wyświetla się komunikat o zakończeniu rozgrywki.

    - **ActionMenuButton** - przycisk wyboru akcji postaci. Gracz ma do wyboru, w zależności od typu postaci, różne akcje. Medyk posiada trzy akcje: leczenie, atak, ruch; trebusz i katapulta wyłącznie atak, a pozostałe postaci poruszanie i atak.
    
    - **Button** - klasa reprezentująca przycisk. Posiada kształt, teksturę, tekst oraz kolor, który zmienia się w zależności od stanu przycisku. Przycisk zmienia swój stan na aktywny, gdy nastąpi kliknięcie i puszczenie lewego przycisku myszy. Ułatwia to interakcję graczy z interfejsem. Oprócz oczywistego użycia obiektów tej klasy podczas tworzenia GUI, zastosowaliśmy je do obsługi pól planszy. 

    - **SelectButton** - w przeciwieństwie do **Button**, ten przycisk może być tylko zaznaczony lub odznaczony. Wykorzystujemy go do wyboru bohaterów przez graczy. Ponadto obiekty tej klasy posiadają metodę zwracającą, czy jest na nim kursor. Wykorzystywana jest ona do wyświetlania opisu danej postaci podczas wyboru.

    - **Descriptions** - klasa zawierająca teksty wyświetlane w GUI. Są to: ogólne opisy postaci, opisy danego stylu postaci oraz instrukcja dla użytkowników.

    - **GraphicSettings** - ustawienia graficzne. Okno naszej gry wyświetla się na pełnym ekranie. Maksymalna częstotliwość odświeżania to 60FPS. Okno jest skalowane do rozdzielczości monitora. 

    - **HPBar** - pasek życia bohatera. Zawiera trzy obiekty sf::Rectangle: tło, maksymalny pasek i aktualny pasek. W zależności od aktualnego HP bohatera aktualny pasek jest skalowany w proporcji obecne HP / maksymalne HP. Wyświetlany jest też napis informujący o punktach życia postaci.

    - **Loads** - ilość dostępnych akcji bohatera. Informuje ile razy postać może wykonać atak. Jest wyświetlana obok bohatera.

## Instalacja
Kompilację programu przeprowadzaliśmy z użyciem programu cmake i kompilatora gcc.
Do kompilacji programu wymagane jest połączenie z internetem umożliwiające pobranie wykorzystywanych przez nas bibiotek.

### Pierwsza kompilacja
```
    mkdir build
    cd build
    cmake ..
```

### Kompilacja wszystkich plików wykonawczych
```
    cd build
    cmake --build .
```

### Uruchomienie programu
```
    cd build
    ./main
```

### Uruchomienie testów jednostkowych
```
    ctest
```

### Uruchomienie pojedynczego testu
```
    cd build
    ./(test_name)
```

## Proces tworzenia
Pierwsze spotkanie odbyło się kilka dni po ogłoszeniu rozpoczęcia prac nad projektami. Przeprowadziliśmy długą i merytoryczną rozmowę na temat naszych pomysłów na projekt i założeń, jakie chcielibyśmy wprowadzić do naszej gry. Po krótkim odstępie czasu stworzyliśmy repozytorium na GitLabie, wspólnie rozdysponowaliśmy zadania między siebie i przystąpiliśmy do pracy. 

Spotkania odbywały się regularnie, co około dwa tygodnie. W zależności od warunków spotykaliśmy się zarówno stacjonarnie jak i zdalnie. Podczas spotkań podsumowywaliśmy wykonaną do tej pory część projektu, omawialiśmy kolejne kroki w tworzeniu naszego programu oraz zaznaczaliśmy, co sprawiało nam problemy przy pisaniu kodu. Dodatkowo, każde mergowanie branchy odbywało się na spotkaniach, by wspólnie rozwiązywać napotkane konflikty w kodzie. Na początku chcieliśmy stworzyć działający system rozgrywki, który następnie urozmaicaliśmy dodatkowymi funkcjami.

Wprowadzenie ostatecznych poprawek spowodowało odrzucenie niektórych z początkowych założeń, których realizacji musieliśmy zaniechać - wraz z postępem w pisaniu prototypu gry zdaliśmy sobie sprawę, że niektóre z początkowych pomysłów kłócą się z założeniami rozgrywki. Dlatego podczas jednego z ostatnich spotkań dyskutowaliśmy, co i czemu powinniśmy odrzucić.

## Sposób testowania
Nasz projekt testowaliśmy zarówno za pomocą testów jednostkowych (folder tests), jak i metodą prób i błędów. Podczas uruchamiania gry i przeprowadzania przykładowej rozgrywki łatwo było nam zauważyć, co w jej logice nie jest spójne i potrzebuje poprawek. Pozwoliło nam to na znaczące ulepszenie początkowej wersji gry.

## Możliwości rozwoju
Nasz projekt posiada znaczne pole do rozwoju. Pierwsze, które przychodzą nam na myśl to zaimplementowanie odrzuconych w procesie produkcji ulepszeń znajdujących się na polach. Pozwoliłyby one urozmaicić rozgrywkę, oraz zwiększyć myślenie strategiczne graczy. Kolejna rzecz, nad którą wartoby się zastanowić to rozgrywka z przeciwnikiem sterowanym przez komputer. Dodanie dźwięków i animacji znacząco zwiększyłoby frajdę z płynącą z rozgrywki. Ciekawe byłoby też dodanie wyboru różnych broni, większa personalizacja postaci np. wybór skina bohatera. Zaimplementowana przez nas rozgrywka mogłaby stać się częścią większej gry RPG ze zdobywaniem zasobów za rozegrane bitwy, które umożliwiłyby kupowanie ulepszeń, nowych bohaterów, broni itp.

Ilość pomysłów które moglibyśmy zrealizować świadczy o tym, że nasz projekt nie jest zamkniętą strukturą i ciągle możemy go rozwijać.
