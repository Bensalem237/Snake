🎮 PROJETS “JEU CONSOLE”
Projet 1 — Le jeu du Serpent (Snake simplifié en console)
🎯 Objectif pédagogique :

Réinvestir variables, boucles, conditions, tableaux et fonctions pour simuler le déplacement d’un serpent sur une grille.

🧩 Concept :

Le joueur contrôle un serpent représenté par un caractère ('O') qui se déplace sur une grille 10x10.
Un fruit ('F') apparaît à une position aléatoire. Si le serpent “mange” le fruit, il grandit et le score augmente.
Le jeu s’arrête si le serpent touche les bords.

🧠 Notions utilisées :

Variables : coordonnées du serpent, du fruit, score.

Boucles : boucle principale du jeu.

Conditions : vérification de collision et du fruit mangé.

Tableaux : stockage des positions du serpent.

Fonctions : pour séparer la logique (update(), draw(), input()).

Pointeurs : passage d’adresses à certaines fonctions (mise à jour position).

🪜 Étapes de réalisation :

Initialisation

Définir une grille 10x10 (tableau 2D de char).

Positionner le serpent au centre et le fruit aléatoirement.

Boucle de jeu

Afficher la grille (fonction draw()).

Lire une direction (z, q, s, d).

Mettre à jour la position du serpent (fonction update()).

Vérifier collisions (mur ou fruit).

Conditions de victoire/défaite

Si fruit mangé → augmenter la taille et repositionner fruit.

Si collision → fin du jeu.

Affichage score et message de fin.
Ajouter une pause.
Rendre la taille du serpent réellement visible (tableau de positions).
Ajouter une vitesse croissante.

🤖 PROJETS “IA CONSOLE”
Projet 2 — Devine le nombre (IA qui apprend)
🎯 Objectif :

Montrer la logique inverse du “Plus ou Moins” : ici, c’est l’ordinateur qui devine le nombre du joueur.

🧩 Concept :

Le joueur pense à un nombre entre 1 et 100.
L’IA propose un nombre.
Le joueur indique si c’est “trop grand”, “trop petit” ou “trouvé”.
L’IA affine ses bornes jusqu’à trouver.

🧠 Notions :

Variables : bornes min/max, proposition IA.

Boucles : répéter jusqu’à ce que trouvé.

Conditions : ajuster les bornes.

Fonctions : devinerNombre(), demanderReponse().

Pointeurs : modifier bornes via fonction.

Tableaux : mémoriser les propositions.

🪜 Étapes :

Initialiser min = 1, max = 100.

Calculer une proposition = (min + max) / 2.

Demander au joueur la réponse.

Ajuster bornes selon “+” ou “-”.

Répéter jusqu’à “trouvé”.

🔍 Bonus :

Afficher le nombre d’itérations.

Ajouter une fonction de score : moins l’IA met de coups, mieux elle “joue”.

Projet 3 — Pierre-Feuille-Ciseaux avec IA adaptative
🎯 Objectif :

Introduire la notion de stratégie basique et d’analyse de données simples.

🧩 Concept :

Le joueur joue contre l’ordinateur.
L’IA essaye de “prédire” le prochain coup du joueur en observant son historique.

🧠 Notions :

Variables : coups, scores.

Tableaux : stocker les derniers coups du joueur.

Fonctions : choixIA(), verifierVainqueur(), afficherResultat().

Boucles : pour répéter les tours.

Conditions : déterminer le vainqueur.

Pointeurs : mise à jour des scores via fonction.

🪜 Étapes :

Afficher menu (1 = pierre, 2 = feuille, 3 = ciseaux).

L’IA choisit aléatoirement les premiers coups.

À partir du 3e tour, l’IA observe les 2 derniers choix du joueur et fait un choix “intelligent” (ex : si joueur choisit souvent pierre → jouer feuille).

Mise à jour du score.

Afficher les résultats finaux après 5 manches.

🔍 Bonus :

Ajouter un mode “aléatoire pur” et un mode “intelligent”.

Statistiques finales (taux de victoire, coups favoris).

⏱️ Durée estimée : 1h30
🧭 Recommandation pédagogique
Type de projet	Difficulté	Durée	Objectif clé
Snake console	★★★★☆	Structuration logique et fonctions
IA devine nombre	★★★☆☆	Logique algorithmique + pointeurs
Pierre-Feuille-Ciseaux IA	★★★★☆	Pensée algorithmique et tableaux


Base de code dans votre fichier Principale peu importe le projet:

inclure obligatoirement "#include <windows.h>"

Pour effcer lecran de la console:

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Efface l’écran entier
    FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

pour positionner le curseur avant dessin ou ecriture:

void setCursorPosition(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

ecriture : std::cout << "O"; // Affiche le serpent à la position (10, 5)

ou plus simple pour dessiner ou ecrire a une position donner:
void WriteInPosition(int x, int y, const std::string& information)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
    td::cout << information; // Affiche le serpent à la position (10, 5)
}