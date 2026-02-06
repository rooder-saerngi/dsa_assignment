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

now the main problem is solved by this paticular logic 
*made a dictionary(map) named end map where it maps ) to ( and the counter parts of other brackets [ and {
*make a for loop where if a variable c indicating a character exists in a expression , then checks if that expression contains the brackets "(","{","[" 
*if there are the brackets characters then c is ppushed into the stack 
*if there are ")","}","]" exist 

```
def evaluate(expression):
    string = stack()
    endmap = {")": "(", "]": "[", "}": "{"}
    for c in expression:
        if c == "(" or c == "[" or c == "{" :
            string.push(c)
        elif c == ")" or c == "]" or c == "}" :
            if string.is_empty() :
                return False
            if string.pop() != endmap[c]:
                return False
```


