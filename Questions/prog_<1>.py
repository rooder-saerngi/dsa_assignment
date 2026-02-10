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

    return string.is_empty()

if __name__ == "__main__":
    expression1 = "a+(b-c)*(d"
    print("correct" if evaluate(expression1) else "false" )#the answer I got was False
    expression2 = "m + [a − b ∗ (c + d ∗ {m)]"
    print("correct" if evaluate(expression2) else "false")#the answer I got was False
    expression3 ="a+(b-c)"
    print("correct" if evaluate(expression3) else "false")#the answer I got was correct

