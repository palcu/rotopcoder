# Telina

> Țelina, sau apium graveolens, este o plantă din familia apiaceae. Poate atinge o înălțime de până la 1 m. Frunzele sale sunt mari, penat-lobate. Florile sunt mici, de obicei având culoarea albă. Fructul său este achenă. Poate rezista până la temperaturi aproape de 0 grade Celsius. Perioada de înflorire este la începutul toamnei. Este o plantă hidrofilă.
http://ro.wikipedia.org/wiki/%C8%9Aelin%C4%83

Dat fiind un șir de caracter `S(1), S(2), ... S(n)` se aplică următoarele operații:

* la pasul 1 se alege dacă se alege între `S(1), S(2), ... S(n-2), S(n), S(n-1)` sau `S(1), S(2) ... S(n-2), S(n-1), S(n)`.
* la pasul i se alege șirul de caractere anterior (de la pasul (i - 1)) sau `S(1), S(2) ... reverse(S(n-i), S(n-i+1), ... S(n))`.

Se cere să se gaseasca șirul de caractere minim lexicografic la ultimul pas `n - 1`.

## Fișier de intrare

```
telina
```

## Fișier de ieșire

```
anilet
```

## Restricții

1 <= lungimea lui S < 10^6
