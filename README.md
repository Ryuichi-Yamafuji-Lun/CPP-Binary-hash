# CPP-Binary-hash
CPP files of Binary search and Hash

Binary Search: With a set sorted array, takes user input for key. The program then uses the key(number) and searches for it starting from the middle and see if the key is greater than the or less than the number and proceeds this cycle until the number is found. If it is not found the program returns that there is no such number in the array.

Hash Table: This hash table is a linear probing hash table. It takes user imput of bucket size and delta. Using the bucket size we create an array of nodes that holds the key and the value inputed. Since in a linear probing hash table there can only be one node per key in the arrray, we use delta to determine the movement of the key for the value if the node is already occupied. If the key number becomes bigger than the array then we subtract the size of the array from the key to go back around to find a unoccupied array. When the hash table is full the program will notify users that the table is full when the user tries to input more values than the hash table is capable of holding.
