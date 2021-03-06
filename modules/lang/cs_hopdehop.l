++++ cs_hopdehop.l
++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ pt: Lamego
++++ de: dp

+HOP_SUMMARY(en_us)
Command to give channel half-oper status to an user
+HOP_SUMMARY(pt)
Comando para dar half-op a um utilizador num canal.
+HOP_SUMMARY(nl)
Commando om een gebruiker half-operator-status 
te geven.
+HOP_SUMMARY(pt_br)
Comando para dar o status de half-operador a um usu�rio em um canal.
+HOP_SUMMARY(de)
Befehl um HalfOp-Status an Benutzer zu vergeben.
+++++++++++++++++++++++++++++++++++++++++++++
+DEHOP_SUMMARY(en_us)
Command to remove channel half-operator from an user
+DEHOP_SUMMARY(pt)
Comando para remover half-op de um utilizador
+DEHOP_SUMMARY(nl)
Commando om de half-operator-status van een gebruiker
af te nemen.
+DEHOP_SUMMARY(pt_br)
Comando para remover o status de half-operador de um usu�rio em um canal.
+DEHOP_SUMMARY(de)
Befehl um einem Benutzer den HalfOp-Status zu nehmen.
+++++++++++++++++++++++++++++++++++++++++++++
+HOP_HELP(en_us)
The HOP command will give half-oper status to a user
using chanserv.
Syntax:
  // HOP #Chan nick
+HOP_HELP(pt)
O comando HOP permite dar half-op a um utilizador
utilizando o chanserv.
Sintaxe:
  // HOP #Canal nick
+HOP_HELP(nl)
Het HOP commando geeft half-operator-status aan een
gebruiker met behulp van chanserv.
Syntax:
  // HOP #kanaal bijnaam
+HOP_HELP(pt_br)
O comando HOP permite dar o status de half-operador a um usu�rio
utilizando o chanserv.
Sintaxe:
  // HOP #Canal nick
+HOP_HELP(de)
Der HOP Befehl gibt einem Benutzer HalfOp-Status mittels ChanServ.
Syntax:
  // HOP #channel nick
+++++++++++++++++++++++++++++++++++++++++++++
+DEHOP_HELP(en_us)
The DEHOP command will remove half-oper status from a user
using chanserv.
Syntax:
  // DEHOP #Chan nick
+DEHOP_HELP(pt)
O comando DEHOP permite remover o half-op a um utilizador
utilizando o chanserv.
Sintaxe:
  // DEHOP #Canal nick
+DEHOP_HELP(nl)
Het DEHOP commando verwijdert de half-operator-status 
van een gebruiker met behulp van chanserv.
Syntax:
 // DEHOP #kanaal bijnaam
+DEHOP_HELP(pt_br)
O comando DEHOP permite remover de um usu�rio o status de half-operador,
utilizando o chanserv.
Sintaxe:
  // DEHOP #Canal nick
+DEHOP_HELP(de)
Der DEHOP Befehl nimmt einem Benutzer mittels ChanServ den HalfOp-Status.
Syntax:
  // DEHOP #channel nick
+++++++++++++++++++++++++++++++++++++++++++++
+CHAN_HOP_SYNTAX(en_us)
Invalid Syntax!
Syntax:
  // HOP #Chan nick
+CHAN_HOP_SYNTAX(pt)
Sintaxe inv�lida!
Sintaxe:
  // HOP #Canal nick
+CHAN_HOP_SYNTAX(nl)
Ongeldige syntax!
Syntax:
  // HOP #kanaal bijnaam
+CHAN_HOP_SYNTAX(pt_br)
Sintaxe inv�lida!
Sintaxe:
  // HOP #Canal nick
+CHAN_HOP_SYNTAX(de)
Ung�ltige Syntax.
Syntax:
  // HOP #channel nick
+++++++++++++++++++++++++++++++++++++++++++++
+CHAN_DEHOP_SYNTAX(en_us)
Invalid Syntax!
Syntax:
  // DEHOP #Chan nick
+CHAN_DEHOP_SYNTAX(pt)
Sintaxe inv�lida!
Sintaxe:
  // DEHOP #Canal nick
+CHAN_DEHOP_SYNTAX(nl)
Ongeldige syntax!
Syntax:
  // DEHOP #kanaal bijnaam    
+CHAN_DEHOP_SYNTAX(pt_br)
Sintaxe inv�lida!
Sintaxe:
  // DEHOP #Canal nick
+CHAN_DEHOP_SYNTAX(de)
Ung�ltige Syntax.
Syntax:
  // DEHOP #channel nick
+++++++++++++++++++++++++++++++++++++++++++++  
+NO_HOPDEHOP_PERM_ON_X(en_us)
You don't have HOP/DEHOP permission on \B%s\B !
+NO_HOPDEHOP_PERM_ON_X(pt)
N�o tem permiss�o de HOP/DEHOP kick no \B%s\B !
+NO_HOPDEHOP_PERM_ON_X(nl)
U heeft geen HOP/DEHOP permissie half-op \B%s\B !
+NO_HOPDEHOP_PERM_ON_X(pt_br)
Voc� n�o tem permiss�o para utilizar HOP/DEHOP no \B%s\B!
+NO_HOPDEHOP_PERM_ON_X(de)
Du hast keine Berechtigung f�r HOP/DEHOP in \B%s\B!
+++++++++++++++++++++++++++++++++++++++++++++
+CANT_DEHOP_ADMIN_X_ON_X(en_us)
You can't dehalfop \B%s\B, he/she has admin status on \B%s\B.
+CANT_DEHOP_ADMIN_X_ON_X(pt)
N�o pode remover o halfop a \B%s\B, ele est� com administrar no \B%s\B.
+CANT_DEHOP_ADMIN_X_ON_X(nl)
U kunt de half-operator status van \B%s\B niet verwijderen,
want deze heeft admin-status op %s.
+CANT_DEHOP_ADMIN_X_ON_X(pt_br)
Voc� n�o pode remover o halfop de \B%s\B, ele possui status de administrador no \B%s\B.
+CANT_DEHOP_ADMIN_X_ON_X(de)
DEHOP nicht m�glich. \B%s\B hat Admin-Status in \B%s\B.
+++++++++++++++++++++++++++++++++++++++++++++
+NICK_X_ALREADY_HOP_ON_X(en_us)
\B%s\B is already halfop on \B%s\B !
+NICK_X_ALREADY_HOP_ON_X(pt)
\B%s\B j� est� com halfop no \B%s\B !
+NICK_X_ALREADY_HOP_ON_X(nl)
\B%s\B is al halfoperator op \B%s\B !
+NICK_X_ALREADY_HOP_ON_X(pt_br)
\B%s\B j� est� com op no \B%s\B!
+NICK_X_ALREADY_HOP_ON_X(de)
\B%s\B ist bereits HOP in \B%s\B!
+++++++++++++++++++++++++++++++++++++++++++++
+NICK_X_NOT_HOP_ON_X(en_us)
\B%s\B is not halfop on \B%s\B !
+NICK_X_NOT_HOP_ON_X(pt)
\B%s\B nao esta com halfop no \B%s\B !
+NICK_X_NOT_HOP_ON_X(nl)
\B%s\B is geen half-operator op \B%s\B !
+NICK_X_NOT_HOP_ON_X(pt_br)
\B%s\B n�o est� com op no \B%s\B!
+NICK_X_NOT_HOP_ON_X(de)
\B%s\B ist kein HOp in \B%s\B!
