# Project2---A Modern-Library-Application

**Summary**: 
1. Using C++ to design an application that receives the publications and stores them in the system with the information needed for their retrieval.
   
2. Later, each publication can be lent out to members of the library with a due date for return.
   
3. When Books and other publications arrive in the library, they can be tagged and put on shelves, so they are easily retrievable to be lent out to those who need them.


### Main Menu output

```Text
The >< menu is empty
The Lunch Menu is not empty and has 3 menu items.
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 1
you chose Omelet
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> 2
you chose Tuna Sandwich
Lunch Menu:
 1- Omelet
 2- Tuna Sandwich
 3- California Roll
 0- Exit
> abc
Invalid Selection, try again: 5
Invalid Selection, try again: -1
Invalid Selection, try again: 0
 1- Order more
 0- Exit
> 0
Your orders:
2 Omelets
3 Tuna Sandwichs

```
#### Execution output: Abort Scenarios  (searching all) 
```text
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 0
Aborted!
-------------------------------------------------------
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2024/07/19 | J. K. Rowling   |
   2- | F861 | Harry Potter and the Chamber o |  N/A  | 2024/07/24 | J. K. Rowling   |
   3- | C872 | Harry Potter and the Deathly H | 64984 | 2024/07/17 | J. K. Rowling   |
   4- | C945 | Harry Potter and the Goblet of |  N/A  | 2024/07/14 | J. K. Rowling   |
   5- | C332 | Harry Potter and the Half/Bloo | 85952 | 2024/07/22 | J. K. Rowling   |
   6- | L290 | Harry Potter and the Order of  |  N/A  | 2024/07/11 | J. K. Rowling   |
   7- | D208 | Harry Potter and the Philosoph | 72685 | 2024/07/19 | J. K. Rowling   |
   8- | R856 | Harry Potter and the Prisoner  |  N/A  | 2024/07/10 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
> x
Aborted!
```
####  Execution output: Search on loan
```text
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2024/07/19 | J. K. Rowling   |
   2- | C872 | Harry Potter and the Deathly H | 64984 | 2024/07/17 | J. K. Rowling   |
   3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2024/07/22 | J. K. Rowling   |
   4- | D208 | Harry Potter and the Philosoph | 72685 | 2024/07/19 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
>
```
#### Execution output: Search available publications 
```Text
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | F861 | Harry Potter and the Chamber o |  N/A  | 2024/07/24 | J. K. Rowling   |
   2- | C945 | Harry Potter and the Goblet of |  N/A  | 2024/07/14 | J. K. Rowling   |
   3- | L290 | Harry Potter and the Order of  |  N/A  | 2024/07/11 | J. K. Rowling   |
   4- | R856 | Harry Potter and the Prisoner  |  N/A  | 2024/07/10 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
>
```

#### Execution output: Adding a new publication to the library 
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 1
Adding new publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Shelf No: S001
Title: Seneca Student Handbook
Date: 2022/1/5
Add this publication to the library?
 1- Yes
 0- Exit
> 1
Publication added
```

#### Execution output: removing a publication from the library 
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 2
Removing publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2024/07/11 |
   2- | P008 | MoneySense Magazine........... | 72614 | 2024/07/16 |
   3- | P008 | MoneySense Magazine........... | 48096 | 2024/07/17 |
   4- | P008 | MoneySense Magazine........... | 89325 | 2024/07/17 |
   5- | P008 | MoneySense Magazine........... | 33074 | 2024/07/17 |
   6- | P008 | MoneySense Magazine........... |  N/A  | 2024/07/18 |
   7- | P008 | MoneySense Magazine........... | 70451 | 2024/07/24 |
   8- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
> X (to Exit)
> Row Number(select publication)
> 8
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Remove this publication from the library?
 1- Yes
 0- Exit
> 1
Publication removed
```


#### Execution output: Checking out a publication
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 3
Checkout publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2024/07/11 |
   2- | P008 | MoneySense Magazine........... |  N/A  | 2024/07/18 |
   3- | S001 | Seneca Student Handbook....... |  N/A  | 2024/01/05 |
> X (to Exit)
> Row Number(select publication)
> 3
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Check out publication?
 1- Yes
 0- Exit
> 1
Enter Membership number: 12345
Publication checked out
```

#### Execution output: Returning publication to the library
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 4
Return publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2024/07/19 | J. K. Rowling   |
   2- | C872 | Harry Potter and the Deathly H | 64984 | 2024/07/17 | J. K. Rowling   |
   3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2024/07/22 | J. K. Rowling   |
   4- | D208 | Harry Potter and the Philosoph | 72685 | 2024/07/19 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
> 2
| C872 | Harry Potter and the Deathly H | 64984 | 2024/07/17 | J. K. Rowling   |
Return Publication?
 1- Yes
 0- Exit
> 1
Please pay $4.00 penalty for being 8 days late!
Publication returned
```
