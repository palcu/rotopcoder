#Enunț
Marcel vinde telefoane cu un nou joc, un spirit se deplaseaza pe o matrice cu NxM camere, 
se poate trece dintr-o cameră în alta pe orizontală și pe verticală, în plus camerele de pe prima 
linie sunt legate de cele de pe ultima linie, iar camerele de prima coloană sunt legate de cele de pe ultima coloană.
În fiecare cameră există o carte de joc, carțile au rangurile {2, 3, 4, 5, 6, 7, 8, 9, t, j, q, k, a} 
și culorile {c, h, d, s}, Marcel îți arată K cărți speciale, scopul jocului e să ajungi de la portalul 
de intrare de coordonate x1 și y1 la portalul de ieșire de coordonate x2 și y2 cu numar minim de pași știind că
spiritul ramăne blocat daca ajunge într-o cameră cu o carte specială, 
iar spiritul trebuie să treacă prin fiecare culoare cel puțin o data.

#Date de intare
Pe prima linie sunt 3 numere N, M, K.  
Pe a doua linie sunt cele K cărți speciale.  
Pe următoarele N linii sunt câte M cărți.  
Pe ultimele 2 linii sunt coordonatele portalelor x1 y1 și x2 y2.  

# Date de ieșire
În fișierul de ieșire se v-a afișa un singur număr, numărul minim de pași dacă
există un drum valid, -1 în caz contrar.

Restricții  
1 <= N, M <= 1000  
1 <= K <= 52  
Pentru 20% din teste N, M <= 20.  
Pentrul alte 20% din teste numarul minim de pasi e cel mult 10.  

harta.in
```
4 4 3
ac 2s 2c
3c 3d ts td
kc 2s 2c 2c  
as 2s 3h 2c
ad 2s 2c 2c
1 4
4 1
```
harta.out
```
-1
```

harta.in
```
4 4 3
ac 2s 2c
3c 3d ts td
kc 2s 2c 2c  
as as 3h 2c
ad 2s 2c 2c
1 4
4 1
```
harta.out
```
8
```

Explicații
În primul exemplu, spiritul nu poate ajunge la destinație
trecând prin fiecare culoare o data.
În al doilea exemplu, spiritul ajunge la destinație în 8 pași
drumul este (4,1) -> (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)
-> (3, 2) -> (3, 1) -> (4, 1)
