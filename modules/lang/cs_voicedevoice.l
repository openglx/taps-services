++++ voice_devoice.l
++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ pt: Lamego
++++ pt_br: openglx
++++ de: jo

+VOICE_SUMMARY(en_us)
Command to give channel voice status to a user
+VOICE_SUMMARY(pt)
Comando para dar voice a um utilizador.
+VOICE_SUMMARY(nl)
Commando om een gebruiker voice-status 
te geven.
+VOICE_SUMMARY(pt_br)
Comando para dar voice a um usu�rio.
+VOICE_SUMMARY(de)
Befehl, um einem Benutzer das VOICE-Recht (=darf sprechen) f�r einen Channel zu erteilen.
+++++++++++++++++++++++++++++++++++++++++++++
+DEVOICE_SUMMARY(en_us)
Command to remove channel voice from a user
+DEVOICE_SUMMARY(pt)
Comando para remover o voice a um utilizador.
+DEVOICE_SUMMARY(nl)
Commando om de voice-status van een gebruiker
af te nemen.
+DEVOICE_SUMMARY(pt_br)
Comando para remover o voice de um usu�rio.
+DEVOICE_SUMMARY(de)
Der Befehl entzieht einem Benutzer das Recht, in einem Channel zu sprechen.
+++++++++++++++++++++++++++++++++++++++++++++
+VOICE_HELP(en_us)
The VOICE command will give voice status to a user
using chanserv.
Syntax:
  // VOICE #Chan nick
+VOICE_HELP(pt)
O comando VOICE dar� o status de voice a um utilizador
utilizando o chanserv.
Sintaxe:
  // VOICE #Chan nick  
+VOICE_HELP(nl)
Het VOICE commando geeft voice-status aan een
gebruiker met behulp van chanserv.
Syntax:
  // VOICE #kanaal bijnaam
+VOICE_HELP(pt_br)
O comando VOICE dar� o status de voice a um usu�rio
utilizando o chanserv.
Sintaxe:
  // VOICE #Canal nick
+VOICE_HELP(de)
Der VOICE Befehl erteilt mittels Chanserv einem User das Recht, in einem Channel zu sprechen.
Syntax:
  // VOICE #Channel Nick
+++++++++++++++++++++++++++++++++++++++++++++
+DEVOICE_HELP(en_us)
The DEVOICE command will remove voice status from a user
using chanserv.
Syntax:
  // DEVOICE #Chan nick
+DEVOICE_HELP(pt)
O comando DEVOICE ir� retirar o status de voice de um utilizador
utilizando o chanserv.
Sintaxe:
  // DEVOICE #Chan nick  
+DEVOICE_HELP(nl)
Het DEVOICE commando verwijderd de operator status 
van een bijnaam met behulp van chanserv.
Syntax:
 // DEVOICE #kanaal bijnaam
+DEVOICE_HELP(pt_br)
O comando DEVOICE ir� retirar o status de voice de um usu�rio
utilizando o chanserv.
Sintaxe:
  // DEVOICE #Canal nick
+DEVOICE_HELP(de)
Der DEVOICE Befehl entzieht mittels Chanserv einem User das Recht, in einem Channel zu sprechen.
Syntax:
  // DEVOICE #Channel Nick
+++++++++++++++++++++++++++++++++++++++++++++
+CHAN_VOICE_SYNTAX(en_us)
Invalid Syntax!
Syntax:
  // VOICE #Chan nick
+CHAN_VOICE_SYNTAX(pt)
Sintaxe inv�lida!
Sintaxe:
  // VOICE #canal nick  
+CHAN_VOICE_SYNTAX(nl)
Ongeldige syntax!
Syntax:
  // VOICE #kanaal bijnaam
+CHAN_VOICE_SYNTAX(pt_br)
Sintaxe inv�lida!
Sintaxe:
  // VOICE #Canal nick
+CHAN_VOICE_SYNTAX(de)
Ung�ltige Syntax!
Syntax:
  // VOICE #Channel Nick
