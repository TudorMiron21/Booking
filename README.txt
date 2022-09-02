Pentru indeplinirea temei am abordat o altfel de modalitate de rezolvare in ceea ce priveste unitatile de cazare.
Acestea pot fi de mai multe feluri:-Hotel(format din una sau mai multe camere)  
                                   -Complex de apartamente(format din unul sau mai multe aparatamente)
                                   -Complex de vile(format din una sau mai multe vile)

La randul lor: Aparatamentul(format din una sau mai multe camere)
               Vila(formata din unul sau mai multe apartamente)
Daca administratorul doreste sa adauge doar o singura vila va fi format un complex de vile cu o vila.
Am preferat aceasta modalitate de diferentiere intre unitatile de cazare, inlocuind diferentierea doar prin tipul de clasificare.

Aplicatia are trei interfete : IUnitati_cazare,ICazare,IExceptie.

In ceea ce priveste utilizatorii, am ales sa fac clase care nu deriveaza dintr-o clasa comuna pentru Administrator si User, pentru ca
administratorul este unic in program si am considerat, din acest motiv, ca nu are nevoie de username si parola.

Programul e construit astfel incat utilizatorul trebuie sa aleaga un oras inainte de a alege o unitate de cazare din cadrul acestuia
(administaratorul se ocupa de vectorul de orase si fiecare oras are la randul sau un vector de unitati de cazare).

M-am folosit de doua clase de "populare" pentru a atribui niste valori initiale vectorului de Unitati de cazare si vectorului de orase.

Pentru managementul datelor introduse de useri am folosit clasa Create_time care are diferite functii de transformare(din numar de ore in data de forma zz/ll/aaaa).
O cazare(ex: o camera) este indisponibila doar in perioada de timp precizata de o anumita rezervare.Aceasta suporta mai multe date de rezervare pe perioade diferite.
Se pot adauga doar date reale (ex : nu se poate introduce 78.18.1000),mai mari decat data curenta(nu se pot adauga date mai mici decat ziua de azi).

Un user are posibilitatea de: - a crea un cont 
                              - a se loga intr-un cont deja existent
                              - a da log out
In momentul cand userul este logat acesta poate: - lasa o recenzie
                                                 - face o rezervare

Administratorul are posibilitatea de a: - adauga orase
                                        - adauga unitate de cazare
                                        - afisa statistici
                                        - accepta o rezervare*

* acceptarea rezervarilor e sub forma de notificare, administratorul fiind nevoit sa accepte o rezervare imediat dupa ce se face.

In momentul in care este creat un user i se atribuie un fisier text format prin user_name+"txt"(ex:Andrei.txt),
in care primeste notificari legate de rezervarile sale(istoricul rezervarilor).



 