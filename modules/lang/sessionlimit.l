++++ operserv.l
++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ pt: Lamego
++++ pt_br: Ricardo
++++ de: jo

+OS_SESSION_SUMMARY(en_us)
Session management
+OS_SESSION_SUMMARY(nl)
Sessie beheer
+OS_SESSION_SUMMARY(de)
Sitzungsverwaltung
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_SYNTAX(en_us)
Syntax:
  // SESSION LIST number
  // SESSION VIEW host
+OS_SESSION_SYNTAX(nl)
Syntax:
  // SESSION LIST nummer
  // SESSION VIEW host
+OS_SESSION_SYNTAX(de)
Syntax:
  // SESSION LIST Zahl
  // SESSION VIEW Host
+++++++++++++++++++++++++++++++++++++++++++++  
+OS_SESSION_HELP(en_us)
On the irc services context, a session is defined as the set of
client connections from the a same host.
The // SESSION commands allows to view/manage client sessions.
The supported subcommands are:
  LIST - List sessions with connections above number
  VIEW - View users on a session
You can get more help on these commands with:
  // HELP SESSION subcommand.
+OS_SESSION_HELP(nl)
Binnen de irc services is een sessie aangegeven als het aantal client
connecties vanaf een zelfde host.
De // SESSION commando's stellen u in staat de client sessies te 
bekijken/beheren.
De ondersteunde subcommando's zijn:
  LIST - Lijst van connecties die meer zijn dan het opgegeven nummer
  VIEW - Bekijk de gebruikers van een sessie
Meer informatie hier over kunt u vinden met:
  // HELP SESSION subcommando. 
+OS_SESSION_HELP(de)
Im Zusammenhang mit IRC Services bedeutet eine Sitzung (Session) eine
Menge von Clientverbindungen vom selben Host.
Der // SESSION Befehl erlaubt es, diese Sitzungen einzusehen und zu verwalten.
Folgende Unterbefehler gibt es:
  LIST - Zeige Sitzungen mit mehr Verbindungen als der angegeben Zahl.
  VIEW - Zeige die Bentuzer einer Sitzung
Weitere Hilfe erhälst du mittels:
  // HELP SESSION Unterbefehl
+++++++++++++++++++++++++++++++++++++++++++++  
+OS_SESSION_LIST_SYNTAX(en_us)
Syntax:
  // SESSION LIST number
+OS_SESSION_LIST_SYNTAX(nl)
Syntax:
  // SESSION LIST nummer
+OS_SESSION_LIST_SYNTAX(de)
Syntax:
  // SESSION LIST Zahl
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_LIST_HEADER_X(en_us)
***** Sessions with more than \B%d\B connections *****
Host | Count | | Limit | Hits on limit
+OS_SESSION_LIST_HEADER_X(nl)
****** Sessies met meer dan \B%d\B connecties *******
Host | Count | | Limit | Hits on limit
+OS_SESSION_LIST_HEADER_X(de)
****** Sitzungen mit mehr als \B%d\B Verbindungen *******
Host | Count | | Limit | Hits on limit
+OS_SESSION_LIST_HEADER_X(pt)
****** Sessoes com mais do que \B%d\B conexoes *******
Host | Contagem | Limite | Numero de vezes no limite
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_LIST_TAIL(en_us)
********************************
+OS_SESSION_LIST_TAIL(nl)
*************************************
+OS_SESSION_LIST_TAIL(de)
*************************************
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_LIST_ITEM_host_count_limit_hits(en_us)
  %s %d/%d - \B%d\B Hit(s)
+OS_SESSION_LIST_ITEM_host_count_limit_hits(nl)
  %s %d/%d - \B%d\B overeenkomst(en)
+OS_SESSION_LIST_ITEM_host_count_limit_hits(de)
  %s %d/%d - \B%d\B Treffer
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_LIST_ITEM_host_count_limit(en_us)
  %s %d/%d
+OS_SESSION_LIST_ITEM_host_count_limit(nl)
  %s %d/%d
