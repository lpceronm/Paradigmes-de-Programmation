# **C++**

Etape 4
======
**1. Comme pour la fonction d'affichage, la fonction pour jouer l'objet ne modifie pas l'objet et elle doit être déclarée dans les classes Photo et Video et dans la classe de base afin de permettre un appel polymorphique sur la hiérarchie de classes. Cependant, contrairement à la fonction d'affichage, elle ne peut pas avoir d'implementation au niveau de la classe de base (car a priori chaque type d'objet nécessite un utilitaire différent pour être joué). Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?**

On appelle ces méthodes *abstraites*. Pour les définir on met dans la déclaration de la méthode **=0** à la fin. 

``` void show(ostream &s) = 0 ; ```

**2. Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?**

La classe **Multimedia** deviens abstraite quand on déclare ses méthodes abstraites, par conséquent elle ne peut pas être instancié.

Etape 5
======

**Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.**

La propriété qui permet de traiter des objets selon la nécessité est *le polymorphisme*. Elle permet de regrouper des objets de types différents avec caractéristiques communes sans considérer leur details.

Dans C++ on utilise le mot *virtuel* dans la déclaration des méthodes de la classe de base pour forcer aux sous-classes à utiliser leur propre implémentation de ses méthodes, par contre en Java cette distinction n'est pas nécessaire.

``` 
// Multimedia
virtual void write(ostream &os);
virtual void read(istream &is);
// Photo
void write(ostream &os);
void read(istream &is);
```

Etape 6
======

**Le même problème se pose si un accesseur retourne directement ce tableau sans prendre les précautions nécessaires : la encore le contenu du tableau n'est pas récopié et l'appelant peut le modifier à sa guise. Quelle est la solution très simple que propose C/C++ pour éviter ce problème ?**

La solution le plus simple est définir les accesseurs comme constantes et faire constante aussi ce qu'ils retournent.

``` const int *  getChapters() const; ```

Etape 7
=====
**1. Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?**

Pour le cas spécifique de la classe *Film* il faut détruire le tableau de chapitres quand on détruit l'objet. Pour le faire on appelle *delete[]* dans le destructeur de la classe.

```
Film::~Film(){
  delete[] chapters;
  cout << "Films deleted " + getName() + "\n";
}
```

**De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?**

Si on essaie de copier par exemple un tableau des int avec l'opérateur *=*, on copiera seulement le pointeur vers la première position. Pour copier tout le tableau, il faut définir un *Copy constructor* et *operator=* pour faire la copie profonde des objets.

```
//Copy constructeur
Film::Film(const Film& from): Video(from){ 
  chapNumber = from.chapNumber;
  chapters = new int[from.chapNumber];
  if (from.chapters)  copyChapters(from.chapNumber, from.chapters);
}

//operator=

Film& Film:: operator=(const Film& from) {
  Video::operator=(from);
  chapNumber = from.chapNumber;
  if (from.chapters && chapters) {
    chapters = new int[from.chapNumber];
    copyChapters(from.chapNumber, from.chapters);
  }else{
    delete[] chapters;
    chapters = new int[from.chapNumber];
    if (from.chapters)  copyChapters(from.chapNumber, from.chapters);
  }
  return *this;
}
```

Etape 8
=====
**Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.**

On garde seulement des pointeurs aux objets dans la liste pour permettre la modification d'objets en dehors d'elle et donner plus de dynamisme au programme.

Etape 10
====
**Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?**

On peut faire les constructeurs privés.

Etape 11
====
**Votre méthode processRequest() devra pouvoir accéder aux données de la classe créée à la question précédente. Sachant que cette méthode peut appartenir à n'importe quelle classe, quelle est la solution la plus simple ?**

La solution le plus simple est de créer la méthode dans la classe *Store* car est-elle la seule qui a d'accès aux éléments *Multimedia*

``` bool processRequest(TCPConnection& cnx, const string& request, string& response) ```

# **Java**

Etape 1
====
**Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?**

Si on écrit beaucoup dans le *JTextField* le texte commence à disparaître. Pour voir tout ce qu'on a écrit il faut retailler la fenêtre.