class Node():
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def GetData(self):
        return self.data
    
    def GetNext(self):
        return self.next

    def SetNext(self, next):
        self.next = next

class LinkedList():
    def __init__(self, head: Node):
        assert head is not None
        self.head = head

    def GetHead(self):
        return self.head

    #TODO: just store the count in an instance variable and increment/decrement on each insert/delete operation?
    def GetListSize(self):
        tmp = self.head
        count = 0
        while tmp is not None:
            tmp = tmp.GetNext()
            count += 1
        return count

    def AsList(self):
        outlist = []

        tmp = self.head
        while tmp is not None:
            outlist.append(tmp.GetData())
            tmp = tmp.GetNext()

        return outlist


    #TODO: modify to insert values not Nodes
    def InsertHead(self, node: Node):
        # tmp = self.head
        # self.head = node
        # self.head.SetNext(tmp)
        node.SetNext(self.head)
        self.head = node

    def InsertTail(self, node: Node):
        tmp = self.head        
        while tmp.GetNext() is not None:
            tmp = tmp.GetNext()
        tmp.SetNext(node)
        
if __name__ == '__main__':
    node1 = Node(1, None)
    node2 = Node(2, None)
    node3 = Node(3, None)
    node4 = Node(4, None)
    node5 = Node(5, None)

    # example: ll = [ 3, 2, 1, 5, 4 ]
    myList = LinkedList(node1)
    myList.InsertHead(node2)
    myList.InsertTail(node5)
    myList.InsertHead(node3)
    myList.InsertTail(node4)
    
    print('List contains {} items'.format(myList.GetListSize()))
    print('LinkedList to list(): {}'.format(myList.AsList()))