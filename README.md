# Projet C++  Module 09

Utilisation des conteneurs

Le conteneur utilisé dans un exercice ne pourra plus être utilisé dans un autre.

***Chaque exercie contient son propre Makefile***

## Exercice 00: Bitcoin Exchange

***Objectif:***

```
Le programme affiche la valeur d’une certaine quantité de bitcoins à une certaine date. Il prendra en entrée une deuxième base de données stockant les différents prix/dates à évaluer.
• Le nom du programme est btc.
• Le programme doit prendre un fichier en argument.
• Chaque ligne de ce fichier doit utiliser le format suivant: "date | valeur".
• Une date valide sera toujours au format "Année-Mois-Jour" (YYYY-MM-DD).
• Une valeur valide doit être soit un nombre à virgule flottante (float), ou un entier
positif, compris entre 0 et 1000.
```

***Exemple de résultat attendu***

```
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```

## Exercice 01: Reverse Polish Notation

```
Vous devez créer un programme avec ces contraintes :
• Le nom du programme est RPN.
• Le programme doit prendre en argument une expression mathématique en no-
tation polonaise inversée compos"e de chiffre uniquement.
• Le programme afficher le résultat correct sur la sortie standard.
• Le programme doit être capable de gérer les opérations avec ces opérateurs: "+ - / *".
```

Exemples de notation polonaise inversée :

```
"6 2 / 3 4 * + 7 -" vaut 8
"9 2 * 5 / 3 + 8 -" vaut -2
"8 2 * 4 + 6 3 / -" vaut 18
```

## Exercice 02: PmergeMe

```
• Le nom du programme est PmergeMe.
• Le programme doit prendre une séquence d’entiers positif en argument.
• Le programme doit utiliser l’algorithme de tri "merge-insert" pour trier la séquence
de nombres.
• Le programme doit comparer le résultat obtenu avec 2 types de conteneurs
```

***Exemple de résultat attendu***

```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>
```