+++++++++++++++++++++++++++++++++++++++++++++
+CHAN_DEVOICE_SYNTAX(en_us)
Invalid Syntax!
Syntax:
  // DEVOICE #Chan nick
+CHAN_DEVOICE_SYNTAX(pt)
Sintaxe inv�lida!
Sintaxe:
  // DEVOICE #Chan nick  
+CHAN_DEVOICE_SYNTAX(nl)
Ongeldige syntax!
Syntax:
  // DEVOICE #kanaal bijnaam    
+CHAN_DEVOICE_SYNTAX(pt_br)
Sintaxe inv�lida!
Sintaxe:
  // DEVOICE #Canal nick
+CHAN_DEVOICE_SYNTAX(de)
Ung�ltige Syntax!
Syntax:
  // DEVOICE #Channel Nick
+++++++++++++++++++++++++++++++++++++++++++++  
+NO_VOICEDEVOICE_PERM_ON_X(en_us)
You don't have VOICE/DEVOICE permission on \B%s\B !
+NO_VOICEDEVOICE_PERM_ON_X(pt)
Voc� n�o tem permiss�o para utilizar VOICE/DEVOICE no \B%s\B !
+NO_VOICEDEVOICE_PERM_ON_X(nl)
U heeft geen VOICE/DEVOICE permissie op \B%s\B !
+NO_VOICEDEVOICE_PERM_ON_X(pt_br)
Voc� n�o tem permiss�o para utilizar VOICE/DEVOICE no \B%s\B!
+NO_VOICEDEVOICE_PERM_ON_X(de)
Da hast keine Rechte f�r VOICE/DEVOICE in \B%s\B!
+++++++++++++++++++++++++++++++++++++++++++++
+CANT_DEVOICE_ADMIN_X_ON_X(en_us)
You can't devoice \B%s\B, this nick has admin status on \B%s\B.
+CANT_DEVOICE_ADMIN_X_ON_X(pt)
Voc� n�o pode tirar o voice de \B%s\B, este nick � um administrador no \B%s\B.
+CANT_DEVOICE_ADMIN_X_ON_X(nl)
U kunt de voice-status van \B%s\B niet verwijderen,
deze heeft admin status op %s.
+CANT_DEVOICE_ADMIN_X_ON_X(pt_br)
Voc� n�o pode tirar o voice de \B%s\B, este nick possui status de administrador no \B%s\B.
+CANT_DEVOICE_ADMIN_X_ON_X(de)
Du kannst kein DEVOICE f�r \B%s\B ausf�hren. Der Benutzer ist Admin in \B%s\B.
+++++++++++++++++++++++++++++++++++++++++++++
+NICK_X_ALREADY_VOICE_ON_X(en_us)
\B%s\B is already voice on \B%s\B!
+NICK_X_ALREADY_VOICE_ON_X(pt)
\B%s\B j� tem voice no \B%s\B!
+NICK_X_ALREADY_VOICE_ON_X(nl)
\B%s\B heeft al voice op \B%s\B!
+NICK_X_ALREADY_VOICE_ON_X(pt_br)
\B%s\B j� tem voice no \B%s\B!
+NICK_X_ALREADY_VOICE_ON_X(de)
\B%s\B hat bereits VOICE-Rechte in \B%s\B!
+++++++++++++++++++++++++++++++++++++++++++++
+NICK_X_NOT_VOICE_ON_X(en_us)
\B%s\B is not voice on \B%s\B!
+NICK_X_NOT_VOICE_ON_X(pt)
\B%s\B n�o tem voice no \B%s\B!
+NICK_X_NOT_VOICE_ON_X(nl)
\B%s\B is geen voice op \B%s\B!
+NICK_X_NOT_VOICE_ON_X(pt_br)
\B%s\B n�o tem voice no \B%s\B!
+NICK_X_NOT_VOICE_ON_X(de)
\B%s\B hat keine VOICE-Rechte in \B%s\B!