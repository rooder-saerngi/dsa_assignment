class node:
    def __init__(self, data):
        self.data = data
        self.next = None

class linkedlist:
    def __init__(self, head):
        self.head = head

def reverse_traversal(head):
    current = head
    prev = None

    while current is not None:
        NextNode = current.next
        current.next = prev

        prev = current
        current = NextNode
    return prev


def main(node):
    while node is not None:
        print(node.data, end="")
        if node.next is not None:
            print("->", end="")
        node = node.next
    print()


if __name__ == "__main__":
    head = node(1)
    head.next = node(2)
    head.next.next = node(3)
    head.next.next.next = node(4)
    head.next.next.next.next = node(5)

    head = reverse_traversal(head)
    main(head)
