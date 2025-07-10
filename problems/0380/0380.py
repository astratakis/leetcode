import random

class RandomizedSet:

    def __init__(self):
        self.index_to_value_map = {}
        self.value_to_index_map = {}
        self.count = 0
        

    def insert(self, val: int) -> bool:
        
        if self.value_to_index_map.get(val) == None:
            # In this case the value is not in the map
            self.index_to_value_map[self.count] = val
            self.value_to_index_map[val] = self.count
            self.count += 1
            return True
        else:
            return False

    def remove(self, val: int) -> bool:

        if self.count == 0:
            return False
        
        if self.value_to_index_map.get(val) == None:
            # In this case there is nothing to remove
            return False
        else:
            index_to_be_removed = self.value_to_index_map[val]
            del self.value_to_index_map[val]
            del self.index_to_value_map[index_to_be_removed]
            self.count -= 1

            if self.count == 0:
                return True
            
            # Now rekey the last element
            last_value = self.index_to_value_map[self.count]
            del self.index_to_value_map[self.count]
            self.index_to_value_map[index_to_be_removed] = last_value
            self.value_to_index_map[last_value] = index_to_be_removed
            return True

    def getRandom(self) -> int:
        key = random.randint(0, self.count - 1)

        return self.index_to_value_map[key]


def main():

    commands = ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
    data = [[],[0],[0],[0],[],[0],[0]]

    obj = RandomizedSet()

    for index, command in enumerate(commands):
        if command == "RandomizedSet":
            obj = RandomizedSet()
        elif command == "insert":
            print(obj.insert(data[index][0]))
        elif command == "remove":
            print(obj.remove(data[index][0]))
        elif command == "getRandom":
            print(obj.getRandom())
        else:
            raise ValueError("Unwanted input")

if __name__ == "__main__":
    main()