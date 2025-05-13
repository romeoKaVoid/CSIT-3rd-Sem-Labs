#include <stdio.h>
 #include <stdlib.h>
 
 #define TABLE_SIZE 10 // Size of the hash table
 
 int hashTable[TABLE_SIZE]; // Hash table
 int EMPTY = -1;            // Marker for empty slots
 
 // Hash function: simple modulo operation
 int hashFunction(int key)
 {
     return key % TABLE_SIZE;
 }
 
 // Insert function using linear probing
 void insert(int key)
 {
     int index = hashFunction(key);
 
     // Linear probing in case of collision
     while (hashTable[index] != EMPTY)
     {
         index = (index + 1) % TABLE_SIZE; // Move to the next slot
     }
     hashTable[index] = key;
     printf("Element Inserted!!\n\n");
 }
 
 // Search function
 int search(int key)
 {
     int index = hashFunction(key);
     int start = index; // Keep track of original position
 
     while (hashTable[index] != EMPTY)
     {
         if (hashTable[index] == key)
             return index; // Found key at index
         index = (index + 1) % TABLE_SIZE;
         if (index == start)
             break; // Stop if we complete one full cycle
     }
     return -1; // Not found
 }
 
 // Display function
 void display()
 {
     printf("\nHash Table:\n");
     for (int i = 0; i < TABLE_SIZE; i++)
     {
         if (hashTable[i] == EMPTY)
             printf("[%d] --> Empty\n", i);
         else
             printf("[%d] --> %d\n", i, hashTable[i]);
     }
 }
 
 // Main function
 int main()
 {
     // Initialize hash table with empty values
     for (int i = 0; i < TABLE_SIZE; i++)
         hashTable[i] = EMPTY;
    printf("***Welcome to Hashing Program with Linear Probing***\n");
    printf("------------------------------------------------------\n");
     int choice, key;
     while (choice != 4)
     {
         printf("Choose any one option from below...\n");
         printf("1) Insert element in Hash Table\n2) Search element in Hash Table\n3) Display the Hash Table\n4) Exit\n\n");
         printf("Your choice? ");
         scanf("%d", &choice);
 
         switch (choice)
         {
         case 1:
             printf("Enter the element to be inserted: ");
             scanf("%d", &key);
             insert(key);
             break;
         case 2:
             printf("Enter which element to search: ");
             scanf("%d", &key);
             int index = search(key);
             if (index != -1)
                 printf("Element %d found at index %d\n\n",key, index);
             else
                 printf("Element %d not found\n\n", key);
             break;
         case 3:
             display();
             break;
         case 4:
             printf("Exiting...\n");
             break;
         default:
             printf("Invalid choice! Try again.\n");
         }
     }
     printf("\n\n\tBy Krishna Aryal");
     return 0;
 }