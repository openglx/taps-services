++++ ns_set.l
++++ en_us: Lamego, Stinger
++++ nl: Stinger, Ldp
++++ pt: Lamego
++++ pt_br: Ricardo
++++ de: jo

+SET_SUMMARY(en_us)
Changes your nick info/options.
+SET_SUMMARY(pt)
Altera as op��es/informa��es do seu nick.
+SET_SUMMARY(nl)
Stelt u instaat uw bijnaam-info/opties te wijzigen.
+SET_SUMMARY(pt_br)
Altera as op��es/informa��es do seu nick.
+SET_SUMMARY(de)
�ndert die Infos/Optionen f�r deinen Nick.
++++++++++++++++++++++++++++++++++++++++++++
+SET_HELP(en_us)
This commands allows you set your nick options and info.
  Available info:
    EMAIL      - your email
    FAVLINK    - you favorite web page    
    IMID       - instant messaging id
    LANGUAGE   - services messages language    
    LOCATION   - your location
    PASSWORD   - your password
    URL        - your page url


  Switch options, ON/OFF values only

    NONEWS     - enable/disable newsletter reception
    PRIVATE    - hide your info from nickserv info
    HIDEEMAIL  - hide email from nickserv info
    PROTECTED  - nick is protected (needs to LOGIN)
    USEMSG     - services will use messages instead of notices

  Available languages:
    en_us - English
    pt    - Portugu�s (Portuguese)
    nl    - Nederlands (Dutch)
    pt_br - Portugu�s Brasileiro (Brazilian Portuguese)
    de    - Deutsch (German)

+SET_HELP(pt)
O comando SET permite definir as op��es e dados de um nick.
  Op��es d�spon�veis
    EMAIL      - email
    FAVLINK    - a sua p�gina favorita
    IMID       - identifica��o de \"instant messenger\"
    LANGUAGE   - idioma das mensagens de services    
    LOCATION   - local
    PASSWORD   - password do nick
    URL        - webpage do nick


  Op��es para activar/desactivar, o valor tem que ser ON/OFF

    NONEWS     - activa/desactiva recep��o de newsletter
    PRIVATE    - oculta da informa��o no comando INFO
    HIDEEMAIL  - oculta email da informa��o no comando INFO
    PROTECTED  - o nick est� protegido (tem que fazer LOGIN)
    USEMSG     - os servi�os devem utilizar mensagens privadas
    
  Idiomas dispon�veis:
    en_us - English
    pt    - Portugu�s (Portuguese)
    nl    - Nederlands (Dutch)
    pt_br - Portugu�s Brasileiro (Brazilian Portuguese)
    de    - Deutsch (German)

+SET_HELP(nl)
Dit commando stelt u in staat uw bijnaam info/opties te wijzigen.
  Beschikbare informatie:
    EMAIL      - Uw Email
    IMID       - Instant messenger id
    LANGUAGE   - Taal van de services
    LOCATION   - Uw locatie
    PASSWORD   - Uw wachtwoord
    URL        - Uw pagina URL

  Schakel opties, ON/OFF (aan/uit) waarden alleen

    NONEWS     - Schakel nieuwsbrief ontvangen aan/uit
    PRIVATE    - Bijnaam informatie prive houden met nickserv info
    HIDEEMAIL  - E-mail prive houden met nickserv info
    PROTECTED  - nick is protected (needs to LOGIN)
    USEMSG     - services will use messages instead of notices

  Beschikbare talen:
    en_us - English
    pt    - Portugu�s (Portuguese)
    nl    - Nederlands (Dutch)
    pt_br - Portugu�s Brasileiro (Brazilian Portuguese)
    de    - Deutsch (German)

+SET_HELP(pt_br)
O comando SET permite definir as op��es e informa��es do seu nick.
  Informa��es dispon�veis:
    EMAIL      - Seu email
    IMID       - Identifica��o de \"Instant Messenger\"
    LANGUAGE   - Idioma das mensagens dos Services
    LOCATION   - Sua localiza��o
    PASSWORD   - Senha do nick
    URL        - Webpage do nick

  Ativa ou desativa as op��es, o valor deve ser ON/OFF

    NONEWS     - Ativa/desativa recebimento de newsletter (not�cias)
    PRIVATE    - Oculta suas informa��es no comando INFO
    HIDEEMAIL  - Oculta seu email no comando INFO

  Idiomas dispon�veis:
    en_us - English
    pt    - Portugu�s (Portuguese)
    nl    - Nederlands (Dutch)
    pt_br - Portugu�s Brasileiro (Brazilian Portuguese)
    de    - Deutsch (German)
    
