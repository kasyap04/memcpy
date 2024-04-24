from so import mempy

class MemCPY:
    def __init__(self) -> None:
        self.head = None
        self.current = None

    def __setitem__(self, key, value):
        # print(f"head : {self.head} current : {self.current}")
        if self.head:
            # print(f"NEW VAL : {key}")
            self.current = mempy.insert_node(self.current, key, value)
        else:
            # self.head = key
            # self.current = self.head
            self.head = mempy.create_node(key, value)
            self.current = self.head

    def display(self):
        mempy.display(self.head)
        mempy.free(self.head)

    # def __del__(self):
    #     print("Run clear")
    #     mempy.free(self.head)
        