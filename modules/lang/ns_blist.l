++++ ns_blist.l
++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ pt_br: Ricardo

+BLIST_SUMMARY(en_us)
Manages the email black list.
+BLIST_SUMMARY(pt)
Gere a lista de demails proibidos.
+BLIST_SUMMARY(nl)
Beheer de E-Mail zwartelijst.
+BLIST_SUMMARY(de)
Verwaltet die email Blacklist.
+++++++++++++++++++++++++++++++++++++++++++++
+BLIST_HELP(en_us)
The blist command allows to manage the email black list:

Syntax:
  // BLIST ADD ( user@email | @email )
  // BLIST DEL ( user@email | @email )
  // BLIST LIST [mask]

Examples:
  Add all emails from @myemail.com to the black list
  // BLIST ADD @myemail.com
  Delete @myemail.com from the blacklist
  // BLIST DEL @myemail.com
  List all nicks with \"my\" on the blacklist.
  // BLIST LIST [mask] 

+BLIST_HELP(nl)
Het blist commando stelt u in staat de E-Mail zwartelijst te beheren:

Syntax:
  // BLIST ADD (user@email | @email )
  // BLIST DEL (user@email | @email )
  // BLIST LIST [mask]
  
Voorbeelden:
  Voeg alle E-mail adressen toe aan de zwartelijst van @mijnemail.com
  // BLIST ADD @mijnemail.com
  Verwijder @mijnemail.com van de zwartelijst
  // BLIST DEL @mijnemail.com
  Geef een lijst van alle bijnamen met \"mijn\" die aanwezig zijn op de zwartelijst
  // BLIST LIST [masker] 
+BLIST_HELP(de)
Der blist-Befehl erlabut die Verwaltung der email-Blacklist:

Syntax:
  // BLIST ADD ( user@email | @email )
  // BLIST DEL ( user@email | @email )
  // BLIST LIST [mask]

Beispiele:
  Füge alle emails von @myemail.com zur Blacklist hinzu:
  // BLIST ADD @myemail.com
  Lösche @myemail.com aus der Blacklist:
  // BLIST DEL @myemail.com
  Liste alle Nicks mit \"my\" in der Blacklist.
  // BLIST LIST  

++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_SYNTAX(en_us)
Syntax:
  // BLIST ADD (user@email | @email)
  // BLIST DEL (user@email | @email)
  // BLIST LIST [mask]
+NS_BLIST_SYNTAX(nl)
Syntax:
  // BLIST ADD (iets@email | @email)
  // BLIST DEL (iets@email | @email)
  // BLIST LIST [mask]
+NS_BLIST_SYNTAX(de)
Syntax:
  // BLIST ADD (user@email | @email)
  // BLIST DEL (user@email | @email)
  // BLIST LIST [mask]
+++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_HEADER(en_us)
******* Email BlackList **********
+NS_BLIST_HEADER(nl)
***** E-Mail Zwartelijst *********
+NS_BLIST_HEADER(de)
******* Email BlackList **********
+++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_TAIL(en_us)
******** (%d item(s)) **************
+NS_BLIST_TAIL(nl)
******* (%d regel(s)) ************** 
+NS_BLIST_TAIL(de)
******** (%d Einträg(e) ************
+++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_ITEM_X(en_us)
%s
+NS_BLIST_ITEM_X(nl)
%s
+NS_BLIST_ITEM_X(de)
%s
+++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_DEL_SYNTAX(en_us)
  // BLIST DEL email
+NS_BLIST_DEL_SYNTAX(nl)
  // BLIST DEL email
+NS_BLIST_DEL_SYNTAX(de)
  // BLIST DEL email
+++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_NOT_ON_LIST(en_us)
\B%s\B is not on the email blacklist
+NS_BLIST_NOT_ON_LIST(nl)
\B%s\B bestaat niet op de E-Mail zwartelijst
+NS_BLIST_NOT_ON_LIST(de)
\B%s\B ist nicht in der Email-Blacklist
++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_TARGET_REMOVED(en_us)
\B%s\B has been removed from the email blacklist
+NS_BLIST_TARGET_REMOVED(nl)
\B%s\B is verwijderd van de E-Mail zwartelijst
+NS_BLIST_TARGET_REMOVED(de)
\B%s\B wurde aus der Email-Blacklist gelöscht.
++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_ADD_SYNTAX(en_us)
  // BLIST ADD (user@email | @email)
+NS_BLIST_ADD_SYNTAX(nl)
  // BLIST ADD (iets@email | @email)
+NS_BLIST_ADD_SYNTAX(de)
  // BLIST ADD (user@email | @email)
++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_X_ALREADY_ON_LIST(en_us)
\B%s\B is already on the email blacklist
+NS_BLIST_X_ALREADY_ON_LIST(nl)
\B%s\B staat al op de E-Mail zwartelijst
+NS_BLIST_X_ALREADY_ON_LIST(de)
\B%s\B ist bereits auf der Email-Blacklist.
++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_X_ADD_TO_LIST(en_us)
\B%s\B has been added to the email blacklist
+NS_BLIST_X_ADD_TO_LIST(nl)
\B%s\B is toegevoegd aan de E-Mail zwartelijst
+NS_BLIST_X_ADD_TO_LIST(de)
\B%s\B wurde der Email-Blacklist hinzugefügt.
++++++++++++++++++++++++++++++++++++++++++++++++
+NS_BLIST_INPUT_NOT_CORRECT(en_us)
The email you try to blacklist \B%s\B is not correct, see 
  // \BBLIST HELP\B  for more information
+NS_BLIST_INPUT_NOT_CORRECT(nl)
De invoer \B%s\B die u probeert toe te voegen aan de E-Mail
zwartelijst is niet correct, zie
  // \BBLIST HELP\B voor meer informatie
+NS_BLIST_INPUT_NOT_CORRECT(de)
Die Emailadrese \B%s\B is ungültig und kann so nicht zur Email-Blacklist
hinzugefügt werden, siehe:
  // \BBLIST HELP\B für weitere Informationen
