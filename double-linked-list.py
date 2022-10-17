# Program to delete a node in a doubly-linked list
 
# for Garbage collection
import gc
 
# A node of the doubly linked list
class Node:
     
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
 
class DoublyLinkedList:
     # Constructor for empty Doubly Linked List
    def __init__(self):
        self.head = None
  
   # Function to delete a node in a Doubly Linked List.
   # head_ref --> pointer to head node pointer.
   # dele --> pointer to node to be deleted
 
    def deleteNode(self, dele):
         
        # Base Case
        if self.head is None or dele is None:
            return
         
        # If node to be deleted is head node
        if self.head == dele:
            self.head = dele.next
 
        # Change next only if node to be deleted is NOT
        # the last node
        if dele.next is not None:
            dele.next.prev = dele.prev
     
        # Change prev only if node to be deleted is NOT
        # the first node
        if dele.prev is not None:
            dele.prev.next = dele.next
        # Finally, free the memory occupied by dele
        # Call python garbage collector
        gc.collect()
 
 
    # Given a reference to the head of a list and an
    # integer, inserts a new node on the front of list
    def push(self, new_data):
  
        # 1. Allocates node
        # 2. Put the data in it
        new_node = Node(new_data)
  
        # 3. Make next of new node as head and
        # previous as None (already None)
        new_node.next = self.head
  
        # 4. change prev of head node to new_node
        if self.head is not None:
            self.head.prev = new_node
  
        # 5. move the head to point to the new node
        self.head = new_node
 
 
    def printList(self, node):
        while(node is not None):
            print(node.data,end=' ')
            node = node.next
 
 
# Driver program to test the above functions
 
# Start with empty list
dll = DoublyLinkedList()
 
# Let us create the doubly linked list 10<->8<->4<->2
dll.push(2);
dll.push(4);
dll.push(8);
dll.push(10);
 
print ("\n Original Linked List",end=' ')
dll.printList(dll.head)
 
# delete nodes from doubly linked list
dll.deleteNode(dll.head)
dll.deleteNode(dll.head.next)
dll.deleteNode(dll.head.next)
# Modified linked list will be NULL<-8->NULL
print("\n Modified Linked List",end=' ')
dll.printList(dll.head)