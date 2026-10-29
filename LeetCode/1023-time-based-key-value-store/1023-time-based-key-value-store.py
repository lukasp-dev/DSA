class TimeMap:

    def __init__(self):
        self.mp: dict[str, list[tuple[int, str]]] = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp: return ""

        l = 0
        r = len(self.mp[key]) - 1
        options = self.mp[key]
        ret = ""

        while l <= r:
            mid = l + (r - l) // 2
            curr_tup = options[mid]
            if timestamp == curr_tup[0]:
                return curr_tup[1]
            elif timestamp < curr_tup[0]:
                r = mid - 1
            else:
                l = mid + 1
                ret = curr_tup[1]
        
        return ret

            
            

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)