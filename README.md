# Morse Translater CLI 🔤  
A C++ command-line utility for bi-directional conversion between English text and Morse code. Supports letters, numbers, and a wide range of special characters — with both interactive and file-based modes.

---

## 🚀 Features
- 🔤 **Text to Morse**: Converts regular text to Morse code
- 📡 **Morse to Text**: Decodes Morse code into readable text
- 📁 **File Support**: Read/write Morse and text from files
- 🧩 **Wide Character Coverage**: Letters (A–Z), digits (0–9), punctuation, and symbols
- ❓ **Graceful Error Handling**: Unknown Morse tokens are replaced with `?`

---

## 📖 Morse Format Guide
- Use **dots (.)** and **dashes (-)** for Morse code
- Separate **characters with spaces**
- Separate **words with `/`**

  
---

## 🧪 Examples
Original Text: HELLO WORLD
Morse Output : .... . .-.. .-.. --- / .-- --- .-. .-.. -..

Morse         : .... . .-.. .-.. --- / .-- --- .-. .-.. -..
String Output : HELLO WORLD

🛠 Requirements
- C++11 or later
- Standard Template Library (STL)
- File read/write permissions

📦 File Operations
- Input Morse from input.txt → Output decoded text to output_string.txt
- Input text from input1.txt → Output Morse to output.txt

🧠 Technical Highlights
- Class-based design for clean organization
- Uses vector<pair<char,string>> for manual Morse mapping
- Input normalization with toupper()
- File I/O via ifstream and ofstream
- Minimal STL — raw loops for clarity and control

🤝 Contributing
Feel free to fork, star, or submit issues and suggestions.
This project was built as a hands-on learning exercise — feedback is always welcome!

---
<img width="1478" height="418" alt="Screenshot 2025-10-29 000903" src="https://github.com/user-attachments/assets/49281b83-52e6-4be2-83c5-48c23cab9ae3" />

---

<img width="1473" height="409" alt="Screenshot 2025-10-29 000930" src="https://github.com/user-attachments/assets/7a95b14f-f8b1-40f0-81ae-6651b8515f16" />



