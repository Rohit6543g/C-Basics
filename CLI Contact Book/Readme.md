# CLI Contact Book

A simple command-line Contact Book written in **C** that stores contacts using binary files and an indexing mechanism for efficient searching.

This project was built to practice core C programming concepts such as file handling, dynamic memory allocation, structures, and implementing simple database-like operations.

---

## Features

* Add new contacts
* List all stored contacts
* Search contacts by name
* Delete contacts (logical deletion)
* Supports multiple contacts with the same name
* Uses an index file for faster searching
* Automatically creates the required database files on first execution

---

## Project Structure

```
.
├── main.c
├── README.md
├── data.bin      # Generated automatically
└── idx.bin       # Generated automatically
```

---

## How It Works

The project stores information in two binary files.

### `data.bin`

Stores the complete contact records.

Each record contains:

* Name
* Phone Number
* Email Address

### `idx.bin`

Stores metadata for each contact.

Each index entry contains:

* Contact Name
* Duplicate ID
* Offset of the corresponding record inside `data.bin`

Instead of scanning the entire data file during searches, the program searches the index file and directly jumps to the required record using its file offset.

---

## Search Mechanism

Searching works as follows:

1. Scan `idx.bin`.
2. Compare names with the search query.
3. Collect matching offsets using dynamically allocated memory (`malloc` and `realloc`).
4. Use `fseek()` to jump directly to each record in `data.bin`.
5. Display all matching contacts.

This approach is considerably more efficient than scanning every contact stored in the data file.

---

## Deletion Mechanism

Deletion is implemented using **logical deletion**.

When a contact is deleted:

* The record inside `data.bin` is left unchanged.
* The corresponding entry in `idx.bin` has its offset changed to `-1`.
* Contacts marked this way are ignored while listing and searching.

This keeps deletion simple and avoids rewriting the entire data file every time a record is removed.

---

## Current Limitation

Currently, deleted records are **not physically removed** from `data.bin`.

As a result:

* `data.bin` grows whenever new contacts are added.
* Deleting contacts does **not** reduce the file size.
* The unused records remain inside the data file.

A future update will implement a **garbage collection (file compaction)** mechanism to reclaim unused space by rebuilding the data file and removing orphaned records.

---

## Building

Compile the project using GCC:

```bash
gcc main.c -o contactbook
```

Run the executable:

```bash
./contactbook
```

On the first execution, the program automatically creates:

* `data.bin`
* `idx.bin`

No manual setup is required.

---

## Example Menu

```
1. Add Contact
2. List Contacts
3. Search Contact
4. Delete Contact
0. Exit
```

---

## Concepts Used

* Structures
* Binary File I/O
* Dynamic Memory Allocation
* File Offsets (`ftell`, `fseek`)
* Index-Based Searching
* Logical Deletion
* Modular Programming

---

## Future Improvements

* Garbage collection / file compaction
* Update existing contacts
* Sort contacts alphabetically
* Case-insensitive search
* Partial name search
* Phone number validation
* Email validation
* Improved error handling
* Cross-platform support
* Makefile

---

## Author

**Rohit Saha**

Built as a learning project to explore low-level file handling, indexing, and basic database concepts in C.
