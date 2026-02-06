First implment a stack if in python using a class method or if done in c using the struct 

example :

```
class stack :
    def __init__(self):
        self.stack = []
        self.size = int(len(self.stack))
        self.top = -1
    def push(self,element):
        self.stack.append(element)
        self.top += 1

    def pop(self):
        if self.top == -1:
            return None

        removed_element = self.stack[self.top]
        self.stack = self.stack[:self.top]
        self.top -= 1
        return removed_element
    def peek(self):
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1
```
