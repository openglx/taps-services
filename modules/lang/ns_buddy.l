++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ de: jo

+NS_BUDDY_SUMMARY(en_us)
Buddy list management
+NS_BUDDY_SUMMARY(nl)
Vrienden lijst management
+NS_BUDDY_SUMMARY(de)
Verwaltung der Freundesliste
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_HELP(en_us)
The // BUDDY provides commands to manage your buddy list.
The available subcomands are:
  // BUDDY ADD nick
  // BUDDY DEL nick
  // BUDDY LIST
Please note that adding a buddy will only be completed
after the request has been accepted.
+NS_BUDDY_HELP(nl)
Het // BUDDY commando bied de mogelijkheid uw vriendenlijst
te beheren.
De beschikbare sub commando's zijn
 // BUDDY ADD bijnaam
 // BUDDY DEL bijnaam
 // BUDDY LIST
Notitie: Als u iemand als vriend toevoegd wordt deze alleen
op de lijst gezet als uw vriend de aanvraag heeft geaccepteerd. 
+NS_BUDDY_HELP(de)
Der // BUDDY Befehl ermäglicht die Verwaltung der Freundesliste.
Gültige Unterbefehle sind:
 // BUDDY ADD Nickname
 // BUDDY DEL Nickname
 // BUDDY LIST
Hinweis: Wenn du jemanden zu deiner Freundesliste hinzufügst, so muss
der erst vom Buddy akzeptiert werden.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_SYNTAX(en_us)
Syntax:
  // BUDDY ADD nick
  // BUDDY DEL nick
  // BUDDY ACCEPT nick
+NS_BUDDY_SYNTAX(pt)
Sintaxe:
  // BUDDY ADD nick
  // BUDDY DEL nick
  // BUDDY ACCEPT nick
+NS_BUDDY_SYNTAX(nl)
Syntax:
  // BUDDY ADD bijnaam
  // BUDDY DEL bijnaam
  // BUDDY ACCEPT bijnaam
+NS_BUDDY_SYNTAX(de)
Syntax:
  // BUDDY ADD Nickname
  // BUDDY DEL Nickname
  // BUDDY ACCEPT Nickname
++++++++++++++++++++++++++++++++++++++++++++  
+NS_BUDDY_ADD_SYNTAX(en_us)
Syntax:
  // BUDDY ADD nick
+NS_BUDDY_ADD_SYNTAX(pt)
Sintaxe:
  // BUDDY ADD nick
+NS_BUDDY_SYNTAX(nl)
Syntax:
  // BUDDY ADD bijnaam
+NS_BUDDY_SYNTAX(de)
Syntax:
  // BUDDY ADD Nickname
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_NICK_X_ALREADY_BUDDY(en_us)
The nick \B%s\B is already on your buddies list.
+NS_BUDDY_NICK_X_ALREADY_BUDDY(pt)
O nick \B%s\B já está na sua lista de amigos.
+NS_BUDDY_NICK_X_ALREADY_BUDDY(nl)
Bijnaam \B%s\B staat al op de vriendenlijst.
+NS_BUDDY_NICK_X_ALREADY_BUDDY(de)
Der Nick \B%s\B ist bereits in deiner Freundesliste.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_MAX_REACHED(en_us)
Buddy can not be added.
You have reach the maximum number of buddies for your nick!
+NS_BUDDY_MAX_REACHED(pt)
O amigo não pode ser adicionado.
Atingiu o número máximo de amigos para o seu nick.
+NS_BUDDY_MAX_REACHED(nl)
Het maximale aantal vrienden voor de vriendenlijst is bereikt
voor deze bijnaam.
+NS_BUDDY_MAX_REACHED(de)
Die max. Anzahl and Freunden auf der Liste ist erreicht1!
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_X_MAX_REACHED(en_us)
Nick \B%s\B has too many budies.
+NS_BUDDY_X_MAX_REACHED(pt)
O nick \B%s\B já atingiu o limite de amigos.
+NS_BUDDY_X_MAX_REACHED(nl)
Bijnaam \B%s\B heeft te veel vrienden
+NS_BUDDY_X_MAX_REACHED(de)
Nick \B%s\B hat zu viele Freunde in der Liste.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_X_WAS_ADDED(en_us)
Buddy \B%s\B is added.
+NS_BUDDY_X_WAS_ADDED(pt)
O amigo \B%s\B foi adicionado.
+NS_BUDDY_X_WAS_ADDED(nl)
Vriend \B%s\B is toegevoegd.
+NS_BUDDY_X_WAS_ADDED(de)
Der Nick \B%s\B wurde deiner Frundeslsite hinzugefügt.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_NOT_SELF(en_us)
You can't add yourself as buddy !
+NS_BUDDY_NOT_SELF(pt)
Não se pode adicionar a si próprio como amigo !
+NS_BUDDY_NOT_SELF(nl)
U kan u zelf niet toevoegen aan de vriendelist !
+NS_BUDDY_NOT_SELF(de)
Du kannst dich nicht selber deiner Freundesliste hinzufügen!
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_DEL_SYNTAX(en_us)
Syntax:
  // BUDDY DEL nick
