++++ nickserv.l
++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ pt: Lamego
++++ pt_br: Ricardo
++++ de: jo

+NICK_IS_REGISTERED(en_us)
This nickname is registered and protected.  If it is your
nick, type \B// IDENTIFY password\B.  Otherwise,
please choose a different nick.
+NICK_IS_REGISTERED(pt)
Este nick est� registado. Se � teu identifica-te com
    \B// IDENTIFY password\B
+NICK_IS_REGISTERED(nl)
Deze bijnaam is geregistreerd. Als dit uw bijnaam is identificeer uzelf dan met
    \B// IDENTIFY wachtwoord\B
Indien dit niet uw bijnaam is, kies een andere bijnaam
+NICK_IS_REGISTERED(pt_br)
Este nick est� registrado e protegido. Se for seu, digite
\B// IDENTIFY senha\B. Caso contr�rio, por favor
escolha um nick diferente.
+NICK_IS_REGISTERED(de)
Dieser Nick ist registriert und gesch�tzt. Wenn es dein Nick ist,
identifiziere dich mittels \B// IDENTIFY password\B.  Wenn nicht,
w�hle bitte einen anderen Nick.
+++++++++++++++++++++++++++++++++++++++++++++
+NICK_IS_NOT_REGISTERED(en_us)
This nick is not registered. If you want to keep it
please register it with \B// REGISTER password email\B.
+NICK_IS_NOT_REGISTERED(pt)
Este nick n�o est� registado. Se o pretendes utilizar no futuro
efectua o seu registo com  \B// REGISTER password email\B.
+NICK_IS_NOT_REGISTERED(nl)
Deze bijnaam is niet geregistreerd, als u deze wilt behouden kunt
u hem registreren met \B// REGISTER wachtwoord email-adres\B.
+NICK_IS_NOT_REGISTERED(pt_br)
Este nick n�o est� registrado. Se voc� pretende utiliz�-lo no futuro,
por favor registre-o com \B// REGISTER senha email\B.
+NICK_IS_NOT_REGISTERED(de)
Dieser Nick ist noch nicht registriert. Falls du ihn behalten und
f�r dich sichern willst verwende bitte: \B// REGISTER password email\B.
+++++++++++++++++++++++++++++++++++++++++++++
+CHANGE_IN_1M(en_us)
If you do not identify your nick will be changed in 1 minute.
+CHANGE_IN_1M(pt)
Se n�o identificar o seu nick ser� alterado dentro de 1 minuto.
+CHANGE_IN_1M(nl)
Als u zich niet identificeert, dan wordt uw nick over 1 minuut veranderd.
+CHANGE_IN_1M(pt_br)
Se voc� n�o identificar o seu nick, ele ser� alterado dentro de 1 minuto.
+CHANGE_IN_1M(de)
Wenn Du diesen Nick nicht innerhalb von 1 Minute identifziert, wird dein Nick ge�ndert.
++++++++++++++++++++++++++++++++++++++++++++
+NICK_IS_PROTECTED(en_us)
The nick you were trying is protected, please choose another nick,
or login with the nick using the command:
  \B// LOGIN nick password\B
+NICK_IS_PROTECTED(pt)
O nick que estava a utilizar est� protegido, escolha outro nick
ou mude para o nick utilizando o comando:
  \B// LOGIN nick password\B
+NICK_IS_PROTECTED(nl)
De bijnaam die u probeert is beschermt, kies een andere bijnaam,
of login met de bijnaam door het volgende commando uit te voeren:
  \B// LOGIN bijnaam wachtwoord\B
+NICK_IS_PROTECTED(de)
Dieser Nick ist gesch�tzt. Bitte w�hle einen anderen oder melde dich 
mit folgendem Befehl an:
  \B// LOGIN Nick Passwort\B
++++++++++++++++++++++++++++++++++++++++++++
+NICK_PASSWORD_EXPIRED(en_us)
\BYour nick password has expired!\B
Please change your password with:
   \B// SET PASSWORD password\B
+NICK_PASSWORD_EXPIRED(pt)
\BA password do seu nick expirou!\B
Defina uma nova password com o comando:
  \B// SET PASSWORD password\B
+NICK_PASSWORD_EXPIRED(nl)
\BHet wachtwoord van uw bijnaam is verlopen!\B
Verander het wachtwoord met:
  \B// SET PASSWORD wachtwoord\B
+NICK_PASSWORD_EXPIRED(de)
\BDas Passwort f�r den Nick ist abgelaufen!\B
Bitte �ndere das Passwort mittels:
   \B// SET PASSWORD password\B
++++++++++++++++++++++++++++++++++++++++++++   
+NICK_X_IS_SUSPENDED(en_us)
Nick \B%s\B is suspended.
+NICK_X_IS_SUSPENDED(pt)
O nick \B%s\B est� suspenso.
+NICK_X_IS_SUSPENDED(nl)
Bijnaam \B%s\B is geschorst
+NICK_X_IS_SUSPENDED(de)
Der Nickname \B%s\B ist gesperrt
++++++++++++++++++++++++++++++++++++++++++++
+NICK_X_IS_SUSPENDED_X(en_us)
Nick \B%s\B is suspended, reason: %s
+NICK_X_IS_SUSPENDED_X(pt)
O nick \B%s\B est� suspenso, motivo: %s
+NICK_X_IS_SUSPENDED_X(nl)
Bijnaam \B%s\B is geschorst, reden: %s
+NICK_X_IS_SUSPENDED_X(de)
Der Nickname \B%s\B ist gesperrt. Grund: %s
++++++++++++++++++++++++++++++++++++++++++++
+NICK_IS_SUSPENDED(en_us)
The nick you were trying to use is suspended !
+NICK_IS_SUSPENDED(pt)
O nick que estava a tentar utilizar est� suspenso !
+NICK_IS_SUSPENDED(nl)
De bijnaam die u wilt gebruiken is geschorst !
+NICK_IS_SUSPENDED(de)
Der Nichname, den den versuchst zu benutzen, ist gesperrt!
++++++++++++++++++++++++++++++++++++++++++++
+NS_EXPIRE_ON_OLD(en_us)
Your email is \Bnot\B authenticated!
The nick expire time will not be renewed until you authenticate.
+NS_EXPIRE_ON_OLD(pt)
O seu email ainda \Bn�o\B est� autenticado!
A data em expira o seu nick n�o ser� renovada.
+NS_EXPIRE_ON_OLD(nl)
Uw e-mail is \Bniet\b geauthenticeerd!
De bijnaam verlooptijd wordt niet vernieuwd tot deze is 
geauthenticeerd.
+NS_EXPIRE_ON_OLD(de)
Deine angebenene Emailadresse wurde noch \Bnicht \B authentifiziert!
Ohne Authentifizierung wird die G�ltigkeit deiner Nickregistrierung nicht automatisch verl�ngert.


