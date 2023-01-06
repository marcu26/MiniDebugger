# PSOP-Debugger

Scopul aplicației:
-	Lansarea, oprirea și continuarea execuției unui proces
-	Posibilitaea de punere breakpoint-uri (pe adresă de memorie, pe o linie de cod, pe un apel de funcție)
-	Posibilitate de vizualizare de memorie
-	Modificare variabile la run-time
-	Derulare pas cu pas a fiecărei instrucțiuni cu posibilitatea de a sări peste apelurile de funcție sau de a intra în interiorul execuției funcțiilor
-	Printare locația curentă a sursei
-	Afișare backtrace

###	Vom crea o aplicație în C/C++ care vom lua ca argument un fișier executabil pe care îl vom lansa pentru a-i putea observa și controla execuția prin funcționalitățile menționate mai sus folosind utilitarul PTRACE

###	Usecases:
-   Depanarea de aplicatii pentru verificarea corectitudinii implementarii
-   Scop educativ - invatarea despre workflow-ul unei aplicatii in rulare


### Detalii de implementare
- Vom folosi ptrace cu flag-ul PTRACE_TRACEME in procesul copil pentru a semnaliza ca va fi 'urmarit' de parinte, adica orice semnal va fi transmis acestui
semnal, parintele va fi notificat prin statusul returnat de wait.
- Vom folosi ptrace cu flag-ul PTRACE_GETREGS pentru a obtine intr-o structura user_regs_struct registrii procesorului care executa procesul.
- Vom folosi ptrace cu flag-ul PTRACE_PEEKTEXT pentru a citi un word de la o adresa de memorie specificata, intr-o variabila data.
- Vom folosi ptrace cu flag-ul PTRACE_SINGLESTEP pentru a executa programul instructiune cu instructiune, sistemul de operare oprind executia la urmatoarea
instructiune intalnita.
- Vom folosi ptrace cu flag-ul PTRACE_POKEDATA pentru a scrie date la o anumita adresa de memorie. (ex. setare intrerupere pentru breakpoint).
- Vom folosi ptrace cu flag-ul PTRACE_SYSCALL pentru a face procesul sa se opreasca automat la urmatorul apel de sistem.

### Architectural Diagram
![ArchitecturalDiagram](https://user-images.githubusercontent.com/78821603/201227783-5eb91b0f-4b6f-4550-8df4-9ae4ffe2a4e1.jpeg)

### Executare

- cd build 
- "cmake .." (utilitarul creeaza Makefile)
- make (se creeaza main cu o sursa de test)
- ./main executabil_c/c++
- executabilul trebuie compilat cu flagurile -g-dwarf2 -O0
- g-dwarf2 - o versiune de dwarf mai usor de citit
- O0 - no optimization
