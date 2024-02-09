# Setting Up
Compilation :
> make

Le projet "Setting Up" vise à développer un programme en langage C pour déterminer le plus grand carré possible sur une grille tout en évitant les obstacles. L'objectif principal est de trouver la plus grande zone carrée libre sur une grille donnée.

Fonctionnalités :

Validation de la grille :  
  Le fichier de grille doit respecter certaines contraintes, telles que le nombre de lignes en première ligne, la présence uniquement des caractères '.' et 'o' sur les autres lignes, la même longueur pour toutes les lignes (sauf la première), etc.

Détermination du plus grand carré :  
  Le programme détermine le plus grand carré possible sur la grille sans traverser les obstacles, et le représenter en remplaçant certains '.' par 'x'.

Génération de la grille :  
  En entrant un paterne et un nombre de lignes au lieu d'un fichier le programme généreras une grille en suivant ce paterne

Exemple grille :  
>9  
....................o......  
....o......................  
............o..............  
................o..........  
....o......................  
..............o............  
.................o.........  
.....................o.....  
..o........................  

**Fonctionnement :**  
Avec fichier donnée :  
>./setting_up chemin_vers_grille

Génération :  
>./setting_up nombre_lignes paterne  