+OS_SESSION_LIST_ITEM_host_count_limit(de)
  %s %d/%d
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_VIEW_SYNTAX(en_us)
Syntax:
 // SESSION VIEW host
+OS_SESSION_VIEW_SYNTAX(nl)
Syntax:
  // SESSION VIEW host
+OS_SESSION_VIEW_SYNTAX(de)
Syntax:
  // SESSION VIEW Host
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_VIEW_HEADER_X(en_us)
***** Users connected from \B%s\B *****
+OS_SESSION_VIEW_HEADER_X(nl)
**** Gebruikers verbonden van \B%s\B *****
+OS_SESSION_VIEW_HEADER_X(de)
**** Benutzer die von \B%s\B kommen *****
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_VIEW_TAIL(en_us)
********************************
+OS_SESSION_VIEW_TAIL(nl)
****************************************
+OS_SESSION_VIEW_TAIL(de)
****************************************
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_VIEW_X_NOT_FOUND(en_us)
There are no users connected from \B%s\B !
+OS_SESSION_VIEW_X_NOT_FOUND(nl)
Er zijn geen gebruikers verbonden vanaf \B%s\B !
+OS_SESSION_VIEW_X_NOT_FOUND(de)
Es kommen keine Bentuzer von \B%s\B !
+++++++++++++++++++++++++++++++++++++++++++++
+OS_SESSION_VIEW_ITEM_nick_mask_info(en_us)
  %-20s %s :%s
+OS_SESSION_VIEW_ITEM_nick_mask_info(nl)
  %-20s %s :%s
+OS_SESSION_VIEW_ITEM_nick_mask_info(de)
  %-20s %s :%s
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_SYNTAX(en_us)
Syntax:
  // EXCEPTION ADD owner time host limit reason
  // EXCEPTION DEL host
  // EXCEPTION LIST [mask]
  // EXCEPTION INFO mask
  // EXCEPTION CHANGE old_host new_host
+OS_EXCEPTION_SYNTAX(nl)
Syntax:
  // EXCEPTION ADD eigenaar tijd host limiet reden
  // EXCEPTION DEL host
  // EXCEPTION LIST [mask]
  // EXCEPTION INFO mass
  // EXCEPTION CHANGE old_host new_host
+OS_EXCEPTION_SYNTAX(de)
Syntax:
  // EXCEPTION ADD Besitzer Zeit Host Limit Grund
  // EXCEPTION DEL Host
  // EXCEPTION LIST [Maske]
  // EXCEPTION INFO Maske
  // EXCEPTION CHANGE alter_Host neuer_Host
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_SUMMARY(en_us)
Manage session limit exceptions
+OS_EXCEPTION_SUMMARY(nl)
Beheer sessie limiet uitzonderingen
+OS_EXCEPTION_SUMMARY(de)
Verwaltet Sitzunslimits
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_HELP(en_us)
The command // EXCEPTION allows to add/del/list session limit exceptions.

@OS_EXCEPTION_SYNTAX
+OS_EXCEPTION_HELP(nl)
Het commando EXCEPTION kunt u sessie uitzonderingen 
toevoegen/verwijderen/bekijken.

@OS_EXCEPTION_SYNTAX
+OS_EXCEPTION_HELP(de)
Der EXCEPTION Befehl erlaubt es, Sitzungslimits hinzuzufügen, zu löschen oder anzuzeigen.

@OS_EXCEPTION_SYNTAX
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_LIST_HEADER(en_us)
***** List of exceptions *****
+OS_EXCEPTION_LIST_HEADER(nl)
***** Lijst van uitzonderingen *****
+OS_EXCEPTION_LIST_HEADER(de)
***** Lsite der Ausnahmen *****
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_LIST_TAIL(en_us)
******************************
+OS_EXCEPTION_LIST_TAIL(nl)
*************************************
+OS_EXCEPTION_LIST_TAIL(de)
*************************************
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_LIST_host_slimit_owner_reason(en_us)
  %s %s %s %s
+OS_EXCEPTION_LIST_host_slimit_owner_reason(nl)
  %s %s %s %s
