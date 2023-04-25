import time

class Page:
    def __init__(self, page_id):
        self.page_id = page_id
        self.valid = False
        self.last_access_time = None

    def load(self):
        self.valid = True
        self.last_access_time = time.time()
        print(f"Loaded page {self.page_id}")

    def unload(self):
        self.valid = False
        self.last_access_time = None
        print(f"Unloaded page {self.page_id}")

class Memory:
    def __init__(self, size):
        self.size = size
        self.pages = []
        self.page_table = {}

    def access(self, page_id):
        if page_id not in self.page_table:
            self.page_fault_handler(page_id)
        else:
            self.pages.remove(page_id)
            self.pages.append(page_id)
            print(f"Accessing page {page_id}")

    def page_fault_handler(self, page_id):
        if len(self.pages) == self.size:
            self.evict_page()
        self.load_page(page_id)

    def evict_page(self):
        lru_page = min(self.pages, key=lambda p: self.page_table[p].last_access_time)
        self.page_table[lru_page].unload()
        self.pages.remove(lru_page)
        del self.page_table[lru_page]

    def load_page(self, page_id):
        page = Page(page_id)
        self.pages.append(page_id)
        self.page_table[page_id] = page
        page.load()

memory = Memory(3)
memory.access(0)
memory.access(1)
memory.access(2)
memory.access(3)
memory.access(4)
memory.access(2)