# Prise de notes Concevez votre réseau TCP/IPcours openclassroom

## I-Notion de réseau

​	Les réseaux composent internet pour l'envoie de mail ou la connexion à diverses sites internets. Ces diverses actions nécessitent l'envoie ou la réception respective de requêtes et de réponses depuis votre machine à celle d'autres compagnies et usagers. Or ces machines sont stockées à plusieurs centaines de kilomètre de la votre. Ainsi tous les messages échangé vont être conduit au travers de dizaines de câbles et d'équipement. Ces messages vont aussi devoir être:

- converti
- amplifié
- chiffré
- atténué

L'ensemble de ces étapes sont assuré par un réseau.

Les réseaux ont donc pour but de permettre la transmission d’informations.

Il existe différent types de réseaux :

- **LAN (Local Area Network)** := réseau local (ex : réseaux domestiques de votre domicile, ou les réseaux à l’échelle d’une entreprise)
- **MAN (Metropolitan Area Network)** := réseau déployés à l’échelle d’une ville (ex : réseaux universitaires). Ces réseaux sont eux-même composé de LAN.
- **WAN (Wide Area Network)** := réseaux à échelle mondiale (ex : internet) composé de MANs et de LANs.

Pour représenter un réseaux, deux schémas sont principalement utilisé, les schémas logique et physique.

### 	a) Schéma logique 

Le **schéma logique** indique :

- l'architecture du réseau ;
- certains aspects de sa configuration logicielle.

![](/home/julien/Documents/Formations/Concevez_votre_reseau_tcp_ip/images/Capture d’écran du 2023-08-17 23-52-13.png)

Figure 1: éléments physique d'un réseau ou **schéma logique**) de type LAN (Local Area Network), se compose **d'équipement terminaux** en *bleu*, d'**interconnexion** (ex switchs et routeur), **support communication** représenté par des *traits*.

### b) Schéma physique

Le schéma physique indique:

- la **localisation physique** des équipements (ville/bâtiment/salle) ;
- le **nombre de câbles** utilisés pour relier les éléments ;
- le **nombre exact de machines** sur le réseau ;
- une vue plus détaillée des **équipements d’interconnexion**.

![](/home/julien/Documents/Formations/Concevez_votre_reseau_tcp_ip/images/schema_pysique.png)

Figure 2 : Schéma physique

Maintenant que les schémas ont été présenté, nous allons abordé la simulation de ces réseaux à l'aide de Cisco Packet Tracer.

## II-L’outil de simulation Packet Tracer

- Vous pouvez créer une maquette virtuelle de votre réseau grâce à un outil de simulation.
- Packet Tracer est un outil de simulation très répandu et développé par Cisco  Systems, le leader dans la fabrication d’équipements réseaux. Il existe  cependant d’autres outils de simulation.
- Packet Tracer vous permettra aussi de simuler des communications au sein de votre réseau virtuel, une fois que l’aurez créé.
- Vous pouvez télécharger gratuitement Packet Tracer en vous rendant sur [ce site.](https://www.netacad.com/courses/packet-tracer/introduction-packet-tracer)

## III-Relier deux machines entres elles

### 	A) Identifier les émetteur-récepteurs

​	Les émetteurs-récepteurs sont les **équipements terminaux** de votre réseaux. Ils ont pour particularité la  capacité à traduire un message humain (voix, image, vidéo, texte) en message numérique, ou **langage binaire**.

Leurs formes restent cependant très variées.

	### 	B) Déterminez le bon support de communication

Il y a 3 type de support de communications : 

- le **câble en cuivre**, dont le plus utilisé est le **câble à paires torsadées** (Ethernet ou RJ45);
- le **câble optique** ou **fibre optique** ;
- l’**air**, si on souhaite communiquer sans fil. 

Le choix d'un support dépend des paramètres suivant :

- le type d’équipement à raccorder : PC, serveur, téléphone, tablette… ;
- la distance qui sépare 2 équipements entre eux ;
- l’environnement extérieur : perturbation, humidité... ;
- l’usage : mobilité des usagers, débits.

![](/home/julien/Documents/Formations/Concevez_votre_reseau_tcp_ip/images/choix_support_com.png)

Figure 3 : Tableau récapitulatif choix support de communication

		### 	B) Raccordez vos machines au support choisi

#### 		i) Identifier la carte réseau de votre machine

La carte réseau transforme les données binaires à envoyer, en électricité, lumière ou  ondes électromagnétiques, afin qu’elles puissent voyager sur le support  de transmission choisi et inversement.

`Avec Linux tapez ifconfig`

#### 		ii) != types de cartes réseaux

Carte réseau est associé à un port et à un support de transmission, tout cela étant régi par des **normes**. 

![](/home/julien/Documents/Formations/Concevez_votre_reseau_tcp_ip/images/diff_types_carte_res.png)

Figure 4 : != types de cartes réseaux

**La norme régissant les réseaux LAN et MAN porte le joli nom de IEEE 802. Elle contient tout un ensemble de sous-normes pour des catégories de réseaux plus spécifiques.** 

La norme la plus utilisée pour les communications au sein d’un **réseau WLAN** (Wireless Local Area Network), c’est-à-dire d’un réseau local sans fil, s’appelle Wi-Fi ou IEEE 802.11.

Pour le WIFI, des **Mécanismes de chiffrement** ont été mis en place. Ces mécanismes font intervenir l’usage d’une clé de chiffrement type WPA (pour *Wi-Fi Protected Access*).

Les != câbles réseaux :

- Un **câble croisé** doit être utilisé pour relier directement 2 équipements terminaux entre eux. Par exemple, un PC avec un PC, un PC avec une imprimante ou un PC avec  un serveur.
- Les **câbles droits** seront utilisés dès qu’on a affaire à des réseaux intégrant des équipements  d’interconnexion que nous allons voir dans le chapitre suivant.

### IV) Les != équipements réseaux

#### a) Switch (ou commutateur)

Conduit les != requêtes au travers d'une machine à une autre à travers un réseau.

- **le nombre de ports** allant de 4 à 96, permettant d’y connecter autant de machines ;
- **le type de port** : port RJ45 pour les câbles réseau standard, ou interface optique (type SFP+) pour la fibre optique. Ce sont les plus courants ;
- **le débit possible** sur chaque port : de 10 Mbp à 100 Gbp ;
- **les fonctionnalités** telles que l’interface de configuration, la compatibilité ou les modes de communication.

b) Hub

Distribue les != requêtes au travers des machines auxquelles il est connecté.

C) Routeur

Conduits les messages au travers de != réseaux.

Le routeur a 3 fonctions :

- il sépare 2 réseaux aux règles parfois différentes ;
- il décide quel message a le droit de passer ou non ;
- si besoin, il aiguille les messages dans la bonne direction, comme le switch.