+OS_EXCEPTION_LIST_host_slimit_owner_reason(de)
  %s %s %s %s
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_LIST_host_slimit_count_owner_reason(en_us)
  %s %s (\B%d\B in use) %s %s
+OS_EXCEPTION_LIST_host_slimit_count_owner_reason(pt)  
  %s %s (\B%d\B em uso) %s %s
+OS_EXCEPTION_LIST_host_slimit_count_owner_reason(nl)
  %s %s (\B%d\B in gebruik) %s %s
+OS_EXCEPTION_LIST_host_slimit_count_owner_reason(de)
  %s %s (\B%d\B in Benutzung) %s %s
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_ADD_ALREADY_EXISTS_X(en_us)
There is already an exception for \B%s\B !
+OS_EXCEPTION_ADD_ALREADY_EXISTS_X(nl)
Er isal een uitzondering voor \B%s\B
+OS_EXCEPTION_ADD_ALREADY_EXISTS_X(de)
Es gibt bereits eine Ausnahme für \B%s\B
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_ADD_OK_X(en_us)
Exception for \B%s\B was succesfully added.
+OS_EXCEPTION_ADD_OK_X(nl)
Uitzondering voor \B%s\B is succesvol toegevoegd.
+OS_EXCEPTION_ADD_OK_X(de)
Ausnahme für \B%s\B wurde hinzugefügt.
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_NOT_FOUND_X(en_us)
Exception for \B%s\B was not found !
+OS_EXCEPTION_NOT_FOUND_X(nl)
Uitzondering voor \B%s\B niet gevonden !
+OS_EXCEPTION_NOT_FOUND_X(nl)
Keine Ausnahme für \B%s\B gefunden!
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_DELETED_X(en_us)
Deleted exception for \B%s\B .
+OS_EXCEPTION_DELETED_X(nl)
Uitzondering voor \B%s\B verwijderd.
+OS_EXCEPTION_DELETED_X(de)
Ausnahme für \B%s\B gelöscht.
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_CHANGE_SYNTAX(en_us)
Syntax:

  // EXCEPTION CHANGE old_host new_host
+OS_EXCEPTION_CHANGE_SYNTAX(nl)
Syntax:
   
  // EXCEPTION CHANGE oude_host nieuwe_host
+OS_EXCEPTION_CHANGE_SYNTAX(de)
Syntax:
   
  // EXCEPTION CHANGE alter_Host neuer_Host
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_CHANGE_DENIED(en_us)
You are not allowed to change that exception !
+OS_EXCEPTION_CHANGE_DENIED(pt)
Não lhe é permitido alterar essa excepção !
+OS_EXCEPTION_CHANGE_DENIED(nl)
U heeft geen rechten om de exceptielijst aan te passen!
+OS_EXCEPTION_CHANGE_DENIED(de)
Du besitzt nicht die Rechte, um die Ausnahmeliste zu ändern.!
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_CHANGED(en_us)
The exception host was changed.
+OS_EXCEPTION_CHANGED(nl)
De exceptie van de host is veranderd
+OS_EXCEPTION_CHANGED(de)
Die Ausnahme für den Host wurde geändert.
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_ALREADY_X_EXISTS(en_us)
There is already an exception for \B%s\B !
+OS_EXCEPTION_ALREADY_X_EXISTS(nl)
Er bestaat al een exceptie voot \B%s\B !
+OS_EXCEPTION_ALREADY_X_EXISTS(de)
Es gibt bereits eine Ausnahme für \B%s\B !
+++++++++++++++++++++++++++++++++++++++++++++
+OS_EXCEPTION_INVALID_HOST_X(en_us)
\B%s\B is not a valid hostname !
+OS_EXCEPTION_INVALID_HOST_X(pt)
\B%s\B não é um hostname válido !
+OS_EXCEPTION_INVALID_HOST_X(nl)
\B%s\B is geen geldige hostnaam !
+OS_EXCEPTION_INVALID_HOST_X(de)
\B%s\B ist kein gültiger Hostname!
