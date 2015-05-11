#Enunt

Se da un dictionar de cuvinte si un sir de caractere ce reprezinta o propozitie din care s-au eliminat spatiile. Fiecare cuvant din dictionar are asociat un cost. Sa se afiseze o descompunere valida de cost minim a propozitiei precum si costul minim al acelei descompuneri.

#Date de intrare

Pe prima linia se va afla un sir de caractere fara spatii ce reprezinta propozitia care va trebui descompusa. Pe linia a 2-a va fi un numar N, ce reprezinta numarul de cuvinte din dictionar urmat de N linii astfel:  linia i + 2 contine un cuvant CUV(i) fara spatii urmat de un numar COST(i) ce reprezinta costul asociat cuvantului i.

#Date de iesire
Pe prima linie se va afisa o descompunere valida de cost minim a propozitiei folosind cuvintele din dictionar.
Pe a 2-a linie se va afisa costul minim al acelei descompuneri.
In cazul in care nu exista nicio descompunere valida, se va afisa -1.


#Fișier de intrare

```
anaaremere
6
ana 2
are 5
mere 3
arem 2
er 1
e 1
```

#Fișier de ieșire

```
ana are mere
6
```

#Restrictii
Cuvintele sunt unice.
1 <= len(prop) <= 1000
1 <= len(CUV(i)) <= 50
1 <= COST(i) <= 1000
1 <= N <= 30000
TODO punctaje partiale
