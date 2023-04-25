class Page:
    def __init__(self, page_id):
        self.page_id = page_id
        self.valid = False
        
    def load(self):
        self.valid = True
        print(f"Loaded page {self.page_id}")
        
    def unload(self):
        self.valid = False
        print(f"Unloaded page {self.page_id}")
        
class Memory:
    def __init__(self, num_pages):
        self.num_pages = num_pages
        self.pages = [Page(i) for i in range(num_pages)]
        
    def access(self, page_id):
        page = self.pages[page_id]
        if not page.valid:
            self.load(page_id)
        else:
            print(f"Accessing valid page {page_id}")
        
    def load(self, page_id):
        print(f"Loading page {page_id} into memory")
        unloaded = None
        for page in self.pages:
            if not page.valid:
                unloaded = page
                break
        if unloaded is None:
            unloaded = self.pages.pop(0)
            unloaded.unload()
        unloaded.page_id = page_id
        unloaded.load()
        self.pages.append(unloaded)
        
memory = Memory(3)
memory.access(0)
memory.access(1)
memory.access(2)
memory.access(3)
memory.access(4)
memory.access(2)