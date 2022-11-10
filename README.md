# PSOP-Debugger

Scopul aplicației:
-	Lansarea, oprirea și continuarea execuției unui proces
-	Posibilitaea de punere breakpoint-uri (pe adresă de memorie, pe o linie de cod, pe un apel de funcție)
-	Posibilitate de vizualizare de memorie
-	Modificare variabile la run-time
-	Derulare pas cu pas a fiecărei instrucțiuni cu posibilitatea de a sări peste apelurile de funcție sau de a intra în interiorul execuției funcțiilor
-	Printare locația curentă a sursei
-	Afișare backtrace

###	Vom crea o aplicație în C/C++ care vom lua ca argument un fișier executabil pe care îl vom lansa pentru a-i putea observa și controla execuția prin funcționalitățile menționate mai sus.

###	Vom folosi utilitarul ptrace.
