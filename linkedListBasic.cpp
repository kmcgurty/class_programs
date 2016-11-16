#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct{
    int aValue;
    void *next;
} node;

node* CreateNode(int value);

void PrintList(node* node);

void Append(node* node, int value);

int Length(node* node);

node* Delete(node* node, int value);

int main(){
    int returnValue = 0;

    int const numberOfNodes = 5;

    node* startAddress;

    srand(1);

    startAddress = CreateNode(31);

    // for (int i = 0; i < numberOfNodes ; i++)
    //   {
    //     Append(startAddress, rand());
    //   }

    Append(startAddress, 23);
    Append(startAddress, 30);
    Append(startAddress, 56);
    Append(startAddress, 30);
    // PrintList(startAddress);

    // startAddress = Delete(startAddress, 23);
     PrintList(startAddress);
    // startAddress = Delete(startAddress, 30);
    // PrintList(startAddress);
    // startAddress = Delete(startAddress, 31);
    // PrintList(startAddress);

    cout << "There are " << Length(startAddress) << " nodes." << endl;
    cout << "The program has ended." << endl;
    return returnValue;
}

void PrintList(node* thisNode){
    // Print the values in all nodes in the order they appear in the list
    //   Special case of a 0 length node

    while(thisNode->next != NULL) {
        cout << thisNode->aValue << " ";
        thisNode = (node *)thisNode->next;
    }

    cout << thisNode->aValue << endl;
}

void Append(node* startNode, int value){
    // Find the end of the current list of nodes
    //   create a new node
    //   update the pointer in the last node to point to the newly created node
    node *next;
    node *newNode;
    node *lastNode;

    while(startNode->next != NULL) {
        startNode = (node *)startNode->next;
    }

    newNode = CreateNode(value);
    startNode->next = (void *)newNode;
}

node* CreateNode(int value){
    // Create a new node,
    //   assign a value to the node,
    //   assign a NULL to the next pointer
    //   return the location of the newly created node

    node *returnValue;

    returnValue = (node*)malloc(sizeof(node));

    memset(returnValue, 0, sizeof(node));

    returnValue->aValue = value;
    returnValue->next = NULL;

    return returnValue;
}

int Length(node* thisNode){
    // Follow all pointers from "thisNode" until end counting number of nodes visited
    //   Special case when "thisNode->next" is NULL
    int returnValue = 1;

    while(thisNode->next != NULL) {
        thisNode = (node *)thisNode->next;
        returnValue++;
    }

    return returnValue;
}

node* Delete(node* startNode, int value){
    // Follow all nodes in the list and remove all nodes whose value matches value
    //   Special cases:
    //   1.  No matches
    //   2.  Multiple matches
    //   3.  Match at first node
    //   4.  Match at last node.
    //   5.  0 length list
    //   May need to update the value of startNode if first node deleted

    node* returnValue = startNode;

    node *thisNode;
    node *lastNode;
    node *next;

    return returnValue;
}