+SET_HELP(de)
Der Befehl SET erlaubt dir das �ndern der Infos und Optionen zu deinem Nick.

  M�gliche Infos:
    EMAIL      - Deine Emailadresse
    IMID       - Instant Messenger ID
    LANGUAGE   - Sprache f�r die Services
    LOCATION   - Ort
    PASSWORD   - Passwort
    URL        - Deine Homepage

  Optionen mit Schalterfunktion, nur ON/OFF (Ein/Aus) Werte sind m�glich:

    NONEWS     - Newsletterempfang ein-/ausschalten.
    PRIVATE    - Infos werden bei nickserv info nicht angezeigt (du selbst siehst sie trotzdem)
    HIDEEMAIL  - Deine Emailadresse wird bei nickserv info nicht angezeigt
    PROTECTED  - Der Nick ist gesch�tzt. (ben�tigt LOGIN)
    USEMSG     - Services verwenden Messages und und keine Notizen

  M�glische Sprachen:
    en_us - English
    pt    - Portugu�s (Portuguese)
    nl    - Nederlands (Dutch)
    pt_br - Portugu�s Brasileiro (Brazilian Portuguese)
    de    - Deutsch (German)

++++++++++++++++++++++++++++++++++++++++++++
+NICK_SET_SYNTAX(en_us)
Syntax:
  // SET option value
  For a list of available options use // HELP SET
+NICK_SET_SYNTAX(pt)
Sintaxe:
  // SET op��o valor
  Para listar as op��es dispon�veis digite: 
  // HELP SET
+NICK_SET_SYNTAX(nl)
Syntax:
  // SET optie waarde
  Voor een lijst van beschikbare opties gebruik // HELP SET
+NICK_SET_SYNTAX(pt_br)
Sintaxe:
  // SET op��o valor
  Para listar as op��es dispon�veis, digite: 
  // HELP SET
+NICK_SET_SYNTAX(de)
Syntax:
  // SET Option Wert
  Eine Liste der m�glichen Optionen erh�lst du mit // HELP SET
++++++++++++++++++++++++++++++++++++++++++++
+URL_CHANGED_TO_X(en_us)
The url was changed to \B%s\B.
+URL_CHANGED_TO_X(pt)
O url foi alterado para \B%s\B.
+URL_CHANGED_TO_X(nl)
De URL is veranderd naar \B%s\B.
+URL_CHANGED_TO_X(pt_br)
A URL foi alterada para \B%s\B.
+URL_CHANGED_TO_X(de)
Deine URL wurde ge�ndert in \B%s\B.
++++++++++++++++++++++++++++++++++++++++++++
+FAVLINK_CHANGED_TO_X(en_us)
The favorite link was changed to \B%s\B.
+FAVLINK_CHANGED_TO_X(pt)
O link favorito foi alterado para \B%s\B.
+FAVLINK_CHANGED_TO_X(nl)
De favoriete link is veranderd naar \B%s\B.
+FAVLINK_CHANGED_TO_X(de)
Dein empfohlener Link wurde ge�ndert in \B%s\B.
++++++++++++++++++++++++++++++++++++++++++++
+EMAIL_REQUEST_TO_X(en_us)
The email change request was sent to \B%s\B.
Please check the email and use the auth code to confirm.
+EMAIL_REQUEST_TO_X(pt)
O pedido de altera��o de email foi enviado para \B%s\B.
Por favor verifique o seu email para confirmar.
+EMAIL_REQUEST_TO_X(nl)
Het email-veranderingsverzoek is verstuurd naar \B%s\B.
Controleer uw email en gebruik de authenticatie code om het te bevestigen.
+EMAIL_REQUEST_TO_X(pt_br)
O pedido de altera��o de email foi enviado para \B%s\B.
Por favor, verifique o email e use o c�digo AUTH para confirmar.
+EMAIL_REQUEST_TO_X(de)
Die Anfrage zur �nderung der Email wurde an \B%s\B geschickt.
Bitte checke die Email und verwende den enthaltenen Authentifizierungscode zur Best�tigung.
++++++++++++++++++++++++++++++++++++++++++++
+EMAIL_CHANGED_TO_X(en_us)
The email was changed to \B%s\B.
+EMAIL_CHANGED_TO_X(pt)
O email foi alterado para \B%s\B.
+EMAIL_CHANGED_TO_X(nl)
Email is veranderd naar \B%s\B.
+EMAIL_CHANGED_TO_X(pt_br)
O email foi alterado para \B%s\B.
+EMAIL_CHANGED_TO_X(de)
Die Email wurde ge�ndert in \B%s\B.
++++++++++++++++++++++++++++++++++++++++++++
+URL_UNSET(en_us)
The url is unset.
+URL_UNSET(pt)
O url foi removido.
+URL_UNSET(nl)
De URL is verwijderd.
+URL_UNSET(pt_br)
A URL foi removida.
+URL_UNSET(de)
Die URL ist gel�scht.
++++++++++++++++++++++++++++++++++++++++++++
+FAVLINK_UNSET(en_us)
The favorite link is unset.
+FAVLINK_UNSET(pt)
vO link favorito foi removido.
+FAVLINK_UNSET(nl)
De favoriete link is verwijderd.
+FAVLINK_UNSET(de)
Dein empfohlener Link wurde gel�scht.
++++++++++++++++++++++++++++++++++++++++++++
+CANT_EMAIL_UNSET(en_us)
Sorry, you can only change the email, not remove.
+CANT_EMAIL_UNSET(pt)
N�o pode remover o email, apenas o pode alterar
+CANT_EMAIL_UNSET(nl)
Sorry, kan het emailadres niet verwijderen
+CANT_EMAIL_UNSET(pt_br)
Desculpe, voc� n�o pode remover o email, apenas pode alter�-lo.
+CANT_EMAIL_UNSET(de)
Sorry, die Emailadresse kann nur ge�ndert aber nicht gel�scht werden.
++++++++++++++++++++++++++++++++++++++++++++
+UNKNOWN_OPTION_X(en_us)
\B%s\B is not a valid option, please check the available
options with // HELP SET.
+UNKNOWN_OPTION_X(pt)
\B%s\B n�o � uma op��o v�lida!
Veja as op��es dispon�veis digitando:
  // HELP SET.
+UNKNOWN_OPTION_X(nl)
\B%s\B is geen geldige optie. Voor een lijst van beschikbare
opties, bekijk // HELP SET
+UNKNOWN_OPTION_X(pt_br)
\B%s\B n�o � uma op��o v�lida. Por favor, veja as op��es
dispon�veis, digitando: // HELP SET
+UNKNOWN_OPTION_X(de)
\B%s\B ist keine g�ltige Option. Eine Liste der m�glichen Optionen
erh�lst du unter // HELP SET
++++++++++++++++++++++++++++++++++++++++++++
+LOCATION_UNSET(en_us)
The location is unset.
+LOCATION_UNSET(pt)
O local foi removido.
+LOCATION_UNSET(nl)
De locatie is verwijderd.
+LOCATION_UNSET(pt_br)
A localiza��o foi removida.
+LOCATION_UNSET(de)
Die Ortsangabe ist gel�scht.
++++++++++++++++++++++++++++++++++++++++++++
+LOCATION_CHANGED_TO_X(en_us)
The location was changed to \B%s\B.
+LOCATION_CHANGED_TO_X(pt)
O local foi alterado para \B%s\B.
+LOCATION_CHANGED_TO_X(nl)
De locatie is veranderd naar \B%s\B.
+LOCATION_CHANGED_TO_X(pt_br)
A localiza��o foi alterada para \B%s\B.
+LOCATION_CHANGED_TO_X(de)
Die Ortsangabe wurde in \B%s\B ge�ndert.
++++++++++++++++++++++++++++++++++++++++++++
+OPTION_X_ON(en_us)
The %s option is now \BON\B.
+OPTION_X_ON(pt)
A op��o %s foi \Bactivada\B.
+OPTION_X_ON(nl)
De optie %s is nu \BON\B (aan).
+OPTION_X_ON(pt_br)
A op��o %s foi \Bativada\B.
+OPTION_X_ON(de)
Die Option %s ist jetzt \BON\B (Ein).
++++++++++++++++++++++++++++++++++++++++++++
+OPTION_X_OFF(en_us)
The %s option is now \BOFF\B.
+OPTION_X_OFF(pt)
A op��o %s foi \Bdesactivada\B.
+OPTION_X_OFF(nl)
De optie %s is nu \BOFF\B (uit).
+OPTION_X_OFF(pt_br)
A op��o %s foi \Bdesativada\B.
+OPTION_X_OFF(de)
Die Option %s ist jetzt \BOFF\B (Aus).
++++++++++++++++++++++++++++++++++++++++++++
+VALUE_ON_OR_OFF(en_us)
The value for this option must be \BON\B or \BOFF\B.
+VALUE_ON_OR_OFF(pt)
O valor para esta op��o tem que ser \BON\B ou \BOFF\B.
+VALUE_ON_OR_OFF(nl)
De waarde voor deze optie moet \BON\B (aan) of \BOFF\B (uit) zijn.
+VALUE_ON_OR_OFF(pt_br)
O valor para esta op��o deve ser \BON\B ou \BOFF\B.
+VALUE_ON_OR_OFF(de)
Der Wert f�r diese Option kann nur \BON\B (Ein) oder \BOFF\B (Aus) sein.
++++++++++++++++++++++++++++++++++++++++++++
+INVALID_LANGUAGE_X(en_us)
\B%s\B is not a valid language,
Valid languages are:
    en_us - English (United States)
    pt    - Portuguese
    nl    - Nederlands (Dutch)
    pt_br - Portuguese Brazil
    de    - Deutsch(German)
+INVALID_LANGUAGE_X(pt)
\B%s\B n�o � um idioma v�lido.
Os idiomas v�lidos s�o:
    en_us - English (United States)
    pt    - Portuguese
    nl    - Nederlands (Dutch)
    pt_br - Portuguese Brazil
    de    - Deutsch (German)
+INVALID_LANGUAGE_X(nl)
\B%s\B is geen beschikbare taal
Beschikbare talen zijn:
    en_us - Engels (United States)
    pt    - Portugees (Portuguese)
    nl    - Nederlands (Dutch)
    pt_br - Portuguese Brazil
    de    - Deutsch (German)
+INVALID_LANGUAGE_X(pt_br)
\B%s\B n�o � um idioma v�lido.
Os idiomas v�lidos s�o:
    en_us - English (United States)
    pt    - Portuguese (Portugal)
    nl    - Nederlands (Dutch)
    pt_br - Portuguese Brazil
    de    - Deutsch (German)
+INVALID_LANGUAGE_X(de)
\B%s\B ist keine g�ltige Sprache.
M�gliche Sprachen sind:
    en_us - English (United States)
    pt    - Portuguese
    nl    - Nederlands (Dutch)
    pt_br - Portuguese Brazil
    de    - Deutsch (German)
++++++++++++++++++++++++++++++++++++++++++++
+LANGUAGE_CHANGED_TO_X(en_us)
Language changed to \B%s\B.
+LANGUAGE_CHANGED_TO_X(pt)
Idioma alterado para \B%s\B.
+LANGUAGE_CHANGED_TO_X(nl)
Taal veranderd naar \B%s\B.
+LANGUAGE_CHANGED_TO_X(pt_br)
Idioma alterado para \B%s\B.
+LANGUAGE_CHANGED_TO_X(de)
Sprache ge�ndert in \B%s\B.
++++++++++++++++++++++++++++++++++++++++++++
+SSET_SUMMARY(en_us)
Super SET (For SAdmins only)
+SSET_SUMMARY(pt)
Super SET (Apenas para SAdmins)
+SSET_SUMMARY(nl)
Super SET (Alleen SAdmins)
+SSET_SUMMARY(pt_br)
Super SET (Apenas para SAdmins)
+SSET_SUMMARY(de)
Super SET (Nur f�r SAdmins)
++++++++++++++++++++++++++++++++++++++++++++
+SSET_HELP(en_us)
Allows to change settings for a specified nick.
Syntax:
  // SSET nick option value
Available options:
 All options from // HELP SET
+SSET_HELP(pt)
Permite alterar as configura��es do nick especificado.
Sintaxe:
  // SSET nick op��o valor
Op��es dispon�veis:
 Todas as op��es do // HELP SET 
+SSET_HELP(nl)
Stelt u instaat opties voor een gegeven bijnaam te wijzigen
  // SSET bijnaam optie waarde
Beschikbare opties:
 Alle opties uit // HELP SET
+SSET_HELP(pt_br)
Permite alterar as configura��es do nick especificado.
Sintaxe:
  // SSET nick op��o valor
Op��es dispon�veis:
 Todas as op��es de // HELP SET
+SSET_HELP(de)
Erlaubt das �ndern der Einstellungen f�r einen Nick.
Syntax:
  // SSET Nick Option Wert
M�gliche Optionen:
 Alle Options aus // HELP SET
++++++++++++++++++++++++++++++++++++++++++++
+NICK_X_NOT_FOUND(en_us)
Nick \B%s\B is not a registered nick.
+NICK_X_NOT_FOUND(pt)
O nick \B%s\B n�o est� registrado.
+NICK_X_NOT_FOUND(nl)
De bijnaam \B%s\B is niet geregistreerd
+NICK_X_NOT_FOUND(pt_br)
O nick \B%s\B n�o est� registrado.
+NICK_X_NOT_FOUND(de)
Der Nick \B%s\B ist nicht registriert.
++++++++++++++++++++++++++++++++++++++++++++
+NICK_SSET_SYNTAX(en_us)
Syntax:
  // SSET nick option value
  For a list of available options use /NickServ HELP SSET  
+NICK_SSET_SYNTAX(pt)
Sintaxe:
  // SSET nick op��o valor
  Para uma lista das op��es dispon�veis utilize /NickServ HELP SSET  
+NICK_SSET_SYNTAX(nl)
Syntax:
  // SET nick optie waarde
  Voor een lijst van beschikbare opties bekijk /NickServ HELP SSET
+NICK_SSET_SYNTAX(pt_br)
Sintaxe:
  // SSET nick op��o valor
  Para uma lista das op��es dispon�veis use /NickServ HELP SSET
+NICK_SSET_SYNTAX(de)
Syntax:
  // SSET Nick Option Wert
  Die Liste der m�glichen Optionen erh�lst du unter /NickServ HELP SSET  
++++++++++++++++++++++++++++++++++++++++++++
+IMID_UNSET(en_us)
The IMID is unset.
+IMID_UNSET(pt)
O IMID foi removido.
+IMID_UNSET(nl)
De IMID is verwijderd
+IMID_UNSET(pt_br)
O IMID foi removido.
+IMID_UNSET(de)
Die IMID ist gel�scht.
++++++++++++++++++++++++++++++++++++++++++++
+IMID_CHANGED_TO_X(en_us)
IMID was changed to \B%s\B
+IMID_CHANGED_TO_X(pt)
IMID foi alterado para \B%s\B
+IMID_CHANGED_TO_X(nl)
De IMID is veranderd naar \B%s\B
+IMID_CHANGED_TO_X(pt_br)
IMID foi alterado para \B%s\B
+IMID_CHANGED_TO_X(de)
IMID ge�ndert in \B%s\B
++++++++++++++++++++++++++++++++++++++++++++
+PASSWORD_CHANGED_TO_X(en_us)
The password has been changed to \B%s\B
+PASSWORD_CHANGED_TO_X(pt)
Password alterada para \B%s\B
+PASSWORD_CHANGED_TO_X(nl)
Het wachtwoord is veranderd naar \B%s\B
+PASSWORD_CHANGED_TO_X(pt_br)
Senha alterada para \B%s\B
+PASSWORD_CHANGED_TO_X(de)
Das Passwort wurde ge�ndert in \B%s\B
++++++++++++++++++++++++++++++++++++++++++++
+MANDATORY_PASSWORD(en_us)
Nick password is a mandatory. This can not be unset.
+MANDATORY_PASSWORD(pt)
A password � obrigat�ria. N�o pode ser removida.
+MANDATORY_PASSWORD(nl)
Bijnaam-wachtwoord is verplicht. U kunt deze niet verwijderen
+MANDATORY_PASSWORD(pt_br)
A senha do nick � obrigat�ria. N�o pode ser removida.
+MANDATORY_PASSWORD(de)
Ein Passwort f�r einen Nick ist Pflicht. Kann nicht gel�scht werden.
++++++++++++++++++++++++++++++++++++++++++++
+SET_EMAIL_SECURITY_REQUIRED(en_us)
The current email is authenticated.
You need to provide your nick security code to change it.
The syntax is:
  // SET EMAIL email securitycode
+SET_EMAIL_SECURITY_REQUIRED(pt)
O endere�o de email actual est� autenticado.
� necess�rio utilizar o c�digo de seguran�a do nick para alterar
o email, a sintaxe correcta �:
  // SET EMAIL email c�digodeseguran�a
+SET_EMAIL_SECURITY_REQUIRED(nl)
Het huidige emailadres is geauthenticeerd.
U heeft uw bijnaam-beveilingscode nodig om het email adres te
kunnen veranderen.
De syntax is:
  // SET EMAIL emailadres beveiligingscode
+SET_EMAIL_SECURITY_REQUIRED(pt_br)
O endere�o de email atual est� autenticado.
� necess�rio utilizar o c�digo de seguran�a do nick para alter�-lo.
A sintaxe �:
  // SET EMAIL email C�digoDeSeguran�a
+SET_EMAIL_SECURITY_REQUIRED(de)
Die jetzige Emailadresse ist authentifiziert.
Du ben�tigst den Sicherheitscode f�r deinen Nick um die Emailadresse zu �ndern.
Die Syntax lautet:
  // SET EMAIL Email Sicherheitscode
++++++++++++++++++++++++++++++++++++++++++++
+PASSWORD_CHANGED_FOR_X_TO_X(en_us)
Password for \B%s\B has been changed to \B%s\B .
+PASSWORD_CHANGED_FOR_X_TO_X(nl)
Wachtwoord voor \B%s\B is veranderd naar \B%s\B .
+PASSWORD_CHANGED_FOR_X_TO_X(de)
Das Passwort f�r \B%s\B wurde ge�ndert in \B%s\B .
++++++++++++++++++++++++++++++++++++++++++++
+VHOST_UNSET(en_us)
The VHOST was removed.
+VHOST_UNSET(pt)
O VHOST foi removido.
+VHOST_UNSET(nl)
De VHOST is verwijderd.
+VHOST_UNSET(de)
Der VHOST wurde gel�scht.
++++++++++++++++++++++++++++++++++++++++++++
+VHOST_CHANGED_TO_X(en_us)
VHOST was changed to \B%s\B
+VHOST_CHANGED_TO_X(nl)
VHOST is veranderd naar \B%s\B
+VHOST_CHANGED_TO_X(pt)
O VHOST foi alterado para \B%s\B .
+VHOST_CHANGED_TO_X(de)
VHOST wurede ge�ndert in \B%s\B.
++++++++++++++++++++++++++++++++++++++++++++
+URL_NEEDS_HTTP(en_us)
URL must start with \Bhttp://\B !
+URL_NEEDS_HTTP(pt)
O link tem que come�ar com \Bhttp://\B !
+URL_NEEDS_HTTP(nl)
URL moet beginnen met \Bhttp://\B !
+URL_NEEDS_HTTP(de)
Die URL muss mit \Bhttp://\B beginnne!
++++++++++++++++++++++++++++++++++++++++++++
+NS_SET_INVALID_HOST_X(en_us)
\B%s\B is not a valid hostname !
+NS_SET_INVALID_HOST_X(nl)
\B%s\B is geen geldige hostnaam !
+NS_SET_INVALID_HOST_X(de)
\B%s\B ist kein g�ltiger Hostname!