+NS_BUDDY_DEL_SYNTAX(pt)
Sintaxe:
  // BUDDY DEL nick
+NS_BUDDY_DEL_SYNTAX(nl)
Syntax:
  // BUDDY DEL bijnaam
+NS_BUDDY_DEL_SYNTAX(de)
Syntax:
  // BUDDY DEL Nickname
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_NICK_X_NOT_BUDDY(en_us)
Nick \B%s\B is not on your buddy list.
+NS_BUDDY_NICK_X_NOT_BUDDY(pt)
O nick \B%s\B não está na tua lista de amigos.
+NS_BUDDY_NICK_X_NOT_BUDDY(nl)
Bijnaam \B%s\B staat niet op de vriendenlijst.
+NS_BUDDY_NICK_X_NOT_BUDDY(de)
Der Nick \B%s\B steht nicht auf deiner Freundesliste.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_X_REMOVED(en_us)
\B%s\B has been removed from your buddy list.
+NS_BUDDY_X_REMOVED(pt)
O nick \B%s\B foi removido da sua lista de amigos.
+NS_BUDDY_X_REMOVED(nl)
\B%s\B is verwijderd van de vriendenlijst.
+NS_BUDDY_X_REMOVED(de)
Der Nick \B%s\B wurde aus deiner Freundesliste gelöscht.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_X_X_X_ADDED_YOU(en_us)
Nick \B%s\B added you to its buddy list.
You can accept it with:
  // BUDDY ACCEPT %s
Or remove it with:
  // BUDDY DEL %s
+NS_BUDDY_X_X_X_ADDED_YOU(pt)
O nick \B%s\B adiciou-o na lista de amigos.
Pode aceitar e adiciona-lo tambem com o comando:
  // BUDDY ACCEPT %s 
Ou rejeitar a adição com:
  // BUDDY DEL %s
+NS_BUDDY_X_X_X_ADDED_YOU(nl)
Bijnaam \B%s\B heeft u toegevoegd aan zijn/haar
vriendenlijst.
Om dit te accepteren typ:
  // BUDDY ACCEPT %s
Of verwijder het met
  // BUDDY DEL %s
+NS_BUDDY_X_X_X_ADDED_YOU(de)
Der Nick \B%s\B hat dich seiner/ihrer Freundesliste hinzugefügt:
Um das zu akzeptiere tippe:
  // BUDDY ACCEPT %s
Oder, um es abzulehnen:
  // BUDDY DEL %s
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_ACCEPTED_X(en_us)
\B%s\B was added to your buddy list
+NS_BUDDY_ACCEPTED_X(pt)
O nick \B%s\B foi adicionado à sua lista de amigos
+NS_BUDDY_ACCEPTED_X(nl)
\B%s\B heeft u toegevoegd aan zijn/haar vriendelijst
+NS_BUDDY_ACCEPTED_X(de)
\B%s\B hat dich seiner/ihrer Freundesliste hinzugefügt.
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_ACCEPT_SYNTAX(en_us)
Syntax:
  // BUDDY ACCEPT nick
+NS_BUDDY_ACCEPT_SYNTAX(pt)
Sintaxe:
  // BUDDY ACCEPT nick
+NS_BUDDY_ACCEPT_SYNTAX(nl)
Syntax:
  // BUDDY ACCEPT bijnaam
+NS_BUDDY_ACCEPT_SYNTAX(de)
Syntax:
  // BUDDY ACCEPT Nickname
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_LIST_HEADER(en_us)
----- Buddy list -----
+NS_BUDDY_LIST_HEADER(pt)
----- Lista de amigos ---
+NS_BUDDY_LIST_HEADER(nl)
----- Vriendenlijst -----
+NS_BUDDY_LIST_HEADER(de)
----- Freundesliste -----
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_LIST_TAIL(en_us)
-------------------------
+NS_BUDDY_LIST_TAIL(pt)
-------------------------
+NS_BUDDY_LIST_TAIL(nl)
-------------------------
+NS_BUDDY_LIST_TAIL(de)
-------------------------
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_LIST_ITEM_X_X(en_us)
  %s %s
+NS_BUDDY_LIST_ITEM_X_X(pt)
  %s %s
+NS_BUDDY_LIST_ITEM_X_X(nl)
  %s %s
+NS_BUDDY_LIST_ITEM_X_X(de)
  %s %s
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_STATUS_INVITING(en_us)
(Pending)
+NS_BUDDY_STATUS_INVITING(pt)
(Pendente)
+NS_BUDDY_STATUS_INVITING(de)
(wartend)
++++++++++++++++++++++++++++++++++++++++++++
+NS_BUDDY_INVITED(en_us)
You have been added as buddy by the following user(s):
+NS_BUDDY_INVITED(pt)
Voce foi adicionao como amigo pelo(s) seguinte(s) utilizador(es):
+NS_BUDDY_INVITED(de)
Du wurdest von folgenden Benutzern auf ihre Freundeslistze gesetzt:

