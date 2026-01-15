# Procedural Building Tool – Unreal Engine (C++)

This repository contains **selected source files, architecture overview, and design documentation** for a real-time procedural construction system developed entirely in **C++ for Unreal Engine**.

⚠️ **This is not a complete or runnable game project.**  
To protect proprietary algorithms and technical IP, only non-sensitive excerpts and structural components are included.  
Functionality is demonstrated through the videos provided in the `/Media` folder.

---

## 🎯 Purpose of This Repository

The goal is to showcase:

- C++ engineering ability  
- Architecture design quality (SOLID, Clean Architecture)  
- Real-time procedural geometry logic  
- Code clarity, maintainability, and large-system design  

All critical proprietary logic (full algorithms, complete UE modules, buildable project files) has been intentionally omitted.

## 🎥 Demo Videos

Demonstrations of the system in action:

### **1. Full Construction Workflow**  
Placement of procedural walls, doors, and windows, including cuts and interior inspection.  
👉 `Media/procedural_building_tool_showcase.mp4`

### **2. Deletion & Window Stacking**  
Quick demonstration of the deletion tool and vertical window placement.  
👉 `Media/additional_test_deletion_and_window_handling.mp4`

---

## 🧩 Architecture Overview

The Grid system architecture has a map that presents the class relations    
👉 `Media/floor_grid_structure_map.jpg`

The structure ensures:
- Clean responsibilities  
- Easy testing  
- Low compile-time coupling  
- Future extension without modifying existing logic  

---

## 🔧 Code Style & Practices

Code follows:

- **Google C++ Style Guide** (adapted to Unreal conventions)  
- **Clean Code** principles  
- **Defensive programming** for tool safety  
- **Memory-safe Unreal ownership semantics**  

---

## 📄 License

All rights reserved.  
This repository is provided **exclusively for technical evaluation**.  
**No permission is granted to use, copy, modify, or distribute the code or content.**

---

## 👤 Author

**Natanaã Palma**  
C++ / Systems / Tools Engineer  
Focused on real-time systems, procedural generation, and architectural quality.
