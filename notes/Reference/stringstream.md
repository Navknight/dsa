---
difficulty: Unknown
topics: []
source: Standard
star: false
---

### `stringstream`, `istringstream`, and `ostringstream` in C++

|Type|Purpose|Typical Use|
|---|---|---|
|**`ostringstream`**|Output string stream — used to build a string (write into it like a file).|`ostringstream out; out << 10 << " " << 20; string s = out.str();`|
|**`istringstream`**|Input string stream — used to read or extract data from a string (like reading from `cin`).|`istringstream in("10 20"); int x, y; in >> x >> y;`|
|**`stringstream`**|Combined input/output string stream — can both read and write.|`stringstream ss("10"); ss << " 20"; int x, y; ss >> x >> y;`|

---

### How it works

They treat a string as a stream buffer, just like files or standard I/O.  
You can use `<<` to write formatted text into the stream, or `>>` to extract tokens from it.

---

### In your tree (de)serialization used in [[Serialize and Deserialize Binary Tree]]

- `ostringstream out;` — builds the serialized string  
    Example: writes `"1 2 # # 3 # # "`
    
- `istringstream in(data);` — reads that string token-by-token  
    Example: `in >> val` extracts `"1"`, then `"2"`, then `"#"`, and so on during recursion.
    

---

### Summary analogy

- `ostringstream` → write data into a string
    
- `istringstream` → read data from a string
    
- `stringstream` → both read and write on the same string